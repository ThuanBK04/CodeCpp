/*
    sizeof a pointer variable
     * Don't confuse the size of a pointer and size of what it point to
     * All pointers in a program have the same size
     * They may be pointing to very large or very small types

    Typed pointers
     * The compiler will make sure that the address stored in a pointer variable is of the correct type
     * Ex:
        int score {10};
        double high_temp {100.7};
        int *score_ptr {nullptr};
        score_ptr = &score; //OK - Assign the address of score to score pointer
                                 - Score pointer holds address of integers and score's integer
        score_ptr = &high_temp; //Compiler error - Assign the address of high_temp to score pointer
                                  - Told compiler that score pointer holds address of integers
                                    but you're asking it to store the address of double
                                    -> Issue: there's a type conflict
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num{10};
    cout <<"Value of num is: " << num << endl;
    cout <<"sizeof num is: " << sizeof num << endl;
    cout <<"Address of num is: " << &num << endl;

    int *p; // p is a pointer to integer
    cout << "\nValue of p is: " << p << endl;
    cout << "Address of p is: " << &p << endl;
    cout << "sizeof p is: " << sizeof p << endl; // how much storage do I need to represent a pointer
                                                 // on my machine

    p = nullptr;
    cout << "\nValue of p is: " << p << endl; // 0

    int *p1 {nullptr};
    double *p2 {nullptr};
    unsigned long long *p3 {nullptr};
    vector<string> *p4{nullptr};
    string *p5{nullptr};

    // On my machine 4 bytes and I can represent an address of any variable
    // How much storage do I need to represent the address of an integer ?
    cout << "\nsizeof p1 is: " << sizeof p1 << endl; // 4
    cout << "sizeof p2 is: " << sizeof p2 << endl;// 4
    cout << "sizeof p3 is: " << sizeof p3 << endl;// 4
    // pointer to a vector of string objects
    cout << "sizeof p4 is: " << sizeof p4 << endl;// 4
    cout << "sizeof p5 is: " << sizeof p5 << endl;// 4

    int score{10};
    int *score_ptr{nullptr};
    score_ptr = &score;
    cout << "\nValue of score is: " << score << endl;
    cout << "Address of score is: " << &score << endl;
    cout << "Value of score_ptr is: " << score_ptr << endl;

	return 0;
}
