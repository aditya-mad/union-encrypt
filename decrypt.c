#include <stdio.h>
#include <stdlib.h>

union Data
{
    int num;
    char letter;
};

char NUMIPFILE[] = "num_ip.txt";
char TEXTOUTPUT[] = "text_output.txt";

int decrypt();
char getChar(int);

int main()
{
    return decrypt();
}

char getChar(int code)
{
    union Data *storeData = (union Data *)malloc(sizeof(union Data));

    storeData->num = code;

    char letter = storeData->letter;

    free(storeData);

    return letter;
}

int decrypt()
{
    FILE *readData;
    readData = fopen(NUMIPFILE, "r");

    FILE *writeData;
    writeData = fopen(TEXTOUTPUT, "w");

    if (writeData == NULL || readData == NULL)
    {
        return -1;
    }

    int code;

    while (fscanf(readData, "%d", &code) != EOF)
    {
        fprintf(writeData, "%c", getChar(code));
    }

    fclose(readData);
    fclose(writeData);

    return 0;
}
