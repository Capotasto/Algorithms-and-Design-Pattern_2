//
//  Command.hpp
//  ADP2_Project
//
//  Created by Norio Egi on 6/2/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#ifndef Command_hpp
#define Command_hpp

#include <iostream>

using namespace std;

class Command {
public:
    Command(int number);
    virtual ~Command();
    virtual void execute() = 0;
    const int pushedNumber;
};

#endif /* Command_hpp */
