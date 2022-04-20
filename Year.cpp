#include "Year.h"
#include <ctime>

Year::Year(int year, vector<pair<int,string>> frequencies) {
    this->year = year;
    this->frequencies = frequencies;
}

bool operator<(const Year& lhs, const Year& rhs) {
    return lhs.year < rhs.year;
};

bool operator==(const Year& lhs, const Year& rhs) {
    return lhs.year == rhs.year;
};

bool operator!=(const Year& lhs, const Year& rhs) {
    return lhs.year != rhs.year;
};

void Year::timer(void(*sort)()) {
    clock_t start = clock();
    sort();
    clock_t end = clock();
    sort_time = (end-start)/CLOCKS_PER_SEC; //Update time taken to sort
};

//TODO: @mazohu implement quicksort on frequency vector 
void Year::quicksort() {}

//TODO: @mazohu implement heapsort on frequency vector 
void Year::heapsort() {}

int Year::getYear() {return year;}

vector<pair<int,string>> Year::getFrequencies() {return frequencies;}