///week15_angles_TRT_again
#include <GL/glut.h>
#include <stdio.h> ///為了 printf, fprintf, fopen, fclose ..
float angle[20], oldX=0;
int angleID=0;///0:第0個關節, 1:第1個關節, 2:第2個關節
FILE * fout = NULL, * fin = NULL;
void myWrite(){
    if(fin!=NULL){
        fclose(fin);
        fin=NULL;
        ///最好這裡再做個警告, 因為整個file.txt將被清空!!
    }
    if(fout==NULL) fout = fopen("file.txt", "w+");
    for(int i=0; i<20; i++){
        printf(      "%.2f ", angle[i] );
        fprintf(fout, "%.2f ", angle[i] );
    }
    printf("\n");
    fprintf(fout, "\n");///少了fclose,因為不想要才印一行,就結束。想寫多行一些
}
float NewAngle[20],OldAngle[20];
void myRead(){
    if(fout!=NULL) { fclose(fout); fout=NULL; }///還在讀的檔案要關掉
    if(fin==NULL) fin = fopen("file.txt", "r");
    for(int i=0; i<20; i++){
        OldAngle[i]=NewAngle[i];
        fscanf(fin, "%f",&NewAngle[i]);
        //fscanf(fin, "%f", &angle[i] );
    }
    glutPostRedisplay();///重畫畫面!!
}
void myInterpolate(float alpha)
{
    for(int i=0;i<20;i++)
    {
        angle[i]=alpha*NewAngle[i]+(1-alpha)*OldAngle[i];
        printf("%.2f",angle[i]);
    }
    printf("\n");
    glutPostRedisplay();
}
///float alpha=0;
void timer(int t)
{
    float alpha = (t%100)/100.0;
    if(t%100==0)myRead();
    myInterpolate(alpha);
    glutTimerFunc(33,timer,t+1);
}
void keyboard( unsigned char key, int x, int y){
    if(key=='p'){
        myRead();   ///先讀一行
        glutTimerFunc(0,timer,0);   ///馬上開始播動畫
        ///myInterpolate(alpha);
        /// alpha=(alpha+0.1);
        /// if(alpha>1)alpha=alpha-1;
    }
    if( key=='r' ) myRead();
    if( key=='s' ) myWrite();///save
    if( key=='0' ) angleID=0;///預設是這一個
    if( key=='1' ) angleID=1;
    if( key=='2' ) angleID=2;
    if( key=='3' ) angleID=3;
}///用keyboard的按鍵,來決定等一下 motion()裡要改的 angle[i] 是哪一個
void mouse(int button, int state, int x, int y){///mouse按下去
    oldX = x;
}
void motion(int x, int y){
    angle[angleID] += (x-oldX);
    ///myWrite();///沒有必要一直寫檔啦
    oldX = x;
    glutPostRedisplay();
}
#include <math.h>
void myCircle(float x, float y)
{
    glBegin(GL_POLYGON);
        for(float a=0; a<3.1415*2; a+=0.1){
            glVertex2f( x + 0.1*cos(a),  y + 0.1*sin(a) );
        }
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3, 0.5, -0.3, -0.2);///身體,瘦身

    glPushMatrix();  ///右半邊
        glTranslatef( 0.3, 0.5, 0);///(3) 等下要掛在0.5,0.5
        glRotatef( angle[0], 0, 0, 1);///(2) 旋轉
        glTranslatef( -0.3, -0.4, 0);///(1)先把旋轉中心放正中心

        glColor3f(1,0,0);///紅色的
        glRectf(0.3, 0.5, 0.8, 0.3);///右上手臂
        myCircle(0.3, 0.4); ///圓心在 0.3, 0.4

        glPushMatrix();
            glTranslatef(0.8, 0.4, 0); ///(3) 把下手肘掛在關節上
            glRotatef( angle[1], 0, 0, 1); ///(2) 旋轉
            glTranslatef(-0.8, -0.4, 0 );///(1) 把下手肘的旋轉中心,放正中心
            glColor3f(0,1,0);///綠色的
            glRectf(0.8, 0.5, 1.1, 0.3);///再畫右下手肘
            myCircle(0.8, 0.4); ///圓心 0.8 0.4
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();  ///左半邊
        glTranslatef( -0.3, 0.5, 0);///(3) 等下要掛在0.5,0.5
        glRotatef( angle[2], 0, 0, 1);///(2) 旋轉
        glTranslatef( +0.3, -0.4, 0);///(1)先把旋轉中心放正中心
        glColor3f(1,0,0);///紅色的
        glRectf(-0.3, 0.5, -0.8, 0.3);///左上手臂
        glPushMatrix();
            glTranslatef(-0.8, 0.4, 0); ///(3) 把下手肘掛在關節上
            glRotatef( angle[3], 0, 0, 1); ///(2) 旋轉
            glTranslatef(+0.8, -0.4, 0 );///(1) 把下手肘的旋轉中心,放正中心
            glColor3f(0,1,0);///綠色的
            glRectf(-0.8, 0.5, -1.1, 0.3);///再畫左下手肘
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week15 angles TRT again");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);///不放Idle
    glutMainLoop();
}
