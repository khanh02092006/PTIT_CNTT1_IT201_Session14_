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
 node * ceatenode(int value)
 {
     node *newnode=(node *)malloc(sizeof(node));
     if(newnode==NULL) return NULL;
     newnode->data=value;
     newnode->next=NULL;
     return newnode;
 }
 stack * createstack()
 {
     stack* newstack=(stack *)malloc(sizeof(stack));
     if(newstack==NULL) return NULL;
     newstack->head=NULL;
     return newstack;

 }
void push (stack * newstack,int value)
 {
     node *newnode=ceatenode(value);
     if (newnode==NULL) return;
     newnode->next=newstack->head;
     newstack->head=newnode;
 }
void themvaostack(stack* newstack)
 {
     int n;
     int value;
     do
     {
         printf(" nhap so luong muon them vao trong stack");
         scanf("%d",&n);
         if (n<=0)
         {
             printf(" khong hop le");

         }
     } while (n<=0);
     for (int i=0; i<n; i++)
     {
         do
         {
             printf(" nhap phan tu thu %d ",i+1);
             scanf("%d",&value);
             if (value<=0)
             {
                 printf(" khong hop le");;
             }

         } while (value<=0);
         push(newstack,value);
     }
 }
void printf_lit(stack* newstack) {
     if (newstack->head == NULL) {
         printf("stack rong\n");
         return;
     }


     int count = 0;
     node *temp = newstack->head;
     while (temp != NULL) {
         count++;
         temp = temp->next;
     }

     // Cấp phát mảng đúng kích thước
     int *arr = (int *)malloc(count * sizeof(int));
     if (arr == NULL) {
         printf("Khong cap phat duoc mang\n");
         return;
     }


     temp = newstack->head;
     for (int i = 0; i < count; i++) {
         arr[i] = temp->data;
         temp = temp->next;
     }

     // In ra theo FIFO
     printf("Cac phan tu trong stack (FIFO): ");
     for (int i = count - 1; i >= 0; i--) {
         printf("%d ", arr[i]);
     }
     printf("\n");

     free(arr);
 }


int main(void)
{
    stack *newstack=createstack();
     if (newstack==NULL)
     {
         printf("tao ngan xep khong thanh cong");
         return 1;
     }
     themvaostack(newstack);
     printf_lit(newstack);

    return 0;
}