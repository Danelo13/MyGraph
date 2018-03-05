#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
struct Vert {
		float x, y, z, w;
		float nx, ny, nz, nw;
		float u, v;
	};
struct Material {
	unsigned int IB;
	unsigned int diffuse_textID;
	string diffusePath;
	vector <unsigned short> indices;
	int ind;
};
struct Mesh {
	Vert					*vertices;
	unsigned short 			*indices;
	unsigned int			VB;
	unsigned int			IB;
	int						vert, ind, totalMaterial;
	vector <Material*> materials;

};
class Parcer
{
	
public:
	Parcer();
	~Parcer();

	bool OpenFile(const char * Filename);

	fstream Continuar;

	string reader;
	int NVertx;
	int NIndex;
	int NNormal;
	int NTexture;

	char tempchar;
	float holder;
	vector<Mesh*> Literate(const char * Filename, vector<Mesh*> MeshCount);

};
