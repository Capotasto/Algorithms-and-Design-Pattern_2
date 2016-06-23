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

//void generateTree(Tree<char> &tree , std::multimap<int, char> &map){
//    std::multimap<int, char>::iterator it = map.begin();
//    while( it != map.end() ){
//        tree.insertNode((*it).second);
//        tree.insertNode((*it++).second);
//    }
//}

void generateTreeMap(std::multimap<int, ZipUnzipNode*> &treeMap, std::multimap<int, char> &sortedMap){
    std::multimap<int, char>::iterator itSortedMap = sortedMap.begin();
    while (itSortedMap != sortedMap.end()) {
        ZipUnzipNode* node = new ZipUnzipNode((*itSortedMap).second, NULL, NULL);
        treeMap.insert(std::multimap<int, ZipUnzipNode*>::value_type((*itSortedMap).first, node));
        itSortedMap++;
    }
    
    std::multimap<int, ZipUnzipNode*>::iterator itTreeMap = treeMap.begin();
    while (itTreeMap != treeMap.end()) {
        //first
        int firstKey =(*itTreeMap).first;
        ZipUnzipNode* firstNode =(*itTreeMap).second;
        itTreeMap = treeMap.erase(itTreeMap);
        
        //second
        int secondKey =(*itTreeMap).first;
        ZipUnzipNode* secondNode =(*itTreeMap).second;
        itTreeMap = treeMap.erase(itTreeMap);
        
        ZipUnzipNode* node = new ZipUnzipNode('\0', firstNode, secondNode);
        treeMap.insert(make_pair(firstKey+secondKey, node));
    }
    
}

void getBinaryTable(ZipUnzipNode* &rootNode, std::map<string, char> &binaryMap, bool &hasDoneTraversal){
    string binaryStr;
    ZipUnzipNode* nextPtr;
    if (!rootNode->getMarked()) {
        if (rootNode->getNodeStr() != 0) {
            //leaf
            rootNode->setMarked(true);
            binaryMap.insert(make_pair(rootNode->getBinary() ,rootNode->getNodeStr()));
            return;
        }else{
            //not leaf
            if (rootNode->getLeftPtr()->getMarked() == true && rootNode->getRightPtr()->getMarked() == true) {
                rootNode->setMarked(true);
                //hasDoneTraversal = true;
                return;
            }else{
                if (rootNode->getLeftPtr()->getMarked() != true) {
                    //To Left
                    nextPtr = rootNode->getLeftPtr();
                    nextPtr->setBinary(rootNode->getBinary()+"0");
                }else{
                    //To Right
                    nextPtr = rootNode->getRightPtr();
                    nextPtr->setBinary(rootNode->getBinary()+"1");
                }
                getBinaryTable(nextPtr, binaryMap, hasDoneTraversal);
            }
        }
    }else{
        hasDoneTraversal = true;
    }
}

void mainDriverZipUnZip(){
    std::ifstream ifs("input.txt");
    std::string str;
    std::map<char, int> map;
    std::multimap<int, char> sortedMap;
    std::multimap<int, ZipUnzipNode*> treeMap;
    std::map<string, char> binaryMap;
    Tree<char> charTree;
    bool hasDoneTraversal = false;
    
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
    
    sortMap(map, sortedMap);
    
    outPutSortMap(sortedMap);
    
    generateTreeMap(treeMap, sortedMap);
    
    std::multimap<int, ZipUnzipNode*>::iterator itTreeMap = treeMap.begin();
    
    while (itTreeMap != treeMap.end()) {
        ZipUnzipNode * currentPtr = (*itTreeMap).second;
        do {
            getBinaryTable(currentPtr, binaryMap, hasDoneTraversal);
        } while (!hasDoneTraversal);
        itTreeMap++;
    }
    
    std::map<string, char>::iterator itBinaryMap = binaryMap.begin();
    while (itBinaryMap != binaryMap.end()) {
        cout << "binary:char = " <<(*itBinaryMap).first << ":" << (*itBinaryMap).second << endl;
        itBinaryMap++;
    }
}