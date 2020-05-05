/*************************************************************************
	> File Name: byyl.c
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年10月09日 星期三 15时47分13秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int i = 0;
FILE *fp, *rfp;
char buffer[255] = {0};

int WriteFile (char* filename) {
    char a;
    int count = 0;
    if (NULL == (fp = fopen (filename, "w"))) {
        printf ("文件打开失败!"); exit (0);
    }
    for (; i < 255; i++) {
        scanf ("%c", &a);
        if (a == '0') return i;
        fprintf (fp, "%c", a);
    }
    fclose (fp);
    return i;
}

int ReadBuffer () {
    int flen = 0;
    int j = 0;
    char ch;
    char *filename = "abc.txt";
    printf ("文件名: abc.txt \n");
    if ((rfp = fopen ("abc.txt", "r")) == NULL) {
        printf ("文件打开失败 ！"); exit (0);
    }
    for (; j < 255; ++j) {
        ch = fgetc (rfp);
        if (feof (rfp)) {
            i = j; break;
        }
        buffer[j] = ch;
    }
    for (; flen < j; flen++) {
        printf ("%c", buffer[flen]);
    }
    printf ("\n");
    return 1;
}

int main () {
    char *filename = {"abc.txt"};
    int j = 0;
    char creatfile = '0';
    printf ("1、输入c创建文件\n");
    printf ("2、输入o打开文件\n");
    scanf ("%c", &creatfile);
    if (creatfile == 'c') WriteFile (filename);
    if (creatfile == 'o') ReadBuffer ();

    return 0;
}
