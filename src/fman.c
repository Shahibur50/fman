/*
fman (File Manager)
Version 0.0.1

Copyright (c) 2023 Shahibur Rahaman
Licensed under GNU GPLv3
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define VERSION "0.0.1"

void info(void);
void help(void);
int file_crt(char *file);
int file_wrt(char *file);
int file_shw(char *file);
int file_rem(char *file);
int file_cpy(char *file_a, char *file_b);
int file_mov(char *file_a, char *file_b);
int file_ren(char *file_a, char *file_b);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("fman: missing command option\n");
        printf("Try 'fman --help' for more information.\n");
        return 1;
    }
    
    char *cmd = argv[1];
    int cmd_len = strlen(argv[1]);

    // Pointer to store the lowercase version of long command
    char *l_cmd = (char *) malloc(cmd_len + 1);
    
    // Loop to convert all the characters of command to lowercase
    for (int i = 0; i < cmd_len + 1; i++) {
        l_cmd[i] = tolower(cmd[i]);
    }

    if (strcmp(cmd, "-C\0") == 0 || strcmp(l_cmd, "--create\0") == 0) {
        free(l_cmd);
        if (argc < 3) {
            printf("fman: missing path to the file\n");
            printf("Usage: fman -C [path_to/file]\n");
            return 1;
        }
        else if (argc > 3) {
            printf("fman: invalid number of arguments provided\n");
            return 1;
        }
        // Calling the file create function and checking its return value
        if (file_crt(argv[2]) == 0) {
            printf("File created successfully.\n");
            return 0;
        }
        else {
            printf("An error occurred while creating the file.\n");
            return 1;
        }
    }
    else if (strcmp(cmd, "-w\0") == 0 || strcmp(l_cmd, "--write\0") == 0) {
        free(l_cmd);
        if (argc < 3) {
            printf("fman: missing path to the file\n");
            printf("Usage: fman -w [path_to/file]\n");
            return 1;
        }
        else if (argc > 3) {
            printf("fman: invalid number of arguments provided\n");
            return 1;
        }
        // Calling the file write function and checking its return value
        if (file_wrt(argv[2]) == 0) {
            printf("\nFile written successfully.\n");
            return 0;
        }
        else {
            printf("An error occurred while writing to the file.\n");
            return 1;
        }
    }
    else if (strcmp(cmd, "-s\0") == 0 || strcmp(l_cmd, "--show\0") == 0) {
        free(l_cmd);
        if (argc < 3) {
            printf("fman: missing path to the file\n");
            printf("Usage: fman -s [path_to/file]\n");
            return 1;
        }
        else if (argc > 3) {
            printf("fman: invalid number of arguments provided\n");
            return 1;
        }
        // Calling the file show function and checking its return value
        if (file_shw(argv[2]) == 0) {
            return 0;
        }
        else {
            printf("An error occurred while showing the data from the file.\n");
            return 1;
        }
    }
    else if (strcmp(cmd, "-R\0") == 0 || strcmp(l_cmd, "--remove\0") == 0) {
        free(l_cmd);
        if (argc < 3) {
            printf("fman: missing path to the file\n");
            printf("Usage: fman remove [path_to/file]\n");
            return 1;
        }
        else if (argc > 3) {
            printf("fman: invalid number of arguments provided\n");
            return 1;
        }
        // Calling the file remove function and checking its return value
        if (file_rem(argv[2]) == 0) {
            printf("Removed the file successfully.\n");
            return 0;
        }
        else {
            printf("An error occurred while removing the file.\n");
            return 1;
        }
    }
    else if (strcmp(cmd, "-c\0") == 0 || strcmp(l_cmd, "--copy\0") == 0) {
        free(l_cmd);
        if (argc < 4) {
            printf("fman: missing the proper paths to the files\n");
            printf("Usage: fman -c [path_to/file_in] [path_to/file_out]\n");
            return 1;
        }
        else if (argc > 4) {
            printf("fman: invalid number of arguments provided\n");
            return 1;
        }
        // Calling the file copy function and checking its return value
        if (file_cpy(argv[2], argv[3]) == 0) {
            printf("File copied successfully.\n");
            return 0;
        }
        else {
            printf("An error occurred while copying the file.\n");
            return 1;
        }
    }
    else if (strcmp(cmd, "-m\0") == 0 || strcmp(l_cmd, "--move\0") == 0) {
        free(l_cmd);
        if (argc < 4) {
            printf("fman: missing the proper paths to the files\n");
            printf("Usage: fman -m [path_to/file_in] [path_to/file_out]\n");
            return 1;
        }
        else if (argc > 4) {
            printf("fman: invalid number of arguments provided\n");
            return 1;
        }
        // Calling the file move function and checking its return value
        if (file_mov(argv[2], argv[3]) == 0) {
            printf("File moved successfully.\n");
            return 0;
        }
        else {
            printf("An error occurred while moving the file.\n");
            return 1;
        }
    }
    else if (strcmp(cmd, "-r\0") == 0 || strcmp(l_cmd, "--rename\0") == 0) {
        free(l_cmd);
        if (argc < 4) {
            printf("fman: missing the proper paths to the files\n");
            printf("Usage: fman -r [path_to/file_1] [path_to/file_2]\n");
            return 1;
        }
        else if (argc > 4) {
            printf("fman: invalid number of arguments provided\n");
            return 1;
        }
        // Calling the file rename function and checking its return value
        if (file_ren(argv[2], argv[3]) == 0) {
            printf("File renamed successfully.\n");
            return 0;
        }
        else {
            printf("An error occurred while renaming the file.\n");
            return 1;
        }
    }
    else if (strcmp(cmd, "-v\0") == 0 || strcmp(l_cmd, "--version\0") == 0) {
        free(l_cmd);
        info();
        return 0;
    }
    else if (strcmp(cmd, "-h\0") == 0 || strcmp(l_cmd, "--help\0") == 0) {
        free(l_cmd);
        help();
        return 0;
    }
    else {
        free(l_cmd);
        printf("ERROR! Not a valid command.\n");
        return 1;
    }
}

int file_crt(char *file) {
    FILE *fp;
    fp = fopen(file, "wb");
    if (file == NULL) {
        printf("ERROR! Unable to create the file %s\n", file);
        return 1;
    }
    return 0;
}

int file_wrt(char *file) {
    FILE *fp_in, *fp_out;  // File pointers
    
    fflush(stdin);
    fp_in = stdin;
    if (fp_in == NULL) {
        printf("ERROR! Cannot access stdin.\n");
        return 1;
    }
    fp_out = fopen(file, "wb");
    if (fp_out == NULL) {
        printf("ERROR! Cannot open file '%s'.\n", file);
        return 1;
    }

    printf("Press 'Ctrl+D' to stop writing and save the file.\n");
    printf("Type your text:\n");
    printf("---------------\n");

    char ch; // variable to store the character from first file.
    ch = getc(fp_in);
    while (feof(fp_in) == 0) {
        if (ferror(fp_in)) {
            printf("ERROR! Unable to copy from stdin\n");
            return 1;
        }
        putc(ch, fp_out);
        if (ferror(fp_out)) {
            printf("ERROR! Unable to copy to %s\n", file);
            return 1;
        }
        ch = getc(fp_in);
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}

int file_shw(char *file) {
    FILE *fp_in, *fp_out;  // File pointers
    
    fp_in = fopen(file, "rb");
    if (fp_in == NULL) {
        printf("Cannot open file '%s'.\n", file);
        return 1;
    }
    fflush(stdout);
    fp_out = stdout;

    char ch; // variable to store the character from first file.
    ch = getc(fp_in);
    while (feof(fp_in) == 0) {
        if (ferror(fp_in)) {
            printf("ERROR! Unable to read from %s\n", file);
            return 1;
        }
        putc(ch, fp_out);
        if (ferror(fp_out)) {
            printf("ERROR! Unable to show data in the terminal.\n");
            return 1;
        }
        ch = getc(fp_in);
    }
    printf("\n");

    return 0;
}

int file_rem(char *file) {
    if (remove(file) == 0)
        return 0;
    else
        return 1;
}

int file_cpy(char *file_a, char *file_b) {
    FILE *fp_in, *fp_out;  // File pointers
    
    fp_in = fopen(file_a, "rb");
    if (fp_in == NULL) {
        printf("ERROR! Cannot open file '%s'.\n", file_a);
        return 1;
    }
    fp_out = fopen(file_b, "wb");
    if (fp_out == NULL) {
        printf("ERROR! Cannot open file '%s'.\n", file_b);
        return 1;
    }

    char ch; // variable to store the character from first file.
    ch = getc(fp_in);
    while (feof(fp_in) == 0) {
        if (ferror(fp_in)) {
            printf("ERROR! Unable to copy from %s\n", file_a);
            return 1;
        }
        putc(ch, fp_out);
        if (ferror(fp_out)) {
            printf("ERROR! Unable to copy to %s\n", file_b);
            return 1;
        }
        ch = getc(fp_in);
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}

int file_mov(char *file_a, char *file_b) {
    FILE *fp_in, *fp_out;  // File pointers
    
    fp_in = fopen(file_a, "rb");
    if (fp_in == NULL) {
        printf("ERROR! Cannot open file '%s'.\n", file_a);
        return 1;
    }
    fp_out = fopen(file_b, "wb");
    if (fp_out == NULL) {
        printf("ERROR! Cannot open file '%s'.\n", file_b);
        return 1;
    }

    char ch; // variable to store the character from first file.
    ch = getc(fp_in);
    while (feof(fp_in) == 0) {
        if (ferror(fp_in)) {
            printf("ERROR! Unable to move from %s\n", file_a);
            return 1;
        }
        putc(ch, fp_out);
        if (ferror(fp_out)) {
            printf("ERROR! Unable to move to %s\n", file_b);
            return 1;
        }
        ch = getc(fp_in);
    }

    fclose(fp_in);
    fclose(fp_out);

    // Remove the first file
    if (remove(file_a) == 0)
        return 0;
    else {
        printf("ERROR! Unable to delete the file %s after moving it.\n", file_a);
        return 1;
    }
}

int file_ren(char *file_a, char *file_b) {
    FILE *fp_in, *fp_out;  // File pointers
    
    fp_in = fopen(file_a, "rb");
    if (fp_in == NULL) {
        printf("ERROR! Cannot open file '%s'.\n", file_a);
        return 1;
    }
    fp_out = fopen(file_b, "wb");
    if (fp_out == NULL) {
        printf("ERROR! Cannot open file '%s'.\n", file_b);
        return 1;
    }

    char ch; // variable to store the character from first file.
    ch = getc(fp_in);
    while (feof(fp_in) == 0) {
        if (ferror(fp_in)) {
            printf("ERROR! Unable to move from %s\n", file_a);
            return 1;
        }
        putc(ch, fp_out);
        if (ferror(fp_out)) {
            printf("ERROR! Unable to move to %s\n", file_b);
            return 1;
        }
        ch = getc(fp_in);
    }

    fclose(fp_in);
    fclose(fp_out);

    // Remove the first file
    if (remove(file_a) == 0)
        return 0;
    else {
        printf("ERROR! Unable to delete the file %s after renaming it.\n", file_a);
        return 1;
    }
}


void info(void) {
    printf("fman (File Manager)\n");
    printf("Version: %s\n", VERSION);
    printf("Copyright (c) 2023 Shahibur Rahaman\n");
    printf("Licensed under GNU GPLv3\n");
    printf("This is free software; see the source for copying conditions.  There is NO\n");
    printf("warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n");
}

void help(void) {
    printf("Usage: fman [OPTION] INPUT\n\n");
    printf("Option        Long option        Meaning\n");
    printf("-C            --create           Create a new file\n");
    printf("-R            --remove           Remove a file\n");
    printf("-s            --show             Show the contents of a file\n");
    printf("-c            --copy             Copy the contents from a file to another file\n");
    printf("-m            --move             Move a file from one location to another\n");
    printf("-r            --rename           Rename a file\n");
    printf("-w            --write            Create a new file and write to it\n");
    printf("-v            --version          Print the version information and exit\n");
    printf("-h            --help             Show the help text and exit\n");
}
