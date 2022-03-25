// Winter'22
// Instructor: Diba Mirza
// Student name: Ethan Nguyen 
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>
#include "movies.h"
using namespace std;



bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
  if(argc < 2){
    cerr << "Not enough arguments provided (need at least 1 argument)." << endl;
    cerr << "Usage: " << argv[ 0 ] << " filename prefix1 prefix2 ... prefix n " << endl;
    exit(1);
  }


  ifstream movieFile (argv[1]);
 

  if (movieFile.fail()){
    cerr << "Could not open file " << argv[1];
    exit(1);
  }

vector<movies> aList{};
cout << setprecision(1) << fixed;
string line, movieName;
double movieRating;
while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
  movies mov{movieName, movieRating};
  aList.push_back(mov);
}
//BigO analysis starts here since it says the starting point of the analysis should be after the n movies have been stored
movieFile.close();
sort(aList.begin(),aList.end(),compareMoviesA);
//Stackoverflow states that sort has a linearithmic time complexity (n(log(n)))
if(argc == 2){
  for (auto i : aList){
    cout << i.name << ", " << i.rating << endl;
  }
  return 0;
}
//this ^ for loop does not matter since it will occur during the worst case
vector <string> prefixes{};
int count = 0;
for (int i = 2; i < argc;i ++){
  prefixes.push_back(argv[i]);
  count++;
}
//push_back has O(1) runtime ^ For loop has a m runtime
int size = aList.size();
vector <vector<movies>> ratingsList{};
for (int i= 0; i < count; i++){
  vector<movies> rat{};
  for (int a = 0; a < size; a++){
    if(checkPreFix(prefixes[i], aList[a].name)){
      rat.push_back(aList[a]);
    }
  }
  sort(rat.begin(),rat.end(),compareRatings);
  ratingsList.push_back(rat);
}
//outter for loop has a loop of m runtime
//Inner for loop has a runtime of n, stuff inside of the for loop have runtime O(1) so it is just n
//Stackoverflow states that sort has a linearithmic time complexity
//sort function sorts the matching terms so (k(log(k)))
//total function for runtime is (m*(n+k(log(k))))

for (int i = 0; i < count; i++){
  if (ratingsList[i].empty()){
    cout<<"No movies found with prefix "<< prefixes[i]<<endl<<endl;
  }
  for (int a = 0; a < ratingsList[i].size(); a++){
    ratingsList[i][a].print();
  }
  if (!ratingsList[i].empty()){
    cout << endl;
  }
}
//outter for loop is runtime of m
//inner for loop is runtime of k
//rest is runtime of O(1) so total runtime is mk

for (int i = 0; i < count; i++){
  if (!ratingsList[i].empty()){
    cout << "Best movie with prefix "<< prefixes[i]<<" is: " << ratingsList[i][0].name <<" with rating " << std::fixed << std::setprecision(1) << ratingsList[i][0].rating<< endl;
  }
}
//for loop has runtime of m
return 0;
}

/* Add your run time analysis for part 3 of the assignment here as commented block*/

//note all constant time operations are negligible and do not count towards big O notation for worst case
//time complexity of functions in movies.cpp are O(1)
//I chose a vector for my data structure because although it might not be the fastest in terms of the search it has a O(1) insert time complexity
//I thought that it had a good medium of what I needed to do compared to for example a bst which has a fast search but uses a lot of recursion and has a long insert time complexity.
//adding up the total runtimes from each section of code that we derived we receive
//(n(log(n)))+m+(m*(n+k(log(k))))+m
//nlog(n)+2m+mn+nklog(k)


bool parseLine(string &line, string &movieName, double &movieRating) {
  if(line.length() <= 0) return false;
  string tempRating = "";

  bool flag = false;
  movieName = tempRating = "", movieRating = 0.0, flag = false;

  for (int i = 0; i < line.length(); i++){
    if(flag) tempRating += line[i];
    else if(line[i]==','&& line[0]!='"') flag = true;
    else {
		  if(i==0 && line[0]=='"') continue;
		  if(line[i]=='"'){ i++; flag=true; continue;}
		  movieName += line[i];
	  }
  }
  
  movieRating = stod(tempRating);
  return true;
}