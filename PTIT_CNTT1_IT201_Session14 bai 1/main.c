#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct stack {
    node *head;
} stack;

node* createnode(int value) {
    node *newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Không cấp phát được node\n");
        return NULL;
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

stack* createstack() {
    stack *newstack = (stack*)malloc(sizeof(stack));
    if (newstack == NULL) {
        printf("Không cấp phát được stack\n");
        return NULL;
    }
    newstack->head = NULL;
    return newstack;
}

void push(stack *newstack, int value) {
    node *newnode = createnode(value);
    if (newnode == NULL) return;

    newnode->next = newstack->head;
    newstack->head = newnode;
}

int pop(stack *newstack) {
    if (newstack->head == NULL) {
        printf("Stack rỗng, không thể pop\n");
        return -1;
    }

    node *temp = newstack->head;
    int value = temp->data;
    newstack->head = temp->next;
    free(temp);
    return value;
}

void freestack(stack *newstack) {
    node *current = newstack->head;
    while (current != NULL) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(newstack);
}

void printstack(stack *newstack) {
    node *current = newstack->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(void) {
    stack *newstack = createstack();
    if (newstack == NULL) {
        printf("Tạo stack không thành công\n");
        return 1;
    }

    push(newstack, 10);
    push(newstack, 20);
    push(newstack, 30);

    printstack(newstack);
    printf("Pop: %d\n", pop(newstack));
    printstack(newstack);

    freestack(newstack);
    return 0;
}
