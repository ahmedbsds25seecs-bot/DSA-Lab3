#include <iostream>
#include <string>
using namespace std;

class StringPool
{
private:
    string* stringPool;
    int currentSize;
    int maxSize;

public:
    //Constructor creates space for a maximum of 5 strings
    StringPool()
    {
        maxSize = 5;
        currentSize = 0;
        stringPool = new string[maxSize];
    }
    //Adds a string to the pool
    void addString(string str)
    {
        if (currentSize < maxSize)
        {
            stringPool[currentSize] = str;
            currentSize++;

            cout << "String added successfully." << endl;
        }
        else
            cout << "Pool is full. Cannot add more strings." << endl;
        
    }
    //Removes a string without deleting the allocated pool memory
    void removeString(string str)
    {
        for (int i = 0; i < currentSize; i++)
        {
            if (stringPool[i] == str)
            {
                //Shift the remaining strings to fill the empty position
                for (int j = i; j < currentSize - 1; j++)
                    stringPool[j] = stringPool[j + 1];
                
                currentSize--;

                cout << "String removed successfully." << endl;
                return;
            }
        }
        cout << "String not found." << endl;
    }
    //Displays all strings currently in the pool
    void displayPool()
    {
        if (currentSize == 0)
        {
            cout << "Pool is empty." << endl;
            return;
        }
        cout << "\nCurrent Pool:" << endl;

        for (int i = 0; i < currentSize; i++)
        {
            cout << i + 1 << ". " << stringPool[i] << endl;
        }
    }
    //Releases the dynamically allocated memory
    ~StringPool()
    {
        delete[] stringPool;
        stringPool = nullptr;

        cout << "\nPool memory released successfully." << endl;
    }
};
int main()
{
    StringPool pool;

    int choice;
    string str;

    do
    {
        cout << "\n===== STRING POOL MENU =====" << endl;
        cout << "1. Add String" << endl;
        cout << "2. Remove String" << endl;
        cout << "3. Display Pool" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        //Check that the user enters a number
        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number from 1 to 4." << endl;

            cin.clear();
            cin.ignore(1000, '\n');

            continue;
        }

        cin.ignore(1000, '\n');

        switch (choice)
        {
            case 1:
                cout << "Enter a string to add: ";
                getline(cin, str);

                if (str.empty())
                {
                    cout << "Empty string cannot be added." << endl;
                }
                else
                {
                    pool.addString(str);
                }
                break;

            case 2:
                cout << "Enter a string to remove: ";
                getline(cin, str);

                if (str.empty())
                {
                    cout << "Empty string cannot be removed." << endl;
                }
                else
                {
                    pool.removeString(str);
                }
                break;

            case 3:
                pool.displayPool();
                break;

            case 4:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
                break;
        }

    } while (choice != 4);

    return 0;
}

