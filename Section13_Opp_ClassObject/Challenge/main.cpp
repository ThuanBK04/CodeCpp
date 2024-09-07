#include <iostream>
#include "Movies.h"

using namespace std;

void add_movie (Movies &my_movies, std::string name, std::string rating, int watched)
{
    if (my_movies.add_movie(name, rating, watched))
    {
        std::cout << name << " added" << std::endl;
    }
    else
    {
        std::cout << name << " already exists" <<  std::endl;
    }
}

void increment_watched (Movies &my_movies, std::string name)
{
    if (my_movies.increment_watched(name))
    {
        std::cout << name << " watch incremented" <<  std::endl;
    }
    else
    {
        std::cout << name << " not found" <<  std::endl;
    }
}

void display (Movies my_movies)
{
    my_movies.display();
}

int main()
{
    Movies my_movies;

    display(my_movies);

    add_movie(my_movies, "Big", "PG-13",2);                 // OK
    add_movie(my_movies,"Star Wars", "PG",5);             // OK
    add_movie(my_movies,"Cinderella", "PG",7);           // OK

    display(my_movies);   // Big, Star Wars, Cinderella

    add_movie(my_movies,"Cinderella", "PG",7);            // Already exists
    add_movie(my_movies,"Ice Age", "PG",12);              // OK

    display(my_movies);    // Big, Star Wars, Cinderella, Ice Age

    increment_watched(my_movies,"Big");                    // OK
    increment_watched(my_movies,"Ice Age");              // OK

    display(my_movies);    // Big and Ice Age watched count incremented by 1

    increment_watched(my_movies,"XXX");         // XXX not found

    return 0;
}
