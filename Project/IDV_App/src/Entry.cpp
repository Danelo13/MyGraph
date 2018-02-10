#include <IDVDefs.h>
#include <MATRIX4D.h>
#include <IDVWindow/IDVWin32Manager.h>
#include <IDV_TestApplication.h>

#define xPI 3.14159265
#define ToRadian(d) ((d)*(xPI)/180.f)



IDVBaseApplication *g_pApplication = 0;
IDVBaseWindow	   *g_pWindow = 0;

int main(int arg, char ** args) {

	MATRIX4D Persp, Scale, RotX, RotY, RotZ, Trans;
	Persp = Persp*FOVLH(ToRadian(60.f), 1280.f / 720.f, 1.f, 1000.f);
	Scale = Scale*Scaling(1.1, 1.1, 1.1);
	RotX = RotX *RotationX(ToRadian(90.f));
	RotY = RotY *RotationY(ToRadian(15.f));
	RotZ = RotZ *RotationZ(ToRadian(120.f));
	Trans = Trans *Translation(15.f,-5.f,0.0f);

	MATRIX4D Final;
	Final = Persp*Scale*RotX*RotY*RotZ*Trans;

	g_pApplication = new IDVTestApplication();
	g_pWindow = new IDVWin32Manager((IDVBaseApplication*)g_pApplication);
	g_pWindow->InitGlobalVars();
	g_pWindow->OnCreateApplication();

	g_pWindow->UpdateApplication();

	g_pWindow->OnDestroyApplication();

	delete g_pWindow;
	delete g_pApplication;

	


	return 0;
}