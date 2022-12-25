#include "geometry.h"
#include <stdio.h>

void Geometry1::DumpInfo(uint8_t* pMem)
{
	GeometryDesc* pGeo = reinterpret_cast<GeometryDesc*>(pMem);
	if (pGeo)
	{
		if (pGeo->m_version == 0x1E)
		{
			int32_t numSubMeshDesc = pGeo->m_numSubMeshDesc;
			if (numSubMeshDesc)
			{
				for (int32_t iSubMeshDesc = 0; iSubMeshDesc < numSubMeshDesc; iSubMeshDesc++)
				{
					SubMeshDesc* pSubMeshDesc = &pGeo->m_pSubMeshDescTable[iSubMeshDesc];
					printf("name: %s\n", pSubMeshDesc->m_name);
				}
			}
		}
	}
}
