#include "SP_LB2-2.h"

void ControlMenu(HMENU hMenu)
{

	// ”правление меню потока 1
	if (hSecThread[1] == NULL)
	{
		EnableMenuItem(hMenu, ID_THREAD1_CREATE_THREAD, MF_ENABLED);
		EnableMenuItem(hMenu, ID_THREAD1_CREATE_WAITING_THREAD, MF_ENABLED);
		EnableMenuItem(hMenu, ID_THREAD1_SUSPEND_THREAD, MF_GRAYED);
		EnableMenuItem(hMenu, ID_THREAD1_CONTINUE_WORK_THREAD, MF_GRAYED);
		EnableMenuItem(hMenu, ID_THREAD1_DESTROY_THREAD, MF_GRAYED);
		EnableMenuItem(hMenu, ID_THREAD1_INCREASE_PRIORITY, MF_GRAYED);
		EnableMenuItem(hMenu, ID_THREAD1_DECREASE_PRIORITY, MF_GRAYED);
		EnableMenuItem(hMenu, ID_THREADSINFORMATION_THREAD1, MF_GRAYED);

		
	}
	else
	{
		EnableMenuItem(hMenu, ID_THREAD1_CREATE_THREAD, MF_GRAYED);
		EnableMenuItem(hMenu, ID_THREAD1_CREATE_WAITING_THREAD, MF_GRAYED);
		EnableMenuItem(hMenu, ID_THREAD1_SUSPEND_THREAD, MF_ENABLED);
		EnableMenuItem(hMenu, ID_THREAD1_CONTINUE_WORK_THREAD, MF_ENABLED);
		EnableMenuItem(hMenu, ID_THREAD1_DESTROY_THREAD, MF_ENABLED);
		EnableMenuItem(hMenu, ID_THREAD1_INCREASE_PRIORITY, MF_ENABLED);
		EnableMenuItem(hMenu, ID_THREAD1_DECREASE_PRIORITY, MF_ENABLED);
		EnableMenuItem(hMenu, ID_THREADSINFORMATION_THREAD1, MF_ENABLED);
	}


	// ”правление меню потока 2
	if (hSecThread[2] == NULL)
	{
		EnableMenuItem(hMenu, ID_THREAD2_CREATE_THREAD, MF_ENABLED);
		EnableMenuItem(hMenu, ID_THREAD2_CREATE_WAITING_THREAD, MF_ENABLED);
		EnableMenuItem(hMenu, ID_THREAD2_SUSPEND_THREAD, MF_GRAYED);
		EnableMenuItem(hMenu, ID_THREAD2_CONTINUE_WORK_THREAD, MF_GRAYED);
		EnableMenuItem(hMenu, ID_THREAD2_DESTROY_THREAD, MF_GRAYED);
		EnableMenuItem(hMenu, ID_THREAD2_INCREASE_PRIORITY, MF_GRAYED);
		EnableMenuItem(hMenu, ID_THREAD2_DECREASE_PRIORITY, MF_GRAYED);
		EnableMenuItem(hMenu, ID_THREADSINFORMATION_THREAD2, MF_GRAYED);


	}
	else
	{
		EnableMenuItem(hMenu, ID_THREAD2_CREATE_THREAD, MF_GRAYED);
		EnableMenuItem(hMenu, ID_THREAD2_CREATE_WAITING_THREAD, MF_GRAYED);
		EnableMenuItem(hMenu, ID_THREAD2_SUSPEND_THREAD, MF_ENABLED);
		EnableMenuItem(hMenu, ID_THREAD2_CONTINUE_WORK_THREAD, MF_ENABLED);
		EnableMenuItem(hMenu, ID_THREAD2_DESTROY_THREAD, MF_ENABLED);
		EnableMenuItem(hMenu, ID_THREAD2_INCREASE_PRIORITY, MF_ENABLED);
		EnableMenuItem(hMenu, ID_THREAD2_DECREASE_PRIORITY, MF_ENABLED);
		EnableMenuItem(hMenu, ID_THREADSINFORMATION_THREAD2, MF_ENABLED);
	}
}

void ShowThreadInfoDialog(HWND hWnd, const ThreadInfo& threadInfo)
{
	TCHAR szInfo[256];
	wsprintf(szInfo, _T("ID: %lu\n"), threadInfo.dwThreadId);
	wsprintf(szInfo + lstrlen(szInfo), _T("Stream: %p\n"), threadInfo.hThread);
	wsprintf(szInfo + lstrlen(szInfo), _T("State: %s\n"), (threadInfo.dwThreadState == STILL_ACTIVE) ? _T("Active") : _T("Completed"));
	wsprintf(szInfo + lstrlen(szInfo), _T("Relative priority: %d\n"), threadInfo.nThreadPriority);
	FILETIME ftNow;
	GetSystemTimeAsFileTime(&ftNow);
	ULARGE_INTEGER ullCurrentTime;
	ullCurrentTime.LowPart = ftNow.dwLowDateTime;
	ullCurrentTime.HighPart = ftNow.dwHighDateTime;
	ULONGLONG ullElapsedTime = ullCurrentTime.QuadPart - threadInfo.ullThreadStartTime;
	wsprintf(szInfo + lstrlen(szInfo), _T("Rrunning time: %lu milliseconds\n"), ullElapsedTime / 10000);
	MessageBox(hWnd, szInfo, _T("Thread INFO"), MB_OK | MB_ICONINFORMATION);
}
