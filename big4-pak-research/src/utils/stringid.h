/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#pragma once

#include <cinttypes>

extern std::uint32_t g_crc32Table[];

typedef std::uint32_t StringId;

const StringId StringIdHashConcat(std::uint32_t base, const char* str);

const StringId StringIdHash(const char* str);

// macros & constants
//-----------------------------------------------------------------------------
#define SID(str) (StringIdHash(str))
//-----------------------------------------------------------------------------
// end: macros & constant

