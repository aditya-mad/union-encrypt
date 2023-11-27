#include <stdio.h>
#include <stdlib.h>

union Data
{
    int num;
    char letter;
};

int encrypt();
int decrypt();

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

    union Data *storeData = (union Data *)malloc(sizeof(union Data));

    while ((storeData->letter = fgetc(readData)) != EOF)
    {
        fprintf(writeData, "%d\n", storeData->num);
    }

    fclose(readData);
    fclose(writeData);

    free(storeData);

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

    union Data *storeData = (union Data *)malloc(sizeof(union Data));

    while (fscanf(readData, "%d", &storeData->num) != EOF)
    {
        fprintf(writeData, "%c", storeData->letter);
    }

    fclose(readData);
    fclose(writeData);

    free(storeData);

    return 1;
}
