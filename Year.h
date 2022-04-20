#pragma once
#include <string>
#include <vector>
#include <tuple>

using namespace std;

//Class to store years
class Year {
    private:
        int year;
        vector<pair<int,string>> frequencies;
    public:
        Year();
        Year(int year, vector<pair<int,string>> frequencies);
        void quicksort();
        void heapsort();
        friend bool operator<(const Year& lhs, const Year& rhs); //Overload less than operator for set organization
        friend bool operator==(const Year& lhs, const Year& rhs);
        friend bool operator!=(const Year& lhs, const Year& rhs);
};