//
//  driverFinal.cpp
//  ADP2_Project
//
//  Created by Norio Egi on 6/7/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "driverFinal.hpp"

class ActualData{
public:
    ActualData():mSomething("Default Value"){};
    ActualData(string string):mSomething(string){};
    ~ActualData(){cout << "Object Destructor\n" << endl;};
    string getSomething(){ return mSomething;};
    void setSomething(int string){mSomething = mSomething;};
    string print(){ cout << "String is "<< getSomething() << endl;return getSomething(); };
    
private:
    string mSomething;

};

void mainDriverFinal(){
    
    SmartPtr<ActualData> smart(new ActualData("Something01"));
    smart->print();
    
    ActualData* testPtr = new ActualData();
    smart = testPtr;
    
    delete testPtr;
    
    cout << "Debugging TestClass: " << smart->print() << endl;
}