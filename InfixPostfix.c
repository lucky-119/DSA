//
//  InfixPostfix.c
//  
//
//  Created by Lakshay Arora on 08/02/18.
//


#include <stdio.h>
#include <stdlib.h>

struct ll
{
    char value;
    struct ll *p;
    
}*top,*temp;

void push(char t)
{
    temp=(struct ll *)malloc(sizeof(struct ll)); temp->value=t;
    temp->p=top;
    top=temp;
}

int pop()
{
    if(top==NULL)
    {
        printf("Incorrect Expression");
    }
    temp=top;
    top=temp->p;
    return temp->value;
    free(temp);
}

int priority(char a)
{
    int x;
    if(a=='^')
        x=4;
    else if(a=='*' || a=='/')
        x=3;
    else if(a=='+' || a=='-')
        x=2;
    else
        x=1;
    return x;
}

void post(char input[100])
{
    char a[100],c=0,t,x=0;
    push('(');
    int i;
    for(i=0;input[i]!='\0';i++)
    {
        if(x<0 || x>1)
        {
            printf("Incorrect Expression");
            return;
        }
        if(isalpha(input[i]) || isdigit(input[i]))
        {
            x++;
            a[c]=input[i];
            c++;
        }
        else if(input[i]=='(')
            push('(');
        else if(input[i]==')')
        {
            while(top->value!='(')
            {
                t=pop();
                a[c]=t;
                c++;
            }
            if(top->value=='(')
                t=pop();
            if(top==NULL)
            {
                printf("Incorrect Expression");
                return;
            }
        }
        else
        {
            x--;
            if((priority(input[i]))>=(priority(top->value)))
                push(input[i]);
            else
            {
                while((priority(input[i]))<(priority(top->value)))
                {
                    t=pop();
                    a[c]=t;
                    c++;
                }
                if(top->value=='(')
                        t=pop();
                push(input[i]);
            }
        }
    }
    printf("\nPostfix= ");
    for(i=0;i<c;i++)
        printf("%c",a[i]);
}

main()
{
    top=NULL;
    char input[100];
    char ans;
    do
    {
        system("cls");
        printf("\t\t\t Welcome To The LUCKY Software\n\n");
        printf("Main Menu\n\n1) Infix to Postfix\n\nEnter choice: ");
        int choice;
        scanf("%d",&choice);
        printf("\nEnter Expression: ");
        scanf("%s",&input);
        switch (choice)
        {
            case 1:
                post(input);
                break;
            default:
                printf("\n\nError");
        }
        printf("\n\nDo you want to continue? (y/n) ");
        scanf("%s",&ans);
    }while(ans=='y');
}
