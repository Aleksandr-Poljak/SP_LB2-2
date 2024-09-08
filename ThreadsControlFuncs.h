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
/// Создает новый поток.
/// </summary>
/// <param name="thParams">Структура с параметрами потока.</param>
void CreateUserThread(ThreadParams thParams);

/// <summary>
/// Создает поток, который находится в ожидании.
/// </summary>
/// <param name="thParams">Структура с параметрами потока.</param>
void CreateWaitingThread(ThreadParams thParams);

/// <summary>
/// Приостанавливает выполнение указанного потока.
/// </summary>
/// <param name="thParams">Структура с параметрами потока.</param>
void SuspendThread(ThreadParams thParams);

/// <summary>
/// Возобновляет выполнение указанного потока.
/// </summary>
/// <param name="thParams">Структура с параметрами потока.</param>
void ContinueThread(ThreadParams thParams);

/// <summary>
/// Завершает указанный поток.
/// </summary>
/// <param name="thParams">Структура с параметрами потока.</param>
/// <param name="quietMode">Режим тишины.</param>
void DestroyUserThread(ThreadParams thParams, bool quietMode);

/// <summary>
/// Увеличивает приоритет выполнения указанного потока.
/// </summary>
/// <param name="thParams">Структура с параметрами потока.</param>
void IncreasePriorityThread(ThreadParams thParams);

/// <summary>
/// Уменьшает приоритет выполнения указанного потока.
/// </summary>
/// <param name="thParams">Структура с параметрами потока.</param>
void DecreasePriorityThread(ThreadParams thParams);

/// <summary>
/// Показывает информацию о указанном потоке.
/// </summary>
/// <param name="thParams">Структура с параметрами потока.</param>
void ShowThreadInfo(ThreadParams thParams);

/// <summary>
/// Проверяет, существует ли поток.
/// </summary>
/// <param name="thParams">Структура с параметрами потока.</param>
/// <returns>TRUE, если поток существует, иначе FALSE.</returns>
BOOL IsThreadExist(ThreadParams thParams);
