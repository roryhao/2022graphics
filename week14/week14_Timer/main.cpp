#include <GL/glut.h>
#include <mmsystem.h>
#include <stdio.h>
void timer(int t){///t�����Oms
    ///1000�N��1��B1500�N��1.5��
    printf("�x��%d�A�_�ɤF\n",t);
    PlaySound("do.wav",NULL,SND_ASYNC);
    printf("�]�w�U�@�Ӿx��");
    glutTimerFunc(2000,timer,t+1);///2���
    ///printf("�]���x���A�^��\n");
}
void display()
{

}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14 timer");

    glutTimerFunc(3000,timer,0);    ///3���A�stimer
    glutDisplayFunc(display);
    glutMainLoop();
}
