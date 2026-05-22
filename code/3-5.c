#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }


    int sum = 0;
    int num;
    
    char invalid_inputs[100][256];
    int invalid_count = 0;

    while (!feof(fp)) {
        int result = fscanf(fp, "%d", &num);

        if (result == 1) {
            sum += num;
        } 
        else if (result == 0) {
            if (invalid_count < 100) {
                if (fscanf(fp, "%255s", invalid_inputs[invalid_count]) == 1) {
                    invalid_count++;
                }
            } else {
                char dummy[256];
                fscanf(fp, "%255s", dummy);
            }
        } 
        else {
            break;
        }
    }

    printf("sum: %d\n", sum);

    for (int i = 0; i < invalid_count; i++) {
        printf("invalid input %s\n", invalid_inputs[i]);
    }
    return 0;
}
