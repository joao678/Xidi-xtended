/*****************************************************************************
 * Xidi
 *      DirectInput interface for XInput controllers.
 *****************************************************************************
 * Authored by Samuel Grossman
 * Copyright (c) 2016
 *****************************************************************************
 * ExportApiWinMM.cpp
 *      Implementation of primary exported functions for the WinMM library.
 *****************************************************************************/

#include "ImportApiWinMM.h"
#include "WrapperJoyWinMM.h"

using namespace Xidi;


// -------- DLL EXPORT FUNCTIONS ------------------------------------------- //
// See WinMM documentation for more information.

MMRESULT WINAPI ExportApiWinMMAuxGetDevCapsA(UINT_PTR uDeviceID, LPAUXCAPSA lpCaps, UINT cbCaps)
{
    return ImportApiWinMM::auxGetDevCapsA(uDeviceID, lpCaps, cbCaps);
}

// ---------

MMRESULT WINAPI ExportApiWinMMAuxGetDevCapsW(UINT_PTR uDeviceID, LPAUXCAPSW lpCaps, UINT cbCaps)
{
    return ImportApiWinMM::auxGetDevCapsW(uDeviceID, lpCaps, cbCaps);
}

// ---------

UINT WINAPI ExportApiWinMMAuxGetNumDevs(void)
{
    return ImportApiWinMM::auxGetNumDevs();
}

// ---------

MMRESULT WINAPI ExportApiWinMMAuxGetVolume(UINT uDeviceID, LPDWORD lpdwVolume)
{
    return ImportApiWinMM::auxGetVolume(uDeviceID, lpdwVolume);
}

// ---------

MMRESULT WINAPI ExportApiWinMMAuxOutMessage(UINT uDeviceID, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2)
{
    return ImportApiWinMM::auxOutMessage(uDeviceID, uMsg, dwParam1, dwParam2);
}

// ---------

MMRESULT WINAPI ExportApiWinMMAuxSetVolume(UINT uDeviceID, DWORD dwVolume)
{
    return ImportApiWinMM::auxSetVolume(uDeviceID, dwVolume);
}

// ---------

MMRESULT WINAPI ExportApiWinMMJoyConfigChanged(DWORD dwFlags)
{
    return WrapperJoyWinMM::JoyConfigChanged(dwFlags);
}

// ---------

MMRESULT WINAPI ExportApiWinMMJoyGetDevCapsA(UINT_PTR uJoyID, LPJOYCAPSA pjc, UINT cbjc)
{
    return WrapperJoyWinMM::JoyGetDevCapsA(uJoyID, pjc, cbjc);
}

// ---------

MMRESULT WINAPI ExportApiWinMMJoyGetDevCapsW(UINT_PTR uJoyID, LPJOYCAPSW pjc, UINT cbjc)
{
    return WrapperJoyWinMM::JoyGetDevCapsW(uJoyID, pjc, cbjc);
}

// ---------

UINT WINAPI ExportApiWinMMJoyGetNumDevs(void)
{
    return WrapperJoyWinMM::JoyGetNumDevs();
}

// ---------

MMRESULT WINAPI ExportApiWinMMJoyGetPos(UINT uJoyID, LPJOYINFO pji)
{
    return WrapperJoyWinMM::JoyGetPos(uJoyID, pji);
}

// ---------

MMRESULT WINAPI ExportApiWinMMJoyGetPosEx(UINT uJoyID, LPJOYINFOEX pji)
{
    return WrapperJoyWinMM::JoyGetPosEx(uJoyID, pji);
}

// ---------

MMRESULT WINAPI ExportApiWinMMJoyGetThreshold(UINT uJoyID, LPUINT puThreshold)
{
    return WrapperJoyWinMM::JoyGetThreshold(uJoyID, puThreshold);
}

// ---------

MMRESULT WINAPI ExportApiWinMMJoyReleaseCapture(UINT uJoyID)
{
    return WrapperJoyWinMM::JoyReleaseCapture(uJoyID);
}

// ---------

MMRESULT WINAPI ExportApiWinMMJoySetCapture(HWND hwnd, UINT uJoyID, UINT uPeriod, BOOL fChanged)
{
    return WrapperJoyWinMM::JoySetCapture(hwnd, uJoyID, uPeriod, fChanged);
}

// ---------

MMRESULT WINAPI ExportApiWinMMJoySetThreshold(UINT uJoyID, UINT uThreshold)
{
    return WrapperJoyWinMM::JoySetThreshold(uJoyID, uThreshold);
}

// ---------

MMRESULT WINAPI ExportApiWinMMTimeBeginPeriod(UINT uPeriod)
{
    return ImportApiWinMM::timeBeginPeriod(uPeriod);
}

// ---------

MMRESULT WINAPI ExportApiWinMMTimeEndPeriod(UINT uPeriod)
{
    return ImportApiWinMM::timeEndPeriod(uPeriod);
}

// ---------

MMRESULT WINAPI ExportApiWinMMTimeGetDevCaps(LPTIMECAPS ptc, UINT cbtc)
{
    return ImportApiWinMM::timeGetDevCaps(ptc, cbtc);
}

// ---------

MMRESULT WINAPI ExportApiWinMMTimeGetSystemTime(LPMMTIME pmmt, UINT cbmmt)
{
    return ImportApiWinMM::timeGetSystemTime(pmmt, cbmmt);
}

// ---------

DWORD WINAPI ExportApiWinMMTimeGetTime(void)
{
    return ImportApiWinMM::timeGetTime();
}

// ---------

MMRESULT WINAPI ExportApiWinMMTimeKillEvent(UINT uTimerID)
{
    return ImportApiWinMM::timeKillEvent(uTimerID);
}

// ---------

MMRESULT WINAPI ExportApiWinMMTimeSetEvent(UINT uDelay, UINT uResolution, LPTIMECALLBACK lpTimeProc, DWORD_PTR dwUser, UINT fuEvent)
{
    return ImportApiWinMM::timeSetEvent(uDelay, uResolution, lpTimeProc, dwUser, fuEvent);
}