#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

// function to insert a node at a particular position
void insertNode(Node *&tail, int element, int data)
{
    // empty list
    if (tail == NULL)
    {
        Node *nodeToInsert = new Node(data);
        tail = nodeToInsert;
        nodeToInsert->next = nodeToInsert;
    }
    else
    {
        // non empty list
        // assuming that the element is present in the list
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *nodeToInsert = new Node(data);
        nodeToInsert->next = curr->next;
        curr->next = nodeToInsert;
    }
}

// function to delete a node in the circular linked list
void deleteNode(Node *&tail, int value)
{
    //empty list
    if (tail == NULL)
    {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = tail->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        // in case of only 1 node
        if (curr == prev)
        {
            tail = NULL;
        }
        else if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

// function to traverse and print the linked list
void print(Node *&tail)
{
    Node *temp = tail;
    if (tail == NULL)
    {
        cout << "List is empty" << endl
             << endl;
        return;
    }
    else
    {
        do
        {
            cout << tail->data << " ";
            tail = tail->next;
        } while (tail != temp);
        cout << endl;
    }
}

int main()
{
    Node *tail = NULL;
    print(tail);

    insertNode(tail, 1, 5);
    print(tail);
    insertNode(tail, 5, 2);
    print(tail);
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 2, 10);
    print(tail);
    insertNode(tail, 10, 99);
    print(tail);

    deleteNode(tail, 5);
    print(tail);
    deleteNode(tail, 99);
    print(tail);
    deleteNode(tail, 2);
    print(tail);

    return 0;
}