//
//  Assingment3.hpp
//  ADP2_Project
//
//  Created by Norio Egi on 5/19/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#ifndef Assingment3_hpp
#define Assingment3_hpp

#include <iostream>
#include <vector>
using namespace std;

class TimeObserver;
string getZuluZone(int zone);

class Time{
private:
    vector<TimeObserver*> views;
    int hour;
    int minutes;
    int second;
    int timeZone;
    
public:
    void attach(TimeObserver* obs){
        this->views.push_back(obs);
    }
    void setVal(int hour, int min, int second, int zone){
        this->hour = hour;
        this->minutes = min;
        this->second = second;
        this->timeZone = zone;
        notify();
    }
    int getHour(){
        return this->hour;
    }
    int getMinutes(){
        return this->minutes;
    }
    int getSecond(){
        return this->second;
    }
    int getZone(){
        return this->timeZone;
    }
    void notify();

};

class TimeObserver{
private:
    Time* model;
    
public:
    TimeObserver(Time* mod){
        this->model = mod;
        model->attach(this);
    }
    virtual void showTime() = 0;
protected:
    Time* getModel(){
        return this->model;
    }
};

void Time::notify(){
    for (int i=0; i < views.size(); i++) {
        views[i]->showTime();
    }
};


class CivilianTime: public TimeObserver{
private:
    string civilianZone;
public:
    CivilianTime(Time* mod) : TimeObserver(mod){}
    void showTime(){
        Time* time = getModel();
        switch (time->getZone()) {
            case 0:
                civilianZone = "AM";
                break;
                
            case 1:
                civilianZone = "PM";
                break;
                
            default:
                civilianZone = "UNKNOWN ZONE";
                break;
        }
        cout << time->getHour() << ":" << time->getMinutes() << ":" << time->getSecond() << " " << civilianZone << endl;
    }
};

class MilitaryTime: public TimeObserver{
public:
    MilitaryTime(Time* mod):TimeObserver(mod){}
    void showTime(){
        Time* time = getModel();
        cout << time->getHour() << ":" << time->getMinutes() << ":" << time->getSecond() << endl;
    }
};

class ZuluTime: public TimeObserver{
private:
    string zuluZone;
public:
    ZuluTime(Time* mod):TimeObserver(mod){}
    void showTime(){
        Time* time = getModel();
        zuluZone = getZuluZone(time->getZone());
        cout << time->getHour() << ":" << time->getMinutes() << ":" << time->getSecond() << " " <<zuluZone <<endl;
    }
    
};

void mainAssignment3(void){
    Time time;
    CivilianTime civObj(&time);
    MilitaryTime milObj(&time);
    ZuluTime zuluObj(&time);
    time.setVal(14, 30, 57, 1);

}

string getZuluZone(int zone){
    string civilianZone;
    switch (zone) {
        case 1:
            civilianZone = "GMT";
            break;
        case 2:
            civilianZone = "UTC";
            break;
        case 3:
            civilianZone = "ECT";
            break;
        case 4:
            civilianZone = "EET";
            break;
        case 5:
            civilianZone = "ART";
            break;
        case 6:
            civilianZone = "EAT";
            break;
        case 7:
            civilianZone = "MET";
            break;
        case 8:
            civilianZone = "NET";
            break;
        case 9:
            civilianZone = "PLT";
            break;
        case 10:
            civilianZone = "IST";
            break;
        case 11:
            civilianZone = "BST";
            break;
        case 12:
            civilianZone = "VST";
            break;
        case 13:
            civilianZone = "CTT";
            break;
        case 14:
            civilianZone = "JST";
            break;
        case 15:
            civilianZone = "ACT";
            break;
        case 16:
            civilianZone = "AET";
            break;
        case 17:
            civilianZone = "SST";
            break;
        case 18:
            civilianZone = "NST";
            break;
        case 19:
            civilianZone = "MIT";
            break;
        case 20:
            civilianZone = "HST";
            break;
        case 21:
            civilianZone = "AST";
            break;
        case 22:
            civilianZone = "PST";
            break;
        case 23:
            civilianZone = "PNT";
            break;
        case 24:
            civilianZone = "MST";
            break;
        case 25:
            civilianZone = "CST";
            break;
        case 26:
            civilianZone = "EST";
            break;
        case 27:
            civilianZone = "IET";
            break;
        case 28:
            civilianZone = "PRT";
            break;
        case 29:
            civilianZone = "CNT";
            break;
        case 30:
            civilianZone = "AGT";
            break;
        case 31:
            civilianZone = "BET";
            break;
        case 32:
            civilianZone = "CAT";
            break;
        default:
            break;
    }
    return civilianZone;
}

#endif /* Assingment3_hpp */
