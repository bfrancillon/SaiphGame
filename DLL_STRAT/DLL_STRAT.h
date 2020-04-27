// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the DLLSTRAT_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// DLLSTRAT_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DLLSTRAT_EXPORTS
#define DLLSTRAT_API  __declspec(dllexport)
#else
#define DLLSTRAT_API __declspec(dllimport)
#endif

#include "IDeflectionStrategy.h"


class Strategy : public IDeflectionStrategy {
public:

	Strategy();
	void Deflect(float& bulletHeading);
	void Destroy();

};

extern "C" DLLSTRAT_API IDeflectionStrategy * CreateStrategy();