#include <iostream>
#include <regex>
#include "Parser.h"

using namespace std;

//Default constructor for class Parser which initializes the dictionary and stop words
Parser::Parser() {
    //Load and build the dictionary
    filestream.open("stop_words.txt", std::ios::in);
    if(filestream.is_open()) {    
        string word;
        while(getline(filestream, word,','))
            stopWords.insert(word);
    } else {
        cout << "Could not open file" << endl;
    }
    filestream.close();
}
void Parser::clean(stringstream& stream, const int& year) {
    string buff;
    while(getline(stream, buff, ' ')) { //Parse the lyrics
        //Remove non alpha characters
        buff.erase(remove_if(buff.begin(), buff.end(), [](auto const& c) -> bool {return !isalpha(c);}), buff.end());
        //If the word is a stop word or an empty string, skip it
        if(stopWords.count(buff) || buff.empty())
            continue; //Skip
        years[year][buff]++;
    }
}
void Parser::read(const string& ifilepath) {
    int year;
    string entry, data;
    filestream.open(ifilepath, std::ios::in);
    if(filestream.is_open()) {
        getline(filestream, entry); //Toss the first line of the csv
        while(getline(filestream, entry)) { //Extract an entry from the file
            stringstream entrystream(entry); //Prepare to parse the entry
            for(int i = 0; i < 3; i++) 
                getline(entrystream, data, ','); //Discard RANK, SONG, ARTIST
            getline(entrystream, data, ','); //Get YEAR
            year = stoi(data);
            getline(entrystream, data, '\"'); //Discard the first double-quote
            getline(entrystream, data, '\"'); //Get LYRICS
            entrystream.str(data); //Reuse the stringstream to parse the lyrics
            clean(entrystream, year); //Clean the lyrics
        }
    } else {
        cout << "Could not open file" << endl;
    }
    filestream.close();
}
void Parser::write(const string& ofilepath) {
    filestream.open(ofilepath, std::ios::out);
    if(filestream.is_open()) {
        //Output with format year|word1 freq|word2 freq|word3 freq...|wordn freq|\n
        for(auto& entry : years) {
            filestream << entry.first << "|";
            for(auto& word : entry.second) {
                filestream << word.first << " " << word.second << "|";
            }
            filestream << endl;
        }
    } else {
        cout << "Could not open file" << endl;
    }
}
