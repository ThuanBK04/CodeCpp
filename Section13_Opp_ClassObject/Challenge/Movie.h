#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

class Movie
{
private:
    std::string name;
    std::string rating;
    int watched;
public:
    // Constructor
    Movie(std::string name, std::string rating, int watched);
    // Copy constructor
    Movie(const Movie &source);
    // Decontructor
    ~Movie();
    std::string get_name() const;
    void set_name(std::string name);
    std::string get_rating() const;
    void set_rating(std::string rating);
    int get_watched() const;
    void set_watched(int watched);
    
    void increment_watched();
    void display() const;
};

#endif // _MOVIE_H_
