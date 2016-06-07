//
//  Invoker.cpp
//  ADP2_Project
//
//  Created by Norio Egi on 6/3/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#include "Invoker.hpp"

//Constructor
Invoker::Invoker(int currentFloor):mCurrentFloor(currentFloor){};
//Destructor
Invoker::~Invoker(){
    std::vector<Command*>::iterator it = mCommandQueue.begin();
    while (it != mCommandQueue.end()) {
        delete (*it);
        it++;
    }
}

void Invoker::Store(Command* cmd){
    mCommandQueue.push_back(cmd);
};

void Invoker::Execute(){
    Command *commandFront = mCommandQueue.front();
    if(commandFront->pushedNumber > mCurrentFloor){
        //Going Up
        sortVector(mCommandQueue, ASC);
        vector<Command*>::iterator it = mCommandQueue.begin();
        while (it != mCommandQueue.end()) {
            if ((*it)->pushedNumber > mCurrentFloor) {
                (*it)->execute();
            }
            it++;
        }
        
    }else if(commandFront->pushedNumber < mCurrentFloor){
        //Going Down
        sortVector(mCommandQueue, DEC);
        vector<Command*>::iterator it = mCommandQueue.begin();
        while (it != mCommandQueue.end()) {
            if ((*it)->pushedNumber < mCurrentFloor) {
                (*it)->execute();
            }
            it++;
        }
        
    }else{
        //nothing to do
    }

};

void Invoker::sortVector(std::vector<Command*> &vector, type_sort type){
    for (int i = 0; i < vector.size(); i++) {
        for (int j = 0; j < vector.size()-1; j++) {
            switch (type) {
                case ASC:
                    if (vector[j]->pushedNumber > vector[j+1]->pushedNumber) {
                        Command *temp =vector[j+1];
                        vector[j+1] = vector[j];
                        vector[j] = temp;
                    }
                    break;
                    
                case DEC:
                    if (vector[j]->pushedNumber < vector[j+1]->pushedNumber) {
                        Command *temp =vector[j+1];
                        vector[j+1] = vector[j];
                        vector[j] = temp;
                    }
                    break;

                default:
                    break;
            }
        }
    }

};