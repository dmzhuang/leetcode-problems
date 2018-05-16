#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


typedef struct linklist {
    int data;
    struct linklist* next;
}linknode, *linklistp;


linklistp insert_head(linklistp head, linklistp newnode) {
    //assert(head);
    assert(newnode);

    if(head == NULL) {
        head = newnode;
    }else {
        newnode->next = head;
        head = newnode;
    }
    return head;
}


linklistp insert_tail(linklistp head, linklistp newnode) {
    assert(newnode);

    if(head == NULL) {
        head = newnode;
    }else {
        linklistp temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }
    return head;
}


linklistp insert_local(linklistp head, linklistp newnode) {
    return head;
}


void output(linklistp head) {
    linklistp temp = head;
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    linklistp head = NULL;
    srand(time(0));

    for(int i = 0; i < 10; i++) {
        linklistp newnode = (linklistp)malloc(sizeof(linklist));
        newnode->data = rand() % 100;
        newnode->next = NULL;

        //head = insert_head(head, newnode);
        head = insert_tail(head, newnode);
  
        output(head);
        getchar();
    }

    return 0;
}
