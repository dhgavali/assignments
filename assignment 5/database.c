/*
Assignment No -5
Title : Implement database using doubly linked list
Name: Dhananjay Gavali
Roll No: DSEITA174
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int prn, marks;
    char name[20];
    struct node *prev, *next;
};

void reverse(struct node *p)
{
    if (p != NULL)
    {

        reverse(p->next);
        printf("%s\t%d\t%d\n", p->name, p->prn, p->marks);
    }
}

struct node *insert(struct node *head)
{
    int stud;
    char naw[20];
    struct node *temp, *q;
    q = head;

    printf("Enter prn_no :");
    scanf("%d", &head->prn);
    printf("Enter name :");
    scanf("%s", naw);
    strcpy(head->name, naw);
    printf("Enter MARKS :");
    scanf("%d", &head->marks);
    head->prev = NULL;
    head->next = NULL;
    printf("Enter Number OF students\n");
    scanf("%d", &stud);
    printf("Enter the data:\n");
    for (int i = 0; i < stud; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter prn_no :");
        scanf("%d", &temp->prn);
        printf("Enter name :");
        scanf("%s", temp->name);
        printf("Enter MARKS :");
        scanf("%d", &temp->marks);

        temp->next = NULL;
        temp->prev = head;
        head->next = temp;
        head = head->next;
    }
    return q;
}

void display(struct node *head)
{
    struct node *p;
    p = head;
    while (p != NULL)
    {
        printf("prn_no:%d\n", p->prn);
        printf("name:%s\n", p->name);
        printf("Marks:%d\n\n\n", p->marks);
        p = p->next;
    }
}
void del(struct node *head)
{
    int po;
    printf("Enter prn number to delete the record\n");
    scanf("%d", &po);

    struct node *p, *q;
    p = head;
    q = head->next;

    while (p->prn != po)
    {
        p = p->next;
        q = q->next;
    }
    p->prev->next = p->next;
    q->prev = p->prev;
    free(p);
}
struct node *delStart(struct node *head)
{
    struct node *p = head;
    head = head->next;

    head->prev = NULL;

    free(p);
    printf("Deleted succesfully\n");
    return head;
}
void delEnd(struct node *head)
{
    struct node *p = head;
    while (p != NULL && p->next != NULL)
    {
        p = p->next;
    }
    p->prev->next = NULL;
    
    free(p);
}

int main(void)
{
    int a;
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));

    do
    {
        printf("1)Insert a record\n2)Delete record at first position \n3)Delete a record between first and last\n4)Display list\n5)Display in Reverse Order\n6)Delete record at end\n7)Exit\n");
        printf("\nEnter ur choice \n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            head = insert(head);
            break;
        case 2:
            head = delStart(head);
            break;

        case 3:
            del(head);
            break;

        case 4:
            display(head);
            break;

        case 5:
            reverse(head);
            break;

        case 6:
            delEnd(head);
            break;

        default:
            printf("Invalid Input\n");
        }

    } while (a != 7);
}
