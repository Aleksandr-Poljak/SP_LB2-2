#include <wtypes.h>
#include <Windows.h>

// Number of threads. 
extern DWORD g_uThCount;

// Thread descriptors.
extern HANDLE hSecThread[3];

// Threads identifiers
extern DWORD dwSecThreadId[3];

struct ThreadParams
{
    int Num;
    UINT xPos;
    UINT yPos;
    HWND hWnd;

    ThreadParams(HWND hwnd, int num, UINT x = 1, UINT y = 1)
        : Num(num), xPos(x), yPos(y), hWnd(hwnd)
    {
    }
};

/// <summary>
/// ������� ����� �����.
/// </summary>
/// <param name="thParams">��������� � ����������� ������.</param>
void CreateUserThread(ThreadParams thParams);

/// <summary>
/// ������� �����, ������� ��������� � ��������.
/// </summary>
/// <param name="thParams">��������� � ����������� ������.</param>
void CreateWaitingThread(ThreadParams thParams);

/// <summary>
/// ���������������� ���������� ���������� ������.
/// </summary>
/// <param name="thParams">��������� � ����������� ������.</param>
void SuspendThread(ThreadParams thParams);

/// <summary>
/// ������������ ���������� ���������� ������.
/// </summary>
/// <param name="thParams">��������� � ����������� ������.</param>
void ContinueThread(ThreadParams thParams);

/// <summary>
/// ��������� ��������� �����.
/// </summary>
/// <param name="thParams">��������� � ����������� ������.</param>
/// <param name="quietMode">����� ������.</param>
void DestroyUserThread(ThreadParams thParams, bool quietMode);

/// <summary>
/// ����������� ��������� ���������� ���������� ������.
/// </summary>
/// <param name="thParams">��������� � ����������� ������.</param>
void IncreasePriorityThread(ThreadParams thParams);

/// <summary>
/// ��������� ��������� ���������� ���������� ������.
/// </summary>
/// <param name="thParams">��������� � ����������� ������.</param>
void DecreasePriorityThread(ThreadParams thParams);

/// <summary>
/// ���������� ���������� � ��������� ������.
/// </summary>
/// <param name="thParams">��������� � ����������� ������.</param>
void ShowThreadInfo(ThreadParams thParams);

/// <summary>
/// ���������, ���������� �� �����.
/// </summary>
/// <param name="thParams">��������� � ����������� ������.</param>
/// <returns>TRUE, ���� ����� ����������, ����� FALSE.</returns>
BOOL IsThreadExist(ThreadParams thParams);
