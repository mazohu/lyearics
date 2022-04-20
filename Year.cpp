#include "Year.h"

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

//TODO: @mazohu implement quicksort on frequency vector 
void Year::quicksort() {}

//TODO: @abipr implement heapsort on frequency vector 
void Year::heapsort() {}