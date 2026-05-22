#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct config {
    char InputFileName[64];
    int Options;
    char SectionName[64];
    unsigned long long Address;
} Config;

void config_parser(Config* config_ptr) {
    FILE* fp = fopen("config.txt", "r");
    if (fp == NULL) {
        printf("Error: config.txt 파일을 열 수 없습니다.\n");
        return;
    }

    char key[64];
    char dummy[4];

    while (!feof(fp)) {
        if (fscanf(fp, "%63s %3s", key, dummy) == 2) {

            if (strcmp(key, "InputFileName") == 0) {
                fscanf(fp, "%63s", config_ptr->InputFileName);
            } 
            else if (strcmp(key, "Options") == 0) {
                fscanf(fp, "%d", &config_ptr->Options);
            } 
            else if (strcmp(key, "SectionName") == 0) {
                fscanf(fp, "%63s", config_ptr->SectionName);
            } 
            else if (strcmp(key, "Address") == 0) {
                fscanf(fp, "%lli", &config_ptr->Address);
            }
            else {
                char skip[128];
                fscanf(fp, "%127s", skip);
            }
        }
    }

    fclose(fp);
}

int main(int argc, const char* argv[]) {
    Config config;
    config_parser(&config);

    printf("config: %s %d %s %llu\n", 
        config.InputFileName, 
        config.Options,
        config.SectionName,
        config.Address);
    return 0;
}

