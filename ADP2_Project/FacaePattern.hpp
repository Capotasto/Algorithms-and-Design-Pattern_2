//
//  FacaePattern.hpp
//  ADP_Projects
//
//  Created by Norio Egi on 5/4/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#ifndef FacaePattern_hpp
#define FacaePattern_hpp

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void mainFacaePattern();

enum type_workers{
    BOSS,//0
    PIECE,//1
    COMMISSION,//2
    HOURLY,//3
    QUIT//4
};

class Facade{
public:
    virtual void print() = 0;//This makes this class abstract
};

class ConcreateFacade:public Facade{
public:
    ConcreateFacade();
    ConcreateFacade(int type, int wage);
    void print(){cout << "This is facade class."<<endl;}
    
private:
    Facade *facade;
    
};

/**
 Boss
 */
class Boss:public ConcreateFacade{
public:
    Boss(int num):ConcreateFacade(){ amount = num;}
    void print() { cout << "Boss wage is $" << amount << "/mon." << endl; }
    
private:
    int amount;
};

/**
 PieceWorker
 */
class PieceWorker:public ConcreateFacade{
public:
    PieceWorker(int num):ConcreateFacade(){count = num;}
    void print() { cout << "Piece workers wage is "<< count * 300 << endl; }
    
private:
    int count;
};

/**
 Commission Workers
 */
class CommissionWorkers:public ConcreateFacade{
public:
    CommissionWorkers(int num):ConcreateFacade(){sales = num;}
    void print() { cout << "Commission workers wage is "<<  MINIMUM + sales * 0.03 <<endl; }
    
private:
    int sales;
    int const static MINIMUM = 2500;
};

/**
 Hourly Workers
 */
class HourlyWorkers:public ConcreateFacade{
public:
    HourlyWorkers(int num):ConcreateFacade(){hour = num;}
    void print() {
        int sum = (hour > 20)? MINIMUM_HOURLY*hour*1.5: MINIMUM_HOURLY*hour;
        cout << "Hourly workers wage is " << sum << endl;
    }
    
private:
    int hour;
    int const static MINIMUM_HOURLY = 10;
};


#endif /* FacaePattern_hpp */
