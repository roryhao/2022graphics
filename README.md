## 2022graphics
# 把修改的資料，推送到雲端
cd desktop 進人貞面
git clone https：1/你的倉庫網址
1. cd 2022graphics 進入你的倉庫
2. git status 看你的狀況（红的，多了目錄）
3. git add .把檔案加進帳冊
4. git status 再看一次（綠的）這裡要加入
            git config --global user. email "你的email"
            git config --global user.name“你的名”
            git commit -m “上傳第1週”
5. git push 推送到雲端，BUT要登入
6 在Chrome登陸GitHub

## 基本設定

```c
#include <GL/glut.h>

void display()

{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


    glutSwapBuffers();

}

int main(int argc,char**argv)

{

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("自行設定");



    glutDisplayFunc(display);

    glutMainLoop();

}
```
