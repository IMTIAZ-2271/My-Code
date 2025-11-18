#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp = fopen("self_copying_program.c", "rb"); // rb not r
    if (!fp)
    {
        return 1;
    }
    char *buffer;
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    rewind(fp);
    buffer = (char *)malloc(fsize);
    fread(buffer, 1, fsize, fp);
    FILE *fp2 = fopen("out.txt", "wb"); // wb not w
    if (!fp2)
    {
        return 1;
    }
    // fwrite(buffer,1,fsize,fp2);//For direct copy
    for (int i = fsize - 1; i >= 0; i--)
    { // For reversing the content
        fputc(buffer[i], fp2);
    }
    fclose(fp);
    fclose(fp2);
    free(buffer);
    return 0;
}
