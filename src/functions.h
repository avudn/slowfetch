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


int checkdistro() {
	char osrelease[40];
	FILE *openosrelease = fopen(OS_DIR, "r");
	
	fgets(osrelease, sizeof(osrelease), openosrelease);
	char *distro = (osrelease + 6);
	distro[strlen(distro) - 2] = '\0';
	printf("%s Linux\n", distro);
	return 0;
}

#endif
