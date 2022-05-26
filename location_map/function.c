#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_length 41
#define max_length_colonna 5

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
    char *1_1= strtok (riga_1, ",");
    char *1_2= strtok (NULL, ",");
    char *1_3= strtok (NULL, ",");
    char *1_4= strtok (NULL, ",");
    char *1_5= strtok (NULL, ",");
    char *2_1= strtok (riga_2, ",");
    char *2_2= strtok (NULL, ",");
    char *2_3= strtok (NULL, ",");
    char *2_4= strtok (NULL, ",");
    char *2_5= strtok (NULL, ",");
    char *3_1= strtok (riga_3, ",");
    char *3_2= strtok (NULL, ",");
    char *3_3= strtok (NULL, ",");
    char *3_4= strtok (NULL, ",");
    char *3_5= strtok (NULL, ",");
    char *4_1= strtok (riga_4, ",");
    char *4_2= strtok (NULL, ",");
    char *4_3= strtok (NULL, ",");
    char *4_4= strtok (NULL,",");
    char *4_5= strtok (NULL, ",");
    printf

}

