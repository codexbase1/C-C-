#ifndef _CTYPE_H
#define _CTYPE_H

/* ctype.h - C99 standard header */

#ifndef RC_INVOKED

#if __POCC__ < 900
#error <ctype.h> need POCC version 9.0 or higher
#endif /* __POCC__ < 900 */

#pragma once

#include <crtdef.h>

#ifdef _MSC_EXTENSIONS
/* for compiling with windows.h -- see Microsoft ctype.h */
#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
typedef __WCHAR_TYPE__ wchar_t;
#endif
#endif /* _MSC_EXTENSIONS */

/* classification bit masks */
#define _DIGIT  0x01    /* decimal digit */
#define _HEX    0x02    /* hexadecimal digit */
#define _LOWER  0x04    /* lower case letter */
#define _UPPER  0x08    /* upper case letter */
#define _CNTRL  0x10    /* control character */
#define _WHITE  0x20    /* white space character */
#define _SPACE  0x40    /* space */
#define _PUNCT  0x80    /* punctuation character */
#define _BLANK  0x100   /* blank (tab) */

/* data declarations */
#ifndef __MT__
extern const unsigned short *__ctypetab;
extern const short *__tolowertab;
extern const short *__touppertab;
#endif /* !__MT__ */

/* declarations */
extern int __cdecl isalnum(int);
extern int __cdecl isalpha(int);
extern int __cdecl iscntrl(int);
extern int __cdecl isdigit(int);
extern int __cdecl isgraph(int);
extern int __cdecl islower(int);
extern int __cdecl isprint(int);
extern int __cdecl ispunct(int);
extern int __cdecl isspace(int);
extern int __cdecl isblank(int);
extern int __cdecl isupper(int);
extern int __cdecl isxdigit(int);
extern int __cdecl _isascii(int);
extern int __cdecl tolower(int);
extern int __cdecl toupper(int);
extern int __cdecl _toascii(int);

/* macro overrides */
#ifndef __MT__
#define isalnum(c)  (__ctypetab[(int)(c)] & (_DIGIT|_LOWER|_UPPER))
#define isalpha(c)  (__ctypetab[(int)(c)] & (_LOWER|_UPPER))
#define iscntrl(c)  (__ctypetab[(int)(c)] & _CNTRL)
#define isdigit(c)  (__ctypetab[(int)(c)] & _DIGIT)
#define isgraph(c)  (__ctypetab[(int)(c)] & (_DIGIT|_LOWER|_UPPER|_PUNCT))
#define islower(c)  (__ctypetab[(int)(c)] & _LOWER)
#define isprint(c)  (__ctypetab[(int)(c)] & (_DIGIT|_LOWER|_UPPER|_PUNCT|_SPACE))
#define ispunct(c)  (__ctypetab[(int)(c)] & _PUNCT)
#define isspace(c)  (__ctypetab[(int)(c)] & (_SPACE|_WHITE))
#define isblank(c)  (__ctypetab[(int)(c)] & (_SPACE|_BLANK))
#define isupper(c)  (__ctypetab[(int)(c)] & _UPPER)
#define isxdigit(c)  (__ctypetab[(int)(c)] & _HEX)
#define tolower(c)  __tolowertab[(int)(c)]
#define toupper(c)  __touppertab[(int)(c)]
#define _isascii(c)  ((int)(c) < 0x80)
#define _toascii(c)  ((int)(c) & 0x7F)
#endif /* !__MT__ */

#ifdef __POCC__OLDNAMES
extern int __cdecl isascii(int);
extern int __cdecl toascii(int);
#define isascii(c)  ((int)(c) < 0x80)
#define toascii(c)  ((int)(c) & 0x7F)
#endif /* __POCC__OLDNAMES */

#endif /* !RC_INVOKED */

#endif /* _CTYPE_H */
