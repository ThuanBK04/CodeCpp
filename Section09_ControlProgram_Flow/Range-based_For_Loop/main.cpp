#include <iostream>
#include <vector>

using namespace std;

int main()
{
    /*
     * Example 1:
     * */
    cout << "Example 1" << endl;
    int scores [] {100, 90, 97};
    for (int score : scores)
    {
        cout << score << endl;
    }

    /*
     * Example 2: Don't have to explicitly provide the type of variable
     * */
    cout << endl << "Example 2" << endl;
    for (auto score : scores)
    {
        cout << score << endl;
    }

    /*
     * Example 3: Vector
     * */
    cout << endl << "Example 3" << endl;
    vector<double> temps {87.2, 77.1, 80.0, 72.5};
    double average {};
    double sum {};
    for (auto temp : temps)
    {
        sum += temp;
    }
    average = sum/temps.size();
    cout << average << endl;

    /*
     * Example 4: Initializer
     * */
    cout << endl << "Example 4" << endl;
    double average1 {};
    double sum1 {};
    int size = 0;
    for (auto temp : {1, 2})
    {
        sum1 += temp;
        size++;
    }
    average1 = sum1/size;
    cout << average1 << endl;

    /*
     * Example 5: String
     * */
    cout << endl << "Example 5" << endl;
    for (auto c : "Thuan")
    {
        cout << c << endl;
    }

	return 0;
}
