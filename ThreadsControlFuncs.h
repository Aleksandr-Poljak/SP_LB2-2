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
/// Creates a new thread.
/// </summary>
/// <param name="thParams">Structure containing thread parameters.</param>
void CreateUserThread(ThreadParams thParams);

/// <summary>
/// Creates a thread that is in a waiting state.
/// </summary>
/// <param name="thParams">Structure containing thread parameters.</param>
void CreateWaitingThread(ThreadParams thParams);

/// <summary>
/// Suspends the execution of the specified thread.
/// </summary>
/// <param name="thParams">Structure containing thread parameters.</param>
void SuspendThread(ThreadParams thParams);

/// <summary>
/// Resumes the execution of the specified thread.
/// </summary>
/// <param name="thParams">Structure containing thread parameters.</param>
void ContinueThread(ThreadParams thParams);

/// <summary>
/// Terminates the specified thread.
/// </summary>
/// <param name="thParams">Structure containing thread parameters.</param>
/// <param name="quietMode">Silent mode.</param>
void DestroyUserThread(ThreadParams thParams, bool quietMode);

/// <summary>
/// Increases the priority of the specified thread.
/// </summary>
/// <param name="thParams">Structure containing thread parameters.</param>
void IncreasePriorityThread(ThreadParams thParams);

/// <summary>
/// Decreases the priority of the specified thread.
/// </summary>
/// <param name="thParams">Structure containing thread parameters.</param>
void DecreasePriorityThread(ThreadParams thParams);

/// <summary>
/// Displays information about the specified thread.
/// </summary>
/// <param name="thParams">Structure containing thread parameters.</param>
void ShowThreadInfo(ThreadParams thParams);

/// <summary>
/// Checks if a thread exists.
/// </summary>
/// <param name="thParams">Structure containing thread parameters.</param>
/// <returns>TRUE if the thread exists, otherwise FALSE.</returns>
BOOL IsThreadExist(ThreadParams thParams);
