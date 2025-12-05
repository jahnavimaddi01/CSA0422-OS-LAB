/* PROGRAM 37 : SEQUENTIAL SEARCH IN FILE */

#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char word[20], temp[20];
    int found = 0;

    fp = fopen("data.txt", "r");

    printf("Enter word to search: ");
    scanf("%s", word);

    while(fscanf(fp, "%s", temp) != EOF) {
        if(strcmp(word, temp) == 0) {
            found = 1;
            break;
        }
    }

    if(found) printf("Word Found\n");
    else printf("Not Found\n");

    fclose(fp);
    return 0;
}
