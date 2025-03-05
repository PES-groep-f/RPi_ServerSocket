#ifndef MY_GLOBALS_H
#define MY_GLOBALS_H

#include <unistd.h>
#include <cstring>
#include <unordered_map>
#include <iostream>
#include <mutex> 

using namespace std;

extern unordered_map<string, int> clientMap;
extern mutex clientMapMutex;
extern string raspberryClientIP;

#endif
