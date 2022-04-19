#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

//Class for parsing and cleaning data
    //Input file has format Rank,"Song","Artist",Year,"Lyrics",Source
class Parser {
    private:
        fstream ifilestream;
        ostream ofilestream;
        //Maps years to lyrics from those years and their frequencies
        map<int,unordered_map<string,int>> years;
    public:
        Parser();
        //Extract the year and the lyrics
        void read(const string& ifilepath);
        //Write the years and associated lyrics with their frequencies
        void write(const string& ofilepath);
};
