#ifndef IDV_D3DXSHADER_H
#define IDV_D3DXSHADER_H

#include <IDVVideo/IDVBaseDriver.h>
#include <d3d11.h>
#include <dxgi.h>
#include <D3Dcompiler.h>

#include <wrl.h>
#include <wrl/client.h>
using namespace Microsoft::WRL;


class IDVD3DXShader : public IDVShaderBase {
public:

	bool CreateShaderAPI(std::string src_vs, std::string src_fs, unsigned int sig);
	ComPtr<ID3D11VertexShader>  pVS;
	ComPtr<ID3D11PixelShader>   pFS;
	ComPtr<ID3DBlob>            VS_blob;
	ComPtr<ID3DBlob>            FS_blob;
	ComPtr<ID3D11InputLayout>   Layout;
	std::vector<D3D11_INPUT_ELEMENT_DESC>	VertexDecl;
};

#endif