#include <IDVVideo/IDVGLShader.h>
#include <IDVScene\IDVGLMesh.h>
#include <IDVUtils/IDVUtils.h>

void GLMESH::Create(char * File) {
	SigBase = IDVSig::HAS_TEXCOORDS0;

	char *vsSourceP = file2string("Shaders/VS_Mesh.glsl");
	char *fsSourceP = file2string("Shaders/FS_Mesh.glsl");

	std::string vstr = std::string(vsSourceP);
	std::string fstr = std::string(fsSourceP);

	free(vsSourceP);
	free(fsSourceP);

	g_pBaseDriver->CreateShader(vstr, fstr, SigBase);

	Meshes = Parseador.Literate(File,Meshes);


	for (int i = 0; i < Meshes.size(); i++) {
		cout << "size " << Meshes.size() << endl;

		glGenBuffers(1, &Meshes[i]->VB);
		glBindBuffer(GL_ARRAY_BUFFER, Meshes[i]->VB);
		glBufferData(GL_ARRAY_BUFFER, Meshes[i]->vert * sizeof(Vert), Meshes[i]->vertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);


		//for (int j = 0; j < Meshes[i]->ind * 3; ++j) {

		glGenBuffers(1, &Meshes[i]->IB);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[i]->IB);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, Meshes[i]->ind * sizeof(unsigned short), Meshes[i]->indices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		//}
	}
	MATRIX4D &transform = Identity();
}

void GLMESH::Transform(float *t) {
	for (int i = 0; i < 16; i++)
		transform.v[i] = t[i];
}

void GLMESH::Draw(float *t, float *vp) {


	unsigned int sig = SigBase;
	sig |= gSig;
	IDVGLShader * s = dynamic_cast<IDVGLShader*>(g_pBaseDriver->GetShaderSig(sig));

	glUseProgram(s->ShaderProg);

	if (t)
		for (int i = 0; i < 16; i++)
			transform.v[i] = t[i];

	MATRIX4D VP;
	for (int i = 0; i < 16; i++)
		VP.v[i] = vp[i];
	MATRIX4D WVP = transform*VP;

	glUniformMatrix4fv(s->matWorldUniformLoc, 1, GL_FALSE, t);
	glUniformMatrix4fv(s->matWorldViewProjUniformLoc, 1, GL_FALSE, &WVP.m[0][0]);

	for (int i = 0; i < Meshes.size(); i++) {

		glBindBuffer(GL_ARRAY_BUFFER, Meshes[i]->VB);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[i]->IB);

		glEnableVertexAttribArray(s->vertexAttribLoc);
		glEnableVertexAttribArray(s->normalAttribLoc);

		if (s->uvAttribLoc != -1)
			glEnableVertexAttribArray(s->uvAttribLoc);

		glVertexAttribPointer(s->vertexAttribLoc, 4, GL_FLOAT, GL_FALSE, sizeof(Vert), BUFFER_OFFSET(0));
		glVertexAttribPointer(s->normalAttribLoc, 4, GL_FLOAT, GL_FALSE, sizeof(Vert), BUFFER_OFFSET(16));

		if (s->uvAttribLoc != -1)
			glVertexAttribPointer(s->uvAttribLoc, 2, GL_FLOAT, GL_FALSE, sizeof(Vert), BUFFER_OFFSET(32));

		glDrawElements(GL_TRIANGLES, Meshes[i]->ind, GL_UNSIGNED_SHORT, 0);


		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		glDisableVertexAttribArray(s->vertexAttribLoc);
		glDisableVertexAttribArray(s->normalAttribLoc);

		if (s->uvAttribLoc != -1) {
			glDisableVertexAttribArray(s->uvAttribLoc);
		}
	}
}

void GLMESH::Destroy() {

}

