// Exercise1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

int main()
{ 
   STARTUPINFO si = { sizeof(si) };
   PROCESS_INFORMATION pi;

   TCHAR name[] = _T("calc");
   BOOL success = CreateProcess(nullptr, name, nullptr, nullptr, FALSE, 0, nullptr, nullptr, &si, &pi);
   if (success) {
      cout << "PID: " << pi.dwProcessId << endl;
      cout << "TID: " << pi.dwThreadId << endl;
      cout << "Process handle: " << pi.hProcess << endl;
      //WaitForSingleObject(pi.hProcess, INFINITE);  wait for process to exit
      //DWORD code;
      //GetExitCodeProcess(pi.hProcess, &code);
      //cout << "process exited with code" << code << endl;
      cin.get();
      CloseHandle(pi.hProcess);
      CloseHandle(pi.hThread);
   }
   else {
      cout << "Creation failed. error=" << GetLastError() << endl;
   }
    return 0;
}

