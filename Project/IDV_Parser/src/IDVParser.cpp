#include <IDVParser.h>
#include <stdio.h>



Parcer::Parcer()
{
}


Parcer::~Parcer()
{
}


bool Parcer::OpenFile(const char * Filename) {
	Continuar.open(Filename, fstream::in);
	if (!Continuar.is_open()) {
		return false;
	}
	return true;

}

vector <Mesh*> Parcer::Literate(const char * Filename, /*vector<unsigned short> index,*/ vector <Mesh*> MeshCount) {

	Mesh *M;
	M = new Mesh();
	if (OpenFile(Filename)) {
		getline(Continuar, reader);
		if (reader == "xof 0303txt 0032") {
			while (/*!Continuar.eof()*/getline(Continuar, reader))
			{


				int findMesh = reader.find("Mesh mesh");
				int findNormals = reader.find("MeshNormals normals");
				int findT = reader.find("MeshTextureCoords tc0 {");


				if (findMesh != -1) {

					Continuar >> M->vert >> tempchar;
					cout << "Vertices: " << M->vert << endl;
					M->vertices = new Vert[M->vert];
					for (int i = 0; i < M->vert; i++) {
						//	CVertex4 *V = new CVertex4();

						Continuar >> holder >> tempchar;
						M->vertices[i].x = holder;
						Continuar >> holder >> tempchar;
						M->vertices[i].y = holder;
						Continuar >> holder >> tempchar >> tempchar;
						M->vertices[i].z = holder;
						M->vertices[i].w = 1;
					}
					Continuar >> M->ind >> tempchar;
					cout << "indices: " << M->ind << endl;
					M->indices = new unsigned short[M->ind * 3];

					cout << "Estos son los indices:" << endl;

					for (int i = 0; i < M->ind * 3; i++) {


						Continuar >> tempchar >> tempchar >> holder >> tempchar;    // 1,3,2


						M->indices[i] = holder; cout << M->indices[i] << ",";   // 1
						Continuar >> holder >> tempchar;
						float temp3 = holder;  //3 
						i++;
						Continuar >> holder >> tempchar >> tempchar;
						M->indices[i] = holder; cout << M->indices[i] << ",";   //2
						i++;
						M->indices[i] = temp3; cout << M->indices[i] << "  " << i << endl;


					}
					/*				cout << "Random indices: " << M->indices[3000] << "," << M->indices[3001] << endl;
					cout << "Random indices: " << M->vertices[2000].x << "," << M->vertices[2000].y << endl;*/

				}


				if (findNormals != -1) {
					Continuar >> NNormal >> tempchar;
					cout << "Normales: " << NNormal << endl;
					for (int i = 0; i < NNormal; i++) {

						Continuar >> holder >> tempchar;
						M->vertices[i].nx = holder;
						Continuar >> holder >> tempchar;
						M->vertices[i].ny = holder;
						Continuar >> holder >> tempchar >> tempchar;
						M->vertices[i].nz = holder;
						M->vertices[i].nw = 1;

					}

				}

				if (findT != -1) {
					Continuar >> NTexture >> tempchar;
					for (int i = 0; i < NTexture; i++) {


						Continuar >> holder >> tempchar;
						M->vertices[i].u = holder;

						Continuar >> holder >> tempchar >> tempchar;
						M->vertices[i].v = holder;

					}


					MeshCount.push_back(M);
				}


			}
		}

		Continuar.close();
	}
	return MeshCount;

}



