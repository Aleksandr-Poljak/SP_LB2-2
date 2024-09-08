#include <windows.h>
#include "SP_LB2-2.h"
#include <string>

BOOL IsThreadExist(ThreadParams thParams)
{
    BOOL flag = FALSE;
    int threadNum = thParams.Num;

    if (threadNum < 0 || threadNum > 2)
    {
        MessageBox(thParams.hWnd, L"Invalid thread number", L"Error", MB_OK | MB_ICONERROR);
        return TRUE;
    }
    if (hSecThread[threadNum] != NULL || dwSecThreadId[threadNum] != 0)  flag = TRUE;

    return flag;
}

void CreateUserThread(ThreadParams thParams)
{
    if (thParams.Num < 1 || thParams.Num > 2)
    {
        MessageBox(thParams.hWnd, _T("Incorrect thread number"), _T("Error"), MB_OK | MB_ICONERROR);
        return;
    }

    // ����������� ������� ��� ������
    LPTHREAD_START_ROUTINE lpThreadFunc = RunningLine;
    if (lpThreadFunc == NULL)
    {
        MessageBox(thParams.hWnd, _T("The thread function is not defined"), _T("Error"), MB_OK | MB_ICONERROR);
        return;
    }

    // �������� ������
    hSecThread[thParams.Num] = CreateThread(
        NULL,                     
        0,                        
        lpThreadFunc,             
        &thParams,               
        0,                        
        &dwSecThreadId[thParams.Num] 
    );

    // �������� ��������� �������� ������
    if (!IsThreadExist(thParams))
    {
        MessageBox(thParams.hWnd, _T("Failed to create a thread"), _T("Error"), MB_OK | MB_ICONERROR);
        return;
    }

    // ���������� �������� �������
    g_uThCount++;

    // ��������� �� �������� �������� ������
    std::wstring msg = L"Thread is " + std::to_wstring(thParams.Num) + L" created.";
    MessageBox(thParams.hWnd, msg.c_str(), L"Info", MB_OK);
}

void DestroyUserThread(ThreadParams thParams, bool quietMode)
{
    // �������� �� ���������� ����� ������
    if (thParams.Num < 0 || thParams.Num > 2)
    {
        if (!quietMode)
        {
            MessageBox(thParams.hWnd, L"The thread function is not defined", L"Error", MB_OK | MB_ICONERROR);
        }       
        return;
    }

    // ��������, ���������� �� �����
    if (!IsThreadExist(thParams))
    {
        if (!quietMode)
        {
            MessageBox(thParams.hWnd, L"The thread descriptor is not valid", L"Error", MB_OK | MB_ICONERROR);
        }       
        return;
    }

    // �������� ������� ���������� ������
    if ((TerminateThread(hSecThread[thParams.Num], 0) == 0) && quietMode == FALSE)
    {
        DWORD dwError = GetLastError();
        std::wstring errorMessage = L"Failed to terminate the thread. Error code: " + std::to_wstring(dwError);
        MessageBox(thParams.hWnd, errorMessage.c_str(), L"Error", MB_OK | MB_ICONERROR);
        return;
    }

    // �������� ���������� ������
    WaitForSingleObject(hSecThread[thParams.Num], INFINITE);

    // �������� ����������� ������
    CloseHandle(hSecThread[thParams.Num]);
    hSecThread[thParams.Num] = NULL;  // ��������� �����������
    dwSecThreadId[thParams.Num] = 0;  // ��������� �������������� ������

    // ���������� �������� �������
    g_uThCount--;

    // ��������� �� �������� ����������� ������
    if (quietMode == FALSE)
    {
        std::wstring msg = L"Thread " + std::to_wstring(thParams.Num) + L" Destroyed.";
        MessageBox(thParams.hWnd, msg.c_str(), L"Info", MB_OK);
    }
}

void CreateWaitingThread(ThreadParams thParams)
{

    if (thParams.Num < 1 || thParams.Num > 2)
    {
        MessageBox(thParams.hWnd, _T("Incorrect thread number"), _T("Error"), MB_OK | MB_ICONERROR);
        return;
    }

    // ����������� ������� ��� ������
    LPTHREAD_START_ROUTINE lpThreadFunc = RunningLine;
    if (lpThreadFunc == NULL)
    {
        MessageBox(thParams.hWnd, _T("The thread function is not defined"), _T("Error"), MB_OK | MB_ICONERROR);
        return;
    }

    // �������� ������
    hSecThread[thParams.Num] = CreateThread(
        NULL,
        0,
        lpThreadFunc,
        &thParams,
        CREATE_SUSPENDED,
        &dwSecThreadId[thParams.Num]
    );

    // �������� ��������� �������� ������
    if (!IsThreadExist(thParams))
    {
        MessageBox(thParams.hWnd, _T("Failed to create a thread"), _T("Error"), MB_OK | MB_ICONERROR);
        return;
    }

    // ���������� �������� �������
    g_uThCount++;

    // ��������� �� �������� �������� ������
    std::wstring msg = L"Thread is " + std::to_wstring(thParams.Num) + L" created.";
    MessageBox(thParams.hWnd, msg.c_str(), L"Info", MB_OK);

}

void SuspendThread(ThreadParams thParams) { MessageBox(NULL, L"Thread 1 suspended", L"Info", MB_OK); }

void ContinueThread(ThreadParams thParamsm) { MessageBox(NULL, L"Thread 1 continued", L"Info", MB_OK); }

void IncreasePriorityThread(ThreadParams thParams) { MessageBox(NULL, L"Thread 1 priority increased", L"Info", MB_OK); }

void DecreasePriorityThread(ThreadParams thParams) { MessageBox(NULL, L"Thread 1 priority decreased", L"Info", MB_OK); }

void ShowThreadInfo(ThreadParams thParams) { MessageBox(NULL, L"Thread 1 information", L"Info", MB_OK); }
