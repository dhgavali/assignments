// club info

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int prn;
    int roll;
    char name[10];
    struct node *next;
};

struct node *createnode(int n)
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    head = ptr;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            printf("This is first node \n It is for President\n");
            printf("Enter name of president\n");
            scanf("%s", ptr->name);
            ptr->prn = 00;
            ptr->roll = 00;
        }
        else if (i == n - 1)
        {
            printf("This is last node \n Tt is for secretary\n");
            printf("Enter name of Secretary\n");
            scanf("%s", ptr->name);
            ptr->prn = 0;
            ptr->roll = 0;
        }
        else
        {
            printf("enter prn no,roll no,Name resp of %dth member:\n", i);
            scanf("%d%d%s", &ptr->prn, &ptr->roll, ptr->name);
        }
        ptr->next = (i < n - 1) ? ((struct node *)malloc(sizeof(struct node))) : NULL;
        ptr = ptr->next;
    }
    return head;
}
void display(struct node *head)
{
    printf("\n\n");
    printf("****List of All Members***\n");
    printf("PRN ROLL NAME\n");
    while (head != NULL)
    {
        printf("%d  %d   %s\n", head->prn, head->roll, head->name);
        head = head->next;
    }
}
struct node *addmember(struct node *head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter prn no ,roll no,Name of member to add\n");
    scanf("%d%d%s", &ptr->prn, &ptr->roll, ptr->name);
    ptr->next = head->next;
    head->next = ptr;
    return head;
}
void *deletemember(struct node *head, int n)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    while (head->roll != n)
    {

        temp = head;
        head = head->next;
    }
    temp->next = head->next;
    free(head);
    printf("\n deleted member successfully");
}

struct node *deletePresident(struct node *head)
{
    struct node *temp;
    temp = head;
    head = head->next;

    free(temp);
    printf("\n Deleted President");
    return head;
}

void *deleteSecretory(struct node *head)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    while (head->next != NULL)
    {
        temp = head;
        head = head->next;
    }

    free(head);
    printf("\n deleted secretory");
}
int main()
{
    int i, j, t = 1, s, n, del;
    struct node *head;
    printf("Enter total no of members is in club:\n");
    scanf("%d", &n);
    head = createnode(n);
    while (t != 0)
    {
        printf("\n\n");
        printf("****menu****\n");
        printf("Press 1 for to add member in linked list\n");
        printf("Press 2 for to delete member in linked list\n");
        printf("Press 3 to display information\n");
        printf("Press 4 to delete President\n");
        printf("Press 5 to delete Secretory\n");
        printf("Press 0 for exit\n");
        scanf("%d", &s);
        switch (s)
        {
        case 1:
        {
            head = addmember(head);
            break;
        }
        case 2:
        {
            printf("enter roll no of member to delete\n");
            scanf("%d", &del);
            deletemember(head, del);
            break;
        }
        case 3:
        {
            display(head);
            break;
        }
        case 4:
            head = deletePresident(head);
            break;
        case 5:
            deleteSecretory(head);
            break;
        case 0:
        {
            t = 0;
            break;
        }
        }
    }

    return 0;
}
