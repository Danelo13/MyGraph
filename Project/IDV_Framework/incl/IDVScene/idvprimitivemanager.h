#ifndef IDV_PRIMITIVEMANAGER_H
#define IDV_PRIMITIVEMANAGER_H

#include <MATRIX4D.h>

#include <vector>

#include <IDVVideo/IDVBaseDriver.h>
#include <IDVScene/IDVPrimitive.h>
#include <IDVScene/IDVSceneProp.h>

class PrimitiveManager {
public:
	PrimitiveManager(IDVAPI Selected) { SelectedApi = Selected;  }
	void SetVP(MATRIX4D *vp) {
		pVP = vp;
	}
	int  CreateQuad();
	int  CreateMesh();
	void SetSceneProps(SceneProps *p);

	void DrawPrimitives();
	void DestroyPrimitives();
	PrimitiveBase*	GetPrimitive(unsigned int);

	std::vector<PrimitiveBase*> primitives;

	IDVAPI		SelectedApi;
	MATRIX4D *pVP;
};

#endif
