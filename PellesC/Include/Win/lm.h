#ifndef _LM_H
#define _LM_H

#if __POCC__ >= 500
#pragma once
#endif

/* Lan Manager definitions */

#include <lmcons.h>
#include <lmerr.h>
#include <lmaccess.h>
#include <lmalert.h>
#include <lmshare.h>
#include <lmmsg.h>
#include <lmremutl.h>
#include <lmrepl.h>
#include <lmserver.h>
#include <lmsvc.h>
#include <lmuse.h>
#include <lmwksta.h>
#include <lmapibuf.h>
#include <lmerrlog.h>
#include <lmconfig.h>
#include <lmstats.h>
#include <lmaudit.h>
#include <lmjoin.h>

#if defined(WIN32_DEFAULT_LIBS)
#pragma comment(lib, "netapi32.lib")
#endif

#endif /* _LM_H */
