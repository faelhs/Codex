// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include "StdAfx.h"
CARREGAR carrega;

HANDLE m_DllModule;
extern  "C"  __declspec(dllexport) void __cdecl Hl5()  
{
	//GAMEGUARD.DLL GENERAL CONFIGURATION START///////////////////////////////
	 carrega.Dll_Build_Option            = 0; // [CHOICE!] Chose an option: 1= build Gameguard dll [Rename it: GameGuard.Dll], 2= build Inject dll = [Rename it: C.dll] 
//Mxmain Data:
	 carrega.MainWindowName              = "Mxmain";             // Exact the same as Codex.dll       
	 carrega.MainClassName               = "ConsoleWindowClass"; // Exact the same as Codex.dll      
	 carrega.Nome_do_Main	    		 = "Mxmain.exe";           // Exact the same as Codex.dll       
     carrega.Show_Splash_Message         = 0; // [I tink a good idea, alwais OFF = 0]  1 = Show a splash message, only use for configuration puposes!	
	 carrega.Shutdown_Computer           = 0; // [ATENTION! use at your own risk!] = Someone may not like this GameGuard.dll "feature"...  On/Off =  If GameGuard.dll can't kill Mxmain.exe after all, Guameguard.dll shutdown computer.
	//GAMEGUARD.DLL GENERAL CONFIGURATION END /////////////////////////////////
	

if (carrega.Dll_Build_Option == 0)
   {
	MessageBoxA(NULL,"WARNING! [START.cpp > carrega.Dll_Build_Option] turned OFF\n\nPlease choose an option to build an valid anti-hack dll file.", "GG CONFIGURATION MESSAGE", MB_SERVICE_NOTIFICATION | MB_ICONWARNING);}
   }

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	                          switch (ul_reason_for_call){
						      case DLL_PROCESS_ATTACH: m_DllModule = hModule;							 			  	
							  Hl5();	

   if(carrega.Dll_Build_Option == 1)
   {	
   CheckWindow_GG();
   Anti_kill1();
   Anti_kill2();					
   }

   if(carrega.Dll_Build_Option == 2)
   {
   CI();
   }
   								  
                 		  break;
					      case DLL_THREAD_ATTACH:
						  case DLL_THREAD_DETACH:
						  case DLL_PROCESS_DETACH:
						  break;
						  }
						  return TRUE;
}





