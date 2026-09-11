#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define VERSION "1.2.6"

int checkfile(const char *file) {
        char buffer[100];
        FILE *f  = fopen(file, "r");

        if (f == NULL) {
                return 1;
	}

	fgets(buffer, sizeof(buffer), f);
	printf("%s", buffer);

        return 0;
}



void showhelp() {

	printf("sifetch 1.2.6\n");
	printf("Usage: sifetch [Option] \n");
	printf("-v — Check current version\n");
	printf("-h — Show Help\n");

}

void handleargs(char *argv[]) {
	if (strncmp("-v", argv[1], 3) == 0) {
		printf("Version: %s\n", VERSION);
	} else if (strncmp("-h", argv[1], 3) == 0) {
		showhelp();
	}
}

int get_module(const char * module) {

	struct sysinfo modules;
	sysinfo(&modules);

	if (strcmp(module, "uptime") == 0) {
		long seconds = modules.uptime;
		long minutes = seconds/60;
		long hours = minutes/60;

		minutes %= 60;

		printf("%ld hours, %ld mins\n", hours, minutes);

	} else if (strcmp(module, "procs") == 0) {
		printf("%d\n", modules.procs);

	} else if (strcmp(module, "host") == 0) {
		char *user = getenv("USER");
			if (user == NULL)
				return 1;
		printf("%s", user);


	} else {
		printf("Module not found. Aborting.");
		return 1;

	}
	return 0;
}



void checkdistro() {
	char osrelease[40];
	FILE *openosrelease = fopen(OS_DIR, "r");

	fgets(osrelease, sizeof(osrelease), openosrelease);
	char *distro = (osrelease + 6);
	distro[strlen(distro) - 2] = '\0';

	if (strstr(distro, "Linux") != NULL) {
		printf("%s\n", distro);
	} else {
		printf("%s Linux\n", distro);
	}
}



#endif
