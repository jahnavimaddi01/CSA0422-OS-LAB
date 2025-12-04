/* PROGRAM 24 : FILE CREATE, WRITE, READ, CLOSE */

#include <stdio.h>

int main() {
    FILE *fp;
    char text[50];

    fp = fopen("data.txt", "w");
    fprintf(fp, "Hello OS Lab");
    fclose(fp);

    fp = fopen("data.txt", "r");
    fgets(text, 50, fp);
    printf("File Content: %s\n", text);
    fclose(fp);

    return 0;
}
