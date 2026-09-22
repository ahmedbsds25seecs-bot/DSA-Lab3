#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//Function to check whether the string is a palindrome
bool isPalindrome(string str)
{
    string cleanString = "";

    //Remove spaces and punctuation 
    for (char ch : str)
    {
        if (isalnum(ch))
        {
            cleanString += tolower(ch);
        }
    }
    int start = 0;
    int end = cleanString.length() - 1;

    //Compare characters from both ends
    while (start < end)
    {
        if (cleanString[start] != cleanString[end])
        {
            return false;
        }

        start++;
        end--;
    }
    return true;
}
int main()
{
    string str;
    char choice;

    do
    {
        cout << "Enter a string: ";
        getline(cin, str);

        if (str.empty())
            cout << "String should not be empty" << endl;
        
        else if (isPalindrome(str))
            cout << "The string is a palindrome." << endl;
        
        else
            cout << "The string is not a palindrome." << endl;
        
        cout << "\nPress y to check another string: ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');
    cout << "Program ended." << endl;
    return 0;
}