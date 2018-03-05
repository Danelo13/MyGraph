#ifndef IDV_SCENEPROPS_H
#define IDV_SCENEPROPS_H

#include <MATRIX4D.h>

#include <vector>


struct SceneProps{
	SceneProps() : ActiveCamera(0) , ActiveLights(1), ActiveLightCamera(0), ActiveGaussKernel(0), Exposure(0.3f) , BloomFactor(1.1f) {}




	MATRIX4D			AmbientColor;

	int ActiveCamera;
	int	ActiveLights;
	int ActiveLightCamera;
	int ActiveGaussKernel;
	
	// HDR
	float	Exposure;
	float	BloomFactor;
};

#endif
