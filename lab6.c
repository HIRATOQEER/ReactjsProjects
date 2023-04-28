#include <stdio.h>

int main() {
    FILE *input_file, *output_file;
    char c;

    // Open input.txt in read mode
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input.txt file!");
        return 1;
    }

    // Open output.txt in write mode, overwrite the file if it already exists
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error creating output.txt file!");
        return 1;
    }

    // Read input.txt character by character and write to output.txt
    while ((c = fgetc(input_file)) != EOF) {
        fputc(c, output_file);
    }

    // Close both files
    fclose(input_file);
    fclose(output_file);

    printf("Data written to output.txt file successfully!");

    return 0;
}

