#include <stdio.h>
#include "include/output.h"

void read_data();

int main(int argc, char* argv[])
{
	if(argc == 2){
		status = COMPRESSING;
		extract_fileName_filePath(argv[1]);
		read_data();
		build_HuffmanTree();
		encode(final_root, code, 0);
		output_compressed();
	}

	return 0;
}

void read_data(){
	FILE* given_file;
	given_file = fopen(given_file_path, "r");

	char c = fgetc(given_file);
	while(c != EOF){
		Insert2Map(c);
		c = fgetc(given_file);
	}

	fclose(given_file);
}