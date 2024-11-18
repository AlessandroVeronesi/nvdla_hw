#ifndef NVDLA_CRISPY_H
#define NVDLA_CRISPY_H

#define IMPLEMENTATION_CRISPY

#define NVDLA_BASE (void*)0x02100000
#define pri_mem (void*)0x02140000

#define nvdlaRegWrite( __REG__ , __VAL__) *(volatile uint32_t*)(NVDLA_BASE + __REG__) = __VAL__
#define nvdlaRegRead(__REG__) *(volatile uint32_t*)(NVDLA_BASE + __REG__)
#define mem_init( __MEM__ , __ADDR__ , __SIZE__ , __PATTERN__ ) for(int i=0;i< __SIZE__ ;i++) *(volatile uint8_t*)(__MEM__ + __ADDR__ + i) = __PATTERN__
#define mem_view(__MEM__, __ADDR__, __SIZE__, __WORD_SIZE__) //for(int i=0;i<__SIZE__;i+=4)printf_("%#010x\r\n",*(volatile uint32_t*)(__MEM__ + __ADDR__ + i));
#define flush_caches()
#define sleep(__TIME__)

#endif
