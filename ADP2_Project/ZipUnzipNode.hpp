//
//  ZipUnzipNode.hpp
//  ADP2_Project
//
//  Created by Norio Egi on 6/20/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#ifndef ZipUnzipNode_hpp
#define ZipUnzipNode_hpp

#include <iostream>

using namespace std;

class ZipUnzipNode{
public:
    //Constructor
    ZipUnzipNode(char nodeStr, ZipUnzipNode* left, ZipUnzipNode* right);
    //getter
    char getNodeStr();
    ZipUnzipNode * getLeftPtr();
    ZipUnzipNode * getRightPtr();
    string getBinary();
    bool getMarked();
    //setter
    void setNodeStr(char nodeStr);
    void setLeftPtr(ZipUnzipNode* leftPtr);
    void setRightPtr(ZipUnzipNode* rightPtr);
    void setBinary(string binaryStr);
    void setMarked(bool flag);
    
private:
    char mNodeStr;
    ZipUnzipNode * mLeftPtr;
    ZipUnzipNode * mRightPtr;
    string mBinary;
    bool mMarked;
};

#endif /* ZipUnzipNode_hpp */
