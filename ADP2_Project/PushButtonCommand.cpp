//
//  PushButtonCommand.cpp
//  ADP2_Project
//
//  Created by Norio Egi on 6/3/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "PushButtonCommand.hpp"

PushButtonCommand::PushButtonCommand(int number):Command(number){
    
};
void PushButtonCommand::execute(){
    cout << "Go to the " << pushedNumber << " floor!" << endl;
};

