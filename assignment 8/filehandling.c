/* Assignment No. 8

Title: File handling
Name: Dhananjay Vijay Gavali
Roll No: DSEITA174
*/

#include <stdio.h>
#include <stdlib.h>

struct stud
{
    int roll;
    char name[20];
    char div;
    char address[50];
} s[10];

void accept(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the details of student %d ", i + 1);
        printf("\n\nEnter the Name :-");
        scanf("%s", s[i].name);
        printf("Enter Division A,B,C,D :- ");
        scanf(" %c", &s[i].div);
        printf("Enter Roll Number :- ");
        scanf("%d", &s[i].roll);

        printf("Enter Address :- ");
        scanf("%s", s[i].address);
    }
}

void writeFile(int n)
{
    int i;
    FILE *fp;
    fp = fopen("record.txt", "a");
    if (fp == NULL)
        printf("\nError");
    else
    {
        for (int i = 0; i < n; i++)
        {
            fprintf(fp, "%d %s %c %s\n", s[i].roll, s[i].name, s[i].div, s[i].address);
        }
    }
    fclose(fp);
}

void display(int n)
{
    int roll;
    char nm[100];
    char div;
    char address[100];
    FILE *fp;
    fp = fopen("record.txt", "r");
    if (fp == NULL)
        printf("\nError");
    else
        for (int i = 0; i < n; i++)
        {
            fscanf(fp, "%d %s %c %s", &roll, nm, &div, address);
            printf("%d %s %c %s\n", roll, nm, div, address);
        }
    fclose(fp);
}

void search(int n, int rn)
{
    int c = 0;
    int roll;
    char nm[100];
    char div;
    char address[100];
    FILE *fp;
    fp = fopen("record.txt", "r+");
    if (fp == NULL)
        printf("\nError");
    else
        for (int i = 0; i < n; i++)
        {
            fscanf(fp, "%d %s %c %s", &roll, nm, &div, address);
            if (roll == rn)
            {
                c = 1;
                printf("\n\n%d %s %c %s\n", roll, nm, div, address);
                break;
            }
        }
    if (c == 0)
        printf("\nStudent not found");
    fclose(fp);
}

void delete (int n, int rn)
{
    int roll;
    char nm[100];
    char div;
    char address[100];
    int t = 0;
    FILE *fp;
    fp = fopen("record.txt", "r");
    FILE *f;
    f = fopen("record1.txt", "w");
    if (fp == NULL)
        printf("\nError");
    else
    {
        for (int i = 0; i < n; i++)
        {
            fscanf(fp, "%d %s %c %s", &roll, nm, &div, address);
            if (roll != rn)
            {
                t++;
                fprintf(f, "%d %s %c %s\n", roll, nm, div, address);
            }
        }
    }
    fclose(f);
    fclose(fp);
    f = fopen("record1.txt", "r");
    fp = fopen("record.txt", "w");
    if (f == NULL)
        printf("\nError");
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            fscanf(f, "%d %s %c %s", &roll, nm, &div, address);
            fprintf(fp, "%d %s %c %s\n", roll, nm, div, address);
        }
    }
    FILE *f1;

    fclose(f);
    fclose(fp);
    f1 = fopen("record.txt", "r");
    if (f1 == NULL)
        printf("\nError");
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            fscanf(f1, "%d %s %c %s", &roll, nm, &div, address);
            printf("%d %s %c %s\n", roll, nm, div, address);
        }
    }
}
int main()
{
    int n;
    int ch;
    int rn;
    printf("\nEnter the number of students :- ");
    scanf("%d", &n);
    accept(n);
    writeFile(n);
    while (1)
    {
        printf("\n=============MENU============");
        printf("\n 1 - Display All ");
        printf("\n 2 - Search Student ");
        printf("\n 3 - Delete Record ");
        printf("\n  0 - to exit ");
        printf("\n\nEnter the choice :- \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display(n);
            break;
        case 2:
            printf("\nEnter the roll no of student :- ");
            scanf("%d", &rn);
            search(n, rn);
            break;
        case 3:
            printf("\nEnter the roll no of student to delete record :- ");
            scanf("%d", &rn);
            delete (n, rn);
            break;
        case 0:
            exit(0);
            return 0;
        default:
            printf("\nEnter valid choice ");
        }
    }
    return 0;
}