//
//  linkedlist.c
//
//  Created by Lakshay Arora on 08/02/18.
//

#include <stdio.h>
#include <stdlib.h>

struct ll
{
    int value;
    struct ll *p;
    
}*temp,*head=NULL,*temp2;

void ib()
{
    temp=(struct ll *)malloc(sizeof(struct ll));
    printf("\nEnter value of node: ");
    scanf("%d",&temp->value); temp->p=head;
    head=temp;
    printf("Node Inserted");
}

void ii()
{
    temp=(struct ll *)malloc(sizeof(struct ll));
    printf("\nEnter value of node: ");
    scanf("%d",&temp->value);
    printf("Enter index at which element should be inserted: ");
    int i,x;     scanf("%d",&x);     temp2=head;
    for(i=0;i<x-1;i++)
    {
        if(temp2->p==NULL)
        {
            printf("Error! Index exceeds maximum value");
            return;
        }
        temp2=temp2->p;
    }
    temp->p=temp2->p;
    temp2->p=temp;
    printf("Node Inserted");
}

void rb()
{
    if(head!=NULL)
    {
        temp=head;
        head=temp->p;
        free(temp);
        printf("\nNode Deleted");
    }
    else
    { printf("Linked List is Empty");
    }
}

void ri()
{
    if(head==NULL)
    {
        printf("Linked List is Empty");
        return;
    }
    printf("Enter index at which element should be deleted: ");
    int i,x;     scanf("%d",&x);     temp2=head;
    for(i=0;i<x-1;i++)
    {
        if(temp2->p==NULL)
        {
            printf("Error! No such Index");
            return;
        }
        temp2=temp2->p;
    }
    temp=temp2->p;
    temp2->p=temp->p;
    free(temp);
    printf("\nNode Deleted");
}

void display()
{
    if(head!=NULL)
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("\n%d",temp->value);
            temp=temp->p;
        }
    }
    else
    {
        printf("Linked List is Empty");
    }
}

int main()
{
    char ans;
    do
    {
        system("cls");
        printf("\t\t\t Welcome To The LUCKY Software\n\n");
        printf("Main Menu\n\n1) Insert Element at the Beginning \n2) Insert Element Inbetween \n3) Delete Element from the Beginning \n4) Delete Element Inbetween \n5) Display \n\nEnter choice: ");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                ib();
                break;
            case 2:
                ii();
                break;
            case 3:
                rb();
                break;
            case 4:
                ri();
                break;
            case 5:
                display();
                break;
            default:
                printf("\n\nError");
        }
        printf("\n\nDo you want to continue? (y/n) ");
        scanf("%s",&ans);
    }while(ans=='y');
    return 0;
}

