//COMSC-210|Ethan Aylard|Lab-25
//IDE Used: Visual Studio Code
//This Program is to time different methods of storing information.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

int SZ_CODES = 20000;


int main() {

    string tempCode;
    //Declaring the different competetors in the race:
    vector<string> strCode;
    list<string> listCode;
    set<string> setCode;
    
    //Opening the codes for the race:
    ifstream iFile("codes.txt");

    auto start = high_resolution_clock::now();
    
    for(int i = 0; i < SZ_CODES; i++){

    getline(iFile, tempCode);
    strCode.push_back(tempCode);
    }

    auto end = high_resolution_clock::now();



    iFile.close();

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/