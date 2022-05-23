#include <GL/glut.h>
#include <mmsystem.h>
#include <stdio.h>
void timer(int t){///t的單位是ms
    ///1000代表1秒、1500代表1.5秒
    printf("鬧鐘%d，起床了\n",t);
    PlaySound("do.wav",NULL,SND_ASYNC);
    printf("設定下一個鬧鐘");
    glutTimerFunc(2000,timer,t+1);///2秒後
    ///printf("設完鬧鐘，回鍋\n");
}
void display()
{

}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14 timer");

    glutTimerFunc(3000,timer,0);    ///3秒後，叫timer
    glutDisplayFunc(display);
    glutMainLoop();
}
