#include<stdio.h>
#include<stdlib.h>

struct linked_list{
   int data;
   struct linked_list *next;
   struct linked_list *prev;
};

typedef struct linked_list node;
node *head = NULL, *tail = NULL;

node* getNewNode(int value);
void printLinkedListForward();
void insertAtTail(int val);
void insertAtFront(int val);
void insertAtMiddle(int val, int pos);
void deleteDoublylist(int pos);

int main()
{
    int a=4,b=34,c=12,d=89,e=61,f=19;
    //create linked list
    insertAtTail(a);
    insertAtTail(b);
    insertAtFront(c);
    printLinkedListForward();
    insertAtMiddle(d,2);
    printLinkedListForward();
    deleteDoublylist(9);
    printLinkedListForward();

    return 0;
}

node* getNewNode(int value)
{
    node *tempNode;
    tempNode = (node *) malloc(sizeof(node));
    tempNode -> data = value;
    tempNode -> next = NULL;
    tempNode -> prev = NULL;

    return tempNode;
}

void insertAtTail(int val)
{
    node *newNode = getNewNode(val);

    if(head == NULL)  //for 1st element
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail -> next = newNode;  //tail is global. newNode will be next of tail
    newNode -> prev = tail;
    tail = newNode;          //newNode will be tail as it is the newest last node
}

void insertAtFront(int val)
{
    node *newNode = getNewNode(val);

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    head ->prev = newNode;
    newNode ->next = head;
    head = newNode;
}

void insertAtMiddle(int val, int pos)
{
    int i;
    node *newNode = getNewNode(val);

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    node *temp = (node *)malloc(sizeof(node));
    temp = head;
    i = 1;

    while(i < pos-1 && temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void deleteDoublylist(int pos)
{
    if(head == NULL)  //list empty
        return;

    if(pos == 1)      //delete head node
    {
        head = head->next;

        if(head->next == NULL)
            tail = NULL;
        else
            head->next->prev = NULL;

        return;
    }
    node *temp = (node *)malloc(sizeof(node));
    node *tempAnother = (node *)malloc(sizeof(node));
    int i = 1;
    temp = head;

    while((i < pos) && (temp->next != NULL))
    {
        temp = temp->next;
        i++;
    }

    if(i == pos)
    {
        tempAnother = temp->prev;
        tempAnother ->next = temp->next;

        if(temp->next == NULL)     //temp is the last node
            tail = tempAnother;
        else
            temp->next->prev = tempAnother;

        free(temp);
    }
    else
        printf("Position %d doesn't exist!\n\n",pos);
}

void printLinkedListForward()
{
    printf("Updated linked list in forward order:\n");

    node *myList;
    myList = head;
    while(1)
    {
        if((head == NULL) | (tail == NULL))
            break;

        printf("%d ", myList ->data);

        if(myList == tail)
            break;

        myList = myList ->next;
    }
    puts("\n");
}

