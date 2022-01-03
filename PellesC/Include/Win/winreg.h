#ifndef _WINREG_H
#define _WINREG_H

/* Windows Registry API definitions */

#if __POCC__ >= 500
#pragma once
#endif

#if defined(WIN32_DEFAULT_LIBS)
#pragma comment(lib, "advapi32.lib")
#endif

/* API Set api-ms-win-core-registry-l1 */

/* #include <winapifamily.h> */

/* #include <apiset.h> */
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>

#ifndef WINVER
#define WINVER  0x0500
#endif /* !WINVER */

#define RRF_RT_REG_NONE  0x00000001
#define RRF_RT_REG_SZ  0x00000002
#define RRF_RT_REG_EXPAND_SZ  0x00000004
#define RRF_RT_REG_BINARY  0x00000008
#define RRF_RT_REG_DWORD  0x00000010
#define RRF_RT_REG_MULTI_SZ  0x00000020
#define RRF_RT_REG_QWORD  0x00000040

#define RRF_RT_DWORD  (RRF_RT_REG_BINARY | RRF_RT_REG_DWORD)
#define RRF_RT_QWORD  (RRF_RT_REG_BINARY | RRF_RT_REG_QWORD)
#define RRF_RT_ANY  0x0000ffff

#if (_WIN32_WINNT >= _WIN32_WINNT_WINTHRESHOLD)
#define RRF_SUBKEY_WOW6464KEY  0x00010000
#define RRF_SUBKEY_WOW6432KEY  0x00020000
#define RRF_WOW64_MASK  0x00030000
#endif /* _WIN32_WINNT >= _WIN32_WINNT_WINTHRESHOLD */

#define RRF_NOEXPAND  0x10000000
#define RRF_ZEROONFAILURE  0x20000000

#define REG_PROCESS_APPKEY  0x00000001

#define REG_MUI_STRING_TRUNCATE  0x00000001

typedef ACCESS_MASK REGSAM;

#define HKEY_CLASSES_ROOT  ((HKEY)(ULONG_PTR)((LONG)0x80000000))
#define HKEY_CURRENT_USER  ((HKEY)(ULONG_PTR)((LONG)0x80000001))
#define HKEY_LOCAL_MACHINE  ((HKEY)(ULONG_PTR)((LONG)0x80000002))
#define HKEY_USERS  ((HKEY)(ULONG_PTR)((LONG)0x80000003))
#define HKEY_PERFORMANCE_DATA  ((HKEY)(ULONG_PTR)((LONG)0x80000004))
#define HKEY_PERFORMANCE_TEXT  ((HKEY)(ULONG_PTR)((LONG)0x80000050))
#define HKEY_PERFORMANCE_NLSTEXT  ((HKEY)(ULONG_PTR)((LONG)0x80000060))
#define HKEY_CURRENT_CONFIG  ((HKEY)(ULONG_PTR)((LONG)0x80000005))
#define HKEY_DYN_DATA  ((HKEY)(ULONG_PTR)((LONG)0x80000006))
#define HKEY_CURRENT_USER_LOCAL_SETTINGS  ((HKEY)(ULONG_PTR)((LONG)0x80000007))

#define REG_SECURE_CONNECTION  1

#ifndef _PROVIDER_STRUCTS_DEFINED
#define _PROVIDER_STRUCTS_DEFINED

#define PROVIDER_KEEPS_VALUE_LENGTH  0x1

struct val_context {
    int valuelen;
    LPVOID value_context;
    LPVOID val_buff_ptr;
};

typedef struct val_context *PVALCONTEXT;

typedef struct pvalueA {
    LPSTR pv_valuename;
    int pv_valuelen;
    LPVOID pv_value_context;
    DWORD pv_type;
} PVALUEA, *PPVALUEA;

typedef struct pvalueW {
    LPWSTR pv_valuename;
    int pv_valuelen;
    LPVOID pv_value_context;
    DWORD pv_type;
} PVALUEW, *PPVALUEW;

#ifdef UNICODE
typedef PVALUEW PVALUE;
typedef PPVALUEW PPVALUE;
#else /* !UNICODE */
typedef PVALUEA PVALUE;
typedef PPVALUEA PPVALUE;
#endif /* !UNICODE */

typedef DWORD __cdecl QUERYHANDLER(LPVOID, PVALCONTEXT, DWORD, LPVOID, DWORD *, DWORD);

typedef QUERYHANDLER *PQUERYHANDLER;

typedef struct provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_key_context;
} REG_PROVIDER;

typedef struct provider_info *PPROVIDER;

typedef struct value_entA {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
} VALENTA, *PVALENTA;

typedef struct value_entW {
    LPWSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
} VALENTW, *PVALENTW;

#ifdef UNICODE
typedef VALENTW VALENT;
typedef PVALENTW PVALENT;
#else /* !UNICODE */
typedef VALENTA VALENT;
typedef PVALENTA PVALENT;
#endif /* !UNICODE */

#endif /* !_PROVIDER_STRUCTS_DEFINED */

#define WIN31_CLASS  NULL

typedef LONG LSTATUS;

WINADVAPI LSTATUS APIENTRY RegCloseKey(HKEY);
WINADVAPI LSTATUS APIENTRY RegOverridePredefKey(HKEY, HKEY);
WINADVAPI LSTATUS APIENTRY RegOpenUserClassesRoot(HANDLE, DWORD, REGSAM, PHKEY);
WINADVAPI LSTATUS APIENTRY RegOpenCurrentUser(REGSAM, PHKEY);
WINADVAPI LSTATUS APIENTRY RegDisablePredefinedCache(VOID);
WINADVAPI LSTATUS APIENTRY RegDisablePredefinedCacheEx(VOID);
WINADVAPI LSTATUS APIENTRY RegConnectRegistryA(LPCSTR, HKEY, PHKEY);
WINADVAPI LSTATUS APIENTRY RegConnectRegistryW(LPCWSTR, HKEY, PHKEY);
WINADVAPI LSTATUS APIENTRY RegConnectRegistryExA(LPCSTR, HKEY, ULONG, PHKEY);
WINADVAPI LSTATUS APIENTRY RegConnectRegistryExW(LPCWSTR, HKEY, ULONG, PHKEY);
WINADVAPI LSTATUS APIENTRY RegCreateKeyA(HKEY, LPCSTR, PHKEY);
WINADVAPI LSTATUS APIENTRY RegCreateKeyW(HKEY, LPCWSTR, PHKEY);
WINADVAPI LSTATUS APIENTRY RegCreateKeyExA(HKEY, LPCSTR, DWORD, LPSTR, DWORD, REGSAM, CONST LPSECURITY_ATTRIBUTES, PHKEY, LPDWORD);
WINADVAPI LSTATUS APIENTRY RegCreateKeyExW(HKEY, LPCWSTR, DWORD, LPWSTR, DWORD, REGSAM, CONST LPSECURITY_ATTRIBUTES, PHKEY, LPDWORD);
WINADVAPI LSTATUS APIENTRY RegCreateKeyTransactedA(HKEY, LPCSTR, DWORD, LPSTR, DWORD, REGSAM, CONST LPSECURITY_ATTRIBUTES, PHKEY, LPDWORD, HANDLE, PVOID);
WINADVAPI LSTATUS APIENTRY RegCreateKeyTransactedW(HKEY, LPCWSTR, DWORD, LPWSTR, DWORD, REGSAM, CONST LPSECURITY_ATTRIBUTES, PHKEY, LPDWORD, HANDLE, PVOID);
WINADVAPI LSTATUS APIENTRY RegDeleteKeyA(HKEY, LPCSTR);
WINADVAPI LSTATUS APIENTRY RegDeleteKeyW(HKEY, LPCWSTR);
WINADVAPI LSTATUS APIENTRY RegDeleteKeyExA(HKEY, LPCSTR, REGSAM, DWORD);
WINADVAPI LSTATUS APIENTRY RegDeleteKeyExW(HKEY, LPCWSTR, REGSAM, DWORD);
WINADVAPI LSTATUS APIENTRY RegDeleteKeyTransactedA(HKEY, LPCSTR, REGSAM, DWORD, HANDLE, PVOID);
WINADVAPI LSTATUS APIENTRY RegDeleteKeyTransactedW(HKEY, LPCWSTR, REGSAM, DWORD, HANDLE, PVOID);
WINADVAPI LONG APIENTRY RegDisableReflectionKey(HKEY);
WINADVAPI LONG APIENTRY RegEnableReflectionKey(HKEY);
WINADVAPI LONG APIENTRY RegQueryReflectionKey(HKEY, BOOL *);
WINADVAPI LSTATUS APIENTRY RegDeleteValueA(HKEY, LPCSTR);
WINADVAPI LSTATUS APIENTRY RegDeleteValueW(HKEY, LPCWSTR);
WINADVAPI LSTATUS APIENTRY RegEnumKeyA(HKEY, DWORD, LPSTR, DWORD);
WINADVAPI LSTATUS APIENTRY RegEnumKeyW(HKEY, DWORD, LPWSTR, DWORD);
WINADVAPI LSTATUS APIENTRY RegEnumKeyExA(HKEY, DWORD, LPSTR, LPDWORD, LPDWORD, LPSTR, LPDWORD, PFILETIME);
WINADVAPI LSTATUS APIENTRY RegEnumKeyExW(HKEY, DWORD, LPWSTR, LPDWORD, LPDWORD, LPWSTR, LPDWORD, PFILETIME);
WINADVAPI LSTATUS APIENTRY RegEnumValueA(HKEY, DWORD, LPSTR, LPDWORD, LPDWORD, LPDWORD, LPBYTE, LPDWORD);
WINADVAPI LSTATUS APIENTRY RegEnumValueW(HKEY, DWORD, LPWSTR, LPDWORD, LPDWORD, LPDWORD, LPBYTE, LPDWORD);
WINADVAPI LSTATUS APIENTRY RegFlushKey(HKEY);
WINADVAPI LSTATUS APIENTRY RegGetKeySecurity(HKEY, SECURITY_INFORMATION, PSECURITY_DESCRIPTOR, LPDWORD);
WINADVAPI LSTATUS APIENTRY RegLoadKeyA(HKEY, LPCSTR, LPCSTR);
WINADVAPI LSTATUS APIENTRY RegLoadKeyW(HKEY, LPCWSTR, LPCWSTR);
WINADVAPI LSTATUS APIENTRY RegNotifyChangeKeyValue(HKEY, BOOL, DWORD, HANDLE, BOOL);
WINADVAPI LSTATUS APIENTRY RegOpenKeyA(HKEY, LPCSTR, PHKEY);
WINADVAPI LSTATUS APIENTRY RegOpenKeyW(HKEY, LPCWSTR, PHKEY);
WINADVAPI LSTATUS APIENTRY RegOpenKeyExA(HKEY, LPCSTR, DWORD, REGSAM, PHKEY);
WINADVAPI LSTATUS APIENTRY RegOpenKeyExW(HKEY, LPCWSTR, DWORD, REGSAM, PHKEY);
WINADVAPI LSTATUS APIENTRY RegOpenKeyTransactedA(HKEY, LPCSTR, DWORD, REGSAM, PHKEY, HANDLE, PVOID);
WINADVAPI LSTATUS APIENTRY RegOpenKeyTransactedW(HKEY, LPCWSTR, DWORD, REGSAM, PHKEY, HANDLE, PVOID);
WINADVAPI LSTATUS APIENTRY RegQueryInfoKeyA(HKEY, LPSTR, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, PFILETIME);
WINADVAPI LSTATUS APIENTRY RegQueryInfoKeyW(HKEY, LPWSTR, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, PFILETIME);
WINADVAPI LSTATUS APIENTRY RegQueryValueA(HKEY, LPCSTR, LPSTR, PLONG);
WINADVAPI LSTATUS APIENTRY RegQueryValueW(HKEY, LPCWSTR, LPWSTR, PLONG);
WINADVAPI LSTATUS APIENTRY RegQueryMultipleValuesA(HKEY, PVALENTA, DWORD, LPSTR, LPDWORD);
WINADVAPI LSTATUS APIENTRY RegQueryMultipleValuesW(HKEY, PVALENTW, DWORD, LPWSTR, LPDWORD);
WINADVAPI LSTATUS APIENTRY RegQueryValueExA(HKEY, LPCSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD);
WINADVAPI LSTATUS APIENTRY RegQueryValueExW(HKEY, LPCWSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD);
WINADVAPI LSTATUS APIENTRY RegReplaceKeyA(HKEY, LPCSTR, LPCSTR, LPCSTR);
WINADVAPI LSTATUS APIENTRY RegReplaceKeyW(HKEY, LPCWSTR, LPCWSTR, LPCWSTR);
WINADVAPI LSTATUS APIENTRY RegRestoreKeyA(HKEY, LPCSTR, DWORD);
WINADVAPI LSTATUS APIENTRY RegRestoreKeyW(HKEY, LPCWSTR, DWORD);

#if (WINVER >= 0x0600)
WINADVAPI LSTATUS APIENTRY RegRenameKey(HKEY, LPCWSTR, LPCWSTR);
#endif /* WINVER >= 0x0600 */

WINADVAPI LSTATUS APIENTRY RegSaveKeyA(HKEY, LPCSTR, CONST LPSECURITY_ATTRIBUTES);
WINADVAPI LSTATUS APIENTRY RegSaveKeyW(HKEY, LPCWSTR, CONST LPSECURITY_ATTRIBUTES);
WINADVAPI LSTATUS APIENTRY RegSetKeySecurity(HKEY, SECURITY_INFORMATION, PSECURITY_DESCRIPTOR);
WINADVAPI LSTATUS APIENTRY RegSetValueA(HKEY, LPCSTR, DWORD, LPCSTR, DWORD);
WINADVAPI LSTATUS APIENTRY RegSetValueW(HKEY, LPCWSTR, DWORD, LPCWSTR, DWORD);
WINADVAPI LSTATUS APIENTRY RegSetValueExA(HKEY, LPCSTR, DWORD, DWORD, CONST BYTE *, DWORD);
WINADVAPI LSTATUS APIENTRY RegSetValueExW(HKEY, LPCWSTR, DWORD, DWORD, CONST BYTE *, DWORD);
WINADVAPI LSTATUS APIENTRY RegUnLoadKeyA(HKEY, LPCSTR);
WINADVAPI LSTATUS APIENTRY RegUnLoadKeyW(HKEY, LPCWSTR);

#ifdef UNICODE
#define RegConnectRegistry  RegConnectRegistryW
#define RegConnectRegistryEx  RegConnectRegistryExW
#define RegCreateKey  RegCreateKeyW
#define RegCreateKeyEx  RegCreateKeyExW
#define RegCreateKeyTransacted  RegCreateKeyTransactedW
#define RegDeleteKey  RegDeleteKeyW
#define RegDeleteKeyEx  RegDeleteKeyExW
#define RegDeleteKeyTransacted  RegDeleteKeyTransactedW
#define RegDeleteValue  RegDeleteValueW
#define RegEnumKey  RegEnumKeyW
#define RegEnumKeyEx  RegEnumKeyExW
#define RegEnumValue  RegEnumValueW
#define RegLoadKey  RegLoadKeyW
#define RegOpenKey  RegOpenKeyW
#define RegOpenKeyEx  RegOpenKeyExW
#define RegOpenKeyTransacted  RegOpenKeyTransactedW
#define RegQueryInfoKey  RegQueryInfoKeyW
#define RegQueryValue  RegQueryValueW
#define RegQueryMultipleValues  RegQueryMultipleValuesW
#define RegQueryValueEx  RegQueryValueExW
#define RegReplaceKey  RegReplaceKeyW
#define RegRestoreKey  RegRestoreKeyW
#define RegSaveKey  RegSaveKeyW
#define RegSetValue  RegSetValueW
#define RegSetValueEx  RegSetValueExW
#define RegUnLoadKey  RegUnLoadKeyW
#else /* !UNICODE */
#define RegConnectRegistry  RegConnectRegistryA
#define RegConnectRegistryEx  RegConnectRegistryExA
#define RegCreateKey  RegCreateKeyA
#define RegCreateKeyEx  RegCreateKeyExA
#define RegCreateKeyTransacted  RegCreateKeyTransactedA
#define RegDeleteKey  RegDeleteKeyA
#define RegDeleteKeyEx  RegDeleteKeyExA
#define RegDeleteKeyTransacted  RegDeleteKeyTransactedA
#define RegDeleteValue  RegDeleteValueA
#define RegEnumKey  RegEnumKeyA
#define RegEnumKeyEx  RegEnumKeyExA
#define RegEnumValue  RegEnumValueA
#define RegLoadKey  RegLoadKeyA
#define RegOpenKey  RegOpenKeyA
#define RegOpenKeyEx  RegOpenKeyExA
#define RegOpenKeyTransacted  RegOpenKeyTransactedA
#define RegQueryInfoKey  RegQueryInfoKeyA
#define RegQueryValue  RegQueryValueA
#define RegQueryMultipleValues  RegQueryMultipleValuesA
#define RegQueryValueEx  RegQueryValueExA
#define RegReplaceKey  RegReplaceKeyA
#define RegRestoreKey  RegRestoreKeyA
#define RegSaveKey  RegSaveKeyA
#define RegSetValue  RegSetValueA
#define RegSetValueEx  RegSetValueExA
#define RegUnLoadKey  RegUnLoadKeyA
#endif /* !UNICODE */

#if _WIN32_WINNT >= 0x0600

WINADVAPI LSTATUS APIENTRY RegDeleteKeyValueA(HKEY, LPCSTR, LPCSTR);
WINADVAPI LSTATUS APIENTRY RegDeleteKeyValueW(HKEY, LPCWSTR, LPCWSTR);
WINADVAPI LSTATUS APIENTRY RegSetKeyValueA(HKEY, LPCSTR, LPCSTR, DWORD, LPCVOID, DWORD);
WINADVAPI LSTATUS APIENTRY RegSetKeyValueW(HKEY, LPCWSTR, LPCWSTR, DWORD, LPCVOID, DWORD);
WINADVAPI LSTATUS APIENTRY RegDeleteTreeA(HKEY, LPCSTR);
WINADVAPI LSTATUS APIENTRY RegDeleteTreeW(HKEY, LPCWSTR);
WINADVAPI LSTATUS APIENTRY RegCopyTreeA(HKEY, LPCSTR, HKEY);

#ifdef UNICODE
#define RegDeleteKeyValue  RegDeleteKeyValueW
#define RegSetKeyValue  RegSetKeyValueW
#define RegDeleteTree  RegDeleteTreeW
#else /* !UNICODE */
#define RegDeleteKeyValue  RegDeleteKeyValueA
#define RegSetKeyValue  RegSetKeyValueA
#define RegDeleteTree  RegDeleteTreeA
#define RegCopyTree  RegCopyTreeA
#endif /* !UNICODE */

#endif /* _WIN32_WINNT >= 0x0600 */

#if (_WIN32_WINNT >= 0x0502)

WINADVAPI LSTATUS APIENTRY RegGetValueA(HKEY, LPCSTR, LPCSTR, DWORD, LPDWORD, PVOID, LPDWORD);
WINADVAPI LSTATUS APIENTRY RegGetValueW(HKEY, LPCWSTR, LPCWSTR, DWORD, LPDWORD, PVOID, LPDWORD);

#ifdef UNICODE
#define RegGetValue  RegGetValueW
#else /* !UNICODE */
#define RegGetValue  RegGetValueA
#endif /* !UNICODE */

#endif /* _WIN32_WINNT >= 0x0502 */

#if (_WIN32_WINNT >= 0x0600)

WINADVAPI LSTATUS APIENTRY RegCopyTreeW(HKEY, LPCWSTR, HKEY);
WINADVAPI LSTATUS APIENTRY RegLoadMUIStringA(HKEY, LPCSTR, LPSTR, DWORD, LPDWORD, DWORD, LPCSTR);
WINADVAPI LSTATUS APIENTRY RegLoadMUIStringW(HKEY, LPCWSTR, LPWSTR, DWORD, LPDWORD, DWORD, LPCWSTR);
WINADVAPI LSTATUS APIENTRY RegLoadAppKeyA(LPCSTR, PHKEY, REGSAM, DWORD, DWORD);
WINADVAPI LSTATUS APIENTRY RegLoadAppKeyW(LPCWSTR, PHKEY, REGSAM, DWORD, DWORD);

#ifdef UNICODE
#define RegCopyTree  RegCopyTreeW
#define RegLoadMUIString  RegLoadMUIStringW
#define RegLoadAppKey  RegLoadAppKeyW
#else
#define RegLoadMUIString  RegLoadMUIStringA
#define RegLoadAppKey  RegLoadAppKeyA
#endif

#endif /* _WIN32_WINNT >= 0x0600 */

WINADVAPI BOOL APIENTRY InitiateSystemShutdownA(LPSTR, LPSTR, DWORD, BOOL, BOOL);
WINADVAPI BOOL APIENTRY InitiateSystemShutdownW(LPWSTR, LPWSTR, DWORD, BOOL, BOOL);
WINADVAPI BOOL APIENTRY AbortSystemShutdownA(LPSTR);
WINADVAPI BOOL APIENTRY AbortSystemShutdownW(LPWSTR);

#ifdef UNICODE
#define InitiateSystemShutdown  InitiateSystemShutdownW
#define AbortSystemShutdown  AbortSystemShutdownW
#else /* !UNICODE */
#define InitiateSystemShutdown  InitiateSystemShutdownA
#define AbortSystemShutdown  AbortSystemShutdownA
#endif /* !UNICODE */

#include <reason.h>

#define REASON_SWINSTALL  (SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_INSTALLATION)
#define REASON_HWINSTALL  (SHTDN_REASON_MAJOR_HARDWARE|SHTDN_REASON_MINOR_INSTALLATION)
#define REASON_SERVICEHANG  (SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_HUNG)
#define REASON_UNSTABLE  (SHTDN_REASON_MAJOR_SYSTEM|SHTDN_REASON_MINOR_UNSTABLE)
#define REASON_SWHWRECONF  (SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_RECONFIG)
#define REASON_OTHER  (SHTDN_REASON_MAJOR_OTHER|SHTDN_REASON_MINOR_OTHER)
#define REASON_UNKNOWN  SHTDN_REASON_UNKNOWN
#define REASON_LEGACY_API  SHTDN_REASON_LEGACY_API
#define REASON_PLANNED_FLAG  SHTDN_REASON_FLAG_PLANNED

#define MAX_SHUTDOWN_TIMEOUT  (10*365*24*60*60)

WINADVAPI BOOL APIENTRY InitiateSystemShutdownExA(LPSTR, LPSTR, DWORD, BOOL, BOOL, DWORD);
WINADVAPI BOOL APIENTRY InitiateSystemShutdownExW(LPWSTR, LPWSTR, DWORD, BOOL, BOOL, DWORD);

#ifdef UNICODE
#define InitiateSystemShutdownEx  InitiateSystemShutdownExW
#else /* !UNICODE */
#define InitiateSystemShutdownEx  InitiateSystemShutdownExA
#endif /* !UNICODE */

#define SHUTDOWN_FORCE_OTHERS  0x00000001
#define SHUTDOWN_FORCE_SELF  0x00000002
#define SHUTDOWN_RESTART  0x00000004
#define SHUTDOWN_POWEROFF  0x00000008
#define SHUTDOWN_NOREBOOT  0x00000010
#define SHUTDOWN_GRACE_OVERRIDE  0x00000020
#define SHUTDOWN_INSTALL_UPDATES  0x00000040
#define SHUTDOWN_RESTARTAPPS  0x00000080
#define SHUTDOWN_SKIP_SVC_PRESHUTDOWN  0x00000100
#define SHUTDOWN_HYBRID  0x00000200
#define SHUTDOWN_RESTART_BOOTOPTIONS  0x00000400
#define SHUTDOWN_SOFT_REBOOT  0x00000800
#define SHUTDOWN_MOBILE_UI  0x00001000

WINADVAPI DWORD APIENTRY InitiateShutdownA(LPSTR, LPSTR, DWORD, DWORD, DWORD);
WINADVAPI DWORD APIENTRY InitiateShutdownW(LPWSTR, LPWSTR, DWORD, DWORD, DWORD);

#ifdef UNICODE
#define InitiateShutdown  InitiateShutdownW
#else /* !UNICODE */
#define InitiateShutdown  InitiateShutdownA
#endif /* !UNICODE */

WINADVAPI DWORD APIENTRY CheckForHiberboot(PBOOLEAN, BOOLEAN);
WINADVAPI LSTATUS APIENTRY RegSaveKeyExA(HKEY, LPCSTR, CONST LPSECURITY_ATTRIBUTES, DWORD);
WINADVAPI LSTATUS APIENTRY RegSaveKeyExW(HKEY, LPCWSTR, CONST LPSECURITY_ATTRIBUTES, DWORD);

#ifdef UNICODE
#define RegSaveKeyEx  RegSaveKeyExW
#else /* !UNICODE */
#define RegSaveKeyEx  RegSaveKeyExA
#endif /* !UNICODE */

#endif /* _WINREG_H */
