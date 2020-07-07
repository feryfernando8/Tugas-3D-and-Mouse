#include <windows.h>
#include <stdlib.h>
#include <gl/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char,int,int);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("Fery Fernando - 672018116");
    init();
    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    //glutIdleFunc(idle);
    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);
}

void tampil(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    glPushMatrix();

    //depan
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-30.0, -15.0, 25.0);
    glVertex3f(-30.0, 15.0, 25.0);
    glVertex3f(0, 15.0, 25.0);
    glVertex3f(0, -15.0, 25.0);
    glEnd();
    //pintu
    glBegin(GL_QUADS);
    glColor3f(0.1f,0.0f,0.0f);
    glVertex3f(-16.5,-15.0,25.2);
    glVertex3f(-16.5,12.0,25.2);
    glVertex3f(-7,12,25.2);
    glVertex3f(-7,-15,25.2);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-1,-9.0,25.2);
    glVertex3f(-1,9.0,25.2);
    glVertex3f(-6.5,9,25.2);
    glVertex3f(-6.5,-9,25.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-22.5,-9.0,25.2);
    glVertex3f(-22.5,9.0,25.2);
    glVertex3f(-17,9,25.2);
    glVertex3f(-17,-9,25.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-23.5,-9.0,25.2);
    glVertex3f(-23.5,9.0,25.2);
    glVertex3f(-29,9,25.2);
    glVertex3f(-29,-9,25.2);
    glEnd();

    //depan kedua
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(0.0, -15.0, 0.0);
    glVertex3f(0.0, 15.0, 0.0);
    glVertex3f(30, 15.0, 0.0);
    glVertex3f(30, -15.0, 0.0);
    glEnd();
    //pintu garasi
    glBegin(GL_QUADS);
    glColor3f(0.1f,0.0f,0.0f);
    glVertex3f(17,-15.0,0.1);
    glVertex3f(17,10.0,0.1);
    glVertex3f(29.5,10,0.1);
    glVertex3f(29.5,-15,0.1);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(6,-9.0,0.1);
    glVertex3f(6,9.0,0.1);
    glVertex3f(16,9,0.1);
    glVertex3f(16,-9,0.1);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-30.0, -15.0, -15.0);
    glVertex3f(-30.0, 15.0, -15.0);
    glVertex3f(30.0, 15.0, -15.0);
    glVertex3f(30.0, -15.0, -15.0);
    glEnd();

    //atas kedua pertama (atap)
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-30.0, 15.0+15.0, -7.5);
    glVertex3f(-30.0, -15.0+30.0, 0.0);
    glVertex3f(30.0, -15.0+30.0, 0.0);
    glVertex3f(30.0, 15.0+15.0, -7.5);
    glEnd();

    //atas kedua KEDUA (atap)
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-30.0, 15.0+15.0, -7.5);
    glVertex3f(-30.0, -15.0+30.0, -15.0);
    glVertex3f(30.0, -15.0+30.0, -15.0);
    glVertex3f(30.0, 15.0+15.0, -7.5);
    glEnd();

    //tutup atas pertama
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(30,30,-7.5);
    glVertex3f(30,15,0);
    glVertex3f(30,15,-15);
    glEnd();

    //tutup atas kedua
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-30,30,-7.5);
    glVertex3f(-30,15,0);
    glVertex3f(-30,15,-15);
    glEnd();



    //kanan
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(0.0, 15.0, 25.0);
    glVertex3f(0.0, -15.0, 25.0);
    glVertex3f(0.0, -15.0, 0.0);
    glVertex3f(0.0, 15.0, 0.0);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(0.2, 9.0, 22.0);
    glVertex3f(0.2, -9.0, 22.0);
    glVertex3f(0.2, -9.0, 17.0);
    glVertex3f(0.2, 9.0, 17.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(0.2, 9.0, 16.5);
    glVertex3f(0.2, -9.0, 16.5);
    glVertex3f(0.2, -9.0, 11.5);
    glVertex3f(0.2, 9.0, 11.5);
    glEnd();
    //pintu
    glBegin(GL_QUADS);
    glColor3f(0.1f,0.0f,0.0f);
    glVertex3f(0.2, 12.0, 11.0);
    glVertex3f(0.2, -15.0, 11.0);
    glVertex3f(0.2, -15.0, 1.40);
    glVertex3f(0.2, 12.0, 1.0);
    glEnd();


    //kanan kedua
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(30.0, 15.0, 0.0);
    glVertex3f(30.0, -15.0, 0.0);
    glVertex3f(30.0, -15.0, -15.0);
    glVertex3f(30.0, 15.0, -15.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-30.0, 15.0, 25.0);
    glVertex3f(-30.0, -15.0, 25.0);
    glVertex3f(-30.0, -15.0, -15.0);
    glVertex3f(-30.0, 15.0, -15.0);
    glEnd();
    //jendela kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-30.2, 9.0, 24.0);
    glVertex3f(-30.2, -9.0, 24.0);
    glVertex3f(-30.2, -9.0, 19.0);
    glVertex3f(-30.2, 9.0, 19.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-30.2, 9.0, 18.0);
    glVertex3f(-30.2, -9.0, 18.0);
    glVertex3f(-30.2, -9.0, 13.0);
    glVertex3f(-30.2, 9.0, 13.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-30.2, 9.0, 10.0);
    glVertex3f(-30.2, -9.0, 10.0);
    glVertex3f(-30.2, -9.0, 5.0);
    glVertex3f(-30.2, 9.0, 5.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-30.2, 9.0, 4.0);
    glVertex3f(-30.2, -9.0, 4.0);
    glVertex3f(-30.2, -9.0, -1.0);
    glVertex3f(-30.2, 9.0, -1.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-30.2, 9.0, -3.0);
    glVertex3f(-30.2, -9.0, -3.0);
    glVertex3f(-30.2, -9.0, -8.0);
    glVertex3f(-30.2, 9.0, -8.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-30.2, 9.0, -9.0);
    glVertex3f(-30.2, -9.0, -9.0);
    glVertex3f(-30.2, -9.0, -14.0);
    glVertex3f(-30.2, 9.0, -14.0);
    glEnd();

    //atas kanan
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-15.0, 15.0+15.0, 25.0);
    glVertex3f(0.0, -15.0+30.0, 25.0);
    glVertex3f(0.0, -15.0+30.0, -7.0);
    glVertex3f(-15.0, 15.0+15.0, -7.0);
    glEnd();

    //atas kiri
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-30.0, -15.0+30.0, 25.0);
    glVertex3f(-15.0, 15.0+15.0, 25.0);
    glVertex3f(-15.0, 15.0+15.0, -7.0);
    glVertex3f(-30.0, -15.0+30.0, -7.0);
    glEnd();

    //atas tampak depan
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-15.0, 30.0, 25.0);
    glVertex3f(-30.0, 15.0, 25.0);
    glVertex3f(0.0, 15.0, 25.0);
    glEnd();

    //atas tampak depan kedua
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-15.0, 30.0, 0.0);
    glVertex3f(-30.0, 15.0, 0.0);
    glVertex3f(0.0, 15.0, 0.0);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(0.0,1.5,0.0);
    glVertex3f(-30.0, -15.0, 25.0);
    glVertex3f(0.0, -15.0, 25.0);
    glVertex3f(0.0, -15.0, -15.0);
    glVertex3f(-30.0, -15.0, -15.0);
    glEnd();

    //bawah kedua
    glBegin(GL_QUADS);
    glColor3f(0.0,1.5,0.0);
    glVertex3f(0.0, -15.0, .0);
    glVertex3f(30.0, -15.0, .0);
    glVertex3f(30.0, -15.0, -15.0);
    glVertex3f(0.0, -15.0, -15.0);
    glEnd();

//kursi
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-29.0, -12.5, 25.0);
    glVertex3f(-24.0, -12.5, 25.0);
    glVertex3f(-24.0, -12.5, 15.0);
    glVertex3f(-29.0, -12.5, 15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-29.0, -12.5, 25.0);
    glVertex3f(-29.5, -5.5, 25.0);
    glVertex3f(-29.5, -5.5, 15.0);
    glVertex3f(-29.0, -12.5, 15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-29.0, -12.5, 25.0);
    glVertex3f(-29.0, -15.0, 25.0);
    glVertex3f(-24.0, -15.0, 25.0);
    glVertex3f(-24.0, -12.5, 25.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-29.0, -12.5, 15.0);
    glVertex3f(-29.0, -15.0, 15.0);
    glVertex3f(-24.0, -15.0, 15.0);
    glVertex3f(-24.0, -12.5, 15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-29.0, -12.5, 25.0);
    glVertex3f(-29.0, -15.0, 25.0);
    glVertex3f(-29.0, -15.0, 15.0);
    glVertex3f(-29.0, -12.5, 15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-24.0, -12.5, 25.0);
    glVertex3f(-24.0, -15.0, 25.0);
    glVertex3f(-24.0, -15.0, 15.0);
    glVertex3f(-24.0, -12.5, 15.0);
    glEnd();

//lemari
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-29.0, -15.0, 13.0);
    glVertex3f(-24.0, -15.0, 13.0);
    glVertex3f(-24.0, -15.0, 0.0);
    glVertex3f(-29.0, -15.0, 0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-29.0, 7.0, 13.0);
    glVertex3f(-24.0, 7.0, 13.0);
    glVertex3f(-24.0, 7.0, 0.0);
    glVertex3f(-29.0, 7.0, 0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-29.0, -15.0, 13.0);
    glVertex3f(-29.0, 7.0, 13.0);
    glVertex3f(-24.0, 7.0, 13.0);
    glVertex3f(-24.0, -15.0, 13.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(.0,0.5,0.0);
    glVertex3f(-29.0, -15.0, 6.5);
    glVertex3f(-29.0, 7.0, 6.5);
    glVertex3f(-24.0, 7.0, 6.5);
    glVertex3f(-24.0, -15.0, 6.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(-29.0, -15.0, .0);
    glVertex3f(-29.0, 7.0, .0);
    glVertex3f(-24.0, 7.0, .0);
    glVertex3f(-24.0, -15.0, .0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-29.0, 7.0, 13.0);
    glVertex3f(-29.0, -15.0, 13.0);
    glVertex3f(-29.0, -15.0, .0);
    glVertex3f(-29.0, 7.0, .0);
    glEnd();

//Meja
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-22.0, -12.5, 25.0);
    glVertex3f(-17.0, -12.5, 25.0);
    glVertex3f(-17.0, -12.5, 15.0);
    glVertex3f(-22.0, -12.5, 15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-22.0, -15.0, 24.5);
    glVertex3f(-22.0, -12.5, 24.5);
    glVertex3f(-17.0, -12.5, 24.5);
    glVertex3f(-17.0, -15.0, 24.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-22.0, -15.0, 15.5);
    glVertex3f(-22.0, -12.5, 15.5);
    glVertex3f(-17.0, -12.5, 15.5);
    glVertex3f(-17.0, -15.0, 15.5);
    glEnd();

//Tempat tidur
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-29.5, -12.5, -2.0);
    glVertex3f(-12.0, -12.5, -2.0);
    glVertex3f(-12.0, -12.5, -14.0);
    glVertex3f(-29.5, -12.5, -14.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-29.5, -15.0, -2.0);
    glVertex3f(-29.5, -5.0, -2.0);
    glVertex3f(-29.5, -5.0, -14.0);
    glVertex3f(-29.5, -15.0, -14.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(-28.0, -15.0, -2.0);
    glVertex3f(-28.0, -5.0, -2.0);
    glVertex3f(-28.0, -5.0, -14.0);
    glVertex3f(-28.0, -15.0, -14.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-29.5, -15.0, -14.0);
    glVertex3f(-29.5, -5., -14.0);
    glVertex3f(-28.0, -5., -14.0);
    glVertex3f(-28.0, -15.0, -14.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(-29.5, -15.0, -2.0);
    glVertex3f(-29.5, -5., -2.0);
    glVertex3f(-28.0, -5., -2.0);
    glVertex3f(-28.0, -15.0, -2.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-29.5, -15.0, -14.0);
    glVertex3f(-29.5, -12.5, -14.0);
    glVertex3f(-12.0, -12.5, -14.0);
    glVertex3f(-12.0, -15.0, -14.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-29.5, -15.0, -2.0);
    glVertex3f(-29.5, -12.5, -2.0);
    glVertex3f(-12.0, -12.5, -2.0);
    glVertex3f(-12.0, -15.0, -2.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-29.5, -5., -2.0);
    glVertex3f(-28.0, -5., -2.0);
    glVertex3f(-28.0, -5., -14.0);
    glVertex3f(-29.5, -5., -14.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(-12.0, -15.0, -2.0);
    glVertex3f(-12.0, -12.5, -2.0);
    glVertex3f(-12.0, -12.5, -14.0);
    glVertex3f(-12.0, -15.0, -14.0);
    glEnd();

//tv dan tempatnya
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(30.0, -15.0, -2.0);
    glVertex3f(30.0, -10.0, -2.0);
    glVertex3f(30.0, -10.0, -14.0);
    glVertex3f(30.0, -15.0, -14.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(27.0, -15.0, -2.0);
    glVertex3f(27.0, -10.0, -2.0);
    glVertex3f(27.0, -10.0, -14.0);
    glVertex3f(27.0, -15.0, -14.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(30.0, -15.0, -14.0);
    glVertex3f(30.0, -10.5, -14.0);
    glVertex3f(27.0, -10.5, -14.0);
    glVertex3f(27.0, -15.0, -14.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(30.0, -15.0, -2.0);
    glVertex3f(30.0, -10.5, -2.0);
    glVertex3f(27.0, -10.5, -2.0);
    glVertex3f(27.0, -15.0, -2.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(30.0, -10., -2.0);
    glVertex3f(27.0, -10., -2.0);
    glVertex3f(27.0, -10., -14.0);
    glVertex3f(30.0, -10., -14.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(.0,.0,.0);
    glVertex3f(29., -8., -2.0);
    glVertex3f(28., -10., -2.0);
    glVertex3f(28., -10., -14.0);
    glVertex3f(29., -8., -14.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(.0,.0,.0);
    glVertex3f(29., -4., -2.0);
    glVertex3f(28., -2., -2.0);
    glVertex3f(28., -2., -14.0);
    glVertex3f(29., -4., -14.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(29., -4.0, -2.0);
    glVertex3f(29., -8.0, -2.0);
    glVertex3f(29., -8.0, -14.0);
    glVertex3f(29., -4.0, -14.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0,.0,.0);
    glVertex3f(28., -2.0, -2.0);
    glVertex3f(28., -10.0, -2.0);
    glVertex3f(28., -10.0, -14.0);
    glVertex3f(28., -2.0, -14.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(29.0, -8.0, -14.);
    glVertex3f(29.0, -4., -14.);
    glVertex3f(28.0, -2., -14.);
    glVertex3f(28.0, -10.0, -14.);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(29.0, -8.0, -2.);
    glVertex3f(29.0, -4., -2.);
    glVertex3f(28.0, -2., -2.);
    glVertex3f(28.0, -10.0, -2.);
    glEnd();


    glPopMatrix();
    glutSwapBuffers();
}

void idle()
{
    if(!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y)
{
    if(mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void keyboard(unsigned char key,int x, int y)
{
    switch(key)
    {

    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0, 0.0, 3.0);
        break;
    case '7':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case '9':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 1;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 0;
            glEnable(GL_DEPTH_TEST);
        }

    }
    tampil();

}

void ukuran(int lebar, int tinggi)
{
    if(tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar/tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
