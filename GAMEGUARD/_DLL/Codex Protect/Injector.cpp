// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include "StdAfx.h"

BOOL EnableDebugPrivilege()
{
    HANDLE hToken;
    LUID luid;
    TOKEN_PRIVILEGES tkp;
    if(!OpenProcessToken( GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken ))
    {
		//cout << "1 false" <<endl;
        return FALSE;		
    }
    if(!LookupPrivilegeValue( NULL, SE_DEBUG_NAME, &luid ))
    {
		//cout << "2 false" <<endl;
        return FALSE;	
    }
    tkp.PrivilegeCount = 1;
    tkp.Privileges[0].Luid = luid;
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    if(!AdjustTokenPrivileges( hToken, false, &tkp, sizeof( tkp ), NULL, NULL ))
    {
		//cout << "3 false" <<endl;
        return FALSE;	
    }
    if(!CloseHandle( hToken ))
    {
		//cout << "4 false" <<endl;
        return FALSE;		
    }
	//cout << " true" <<endl;
    return TRUE;
}

typedef LONG (NTAPI *NtResumeProcess)(IN HANDLE ProcessHandle); 
void C_I2(DWORD processId){
again:
	Sleep (5000);
    HWND procHwnd;
    DWORD pid;
    procHwnd = FindWindow(NULL, carrega.MainWindowName); 
    if (procHwnd != 0){ 
//cout << "Window Running"<<endl;
        GetWindowThreadProcessId(procHwnd, &pid); //  function that captures the pid
//cout<<"The window pid is "<< pid<<endl;
    HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    NtResumeProcess pfnNtResumeProcess = (NtResumeProcess)GetProcAddress(
    GetModuleHandle("ntdll"), "NtResumeProcess");
    pfnNtResumeProcess(processHandle);
    CloseHandle(processHandle);
goto again;
	}
	else
	{
goto again;
}
}


void CI(){	
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(EnableDebugPrivilege),NULL,0,0);	
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(C_I2),NULL,0,0);
}

