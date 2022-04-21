#pragma once
#include <string>
#include <vector>
#include <tuple>
#include <iostream>

using namespace std;

//Class to store years
class Year {
    private:
        int year;
        vector<pair<int,string>> frequencies;
        //Helper function for sorting subarrays in quicksort
        int partition(int first, int last);
        //Recursively quicksort the frequencies in descending order
        void recurQuicksort(int first, int last);
        //Heapsort helper function to build a min heap
        void buildHeap();
        //Heapsort helper function to remove the minimum node from the heap
        void extractMin(int& size);
        //Heapsort helper function to heapify
        void heapify(int size, int root);
    public:
        Year();
        Year(int year, vector<pair<int,string>> frequencies);
        //Quicksort wrapper to hide recurQuicksort
        void quicksort();
        //Heapsort the frequencies in descending order
        void heapsort();
        //Overload less than operator for set organization
        friend bool operator<(const Year& lhs, const Year& rhs); 
        friend bool operator==(const Year& lhs, const Year& rhs);
        friend bool operator!=(const Year& lhs, const Year& rhs);
        friend ostream& operator<<(ostream& os, const Year& year);
        //Accessors
        int getYear();
        //Gets the intersection of the top 20 frequencies of the lhs and rhs Years (using whichever has a shorter list of frequencies) and update a vector storing the intersection
        void getIntersection(Year& rhs, vector<pair<int,string>>& intersection);
};