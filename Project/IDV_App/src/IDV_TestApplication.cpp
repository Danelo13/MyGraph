#include <IDV_TestApplication.h>

#include <stdio.h>

void IDVTestApplication::InitVars() {

}

void IDVTestApplication::CreateAssets() {
	MATRIX4D VP;

	PrimitiveMgr = new PrimitiveManager(m_pWindow->m_pVideoDriver->SelectedApi);

	int index = PrimitiveMgr->CreateMesh();
	MeshInst.CreateInstance(PrimitiveMgr->GetPrimitive(index), &VP);


	MATRIX4D View;
	VECTOR4D Pos = VECTOR4D(0.0f, 1.0f, 5.0f, 0.0f);
	VECTOR4D Up = VECTOR4D(0.0f, 1.0f, 0.0f, 0.0f);
	VECTOR4D LookAt = VECTOR4D(0.0001f, 0.0001f, 0.0001f, 0.0f) - Pos;
	View = LookAtRH(Pos, LookAt, Up);
	MATRIX4D Proj;

	Proj = FOVLH(0.785398f, 1280.0f / 720.0f, 0.1f, 1000.0f);
	cout << endl << Proj << endl;
	cout << endl << View << endl;
	//	D3DXMatrixOrthoRH(&Proj, 1280.0f / 720.0f, 1.0f , 0.1, 100.0f);
	VP = View*Proj;

}

void IDVTestApplication::DestroyAssets() {
	delete PrimitiveMgr;
}

void IDVTestApplication::OnUpdate() {

	OnDraw();
}

void IDVTestApplication::OnDraw(){
	m_pWindow->m_pVideoDriver->Clear();

	MeshInst.Draw();

	m_pWindow->m_pVideoDriver->SwapBuffers();
}

void IDVTestApplication::OnInput() {

}