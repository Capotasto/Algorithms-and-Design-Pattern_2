//
//  smartPtr.h
//  ADP2_Project
//
//  Created by Norio Egi on 6/7/16.
//  Copyright © 2016 Capotasto. All rights reserved.
//

#ifndef smartPtr_h
#define smartPtr_h

template <class T>
class SmartPtr {
public:
    SmartPtr(T* ptrClass): mObjPointer(ptrClass){};
    ~SmartPtr(){  delete mObjPointer;};
    
    T* operator->() { return mObjPointer;}
    T &operator*() { return mObjPointer; }
    T* operator=(T* rhs) { mObjPointer = rhs; return mObjPointer;}
    
protected:
    T* mObjPointer;
};
    
#endif /* smartPtr_h */
