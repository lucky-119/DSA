/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lakshay
 *
 * Created on 26 January, 2018, 7:03 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
struct q
{
    int a;
    struct q *p;
}*temp;
struct q *f=NULL;
struct q *r=NULL;
void insert()
{
    int item;
    scanf("%d",&item);
    temp=(struct q *)malloc(sizeof(struct q));
    temp->a=item;
    if(f==NULL)
    {
        f=temp;
        r=temp;
    }
    else
    {
        r->p=temp;
        r=temp;
    }
    temp->p=NULL;
}

void delete()
{
    if(f==NULL)
    {
        printf("Queue Empty");
    }
    else if(f->p==NULL)
    {
        temp=f;
        f=NULL;
        r=NULL;
    }
    else
    {
        temp=f;
        f=f->p;
    }
    
}

void display()
{
    if(f==NULL)
    {
        printf("Queue Empty");
    }
    else
    {
        temp=f;
        while(temp!=r)
        {
            printf("%d\n",temp->a);
            temp=temp->p;
        }
        printf("%d\n",temp->a);
        temp=temp->p;
    }
}
int main(int argc, char** argv) {
    char ans;
    do
    {
        printf("1)Insert\n2)Delete\n3)Display\nEnter choice: ");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
        }
        printf("\n\nDo you want to continue?");
        scanf("%s",&ans);
    }while(ans=='y');
    return (EXIT_SUCCESS);
}

