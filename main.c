#include <stdio.h>
#include <stdlib.h>

union Data
{
    int num;
    char letter;
};

int encrypt();
int decrypt();
int getCode(char);
char getChar(int);

int main()
{
    int choice, output;
    printf("1 - Encrypt\n2 - Decrypt\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        output = encrypt();
        break;
    case 2:
        output = decrypt();
        break;
    default:
        output = 0;
        break;
    }

    (output == 0) ? printf("Failed") : printf("Sucessfully performed operation");

    return 0;
}

int getCode(char letter)
{
    union Data *storeData = (union Data *)malloc(sizeof(union Data));

    storeData->letter = letter;

    int code = storeData->num;

    free(storeData);

    return code;
}

char getChar(int code)
{
    union Data *storeData = (union Data *)malloc(sizeof(union Data));

    storeData->num = code;

    char letter = storeData->letter;

    free(storeData);

    return letter;
}

int encrypt()
{
    FILE *readData;
    readData = fopen("input.txt", "r");

    FILE *writeData;
    writeData = fopen("output.txt", "w");

    if (writeData == NULL || readData == NULL)
    {
        return 0;
    }

    char letter;

    while ((letter = fgetc(readData)) != EOF)
    {
        fprintf(writeData, "%d\n", getCode(letter));
    }

    fclose(readData);
    fclose(writeData);

    return 1;
}

int decrypt()
{
    FILE *readData;
    readData = fopen("input.txt", "r");

    FILE *writeData;
    writeData = fopen("output.txt", "w");

    if (writeData == NULL || readData == NULL)
    {
        return 0;
    }

    int code;

    while (fscanf(readData, "%d", &code) != EOF)
    {
        fprintf(writeData, "%c", getChar(code));
    }

    fclose(readData);
    fclose(writeData);

    return 1;
}
