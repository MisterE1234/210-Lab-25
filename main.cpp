//COMSC-210|Ethan Aylard|Lab-25
//IDE Used: Visual Studio Code
//This Program is to time different methods of storing information.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <chrono>
#include <fstream>
#include <iomanip>
using namespace std;
using namespace std::chrono;

int SZ_CODES = 20000;


int main() {

    string tempCode;
    int durVect;
    int durList;
    int durSet;





    //Declaring the different competetors in the race:
    vector<string> vectCode;
    list<string> listCode;
    set<string> setCode;
    
    cout << "";
    //Opening the codes for the race:
    ifstream iFile("codes.txt");

    //Getting the time for the start of the timer:
    auto start = high_resolution_clock::now();

    //Using a for loop to read the file to the vector:
    for(int i = 0; i < SZ_CODES; i++){

    getline(iFile, tempCode);
    vectCode.push_back(tempCode);
    }
    //Getting the time for the end of the timer and then getting the difference between the start and end:
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    durVect = duration.count();


    //Getting the time for the start of the timer:
    start = high_resolution_clock::now();

    //Using a for loop to read the file to the list:
    for(int i = 0; i < SZ_CODES; i++){

    getline(iFile, tempCode);
    listCode.push_back(tempCode);
    }
    //Getting the time for the end of the timer and then getting the difference between the start and end:
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);

    durList = duration.count();


    //Getting the time for the start of the timer:
    start = high_resolution_clock::now();

    //Using a for loop to read the file to the set:
    for(int i = 0; i < SZ_CODES; i++){

    getline(iFile, tempCode);
    setCode.insert(tempCode);
    }
    //Getting the time for the end of the timer and then getting the difference between the start and end:
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);

    durSet = duration.count();

    


    iFile.close();

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/