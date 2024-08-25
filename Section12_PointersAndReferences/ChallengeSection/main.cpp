/* Write a C++ function named apply_all that expects two arrays of integers and their sizes and
  dynamically allocates a new array of integers whose size is the product of the 2 array sizes
  
  The function should loop through the second array and multiplies each element across each element of array 1 and store the
  product in the newly created array.
  
  The function should return a pointer to the newly allocated array.
  
  You can also write a print function that expects a pointer to an array of integers and its size and display the
  elements in the array.
    
  For example,
  
  Below is the output from the following code which would be in main:
  
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1: " ;
    print(array1,5);
    
    cout << "Array 2: " ;
    print(array2,3);
    
    int *results = apply_all(array1, 5, array2, 3);
    cout << "Result: " ;
    print(results,15);
   
   Output
   ---------------------
   Array 1: [ 1 2 3 4 5 ]
   Array 2: [ 10 20 30 ]
   Result: [ 10 20 30 40 50 20 40 60 80 100 30 60 90 120 150 ]
*/

#include <iostream>

using namespace std;

void print (int const *arr, int size)
{
    cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        cout << *arr++ << " ";
    }
    cout << "]";
}

int *apply_all (int *arr1, int size1, int *arr2, int size2)
{
    int *result = new int[size1 * size2];

    for (int idx2 = 0; idx2 < size2; idx2++)
    {
        for (int idx1 = 0; idx1 < size1; idx1++)
        {
            *(result + idx2 * size1 + idx1) = *(arr2 + idx2) * (*(arr1 + idx1));
        }
    }
    return result;
}

int main()
{
    int arr1[] {1, 2, 3, 4, 5};
    int arr2[] {10, 20, 30};
    int *result;

    cout << "Array1: ";
    print (arr1, 5);

    cout << "\nArray2: ";
    print (arr2, 3);

    cout << "\nResult: ";
    result = apply_all(arr1, 5, arr2, 3);
    print (result, 15);
    delete [] result;

	return 0;
}
