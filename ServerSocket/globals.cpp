#include "globals.h"

unordered_map<string, int> clientMap;
mutex clientMapMutex;
string raspberryClientIP = "169.254.10.156";
string Wemos_0_IP = "10.42.0.64";
string Wemos_1_IP = "10.42.0.57";
string Wemos_2_IP = "10.42.0.56";
MainWindow* mainWindow = nullptr;
mutex mainWindowMutex;
