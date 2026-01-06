#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void toLowerCase(char *str){
    for (int i = 0; str[i]; i++){
        str[i] = tolower((unsigned char)str[i]);
    }
}

int main(){
    char word[50], find[1000], yesno;
    FILE *file, *output;
    int count = 0;


    printf("Enter the word to count: ");
    scanf("%s", word);
    printf("Would you like to hide the word? (Y/N): ");
    scanf(" %c",&yesno);

    if(yesno == 'y' || yesno == 'Y'){
        output = fopen("output.txt", "w");
        if (output == NULL) {
            printf("Could not create output file\n");
            fclose(file);
            return 1;
        }

    }
    
    toLowerCase(word);

    
    file = fopen("projectword.txt", "r");
    if(file == NULL){
        printf("Could not open file \n");
        return 1;
    }

   
    while (fscanf(file, "%s", find) == 1){
        toLowerCase(find);
        if(strcmp(find, word) == 0) {
            count++;
        }

        if(yesno == 'y' || yesno == 'Y'){
            if(strcmp(find, word) == 0) {
                for (int i = 0; i < strlen(find); i++) {
                        find[i] = '*';
                }
            }

            fprintf(output, "%s ", find);
        }
    }

        

            
        

    fclose(file);
    fclose(output);

    printf("The word '%s' appears %d times in the file.\n", word, count);

    return 0;
}
