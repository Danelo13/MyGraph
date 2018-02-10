
#ifndef IDV_D3DXDRIVER_H
#define IDV_D3DXDRIVER_H

#include <IDVVideo\IDVBaseDriver.h>

#include <d3d11.h>
#include <dxgi.h>
#include <D3Dcompiler.h>

#include <wrl.h>
#include <wrl/client.h>
using namespace Microsoft::WRL;

class D3DXDriver : public BaseDriver {
public:
	D3DXDriver() {  }
	void	InitDriver();
	void	CreateSurfaces();
	void	DestroySurfaces();
	void	Update();
	void	DestroyDriver();
	void	SetWindow(void *window);
	void	SetDimensions(int, int);

	int			CreateShader(std::string src_vs, std::string src_fs, unsigned int sig);
	ShaderBase*	GetShaderSig(unsigned int sig);
	ShaderBase*	GetShaderIdx(int Id);
	void		DestroyShaders();

	void	Clear();
	void	SwapBuffers();

	int		Width;
	int		Height;
	HWND	hwnd;

	D3D11_VIEWPORT viewport;
	D3D11_VIEWPORT viewport_RT;
};

#endif