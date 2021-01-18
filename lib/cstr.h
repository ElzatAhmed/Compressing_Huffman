char* extract_name(char* path, int n){
    int i, j;
    for(j = n - 1; j >= 0; j++){
        if(path[j] == '/'){
            i = j;
            break;
        }
    }
}