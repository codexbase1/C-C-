#ifndef _ACTIVEDS_H
#define _ACTIVEDS_H

#if __POCC__ >= 500
#pragma once
#endif

/* Active Directory Service master include file */

#include "iads.h"
#include "adshlp.h"
#include "adserr.h"
#include "adsiid.h"
#include "adssts.h"
#include "adsnms.h"
#include "adsdb.h"

#if defined(WIN32_DEFAULT_LIBS)
#pragma comment(lib, "activeds.lib")
#endif

#endif /* _ACTIVEDS_H */
