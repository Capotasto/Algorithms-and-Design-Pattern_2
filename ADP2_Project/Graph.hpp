////
////  Graph.hpp
////  ADP2_Project
////
////  Created by Norio Egi on 5/20/16.
////  Copyright © 2016 Capotasto. All rights reserved.
////
//
//#ifndef Graph_hpp
//#define Graph_hpp
//
//#include <iostream>
//#include <vector>
//#include "GraphNode.hpp"
//
//using namespace std;
//
//class Graph{
//public:
//    //Constuctor
//    Graph(vector<GraphNode*> nodes, int count);
//    //Getter
//    vector<GraphNode*> getNodes();
//    int getCount();
//    //Setter
//    void setNodes(vector<GraphNode*> node);
//    void setCount(int count);
//    
//    //other
//    void AddNode(GraphNode *node , int indexinArray);
//    void RemoveNode(int indexinArray);
//    //void AddArc(fromIndex, toindex, weight);
//    //void RemoveArc(fromindex, toindex);
//    //void GetArc(fromindex, toindex);
//    void DepthTraverse(GraphNode);
//    void LevelTraverse(GraphNode);
//    
//    
//private:
//    vector<GraphNode*> mNodes;
//    int mCount;
//};
//
//#endif /* Graph_hpp */
