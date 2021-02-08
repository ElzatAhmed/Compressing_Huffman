#include <stdio.h>

int main(){

    FILE* f1 = fopen("testcases/hello", "r");
    // FILE* f2 = fopen("param.txt", "w");
    char c = fgetc(f1);
    while(c != EOF){
        printf("%d\n", (int)c);
        c = fgetc(f1);
    }
    fclose(f1); /*fclose(f2);*/

    return 0;
}