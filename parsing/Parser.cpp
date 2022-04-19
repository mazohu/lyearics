#include <iostream>
#include <regex>
#include "Parser.h"

using namespace std;

//Extract the year and the lyrics
void Parser::read(const string& ifilepath) {
    try {
        int year;
        string entry, data;
        ifilestream.open(ifilepath);
        while(getline(ifilestream, entry)) { //Extract an entry from the file
            stringstream entrystream(entry); //Prepare to parse the entry
            for(int i = 0; i < 3; i++)
                getline(entrystream, data, ','); //Discard RANK, SONG, and ARTIST
            getline(entrystream, data, ','); //Get YEAR
            year = stoi(data);
            getline(entrystream, data, '\"'); //Discard the first double-quote
            getline(entrystream, data, '\"'); //Get LYRICS
            entrystream.str(data); //Reuse the stringstream to parse the lyrics
            bool add = true;
            while(getline(entrystream, data)) {
                //TODO: Skip stop words
                if(regex_match(data, regex("[A-Za-z\\s]+"))) //Only update strings of all letters
                    years[year][data]++;
            }
        }
    }
    catch (const ifstream::failure& e) {
        cout << "Could not open file" << endl;
    }
}
//Write the years and associated lyrics with their frequencies
void Parser::write(const string& ofilepath) {}
