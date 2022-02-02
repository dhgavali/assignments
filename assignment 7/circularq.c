// Assignment 7
// Title: circular queue
// Name: Dhananjay Vijay Gavali
// Roll No: DSEITA 174

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int n, front = -1, rear = -1;

void enqueue();
void dequeue();
void display();

int main()
{
    printf("Enter Size of queue: ");
    scanf("%d", &n);
    int arr[10];
    int opt;
    do
    {
        printf("\n==========Menu==============");
        printf("\n================================");
        printf("\n\tPress 1 : Enqueue\n\tPress 2 : Dequeue\n\tPress 3 : Display\n\tPress 0 : Exit\n");

        printf(" Press: ");
        scanf("%d", &opt);
        printf("\n");
        switch (opt)
        {
        case 0:

            break;
        case 1:
            enqueue(arr);
            break;
        case 2:
            dequeue(arr);
            break;
        case 3:
            display(arr);
            break;

        default:
            break;
        }

        getchar();
    } while (opt != 0);
}

void enqueue(int arr[])
{
    if ((rear + 1) % n == front)
    {
        printf("\nQueue is Full\n");
        return;
    }
    printf("Enter Data: ");
    int data;
    scanf("%d", &data);

    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
        rear = (rear + 1) % n;

    arr[rear] = data;

    printf("Data Enqueued....\n");
}

void dequeue(int arr[])
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is Empty\n");
        return;
    }
    if (front == rear)
    {
        front = -1;
        rear = -1;
        return;
    }

    front = (front + 1) % n;

    printf("Data deQueued Sucessfully....\n");
}

void display(int arr[])
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is Empty\n");
        return;
    }

    if (rear >= front)
    {
        for (i = front; i <= rear; i++)
            printf("%d ", arr[i]);
    }
    else
    {
        for (i = front; i < n; i++)
            printf("%d ", arr[i]);

        for (i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
    }
    printf("\n\n");
}