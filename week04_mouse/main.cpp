#include <GL/glut.h>
#include <stdio.h>
int mousex=0,mousey=0,n=0;///n���I
int mx[100],my[100];///�ΨӰO��
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);///����
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<n;i++)
    {
        glVertex2f((mx[i]-150)/150.0,-(my[i]-150)/150.0);
    }
    glEnd();
    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    ///printf("%d %d %d %d\n",button,state,x,y);
    mousex=x;mousey=y;
    if(state==GLUT_DOWN)
    {
        printf("  glVertex2f( (%d-150)/150.0), -(%d-150)/150.0));\n",x,y);
        n++;
        mx[n-1]=x; my[n-1]=y;///�}�C �ƥ��y��
    }
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("HW2 bonus");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
