#include <windows.h>
#include <stdio.h>
int main()
{
    printf("現在在PlaySound()前\n");
    PlaySound("07042111.wav",NULL,SND_SYNC);
    printf("現在在PlaySound()後\n");
    int N;
    scanf("%d",&N); ///等你輸入數字
}

