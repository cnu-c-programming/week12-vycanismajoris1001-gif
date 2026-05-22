#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 2)
        return 0;

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: 파일을 열 수 없습니다: %s\n", argv[1]);
        return 1;
    }

    int alphabet_counts[26] = {0};
    char ch;

    while (!feof(fp)) {
        if (fscanf(fp, "%c", &ch) == 1) {
            if (ch >= 'a' && ch <= 'z') {
                alphabet_counts[ch - 'a']++;
            }
        }
    }

    printf("--- 소문자 알파벳 빈도수 결과 ---\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, alphabet_counts[i]);
    }



    fclose(fp);
}

