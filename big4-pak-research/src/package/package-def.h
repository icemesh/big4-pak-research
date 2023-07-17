/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#pragma once

#include <stdint.h>

struct PakHeader //size 0x2C
{
	uint32_t m_magic;					//0x0 0x00000A79
	uint32_t m_hdrSize;					//0x4 header size
	uint32_t m_pakLoginTableIdx;		//0x8 idx of the page storing the PakLoginTable
	uint32_t m_pakLoginTableOffset;		//0xC relative offset PakLoginTable = PakPageHeader + m_pakLoginTableOffset; //its a ResItem 
	uint32_t m_pageCt;					//0x10 page count. Total number of pages in the package
	uint32_t m_pPakPageEntryTable;		//0x14 ptr to the PakPageEntry array/table
	uint32_t m_numPointerFixUpPages;	//0x18 always 0x8
	uint32_t m_pointerFixUpTableOffset; //0x1C ptr to the PointerFixUpTable table
	uint32_t m_dataSize;				//0x20 size of the data from the end of the last page to the EOF
	uint32_t m_vramDescTablePageIdx;	//0x24 page idx where the VramDescTable is stored
	uint32_t m_vramDescTableOffset;		//0x28 m_pageHdrs[m_vramDescTablePageIdx] + m_vramDescTableOffset = ResItem
};
//ok
struct PakPageEntry //0xC 
{
	uint32_t m_resPageOffset;						//0x0 absolute offset to the ResPage
	uint32_t m_pageSize;							//0x4 page size
	uint32_t m_owningPackageIndex;					//0x8 
};

struct ResPage //0x14
{
	uint64_t m_unused;								//0x0	0xDEADBEEFDEADBEEF
	uint32_t m_unk;									//0x8	always 0 ?
	uint32_t m_pageSize;							//0xC	size maybe from the start of PakPageHeader
	uint16_t m_unk2;								//0x10
	uint16_t m_numPageHeaderEntries;				//0x12	number of pointers in the table
};

struct ResPageEntry //0x10 
{
	uint64_t m_name;								//0x0 same as the ResItem name... This field is usually used by animations
	uint32_t m_resItemOffset;						//0x8 relative offset. -> ResItem = PakPageHeader + m_pakLoginItemOffset
	uint32_t m_padding;								//0xC always 00 01 23 45
};

struct ResItem //0x20 
{
	uint64_t m_itemNameOffset;						//0x0 item name. relative offset PakPageHeader + m_itemNameOffset;
	uint64_t m_itemTypeOffset;						//0x8 item type name. relative offset PakPageHeader + m_itemTypeOffset; PM_COLLECTION_2 || RAW_DATA etc
	uint32_t m_unkNumber;							//0x10 no idea what this is used for seems to vary from entry to entry
	uint32_t m_unused;								//0x14 always 00 01 23 45 
	uint32_t m_unused2;								//0x18 always 00 01 23 45 NOTE: this might be used by the JOINT_HIERARCHY || ANIM
	uint32_t m_unused3;								//0x1C always 00 01 23 45 NOTE: this might be used by the JOINT_HIERARCHY || ANIM
};

struct PointerFixUpPage //0xC
{
	uint32_t m_pageEntryNumber;						// 0x0 0, 1, 2 ...
	uint32_t m_dataOffset;							// 0x4 ptr to the table
	uint32_t m_numLoginPageEntries;					// 0x8 number of login pages entries
};

struct PointerFixUpPageEntry //0x8
{
	uint16_t m_page1Idx;							// 0x0 idx in the page table
	uint16_t m_page2Idx;							// 0x2 idx in the page table
	uint32_t m_offset;								// 0x4 offset
};

struct PakLoginTableEntry //0x8
{
	uint32_t m_wantedPage;							// 0x0 page idx in the table
	uint32_t m_resItemOffset;						// 0x4 offset of the res item
};