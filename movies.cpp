#include "movies.h"
#include <iostream>
using namespace std;

movies::movies(string str, double x){
    name = str;
    rating = x;
}
void movies::print(){
    cout << name << ", " << rating << endl;
}
bool compareMoviesA(movies mov1, movies mov2){
    string str = mov1.name;
    string str1 = mov2.name;
    int x = str.size();
    int y = str.size();
    if (x <= y){
        for (int i = 0; i < x ; i++){
            if (str[i] < str1[i]){
                return true;
            }
            else if (str[i] > str1[i]){
                return false;
            }
        }
    }
    if (x > y){
        for (int i = 0; i < y ; i++){
            if (str[i] < str1[i]){
                return true;
            }
            else if (str[i] > str1[i]){
                return false;
            }
        }
    }
}

bool compareRatings(movies mov1, movies mov2){
    if(mov1.rating > mov2.rating){
        return true;
    }
    else if (mov1.rating < mov2.rating){
        return false;
    }
    else if (mov1.rating == mov2.rating){
        return compareMoviesA(mov1,mov2);
    }
}

bool checkPreFix(string pre, string check){
    int x = pre.size();
    for (int i = 0; i < x; i++){
        if (pre[i] != check[i]){
            return false;
        }
    }
    return true;
}