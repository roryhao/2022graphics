#include <GL/glut.h>
#include <stdio.h>  ///���Fprintf�Bfprintf�Bfopen�Bfclose
float angle[20],oldX=0;
int angleID=0;  ///0:��0�����`,1:��1�����`,2:��2�����`
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
            fclose(fout);///�ΨӽT�{���bŪ���ɮ׬O�_����
            fout=NULL;
    }
    if(fin==NULL)fin = fopen("file.txt","r");
    for(int i=0;i<20;i++){
        fscanf(fin,"%f",&angle[i]);
    }
    glutPostRedisplay(); ///���e�e��
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='r')myRead();
    if(key=='s')myWrite();///save
    if(key=='0')angleID=0;
    if(key=='1')angleID=1;
    if(key=='2')angleID=2;
    if(key=='3')angleID=3;
}///�Ϋ���ӨM�wmotion()�̧諸angle[i]�O���@��
void mouse(int button,int  state,int x,int y)///mouse���U�h
{
    oldX=x;
}
void motion(int x,int y)
{
    angle[angleID]+=(x-oldX);
    ///myWrite();   ///�S�����n�@���g��
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.3,0.5,-0.3,-0.2);     ///������u�@�I�A���G����}�F

    glPushMatrix(); ///�k�b��
        glTranslatef(0.3,0.5,0);///�γo�ӽվ���u
        glRotatef(angle[0],0,0,1);///����
        glTranslatef(-0.3,-0.4,0);///������त�ߩ񤤶�
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.8,0.3);///�W���u
        glPushMatrix();
            glTranslatef(0.8,0.4,0);///3.��U��y���b���`�W
            glRotatef(angle[1],0,0,1);///2.����
            glTranslatef(-0.8,-0.4,0);///1.��U��y�����त�ߩ񥿤���
            glColor3f(0,1,0);///���
            glRectf(0.8,0.5,1.1,0.3);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix(); ///���b��
        glTranslatef(-0.3,0.5,0);///�γo�ӽվ���u
        glRotatef(angle[2],0,0,1);///����
        glTranslatef(+0.3,-0.4,0);///������त�ߩ񤤶�
        glColor3f(1,0,0);
        glRectf(-0.3,0.5,-0.8,0.3);///���W���u
        glPushMatrix();
            glTranslatef(-0.8,0.4,0);///3.��U��y���b���`�W
            glRotatef(angle[3],0,0,1);///2.����
            glTranslatef(+0.8,-0.4,0);///1.�⥪�U��y�����त�ߩ񥿤���
            glColor3f(0,1,0);///���
            glRectf(-0.8,0.5,-1.1,0.3);///�A�e���U��y
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
