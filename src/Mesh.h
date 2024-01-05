#ifndef BILLIARDS_MESH_H
#define BILLIARDS_MESH_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Vector.h"
#include "Shader.h"
#include "Material.h"

using namespace std;

enum MeshType {
    LINE_LOOP = GL_LINE_LOOP, TRIANGLE = GL_TRIANGLES, POLYGON=GL_TRIANGLE_FAN
};

class Mesh {
private:
    MeshType type;
    GLuint vao;
    int numberOfVertices;
    Material *material;
public:
    Mesh(vector<Vector> verticesVector,
         vector<Vector> normalsVector,
         MeshType type = MeshType::TRIANGLE);

    Mesh(vector<Vector> verticesVector,
         vector<Vector> normalsVector,
         vector<Vector> textureCoordinatesVector,
         Material *material,
         MeshType type = MeshType::TRIANGLE);

    void draw(Shader *shader, Matrix &modelMatrix);
};

#endif //BILLIARDS_MESH_H
