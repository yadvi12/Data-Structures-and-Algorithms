#include <bits/stdc++.h>
using namespace std;

// creating the node class
class Node
{
public:
    int data;
    Node *next;

    // creating the constructor for the Node class
    Node(int data)
    {
        this->data = data;
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

// function to print/traverse the linked list
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

// function to insert a node at the head
void insertAtHead(Node *&head, int data)
{
    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = head;
    head = nodeToInsert;
}

// function to insert a node at the tail
void insertAtTail(Node *&tail, int data)
{
    Node *nodeToInsert = new Node(data);
    tail->next = nodeToInsert;
    tail = nodeToInsert;
}

// function to insert a node at a particular position
void insert(Node *&head, Node *&tail, int position, int data)
{
    // insert at starting position
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // inserting at last position
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// function to delete a node by it's position
void deleteNode(Node *&head, int position)
{
    // deleting the first node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    // created a new node
    Node *node1 = new Node(5);

    // printing the data value and next pointer value of node 1
    // cout << endl;
    // cout << "Data at node 1: " << node1->data << endl;
    // cout << "Next address at node 1: " << node1->next << endl;
    // cout << endl
    //      << endl;

    // head and tail pointing to node 1
    Node *head = node1;
    Node *tail = node1;

    print(head);
    cout << endl;

    // inserting the nodes from the head and printing the linked list
    insertAtHead(head, 3);
    print(head);
    cout << endl;

    insertAtHead(head, 1);
    print(head);
    cout << endl;

    // inserting the nodes from the head and printing the linked list
    insertAtTail(tail, 10);
    print(head);
    cout << endl;

    insertAtTail(tail, 15);
    print(head);
    cout << endl;

    // inserting the node at some particular position
    insert(head, tail, 2, 2);
    print(head);
    cout << endl;

    insert(head, tail, 1, 0);
    print(head);
    cout << endl;

    insert(head, tail, 8, 20);
    print(head);
    cout << endl;

    // deleting the nodes and printing the linked list
    deleteNode(head, 1);
    print(head);
    cout << endl;

    deleteNode(head, 3);
    print(head);
    cout << endl;

    deleteNode(head, 6);
    print(head);
    cout << endl;

    return 0;
}
