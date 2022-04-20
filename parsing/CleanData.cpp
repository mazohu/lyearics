#include "Parser.h"
#include <iostream>

using namespace std;

main() {
    Parser parser;
    parser.read("../billboard_lyrics.csv");
    parser.write("../cleaned_data.txt");
    return 0;
}