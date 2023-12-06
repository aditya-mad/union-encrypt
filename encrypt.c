#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

union Data
{
    int num;
    char letter;
};

char TEXTFILE[] = "text_input.txt";
char NUMOPFILE[] = "num_op.txt";

int encrypt();
int getCode(char);

int main()
{
    return encrypt();
}

int getCode(char letter)
{
    union Data *storeData = (union Data *)malloc(sizeof(union Data));

    storeData->letter = letter;

    int code = storeData->num;

    free(storeData);

    return code;
}

int encrypt()
{
    FILE *readData;
    readData = fopen(TEXTFILE, "r");

    FILE *writeData;
    writeData = fopen(NUMOPFILE, "w");

    if (writeData == NULL || readData == NULL)
    {
        return -1;
    }

    char letter;

    while ((letter = fgetc(readData)) != EOF)
    {
        fprintf(writeData, "%d\n", getCode(letter));
    }

    fclose(readData);
    fclose(writeData);

    return 0;
}
