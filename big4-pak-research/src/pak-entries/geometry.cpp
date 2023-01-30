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
					/*
					StreamDesc* pDesc = pSubMeshDesc->m_pStreamDesc;
					uint32_t numStreamSource = pSubMeshDesc->m_numStreamSource;
					
					StreamSource* pSrc = pDesc->m_aStreamSources;
					
					for (uint32_t iSource = 0; iSource < numStreamSource; iSource++)
					{
						FloatDesc* pDesc = pSrc->m_unkPtr;
						printf("pDec->m_floatType: %d\n", pDesc->m_floatType);
						pSrc++;
					}
					*/
					printf("name: %s\n", pSubMeshDesc->m_name);
				}
			}

			int32_t numMaterialInst = pGeo->m_numShaders;
			for(int32_t iMaterialInst = 0; iMaterialInst < numMaterialInst; iMaterialInst++)
			{
				
				MaterialInstanceDesc* pMatDesc = &pGeo->m_aMaterialInstanceDesc[iMaterialInst];
				/*
				printf("MATERIAL %s\n", pMatDesc->m_materialDebugName);
				printf("FILE %s\n", pMatDesc->m_materialFile);
				printf("MATERIAL HASH %s\n", pMatDesc->m_materialHash);
				*/
				uint32_t cap = pMatDesc->field_38;
				printf("[MatDump]|%s|%s|%s|%d|\n", pMatDesc->m_materialDebugName, pMatDesc->m_materialFile, pMatDesc->m_materialHash, cap);
				for (uint32_t i = 0; i < cap; i++)
				{
					printf("|%d| %s\n", i, pMatDesc->m_paUnknames[i]);
				}
				puts("-----------------");
			}
		}
	}
}
