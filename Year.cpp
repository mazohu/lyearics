#include "Year.h"
#include <cstdlib>
#include <algorithm>

Year::Year(int year, vector<pair<int,string>> frequencies) {
    this->year = year;
    this->frequencies = frequencies;
}

ostream& operator<<(ostream& os, const Year& year) {
    os << year.year << endl;
    for(auto point : year.frequencies)
        os << point.second << "  " << point.first << endl;
    return os;
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

int Year::partition(int first, int last) {
    //Randomly select the pivot
    int pivot = rand() % ((last-first)+1) + first;
    swap(frequencies[pivot], frequencies[first]);
    pivot = frequencies[first].first; //Set pivot to the value of the first element
    //Initialize up and down to first+1 and last
    int up = first+1, down = last;
    while(up < down) {//While up is to the left of down
        while(up < last) { //Increment up while up is less than last or until it selects an element leq than the pivot, which should be moved to the right of the pivot
            if(frequencies[up].first <= pivot)
                break;
            up++;
        }
        while(down > first) {  //Increment down while down is greater than first or until it selects an element greater than the pivot
            if(frequencies[down].first > pivot)
                break;
            down--;
        }
        if(up < down) //If up is right of down then all the elements in the left are geq to the pivot, so swap up and down
            swap(frequencies[up], frequencies[down]);
    }
    swap(frequencies[first], frequencies[down]);
    return down;
}

void Year::recurQuicksort(int first, int last) {
    if(first < last) {
        int pivot = partition(first, last);
        recurQuicksort(first, pivot - 1); //quicksort on left
        recurQuicksort(pivot + 1, last); //quicksort on right 
    }
}

void Year::quicksort() {
    recurQuicksort(0, frequencies.size()-1);
}

void Year::buildHeap() {
    for(int i = (frequencies.size()/2)-1; i >= 0; i--)
        heapify(frequencies.size(), i);
}

void Year::heapify(int size, int root) {
    if(root < 0 || root >= size/2) //If root is out of bounds or a leaf node, don't continue
        return;
    //Find left child
    int child = 2*root+1;
    //Get smaller child
    if(root < (size/2)-1 && frequencies[child] > frequencies[child+1]) 
        child++;
    if(frequencies[root] > frequencies[child]) {
        swap(frequencies[child], frequencies[root]);
        heapify(size, child); //Heapify recursively on child
    }
}

void Year::extractMin(int& size) {
    //Swap root with end and decrement size
    swap(frequencies[0], frequencies[--size]);
    heapify(size, 0); //Heapify root
}

void Year::heapsort() {
    buildHeap();
    int size = frequencies.size();
    while(size > 1) //While heap size is greater than 1
        extractMin(size);
}

int Year::getYear() {return year;}

//TODO: Write function for getting the intersection of frequencies between two years
void Year::getIntersection(Year& rhs, vector<pair<int,string>>& intersection) {
    vector<pair<int,string>> smaller = this->frequencies, larger = rhs.frequencies;
    if(smaller.size() > larger.size()) {
        smaller.swap(larger);
    }
    for(auto pair : smaller) {
        
    }
}