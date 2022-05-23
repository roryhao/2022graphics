#include <stdio.h>
int main()
{
    FILE * fout=fopen("file.txt","w+");///write+ ¶¶«K·s¼W

    printf("Hello World\n");
   fprintf(fout,"Hello World\n");

   fclose(fout);
}
