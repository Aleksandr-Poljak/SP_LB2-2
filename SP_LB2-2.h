#include "framework.h"
#include "resource.h"
#include "Windows.h"
#include "ThreadsControlFuncs.h"


/// <summary>
/// About
/// </summary>
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);


/// <summary>
/// Starts the ticker.
/// </summary>
DWORD WINAPI RunningLine(LPVOID lpParam);