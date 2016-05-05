//
//  FacaePattern.cpp
//  ADP_Projects
//
//  Created by Norio Egi on 5/4/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "FacaePattern.hpp"

ConcreateFacade::ConcreateFacade(){}

ConcreateFacade::ConcreateFacade(int type, int wage){
    
    switch (type) {
        case BOSS:
            facade = new Boss(wage);
            facade->print();
            
            break;
        case PIECE:
            facade = new PieceWorker(wage);
            facade->print();

            break;

        case COMMISSION:
            facade = new CommissionWorkers(wage);
            facade->print();

            break;

        case HOURLY:
            facade = new HourlyWorkers(wage);
            facade->print();

            break;
            
        default:
            break;
    }
}

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
    int wage = 0;
    ConcreateFacade *concreateFacade;
    
    do {
        showQuestion();
        cin >> input;
        switch (input-1) {
            case BOSS:
                cout << "Enter the num for boss wage" << endl;
                break;
            case PIECE:
                cout << "Enter the num for how many piece did he make?" << endl;
                break;
            case COMMISSION:
                cout << "Enter the num how much did he sale?" << endl;
                break;

            case HOURLY:
                cout << "Enter the num how long did he work?" << endl;
                break;
                
            default:
                break;
        }
        
        cin >> wage;
        concreateFacade = new ConcreateFacade(input-1, wage);
        
    } while (input-1 != QUIT);
    
    delete concreateFacade;
    
}