// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include "StdAfx.h"

void Serial_e_Etc()
{
	DWORD* Serial = (DWORD*)(0x0066FEF0); // Serial Offset, in this case, mxmain Version 1.01E are = 692174 
	memset(&Serial[0],0x00,17);           // Max digits (17)
	memcpy(&Serial[0],carrega.Serial,17); 

	DWORD* Versao = (DWORD*)(0x0066FEE8); // Version Offset, in this case, mxmain Version 1.01E are = 69216C
	memset(&Versao[0],0x00,6);            // Max digits (6)
	memcpy(&Versao[0],carrega.Versao,6);  

    DWORD* Ip = (DWORD*)(0x0067F3E2);     // IP Offset 
	memset(&Ip[0],0x00,15);               // Max digits (15)
    memcpy(&Ip[0],carrega.IP,15); 
}


