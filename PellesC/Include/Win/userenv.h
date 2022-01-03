#ifndef _USERENV_H
#define _USERENV_H

#if __POCC__ >= 500
#pragma once
#endif

/* User Environment API definitions (profiles, environment variables and group policies) */

#include <wbemcli.h>
#include <profinfo.h>

#define USERENVAPI DECLSPEC_IMPORT

#if defined(WIN32_DEFAULT_LIBS)
#pragma comment(lib, "userenv.lib")
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define PI_NOUI  0x00000001
#define PI_APPLYPOLICY  0x00000002

USERENVAPI BOOL WINAPI LoadUserProfileA(HANDLE,LPPROFILEINFOA);
USERENVAPI BOOL WINAPI LoadUserProfileW(HANDLE,LPPROFILEINFOW);
USERENVAPI BOOL WINAPI UnloadUserProfile(HANDLE,HANDLE);
USERENVAPI BOOL WINAPI GetProfilesDirectoryA(LPSTR,LPDWORD);
USERENVAPI BOOL WINAPI GetProfilesDirectoryW(LPWSTR,LPDWORD);
USERENVAPI BOOL WINAPI GetUserProfileDirectoryA(HANDLE,LPSTR,LPDWORD);
USERENVAPI BOOL WINAPI GetUserProfileDirectoryW(HANDLE,LPWSTR,LPDWORD);
USERENVAPI BOOL WINAPI CreateEnvironmentBlock(LPVOID*,HANDLE,BOOL);
USERENVAPI BOOL WINAPI DestroyEnvironmentBlock(LPVOID);

#ifdef UNICODE
#define LoadUserProfile  LoadUserProfileW
#define GetProfilesDirectory  GetProfilesDirectoryW
#define GetUserProfileDirectory  GetUserProfileDirectoryW
#else
#define LoadUserProfile  LoadUserProfileA
#define GetProfilesDirectory  GetProfilesDirectoryA
#define GetUserProfileDirectory  GetUserProfileDirectoryA
#endif /* UNICODE */

#if (WINVER >= 0x0500)

#define PT_TEMPORARY  0x00000001
#define PT_ROAMING  0x00000002
#define PT_MANDATORY  0x00000004

#define RP_FORCE  1

#define GPC_BLOCK_POLICY  0x00000001

#define GPO_FLAG_DISABLE  0x00000001
#define GPO_FLAG_FORCE  0x00000002

#define GPO_LIST_FLAG_MACHINE  0x00000001
#define GPO_LIST_FLAG_SITEONLY  0x00000002

#define GP_DLLNAME  TEXT("DllName")
#define GP_ENABLEASYNCHRONOUSPROCESSING  TEXT("EnableAsynchronousProcessing")
#define GP_MAXNOGPOLISTCHANGESINTERVAL  TEXT("MaxNoGPOListChangesInterval")
#define GP_NOBACKGROUNDPOLICY  TEXT("NoBackgroundPolicy")
#define GP_NOGPOLISTCHANGES  TEXT("NoGPOListChanges")
#define GP_NOMACHINEPOLICY  TEXT("NoMachinePolicy")
#define GP_NOSLOWLINK  TEXT("NoSlowLink")
#define GP_NOTIFYLINKTRANSITION  TEXT("NotifyLinkTransition")
#define GP_NOUSERPOLICY  TEXT("NoUserPolicy")
#define GP_PERUSERLOCALSETTINGS  TEXT("PerUserLocalSettings")
#define GP_PROCESSGROUPPOLICY  TEXT("ProcessGroupPolicy")
#define GP_REQUIRESSUCCESSFULREGISTRY  TEXT("RequiresSuccessfulRegistry")

#define GPO_INFO_FLAG_MACHINE  0x00000001
#define GPO_INFO_FLAG_BACKGROUND  0x00000010
#define GPO_INFO_FLAG_SLOWLINK  0x00000020
#define GPO_INFO_FLAG_VERBOSE  0x00000040
#define GPO_INFO_FLAG_NOCHANGES  0x00000080
#define GPO_INFO_FLAG_LINKTRANSITION  0x00000100

#define GPO_INFO_FLAG_LOGRSOP_TRANSITION  0x00000200

#define GPO_INFO_FLAG_FORCED_REFRESH  0x00000400
#define GPO_INFO_FLAG_SAFEMODE_BOOT  0x00000800
#define GPO_INFO_FLAG_ASYNC_FOREGROUND  0x00001000

#define REGISTRY_EXTENSION_GUID  {0x35378EAC,0x683F,0x11D2,0xA8,0x9A,0x00,0xC0,0x4F,0xBB,0xCF,0xA2}

#define FLAG_NO_GPO_FILTER  0x80000000
#define FLAG_NO_CSE_INVOKE  0x40000000
#define FLAG_ASSUME_SLOW_LINK  0x20000000
#define FLAG_LOOPBACK_MERGE  0x10000000
#define FLAG_LOOPBACK_REPLACE  0x08000000

#define FLAG_ASSUME_USER_WQLFILTER_TRUE  0x04000000
#define FLAG_ASSUME_COMP_WQLFILTER_TRUE  0x02000000
#define FLAG_INTERNAL_MASK  0x01FFFFFF

#define FLAG_NO_USER  0x00000001
#define FLAG_NO_COMPUTER  0x00000002
#define FLAG_FORCE_CREATENAMESPACE  0x00000004

#define RSOP_USER_ACCESS_DENIED  0x00000001
#define RSOP_COMPUTER_ACCESS_DENIED  0x00000002
#define RSOP_TEMPNAMESPACE_EXISTS  0x00000004

typedef enum _GPO_LINK {
    GPLinkUnknown = 0,
    GPLinkMachine,
    GPLinkSite,
    GPLinkDomain,
    GPLinkOrganizationalUnit
} GPO_LINK, *PGPO_LINK;

typedef struct _GROUP_POLICY_OBJECTA {
    DWORD dwOptions;
    DWORD dwVersion;
    LPSTR lpDSPath;
    LPSTR lpFileSysPath;
    LPSTR lpDisplayName;
    CHAR szGPOName[50];
    GPO_LINK GPOLink;
    LPARAM lParam;
    struct _GROUP_POLICY_OBJECTA *pNext;
    struct _GROUP_POLICY_OBJECTA *pPrev;
    LPSTR lpExtensions;
    LPARAM lParam2;
    LPSTR lpLink;
} GROUP_POLICY_OBJECTA, *PGROUP_POLICY_OBJECTA;

typedef struct _GROUP_POLICY_OBJECTW {
    DWORD dwOptions;
    DWORD dwVersion;
    LPWSTR lpDSPath;
    LPWSTR lpFileSysPath;
    LPWSTR lpDisplayName;
    WCHAR szGPOName[50];
    GPO_LINK GPOLink;
    LPARAM lParam;
    struct _GROUP_POLICY_OBJECTW *pNext;
    struct _GROUP_POLICY_OBJECTW *pPrev;
    LPWSTR lpExtensions;
    LPARAM lParam2;
    LPWSTR lpLink;
} GROUP_POLICY_OBJECTW, *PGROUP_POLICY_OBJECTW;

typedef UINT_PTR ASYNCCOMPLETIONHANDLE;

typedef PVOID PRSOPTOKEN;

typedef GUID *REFGPEXTENSIONID;

typedef enum _SETTINGSTATUS {
    RSOPUnspecified = 0,
    RSOPApplied,
    RSOPIgnored,
    RSOPFailed,
    RSOPSubsettingFailed
} SETTINGSTATUS;

typedef struct _POLICYSETTINGSTATUSINFO {
    LPWSTR szKey;
    LPWSTR szEventSource;
    LPWSTR szEventLogName;
    DWORD dwEventID;
    DWORD dwErrorCode;
    SETTINGSTATUS status;
    SYSTEMTIME timeLogged;
} POLICYSETTINGSTATUSINFO, *LPPOLICYSETTINGSTATUSINFO;

USERENVAPI BOOL WINAPI GetProfileType(DWORD*);
USERENVAPI BOOL WINAPI DeleteProfileA(LPCSTR,LPCSTR,LPCSTR);
USERENVAPI BOOL WINAPI DeleteProfileW(LPCWSTR,LPCWSTR,LPCWSTR);
USERENVAPI BOOL WINAPI GetDefaultUserProfileDirectoryA(LPSTR,LPDWORD);
USERENVAPI BOOL WINAPI GetDefaultUserProfileDirectoryW(LPWSTR,LPDWORD);
USERENVAPI BOOL WINAPI GetAllUsersProfileDirectoryA(LPSTR,LPDWORD);
USERENVAPI BOOL WINAPI GetAllUsersProfileDirectoryW(LPWSTR,LPDWORD);
USERENVAPI BOOL WINAPI ExpandEnvironmentStringsForUserA(HANDLE,LPCSTR,LPSTR,DWORD);
USERENVAPI BOOL WINAPI ExpandEnvironmentStringsForUserW(HANDLE,LPCWSTR,LPWSTR,DWORD);
USERENVAPI BOOL WINAPI RefreshPolicy(BOOL);
USERENVAPI BOOL WINAPI RefreshPolicyEx(BOOL,DWORD);
USERENVAPI HANDLE WINAPI EnterCriticalPolicySection(BOOL);
USERENVAPI BOOL WINAPI LeaveCriticalPolicySection(HANDLE);
USERENVAPI BOOL WINAPI RegisterGPNotification(HANDLE,BOOL);
USERENVAPI BOOL WINAPI UnregisterGPNotification(HANDLE);
USERENVAPI BOOL WINAPI GetGPOListA(HANDLE,LPCSTR,LPCSTR,LPCSTR,DWORD,PGROUP_POLICY_OBJECTA*);
USERENVAPI BOOL WINAPI GetGPOListW(HANDLE,LPCWSTR,LPCWSTR,LPCWSTR,DWORD,PGROUP_POLICY_OBJECTW*);
USERENVAPI BOOL WINAPI FreeGPOListA(PGROUP_POLICY_OBJECTA);
USERENVAPI BOOL WINAPI FreeGPOListW(PGROUP_POLICY_OBJECTW);
USERENVAPI DWORD WINAPI GetAppliedGPOListA(DWORD,LPCSTR,PSID,GUID*,PGROUP_POLICY_OBJECTA*);
USERENVAPI DWORD WINAPI GetAppliedGPOListW(DWORD,LPCWSTR,PSID,GUID*,PGROUP_POLICY_OBJECTW*);
USERENVAPI DWORD WINAPI ProcessGroupPolicyCompleted(REFGPEXTENSIONID,ASYNCCOMPLETIONHANDLE,DWORD);
USERENVAPI DWORD WINAPI ProcessGroupPolicyCompletedEx(REFGPEXTENSIONID,ASYNCCOMPLETIONHANDLE,DWORD,HRESULT);
USERENVAPI HRESULT WINAPI RsopAccessCheckByType(PSECURITY_DESCRIPTOR,PSID,PRSOPTOKEN,DWORD,POBJECT_TYPE_LIST,DWORD,PGENERIC_MAPPING,PPRIVILEGE_SET,LPDWORD,LPDWORD,LPBOOL);
USERENVAPI HRESULT WINAPI RsopFileAccessCheck(LPTSTR,PRSOPTOKEN,DWORD,LPDWORD,LPBOOL);
USERENVAPI HRESULT WINAPI RsopSetPolicySettingStatus(DWORD,IWbemServices*,IWbemClassObject*,DWORD,POLICYSETTINGSTATUSINFO*);
USERENVAPI HRESULT WINAPI RsopResetPolicySettingStatus(DWORD,IWbemServices*,IWbemClassObject*);

#ifdef UNICODE
typedef GROUP_POLICY_OBJECTW GROUP_POLICY_OBJECT;
typedef PGROUP_POLICY_OBJECTW PGROUP_POLICY_OBJECT;
#define DeleteProfile  DeleteProfileW
#define GetDefaultUserProfileDirectory  GetDefaultUserProfileDirectoryW
#define GetAllUsersProfileDirectory  GetAllUsersProfileDirectoryW
#define ExpandEnvironmentStringsForUser  ExpandEnvironmentStringsForUserW
#define GetGPOList  GetGPOListW
#define FreeGPOList  FreeGPOListW
#define GetAppliedGPOList  GetAppliedGPOListW
#else
typedef GROUP_POLICY_OBJECTA GROUP_POLICY_OBJECT;
typedef PGROUP_POLICY_OBJECTA PGROUP_POLICY_OBJECT;
#define DeleteProfile  DeleteProfileA
#define GetDefaultUserProfileDirectory  GetDefaultUserProfileDirectoryA
#define GetAllUsersProfileDirectory  GetAllUsersProfileDirectoryA
#define ExpandEnvironmentStringsForUser  ExpandEnvironmentStringsForUserA
#define GetGPOList  GetGPOListA
#define FreeGPOList  FreeGPOListA
#define GetAppliedGPOList  GetAppliedGPOListA
#endif /* UNICODE */

/* after UNICODE: */
typedef struct _RSOP_TARGET {
    WCHAR *pwszAccountName;
    WCHAR *pwszNewSOM;
    SAFEARRAY *psaSecurityGroups;
    PRSOPTOKEN pRsopToken;
    PGROUP_POLICY_OBJECT pGPOList;
    IWbemServices *pWbemServices;
} RSOP_TARGET, *PRSOP_TARGET;

typedef DWORD (*PFNSTATUSMESSAGECALLBACK)(BOOL,LPWSTR);
typedef DWORD (*PFNPROCESSGROUPPOLICY)(DWORD,HANDLE,HKEY,PGROUP_POLICY_OBJECT,PGROUP_POLICY_OBJECT,ASYNCCOMPLETIONHANDLE,BOOL*,PFNSTATUSMESSAGECALLBACK);
typedef DWORD (*PFNPROCESSGROUPPOLICYEX)(DWORD,HANDLE,HKEY,PGROUP_POLICY_OBJECT,PGROUP_POLICY_OBJECT,ASYNCCOMPLETIONHANDLE,BOOL*,PFNSTATUSMESSAGECALLBACK,IWbemServices*,HRESULT*);
typedef DWORD (*PFNGENERATEGROUPPOLICY)(DWORD,BOOL*,WCHAR*,PRSOP_TARGET,PRSOP_TARGET);

#endif /* WINVER >= 0x0500 */

#if (WINVER >= 0x0600)
USERENVAPI HRESULT WINAPI CreateProfile(LPCWSTR,LPCWSTR,LPWSTR,DWORD);
#endif /* WINVER >= 0x0600 */

#ifdef __cplusplus
}
#endif

#endif /* _USERENV_H */
