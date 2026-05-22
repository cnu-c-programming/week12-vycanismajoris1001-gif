#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 3)
        return 0;

    FILE* fp_src = fopen(argv[1], "r");
    FILE* fp_dst = fopen(argv[2], "r");

    while ((fp = fgetc(src)) != EOF) {
        fputc(fp, dst);
    }


    fclose(fp_scr);
    fclose(fp_dst);


}

