#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include "config.h"
#include "functions.h"

/* Functions are defined in functions.h file, if you want to take a look at them. */

int main(int argc, char *argv[]) {

	/* Arguments */

	if (argc >= 2) {
		handleargs(argv);
	} else {

	printf("%s", os);
	checkdistro();

	printf("%s", kernel);
	checkfile(KERNEL_DIR);

	printf("%s", hostname);
	checkfile(HOST_DIR);

	printf("%s", uptime);
	get_module("uptime");

	printf("%s", procs);
	get_module("procs");

	}
	return 0;
}
