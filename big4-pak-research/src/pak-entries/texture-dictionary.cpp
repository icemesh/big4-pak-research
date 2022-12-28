/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#include "texture-dictionary.h"
#include "../package/package.h"
#include <stdio.h>

void TextureDictionary::DumpInfo(uint8_t* pMem, Package* pPackage)
{
	TextureDictionary* pTexDict = reinterpret_cast<TextureDictionary*>(pMem);
	if (pTexDict)
	{
		if (pTexDict->m_numTextureEntries)
		{
			//kMaxTextureEntries = 0x61A8 in big1-ps4
			int32_t maxTex = pTexDict->m_numTextureEntries;
			for (int32_t iTex = 0; iTex < maxTex; iTex++)
			{
				PakVramItem* pTextureItem = pTexDict->m_paPakVramItems[iTex];
				printf("%s\nUid: 0x%016llX\nWidth: %d\nHeight: %d\nMipCount: %d\nPakOffset: 0x%08X (RealOffset: 0x%08llX)\n",
					pTextureItem->m_pTextureFileName,
					pTextureItem->m_uid,
					pTextureItem->m_width,
					pTextureItem->m_height,
					pTextureItem->m_mipCount,
					pTextureItem->m_pakOffset,
					pPackage->m_textureBaseOffset + pTextureItem->m_pakOffset
				);
				puts("---------------------------------------------");
				
			}	
		}
	}
}
