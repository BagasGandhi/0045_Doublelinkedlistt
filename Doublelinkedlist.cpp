#include <iostream>
#include <string>
using namespace std;

class Node 
{
public:
    int no;
    string name;
    Node *next;
    Node *prev; 
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "Enter the roll number of the student: ";
        cin >> nim;

        // Step 1: Allocate memory for new node
        Node *newnode = new Node();

        // Step 2: Assign values to the data fields
        newnode->no = nim;

        // Step 3: Prompt for insertion if list is empty or not
        if (START == NULL || nim <= START->no)
        {
            if (START != NULL && nim == START->no)
            {
                cout << "Duplicate roll numbers not allowed" << endl;
                return;
            }

            newnode->next = START;

            if (START != NULL)
                START->prev = newnode;

            newnode->prev = NULL;

            START = newnode;
            return;
        }

        // Step 4: Locate the node before the point of insertion
        Node *current = START;
        while (current->next != NULL && current->next->no < nim)
            current = current->next;

        if (current->next != NULL && current->next->no == nim)
        {
            cout << "Duplicate roll numbers not allowed" << endl;
            return;
        }

        newnode->next = current->next;

        if (current->next != NULL)
            current->next->prev = newnode;

        newnode->prev = current;
        current->next = newnode;
    }

    void deleteNode()
    {
        if (START == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        int rollNo;
        cout << "Enter the roll number of the student whose record is to be deleted: ";
        cin >> rollNo;

        Node *current = START;

        while (current != NULL && current->no != rollNo)
            current = current->next;

        if (current == NULL)
        {
            cout << "Record not found" << endl;
            return;
        }

        if (current == START)
        {
            START = current->next;
            if (START != NULL)
                START->prev = NULL;
        }
        else
        {
            if (current->next != NULL)
                current->next->prev = current->prev;

            current->prev->next = current->next;
        }

        delete current;
        cout << "Record with roll number " << rollNo << " deleted" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *current = START;

        cout << "Records in ascending order of roll number are:\n";
        while (current != NULL)
        {
            cout << current->no << " ";
            current = current->next;
        }
        cout << endl;
    }
};