#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define VERSION "1.3.0"

int checkfile(const char *file) {
        char buffer[100];
        FILE *f  = fopen(file, "r");

        if (f == NULL) {
                return 1;
	}

	fgets(buffer, sizeof(buffer), f);
	printf("%s", buffer);

	fclose(f);
        return 0;
}

void showhelp() {
	printf("sifetch 1.3.0\n");
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

unsigned long long get_meminfo_value(const char *key) {
    char buffer[400];
    unsigned long long value = 0;
    
    FILE *fl = fopen("/proc/meminfo", "r");
    if (fl == NULL)
        return 0;

    while (fgets(buffer, sizeof buffer, fl) != NULL) {
        if (strncmp(buffer, key, strlen(key)) == 0) {
            sscanf(buffer, "%*s %llu", &value);
            break;
        }
    }

    fclose(fl);
    return value;
}

void get_memory(void) {
    unsigned long long total = get_meminfo_value("MemTotal:") / 1024;
    unsigned long long avail = get_meminfo_value("MemAvailable:") / 1024;
    unsigned long long used  = total - avail;

    printf("%llu MiB/%llu MiB\n", used, total);
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
		checkfile(HOST_DIR);	

	} else if (strcmp(module, "term") == 0) {
		char *term = getenv("TERM");
			if (term == NULL)
				return 1;
		printf("%s\n", term);

	} else if (strcmp(module, "kernel") == 0) {
		checkfile(KERNEL_DIR);

	} else if (strcmp(module, "session") == 0) {
		char *session = getenv("XDG_SESSION_TYPE");
			if (session == NULL)
				return 1;
		printf("%s\n", session);	

	} else {
		printf("Module not found. Aborting.\n");
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
