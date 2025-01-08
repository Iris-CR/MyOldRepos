#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover rawfile\n");
        return 1;
    }
    char *fileName = argv[1];
    FILE *infile = fopen(fileName, "rb");
    if (infile == NULL)
    {
        printf("Could not open %s.\n", fileName);
        return 2;
    }
    BYTE buffer[512];
    int imgCount = 0;
    char outName[8];
    FILE *out = NULL;
    while (fread(&buffer, sizeof(buffer), 1, infile))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (imgCount == 0)
            {
                sprintf(outName, "%03i.jpg", imgCount);
                out = fopen(outName, "wb");
                fwrite(&buffer, sizeof(buffer), 1, out);
                imgCount++;
            }
            else if (imgCount != 0)
            {
                fclose(out);
                sprintf(outName, "%03i.jpg", imgCount);
                out = fopen(outName, "wb");
                fwrite(&buffer, sizeof(buffer), 1, out);
                imgCount++;
            }
        }
        else if (imgCount != 0)
        {
            fwrite(&buffer, sizeof(buffer), 1, out);
        }
    }
    fclose(out);
    fclose(infile);
    imgCount++;
}
