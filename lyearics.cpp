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
    auto toit = find_if(years.begin(), years.end(), [&](Year& year) {return year.getYear() == to;});
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
    cout << "Welcome to lyearics" << endl;
    while(true) {
        int from = 0, to = 0, sort_i = 0;
        char option;
        cout <<"You can view the top 20 most frequently used words in songs from a range of years between 1965 and 2015" << endl;
        cout << "Press any character to continue or '.' to exit" << endl;
        cin >> option;
        if(option == '.')
            break;
        cout << "Enter your range of years with the format \"FROM TO\"" << endl;
        double elapsed = 0.0;
        cin >> from;
        cin >> to;
        cout << "How would you like to sort the frequencies?" << endl;
        cout << "1: HEAPSORT    2: QUICKSORT" << endl;
        cin >> sort_i;
        string sortalgo = "";
        vector<Year> sorted;
        vector<pair<int,string>> intersection;
        if(sort_i == 1) {
            sorted = sort(years, elapsed, HEAPSORT);
            sortalgo = "HEAPSORT";
        }
        if (sort_i == 2) {
            sorted = sort(years, elapsed, QUICKSORT);
            sortalgo = "QUICKSORT";
        }
        cout << "Sorting with " << sortalgo << " finished in " << elapsed << " ms" << endl;
        getFreqRange(sorted, from, to, intersection);
        cout << "The 20 most frequently used words in songs between " << from << " and " << to << " are" << endl;
        for(int i = 0; i < 20; i++) {
            cout << i+1 << ". " << intersection[i].second << "  " << intersection[i].first << endl;
        }
        sorted.clear();
        intersection.clear();
    }
    return 0;
}