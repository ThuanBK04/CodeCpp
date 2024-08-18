/*
 * 
 * Recursive Functions
 * A recursive function is a function that calls itself
 *  Either directly or indirectly through another function
 * 
 * Recursive problem solving
 *  Base case
 *  Divide the rest of problem into subproblem and do recursive call
 *
 * There are many problems that lend themselves to recursive solutions (Fibonacci, fractals,...)
 *
 * If recursion doesn't eventually stop you will have infinite recursion
 * Recursion can be resource intensive
 * Remember the base case(s)
 *  It terminates the recursion
 * Only use recursive solutions when it makes sense
 * Anything that can be done recursively can be done iteratively
 *  Stack overflow error
 *
 */

#include <iostream>

using namespace std;

/* Ex1: Factorial
 *     0! = 1
 *     n! = n * (n-1)!
 * Base case: factorial(0) = 1
 * Recursive case: factorial(n) = n * factorial(n - 1)
*/
unsigned long long factorial (unsigned long long n)
{
    if (n == 0)
        return 1; // base case
    return n * factorial(n-1); // recursive case
}

/* Ex2: Fibonacci
 *     Fib(0) = 0
 *     Fib(1) = 1
 *     Fib(n) = Fib(n-1) + Fib(n-2)
 * 
 * Base case:
 *     Fib(0) = 0
 *     Fib(1) = 1
 * Recursive case:  Fib(n) = Fib(n-1) + Fib(n-2)
*/
unsigned long long fibonacci (unsigned long long n)
{
    if (n <= 1)
        return n; // base case
    return fibonacci(n-1) + fibonacci(n-2); // recursive case
}

/* Ex3: Sum of Digits */
int sum_of_digits(int n) {
    // Write your code below this line
    
    if (n == 0)
        return 0;
    
    return n%10 + sum_of_digits(n/10);
    
    // Write your code above this line
}

/* Ex4:
Implementing a Recursive Function - Save a Penny
In this exercise you will create a program that calculates the total_amount of money that will be accumulated if you start with a penny and double it everyday for n number of days.

E.g.

Day 1: $0.01

Day 2: $0.02

Day 3: $0.04

. . .

. . .

. . .

Day 16: $327.68

Day 17: $655.36

Day 18: $1310.72
 * */
double a_penny_doubled_everyday(int days, double amount) {//----WRITE THE FUNCTION PARAMETER LIST WITHIN THE PARENTHESES
    function_activation_count++;
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    
    if (days == 1)
        return amount;
    
    //----WRITE THE FUNCTION BODY BELOW THIS LINE----
    days = days - 1;
    
    return 2*a_penny_doubled_everyday(days);
    
    //----WRITE THE FUNCTION BODY ABOVE THIS LINE----
    //DO NOT MODIFY THE CODE BELOW THIS LINE----
}

int main()
{
    cout << "********* Fibonacci *********" << endl;
	cout << fibonacci(5) << endl; //5
	cout << fibonacci(30) << endl; //842040
    cout << "********* Factorial *********" << endl;
	cout << factorial(3) << endl; //6
	cout << factorial(8) << endl; //40320
	return 0;
}
