#ifndef SANITY0_H
#define SANITY0_H

#include "register_offsets.h"

int sanity0()
{
	u32 num = 0x8;
	u32 val = 0;

	nvdlaInit();

	printf("-I: Writing 0xFF to register...\n\r");
	nvdlaRegWrite(NVDLA_CSC_D_ENTRY_PER_SLICE, 0xFF);

	flush_caches();

	printf("-I: Reading register...\n\r");
	val = nvdlaRegRead(NVDLA_CSC_D_ENTRY_PER_SLICE);
	printf("-I: Value %d read from register.\n\r", val);

	mem_init(pri_mem, 0x0, num, ALL_ZERO);
	num = mem_load(pri_mem, 0x0, "test.dat");
	printf("-I: loaded %d bytes\n", num);

	mem_view(pri_mem, 0x0, num, 0x4);
	mem_dump(pri_mem, 0x0, num, 0x4, "out.dat");

	nvdlaDestroy();

	return 0;
}

#endif
