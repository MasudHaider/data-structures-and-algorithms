#include <iostream>
#include<cstdlib>

using namespace std;

struct ListNode{
    int data;
    ListNode *next;
};

class LinkedList
{
    private : ListNode *head, *tail;
    public : LinkedList()
    {
        head = NULL;
        tail = NULL;
    };

    void CreateNode(int value)
    {
        ListNode *temp = new ListNode;
        temp -> data = value;
        temp -> next = NULL;
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail -> next = temp;
            tail = temp;
        }
    }

    //Insertion
    void InsertLinkedList(ListNode **head, int value, int position)
    {
        int k = 1;
        ListNode *p, *q, *newNode;
        newNode = new ListNode;

        if(!newNode)
        {
            cout << "Memory error" << endl;
            return;
        }

        newNode -> data = value;
        p = *head;

        //insert at the beginning
        if(position == 1)
        {
            newNode -> next = p;
            *head = newNode;
        }
        else{
            //Traverse the list until the position where we want to insert
            while((p != NULL) && (k < position))
            {
                k++;
                q = p;
                p = p -> next;
            }

            q -> next = newNode;
            newNode -> next = p;
        }
    }

    void PrintList()
    {
        ListNode *localhead = new ListNode;
        localhead = head;
        int nodeCounter = 0;
        cout<<"Elements are:"<< endl;
        while(localhead != NULL)
        {
            cout<< localhead->data <<endl;
            localhead = localhead -> next;
            nodeCounter++;
        }
        cout<<"Nodes: "<<nodeCounter<<endl;
    }

    void DeleteNodeFromLinkedList(ListNode **head, int position)
    {
        int k = 1;
        ListNode *p, *q;
        if(*head == NULL)
        {
            cout<<"list empty"<<endl;
            return;
        }
        p = *head;
        //from beginning
        if(position == 1)
        {
            *head = (*head) -> next;
            free(p);
            return;
        }
        else{
            //traverse the list until arriving at the position from which we want to delete
            while((p != NULL) && (k < position))
            {
                k++;
                q = p;
                p = p -> next;
            }
            if(p == NULL)
                cout<<"Position does not exist"<<endl;
            else{
                q -> next = p -> next;
                free(p);
            }
        }
    }
};

int main()
{

    LinkedList listobj;
    listobj.CreateNode(12);
    listobj.CreateNode(40);
    listobj.PrintList();

    return 0;
}
