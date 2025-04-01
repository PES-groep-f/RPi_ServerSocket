#include "globals.h"

unordered_map<string, int> clientMap;
mutex clientMapMutex;
string raspberryClientIP = "169.254.10.156";
string ventilatorIP = "10.42.0.64";
MainWindow* mainWindow = nullptr;
mutex mainWindowMutex;
