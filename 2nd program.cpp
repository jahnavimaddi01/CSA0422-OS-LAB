// Program 2: Copy content from one file to another (Windows Supported)
#include <stdio.h>

int main() {
    FILE *src, *dest;
    char sourceFile[50], destFile[50];
    char ch;

    printf("Enter Source File Name: ");
    scanf("%s", sourceFile);

    printf("Enter Destination File Name: ");
    scanf("%s", destFile);

    // Open source file in read mode
    src = fopen(sourceFile, "r");
    if(src == NULL) {
        printf("Error: Cannot open source file!\n");
        return 1;
    }

    // Open destination file in write mode
    dest = fopen(destFile, "w");
    if(dest == NULL) {
        printf("Error: Cannot create destination file!\n");
        fclose(src);
        return 1;
    }

    // Copy character by character
    while((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    printf("\nFile Copied Successfully!\n");

    fclose(src);
    fclose(dest);

    return 0;
}

