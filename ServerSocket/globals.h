#ifndef MY_GLOBALS_H
#define MY_GLOBALS_H

#include <unistd.h>
#include <cstring>
#include <unordered_map>
#include <iostream>
#include <mutex> 

#include "main_window.h"

using namespace std;

extern unordered_map<string, int> clientMap;
extern mutex clientMapMutex;
extern string raspberryClientIP;
extern string ventilatorIP;
extern string RGBLamp0IP;
extern string RGBLamp1IP;
extern MainWindow* mainWindow;
extern mutex mainWindowMutex;

#endif
