#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char line[512];
    long x = 0, y = 0, aim = 0;
    FILE *file = fopen(argv[1], "r");

    while(fgets(line, sizeof(line), file))
    {
        char *token = strtok(line, " ");
        char direction = token[0] & ~32;
        long value = atol(strtok(NULL, " "));
        switch(direction)
        {
            case 'U':
                y -= value;
                break;
            case 'D':
                y += value;
                break;
            case 'F':
                x += value;
                break;
        }
    }

    printf("%ld\n", x*y);
    fclose(file);
    return 0;
}
