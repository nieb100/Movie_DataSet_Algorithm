#ifndef MOVIES_H
#define MOVIES_H
#include <iostream>
#include <string>
using namespace std;

class movies {

 public:
    movies(string str, double x);
    void print();
    string name;
    double rating;


};

bool compareMoviesA(movies mov1, movies mov2);
bool compareRatings(movies mov1, movies mov2);
bool checkPreFix(string pre, string check);

#endif