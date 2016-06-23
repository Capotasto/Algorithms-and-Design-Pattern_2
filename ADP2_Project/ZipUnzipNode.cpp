//
//  ZipUnzipNode.cpp
//  ADP2_Project
//
//  Created by Norio Egi on 6/20/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "ZipUnzipNode.hpp"

//Constructor
ZipUnzipNode::ZipUnzipNode(char nodeStr, ZipUnzipNode* left, ZipUnzipNode* right)
:mNodeStr(nodeStr), mLeftPtr(left), mRightPtr(right){};
//getter
char ZipUnzipNode::getNodeStr(){
    return mNodeStr;
};
ZipUnzipNode * ZipUnzipNode::getLeftPtr(){
    return mLeftPtr;
};
ZipUnzipNode * ZipUnzipNode::getRightPtr(){
    return mRightPtr;
};

string ZipUnzipNode::getBinary(){
    return mBinary;
};
bool ZipUnzipNode::getMarked(){
    return mMarked;
};

//setter
void ZipUnzipNode::setNodeStr(char nodeStr){
    mNodeStr = nodeStr;
};
void ZipUnzipNode::setLeftPtr(ZipUnzipNode* leftPtr){
    mLeftPtr = leftPtr;
};
void ZipUnzipNode::setRightPtr(ZipUnzipNode* rightPtr){
    mRightPtr = rightPtr;
};

void ZipUnzipNode::setBinary(string binaryStr){
    mBinary = binaryStr;
};
void ZipUnzipNode::setMarked(bool flag){
    mMarked = flag;
};


