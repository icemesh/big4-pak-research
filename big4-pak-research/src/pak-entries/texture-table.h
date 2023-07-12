/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#pragma once

#include "texture-dictionary.h" //find another way

//#include <cinttypes>

class Package;

namespace TextureTable
{
	struct PakTextureTable //probably has more data
	{
		uint64_t m_count;					///< <c>0x00</c>:
		void* m_unkPtr;						///< <c>0x08</c>:
		const char** m_apNames;				///< <c>0x10</c>: array of pointers to names 
		TextureDictionary::PakVramItem** m_apPakVramItems;		///< <c>0x18</c>: array of pointers to PakVramItem
	};

	void DumpInfo(uint8_t* pMem, Package* pPackage);
}