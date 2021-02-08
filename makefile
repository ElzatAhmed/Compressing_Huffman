object := loop.c

make:
	-gcc compress.c -fno-stack-protector -g -o bin/compress
	-gcc decompress.c -fno-stack-protector -g -o bin/decompress
compress:
	-./bin/compress testcases/${object}
decompress:
	-./bin/decompress testcases/${object}.compressed
both:
	-./bin/compress testcases/${object}
	-./bin/decompress testcases/${object}.compressed
clean:
	-rm bin/compress bin/decompress