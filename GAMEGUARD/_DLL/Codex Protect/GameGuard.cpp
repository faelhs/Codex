// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include "StdAfx.h"

// MAIN KILL - START //////////////////////////////////////////////////////////////////////////////////
int Shutdown(){	
	Sleep(4000);
HWND WinTitle = FindWindowA(NULL,carrega.MainWindowName);
if( WinTitle != 0){  // != 
	HWND WinClasse = FindWindowExA(NULL,NULL,carrega.MainClassName,NULL);
if( WinClasse != 0){ // !=
if (carrega.Shutdown_Computer == 1){
	system("shutdown -r -t 10");  // If everything fail: -r reestart -s shutdown -t 10 seconds
//cout <<"COMPUTER SHUTDOWN IN 10 SECONDS!"<<endl;
ExitProcess(0);
return(0);
}
else
{
//cout <<"COMPUTER SHUTDOWN DON'T NEEDED!"<<endl;
}
}
}
ExitProcess(0);
return(0);
}
void Msg_PK_1(){
	MessageBoxA(NULL,"GuameGuard closing: Nome_do_Main!\n\nDisable: [carrega.Show_Splash_Message] after configuration!", "GG - CONFIGURATION MESSAGE", MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
ExitProcess(0);
}
void PipeMessage1(){
	if (carrega.Show_Splash_Message == 1){
    CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_PK_1),NULL,0,0);
	Shutdown();
}
else
{
Shutdown();
}
}
int gargalo = 0;
void PipeMessage(){
gargalo++; 
if (gargalo == 1){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(PipeMessage1),NULL,0,0);
 }
 else
 {
 _endthread();
}
}
void GoPID_Kill()
{ 	
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    if (Process32First(snapshot, &entry) == TRUE)
    {
        while (Process32Next(snapshot, &entry) == TRUE)
        {
            if (stricmp(entry.szExeFile, carrega.Nome_do_Main) == 0)
            {  
            //cout << "If Exist: Close process by PID"<<endl;
			HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
        	TerminateProcess(hProcess,NULL);
			//cout << "PID = PipeMessage2x"<<endl;
			}
        }
    }
    CloseHandle(snapshot);
	//cout << "PID close snapshot, endthread!"<<endl;
}
void Main_Kill2(){
HWND WinTitle = FindWindowA(NULL, carrega.MainWindowName);
SendMessage(WinTitle, WM_CLOSE,0,0);  
//cout << "Close process by Window name"<<endl;
/////////////////////////////////
HWND WinClasse = FindWindowExA(NULL,NULL,carrega.MainClassName,NULL);
SendMessage(WinClasse, WM_CLOSE,0,0);  
//cout << "Close process by Class name"<<endl;
/////////////////////////////////
PipeMessage();
GoPID_Kill();
}
void Main_Kill(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Main_Kill2),NULL,0,0);
}
// MAIN.EXE KILL - END ////////////////////////////////////////////////////////////////////////////////




// GAMEGUARD DLL - START ////////////////////////////////////////////////////////////////////////////////
char * CreateFileName   = "b.cdx";  //1 //PERSONALIZE Name file/adress FOR MORE SECURITY
char * ReadFileName     = "a.cdx";  //2 //PERSONALIZE Name file/adress FOR MORE SECURITY
int aio = 0;

void TxtFileCreate(){ 
	SetFileAttributes("b.cdx", FILE_ATTRIBUTE_HIDDEN); // Set file as a HIDDEN file
again:
   //cout <<"Main Create file"<<endl;
aio ++;
   //cout <<aio <<endl;
	ofstream file3(CreateFileName, ios::app);
    file3 << " ";
	file3.close();	
	if (aio > 100){
		std::ofstream(CreateFileName);	//Delete/Reset all file content
		file3.close();        
		aio = 0;
		Sleep (250);
		goto again;
	}
	else
	{
		Sleep (250);
		goto again;
	}
}
void Sizemeter(){
	Dpipe();  //Antikill
	Sleep (200);
	Dpipe();  //Antikill
	Sleep (200);
	Dpipe();  //Antikill
	Sleep (200);
	Dpipe();  //Antikill
	Sleep (200);
	Dpipe();  //Antikill
	Sleep (200);
	Dpipe();  //Antikill
	Sleep (200);
	Dpipe();  //Antikill
	Sleep (200);
	Dpipe();  //Antikill
	Sleep (200);
	Dpipe();  //Antikill
	Sleep (200);
	Dpipe();  //Antikill
	Sleep (200);
	Dpipe();  //Antikill
again:
	//cout <<"Main sizimeter"<<endl;
	ifstream file(ReadFileName, ios::binary | ios::ate);
			Dpipe();  //Antikill
			Sleep (200);	
			Dpipe();  //Antikill   // 600 ms
			Sleep (200);
			Dpipe();  //Antikill
			Sleep (200);
			Dpipe();  //Antikill
	ifstream file2(ReadFileName, ios::binary | ios::ate);
	//cout <<"Size 1:"<< file.tellg()<< "  Size 2:" <<file2.tellg()<<endl;
	if (file.tellg() == file2.tellg()){
	//cout <<"Filesize match! - Game over!"<<endl;		
	Main_Kill();
	}
	else
	{
	file.close();
	file2.close();
goto again;
}
}
void CheckWindow_GG(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(TxtFileCreate),NULL,0,0);
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Sizemeter),NULL,0,0); 
}





