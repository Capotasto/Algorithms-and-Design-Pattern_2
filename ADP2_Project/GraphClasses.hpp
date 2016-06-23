//
//  GraphClasses.hpp
//  ADP2_Project
//
//  Created by Norio Egi on 6/20/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#ifndef GraphClasses_hpp
#define GraphClasses_hpp

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph;
class GraphArc;
class GraphNode;

class GraphArc{
public:
    //Constructor
    GraphArc(GraphNode *node, int weight);
    //Destructor
    ~GraphArc();
    //Data member
    GraphNode * mNode;
    int mArcWeight;
    
};

//Constructor
GraphArc::GraphArc(GraphNode *node, int weight):
mNode(node), mArcWeight(weight){};

//Destructor
GraphArc::~GraphArc(){};


class GraphNode{
public:
    //Constructor
    GraphNode(int data, bool flag, list<GraphArc> arcList);
    //Destructor
    ~GraphNode();
    //other
    void addArc(GraphNode *node, int weight);
    GraphArc* getNode(GraphNode* pNode);
    void removeArc(list<GraphArc>::iterator it);
    //
    int mData;
    bool mMarked;
    list<GraphArc> mArcList;
    
};

//Constructor
GraphNode::GraphNode(int data, bool flag, list<GraphArc> arcList):
mData(data), mMarked(flag), mArcList(arcList){};
//Destructor
GraphNode::~GraphNode(){};
//other
void GraphNode::addArc(GraphNode *node, int weight){
    
};
GraphArc* GraphNode::getNode(GraphNode* pNode){
    return NULL;
};
void GraphNode::removeArc(list<GraphArc>::iterator it){
    mArcList.erase(it);
};

class Graph{
public:
    //Constuctor
    Graph(vector<GraphNode*> nodes, int count);
    //Getter
    vector<GraphNode*> getNodes();
    int getCount();
    //Setter
    void setNodes(vector<GraphNode*> node);
    void setCount(int count);
    //other
    void AddNode(GraphNode *node , int indexinArray);
    void RemoveNode(int indexinArray);
    void AddArc(int fromIndex, int toindex, int weight);
    void RemoveArc(int fromindex, int toindex);
    void GetArc(int fromindex, int toindex);
    void DepthTraverse(GraphNode);
    void LevelTraverse(GraphNode);
    
private:
    vector<GraphNode*> mNodes;
    int mCount;
};

//Constuctor
Graph::Graph(vector<GraphNode*> nodes, int count):
mNodes(nodes), mCount(count){};
//Getter
vector<GraphNode*> Graph::getNodes(){
    return mNodes;
};
int Graph::getCount(){
    return mCount;
};
//Setter
void Graph::setNodes(vector<GraphNode*> node){
    mNodes = node;
};
void Graph::setCount(int count){
    mCount = count;
};
//other
void Graph::AddNode(GraphNode *node , int indexinArray){
    mNodes.insert(mNodes.begin() + indexinArray, node);
};
void Graph::RemoveNode(int indexinArray){
    mNodes.erase(mNodes.begin() + indexinArray);
};
void Graph::AddArc(int fromIndex, int toindex, int weight){
    //mNodes[fromIndex]->addArc()??????
};
void Graph::RemoveArc(int fromindex, int toindex){
};
void Graph::GetArc(int fromindex, int toindex){
};
void Graph::DepthTraverse(GraphNode){
};
void Graph::LevelTraverse(GraphNode){
};



#endif /* GraphClasses_hpp */
