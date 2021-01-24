
char* file_path;
char* file_name;

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