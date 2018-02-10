/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lakshay
 *
 * Created on 26 January, 2018, 6:11 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int q[10],f=-1,r=-1;
void insert()
{
    if(f+r==9)
    {
        printf("Queue Full");
    }
    else
    {
        int item;
        scanf("%d",&item);
        if(f==-1)
        {
            f=0;
            r=0;
        }
        else 
        {
            r=(r+1)%10;
        }
        q[r]=item;
        printf("Element Inserted");
    }
}

void delete()
{
    if(f==-1)
    {
        printf("Queue Empty");
    }
    else
    {
        if(f==r)
            f=r=-1;
        f=(f+1)%10;
        printf("Element deleted");
    }
}

void display()
{
    if(f==-1)
    {
        printf("Queue Empty");
    }
    for(int i=f;i<=r;i++)
    {
        printf("%d",q[i]);
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

