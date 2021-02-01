/**
 * Database
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define COMPRESSING 0x11
#define DECOMPRESSING 0x22

int status;

FILE* given_file;
FILE* output_file;

char* file_path;    // without file name
char* file_name;    // only file name

char* given_file_path;              // with file name
char* compressed_file_path;         // compressed file path with compressed file name
char* decompressed_file_path;       // decompressed file path with decompressed file name

int byte_count = 0;     // == file_size
int char_count = 0;     // == number of different characters in the given file

const char* compressed_suffix = ".compressed";
const char* decompressed_suffix = ".decompressed";

struct{
   char data;
   int frequency; 
}frequency_map[256];

struct{
    char data;
    char code[0xff];
    int code_len;
}encode_map[256]; int count = 0;

char* preorder;
char* inorder;

void Insert2Map(char c){        // insert to frequency map
    int i;
    for(i = 0; i < char_count && frequency_map[i].data != c; i++);
    if(i == char_count){
        frequency_map[i].data = c;
        frequency_map[i].frequency = 1;
        char_count++;
    }
    else frequency_map[i].frequency++;
}

char* isCompressedFile(char* name){
    int len = strlen(name), i, n = -1;
    for(i = 0; i < len; i++) if(name[i] == '.') n = i;
    if(n == len || len - n + 1 != 12 || n == -1) return NULL;
    int j = 0, k = n;
    for(; k < len; k++, j++) if(name[k] != compressed_suffix[j]) return NULL;
    char* ret = (char*)malloc(i * sizeof(char));
    for(j = 0; j < n; j++) ret[j] = name[j];
    return ret;
}

void extract_fileName_filePath(char *args){

    given_file_path = args;

    int i = 0, len = strlen(args), j;
    while(i != len){        // looking for the last '/' that appears in the file path
        if(args[i] == '/') j = i;
        i++;
    }

    // before the last '/' is the file_path
    // after the last '/' is the file_name
    int k, l;
    file_path = (char*)malloc(j * sizeof(char));
    for(k = 0; k < j; k++) file_path[k] = args[k];
    file_name = (char*)malloc((i - j - 1) * sizeof(char));
    for(k = j + 1, l = 0; k < i; k++, l++) file_name[l] = args[k];


    if(status == COMPRESSING){          // if compressing
        compressed_file_path = (char*)malloc((i + 12) * sizeof(char));
        for(k = 0; k < j; k++) compressed_file_path[k] = file_path[k];
        compressed_file_path[j] = '/';
        for(k = j + 1, l = 0; k < i; k++, l++) compressed_file_path[k] = file_name[l];
        for(k = i, l = 0; l < 12; k++, l++) compressed_file_path[k] = compressed_suffix[l];
    }

    if(status == DECOMPRESSING){        // if decompressing
        file_name = isCompressedFile(file_name);
        if(file_name == NULL) return;
        decompressed_file_path = (char*)malloc((i + 14) * sizeof(char));
        for(k = 0; k < j; k++) decompressed_file_path[k] = file_path[k];
        decompressed_file_path[j] = '/';
        for(k = j + 1, l = 0; l < strlen(file_name); k++, l++) decompressed_file_path[k] = file_name[l];
        for(l = 0; l < 14; k++, l++) decompressed_file_path[k] = decompressed_suffix[l];
    }

}