#include <GL/glut.h>
float angle=0,oldx=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix(); ///備份矩陣
        glRotatef(angle,0,0,1); ///轉180度
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    oldx=x;
}
void motion(int x,int y)
{
    angle+=(x-oldx);
    angle=x;
    display();
}
int main(int argc,char**argv)
{///進階的內函式
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05 Rotate");///建視窗

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
    glutMainLoop();

}
