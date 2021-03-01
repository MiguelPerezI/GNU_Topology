#include <stdarg.h>
#include "VectorND.hpp"
#include <string>
#include <GL/glut.h>

#ifndef GEOMETRY
#define GEOMETRY

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Facet {

private:
    string name;
    VectorND A, B, C, normal, aux1, aux2;

public:

    Facet() {};
    Facet(const VectorND& a, const VectorND& b, const VectorND& c, string s) {
        A.initCopyVectorND(a);
        B.initCopyVectorND(b);
        C.initCopyVectorND(c);

        this->normal.initCopyVectorND(a);
        this->aux1.initCopyVectorND(a);
        this->aux2.initCopyVectorND(a);

        updateNormal();
        this->name = s;
    }

    ~Facet() {
        //cout << "\nDestroyed Simplex " << name << endl;
    };
    
    void initFacetDefault(string s) {

        A.initVectorND(3, 1.0, 0.0, 0.0);
        B.initVectorND(3, 0.0, 1.0, 0.0);
        C.initVectorND(3, 0.0, 0.0, 1.0);

        this->normal.initVectorND(3, 1.0, 1.0, 1.0);
        this->aux1.initVectorND(3, 1.0, 0.0, 0.0);
        this->aux2.initVectorND(3, 1.0, 0.0, 0.0);

        this->name = s;
    }

    void escFacet(string s) const {

        if (s == "info") {
            cout << "\nName := " << name << endl;
            cout << "Point A := "; A.escVectorND("info");
            cout << "Point B := "; B.escVectorND("info");
            cout << "Point C := "; C.escVectorND("info");
        }
    }

    void updateNormal() {

        this->aux1.subVectorND(this->B, this->A);
        this->aux2.subVectorND(this->C, this->A);
        this->normal.Cross3D(this->aux1, this->aux2);
    }

    void updateNormal0() {

        VectorND aa = VectorND({B[0] - A[0], B[1] - A[1], B[2] - A[2]});
        VectorND bb = VectorND({C[0] - A[0], C[1] - A[1], C[2] - A[2]});
        this->normal.Cross3D(aa, bb);
    }

    void updateFacet(const VectorND& a, const VectorND& b, const VectorND& c) {

        A.updateVector3DP(a);
        B.updateVector3DP(b);
        C.updateVector3DP(c);

        updateNormal0();
    }

    void renderFacetOpenGL(int mod) const {

        double shadow = (double)mod / 765;
        glColor3ub(255 * shadow, 255 * shadow, 255 * shadow);

        glBegin(GL_TRIANGLES);
        glNormal3f( normal[0], normal[1], normal[2]);
        glVertex3f( A[0], A[1], A[2]);
        glVertex3f( B[0], B[1], B[2]);
        glVertex3f( C[0], C[1], C[2]);
        glEnd();
    }
};

class MatrixFacet {

private:
    int m, n;
    string name;
    Facet * * A;

public:
    
    MatrixFacet() {};
    void initMatrixFacet(int m, int n, string N) {

        this->m = m;
        this->n = n;
        this->name = N;

        this->A = (Facet **) malloc (m * sizeof(Facet*));
        if (this->A == NULL) 
            cerr << "\nNo Memory for " << name << endl;
        else {
            for (int i = 0; i < m; i++) {
                this->A[i] = (Facet *) malloc (n * sizeof(Facet));
                if (this->A[i] != NULL) 
                    for (int j = 0; j < n; j++) {
                        string mat = "(" + to_string(i) + ", " + to_string(j) + ")";
                        this->A[i][j].initFacetDefault(mat);
                    }
                else {
                    cout << "\nNo Memory for " << name << endl;
                }
            }
        }
    };
    ~MatrixFacet() {
        //cout << "\n-->Destroyed MatrixFacet " << name << endl;
    };

    void updateFacet(int i, int j, const VectorND& a, const VectorND& b, const VectorND& c) {

        this->A[i][j].updateFacet(a, b, c);
    }

    void renderFacetOpenGL(int i, int j, int mod) const {
        A[i][j].renderFacetOpenGL(mod);
    }
    
};

#endif
