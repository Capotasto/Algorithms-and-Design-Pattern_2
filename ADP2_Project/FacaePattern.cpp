//
//  FacaePattern.cpp
//  ADP_Projects
//
//  Created by Norio Egi on 5/4/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "FacaePattern.hpp"

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

class Boss:public Facade{
public:
    Boss(int num){ amount = num;}
    void print() { cout << "Boss wage is $" << amount << "/mon." << endl; }
    
private:
    int amount;
};

class PieceWorker:public Facade{
public:
    PieceWorker(int num){count = num;}
    void print() { cout << "Piece workers wage is "<< count * 300 << endl; }
    
private:
    int count;
};

class CommissionWorkers:public Facade{
public:
    CommissionWorkers(int num){sales = num;}
    void print() { cout << "Commission workers wage is "<<  MINIMUM + sales * 0.03 <<endl; }
    
private:
    int sales;
    int const static MINIMUM = 2500;
};

class HourlyWorkers:public Facade{
public:
    HourlyWorkers(int num){hour = num;}
    void print() {
        int sum = (hour > 20)? MINIMUM_HOURLY*hour*1.5: MINIMUM_HOURLY*hour;
        cout << "Hourly workers wage is " << sum << endl;
    }
    
private:
    int hour;
    int const static MINIMUM_HOURLY = 10;
};

void showQuestion(){
    cout << "\nChoose the worker type below."<< endl;
    cout << "1.Boss."<< endl;
    cout << "2.Piece worker."<< endl;
    cout << "3.Commission worker."<< endl;
    cout << "4.Hourly worker."<< endl;
    cout << "5.Quit."<< endl;

}

void mainFacaePattern(){
    
    int input;
    int wage;
    
    do {
        showQuestion();
        cin >> input;
        
        switch (input-1) {
            case BOSS:{
                
                cout << "Enter the number for boss wage."<< endl;
                cin >> wage;
                Boss boss(wage);
                boss.print();
                break;
            }
            case PIECE:{
                cout << "Enter the number he made."<< endl;
                cin >> wage;
                PieceWorker piece(wage);
                piece.print();
                break;
            }
            case COMMISSION:{
                cout << "Enter the number of his sales."<< endl;
                cin >> wage;
                CommissionWorkers com(wage);
                com.print();
                break;
            }
            case HOURLY:{
                cout << "Enter the number of the hour."<< endl;
                cin >> wage;
                HourlyWorkers hour(wage);
                hour.print();
                break;
            }
            default:{
                break;
            }
        }

    } while (input-1 != QUIT);
    
}