#include<stdio.h>
#include<stdlib.h>

struct linked_list{
   int data;
   struct linked_list *next;
};

typedef struct linked_list node;
node *head = NULL, *tail = NULL;

void insertAtHead(int value);
void insertAtTail(int value);
void insertAtMiddle(int value, int pos);
void deleteHead();
void deleteTail();
void deleteAtMiddle(int position);
int getListLength();
void printList();

int main()
{
    int a=4,b=34,c=12,d=89,e=61,f=19,pos=3;

    printf("insert at head %d\n", a);
    insertAtHead(a);
    printList();
    printf("insert at head %d\n", b);
    insertAtHead(b);
    printList();
    printf("insert at tail %d\n",c);
    insertAtTail(c);
    insertAtTail(e);
    printList();
    printf("insert value %d, at position %d\n",d,pos);
    insertAtMiddle(d,pos);
    printList();
    printf("delete head node\n");
    deleteHead();
    printList();
    printf("delete tail node\n");
    deleteTail();
    printList();
    printf("delete node at position %d\n",pos);
    deleteAtMiddle(pos);
    printList();

    return 0;
}

void deleteHead()
{
    if(head == NULL)
        return;

    node *temp = head;
    tail ->next = head ->next;
    head = head->next;

    free(temp);
}

void deleteTail()
{
    if(head == NULL)
        return;
    node *temp = head;
    node *current = head;

    while(current->next != head)
    {
        temp = current;
        current = current->next;
    }
    temp -> next = head;
    tail = temp;
    free(current);
}

void deleteAtMiddle(int position)
{
    if(head == NULL)
        return;

    if(position == 1){
        deleteHead();
        return;
    }

    node *temp;
    node *current = head;
    int count = 0;

    do{
        count++;
        temp = current;
        current = current->next;
    }while((current->next != head) && (count < position-1));

    if(count == position-1)
    {
        if(current == tail){
            deleteTail();
            return;
        }

        temp->next = current->next;
        free(current);
        return;
    }
    printf("position %d doesn't exist to delete\n",position);
}

int getListLength()
{
    if(head == NULL)
        return 0;

    int count = 0;
    node *currentNode = head;

    do{
        count++;
        currentNode = currentNode->next;
    }while(currentNode != head);

    return count;
}

void insertAtHead(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = newNode;

    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    else{
        newNode ->next = head;
        tail ->next = newNode;
        head = newNode;
    }
}

void insertAtTail(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = newNode;

    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    else{
        newNode ->next = head;
        tail ->next = newNode;
        tail = newNode;
    }
}

void insertAtMiddle(int value, int pos)
{
    if(pos == 1){
        insertAtHead(value);
        return;
    }
    else if(pos > 1 && head != NULL)
    {
        node *current = head;
        node *temp = (node *)malloc(sizeof(node));
        int count = 0;

        do{
            count++;
            temp = current;
            current = current->next;
        }while((current->next != head) && (count < pos-1));

        if(count == pos-1){
            if(temp == tail)
                insertAtTail(value);
            else{
                node *newNode = (node *)malloc(sizeof(node));
                newNode->data = value;

                temp->next = newNode;
                newNode->next = current;
            }
            return;
        }
    }
    printf("position %d doesn't exist!\n",pos);
}

void printList()
{
    if(head == NULL)
        return;
    node *current = head;

    do{
         printf("%d ",current->data);
         current = current->next;
    }while(current != head);

    printf("\nList length: %d\n",getListLength());
    puts("\n");
}



