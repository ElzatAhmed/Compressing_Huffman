/**
 * Database
 */

char* file_path;
char* file_name;

char* given_file_path;
char* compressed_file_path;

int byte_count = 0;
int char_count = 0;

struct{
   char data;
   int frequency; 
}frequency_map[256];

void Insert2Map(char c){
    int i;
    for(i = 0; i < char_count && frequency_map[i].data != c; i++);
    if(i == char_count){
        frequency_map[i].data = c;
        frequency_map[i].frequency = 1;
        char_count++;
    }
    else frequency_map[i].frequency++;
}

void extract_fileName_filePath(char *args){

    const char* suffix = ".compressed";

    int i = 0, j;
    while(args[i] != '\0') if(args[i] == '/') j = i;
    int k, l;
    for(k = 0; k < j; k++) file_path[k] = args[k];
    for(k = j + 1, l = j; k < i; k++, l++) file_name[l] = args[k];

    given_file_path = args;
    for(k = 0; k < j; k++) compressed_file_path[k] = file_path[k];
    compressed_file_path[j] = '/';
    for(k = j + 1, l = 0; k < i; k++, l++) compressed_file_path[k] = file_name[k];
    for(k = i, l = 0; l < 12; k++, l++) compressed_file_path[k] = suffix[l];
}