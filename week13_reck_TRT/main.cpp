#include <GL/glut.h>
float angle=45,oldX=0;
void mouse(int button,int  state,int x,int y)///mouse按下去
{
    oldX=x;
}
void motion(int x,int y)
{
    angle+=(x-oldX);
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.5,0.5,-0.5,-0.5);     ///白色的四邊形(Rectangle)座標
    glPushMatrix();
        glTranslatef(0.5,0.5,0);
        glRotatef(angle,0,0,1);///旋轉
        glTranslatef(-0.5,-0.4,0);///先把旋轉中心放中間
        glColor3f(1,0,0);  ///紅色
        glRectf(0.5,0.5,1.0,0.3);///四邊形座標
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc,char**argv)

{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week13_rect_TRT");
    glutMouseFunc(mouse);
    glutMotionFunc(motion)
    glutDisplayFunc(display);
    glutMainLoop();

}
