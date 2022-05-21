#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_length 41

void reading()
{
    char *path_map;
    char line[max_length] = {0};
    path_map = "map.txt";
    FILE *file = fopen(path_map, "r");
    while (fgets(line, max_length, file))
    {
    }
    char *riga_1 = strtok(line, "!");
    char *riga_2 = strtok(NULL, "!");
    char *riga_3 = strtok(NULL, "!");
    char *riga_4 = strtok(NULL, "!");
    printf("%s\n%s\n%s\n%s", riga_1, riga_2, riga_3, riga_4);
    char token = 1;
    while (token != NULL)
    {
        //printf("%s\n", token);
        token = strtok(NULL, ",");
    }

}

