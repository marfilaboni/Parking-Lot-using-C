#include<stdio.h>
#include<stdlib.h>
#include<windows.h>



struct node
{
    int val;
    struct node* next;
};

typedef struct node node;
node *head = NULL;
int T=0;


void insert (int);
void del(int);
void display(node*);
void count(node*);

int main()
{
    int  a, n;
    count(head);
    do
    {
    printf("\n\n\nselected-\n");
    printf("For parking the car press 1\nFor leaving the car press 2\nFor Exit enter 0\n\n Please Press: ");
    scanf("%d", &a);
    switch (a)
    {
    case 1:
    {
    if(T<10){
        printf("Inter the car number you want to parking:");
        scanf("%d", &n);
        insert (n);
        system("cls");
        }
    else
        printf("\nPlease deallocate lot first\n");

    count(head);
    display(head);
    break;
    }

    case 2:
    {
        printf("Inter the car number you want to leaving:");
        scanf("%d", &n);
        system("cls");
        del(n);
        count(head);
        display(head);
    break;
    }
    default:
        printf("Wrong Input, press again\n");
        break;
    }
    } while (a!=0);


}


void insert(int num)
{
    node *p;
    p=(node*)malloc(sizeof(node));
    p->val=num;
    p->next=head;
    head=p;
}


void del(int num)
{
    struct node *temp, *prev;
    temp=head;
    while(temp!=NULL)
    {
    if(temp->val==num)
    {
        if(temp==head)
        {
        head=head->next;
        free(temp);
        printf("Deallocated");
        return;
        }
        else
        {
        prev->next=temp->next;
        free(temp);
        printf("Deallocated");
        return ;
        }
    }
    else
    {
        prev=temp;
        temp= temp->next;
    }
    }
    printf("\nThis car is not the parking plot");
    return;
}


void display(node *p)
{
    printf("Available car no:");
    while(p!=NULL){
        printf("%d  ",p->val);
        p=p->next;
    }
}


void count(node *p)
{
    int total=0;
    while( p!=NULL )
    {
        p=p->next;
        total++;
    }
    T=total;
    printf("\nTotal parking lot : %d\n",10-total);
    return;
}
