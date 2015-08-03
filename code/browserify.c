#include <stdio.h>

int main(int argc, const char *argv[])
{
	FILE *file;
	unsigned int state;
	unsigned short data;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s input-file\n", argv[0]);
		return 255;
	}
	
	if ((file = fopen(argv[1], "rb")) == NULL)
	{
		perror("fopen");
		return 1;
	}

	while (fread(&data, 2, 1, file) == 1)
	{
		printf("\\u%04x", data);
	}
	fclose(file);
	return 0;
}
