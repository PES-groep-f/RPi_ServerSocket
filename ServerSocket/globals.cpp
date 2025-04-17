#include "globals.h"

unordered_map<string, int> clientMap;
mutex clientMapMutex;
string raspberryClientIP = "169.254.10.156";
string ventilatorIP = "10.42.0.64";
string RGBLamp0IP = "10.42.0.57";
string RGBLamp1IP = "10.42.0.56";
MainWindow* mainWindow = nullptr;
mutex mainWindowMutex;
