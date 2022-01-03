#ifndef ELSSRVC_H
#define ELSSRVC_H

/* Extended Linguistic Services GUID definitions */

#if __POCC__ >= 500
#pragma once
#endif

#include <windef.h>

/*static*/ const GUID ELS_GUID_LANGUAGE_DETECTION = { 0xCF7E00B1, 0x909B, 0x4D95, {0xA8, 0xF4, 0x61, 0x1F, 0x7C, 0x37, 0x77, 0x02} };
/*static*/ const GUID ELS_GUID_SCRIPT_DETECTION = { 0x2D64B439, 0x6CAF, 0x4F6B, {0xB6, 0x88, 0xE5, 0xD0, 0xF4, 0xFA, 0xA7, 0xD7} };
/*static*/ const GUID ELS_GUID_TRANSLITERATION_HANT_TO_HANS = { 0xA3A8333B, 0xF4FC, 0x42f6, {0xA0, 0xC4, 0x04, 0x62, 0xFE, 0x73, 0x17, 0xCB} };
/*static*/ const GUID ELS_GUID_TRANSLITERATION_HANS_TO_HANT = { 0x3CACCDC8, 0x5590, 0x42dc, {0x9A, 0x7B, 0xB5, 0xA6, 0xB5, 0xB3, 0xB6, 0x3B} };
/*static*/ const GUID ELS_GUID_TRANSLITERATION_MALAYALAM_TO_LATIN = { 0xD8B983B1, 0xF8BF, 0x4a2b, {0xBC, 0xD5, 0x5B, 0x5E, 0xA2, 0x06, 0x13, 0xE1} };
/*static*/ const GUID ELS_GUID_TRANSLITERATION_DEVANAGARI_TO_LATIN = { 0xC4A4DCFE, 0x2661, 0x4d02, {0x98, 0x35, 0xF4, 0x81, 0x87, 0x10, 0x98, 0x03} };
/*static*/ const GUID ELS_GUID_TRANSLITERATION_CYRILLIC_TO_LATIN = { 0x3DD12A98, 0x5AFD, 0x4903, {0xA1, 0x3F, 0xE1, 0x7E, 0x6C, 0x0B, 0xFE, 0x01} };
/*static*/ const GUID ELS_GUID_TRANSLITERATION_BENGALI_TO_LATIN = { 0xF4DFD825, 0x91A4, 0x489f, {0x85, 0x5E, 0x9A, 0xD9, 0xBE, 0xE5, 0x57, 0x27} };
/*static*/ const GUID ELS_GUID_TRANSLITERATION_HANGUL_DECOMPOSITION = { 0x4BA2A721, 0xE43D, 0x41b7, {0xB3, 0x30, 0x53, 0x6A, 0xE1, 0xE4, 0x88, 0x63} };

#endif /* ELSSRVC_H */
