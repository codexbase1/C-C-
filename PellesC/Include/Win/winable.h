#ifndef _WINABLE_H
#define _WINABLE_H

#if __POCC__ >= 500
#pragma once
#endif

/* Windows system event hooking definitions */

#define WINABLEAPI  DECLSPEC_IMPORT

#if defined(WIN32_DEFAULT_LIBS)
#pragma comment(lib, "user32.lib")
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>

#if (WINVER < 0x0500)

typedef struct tagGUITHREADINFO {
    DWORD cbSize;
    DWORD flags;
    HWND hwndActive;
    HWND hwndFocus;
    HWND hwndCapture;
    HWND hwndMenuOwner;
    HWND hwndMoveSize;
    HWND hwndCaret;
    RECT rcCaret;
} GUITHREADINFO, *LPGUITHREADINFO;

#define GUI_CARETBLINKING  0x00000001
#define GUI_INMOVESIZE  0x00000002
#define GUI_INMENUMODE  0x00000004
#define GUI_SYSTEMMENUMODE  0x00000008
#define GUI_POPUPMENUMODE  0x00000010

BOOL WINAPI GetGUIThreadInfo(DWORD,LPGUITHREADINFO);
UINT WINAPI GetWindowModuleFileNameW(HWND,LPWSTR,UINT);
UINT WINAPI GetWindowModuleFileNameA(HWND,LPSTR,UINT);

#ifdef UNICODE
#define GetWindowModuleFileName GetWindowModuleFileNameW
#else
#define GetWindowModuleFileName GetWindowModuleFileNameA
#endif

#endif /* WINVER < 0x0500 */

BOOL WINAPI BlockInput(BOOL);

#if (_WIN32_WINNT < 0x0403)

typedef struct tagMOUSEINPUT {
    LONG dx;
    LONG dy;
    DWORD mouseData;
    DWORD dwFlags;
    DWORD time;
    DWORD dwExtraInfo;
} MOUSEINPUT, *PMOUSEINPUT, *LPMOUSEINPUT;

typedef struct tagKEYBDINPUT {
    WORD wVk;
    WORD wScan;
    DWORD dwFlags;
    DWORD time;
    DWORD dwExtraInfo;
} KEYBDINPUT, *PKEYBDINPUT, *LPKEYBDINPUT;

typedef struct tagHARDWAREINPUT {
    DWORD uMsg;
    WORD wParamL;
    WORD wParamH;
    DWORD dwExtraInfo;
} HARDWAREINPUT, *PHARDWAREINPUT, *LPHARDWAREINPUT;

#define INPUT_MOUSE  0
#define INPUT_KEYBOARD  1
#define INPUT_HARDWARE  2

typedef struct tagINPUT {
    DWORD type;
    union {
        MOUSEINPUT mi;
        KEYBDINPUT ki;
        HARDWAREINPUT hi;
    };
} INPUT, *PINPUT, *LPINPUT;

UINT WINAPI SendInput(UINT,LPINPUT,int);
#endif /* (_WIN32_WINNT < 0x0403) */

#define CCHILDREN_FRAME  7

#if WINVER < 0x0500

WINABLEAPI void WINAPI NotifyWinEvent(DWORD,HWND,LONG,LONG);

#define CHILDID_SELF  0

#define OBJID_WINDOW  0x00000000
#define OBJID_SYSMENU  0xFFFFFFFF
#define OBJID_TITLEBAR  0xFFFFFFFE
#define OBJID_MENU  0xFFFFFFFD
#define OBJID_CLIENT  0xFFFFFFFC
#define OBJID_VSCROLL  0xFFFFFFFB
#define OBJID_HSCROLL  0xFFFFFFFA
#define OBJID_SIZEGRIP  0xFFFFFFF9
#define OBJID_CARET  0xFFFFFFF8
#define OBJID_CURSOR  0xFFFFFFF7
#define OBJID_ALERT  0xFFFFFFF6
#define OBJID_SOUND  0xFFFFFFF5

#define CCHILDREN_FRAME 7

#define ALERT_SYSTEM_INFORMATIONAL  1
#define ALERT_SYSTEM_WARNING  2
#define ALERT_SYSTEM_ERROR  3
#define ALERT_SYSTEM_QUERY  4
#define ALERT_SYSTEM_CRITICAL  5
#define CALERT_SYSTEM  6

typedef DWORD HWINEVENTHOOK;

typedef VOID (CALLBACK *WINEVENTPROC)(HWINEVENTHOOK,DWORD,HWND,LONG,LONG,DWORD,DWORD);

#define WINEVENT_OUTOFCONTEXT  0x0000
#define WINEVENT_SKIPOWNTHREAD  0x0001
#define WINEVENT_SKIPOWNPROCESS 0x0002
#define WINEVENT_INCONTEXT  0x0004
#define WINEVENT_32BITCALLER  0x8000
#define WINEVENT_VALID  0x8007

WINABLEAPI HWINEVENTHOOK WINAPI SetWinEventHook(DWORD,DWORD,HMODULE,WINEVENTPROC,DWORD,DWORD,DWORD);
WINABLEAPI BOOL WINAPI UnhookWinEvent(HWINEVENTHOOK);

#define EVENT_MIN  0x00000001
#define EVENT_MAX  0x7FFFFFFF

#define EVENT_SYSTEM_SOUND  0x0001
#define EVENT_SYSTEM_ALERT  0x0002
#define EVENT_SYSTEM_FOREGROUND 0x0003
#define EVENT_SYSTEM_MENUSTART  0x0004
#define EVENT_SYSTEM_MENUEND  0x0005
#define EVENT_SYSTEM_MENUPOPUPSTART 0x0006
#define EVENT_SYSTEM_MENUPOPUPEND  0x0007
#define EVENT_SYSTEM_CAPTURESTART  0x0008
#define EVENT_SYSTEM_CAPTUREEND  0x0009
#define EVENT_SYSTEM_MOVESIZESTART  0x000A
#define EVENT_SYSTEM_MOVESIZEEND  0x000B
#define EVENT_SYSTEM_CONTEXTHELPSTART  0x000C
#define EVENT_SYSTEM_CONTEXTHELPEND  0x000D
#define EVENT_SYSTEM_DRAGDROPSTART  0x000E
#define EVENT_SYSTEM_DRAGDROPEND  0x000F
#define EVENT_SYSTEM_DIALOGSTART  0x0010
#define EVENT_SYSTEM_DIALOGEND  0x0011
#define EVENT_SYSTEM_SCROLLINGSTART 0x0012
#define EVENT_SYSTEM_SCROLLINGEND  0x0013
#define EVENT_SYSTEM_SWITCHSTART  0x0014
#define EVENT_SYSTEM_SWITCHEND  0x0015
#define EVENT_SYSTEM_MINIMIZESTART  0x0016
#define EVENT_SYSTEM_MINIMIZEEND  0x0017

#define EVENT_OBJECT_CREATE  0x8000
#define EVENT_OBJECT_DESTROY  0x8001
#define EVENT_OBJECT_SHOW  0x8002
#define EVENT_OBJECT_HIDE  0x8003
#define EVENT_OBJECT_REORDER  0x8004
#define EVENT_OBJECT_FOCUS  0x8005
#define EVENT_OBJECT_SELECTION  0x8006
#define EVENT_OBJECT_SELECTIONADD  0x8007
#define EVENT_OBJECT_SELECTIONREMOVE  0x8008
#define EVENT_OBJECT_SELECTIONWITHIN  0x8009
#define EVENT_OBJECT_STATECHANGE  0x800A
#define EVENT_OBJECT_LOCATIONCHANGE  0x800B
#define EVENT_OBJECT_NAMECHANGE  0x800C
#define EVENT_OBJECT_DESCRIPTIONCHANGE  0x800D
#define EVENT_OBJECT_VALUECHANGE  0x800E
#define EVENT_OBJECT_PARENTCHANGE  0x800F
#define EVENT_OBJECT_HELPCHANGE  0x8010
#define EVENT_OBJECT_DEFACTIONCHANGE  0x8011
#define EVENT_OBJECT_ACCELERATORCHANGE  0x8012

#endif /* WINVER < 0x0500 */

#ifdef __cplusplus
}
#endif

#endif /* _WINABLE_H */
