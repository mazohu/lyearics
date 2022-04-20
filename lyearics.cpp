#include "Year.h"
#include <set>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

main() {
    set<Year> years; //Set containing Year objects; each year object contains its year and a vector of pairs of frequencies and words
    ifstream file("cleaned_data.txt");
    //Entries have format "year|word1 freq|word2 freq|word3 freq...|wordn freq|\n"
    string entry;
    //Load data into structure for holding years
    if(file.is_open()) {
        while(getline(file, entry)) {
            stringstream data(entry);
            string databuff;
            getline(data, databuff, '|');
            int year = stoi(databuff); //Store year to construct Year object
            vector<pair<int,string>> frequencies; //Store frequencies to construct Year object
            while(getline(data, databuff, '|')) {
                stringstream point(databuff);
                string word;
                int frequency;
                point >> word;
                point >> frequency;
                frequencies.push_back(make_pair(frequency, word));
            }
            years.emplace(year, frequencies);
        }
    } else {
        cout << "Could not open file" << endl;
    }
    return 0;
}