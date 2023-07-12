#include "havok-data.h"

void HavokLoadPackfile(HavokBackgroundCollisionData* pHavokBackgroundCollisionData)
{
	if (pHavokBackgroundCollisionData->m_pHavokShapeData)
	{
		hkPackfileHeader* pHdr = pHavokBackgroundCollisionData->m_pHavokShapeData;
		hkPackfileSectionHeader* pSectionHdr = reinterpret_cast<hkPackfileSectionHeader*>(&pHdr[1]);
		for (uint32_t i = 0; i < pHdr->m_numSections; i++)
		{
			pSectionHdr++;
		}
	}
}
