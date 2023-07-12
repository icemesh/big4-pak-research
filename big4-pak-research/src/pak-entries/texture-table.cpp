#include "texture-table.h"
//#include "texture-dictionary.h"
#include "../package/package.h"
#include <stdio.h>

void TextureTable::DumpInfo(uint8_t* pMem, Package* pPackage)
{
	PakTextureTable* pTable = reinterpret_cast<PakTextureTable*>(pMem);
	if (pTable)
	{
		uint64_t maxCount = pTable->m_count;
		TextureDictionary::PakVramItem** ppArray = pTable->m_apPakVramItems;
		for (uint64_t iPakItem = 0; iPakItem < maxCount; iPakItem++)
		{
			TextureDictionary::PakVramItem* pItem = ppArray[iPakItem];
			printf("name: %s\n0x%016llX\n", pItem->m_pTextureFileName, pItem->m_pakOffset+ pPackage->m_textureBaseOffset);
		}
	}
}
