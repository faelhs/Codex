// Video tutorial: http://www.youtube.com/user/vertexbrasil

#include <process.h>    /* _beginthread, _endthread */
#include <string>
#include <windows.h>
#include <tlhelp32.h>
#include <fstream>
#include <iostream> 
#include "START.h"
#include <sstream>
#include <map>
#include <tchar.h>    //to T_ string title (start.cpp)

#include <stdio.h>   // pipe
#include <stdlib.h>  // pipe

#include "START.h"
#include "Classe.h"

using namespace std;

 #pragma warning (disable: 4996)

extern  "C"  __declspec(dllexport) void __cdecl Hl5(); 