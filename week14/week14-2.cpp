#include <stdio.h>
int main()
{
    FILE * fout=fopen("file2.txt","w+");///write+ 順便新增
    fprintf(fout,"angle1 %d\n",999);
    fclose(fout);

    char line[200];
    int a;
    FILE * fin = fopen("file2.txt", "r");
    fscanf(fin, "%s %d",line,&a);
    printf("讀到了字串:%s 及整數%d\n",line,a);
    fclose(fin);
}
