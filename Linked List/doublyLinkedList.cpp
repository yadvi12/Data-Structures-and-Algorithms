#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // creating a constructor for node class
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    // creating the destructor for the Node class
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

// function to insert a node at the head
void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *nodeToInsert = new Node(data);
        head = nodeToInsert;
        tail = nodeToInsert;
    }
    else
    {
        Node *nodeToInsert = new Node(data);
        nodeToInsert->next = head;
        head->prev = nodeToInsert;
        head = nodeToInsert;
    }
}

// function to insert a node at the tail
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *nodeToInsert = new Node(data);
        head = nodeToInsert;
        tail = nodeToInsert;
    }
    else
    {
        Node *nodeToInsert = new Node(data);
        tail->next = nodeToInsert;
        nodeToInsert->prev = tail;
        tail = nodeToInsert;
    }
}

// function to insert a node at a particular position
void insert(Node *&head, Node *&tail, int position, int data)
{
    //insert at Start
    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    //inserting at Last Position
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node *nodeToInsert = new Node(data);
    nodeToInsert->prev = temp;
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
}

// function to delete a node in the linked list
void deleteNode(Node *&head, int position)
{
    //deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *temp = head;
        Node *back = NULL;
        int count = 1;
        while (count < position)
        {
            back = temp;
            temp = temp->next;
            count++;
        }
        if (temp->next == NULL)
        {
            temp->prev = NULL;
            back->next = temp->next;
            temp->next = NULL;
            delete temp;
        }
        else
        {
            temp->prev = NULL;
            back->next = temp->next;
            temp->next->prev = back;
            temp->next = NULL;

            delete temp;
        }
    }
}

// traversing and printing the linked list
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// gives length of the linked list
int getLength(Node *&head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    cout << endl;

    insertAtHead(head, tail, 5);
    print(head);
    insertAtHead(head, tail, 4);
    print(head);
    insertAtHead(head, tail, 3);
    print(head);
    insertAtTail(head, tail, 6);
    print(head);
    insertAtTail(head, tail, 10);
    print(head);
    insert(head, tail, 2, 100);
    print(head);
    insert(head, tail, 1, 99);
    print(head);
    insert(head, tail, 8, 22);
    print(head);
    deleteNode(head, 2);
    print(head);
    deleteNode(head, 7);
    print(head);
    deleteNode(head, 3);
    print(head);
    // cout << head->next->data << endl;
    // cout << head->next->prev->data << endl;
    cout << "Length of the Linked List: " << getLength(head) << endl;
    cout << endl;
    return 0;
}