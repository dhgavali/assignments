#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define OPERATORS 7

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

char precedence[OPERATORS][2] = {{'(', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'%', 2}, {')', 3}};

int getIndex(int data)
{
    int i;
    for (i = 0; i < OPERATORS; i++)
    {
        if (data == precedence[i][0])
            return i;
    }
}
struct node *createNode(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
}

void push(int data)
{
    struct node *ptr = createNode(data);
    if (top == NULL)
    {
        top = ptr;
        return;
    }
    ptr->next = top;
    top = ptr;
}

int pop()
{
    int data;
    struct node *temp;
    if (top == NULL)
        return -1;
    data = top->data;
    temp = top;
    top = top->next;
    free(temp);
    return (data);
}

void infix_to_postfix(char infix[], char postfix[])
{
    int i, j = 0, data;
    int index1, index2;
    for (i = 0; i < strlen(infix); i++)
    {
        /* given input is operator or not */
        if (tolower(infix[i]) >= 'a' && tolower(infix[i] <= 'z'))
            postfix[j++] = infix[i];
        else if (infix[i] == ')')
        {

            data = pop();
            while (data != '(' && data != -1)
            {
                postfix[j++] = data;
                data = pop();
            }
        }
        else if (infix[i] == '(')
        {

            push(infix[i]);
        }
        else
        {

            data = pop();
            if (data == -1)
            {
                push(infix[i]);
                continue;
            }
            else if (data == '(')
            {

                push(data);
                push(infix[i]);
                continue;
            }

            index1 = getIndex(data);
            index2 = getIndex(infix[i]);
            while (precedence[index1][1] >= precedence[index2][1])
            {

                postfix[j++] = data;
                data = pop();
                if (data == -1)
                {
                    push(infix[i]);
                    break;
                }
                else if (data == '(')
                {
                    push(data);
                    push(infix[i]);
                    data = -1;
                    break;
                }
                index1 = getIndex(data);
            }
            if (data != -1)
            {
                push(data);
                push(infix[i]);
            }
        }
    }

    while (1)
    {
        if ((data = pop()) == -1)
            break;
        postfix[j++] = data;
    }
    postfix[j] = '\0';
}

/* string reverse operation */
void strrevs(char str[])
{
    int i = 0, j = 0;
    char ptr[100];
    while (str[i] != '\0')
        i++;
    for (i = i - 1; i >= 0; i--)
    {
        ptr[j] = str[i];
        j++;
    }
    ptr[j] = '\0';
    strcpy(str, ptr);
}
void infix_to_prefix(char infix[], char postfix[])
{
    int i, j = 0, data;
    int index1, index2;
    for (i = 0; i < strlen(infix); i++)
    {
        /* if the given i/p is operand, place in output buffer */
        if (tolower(infix[i]) >= 'a' && tolower(infix[i] <= 'z'))
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
        {

            data = pop();
            while (data != ')' && data != -1)
            {
                postfix[j++] = data;
                data = pop();
            }
        }
        else if (infix[i] == ')')
        {

            push(infix[i]);
        }
        else
        {
            data = pop();
            if (data == -1)
            {

                push(infix[i]);
                continue;
            }
            else if (data == ')')
            {

                push(data);
                push(infix[i]);
                continue;
            }
            index1 = getIndex(data);
            index2 = getIndex(infix[i]);

            while (precedence[index1][1] > precedence[index2][1])
            {
                postfix[j++] = data;
                data = pop();
                if (data == -1 || data == ')')
                {
                    push(infix[i]);
                    break;
                }
                index1 = getIndex(data);
            }
            if (data != -1)
            {
                push(data);
                push(infix[i]);
            }
        }
    }
    while (1)
    {
        if ((data = pop()) == -1)
            break;
        postfix[j++] = data;
    }
    postfix[j] = '\0';
}

void postfixSolve(char str[])
{

    int i, data = -1, operand1, operand2, result;

    for (i = 0; i < strlen(str); i++)
    {
        if (isdigit(str[i]))
        {
            /*
             * if the i/p char is digit, parse
             * character by character to get
             * complete operand
             */
            data = (data == -1) ? 0 : data;
            data = (data * 10) + (str[i] - 48);
            continue;
        }

        /* push the operator into the stack */
        if (data != -1)
        {
            push(data);
        }

        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            /*
             * if the i/p character is an operator,
             * then pop two elements from the stack,
             * apply operator and push the result into
             * the stack
             */
            operand2 = pop();
            operand1 = pop();
            if (operand1 == -1 || operand2 == -1)
                break;
            switch (str[i])
            {
            case '+':
                result = operand1 + operand2;
                /* pushing result into the stack */
                push(result);
                break;
            case '-':
                result = operand1 - operand2;
                push(result);
                break;
            case '*':
                result = operand1 * operand2;
                push(result);
                break;
            case '/':
                result = operand1 / operand2;
                push(result);
                break;
            }
        }
        data = -1;
    }
    if (top != NULL && top->next == NULL)
        printf("Output:%d\n", top->data);
    else
        printf("u ve entered wrong expression\n");
}

int main()
{
    char str[100], output[100];
    int choice = 0;
    do
    {
        printf("\n \t================================");
        printf("\n \t==============MENU==============");
        printf("\n \t================================");
        printf("\n \t 1. Convert Infix to Postfix \n \t 2. Convert Infix to Prefix \n \t 3. Evaluate Postfix expression \n \t 4. Exit");
        printf("\n \t================================");
        printf("\n \t Enter Your choice \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter infix Expression:");
            scanf("%s", str);
            infix_to_postfix(str, output);

            printf("PostFix Expression Output: %s \n\n", output);

            break;
        case 2:
            printf("Enter infix Expression:");
            scanf("%s", str);
            // str[strlen(str) - 1] = '\0';
            strrev(str);
            infix_to_prefix(str, output);
            strrev(output);
            printf("Prefix Expression output: %s\n\n", output);
            break;
        case 3:
            printf("\n Enter PostFix expression :");
            scanf("%s", str);

            postfixSolve(str);
            break;
        default:

            printf("Please enter valid choice");
            break;
        }
    } while (choice != 4);
    return 0;
}
