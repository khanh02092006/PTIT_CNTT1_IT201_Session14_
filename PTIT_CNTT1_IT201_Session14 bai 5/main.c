#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    typedef  struct node
    {
     int data;
        struct node *next;
    }node;
typedef struct stack
{
    node *head;
}stack;
 node *ceatenode(int value)
 {
     node* newnode=(node*)malloc(sizeof(node));
     if (newnode==NULL) return NULL;
     newnode->data=value;
     newnode->next=NULL;
     return newnode;

 }
stack *createstack()
 {
     stack *newstack=(stack*)malloc(sizeof(stack));
     if (newstack==NULL) return NULL;
     newstack->head=NULL;
     return newstack;
 }
 void push (stack *newstack,int value)
 {
     if (newstack==NULL)
     {
         printf(" rong");
         return;
     }
     node *newnode=ceatenode(value);
     if (newnode==NULL) return;
     newnode->next=newstack->head;
     newstack->head=newnode;

 }
void addstack(stack* newstack)
 {
     int n;
     do
     {
         printf(" nhap so phan tu");
         scanf("%d",&n);
         if (n<=0)
         {
             printf(" loi, nhap lai");
         }
     } while (n<=0);
     int value;
     for (int i=0;i<n;i++)
     {
        do
        {
            printf(" nhap phan tu thu %d",i+1);
            scanf("%d",&value);
            if (value<=0)
            {
                printf(" phan tu khong hop le");

            }
        } while (value<=0);
         push(newstack,value);
     }

 }
int pop(stack *newstack)
 {
     if (newstack->head==NULL)
     {
         printf(" stack rong");
         return 0;
     }
     node *temp = newstack->head;
    int value=temp->data;
     newstack->head=temp->next;
     free(temp);
     return value;


 }
void print_stack(stack *newstack)
 {
     if (newstack->head==NULL)
     {
         printf(" rong");
         return;
     }
     node *temp = newstack->head;
     while (temp!=NULL)
     {
         printf(" %d",temp->data);
         temp=temp->next;

     }
     printf("\n");
 }
int pep(stack *newstack)
 {
     if (newstack->head==NULL)
     {
         printf(" stack rong");
         return -1;
     }
     return newstack->head->data;
 }
int main(void)
{
     stack *newstack = createstack();
     if (newstack == NULL) {
         printf("Khong the tao stack\n");
         return 1;
     }

     addstack(newstack);           // Nhap phan tu vao stack
     printf("Stack ban dau:\n");
     print_stack(newstack);        // In stack

     // Peek (xem phan tu tren dinh)
     int top = pep(newstack);
     if (top != -1) {
         printf("Phan tu tren dinh stack: %d\n", top);
     }

     // Pop (lay phan tu tren dinh)
     int lay = pop(newstack);
     if (lay != 0) {
         printf("Phan tu vua bi lay ra (pop): %d\n", lay);
         printf("Stack sau khi pop:\n");
         print_stack(newstack);
     }

     return 0;
}