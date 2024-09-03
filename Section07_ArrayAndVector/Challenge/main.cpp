#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> vector1;
    vector <int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);
    cout << "------- Vector 1 -------" << endl;
    for (int i = 0; i < vector1.size(); i++)
    {
        cout << "Index " << i << " : " << vector1.at(i) << endl;
    }

    vector2.push_back(100);
    vector2.push_back(200);
    cout << "------- Vector 2 -------" << endl;
    for (int i = 0; i < vector2.size(); i++)
    {
        cout << "Index " << i << " : " << vector2.at(i) << endl;
    }

    vector <vector<int>> vector_2d;
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    cout << "------- Vector 2d -------" << endl;
    for (int i = 0; i < vector2.size(); i++)
    {
        for (int j = 0; j < vector1.size(); j++)
        {
            cout << "Index " << i << j << " : " << vector_2d.at(i).at(j) << endl;
        }
    }

    vector1.at(0) = 1000;
    cout << "------- Vector 2d again -------" << endl;
    for (int i = 0; i < vector2.size(); i++)
    {
        for (int j = 0; j < vector1.size(); j++)
        {
            cout << "Index " << i << j << " : " << vector_2d.at(i).at(j) << endl;
        }
    }
    cout << "------- Vector 1 again -------" << endl;
    for (int i = 0; i < vector1.size(); i++)
    {
        cout << "Index " << i << " : " << vector1.at(i) << endl;
    }

	return 0;
}
