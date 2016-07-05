/* test file reading and writing */

#include <stdio.h>

int main()
{
    char tmpBuf[256];
    char first2char[8];
    long int n = 123456;

    //char *p = &tmpBuf[-1];
    char *p = tmpBuf - 1;

    printf("%d\n", n);

    FILE *infp = fopen("input.txt", "r");
    FILE *outfp = fopen("output.txt", "w");

    if(!infp) printf("error to open input file\n");
    if(!outfp) printf("error to open output file\n");

    while(fgets(tmpBuf, 256, infp)) 
    {
        if (!feof(infp)) {
            printf("%s\n", tmpBuf);
            sprintf(first2char, "%c %c\n", p[1], p[2]);
            //sprintf(first2char, "%c %c\n", tmpBuf[0], tmpBuf[1]);
            fputs(first2char, outfp);
        }
        fputs(tmpBuf, outfp);
    }


    return 0;
}
