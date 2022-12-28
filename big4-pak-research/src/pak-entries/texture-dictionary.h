/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#pragma once

#include <cinttypes>

class Package;

namespace TextureDictionary
{
	namespace ndgi
	{
		enum class Format : uint32_t
		{
			kInvalid = 0,
			kR32G32B32A32Float = 2,
			kR32G32B32A32Uint = 3,
			kR32G32B32A32Sint = 4,
			kR32G32B32Float = 6,
			kR32G32B32Uint = 7,
			kR32G32B32Sint = 8,
			kR16G16B16A16Float = 0xA,
			kR16G16B16A16Unorm = 0xB,
			kR16G16B16A16Uint = 0xC,
			kR16G16B16A16Snorm = 0xD,
			kR16G16B16A16Sint = 0xE,
			kR32G32Float = 0x10,
			kR32G32Uint = 0x11,
			kR32G32Sint = 0x12,
			kR32G8X24 = 0x13,
			kD32S8X24 = 0x14,
			kR32X8X24 = 0x15,
			kX32G8X24 = 0x16,
			kR10G10B10A2Unorm = 0x18,
			kR10G10B10A2Uint = 0x19,
			kR11G11B10Float = 0x1A,
			kR8G8B8A8Unorm = 0x1C,
			kR8G8B8A8UnormSrgb = 0x1D,
			kR8G8B8A8Uint = 0x1E,
			kR8G8B8A8Snorm = 0x1F,
			kR8G8B8A8Sint = 0x20,
			kR16G16Float = 0x22,
			kR16G16Unorm = 0x23,
			kR16G16Uint = 0x24,
			kR16G16Snorm = 0x25,
			kR16G16Sint = 0x26,
			kR32Typeless = 0x27,
			kD32Float = 0x28,
			kR32Float = 0x29,
			kR32Uint = 0x2A,
			kR32Sint = 0x2B,
			kR24G8Typeless = 0x2C,
			kD24S8 = 0x2D,
			kR24X8Unorm = 0x2E,
			kX24G8 = 0x2F,
			kR8G8Unorm = 0x31,
			kR8G8Uint = 0x32,
			kR8G8Snorm = 0x33,
			kR8G8Sint = 0x34,
			kR16Typeless = 0x35,
			kR16Float = 0x36,
			kD16Unorm = 0x37,
			kR16Unorm = 0x38,
			kR16Uint = 0x39,
			kR16Snorm = 0x3A,
			kR16Sint = 0x3B,
			kR8Unorm = 0x3D,
			kR8Uint = 0x3E,
			kR8Snorm = 0x3F,
			kR8Sint = 0x40,
			kA8Unorm = 0x41,
			kR1unorm = 0x42,
			kBc1Typeless = 0x46,
			kBc1Unorm = 0x47,
			kBc1UnormSrgb = 0x48,
			kBc2Typeless = 0x49,
			kBc2Unorm = 0x4A,
			kBc2UnormSrgb = 0x4B,
			kBc3Typeless = 0x4C,
			kBc3Unorm = 0x4D,
			kBc3UnormSrgb = 0x4E,
			kBc4Typeless = 0x4F,
			kBc4Unorm = 0x50,
			kBc4Snorm = 0x51,
			kBc5Typeless = 0x52,
			kBc5Unorm = 0x53,
			kBc5Snorm = 0x54,
			kB5G6R5Unorm = 0x55,
			kB5G5R5A1Unorm = 0x56,
			kB8G8R8A8Unorm = 0x57,
			kB8G8R8X8Unorm = 0x58,
			kR10G10B10A2Unorm_2 = 0x59,
			kB8G8R8A8Unorm_2 = 0x5A,
			kB8G8R8A8UnormSrgb = 0x5B,
			kB8G8R8X8Typeless = 0x5C,
			kB8G8R8X8UnormSrgb = 0x5D,
			kBc6Typeless = 0x5E,
			kBc6Uf16 = 0x5F,
			kBc6Sf16 = 0x60,
			kBc7Typeless = 0x61,
			kBc7Unorm = 0x62,
			kBc7UnormSrgb = 0x63,
			kB16G16R16A16Float = 0x64,
			kB10G10R10A2Unorm = 0x65,
			kA16Unorm = 0x66,
			kRa8Unorm = 0x67,
		};
	}

	struct PakVramItem //0x50
	{
		uint32_t		field_0;			///< <c>0x00</c>:
		uint32_t		field_4;			///< <c>0x04</c>:
		uint32_t		m_pakOffset;		///< <c>0x08</c>: offset in the pak
		uint32_t		field_C;			///< <c>0x0C</c>:
		uint32_t		m_vramSize;			///< <c>0x10</c>: texture size
		uint32_t		field_14;			///< <c>0x14</c>:
		uint64_t		m_uid;				///< <c>0x18</c>: StringId ?
		uint32_t		field_20;			///< <c>0x20</c>:
		uint32_t		m_type;				///< <c>0x24</c>:
		ndgi::Format	m_dxFormat;			///< <c>0x28</c>: 
		uint32_t		field_2C;			///< <c>0x2C</c>:
		uint32_t		m_mipCount;			///< <c>0x30</c>: mip count
		uint32_t		m_width;			///< <c>0x34</c>: width
		uint32_t		m_height;			///< <c>0x38</c>: height
		uint32_t		field_3C;			///< <c>0x3C</c>:
		uint32_t		m_streamFlags;		///< <c>0x40</c>:
		uint32_t		field_44;			///< <c>0x44</c>:
		const char*		m_pTextureFileName;	///< <c>0x48</c>: texture name eg:
	};

	struct TextureDictionary
	{
		int32_t			m_numTextureEntries;//0x4
		uint32_t		m_unk;
		uint64_t		m_unkPtr;//0x8
		uint64_t		m_unkPtr2;//0x10
		PakVramItem**	m_paPakVramItems;//0x18
	};

	void DumpInfo(uint8_t* pMem, Package* pPackage);
}