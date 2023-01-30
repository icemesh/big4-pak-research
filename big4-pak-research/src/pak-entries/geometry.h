/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#pragma once

#include <cinttypes>

namespace Geometry1
{
	struct SubMeshDesc;
	struct MaterialInstanceDesc;
	struct StreamDesc;

	struct GeometryDesc
	{
		uint32_t					m_version;				///< <c>0x00</c>: always 0x1E ?
		uint32_t					m_isForeground;			///< <c>0x04</c>: se to 1 if its an actor
		int32_t						m_numSubMeshDesc;		///< <c>0x08</c>:
		uint32_t					m_numCollections;		///< <c>0x0C</c>:
		uint32_t					m_numMaterials;			///< <c>0x10</c>:
		uint32_t					m_field14;				///< <c>0x14</c>:
		uint32_t					m_numShaders;			///< <c>0x18</c>:
		uint32_t					m_unk6;					///< <c>0x1C</c>:
		uint32_t					m_unk7;					///< <c>0x20</c>:
		uint32_t					m_unk8;					///< <c>0x24</c>:
		SubMeshDesc*				m_pSubMeshDescTable;	///< <c>0x28</c>:
		void*						m_paCollection;			///< <c>0x30</c>: PrototypeDesc
		void*						field_38;				///< <c>0x38</c>:
		void*						field_40_elemSize_0x28;	///< <c>0x40</c>:
		MaterialInstanceDesc*		m_aMaterialInstanceDesc;///< <c>0x48</c>:
		void*						m_unkPtr5;				///< <c>0x50</c>:
		void*						m_unkPtr6;				///< <c>0x58</c>:
		void*						m_unkPtr7;				///< <c>0x60</c>:
	};
	//ps4 vers
	struct SubMeshDesc//0xB0; 
	{
		uint32_t		field_0;
		uint32_t		field_4;
		const char*		m_name;
		uint32_t		field_10;
		uint32_t		field_14;
		uint32_t		field_18;
		uint32_t		field_1C;
		uint32_t		field_20;
		int32_t			m_numVertexes;
		int32_t			m_numIndexes;
		uint32_t		m_numStreamSource;
		int32_t			m_numDefaultStreams;
		uint32_t		field_34;
		StreamDesc*		m_pStreamDesc;
		uint32_t		field_40;
		uint32_t		field_44;
		uint16_t*		m_pIndexes;
		//uint32_t		field_50;
		//uint32_t		field_54;
		void*			m_unkPtr;//material related
		int32_t			m_numMaterialInstances;
		uint32_t		field_5C;
		uint32_t		field_60;
		uint32_t		field_64;
		//uint32_t		field_68;
		//uint32_t		field_6C;
		void*			m_unkPtr2; //texture related
		uint32_t		field_70;
		uint32_t		field_74;
		uint32_t		field_78;
		uint32_t		field_7C;
		uint32_t		field_80;
		uint32_t		field_84;
		uint32_t		field_88;
		uint32_t		field_8C;
		uint32_t		field_90;
		uint32_t		field_94;
		//uint32_t		field_98;
		//uint32_t		field_9C;
		const char*		m_unkPtr3; 
		uint32_t		field_A0;
		uint32_t		field_A4;
		//uint32_t		field_A8;
		//uint32_t		field_AC;
		const char*		m_unkPtr4;
	};

	//probably has more data...
	struct FloatDesc
	{
		uint8_t m_unk;
		uint8_t m_unk2;
		uint8_t m_unk3;
		uint8_t m_floatType; // 34 half || 6 
	};

	//0x18
	struct StreamSource
	{
		FloatDesc*	m_unkPtr;
		void*		m_pData; 
		uint64_t	m_unkData;
	};

	//0x8 ? 
	struct StreamDesc
	{
		uint8_t m_numAttributes;
		uint8_t m_unk;
		uint16_t m_stride;
		uint8_t m_unk2;
		uint8_t m_unk3;
		uint16_t m_unk4;
		StreamSource m_aStreamSources[];
	};



	struct MaterialInstanceDesc//0xD0
	{
		const char* m_materialDebugName;
		const char* m_materialFile;
		const char** m_paUnknames;
		const char* m_materialHash;
		void* m_unkPtr; //elemSize_0x18
		void* m_unkPtr2; //elemSize_0x28
		void* m_unkPtr3; //elemSize_0x20
		uint32_t field_38;
		uint32_t field_3C;
		uint32_t field_40;
		uint32_t m_numCbufferInfo;
		uint32_t m_unk;
		uint32_t m_surfaceType; //StringId of the surface type eg: SID("stone-rough")
		uint64_t m_imLazy[0x10];
	};

	void DumpInfo(uint8_t* pMem);
}