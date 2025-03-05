#include "globals.h"

unordered_map<string, int> clientMap;
mutex clientMapMutex;
string raspberryClientIP = "127.0.0.1";