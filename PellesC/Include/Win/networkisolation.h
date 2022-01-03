#ifndef _NETWORKISOLATION_H
#define _NETWORKISOLATION_H

#if __POCC__ >= 500
#pragma once
#endif

/* ApiSet api-ms-win-netsec-isolation-l1 */

/* #include <apiset.h> */
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>

#if (NTDDI_VERSION >= NTDDI_WIN8)

#ifndef __NET_ISOLATION_TYPES__
#define __NET_ISOLATION_TYPES__

typedef enum NETISO_FLAG {
    NETISO_FLAG_FORCE_COMPUTE_BINARIES = 0x1,
    NETISO_FLAG_MAX = 0x2
} NETISO_FLAG;

typedef enum _INET_FIREWALL_AC_CREATION_TYPE {
    INET_FIREWALL_AC_NONE = 0x00,
    INET_FIREWALL_AC_PACKAGE_ID_ONLY = 0x01,
    INET_FIREWALL_AC_BINARY = 0x02,
    INET_FIREWALL_AC_MAX = 0x04
} INET_FIREWALL_AC_CREATION_TYPE;

typedef enum _INET_FIREWALL_AC_CHANGE_TYPE {
    INET_FIREWALL_AC_CHANGE_INVALID = 0,
    INET_FIREWALL_AC_CHANGE_CREATE = 1,
    INET_FIREWALL_AC_CHANGE_DELETE = 2,
    INET_FIREWALL_AC_CHANGE_MAX = 3
} INET_FIREWALL_AC_CHANGE_TYPE;

typedef struct _INET_FIREWALL_AC_CAPABILITIES {
    DWORD count;
    SID_AND_ATTRIBUTES *capabilities;
} INET_FIREWALL_AC_CAPABILITIES, *PINET_FIREWALL_AC_CAPABILITIES;

typedef struct _INET_FIREWALL_AC_BINARIES {
    DWORD count;
    LPWSTR *binaries;
} INET_FIREWALL_AC_BINARIES, *PINET_FIREWALL_AC_BINARIES;

typedef struct _INET_FIREWALL_AC_CHANGE {
    INET_FIREWALL_AC_CHANGE_TYPE changeType;
    INET_FIREWALL_AC_CREATION_TYPE createType;
    SID *appContainerSid;
    SID *userSid;
    LPWSTR displayName;
    union {
        INET_FIREWALL_AC_CAPABILITIES capabilities;
        INET_FIREWALL_AC_BINARIES binaries;
    } u;
} INET_FIREWALL_AC_CHANGE, *PINET_FIREWALL_AC_CHANGE;

typedef struct _INET_FIREWALL_APP_CONTAINER {
    SID *appContainerSid;
    SID *userSid;
    LPWSTR appContainerName;
    LPWSTR displayName;
    LPWSTR description;
    INET_FIREWALL_AC_CAPABILITIES capabilities;
    INET_FIREWALL_AC_BINARIES binaries;
    LPWSTR workingDirectory;
    LPWSTR packageFullName;
} INET_FIREWALL_APP_CONTAINER, *PINET_FIREWALL_APP_CONTAINER;

#endif /* __NET_ISOLATION_TYPES__ */

typedef void (CALLBACK * PAC_CHANGES_CALLBACK_FN)(void *, const INET_FIREWALL_AC_CHANGE *);

HRESULT WINAPI NetworkIsolationSetupAppContainerBinaries(PSID, LPCWSTR, LPCWSTR, LPCWSTR, BOOL, LPCWSTR *, DWORD);
DWORD WINAPI NetworkIsolationRegisterForAppContainerChanges(DWORD, PAC_CHANGES_CALLBACK_FN, PVOID, HANDLE *);
DWORD WINAPI NetworkIsolationUnregisterForAppContainerChanges(HANDLE);
DWORD WINAPI NetworkIsolationFreeAppContainers(PINET_FIREWALL_APP_CONTAINER);
DWORD WINAPI NetworkIsolationEnumAppContainers(DWORD, DWORD *, PINET_FIREWALL_APP_CONTAINER *);
DWORD WINAPI NetworkIsolationGetAppContainerConfig(DWORD *, PSID_AND_ATTRIBUTES *);
DWORD WINAPI NetworkIsolationSetAppContainerConfig(DWORD, PSID_AND_ATTRIBUTES);

#ifndef __NET_ISOLATION_DIAG_TYPES__
#define __NET_ISOLATION_DIAG_TYPES__
typedef enum _NETISO_ERROR_TYPE {
    NETISO_ERROR_TYPE_NONE = 0x00,
    NETISO_ERROR_TYPE_PRIVATE_NETWORK = 0x01,
    NETISO_ERROR_TYPE_INTERNET_CLIENT = 0x02,
    NETISO_ERROR_TYPE_INTERNET_CLIENT_SERVER = 0x03,
    NETISO_ERROR_TYPE_MAX = 0x04
} NETISO_ERROR_TYPE;
#endif /* __NET_ISOLATION_DIAG_TYPES__ */

DWORD NetworkIsolationDiagnoseConnectFailure(LPCWSTR);
DWORD WINAPI NetworkIsolationDiagnoseConnectFailureAndGetInfo(LPCWSTR, NETISO_ERROR_TYPE *);

#endif /* NTDDI_VERSION >= NTDDI_WIN8 */

#endif /* _NETWORKISOLATION_H */
