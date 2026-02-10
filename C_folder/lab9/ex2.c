/**/
#include <stdio.h>
#include <dirent.h>

int main() {
	DIR* dir = opendir("./");

	if (dir == NULL) {
		printf("failure\n");
		return 1;
	}

	struct dirent* entities = readdir(dir);
	while (entities != NULL) {
		printf("%s\n", entities->d_name);
		entities = readdir(dir);
	}
	closedir(dir);

	return 0;
}
