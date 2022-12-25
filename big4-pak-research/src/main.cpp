/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#include <stdio.h>

#include "package/package.h"
#include "utils/utils.h"

int main(int argc, const char* aArgv[])
{
	if (argc > 1)
	{
		Package* pPackage = new Package(aArgv[1]);
		if (pPackage)
		{
			if (pPackage->PackageLogin())
			{
				puts(">>> Further data processing goes here");
			}
			delete pPackage;
		}
		else
		{
			MsgErr("Failed to allocate package class\n");
		}
	}
	else
	{
		puts("Usage: main.exe <name>.pak");
	}
}