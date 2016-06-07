//
//  Invoker.hpp
//  ADP2_Project
//
//  Created by Norio Egi on 6/3/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#ifndef Invoker_hpp
#define Invoker_hpp

#include <iostream>
#include <vector>
#include "Command.hpp"

enum type_sort{
    ASC,
    DEC
};

class Invoker{
public:
    Invoker(int currentFloor);
    ~Invoker();
    void Store(Command* cmd);
    void Execute();
    void sortVector(std::vector<Command*> &vector, type_sort type);
private:
    int mCurrentFloor;
    std::vector<Command*> mCommandQueue;
};

#endif /* Invoker_hpp */
