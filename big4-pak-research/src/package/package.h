/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#pragma once

#include "../loading-heap/loadingheap.h"
#include "package-def.h"

#include <cinttypes>

enum class PackageStatus : uint32_t
{
	kPackageStatusEmpty = 0x0,
	kPackageStatusInvalid = 0x1,
	kPackageStatusWanted = 0x2,
	kPackageStatusDoesFileExists = 0x3,
	kPackageStatusOpenFile = 0x4,
	kPackageStatusLoadingEffectOverride = 0x5,
	kPackageStatusLoadingPakHeader = 0x6,
	kPackageStatusLoadingHeader = 0x7,
	kPackageStatusLoadingPages = 0x8,
	kPackageStatusLoadingVram = 0x9,
	kPackageStatusDataIsLoaded = 0xA,
	kPackageStatusDoingLogin = 0xB,
	kPackageStatusLoaded = 0xC,
	kPackageStatusStalledByReplay = 0xD,
	kPackageStatusDoingLogout = 0xE,
	kPackageStatusWaitingForUnload = 0xF,
	kPackageStatusCount = 0x10,
};

class Package
{

public:
	Package(const char* pakName);
	~Package();
	int PackageLogin();

	void FixPointers();

	const int kMaxPakFileNameLength = 128;

	PackageStatus			m_status;
	char					m_realFileName[128];
	void*					m_pLoadedFile;
	size_t					m_fileSize;
	PakHeader				m_hdr;
	uint32_t				m_pageHdrs[LoadingHeap::kMaxPages];
	int						m_currentPageIdx;
	size_t					m_textureBaseOffset;
};

bool Login(ResItem* pResItem, ResPage* pResPage, Package* pPackage);