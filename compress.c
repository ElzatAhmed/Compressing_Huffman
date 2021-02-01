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

	char c;
	while(c != EOF){
		c = fgetc(given_file);
		Insert2Map(c);
	}

	fclose(given_file);
}