// Challenge
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

*/

#include <iostream>
#include <vector>

using namespace std;

void PrintNumbers (vector <int> &list_integers);
void AddNumber (vector <int> &list_integers);
void MeanOfNumbers (vector <int> &list_integers);
void SmallestNumber (vector <int> &list_integers);
void LargestNumber (vector <int> &list_integers);
void DisplayMenu(void);

void PrintNumbers (vector <int> &list_integers)
{
    if (list_integers.size() == 0)
    {
        cout << "[] - the list is empty" << endl;
    }
    else
    {
        cout << "[ ";
        for (int idx = 0; idx < list_integers.size(); idx++)
        {
            cout << list_integers.at(idx) << " ";
        }
        cout << "]";
    }
    cout << endl << endl;
}

void AddNumber (vector <int> &list_integers)
{
    int numberAdded {0};
    cout << "Enter an integer to add to the list: ";
    cin >> numberAdded;
    list_integers.push_back(numberAdded);
    cout << numberAdded << " added" << endl;
    cout << endl;
}

void MeanOfNumbers (vector <int> &list_integers)
{
    int SumOfList {0};
    if (list_integers.size() == 0)
    {
        cout << "Unable to calculate the mean - no data" << endl;
    }
    else
    {
        for (auto number : list_integers)
        {
            SumOfList += number;
        }
        cout << "The mean is : " << static_cast<double>(SumOfList)/list_integers.size() << endl;
    }
    cout << endl;
}

void SmallestNumber (vector <int> &list_integers)
{
    if (list_integers.size() == 0)
    {
        cout << "Unable to determine the smallest number - list is empty" << endl;
    }
    else
    {
        int smallest = list_integers.at(0);
        for (auto number : list_integers)
        {
            if (number < smallest)
            {
                smallest = number;
            }
        }
        cout << "The smallest number is : " << smallest << endl;
    }
    cout << endl;
}

void LargestNumber (vector <int> &list_integers)
{
    if (list_integers.size() == 0)
    {
        cout << "Unable to determine the largest number - list is empty" << endl;
    }
    else
    {
        int largest = list_integers.at(0);
        for (auto number : list_integers)
        {
            if (number > largest)
            {
                largest = number;
            }
        }
        cout << "The largest number is : " << largest << endl;
    }
    cout << endl;
}

void DisplayMenu(void)
{
    cout << "P - Print numbers"               << endl <<
            "A - Add a number"                << endl <<
            "M - Display mean of the numbers" << endl <<
            "S - Display the smallest number" << endl <<
            "L - Display the largest number"  << endl <<
            "Q - Quit" << endl;
    cout << endl << "Enter your choice:";
}

int main()
{
    char selection {};
    vector <int> list_integers;

    do
    {
        DisplayMenu();
        cin >> selection;

        if ((selection == 'P') || (selection == 'p'))
        {
            PrintNumbers(list_integers);
        }
        else if ((selection == 'A') || (selection == 'a'))
        {
            AddNumber(list_integers);
        }
        else if ((selection == 'M') || (selection == 'm'))
        {
            MeanOfNumbers(list_integers);
        }
        else if ((selection == 'S') || (selection == 's'))
        {
            SmallestNumber(list_integers);
        }
        else if ((selection == 'L') || (selection == 'l'))
        {
            LargestNumber(list_integers);
        }
        else
        {
            cout << "Unknown selection, please try again." << endl;
            cout << endl;
        }
    } while ((selection != 'Q') && (selection != 'q'));

    cout << "Goodbye" << endl;

	return 0;
}
