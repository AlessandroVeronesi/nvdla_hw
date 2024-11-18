#ifndef NVDLA_CRISPY_H
#define NVDLA_CRISPY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>


// PLATFORM INIT

char* NVDLA_BASE;
char* pri_mem;

#define CSB_SIZE 128*1024 // CSB SIZE IN kB
#define DRAM_SIZE 128*1024*1024 // DRAM SIZE IN MB

#define nvdlaInit()                                         \
    NVDLA_BASE = malloc(CSB_SIZE*sizeof(char)); \
    pri_mem    = malloc(DRAM_SIZE*sizeof(char))

#define nvdlaDestroy() \
    free(NVDLA_BASE);  \
    free(pri_mem)

// REGISTER OPERATIONS

#define nvdlaRegWrite( __REG__ , __VAL__) \
	*(volatile uint32_t*)(NVDLA_BASE + __REG__) = __VAL__; \
	printf("-D: Written reg %d to %d \n", __REG__, __VAL__)

#define nvdlaRegRead(__REG__) \
	*(volatile uint32_t*)(NVDLA_BASE + __REG__); \
	printf("-D: Read %d from reg %d \n", *(volatile uint32_t*)(NVDLA_BASE + __REG__), __REG__ );

// MEMORY MANAGEMENT

#define ALL_ZERO 0
#define LINESIZE 10


#define mem_init( __MEM__ , __ADDR__ , __SIZE__ , __PATTERN__ )     \
	memset((void*)(__MEM__ + __ADDR__), __PATTERN__, __SIZE__); \
	printf("-D: init mem %" PRIxPTR " for %d bytes from addr %d to the value %d\n", (uintptr_t) __MEM__, __SIZE__, __ADDR__,  __PATTERN__);

uint32_t _reverse32(uint32_t value) 
{
	return (((value & 0x000000FF) << 24) |
		((value & 0x0000FF00) <<  8) |
		((value & 0x00FF0000) >>  8) |
		((value & 0xFF000000) >> 24));
}

size_t hexstr2byte(const char* _str, char* _buff)
{
	uint32_t _value = (uint32_t) strtol(_str, NULL, 16);
	_value = _reverse32(_value);
	memcpy(_buff, &_value, sizeof(_value));

	return sizeof(uint32_t);
}

size_t mem_load(char* ptr, const size_t offset, const char* fileName)
{
	FILE* fd;
	int _display = -1;

	char strbuff[LINESIZE];
	char bytebuff[4];
	size_t it = 0;

	fd = fopen(fileName, "r");
	if(!fd) {
		printf("\033[31;0m-E: error during file %s opening. Aborting...\033[0m\n", fileName);
		return 0;
	}

	printf("-D: loading memory...\n");
	while (fgets(strbuff, LINESIZE, fd)) {
		size_t len;
		size_t size;

		len  = strlen(strbuff) -1;

		if(_display) {
			printf("-D: %ld-bit alignment detected\n", (len*4));
			_display = 0;
		}
		printf("-D: Parsed string %s", strbuff);

		size = hexstr2byte(strbuff, bytebuff);

		memcpy(&ptr[offset + it], bytebuff, size);

		it += size;
	}
	fclose(fd);

	printf("-D: %ld bytes read\n", it);

	return it;
}

size_t mem_view(const char* ptr, const size_t offset, const size_t num, const size_t align)
{
	printf("-D: dumping %ld bytes from mem %" PRIxPTR " starting from offset %ld (alignment on %ld bytes))...\n", num, (uintptr_t) ptr, offset, align);

	for(size_t it=0; it<num; it++) {
		printf("_%02hhx", ptr[it]);
		if(!((it+1) % align)) {
			printf("\n");
		}

	}

	return num;
}

size_t mem_dump(const char* ptr, const size_t offset, const size_t num, const size_t align, const char* fileName)
{
	FILE* fd;
	char buff[LINESIZE];

	printf("-D: dumping %ld bytes from mem %" PRIxPTR " from offset %ld to file %s (alignment on %ld bytes))...\n", num, (uintptr_t) ptr, offset, fileName, align);

	fd = fopen(fileName, "w+");
	if(!fd) {
		printf("\033[31;0m-E: error during file %s opening. Aborting...\033[0m\n", fileName);
		return 0;
	}

	for(size_t it=0; it<num; it+=align) {
		memcpy(buff, &ptr[offset+it], align);
		for(size_t j=0; j<align; j++) {
			fprintf(fd, "%02hhx", buff[j]);
		}
		fprintf(fd, "\n");
	}
	fclose(fd);

	return num;
}

#endif
