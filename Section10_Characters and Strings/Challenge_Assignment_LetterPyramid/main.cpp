/*
Write a C++ program that displays a Letter Pyramid from a user-provided std::string.

Prompt the user to enter a std::string and then from that string display a Letter Pyramid as follows:

It's much easier to understand the Letter Pyramid given examples.

If the user enters the string "ABC", then your program should display:

  A                                                                                                                    
 ABA                                                                                                                   
ABCBA 

If the user enters the string, "12345", then your program should display:

    1                                                                                                                  
   121                                                                                                                 
  12321                                                                                                                
 1234321                                                                                                               
123454321

If the user enters 'ABCDEFG', then your program should display:

      A                                                                                                                
     ABA                                                                                                               
    ABCBA                                                                                                              
   ABCDCBA                                                                                                             
  ABCDEDCBA                                                                                                            
 ABCDEFEDCBA                                                                                                           
ABCDEFGFEDCBA
If the user enters 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', then your program should display:

                         A
                        ABA
                       ABCBA
                      ABCDCBA
                     ABCDEDCBA
                    ABCDEFEDCBA
                   ABCDEFGFEDCBA
                  ABCDEFGHGFEDCBA
                 ABCDEFGHIHGFEDCBA
                ABCDEFGHIJIHGFEDCBA
               ABCDEFGHIJKJIHGFEDCBA
              ABCDEFGHIJKLKJIHGFEDCBA
             ABCDEFGHIJKLMLKJIHGFEDCBA
            ABCDEFGHIJKLMNMLKJIHGFEDCBA
           ABCDEFGHIJKLMNONMLKJIHGFEDCBA
          ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA
         ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA
        ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA
       ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA
      ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA
     ABCDEFGHIJKLMNOPQRSTUTSRQPONMLKJIHGFEDCBA
    ABCDEFGHIJKLMNOPQRSTUVUTSRQPONMLKJIHGFEDCBA
   ABCDEFGHIJKLMNOPQRSTUVWVUTSRQPONMLKJIHGFEDCBA
  ABCDEFGHIJKLMNOPQRSTUVWXWVUTSRQPONMLKJIHGFEDCBA
 ABCDEFGHIJKLMNOPQRSTUVWXYXWVUTSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSTUVWXYZYXWVUTSRQPONMLKJIHGFEDCBA
If the user enters "C++isFun!", then your program should display:

        C                                                                                                              
       C+C                                                                                                             
      C+++C                                                                                                            
     C++i++C                                                                                                           
    C++isi++C                                                                                                          
   C++isFsi++C                                                                                                         
  C++isFuFsi++C                                                                                                        
 C++isFunuFsi++C                                                                                                       
C++isFun!nuFsi++C
*/
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string user_string{};

    cout << "Enter your string: ";
    getline(cin, user_string);

    for (int idx = 0; idx < user_string.length(); idx++)
    {
            int idx2 = 0;
            int idx3 = idx -1;
            for (int idx1 = 0; idx1 < (user_string.length() * 2 - 1); idx1++)
            {
                if (idx1 < user_string.length())
                {
                    if (idx1 < (user_string.length() - idx -1))
                    {
                        cout << " ";
                    }
                    else
                    {
                        cout << user_string.at(idx2);
                        idx2++;
                    }
                }
                else
                {
                    if (idx1 > (user_string.length() + idx - 1))
                    {
                        cout << " ";
                    }
                    else
                    {
                        cout << user_string.at(idx3);
                        idx3--;
                    }
                }
            }

        cout << endl;
    }

	return 0;
}
