//
//  Random.cpp
//  ADP2_Project
//
//  Created by Norio Egi on 5/24/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "Random.hpp"

bool hasDecimalNumber(vector<unsigned long> vector, unsigned long decimal){
    
    bool hasDecimal = false;
    
    if (vector.size() != 0) {
        for (int i = 0 ; i < vector.size(); i++) {
            if (vector[i] == decimal) {
                return true;
            }
        }
    }
    
    return hasDecimal;
}


char getResultXor(char x, char y){
    
    if (x == y) {
        return '0';
    }else {
        return '1';
    }
}

void mainRandom(){
    
    const int DEGIT_RANDOM = 8;
    string binary = "11001100";
    vector<unsigned long> sizeList;
    
    int i = 1;
    while (i < DEGIT_RANDOM) {
        vector<unsigned long> decimalList;
        unsigned long decimal = std::bitset<DEGIT_RANDOM>(binary).to_ulong();
        deque<char> data;

        while (!hasDecimalNumber(decimalList, decimal)) {
            decimalList.push_back(decimal);
            if (data.size()==0) {
                deque<char> xdata(binary.begin(), binary.end());
                data = xdata;
            }
            
            char newChar = getResultXor(data[0], data[i]);
            data.push_back(newChar);
            data.pop_front();
            
            string binaryEx(data.begin(), data.end());
            
            decimal = std::bitset<DEGIT_RANDOM>(binaryEx).to_ulong();
            
        }
        cout << "index0 : index" << i <<endl;
        cout << "Decimal List(" << i <<") :";
        for (int j = 0; j < decimalList.size(); j++) {
            cout << decimalList[j] << ", ";
        }
        cout << endl;
        sizeList.push_back(decimalList.size());
        
        i++;
    }
    unsigned long max = 0;
    cout << "Size list is :";
    for (int j = 0; j < sizeList.size(); j++) {
        if (max < sizeList[j]) {
            max = sizeList[j];
        }
        cout << sizeList[j] << ", ";
    }
    cout << "Max size is: " << max << endl;
    
    
}