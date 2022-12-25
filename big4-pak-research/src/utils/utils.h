/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#pragma once

#include <cinttypes>

void MsgErr(const char* fmt, ...);

void MsgWarn(const char* fmt, ...);

static inline std::uint64_t ReadU64(std::uint64_t value)
{
#ifdef WIN32
	return ((value & 0x00000000000000FF) << 56)
		| ((value & 0x000000000000FF00) << 40)
		| ((value & 0x0000000000FF0000) << 24)
		| ((value & 0x00000000FF000000) << 8)
		| ((value & 0x000000FF00000000) >> 8)
		| ((value & 0x0000FF0000000000) >> 24)
		| ((value & 0x00FF000000000000) >> 40)
		| ((value & 0xFF00000000000000) >> 56);
#else
	return value;
#endif
}
