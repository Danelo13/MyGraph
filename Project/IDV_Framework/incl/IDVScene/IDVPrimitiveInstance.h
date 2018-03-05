#ifndef IDV_PRIMITIVE_INSTANCE_H
#define IDV_PRIMITIVE_INSTANCE_H


#include <IDVScene/IDVPrimitive.h>
#include <IDVVideo/IDVBaseDriver.h>

#include <MATRIX4D.h>

class PrimitiveInst {
	public:
		void	CreateInstance(PrimitiveBase *pPrim, MATRIX4D *pVP) {
			pBase = pPrim;
			pViewProj = pVP;
			Visible = true;
		}

		void	TranslateAbsolute(float x, float y, float z);
		void	RotateXAbsolute(float ang);
		void	RotateYAbsolute(float ang);
		void	RotateZAbsolute(float ang);
		void	ScaleAbsolute(float sc);

		void	TranslateRelative(float x, float y, float z);
		void	RotateXRelative(float ang);
		void	RotateYRelative(float ang);
		void	RotateZRelative(float ang);
		void	ScaleRelative(float sc);

		void	SetSignature(unsigned int f);

		void	Update();
		void	Draw();

		void ToogleVisible() { Visible = !Visible; }
		void SetVisible(bool f) { Visible = f; }
		bool Visible;

		MATRIX4D		Position;
		MATRIX4D		Scale;
		MATRIX4D		RotationX;
		MATRIX4D		RotationY;
		MATRIX4D		RotationZ;
		MATRIX4D		Final;

		MATRIX4D		*pViewProj;

		PrimitiveBase	*pBase;
};


#endif
