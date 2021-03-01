#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include "VectorND.hpp"
#include "GNU_GEOM.hpp"
#include "Dodecahedron.hpp"
#include <string>
//////////////////////////////////////
//                                  //
//                                  //
//        VARIABLES GLOBALES        //
//                                  //
//                                  //
//////////////////////////////////////

/*
Compile With c++ main.cpp -lGL -lGLU -lglut -o topology
*/

/*variables*/ 
int ciclo = 0;
int cicloSegund = 0;
int color = 0;
double count = 0.0;
double rotSpeed = 0.0;
double rotAxe = 0.0;

int pass00 = 0;

double g11 = 1.0/1.618;
double g21 = 1.0/(1.618 * 1.618);

VectorND vertexD[20] = {
    VectorND({ g21,      0.0,      1.0}, "v0"),
    VectorND({-g21,      0.0,      1.0}, "v1"),
    VectorND({-g11,       g11,       g11}, "v2"),
    VectorND({0.0,      1.0,       g21}, "v3"),
    VectorND({ g11,       g11,       g11}, "v4"),
    VectorND({0.0,     -1.0,       g21}, "v5"),
    VectorND({ g11,      -g11,       g11}, "v6"),
    VectorND({-g11,      -g11,       g11}, "v7"),
    VectorND({ g21,      0.0,     -1.0}, "v8"),
    VectorND({-g21,      0.0,     -1.0}, "v9"),
    VectorND({-g11,      -g11,      -g11}, "v10"),
    VectorND({ 0.0,    -1.0,      -g21}, "v11"),
    VectorND({  g11,     -g11,      -g11}, "v12"),
    VectorND({  g11,      g11,      -g11}, "v13"),
    VectorND({ 0.0,     1.0,      -g21}, "v14"),
    VectorND({ -g11,      g11,      -g11}, "v15"),
    VectorND({ 1.0,     -g21,      0.0}, "v16"),
    VectorND({ -1.0,     g21,      0.0}, "v17"),
    VectorND({ -1.0,    -g21,      0.0}, "v18"),
    VectorND({  1.0,     g21,      0.0}, "v19")
};

/*Definimos Vectores que nos pueden ayudar a generar el espacio*/
VectorND center = VectorND({0, 0, 0}, "center");
VectorND a = VectorND({1.0, 0.0, 0.0}, "a");
VectorND b = VectorND({0.0, 1.0, 0.0}, "b");
VectorND c = VectorND({0.0, 0.0, 1.0}, "c");
VectorND d = VectorND({0.0, 0.0,-1.0}, "c");

VectorND ma = VectorND({-1.0, 0.0, 0.0}, "-a");
VectorND mb = VectorND({0.0, -1.0, 0.0}, "-b");
VectorND mc = VectorND({0.0, 0.0, -1.0}, "-c");

/*Facets*/
Facet simplex0 = Facet(c, a, b, "simplex0");
Facet simplex1 = Facet(c, b, ma, "simplex1");
Facet simplex2 = Facet(c, ma, mb, "simplex2");
Facet simplex3 = Facet(c, mb, a, "simplex3");

Facet simplex4 = Facet(d, a, b, "simplex4");
Facet simplex5 = Facet(d, b, ma, "simplex5");
Facet simplex6 = Facet(d, ma, mb, "simplex6");
Facet simplex7 = Facet(d, mb, a, "simplex7");

Dodecahedron dodeca = Dodecahedron(1.0, center, "dodeca0");

MatrixDodecahedron listDodeca = MatrixDodecahedron(1, 20, "list_0ne");

/*Funciones para dibujar sin pensar en OpenGL*/
void Setup();
void Draw();
void updateProcessingProto();
void ProcessingProto();


//////////////////////////////////////
//                                  //
//                                  //
//        Processing Prototype      //
//                                  //
//                                  //
//////////////////////////////////////

/*Here we build our memory space and filled it with data using initObject methods corresponding to each class.*/
/*initObjects methods are functions that should build memory space and fill it with data*/


///////////////////     SETUP       ///////////////////////
void Setup() {

  if (ciclo == 0) {

          cout << "\n\n\n   ///PREPARING GNU_TOPOLOGY MEMORY//\n\n\n";
          
          for (int i = 0; i < 20; i++)
            listDodeca.dilateDodecahedron(i, vertexD[i], 0.25);
          
          dodeca.updateDodecahedron(0.5, VectorND({0.0, 0.0, 1.0}, "trash"), "updateTest");
          cout << "\n\n\n";


  }
}

//////////////////    UPDATE AUXILIARY FUNCTION ///////////////////

/*In this function we call any method that updates an object in a class.*/
/*Our goal is to define our memory space with initial values.*/
/*Having a memory space filled with initial values we are now able to update these initial values.*/

void updateProcessingProto() {

    if (ciclo > 0) {

      double c = 1.5 * cos(count);

      if (c < 0.0)
        for (int i = 0; i < 20; i++)
              listDodeca.dilateDodecahedron(i, vertexD[i], -c);
      else
        for (int i = 0; i < 20; i++)
            listDodeca.dilateDodecahedron(i, vertexD[i], c);
      //dodeca.dilateDodecahedron(center, 1.0 * c);
      //dodeca.explodeFaces(0.0);
    }
}

///////////////////     DRAW       ///////////////////////

/*Everything is made up of triangles and each class of geometrical objects have triangle drawing methods.*/
void Draw() {

  if (ciclo > 0) {
    /*Draw Here*/
    
    listDodeca.renderMatrixDodecahedronOpenGL();
    
  }
}


void ProcessingProto() {

  Setup();
  updateProcessingProto();
  Draw();
}

/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/

//////////////////////////////////////
//                                  //
//                                  //
//       OPENGL AS BACKGROUND       //
//                                  //
//                                  //
//////////////////////////////////////

/*Posición y color de luz*/
GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};

/*Funciones de OpenGL*/
void display(void);
void init(double theta);
void TimerFunction(int value);
void keyboard(unsigned char key, int x, int y);
void ProcessMenu(int value);

int main(int argc, char **argv)
{
  
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(1080, 720);
  glutCreateWindow(" ------- GNU_GEOM ------- ");
  ProcessMenu(1);
  init(count);

  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutTimerFunc(20, TimerFunction, 1);

  glutMainLoop();

  cout << "\n\n\n-->End of ProcessingProto\n\n\n";
  return 0;             /* ANSI C requires main to return int. */
}

void display(void) {
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0, 1.0, 1.0, 1.0);
  ProcessingProto();
  glutSwapBuffers();
}

void init(double theta)
{
  /* Setup data. */
  GLfloat ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
  GLfloat diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
  GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
  GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };

  /* Enable a single OpenGL light. */
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);

  /* Use depth buffering for hidden surface elimination. */
  glEnable(GL_DEPTH_TEST);
  glFrontFace(GL_CCW);
  //glEnable(GL_CULL_FACE);

  /*Enable color tracking*/
  glEnable(GL_COLOR_MATERIAL);

  /* Set material properties to follow glColor values*/
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

  /*All materials have high shine*/
  glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
  glMateriali(GL_FRONT, GL_SHININESS, 128);

  /* Setup the view of the cube. */
  glMatrixMode(GL_PROJECTION);
  gluPerspective( /* field of view in degree */ 40.0,
                              /* aspect ratio */ 1.0,
                                    /* Z near */ 0.5, 
                                    /* Z far */ 10000.0);
  glMatrixMode(GL_MODELVIEW);

  glEnable(GL_NORMALIZE);

  glutSwapBuffers();
}

void TimerFunction(int value) {

  count += 0.01;
  rotSpeed += 0.001;
  ciclo += 1;

  glLoadIdentity();
  gluLookAt( 4.0*cos(count*0.5), 4.0*sin(count*0.5), 4.0,      /* eye is at (0,0,5) */
             0.5*cos(count*2.5), 0.5*sin(count*2.5),  0.0,      /* center is at (0,0,0) */
             0.0,  0.0,  1.0);      /* up is in positive Y direction */

  //glRotatef(count, 0.0, 0.0, 1.0);

  if (count > 2 * M_PI) count = 0;
  if (ciclo > 100) ciclo = 1;

  glutPostRedisplay();
  glutTimerFunc(20, TimerFunction, 1);
}

void keyboard(unsigned char key, int x, int y) {
  GLint params[2];

  switch (key) {

    case 'b': 
      pass00 += 1;
      break;

  }

  glutPostRedisplay();
}

void ProcessMenu(int value) {
  switch(value) {
    case 1:
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glEnable(GL_BLEND);
      glEnable(GL_POINT_SMOOTH);
      glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
      glEnable(GL_LINE_SMOOTH);
      glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
      glEnable(GL_POLYGON_SMOOTH);
      glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
      break;

    case 2:
      glDisable(GL_BLEND);
      glDisable(GL_LINE_SMOOTH);
      glDisable(GL_POINT_SMOOTH);
      glDisable(GL_POLYGON_SMOOTH);
      break;
    
    default:
      break;
  }

  glutPostRedisplay();
}