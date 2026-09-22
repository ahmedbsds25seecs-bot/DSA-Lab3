#include <iostream>
using namespace std;
//Each node stores a value and the address of the next node
struct Node
{
    int data;
    Node* next;
};
//Adds a new node at the beginning of the list
void insertAtHead(Node*& head, int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = head;

    head = newNode;

    cout << "Node inserted at head successfully." << endl;
}
//Adds a new node at the 3rd position
void insertAtThird(Node*& head, int value)
{
    //At least two nodes are needed before inserting at position 3
    if (head == nullptr || head->next == nullptr)
    {
        cout << "Error: The list must have at least 2 nodes." << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;

    //Move to the second node and insert after it
    Node* current = head->next;

    newNode->next = current->next;
    current->next = newNode;

    cout << "Node inserted at 3rd position successfully." << endl;
}
//Displays all nodes from head to NULL
void displayList(Node* head)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    Node* current = head;

    cout << "\nLinked List: ";

    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}
//Deletes the last node in the list
void deleteLast(Node*& head)
{
    if (head == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    //If there is only one node, delete it directly
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;

        cout << "Last node deleted successfully." << endl;
        return;
    }
    Node* current = head;

    //Stop at the second-last node
    while (current->next->next != nullptr)
        current = current->next;

    delete current->next;
    current->next = nullptr;

    cout << "Last node deleted successfully." << endl;
}
//Counts the number of nodes in the list
int countNodes(Node* head)
{
    int count = 0;
    Node* current = head;

    while (current != nullptr)
    {
        count++;
        current = current->next;
    }

    return count;
}
//Reverses the list using an iterative method
void reverseList(Node*& head)
{
    Node* previous = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    //Change the direction of each link one by one
    while (current != nullptr)
    {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    head = previous;

    cout << "List reversed successfully." << endl;
}
//Searches for a value and displays its position
void searchValue(Node* head, int value)
{
    Node* current = head;
    int position = 1;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            cout << "Value found at position: " << position << endl;
            return;
        }

        current = current->next;
        position++;
    }

    cout << "Value not found in the list." << endl;
}
//Deletes all remaining nodes before the program ends
void destroyList(Node*& head)
{
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main()
{
    Node* head = nullptr;

    int choice;
    int value;

    do
    {
        cout << "\n===== SINGLY LINKED LIST MENU =====" << endl;
        cout << "1. Insert at Head" << endl;
        cout << "2. Insert at 3rd Position" << endl;
        cout << "3. Display List" << endl;
        cout << "4. Delete Last Node" << endl;
        cout << "5. Count Nodes" << endl;
        cout << "6. Reverse List" << endl;
        cout << "7. Search Value" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";

        //Make sure the user enters a number
        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number from 1 to 8." << endl;

            cin.clear();
            cin.ignore(1000, '\n');

            continue;
        }
        cin.ignore(1000, '\n');

        switch (choice)
        {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;

                if (cin.fail())
                {
                    cout << "Invalid value. Please enter an integer." << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else
                    insertAtHead(head, value);
                
                break;

            case 2:
                cout << "Enter value to insert at 3rd position: ";
                cin >> value;

                if (cin.fail())
                {
                    cout << "Invalid value. Please enter an integer." << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else
                    insertAtThird(head, value);
                
                break;

            case 3:
                displayList(head);
                break;

            case 4:
                deleteLast(head);
                displayList(head);
                break;

            case 5:
                cout << "Number of nodes: " << countNodes(head) << endl;
                break;

            case 6:
                if (head == nullptr)
                    cout << "List is empty. Nothing to reverse." << endl;
                else
                {
                    reverseList(head);
                    displayList(head);
                }
                break;

            case 7:
                cout << "Enter value to search: ";
                cin >> value;

                if (cin.fail())
                {
                    cout << "Invalid value. Please enter an integer." << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else
                    searchValue(head, value);
                
                break;

            case 8:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a number from 1 to 8." << endl;
                break;
        }

    } while (choice != 8);
    //Free all dynamically allocated nodes before ending the program
    destroyList(head);

    return 0;
}

