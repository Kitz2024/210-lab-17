#include <iostream>
using namespace std;

const int SIZE = 7;

struct Node
{
    float value;
    Node *next;
};

// Function Prototypes
void output(Node *head);
Node *createLinkedList(int size);
void deleteNode(Node *&head, int index);
void insertNode(Node *&head, int index, float value);
void deleteLinkedList(Node *&head);

int main()
{
    Node *head = createLinkedList(SIZE);
    output(head);

    // Deleting a Node Fix
    int deleteIndex;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> deleteIndex;
    deleteNode(head, deleteIndex);
    output(head);

    // insert a Node Fix
    int insertIndex;
    float insertValue = 10000;
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> insertIndex;
    insertNode(head, insertIndex, insertValue);
    output(head);

    // deleting the linked list
    deleteLinkedList(head);
    output(head);

    return 0;
}
// Function implementations
void output(Node *head)
{
    if (!head)
    {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = head;
    while (current)
    {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

Node *createLinkedList(int size)
{
    Node *head = nullptr;
    for (int i = 0; i < size; i++)
    {
        int tmp_val = rand() % 100;
        Node *newNode = new Node;
        newNode->value = tmp_val;
        newNode->next = head;
        head = newNode;
    }
    return head;
}

void deleteNode(Node *&head, int index)
{
    if (index < 1 || index > SIZE)
    {
        cout << "Invalid index.\n";
        return;
    }

    if (index == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *prev = head;
    Node *current = head;
    for (int i = 1; i < index; i++)
    {
        prev = current;
        current = current->next;
    }

    prev->next = current->next;
    delete current;
}

void insertNode(Node *&head, int index, float value)
{
    if (index < 1 || index > SIZE + 1)
    {
        cout << "Invalid index.\n";
        return;
    }

    if (index == 1)
    {
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *prev = head;
    Node *current = head;
    for (int i = 1; i < index; i++)
    {
        prev = current;
        current = current->next;
    }

    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = current;
    prev->next = newNode;
}

void deleteLinkedList(Node *&head)
{
    Node *current = head;
    while (current)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}