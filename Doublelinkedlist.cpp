#include <iostream>
#include <string>
using namespace std;

class Node 
{
public:
    int noMhs;
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
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        // Step 1: Allocate memory for new node
        Node *newNode = new Node();

        // Step 2: Assign values to the data fields
        newNode->noMhs = nim;

        // Step 3: Insert at the beginning if list is empty or nim is smallest
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate roll numbers not allowed" << endl;
                return;
            }
            // Step 4: newNode.next = START
            newNode->next = START;

            // Step 5: START.prev = newNode (if START exists)
            if (START != NULL)
                START->prev = newNode;

            // Step 6: newNode.prev = NULL
            newNode->prev = NULL;

            // Step 7: Start = newNode
            START = newNode;
            return;
        }

        // insert in between node
        // Step 8: Locate position for insertion
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }
        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }

        // Step 9: Insert between current and current->next
        newNode->next = current->next; // step 9a: newNode.next = current.next
        newNode->prev = current;       // step 9b: newNode.prev = current

        // insert last node
        if (current->next != NULL)
            current->next->prev = newNode; // Step 9c: current.next.prev = newNode

        current->next = newNode; // Step 9d: current.next = newNode
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        cout << "\nEnter the roll number of the student whose record is to be deleted: ";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        // Step 1: Traverse the list to find the node  
        while (current != NULL && current->noMhs != rollNo)    
            current = current->next;

        if (current == NULL)
        {
            cout << "Record not found" << endl;
            return;
        }

        // Step 2: If node is at the beginnintg
        if (current == START)
        {
            START = current->next; // Step 2a: Start = Start.next
            if (START != NULL)
                START->prev = NULL; // Step 2b: Start.prev = NULL
        }
        else
        {
            // Step 3: Link previous node to next of current
            current->prev->next = current->next;

            // Step 4: If current is not the last node
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        // step 5: Delete the node
        delete current;
        cout << "Record with roll number " << rollNo << " deleted" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        //Step 1: Mark first node as currentNode
        Node *currentNode = START;

        cout << "\nRecords in ascending order of roll number are:\n";
        int i = 0;
        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }

    void revtraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        Node *currentNode = START;
        int i = 0;
        while (currentNode->next != NULL)
            currentNode = currentNode->next;

        cout << "\nRecords in descending order of roll number are:\n";
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;

            // Step 3: Move to previous node
            currentNode = currentNode->prev;
            i--;        
        }
        cout << endl;
    }

    void searchData()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "Enter the roll number to search: ";
        cin >> rollNo;

        Node *current = START;

        // Step 1: Traverse to find matching roll number
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        // Step 2: Output result
        if (current == NULL)
        {
            cout << "Record not found\n" << endl;
        }
        else
        {
            cout << "Record found\n" << endl;
            cout << "Roll Number: " << current->noMhs << endl;
        }
    }
};

int main()
{
    DoubleLinkedList list;
    char choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "\n1. Add Record\n";
        cout << "\n2. Delete Record\n";
        cout << "\n3. View Ascending\n";
        cout << "\n4. View Descending\n";
        cout << "\n5. Search Record\n";
        cout << "\n6. Exit\n";
        cout << "\nEnter your choice: ";
        
        cin >> choice;

        switch (choice)
        {
        case '1':
            list.addNode();
            break;
        case '2':
            list.hapus();
            break;
        case '3':
            list.traverse();
            break;
        case '4':
            list.revtraverse();
            break;
        case '5':
            list.searchData();
            break;
        case '6':
            return 0;
        default:
            cout << "Invalid option\n";
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        cout << endl;
        system("clear");    
    } while (choice != '6');
}