#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "functions.h"

#define VERSION "1.2.0"

/* Functions are defined in functions.h file, if you want to take a look at them. */

int main(int argc, char *argv[]) {
	
	/* Arguments */
	if (argc >= 2 && (strncmp("-v", argv[1], 3) == 0)) {
		printf("Version: %s\n", VERSION);
	} else {

	printf("%s", os);
	checkdistro();

	printf("%s", kernel);
	checkfile(KERNEL_DIR);	
	
	printf("%s", hostname);
	checkfile(HOST_DIR);

	}
	return 0;
}
