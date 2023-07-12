#pragma once

#include <cinttypes>

struct hkPackfileHeader;

struct HavokBackgroundCollisionData //0x68
{
	uint32_t	m_version;///< <c>0x00</c>: 
	uint8_t		field_4;///< <c>0x04</c>:
	uint8_t		field_5;///< <c>0x05</c>:
	uint8_t		field_6;///< <c>0x06</c>:
	uint8_t		field_7;///< <c>0x07</c>:
	uint32_t	field_8;///< <c>0x08</c>: 
	uint32_t	m_havokShapeDataSize;///< <c>0x0C</c>: 
	hkPackfileHeader*	m_pHavokShapeData;///< <c>0x10</c>: hkPackfileHeader
	void*		m_unkPtr;///< <c>0x18</c>: 
	void*		m_pLevel;///< <c>0x20</c>: 
	uint64_t	field_28;///< <c>0x28</c>: 
	void*		m_hkpRigidBody;///< <c>0x30</c>: 
	void*		m_pShape;///< <c>0x38</c>: 
	uint32_t	field_40;///< <c>0x40</c>: 
	uint32_t	field_44;///< <c>0x44</c>: 
	void*		field_48;///< <c>0x48</c>: 
	void*		field_50;///< <c>0x50</c>: 
	void*		field_58;///< <c>0x58</c>: 
	void*		m_pPatPalette;///< <c>0x60</c>: 
};

struct LayoutRules //0x4
{
	uint8_t m_bytesInPointer;
	uint8_t m_littleEndian;
	uint8_t m_reusePaddingOptimization;
	uint8_t m_emptyBaseClassOptimization;
};

struct hkPackfileHeader //0x40
{
	uint32_t m_magic[2];
	int m_userTag;
	int m_fileVersion;
	LayoutRules m_layoutRules;
	int m_numSections;
	int m_contentsSectionIndex;
	int m_contentsSectionOffset;
	int m_contentsClassNameSectionIndex;
	int m_contentsClassNameSectionOffset;
	char m_contentsVersion[16];
	int m_flags;
	uint16_t m_maxpredicate;
	uint16_t m_predicateArraySizePlusPadding;
};

struct hkPackfileSectionHeader //0x30
{
	char m_sectionTag[19];
	char m_nullByte;
	uint32_t m_absoluteDataStart;
	uint32_t m_localFixupsOffset;
	uint32_t m_globalFixupsOffset;
	uint32_t m_virtualFixupsOffset;
	uint32_t m_exportsOffset;
	uint32_t m_importsOffset;
	uint32_t m_endOffset;
};

void HavokLoadPackfile(HavokBackgroundCollisionData* pHavokBackgroundCollisionData);