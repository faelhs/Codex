// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include "stdafx.h"

int Antikill, sec, i, x, DAka1, DAkb1, Dpipe1 = 0;
void Detectors_ON(){ 
	Antikill = 3;
}

void Reset_int(){
DAka1 =0;
DAkb1 =0;
Dpipe1 = 0;
    }
void DAka(){
	DAka1 =1;
	}
void DAkb(){
	DAkb1 =1;
	}
void Dpipe(){
	Dpipe1 = 1;
    }


//AK1/////////////////////////////
void Sec(){
	sec = 1;
};
void AK1(){	  
int Soma = DAka1 + DAkb1 + Dpipe1;
if (Soma != Antikill)
{ 
//MessageBoxA(NULL,"ANTI-KILL HIDE DLL DEU SOMA ERRADA!", "HIDE DLL", MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
Main_Kill();
}
else
{
Reset_int();
}
}

void A_Kill1(){	
	Detectors_ON();
	DAka();
	Sec();
again:
	Sleep (600/2); 	
	DAka();
	Sec();
	i++;
	//cout << "DAKa e Sec "<< endl;
	if (i == 2){ 
	//cout << "AKA 1"<< endl;
		i = 0;
		AK1();
	goto again;
	}
	else
	{
	goto again;
}
}
void Anti_kill1(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(A_Kill1),NULL,0,0);
}

//AK2/////////////////////////////
void Reset_Sec(){
    sec = 0;
};

void A_Kill2(){
	DAkb();
again:
	Sleep (600/2); 
	DAkb();
	x ++;
	if (x != 2){ 
goto again;		
	}
else
	{
	x = 0;
if (sec == 0){
Main_Kill();
	}
else
	{
	x = 0;
	Reset_Sec();
goto again;
	}
  }
}

void Anti_kill2(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(A_Kill2),NULL,0,0);
}



