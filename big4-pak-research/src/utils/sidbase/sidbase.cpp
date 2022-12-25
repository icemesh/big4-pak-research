/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#include "sidbase.h"

#include <stdio.h>
#include <stdlib.h>

typedef uint32_t StringId;

struct SidbaseEntry
{
	StringId	m_id;
	uint32_t	m_offset;
};

struct Sidbase
{
	uint8_t*		m_pFile;
	SidbaseEntry*	m_pData;
	char*			m_pStrings;
	uint32_t		m_numEntires;
};

Sidbase g_sidbase;

bool g_bSidbaseAvailable = false;
char g_sidBuffer[0x20];


static inline uint32_t swapU32(uint32_t value)
{
	return ((value & 0x000000FF) << 24)
		| ((value & 0x0000FF00) << 8)
		| ((value & 0x00FF0000) >> 8)
		| ((value & 0xFF000000) >> 24);
}

void InitSidbase()
{
	FILE* fh;
	fopen_s(&fh, "sid1/sidbase.bin", "rb");
	if (fh)
	{
		fseek(fh, 0x0, SEEK_END);
		size_t fsize = ftell(fh);
		fseek(fh, 0x0, SEEK_SET);
		uint8_t* pMem = reinterpret_cast<uint8_t*>(malloc(fsize));
		if (!pMem)
		{
			printf("Failed to allocate 0x%llX bytes for sid db\n", fsize);
		}
		else
		{
			fread(pMem, fsize, 0x1, fh);
			fclose(fh);
			g_sidbase.m_pFile = pMem;
			g_sidbase.m_pData = reinterpret_cast<SidbaseEntry*>(pMem + 0x4);
			uint32_t numEntries = swapU32(*(uint32_t*)pMem);
			g_sidbase.m_numEntires = numEntries;
			g_sidbase.m_pStrings = reinterpret_cast<char*>(pMem + (numEntries << 0x3) + 0x4);
			g_bSidbaseAvailable = true;
		}
	}
	else
	{
		puts("Could not open sid1/sidbase.bin!- Does it even exist ?\n");
	}
}

void ShutdownSidbase()
{
	if (g_sidbase.m_pFile != NULL)
	{
		free(g_sidbase.m_pFile);
	}
}

char* StringIdToStringInternal(uint32_t sid)
{
	if (g_bSidbaseAvailable)
	{
		int32_t nEntries = g_sidbase.m_numEntires;
		SidbaseEntry* pEntry = g_sidbase.m_pData;
		//this can be improved..
		for (int32_t iEntries = 0; iEntries < nEntries; iEntries++)
		{
			StringId id = swapU32(pEntry->m_id);
			if (id == sid)
			{
				return g_sidbase.m_pStrings + swapU32(pEntry->m_offset);
			}
			pEntry++;
		}
	}
	snprintf(g_sidBuffer, 0x20, "#%08X", sid);
	return g_sidBuffer;
}

