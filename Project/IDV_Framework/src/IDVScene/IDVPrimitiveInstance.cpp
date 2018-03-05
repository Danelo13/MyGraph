#include <IDVScene/IDVPrimitiveInstance.h>

void PrimitiveInst::TranslateAbsolute(float x, float y, float z){
	Position = mTranslation(x, y, z);
}

void PrimitiveInst::RotateXAbsolute(float ang) {
	RotationX= mRotationX(ang);
}

void PrimitiveInst::RotateYAbsolute(float ang) {
	RotationY= mRotationY(ang);
}

void PrimitiveInst::RotateZAbsolute(float ang) {
	RotationZ= mRotationZ(ang);
}

void PrimitiveInst::ScaleAbsolute(float sc) {
	Scale= mScaling(sc,sc,sc);
}

void PrimitiveInst::TranslateRelative(float x, float y, float z) {
	MATRIX4D tmp;
	tmp = mTranslation(x, y, z);
	Position = Position * tmp;
}

void PrimitiveInst::RotateXRelative(float ang) {
	MATRIX4D tmp; 
	tmp = mRotationX(ang);
	RotationX = RotationX * tmp;
}

void PrimitiveInst::RotateYRelative(float ang) {
	MATRIX4D tmp;
	tmp = mRotationX(ang);
	RotationY = RotationY * tmp;
}

void PrimitiveInst::RotateZRelative(float ang) {
	MATRIX4D tmp;
	tmp = mRotationZ(ang);
	RotationZ = RotationZ * tmp;
}

void PrimitiveInst::ScaleRelative(float sc) {
	MATRIX4D tmp;
	tmp = mScaling(sc, sc, sc);
	Scale = Scale * tmp;
}

void PrimitiveInst::Update() {
	Final = Scale*RotationX*RotationY*RotationZ*Position;
}

void PrimitiveInst::Draw(){
	if (!Visible)
		return;
	pBase->Draw(&Final.m[0][0],&Final.m[0][0]);
}

void PrimitiveInst::SetSignature(unsigned int f){
	pBase->SetGlobalSignature(f);
}
