/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lakshay
 *
 * Created on 26 January, 2018, 6:51 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
struct stack
{
    int a;
    struct stack *p;
    
}*temp;
struct stack *top=NULL;
void push()
{
    int item;
    scanf("%d",&item);
    temp=(struct stack *)malloc(sizeof(struct stack));
    temp->a=item;
    temp->p=top;
    top=temp;
}

void pop()
{
    if(top==NULL)
    {
        printf("Stack Empty");
    }
    else
    {
        temp=top;
        top=top->p;
    }
}

void display()
{
    if(top==NULL)
    {
        printf("Stack Empty");
    }
    else
    {
        temp=top;
        while(temp!=NULL)
        {
            printf("%d\n",temp->a);
            temp=temp->p;
        }
    }
        
}
int main(int argc, char** argv) 
{
    char ans;
    
    do
    {
        printf("1)Push\n2)Pop\n3)Display\nEnter choice: ");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
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

