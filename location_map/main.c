#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_length 10

void main()
{
    char *path_map;
    char line[max_length] = {0};
    path_map = "map.txt";
    FILE *file = fopen(path_map, "r");
    while (fgets(line, max_length, file))
    {
        printf("%s", line);
    }
}
