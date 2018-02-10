/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lakshay
 *
 * Created on 26 January, 2018, 5:44 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int stack[10],top=-1;
void push()
{
    if(top==10)
    {
        printf("Stack Full");
        return;
    }
    int item;
    scanf("%d",&item);
    top++;
    stack[top]=item;
    printf("Element inserted");
}

void pop()
{
    if(top==-1)
    {
        printf("Stack Empty");
        return;
    }
    int item;
    item=stack[top];
    top--;
    printf("Element popped %d",item);
}

void display()
{
    if(top==-1)
    {
        printf("Stack Empty");
        return;
    }
    for(int i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
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

