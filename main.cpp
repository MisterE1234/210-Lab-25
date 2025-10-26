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
    
    cout << right << setw(8) << "Operation" << setw(8) << "Vector" << "List" << "Set" << endl;
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



    //Reading to the list:
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



    //Reading to the set:
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


    cout <<  right << setw(8) << durVect << durList << durSet << endl;


    

    //Sorting:

    start = high_resolution_clock::now();

    //Sorting the vector so that the Codes are sorted alphabetically
    for(int i = 0; i < SZ_CODES; i++){

        for (int j = i + 1; j < SZ_CODES; j++){
            if(vectCode[i] > vectCode[j]){
            swap(vectCode[i], vectCode[j]);
            }

        }
        
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);

    durVect = duration.count();



    //Sorting the list:
    start = high_resolution_clock::now();

    listCode.sort();

    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);

    durList = duration.count();



    //Sorting the set:
    start = high_resolution_clock::now();
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);

    durList = duration.count();

    //Displaying the times for sorting:

    cout << right << setw(8) << durVect << durList << durSet << endl;




    //Inserting:
    string insert_str = "TESTCODE";

    //Timing and inserting a test string into the middle of the vector
    start = high_resolution_clock::now();

    vectCode.push_back(insert_str);

    for(int i = vectCode.size(); i > SZ_CODES/2; i--){
        for(int j = i - 1; i > SZ_CODES/2; i--){
        
            swap(vectCode[i], vectCode[j]);

        }

    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);

    durVect = duration.count();



    //Timing and inserting a test string into the middle of the list
    auto it = listCode.begin();
    advance(it, SZ_CODES/2);

    start = high_resolution_clock::now();

    listCode.insert(it, insert_str);

    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);

    durList = duration.count();



    //Timing and inserting a test string into the middle of the set

    start = high_resolution_clock::now();

    setCode.insert(insert_str);

    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);

    durSet = duration.count();





    //Clearing all the operations:
    vectCode.clear();
    listCode.clear();
    setCode.clear();

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/