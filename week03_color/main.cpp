
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,0);
    glutSolidTeapot(0.3); ///0.3��߯���

    glutSwapBuffers();///�洫2����buffer
}
int main(int argc,char**argv)
{///�i�������禡
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03������");///�ص���

    glutDisplayFunc(display);///���ѥΨӵe�Ϫ��禡

    glutMainLoop();///�D�n���j��
    return 0;
}
