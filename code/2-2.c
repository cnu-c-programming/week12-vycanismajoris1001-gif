#include <stdio.h>
#include <string.h>

typedef struct student {
    char name[64];
    int score;
} Student;

int main(int argc, const char* argv[]) {
    FILE* fp = fopen("student.txt", "r");
    int count = 0;
    Student students[64];
    



    int max = 0;
    float avg = 0;
    int sum = 0;

    while (!feof(fp)) {
        if (count >= 64) {
            break;
        }


        if (fscanf(fp, "%63s %d", students[count].name, &students[count].score) == 2) {
            
            if (students[count].score > max) {
                max = students[count].score;
            }
            sum += students[count].score;
            
            count++; 
        }
    }

    if (count > 0) {
        avg = (float)sum / count; 
    }

    printf("max: %d\n", max);
    printf("avg: %.2f\n", avg);

    fclose(fp);

    return 0;
}

