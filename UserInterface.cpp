//
// Created by dxuma on 11/29/2019.
//
#include "UserInterface.h"

UserInterface::UserInterface(){
    this->arrayOfCommands = new int[14];

}

UserInterface::~UserInterface(){
    delete[] arrayOfCommands;
}

void UserInterface::help(){
    for(int i = 0; i < 14; i++){
        std::cout << i << ": " << arrayOfCommands[i] << cout::endl;
    }
}

