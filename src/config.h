#ifndef DISTROS_H
#define DISTROS_H

/* Directories */

#define KERNEL_DIR "/proc/sys/kernel/osrelease"
#define OS_DIR "/etc/os-release"
#define HOST_DIR "/etc/hostname"

/* Hardware Stuff */

const char * os = "OS: ";
const char * uptime = "Uptime: ";
const char * kernel = "Kernel: ";
const char * wm = "WM: ";
const char * hostname = "Host: ";
const char * ram = "Memory: ";
const char * cpu = "CPU: ";

#endif
