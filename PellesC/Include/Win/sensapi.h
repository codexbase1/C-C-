#ifndef _SENSAPI_H
#define _SENSAPI_H

#if __POCC__ >= 500
#pragma once
#endif

/* SENS Connectivity API definitions */

#if defined(WIN32_DEFAULT_LIBS)
#pragma comment(lib, "sensapi.lib")
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define NETWORK_ALIVE_LAN  0x00000001
#define NETWORK_ALIVE_WAN  0x00000002
#define NETWORK_ALIVE_AOL  0x00000004

typedef struct tagQOCINFO {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwInSpeed;
    DWORD dwOutSpeed;
} QOCINFO, *LPQOCINFO;

BOOL APIENTRY IsDestinationReachableA(LPCSTR,LPQOCINFO);
BOOL APIENTRY IsDestinationReachableW(LPCWSTR,LPQOCINFO);
BOOL APIENTRY IsNetworkAlive(LPDWORD);

#ifdef UNICODE
#define IsDestinationReachable  IsDestinationReachableW
#else
#define IsDestinationReachable  IsDestinationReachableA
#endif /* UNICODE */

#ifdef __cplusplus
}
#endif

#endif /* _SENSAPI_H */
