// Program 1: Create a Child Process using Thread (Windows Supported)
#include <stdio.h>
#include <windows.h>

DWORD WINAPI childProcess(LPVOID lpParam) {
    printf("\n--- Child Process (Thread) ---\n");
    printf("Child simulated PID: 2002\n");
    printf("Parent simulated PID: 2001\n");
    return 0;
}

int main() {
    HANDLE thread;
    DWORD threadID;

    printf("--- Parent Process ---\n");
    printf("Parent simulated PID: 2001\n");

    // Create Child Process via Thread
    thread = CreateThread(NULL, 0, childProcess, NULL, 0, &threadID);

    if(thread != NULL) {
        WaitForSingleObject(thread, INFINITE); // Wait for child to finish
        CloseHandle(thread);
    }

    printf("\nChild Process Finished.\n");
    return 0;
}

