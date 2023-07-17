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

			int32_t numMaterialInst = pGeo->m_numShaders;
			for(int32_t iMaterialInst = 0; iMaterialInst < numMaterialInst; iMaterialInst++)
			{
				
				MaterialInstanceDesc* pMatDesc = &pGeo->m_aMaterialInstanceDesc[iMaterialInst];
				/*
				printf("MATERIAL %s\n", pMatDesc->m_materialDebugName);
				printf("FILE %s\n", pMatDesc->m_materialFile);
				printf("MATERIAL HASH %s\n", pMatDesc->m_materialHash);
				*/
				uint32_t numShaderFeatures = pMatDesc->m_numShaderFeatures;
				printf("[MatDump]|%s|%s|%s|%d|\n", pMatDesc->m_materialDebugName, pMatDesc->m_materialFile, pMatDesc->m_materialHash, numShaderFeatures);
				for (uint32_t i = 0; i < numShaderFeatures; i++)
				{
					printf("|%d| %s\n", i, pMatDesc->m_apShaderFeatures[i]);
				}
				puts("Shader Variables");
				for (uint32_t iShdrVar = 0; iShdrVar < pMatDesc->m_numShaderVariables; iShdrVar++)
				{
					printf("|%d|: %s\n", iShdrVar, pMatDesc->m_aShaderVariables[iShdrVar].m_variableName);
				}
				puts("Shader Texture");
				ShaderTexture* pShaderTexture = pMatDesc->m_aShaderTextures;
				for (uint32_t iShaderTexture = 0; iShaderTexture < pMatDesc->m_numShaderTextures; iShaderTexture++)
				{
					printf("|%d|: ", iShaderTexture);
					printf("ShaderTextureName: %s\n     TextureName: %s\n     TextureFilePath: %s\n", pShaderTexture->m_shaderTextureName, pShaderTexture->m_textureName, pShaderTexture->m_pShaderTextureDesc->m_textureFilePath);
					pShaderTexture++;
				}
				puts("-----------------");
			}
		}
	}
}
