#include <GL/glut.h>
#include <stdio.h>  ///為了printf、fprintf、fopen、fclose
float angle[20],oldX=0;
int angleID=0;  ///0:第0個關節,1:第1個關節,2:第2個關節
FILE * fout = NULL,* fin = NULL;
void myWrite()
{

    if(fout==NULL)fout=fopen("file.txt","w+");
    for(int i=0;i<20;i++)
    {
         printf(     "%.2f",angle[i]);
        fprintf(fout,"%.2f",angle[i]);
    }
    printf("\n");
    fprintf(fout,  "\n");
}
void myRead()
{
    if(fout!=NULL){
            fclose(fout);///用來確認正在讀的檔案是否關閉
            fout=NULL;
    }
    if(fin==NULL)fin = fopen("file.txt","r");
    for(int i=0;i<20;i++){
        fscanf(fin,"%f",&angle[i]);
    }
    glutPostRedisplay(); ///重畫畫面
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='r')myRead();
    if(key=='s')myWrite();///save
    if(key=='0')angleID=0;
    if(key=='1')angleID=1;
    if(key=='2')angleID=2;
    if(key=='3')angleID=3;
}///用按鍵來決定motion()裡改的angle[i]是哪一個
void mouse(int button,int  state,int x,int y)///mouse按下去
{
    oldX=x;
}
void motion(int x,int y)
{
    angle[angleID]+=(x-oldX);
    ///myWrite();   ///沒有必要一直寫檔
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.3,0.5,-0.3,-0.2);     ///讓身體短一點，結果手分開了

    glPushMatrix(); ///右半邊
        glTranslatef(0.3,0.5,0);///用這個調整手臂
        glRotatef(angle[0],0,0,1);///旋轉
        glTranslatef(-0.3,-0.4,0);///先把旋轉中心放中間
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.8,0.3);///上手臂
        glPushMatrix();
            glTranslatef(0.8,0.4,0);///3.把下手肘掛在關節上
            glRotatef(angle[1],0,0,1);///2.旋轉
            glTranslatef(-0.8,-0.4,0);///1.把下手肘的旋轉中心放正中心
            glColor3f(0,1,0);///綠色
            glRectf(0.8,0.5,1.1,0.3);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix(); ///左半邊
        glTranslatef(-0.3,0.5,0);///用這個調整手臂
        glRotatef(angle[2],0,0,1);///旋轉
        glTranslatef(+0.3,-0.4,0);///先把旋轉中心放中間
        glColor3f(1,0,0);
        glRectf(-0.3,0.5,-0.8,0.3);///左上手臂
        glPushMatrix();
            glTranslatef(-0.8,0.4,0);///3.把下手肘掛在關節上
            glRotatef(angle[3],0,0,1);///2.旋轉
            glTranslatef(+0.8,-0.4,0);///1.把左下手肘的旋轉中心放正中心
            glColor3f(0,1,0);///綠色
            glRectf(-0.8,0.5,-1.1,0.3);///再畫左下手肘
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char**argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week15_TRT_angle_write");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();

}
