
#include <stdint.h>
#include <stdio.h>

#include "dbg_platform.h"
#include "register_offsets.h"

#include "sanity0.h"

int main()
{
	// Init
	nvdlaInit();
	printf("-I: init debug platform\n");
	
	// Tests
	printf("-I: start test sanity0...\n");
	if(sanity0()) {
		printf("\033[31;0m-E: error during test execution. Aborting...\033[0m\n");
		return -1;
	}

	// Exit
	printf("-I: all test \033[32;0mPASSED\033[0m\n");
	return 0;
}
