#ifndef _MADCAPCL_H
#define _MADCAPCL_H

#if __POCC__ >= 500
#pragma once
#endif

/* MADCAP definitions */

#if defined(WIN32_DEFAULT_LIBS)
#pragma comment(lib, "dhcpcsvc.lib")
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>

#define MCAST_CLIENT_ID_LEN  17

#define MCAST_API_CURRENT_VERSION MCAST_API_VERSION_1

enum {
    MCAST_API_VERSION_0 = 0,
    MCAST_API_VERSION_1
};

typedef unsigned short IP_ADDR_FAMILY;

typedef union _IPNG_ADDRESS {
    DWORD IpAddrV4;
    BYTE IpAddrV6[16];
} IPNG_ADDRESS, *PIPNG_ADDRESS;

typedef struct _MCAST_CLIENT_UID {
    LPBYTE ClientUID;
    DWORD ClientUIDLength;
} MCAST_CLIENT_UID, *LPMCAST_CLIENT_UID;

typedef struct _MCAST_SCOPE_CTX {
    IPNG_ADDRESS ScopeID;
    IPNG_ADDRESS Interface;
    IPNG_ADDRESS ServerID;
} MCAST_SCOPE_CTX, *PMCAST_SCOPE_CTX;

typedef struct _MCAST_SCOPE_ENTRY {
    MCAST_SCOPE_CTX ScopeCtx;
    IPNG_ADDRESS LastAddr;
    DWORD TTL;
    UNICODE_STRING ScopeDesc;
} MCAST_SCOPE_ENTRY, *PMCAST_SCOPE_ENTRY;

typedef struct _MCAST_LEASE_REQUEST {
    LONG LeaseStartTime;
    LONG MaxLeaseStartTime;
    DWORD LeaseDuration;
    DWORD MinLeaseDuration;
    IPNG_ADDRESS ServerAddress;
    WORD MinAddrCount;
    WORD AddrCount;
    PBYTE pAddrBuf;
} MCAST_LEASE_REQUEST, *PMCAST_LEASE_REQUEST;

typedef struct _MCAST_LEASE_RESPONSE {
    LONG LeaseStartTime;
    LONG LeaseEndTime;
    IPNG_ADDRESS ServerAddress;
    WORD AddrCount;
    PBYTE pAddrBuf;
} MCAST_LEASE_RESPONSE, *PMCAST_LEASE_RESPONSE;

DWORD APIENTRY McastApiStartup(PDWORD);
VOID APIENTRY McastApiCleanup(VOID);
DWORD APIENTRY McastGenUID(LPMCAST_CLIENT_UID);
DWORD APIENTRY McastEnumerateScopes(IP_ADDR_FAMILY,BOOL,PMCAST_SCOPE_ENTRY,PDWORD,PDWORD);
DWORD APIENTRY McastRequestAddress(IP_ADDR_FAMILY,LPMCAST_CLIENT_UID,PMCAST_SCOPE_CTX,PMCAST_LEASE_REQUEST,PMCAST_LEASE_RESPONSE);
DWORD APIENTRY McastRenewAddress(IP_ADDR_FAMILY,LPMCAST_CLIENT_UID,PMCAST_LEASE_REQUEST,PMCAST_LEASE_RESPONSE);
DWORD APIENTRY McastReleaseAddress(IP_ADDR_FAMILY,LPMCAST_CLIENT_UID,PMCAST_LEASE_REQUEST);

#ifdef __cplusplus
}
#endif

#endif /* _MADCAPCL_H */
