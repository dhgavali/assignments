// Set operation program
// Assignment 1
// Roll No: DSEITA174

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int UnionSet(int n1, int n2, int a[], int b[], int res[]);
int IntersectionSet(int n1, int n2, int a[], int b[], int res[]);
int Differrence(int n1, int n2, int a[], int b[], int res[]);
int SymmetricDiff(int n1, int n2, int a[], int b[], int res[]);
int result(int y, int res[]);

int main(void)
{
    int n1;
    int n2;

    printf("Enter number of elements in Set A : ");
    scanf("%d", &n1);
    int a[n1];

    // input elements for set A
    printf("Enter the elements of set A : ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nEnter number of elements in Set B : ");
    scanf("%d", &n2);
    int b[n2];
    // input elements for set B
    printf("Enter the elements of set B : ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &b[i]);
    }

    // Displaying inputs of set
    printf("\nThe given sets are : \n");
    printf("Set A: {");
    for (int i = 0; i < n1; i++)
    {
        printf("%d", a[i]);
        if (i < n1 - 1)
            printf(",");
    }

    printf("}\n");
    printf("Set B: {");
    for (int i = 0; i < n2; i++)
    {
        printf("%d", b[i]);
        if (i < n2 - 1)
            printf(",");
    }
    printf("}\n\n");

    int res[n1 + n2];
    int sub;
    int p;
    int choice;
    do
    {
        printf("Please choose the set operation:\n");
        printf("\t 1. Union\n\t2. Intersection\n\t3. Difference\n\t4. Symmetric difference\n\t5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            p = UnionSet(n1, n2, a, b, res);
            printf("The Union of given sets are : \n");
            result(p, res);
            break;
        case 2:
            p = IntersectionSet(n1, n2, a, b, res);
            printf("The Intersection of given sets are : \n");
            result(p, res);
            break;
        case 3:
            printf("Select one of the following Differences:\n1.A-B\n2.B-A\n");
            scanf("%d", &sub);
            if (sub == 1)
            {
                p = Differrence(n1, n2, a, b, res);
                printf("The Difference of given sets are : \n");
                result(p, res);
            }
            else if (sub == 2)
            {
                p = Differrence(n1, n2, b, a, res);
                printf("The Difference of given sets are : \n");
                result(p, res);
            }
            else
                printf("Invalid Option\n");
            break;
        case 4:
            p = SymmetricDiff(n1, n2, a, b, res);
            printf("The Symmetric Difference of given sets are : \n");
            result(p, res);
            break;
        case 5:

            break;
        default:
            printf("Invalid Choice\n Please choose correct option \n");
            break;
        }
    } while (choice != 5);
    return 0;
}
int UnionSet(int n1, int n2, int a[], int b[], int res[])
{
    int i;
    for (i = 0; i < n1; i++)
    {
        res[i] = a[i];
    }
    int z = i;
    while (z < n1 + n2)
    {
        int flag = 0;
        for (int j = 0; j < n1; j++)
        {
            if (res[j] == b[z - n1])
                flag = 1;
        }
        if (flag == 0)
        {
            res[i] = b[z - n1];
            i++;
        }
        z++;
    }
    return i;
}
int IntersectionSet(int n1, int n2, int a[], int b[], int res[])
{
    int y = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (a[i] == b[j])
            {
                res[y] = a[i];
                y++;
            }
        }
    }
    return y;
}
int Differrence(int n1, int n2, int a[], int b[], int res[])
{
    int y = 0;
    for (int i = 0; i < n1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n2; j++)
        {
            if (a[i] == b[j])
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            res[y] = a[i];
            y++;
        }
    }
    return y;
}
int SymmetricDiff(int n1, int n2, int a[], int b[], int res[])
{
    int y = 0;
    int temp[n1 + n2];
    int m = IntersectionSet(n1, n2, a, b, temp);
    for (int i = 0; i < n1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n2; j++)
        {
            if (a[i] == temp[j])
                flag = 1;
        }
        if (flag == 0)
        {
            res[y] = a[i];
            y++;
        }
    }
    for (int i = 0; i < n2; i++)
    {
        int flag = 0;
        for (int j = 0; j < m; j++)
        {
            if (b[i] == temp[j])
                flag = 1;
        }
        if (flag == 0)
        {
            res[y] = b[i];
            y++;
        }
    }
    return y;
}

int result(int y, int res[])
{
    printf("result: {");
    for (int i = 0; i < y; i++)
    {
        printf("%d", res[i]);
        if (i < y - 1)
            printf(",");
    }
    printf("}\n");
    printf("\n");
    return 0;
}