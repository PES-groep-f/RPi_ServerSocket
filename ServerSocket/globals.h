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

extern string Wemos_0_IP;
extern string Wemos_1_IP;
extern string Wemos_2_IP;

extern MainWindow* mainWindow;
extern mutex mainWindowMutex;

#endif
