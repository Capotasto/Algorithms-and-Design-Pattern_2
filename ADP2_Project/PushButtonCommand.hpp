//
//  PushButtonCommand.hpp
//  ADP2_Project
//
//  Created by Norio Egi on 6/3/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#ifndef PushButtonCommand_hpp
#define PushButtonCommand_hpp

#include <stdio.h>
#include "Command.hpp"

class PushButtonCommand:public Command{
public:
    PushButtonCommand(int number);
    virtual void execute();
        
};

#endif /* PushButtonCommand_hpp */
