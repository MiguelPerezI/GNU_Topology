#include <stdarg.h>
#include "VectorND.hpp"
#include "GNU_GEOM.hpp"
#include <string>

#ifndef DODECAHEDRON
#define DODECAHEDRON

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double gold = 1.618;
double g1 = 1.0/1.618;
double g2 = 1.0/(1.618 * 1.618);

VectorND vertexGlobal[20] = {
    VectorND({ g2,      0.0,      1.0}, "v0"),
    VectorND({-g2,      0.0,      1.0}, "v1"),
    VectorND({-g1,       g1,       g1}, "v2"),
    VectorND({0.0,      1.0,       g2}, "v3"),
    VectorND({ g1,       g1,       g1}, "v4"),
    VectorND({0.0,     -1.0,       g2}, "v5"),
    VectorND({ g1,      -g1,       g1}, "v6"),
    VectorND({-g1,      -g1,       g1}, "v7"),
    VectorND({ g2,      0.0,     -1.0}, "v8"),
    VectorND({-g2,      0.0,     -1.0}, "v9"),
    VectorND({-g1,      -g1,      -g1}, "v10"),
    VectorND({ 0.0,    -1.0,      -g2}, "v11"),
    VectorND({  g1,     -g1,      -g1}, "v12"),
    VectorND({  g1,      g1,      -g1}, "v13"),
    VectorND({ 0.0,     1.0,      -g2}, "v14"),
    VectorND({ -g1,      g1,      -g1}, "v15"),
    VectorND({ 1.0,     -g2,      0.0}, "v16"),
    VectorND({ -1.0,     g2,      0.0}, "v17"),
    VectorND({ -1.0,    -g2,      0.0}, "v18"),
    VectorND({  1.0,     g2,      0.0}, "v19")
};

class Pentagon {
private:

    string name;
    VectorND p0, p1, p2, p3, p4, center, normal, relCenter;
    Facet f0, f1, f2, f3, f4;
public:

    Pentagon() {};
    Pentagon(const VectorND& q0, const VectorND& q1, const VectorND& q2, const VectorND& q3, const VectorND& q4, string name) {

        this->name = name;
        relCenter.initCopyVectorNDtype2(q0, "Pentagon(" + name + ")-->RelativeCenter");
        relCenter.updateVector3D(0.0, 0.0, 0.0);
        p0.initCopyVectorNDtype2(q0, "Pentagon(" + name + ")-->Vertex0");
        p1.initCopyVectorNDtype2(q1, "Pentagon(" + name + ")-->Vertex1");
        p2.initCopyVectorNDtype2(q2, "Pentagon(" + name + ")-->Vertex2");
        p3.initCopyVectorNDtype2(q3, "Pentagon(" + name + ")-->Vertex3");
        p4.initCopyVectorNDtype2(q4, "Pentagon(" + name + ")-->Vertex4");

        center.initCopyVectorNDtype2(q0, "Pentagon " + name + " -->center");
        center.updateVector3D(0.0, 0.0, 0.0);
        center.addVectorNDP(p0);
        center.addVectorNDP(p1);
        center.addVectorNDP(p2);
        center.addVectorNDP(p3);
        center.addVectorNDP(p4);
        center.scalarMultND(0.2);

        f0.initFacetDefault("Pentagon(" + name + ")-->Face0");
        f0.updateFacet(p0, p1, center);

        f1.initFacetDefault("Pentagon(" + name + ")-->Face1");
        f1.updateFacet(p1, p2, center);

        f2.initFacetDefault("Pentagon(" + name + ")-->Face2");
        f2.updateFacet(p2, p3, center);

        f3.initFacetDefault("Pentagon(" + name + ")-->Face3");
        f3.updateFacet(p3, p4, center);

        f4.initFacetDefault("Pentagon(" + name + ")-->Face4");
        f4.updateFacet(p4, p0, center);  
    }

    void initPentagon(const VectorND& q0, const VectorND& q1, const VectorND& q2, const VectorND& q3, const VectorND& q4, string name) {

        this->name = name;
        relCenter.initCopyVectorNDtype2(q0, "Pentagon(" + name + ")-->RelativeCenter");
        relCenter.updateVector3D(0.0, 0.0, 0.0);
        p0.initCopyVectorNDtype2(q0, "Pentagon(" + name + ")-->Vertex0");
        p1.initCopyVectorNDtype2(q1, "Pentagon(" + name + ")-->Vertex1");
        p2.initCopyVectorNDtype2(q2, "Pentagon(" + name + ")-->Vertex2");
        p3.initCopyVectorNDtype2(q3, "Pentagon(" + name + ")-->Vertex3");
        p4.initCopyVectorNDtype2(q4, "Pentagon(" + name + ")-->Vertex4");

        center.initCopyVectorNDtype2(q0, "Pentagon " + name + " -->center");
        center.updateVector3D(0.0, 0.0, 0.0);
        center.addVectorNDP(p0);
        center.addVectorNDP(p1);
        center.addVectorNDP(p2);
        center.addVectorNDP(p3);
        center.addVectorNDP(p4);
        center.scalarMultND(0.2);

        f0.initFacetDefault("Pentagon(" + name + ")-->Face0");
        f0.updateFacet(p0, p1, center);

        f1.initFacetDefault("Pentagon(" + name + ")-->Face1");
        f1.updateFacet(p1, p2, center);

        f2.initFacetDefault("Pentagon(" + name + ")-->Face2");
        f2.updateFacet(p2, p3, center);

        f3.initFacetDefault("Pentagon(" + name + ")-->Face3");
        f3.updateFacet(p3, p4, center);

        f4.initFacetDefault("Pentagon(" + name + ")-->Face4");
        f4.updateFacet(p4, p0, center);  
    }

    void initPentagonByCopy(const Pentagon& pentagonS, string s) {

        this->name = s;
        relCenter.initCopyVectorNDtype2(pentagonS.relCenter, "Pentagon(" + name + ")-->RelativeCenter");
        relCenter.updateVector3D(0.0, 0.0, 0.0);
        p0.initCopyVectorNDtype2(pentagonS.p0, "Pentagon(" + name + ")-->Vertex0");
        p1.initCopyVectorNDtype2(pentagonS.p1, "Pentagon(" + name + ")-->Vertex1");
        p2.initCopyVectorNDtype2(pentagonS.p2, "Pentagon(" + name + ")-->Vertex2");
        p3.initCopyVectorNDtype2(pentagonS.p3, "Pentagon(" + name + ")-->Vertex3");
        p4.initCopyVectorNDtype2(pentagonS.p4, "Pentagon(" + name + ")-->Vertex4");

        center.initCopyVectorNDtype2(p0, "Pentagon " + name + " -->center");
        center.updateVector3D(pentagonS.center[0], pentagonS.center[1], pentagonS.center[2]);

        f0.initFacetDefault("Pentagon(" + name + ")-->Face0");
        f0.updateFacet(p0, p1, center);

        f1.initFacetDefault("Pentagon(" + name + ")-->Face1");
        f1.updateFacet(p1, p2, center);

        f2.initFacetDefault("Pentagon(" + name + ")-->Face2");
        f2.updateFacet(p2, p3, center);

        f3.initFacetDefault("Pentagon(" + name + ")-->Face3");
        f3.updateFacet(p3, p4, center);

        f4.initFacetDefault("Pentagon(" + name + ")-->Face4");
        f4.updateFacet(p4, p0, center);          
    }

    ~Pentagon() {};

    void updatePentagon(const VectorND& q0, const VectorND& q1, const VectorND& q2, const VectorND& q3, const VectorND& q4) {

        p0.updateVector3D(q0[0], q0[1], q0[2]);
        p1.updateVector3D(q1[0], q1[1], q1[2]);
        p2.updateVector3D(q2[0], q2[1], q2[2]);
        p3.updateVector3D(q3[0], q3[1], q3[2]);
        p4.updateVector3D(q4[0], q4[1], q4[2]);

        center.updateVector3D(0.0, 0.0, 0.0);
        center.addVectorNDP(p0);
        center.addVectorNDP(p1);
        center.addVectorNDP(p2);
        center.addVectorNDP(p3);
        center.addVectorNDP(p4);
        center.scalarMultND(0.2);

        f0.updateFacet(p0, p1, center);
        f1.updateFacet(p1, p2, center);
        f2.updateFacet(p2, p3, center);
        f3.updateFacet(p3, p4, center);
        f4.updateFacet(p4, p0, center);
    }

    void translateRNormal(double x) {

        VectorND aux = VectorND({0.0, 0.0, 0.0}, "auxilary_Vector");
        aux.subVectorND(center, relCenter);
        aux.scalarMultND(x);
        aux.addVectorNDP(relCenter);

        p0.addVectorNDP(aux);
        p1.addVectorNDP(aux);
        p2.addVectorNDP(aux);
        p3.addVectorNDP(aux);
        p4.addVectorNDP(aux);

        center.addVectorNDP(aux);

        f0.updateFacet(p0, p1, center);
        f1.updateFacet(p1, p2, center);
        f2.updateFacet(p2, p3, center);
        f3.updateFacet(p3, p4, center);
        f4.updateFacet(p4, p0, center);

        p0.subVectorNDP(aux);
        p1.subVectorNDP(aux);
        p2.subVectorNDP(aux);
        p3.subVectorNDP(aux);
        p4.subVectorNDP(aux);
        center.subVectorNDP(aux);
    }

    void renderPentagon() {

        f0.renderFacetOpenGL(500);
        f1.renderFacetOpenGL(500);
        f2.renderFacetOpenGL(500);
        f3.renderFacetOpenGL(500);
        f4.renderFacetOpenGL(500);
    }
};


Pentagon pentaGlobal[12] = {

        Pentagon( vertexGlobal[2],  vertexGlobal[1],  vertexGlobal[0],  vertexGlobal[4],  vertexGlobal[3], "Face0"),
        Pentagon( vertexGlobal[2], vertexGlobal[17], vertexGlobal[18],  vertexGlobal[7],  vertexGlobal[1], "Face1"),
        Pentagon( vertexGlobal[1],  vertexGlobal[7],  vertexGlobal[5],  vertexGlobal[6],  vertexGlobal[0], "Face2"),
        Pentagon( vertexGlobal[0],  vertexGlobal[6], vertexGlobal[16], vertexGlobal[19],  vertexGlobal[4], "Face3"),
        Pentagon( vertexGlobal[4], vertexGlobal[19], vertexGlobal[13], vertexGlobal[14],  vertexGlobal[3], "Face4"),
        Pentagon( vertexGlobal[3], vertexGlobal[14], vertexGlobal[15], vertexGlobal[14],  vertexGlobal[2], "Face5"),

        Pentagon(vertexGlobal[12], vertexGlobal[16],  vertexGlobal[6],  vertexGlobal[5], vertexGlobal[11], "Face6"),
        Pentagon(vertexGlobal[11],  vertexGlobal[5],  vertexGlobal[7], vertexGlobal[18], vertexGlobal[10], "Face7"),
        Pentagon(vertexGlobal[10], vertexGlobal[18], vertexGlobal[17], vertexGlobal[15],  vertexGlobal[9], "Face8"),
        Pentagon( vertexGlobal[9], vertexGlobal[15], vertexGlobal[14], vertexGlobal[13],  vertexGlobal[8], "Face9"),
        Pentagon( vertexGlobal[8], vertexGlobal[13], vertexGlobal[19], vertexGlobal[16], vertexGlobal[12], "Face10"),
        Pentagon(vertexGlobal[12], vertexGlobal[11], vertexGlobal[10],  vertexGlobal[9],  vertexGlobal[8], "Face11")
};

class Dodecahedron {

private:
    int n;
    string name;
    MatrixVectorND vertex;
    VectorND center;
    double radius;
    Pentagon penta[12];

public:

    Dodecahedron() {};
    Dodecahedron(double r, const VectorND& c, string N) {
        
        
        name = N;
        radius = r;
        center = VectorND({0.0, 0.0, 0.0});
        vertex.MatrixVector3D(1, 20, "pilaVectorial");


        vertex.updateVector3D(0, 0, vertexGlobal[0][0],     vertexGlobal[0][1], vertexGlobal[0][2]);
        vertex.updateVector3D(0, 1, vertexGlobal[1][0],     vertexGlobal[1][1], vertexGlobal[1][2]);
        vertex.updateVector3D(0, 2, vertexGlobal[2][0],     vertexGlobal[2][1], vertexGlobal[2][2]);
        vertex.updateVector3D(0, 3, vertexGlobal[3][0],     vertexGlobal[3][1], vertexGlobal[3][2]);
        vertex.updateVector3D(0, 4, vertexGlobal[4][0],     vertexGlobal[4][1], vertexGlobal[4][2]);
        vertex.updateVector3D(0, 5, vertexGlobal[5][0],     vertexGlobal[5][1], vertexGlobal[5][2]);
        vertex.updateVector3D(0, 6, vertexGlobal[6][0],     vertexGlobal[6][1], vertexGlobal[6][2]);
        vertex.updateVector3D(0, 7, vertexGlobal[7][0],     vertexGlobal[7][1], vertexGlobal[7][2]);
        vertex.updateVector3D(0, 8, vertexGlobal[8][0],     vertexGlobal[8][1], vertexGlobal[8][2]);
        vertex.updateVector3D(0, 9, vertexGlobal[9][0],     vertexGlobal[9][1], vertexGlobal[9][2]);
        vertex.updateVector3D(0, 10, vertexGlobal[10][0],     vertexGlobal[10][1], vertexGlobal[10][2]);
        vertex.updateVector3D(0, 11, vertexGlobal[11][0], vertexGlobal[11][1], vertexGlobal[11][2]);
        vertex.updateVector3D(0, 12, vertexGlobal[12][0], vertexGlobal[12][1], vertexGlobal[12][2]);
        vertex.updateVector3D(0, 13, vertexGlobal[13][0], vertexGlobal[13][1], vertexGlobal[13][2]);
        vertex.updateVector3D(0, 14, vertexGlobal[14][0], vertexGlobal[14][1], vertexGlobal[14][2]);
        vertex.updateVector3D(0, 15, vertexGlobal[15][0], vertexGlobal[15][1], vertexGlobal[15][2]);
        vertex.updateVector3D(0, 16, vertexGlobal[16][0], vertexGlobal[16][1], vertexGlobal[16][2]);
        vertex.updateVector3D(0, 17, vertexGlobal[17][0], vertexGlobal[17][1], vertexGlobal[17][2]);
        vertex.updateVector3D(0, 18, vertexGlobal[18][0], vertexGlobal[18][1], vertexGlobal[18][2]);
        vertex.updateVector3D(0, 19, vertexGlobal[19][0], vertexGlobal[19][1], vertexGlobal[19][2]);

        for (int i= 0; i< 12; i++)
            penta[i].initPentagonByCopy(pentaGlobal[i], "Pentagon" + to_string(i));



    }

    void defaultDodecahedron() {

        this->name = "defaultDodecahedron";
        this->radius = 1.0;
        this->center = VectorND({0.0, 0.0, 0.0}, "center");
        this->vertex.MatrixVector3D(1, 20, "pilaVectorial");


        this->vertex.updateVector3D(0, 0, vertexGlobal[0][0],     vertexGlobal[0][1], vertexGlobal[0][2]);
        this->vertex.updateVector3D(0, 1, vertexGlobal[1][0],     vertexGlobal[1][1], vertexGlobal[1][2]);
        this->vertex.updateVector3D(0, 2, vertexGlobal[2][0],     vertexGlobal[2][1], vertexGlobal[2][2]);
        this->vertex.updateVector3D(0, 3, vertexGlobal[3][0],     vertexGlobal[3][1], vertexGlobal[3][2]);
        this->vertex.updateVector3D(0, 4, vertexGlobal[4][0],     vertexGlobal[4][1], vertexGlobal[4][2]);
        this->vertex.updateVector3D(0, 5, vertexGlobal[5][0],     vertexGlobal[5][1], vertexGlobal[5][2]);
        this->vertex.updateVector3D(0, 6, vertexGlobal[6][0],     vertexGlobal[6][1], vertexGlobal[6][2]);
        this->vertex.updateVector3D(0, 7, vertexGlobal[7][0],     vertexGlobal[7][1], vertexGlobal[7][2]);
        this->vertex.updateVector3D(0, 8, vertexGlobal[8][0],     vertexGlobal[8][1], vertexGlobal[8][2]);
        this->vertex.updateVector3D(0, 9, vertexGlobal[9][0],     vertexGlobal[9][1], vertexGlobal[9][2]);
        this->vertex.updateVector3D(0, 10, vertexGlobal[10][0],     vertexGlobal[10][1], vertexGlobal[10][2]);
        this->vertex.updateVector3D(0, 11, vertexGlobal[11][0], vertexGlobal[11][1], vertexGlobal[11][2]);
        this->vertex.updateVector3D(0, 12, vertexGlobal[12][0], vertexGlobal[12][1], vertexGlobal[12][2]);
        this->vertex.updateVector3D(0, 13, vertexGlobal[13][0], vertexGlobal[13][1], vertexGlobal[13][2]);
        this->vertex.updateVector3D(0, 14, vertexGlobal[14][0], vertexGlobal[14][1], vertexGlobal[14][2]);
        this->vertex.updateVector3D(0, 15, vertexGlobal[15][0], vertexGlobal[15][1], vertexGlobal[15][2]);
        this->vertex.updateVector3D(0, 16, vertexGlobal[16][0], vertexGlobal[16][1], vertexGlobal[16][2]);
        this->vertex.updateVector3D(0, 17, vertexGlobal[17][0], vertexGlobal[17][1], vertexGlobal[17][2]);
        this->vertex.updateVector3D(0, 18, vertexGlobal[18][0], vertexGlobal[18][1], vertexGlobal[18][2]);
        this->vertex.updateVector3D(0, 19, vertexGlobal[19][0], vertexGlobal[19][1], vertexGlobal[19][2]);

        for (int i= 0; i< 12; i++)
            penta[i].initPentagonByCopy(pentaGlobal[i], "Pentagon" + to_string(i));  
    }

    void updateDodecahedron(double radius, const VectorND& centerC, string s) {

        this->name = s;
        this->radius = radius;
        this->center.updateVector3D(centerC[0], centerC[1], centerC[2]);

        vertex.updateVector3D(0, 0, radius*vertexGlobal[0][0] + center[0],     radius*vertexGlobal[0][1] + center[1], radius*vertexGlobal[0][2] + center[2]);
        vertex.updateVector3D(0, 1, radius*vertexGlobal[1][0] + center[0],     radius*vertexGlobal[1][1] + center[1], radius*vertexGlobal[1][2] + center[2]);
        vertex.updateVector3D(0, 2, radius*vertexGlobal[2][0] + center[0],     radius*vertexGlobal[2][1] + center[1], radius*vertexGlobal[2][2] + center[2]);
        vertex.updateVector3D(0, 3, radius*vertexGlobal[3][0] + center[0],     radius*vertexGlobal[3][1] + center[1], radius*vertexGlobal[3][2] + center[2]);
        vertex.updateVector3D(0, 4, radius*vertexGlobal[4][0] + center[0],     radius*vertexGlobal[4][1] + center[1], radius*vertexGlobal[4][2] + center[2]);
        vertex.updateVector3D(0, 5, radius*vertexGlobal[5][0] + center[0],     radius*vertexGlobal[5][1] + center[1], radius*vertexGlobal[5][2] + center[2]);
        vertex.updateVector3D(0, 6, radius*vertexGlobal[6][0] + center[0],     radius*vertexGlobal[6][1] + center[1], radius*vertexGlobal[6][2] + center[2]);
        vertex.updateVector3D(0, 7, radius*vertexGlobal[7][0] + center[0],     radius*vertexGlobal[7][1] + center[1], radius*vertexGlobal[7][2] + center[2]);
        vertex.updateVector3D(0, 8, radius*vertexGlobal[8][0] + center[0],     radius*vertexGlobal[8][1] + center[1], radius*vertexGlobal[8][2] + center[2]);
        vertex.updateVector3D(0, 9, radius*vertexGlobal[9][0] + center[0],     radius*vertexGlobal[9][1] + center[1], radius*vertexGlobal[9][2] + center[2]);
        vertex.updateVector3D(0, 10, radius*vertexGlobal[10][0] + center[0], radius*vertexGlobal[10][1] + center[1], radius*vertexGlobal[10][2] + center[2]);
        vertex.updateVector3D(0, 11, radius*vertexGlobal[11][0] + center[0], radius*vertexGlobal[11][1] + center[1], radius*vertexGlobal[11][2] + center[2]);
        vertex.updateVector3D(0, 12, radius*vertexGlobal[12][0] + center[0], radius*vertexGlobal[12][1] + center[1], radius*vertexGlobal[12][2] + center[2]);
        vertex.updateVector3D(0, 13, radius*vertexGlobal[13][0] + center[0], radius*vertexGlobal[13][1] + center[1], radius*vertexGlobal[13][2] + center[2]);
        vertex.updateVector3D(0, 14, radius*vertexGlobal[14][0] + center[0], radius*vertexGlobal[14][1] + center[1], radius*vertexGlobal[14][2] + center[2]);
        vertex.updateVector3D(0, 15, radius*vertexGlobal[15][0] + center[0], radius*vertexGlobal[15][1] + center[1], radius*vertexGlobal[15][2] + center[2]);
        vertex.updateVector3D(0, 16, radius*vertexGlobal[16][0] + center[0], radius*vertexGlobal[16][1] + center[1], radius*vertexGlobal[16][2] + center[2]);
        vertex.updateVector3D(0, 17, radius*vertexGlobal[17][0] + center[0], radius*vertexGlobal[17][1] + center[1], radius*vertexGlobal[17][2] + center[2]);
        vertex.updateVector3D(0, 18, radius*vertexGlobal[18][0] + center[0], radius*vertexGlobal[18][1] + center[1], radius*vertexGlobal[18][2] + center[2]);
        vertex.updateVector3D(0, 19, radius*vertexGlobal[19][0] + center[0], radius*vertexGlobal[19][1] + center[1], radius*vertexGlobal[19][2] + center[2]);
    
        penta[0].updatePentagon( vertex[0][2],  vertex[0][1], vertex[0][0], vertex[0][4],  vertex[0][3]);
        penta[1].updatePentagon(vertex[0][18],  vertex[0][7], vertex[0][1], vertex[0][2], vertex[0][17]);
        penta[2].updatePentagon( vertex[0][5],  vertex[0][6], vertex[0][0], vertex[0][1],  vertex[0][7]);
        penta[3].updatePentagon(vertex[0][16], vertex[0][19], vertex[0][4], vertex[0][0],  vertex[0][6]);
        penta[4].updatePentagon(vertex[0][13], vertex[0][14], vertex[0][3], vertex[0][4], vertex[0][19]);
        penta[5].updatePentagon(vertex[0][15], vertex[0][17], vertex[0][2], vertex[0][3], vertex[0][14]);

        penta[6].updatePentagon(vertex[0][12], vertex[0][16], vertex[0][6], vertex[0][5], vertex[0][11]);
        penta[7].updatePentagon(vertex[0][11], vertex[0][5], vertex[0][7], vertex[0][18], vertex[0][10]);
        penta[8].updatePentagon(vertex[0][10], vertex[0][18], vertex[0][17], vertex[0][15], vertex[0][9]);
        penta[9].updatePentagon(vertex[0][9], vertex[0][15], vertex[0][14], vertex[0][13], vertex[0][8]);
        penta[10].updatePentagon(vertex[0][8], vertex[0][13], vertex[0][19], vertex[0][16], vertex[0][12]);
        penta[11].updatePentagon(vertex[0][12], vertex[0][11], vertex[0][10], vertex[0][9], vertex[0][8]);
    }

    ~Dodecahedron() {
        //cout << "\n-->Destroyed Dodecahedron " << name << endl;
    };

    void renderDodecahedronOpenGL() {

        for (int i= 0; i < 12; i++)
            penta[i].renderPentagon();
    }

    void explodeFaces(double x) {

        for (int i = 0; i < 12; i++)
            penta[i].translateRNormal(x);
    }

    //dilate(VectorND head, VectorND source, double lambda)
    void dilateDodecahedron(const VectorND& source, double lambda) {

        for (int i = 0; i < 20; i++)
            vertex.dilate(0, i, vertexGlobal[i], source, lambda);

        penta[0].updatePentagon( vertex[0][2],  vertex[0][1], vertex[0][0], vertex[0][4],  vertex[0][3]);
        penta[1].updatePentagon(vertex[0][18],  vertex[0][7], vertex[0][1], vertex[0][2], vertex[0][17]);
        penta[2].updatePentagon( vertex[0][5],  vertex[0][6], vertex[0][0], vertex[0][1],  vertex[0][7]);
        penta[3].updatePentagon(vertex[0][16], vertex[0][19], vertex[0][4], vertex[0][0],  vertex[0][6]);
        penta[4].updatePentagon(vertex[0][13], vertex[0][14], vertex[0][3], vertex[0][4], vertex[0][19]);
        penta[5].updatePentagon(vertex[0][15], vertex[0][17], vertex[0][2], vertex[0][3], vertex[0][14]);

        penta[6].updatePentagon(vertex[0][12], vertex[0][16], vertex[0][6], vertex[0][5], vertex[0][11]);
        penta[7].updatePentagon(vertex[0][11], vertex[0][5], vertex[0][7], vertex[0][18], vertex[0][10]);
        penta[8].updatePentagon(vertex[0][10], vertex[0][18], vertex[0][17], vertex[0][15], vertex[0][9]);
        penta[9].updatePentagon(vertex[0][9], vertex[0][15], vertex[0][14], vertex[0][13], vertex[0][8]);
        penta[10].updatePentagon(vertex[0][8], vertex[0][13], vertex[0][19], vertex[0][16], vertex[0][12]);
        penta[11].updatePentagon(vertex[0][12], vertex[0][11], vertex[0][10], vertex[0][9], vertex[0][8]);
    }
    
};

class MatrixDodecahedron {

private:
    int m, n;
    string name;
    Dodecahedron * * A;

public:

    MatrixDodecahedron() {};
    MatrixDodecahedron(int m, int n, string s) {

        this->m = m;
        this->n = n;
        this->name = s;

        this->A = (Dodecahedron * *) malloc (m * sizeof(Dodecahedron*));
        if (this->A == NULL) 
            cerr << "\nNo Memory for " << name << endl;
        else {
            for (int i = 0; i < m; i++) {
                this->A[i] = (Dodecahedron *) malloc (n * sizeof(Dodecahedron));
                if (this->A[i] != NULL) 
                    for (int j = 0; j < n; j++) {
                        string mat = "(" + to_string(i) + ", " + to_string(j) + ")";

                        A[i][j].defaultDodecahedron();
                    }
                else {
                    cout << "\nNo Memory for " << name << endl;
                }
            }
        }
    };

    void initDodecahedron(int i, double r, const VectorND& c, string s) {

        this->A[0][i]= Dodecahedron(r, c, s);
    }

    void updateDodecahedronList(int i, double radius, const VectorND& center, string s) {

        this->A[0][i].updateDodecahedron(radius, center, s);
    }

    void dilateDodecahedron(int i, const VectorND& source, double lambda) {

        A[0][i].dilateDodecahedron(source, lambda);
    }

    ~MatrixDodecahedron(){};

    void renderMatrixDodecahedronOpenGL() {

        for (int i= 0; i< m; i++)
            for (int j= 0; j< n; j++)
                A[i][j].renderDodecahedronOpenGL();
    }
    
};

#endif
