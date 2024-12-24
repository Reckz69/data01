#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    Node *prev;
    int data;

    // constructor
    Node(int d)
    {
        this -> data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

void InsertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
        return;
    }

    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
        return;
    }
}



void InsertAtTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        Node *temp = new Node(d);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        return;
    }
}

void InsertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        InsertAtHead(head, tail, d);
    }

    int cnt = 1;
    Node *temp = head;

    while (cnt < position - 1)
    {
        temp->next = temp;
        cnt++;
    }

    if (temp->next == NULL)
    {
        InsertAtTail(head, tail, d);
    }

    Node *NodeToInsert = new Node(d);
    NodeToInsert->next = temp->next;
    NodeToInsert->prev = temp;
    temp->next->prev = NodeToInsert;
    temp->next = NodeToInsert;
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp =  temp -> next;
        }
        cout<<endl;
}



int main(){
    Node*node1 = new Node(10);
    Node*head = node1;
    Node*tail = node1;

    InsertAtHead(head, tail, 20);
    print(head);

    InsertAtTail(head, tail, 30);
    print(head);

    InsertAtPosition(head, tail, 2, 35);
    print(head);
}
