#include "Year.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <chrono>
#include <algorithm>

using namespace std;

enum Sorts {QUICKSORT = 1, HEAPSORT = 2};

double timer(void (Year::*sort)(), Year& year) {
    auto start = chrono::steady_clock::now();
    (year.*sort)();
    auto end = chrono::steady_clock::now();
    return chrono::duration<double, std::milli>(end - start).count(); //Return time to sort
};

    /** Example of sort use:
     *  double elapsed = 0.0;
     *  vector<Year> quicksorted = sort(years, elapsed, QUICKSORT);
     *  elapsed = 0.0; //Reset elapsed
     *  vector<Year> heapsorted = sort(years,elapsed,HEAPSORT); */
vector<Year> sort(vector<Year> years, double& elapsed, Sorts sort) {
    vector<Year> sorted(years.begin(), years.end());
    switch(sort) {
        case QUICKSORT: 
            for(auto& year : sorted)
                elapsed += timer(&Year::quicksort, year);     
        break;
        case HEAPSORT:
            for(auto& year : sorted)
                elapsed += timer(&Year::heapsort, year);
        break;
    }
    return sorted;
}

void getFreqRange(vector<Year>& years, int from, int to, vector<pair<int,string>>& intersection) {
    auto frit = find_if(years.begin(), years.end(), [&](Year& year) {return year.getYear() == from;});
    auto toit = find_if(years.begin(), years.end(), [&](Year& year) {return year.getYear() == from;});
    if(!(frit == years.end() && toit == years.end())) {
        while(frit != toit) {
            frit->getIntersection(*(frit+1), intersection);
            frit++;
        }
    }
    //Sort the frequency range
    std::sort(intersection.begin(), intersection.end(), greater<pair<int,string>>());
}

main() {
    vector<Year> years; //Vector containing Year objects
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
            years.emplace_back(year, frequencies);
        }
    } else {
        cout << "Could not open file" << endl;
    }
    
    //"Welcome to Lyearics"
    //"Press '.' to exit"
    //"You can view the top 20 most frequently used words in songs between 1965 and 2015"
    //"Enter your range of years with the format "FROM-TO""
        //Regex for checking if input meets format is [\d]{4}-[\d]{4}
        //Include a check for if from > to or if from == to (in which case, just output the 20 most common words from that decade)
    //Get from and to as ints using cin/getline
    //"How would you like to sort the frequencies?"
    //"1. Heapsort   2. Quicksort"
    //Get sort as single digit
        //Check if input meets format with regex [\d]{1} and if input is either 1 or 2
    //Generate the intersecting set
    //"Sorting with SORT took ELAPSED_TIME ms"
    //"The 20 most frequently used words in songs between FROM and TO are"
    //  1. WORD FREQUENCY
    return 0;
}