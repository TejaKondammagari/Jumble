//
//  main.cpp
//  JumbleMaster
//
//  Created by Teja  on 4/20/19.
//  Copyright © 2019 Teja . All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// FIX THE COUNT OF KEYS!!

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /*
     the variable word2freq is an unordered_map
     from strings to integers.
     */
    std::unordered_map<std::string, std::vector<std::string>> word2freq;
    std::ifstream file;
    std::string word;
    std::string largestKey;
    int words = 0;
    int keys = 0;
    
    // from freq.cpp
    if(argc != 2) {
        std::cout << "usage:  ./freq <filename>\n";
        std::cout << "goodbye\n";
        return 1;
    }
    
    // from freq.cpp
    file.open(argv[1], std::ios::in);
    
    if(!file.is_open()){
        std::cout << "Error: could not open file '" <<
        argv[1] << "'\n";
        std::cout << "goodbye\n";
        return 1;
    }
    
    std::cout << "Reading input file..." << std::endl;
    
    while (file >> word){
        std::string wordProcessor;
        wordProcessor = word;
        std::sort(wordProcessor.begin(), wordProcessor.end()); // sort the word in alphabetic order(to use it           as a key in the map)
        // adding words to vector if collision
        if(word2freq.count(wordProcessor) == 0)
        {
            keys++;
            word2freq[wordProcessor].push_back(word);
        }
        
        // keeping track of the largest word
        if(word2freq[wordProcessor].size() > word2freq[largestKey].size())
        {
            largestKey = wordProcessor;
        }
        
                else
                {
                    word2freq[wordProcessor].push_back(word);
                }
        
        words++;
    }
    
    std::cout << "Enter the word in jumbled form below" << std::endl;
    std::cout << "When you are done, enter ctrl-d (ctrl-z on windows) to end input" << std::endl;
    std::cout << "> ";
    while(std::cin >> word)
    {
        std::string wordProcessor;
        wordProcessor = word;
        std::sort(wordProcessor.begin(), wordProcessor.end());
        if(word2freq.count(wordProcessor)>0)
        {
            std::cout<<"English Anagrams Found: "<<std::endl;
            for (int i = 0; i < word2freq[wordProcessor].size(); i++)
            {
                std::cout<<word2freq[wordProcessor].at(i)<<std::endl;
            }
            std::cout << ">";
        }
        else
        {
            std::cout << "Sorry, no anagrams of " << word << " were found in the input file " << argv[1] << std::endl;
            std::cout << "<";
        }
    }
    
    
    std::cout << "REPORT:" << std::endl ;
    std::cout<< "keys: " << keys << std::endl;
    std::cout<< "words: " << words << std::endl;
    std::cout<< "size-of-largest-class: " << word2freq[largestKey].size() << std::endl;
    std::cout<< "largest-class key: " << "'" << largestKey << "'" << std::endl;
    std::cout<< "members of largest class: " << std::endl << std::endl;
    for (int i = 0; i < word2freq[largestKey].size(); i++)
    {
        std::cout << word2freq[largestKey].at(i) << std::endl;
    }
    
    return 0;
}
