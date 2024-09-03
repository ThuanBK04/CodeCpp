#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> scores {100, 95, 99};

    /* Accessing vector elements - array syntax -> no bound checking */
	cout << "First score at index 0: " << scores[0] << endl;
    cout << "First score at index 1: " << scores[1] << endl;

    /* Accessing vector elements - vector syntax -> have bound checking 
     * An exception and error message is generated
     * */
	cout << "First score at index 0: " << scores.at(0) << endl;
    cout << "First score at index 1: " << scores.at(1) << endl;

    /* Grow a vector - Vector will auto allocate the required space 
     * The element added must be the same type
     * */
    scores.push_back(80);
    scores.push_back(90);
    
    /* Example of a 2D-vector - is a vecotr of vectors */
    vector <vector<int>> movie_ratings
    {
        {1,2,3,4},
        {1,2,4,4},
        {1,3,4,5}
    };
    
    cout << "\nHere are the movie rating for reviewer #1 using array syntax:" <<endl;
    cout << movie_ratings[0][0] << endl;
    cout << movie_ratings[0][1] << endl;

    cout << "\nHere are the movie rating for reviewer #1 using vector syntax:" <<endl;
    cout << movie_ratings.at(0).at(0) << endl;
    cout << movie_ratings.at(0).at(1) << endl;

	return 0;
}
