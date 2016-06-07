//
//  driverMidterm.cpp
//  ADP2_Project
//
//  Created by Norio Egi on 6/4/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "driverMidterm.hpp"

void mainDriverMidterm(){
    const int MAX_FLOOR = 10;
    
    Invoker invoker1(4);
    invoker1.Store(new PushButtonCommand(5));
    invoker1.Store(new PushButtonCommand(9));
    invoker1.Store(new PushButtonCommand(3));
    invoker1.Store(new PushButtonCommand(2));
    invoker1.Store(new PushButtonCommand(4));
    cout << "Elevator1 is moving like below!" << endl;
    invoker1.Execute();
    
    Invoker invoker2(MAX_FLOOR);
    invoker2.Store(new PushButtonCommand(5));
    invoker2.Store(new PushButtonCommand(9));
    invoker2.Store(new PushButtonCommand(3));
    invoker2.Store(new PushButtonCommand(2));
    invoker2.Store(new PushButtonCommand(4));
    cout << "Elevator2 is moving like below!" << endl;
    invoker2.Execute();

    
}