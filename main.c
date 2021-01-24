#include <stdio.h>
#include "include/HuffmanTree.h"

void read_data();

int main(int argc, char* argv[])
{
	if(argc == 1){
		file_path = argv[0];
		read_data();
		build_HuffmanTree();
	}

	return (0);
}

void read_data(){
	FILE* given_file;
	given_file = fopen(file_path, "r");

	char c;
	while(c != EOF){
		c = fgetc(given_file);
		Insert2Map(c);
	}

	fclose(given_file);
}