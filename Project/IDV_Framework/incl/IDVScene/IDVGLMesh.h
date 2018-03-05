#ifndef IDV_MESH_GL_H
#define IDV_MESH_GL_H

#include <MATRIX4D.h>

#include <GL/glew.h>
#include <IDVParser.h>

#include <IDVVideo\IDVBaseDriver.h>
#include <IDVScene\IDVPrimitive.h>

struct buffers {
	GLuint			VB;
	GLuint			IB;
	int num_Vertices;
	int num_Indices;
};

class GLMESH : public PrimitiveBase {
public:
	//struct Vert {
	//	float x, y, z, w;
	//	float u, v;
	//};

	GLMESH() {}
	void Create() {};
	void Create(char * File);
	void Transform(float *t);
	void Draw(float *t, float *vp);
	void Destroy();
	Parcer Parseador;
	unsigned int	SigBase;

	Material *XMaterial;
	vector <Mesh*> Meshes;
	GLuint	VB;
	GLuint	IB;
	MATRIX4D		transform;
};

#endif