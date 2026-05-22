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
        return; 
    }

    char line[256];

    while (!feof(fp)) {
        if (fgets(line, sizeof(line), fp) == NULL) {
            break;
        }

        if (strstr(line, "InputFileName") != NULL) {
            sscanf(line, "%*[^=]=%s", config_ptr->InputFileName);
        } 
        else if (strstr(line, "Options") != NULL) {
            sscanf(line, "%*[^=]=%d", &config_ptr->Options);
        } 
        else if (strstr(line, "SectionName") != NULL) {
            sscanf(line, "%*[^=]=%s", config_ptr->SectionName);
        } 
        else if (strstr(line, "Address") != NULL) {
            if (strstr(line, "0x") != NULL || strstr(line, "0X") != NULL) {
                sscanf(line, "%*[^=]=%llx", &config_ptr->Address);
            } else {
                sscanf(line, "%*[^=]=%llu", &config_ptr->Address);
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

