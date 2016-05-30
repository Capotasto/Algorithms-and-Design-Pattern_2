//
//  driverZipUnZip.cpp
//  ADP2_Project
//
//  Created by Norio Egi on 5/26/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//
#include "driverZipUnZip.hpp"

void generateTableForMap(std::map<char, int> &map, std::string str, char *cstr){
    //Add the key value to the map(index = 0)
    map.insert(std::map<char, int>::value_type(cstr[0], 1));
    for (int i = 1; i < str.length() +1; i++) {
        if (cstr[i] == '\0') {
            break;
        }
        //check duplicated
        std::map<char, int>::iterator it = map.begin();
        bool isDuplicated = false;
        while( it != map.end() ){
            if((*it).first == cstr[i]){
                (*it).second++;
                isDuplicated = true;
                break;
            }
            it++;
        }
        if (!isDuplicated) {
            map.insert(std::map<char, int>::value_type(cstr[i], 1));
        }
    }
}

void outPutMap(std::map<char, int> &map){
    std::map<char, int>::iterator it = map.begin();
    while( it != map.end() ){
        std::cout << "Map key: " << (*it).first << ", map value: " << (*it).second <<std::endl;
        it++;
    }
}

void outPutSortMap(std::multimap<int, char> &map){
    std::multimap<int, char>::iterator it = map.begin();
    while( it != map.end() ){
        std::cout << "Sorted Map key: " << (*it).first << ", map value: " << (*it).second <<std::endl;
        it++;
    }

}

void sortMap(std::map<char, int> &map, std::multimap<int, char> &sortMap){
    std::map<char, int>::iterator it = map.begin();
    while( it != map.end() ){
        sortMap.insert(std::multimap<int, char>::value_type((*it).second, (*it).first));
        it++;
    }
    
}

void generateTree(Tree<char> &tree , std::multimap<int, char> &map){
    std::multimap<int, char>::iterator it = map.begin();
    while( it != map.end() ){
        tree.insertNode((*it).second);
        tree.insertNode((*it++).second);
    }
}


void mainDriverZipUnZip(){
    std::ifstream ifs("input.txt");
    std::string str;
    std::map<char, int> map;
    std::multimap<int, char> sortedMap;
    Tree<char> charTree;
    
    if (ifs.fail()){
        std::cerr << "File reading is failed." << std::endl;
    }
    
    while (getline(ifs, str)) {
        char *cstr = new char[str.length() + 1];
        strcpy(cstr, str.c_str());
        
        generateTableForMap(map, str, cstr);
 
        delete [] cstr;
    }
    outPutMap(map);
    
    sortMap(map , sortedMap);
    
    outPutSortMap(sortedMap);
    
    generateTree(charTree, sortedMap);
    
}