/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/

#include "../utils/sidbase/sidbase.h"
#include "spawner-group.h"
#include <stdio.h>
#include <stdint.h>

extern uintptr_t g_fileBase;

void EntitySpawnerGroup::DumpInfo(uint8_t* pMem)
{
	SpawnerGroup* pSpawnerGroup = reinterpret_cast<SpawnerGroup*>(pMem);
	int64_t numSpawners = pSpawnerGroup->m_numSpawners;
	if (numSpawners)
	{
		InitSidbase();
		int64_t iSpawner;
		for (iSpawner = 0; iSpawner < numSpawners; iSpawner++)
		{
			EntitySpawner* pSpawner = pSpawnerGroup->m_apEntitySpawners[iSpawner];
			
			printf("\nEntitySpawner \"%s\":\n", pSpawner->m_spawnerName);
			printf("  Process Type: '%s\n", StringIdToStringInternal(pSpawner->m_processType));
			printf("  Art Group: \"%s\"\n", pSpawner->m_artGroup);
			const char* parentSpawner = "(none)";
			if (pSpawner->m_pParentSpawner)
			{
				parentSpawner = pSpawner->m_pParentSpawner->m_spawnerName;
			}
			printf("  Parent Spawner: \"%s\"\n", parentSpawner);
			printf("  Local Pos/Quat: (%4.2f, %4.2f, %4.2f) / (%4.2f, %4.2f, %4.2f, %4.2f) //value @ %.08llX\n",
				pSpawner->m_posX,
				pSpawner->m_posY,
				pSpawner->m_posZ,
				pSpawner->m_rotX,
				pSpawner->m_rotY,
				pSpawner->m_rotZ,
				pSpawner->m_rotW,
				(reinterpret_cast<uintptr_t>(pSpawner) - g_fileBase)
			);
			puts("  Flags: ");
			if ((pSpawner->m_spawnerFlags & 0x2) != 0)
			{
				puts("noAutoBirth ");
			}
			puts("");
			puts("  Schema Properties:\n");
			if (pSpawner->m_pSchemaProperty)
			{
				int64_t propertyCount = pSpawner->m_pSchemaProperty->m_numProperties;
				Property* pPropertyTable = pSpawner->m_pSchemaProperty->m_pPropertyTable;
				if (propertyCount != 0)
				{
					int64_t iProperty;
					for (iProperty = 0; iProperty < propertyCount; iProperty++)
					{
						
						printf("    '%s: ", StringIdToStringInternal(pPropertyTable->m_id));
						PropertyValue* pVal = pPropertyTable->m_pVal;
						switch (pVal->m_typeId)
						{
							case 1:
							{
								int32_t value = 0;
								if (pVal->m_pValue)
								{
									value = *reinterpret_cast<int32_t*>(pVal->m_pValue);
								}
								printf("%d //value @ %.08llX\n", value, (reinterpret_cast<uintptr_t>(pVal->m_pValue) - g_fileBase));
								break;
							}
							case 0x4:
							{
								float value = 0;
								if (pVal->m_pValue)
								{
									value = *reinterpret_cast<float*>(pVal->m_pValue);
								}
								printf("%f //value @ %.08llX\n", value, (reinterpret_cast<uintptr_t>(pVal->m_pValue) - g_fileBase));
								break;
							}

							case 5:
							{
								if (pVal->m_pValue)
								{
									printf("%s //value @ %.08llX\n", *reinterpret_cast<const char**>(pVal->m_pValue), (reinterpret_cast<uintptr_t>(pVal->m_pValue) - g_fileBase));
								}
								else
								{
									puts("(null)");
								}
								break;
							}

							case 7:
							case 8:
							case 9:
							{
								float x = 0;
								float y = 0;
								float z = 0;
								if (pVal->m_pValue)
								{
									float* value = reinterpret_cast<float*>(pVal->m_pValue);
									x = value[0];
									y = value[1];
									z = value[2];
								}
								printf("(%4.2f, %4.2f, %4.2f) //value @ %.08llX\n", x, y, z, (reinterpret_cast<uintptr_t>(pVal->m_pValue) - g_fileBase) );
								break;
							}

							case 13:
							{
								StringId value = 0;
								if (pVal->m_pValue)
								{
									value = *reinterpret_cast<StringId*>(pVal->m_pValue);
								}
								printf("%s //value @ %.08llX\n", StringIdToStringInternal(value), (reinterpret_cast<uintptr_t>(pVal->m_pValue) - g_fileBase));
								break;
							}

							default:
							{
								printf("(%d) unsupported print type\n", pVal->m_typeId);
								break;
							}
						}
						pPropertyTable++;
					}
				}
			}
		}
		ShutdownSidbase();
	}
}
