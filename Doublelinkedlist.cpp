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
    }
};