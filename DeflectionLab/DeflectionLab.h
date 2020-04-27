// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the DEFLECTIONLAB_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// DEFLECTIONLAB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DEFLECTIONLAB_EXPORTS
#define DEFLECTIONLAB_API __declspec(dllexport)
#else
#define DEFLECTIONLAB_API __declspec(dllimport)
#endif





#include "IDeflectionStrategy.h"

// This class is exported from the dll
class Strategy : public IDeflectionStrategy {
public:
	Strategy();
	void Deflect(float& bulletHeading);
	void Destroy();
	//DEFLECTIONLAB_API IDeflectionStrategy* CreateStrategy(void);
	
};

extern "C" DEFLECTIONLAB_API IDeflectionStrategy * CreateStrategy();

//DEFLECTIONLAB_API int fnDeflectionLab(void);
