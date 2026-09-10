#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "config.h"

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
	}
		
	return 0;
}


int checkdistro() {
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

	return 0;
}

#endif
