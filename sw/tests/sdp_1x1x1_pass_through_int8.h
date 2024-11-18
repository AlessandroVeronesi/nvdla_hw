#ifndef SDP_1X1X1_PASS_THROUGH_INT8_H
#define SDP_1X1X1_PASS_THROUGH_INT8_H

#include "register_offsets.h"

#define TESTLEN 0x200

int sdp_1x1x1_pass_through_int8()
{
    #ifdef IMPLEMENTATION_CRISPY
    uint8_t* dst = pri_mem + 0x1000;
    #else
	uint8_t dst[TESTLEN];
    #endif

//	uint8_t sleepCnt = 0;
	uint8_t Status = 0;

    mem_init(pri_mem, 0x0, 0x200, 0);
    mem_init(dst, 0x0, 0x200, 0);

    for(int j=0;j<2;j++)for(int i=0;i<256;i++) *(volatile uint8_t*)(pri_mem + j*256 + i) = i;
    /*
    printf("-I: Displaying input memory content:\r\n");
    mem_view(pri_mem, 0x0, 0x200, 0x8);

    printf("-I: Displaying output memory content (Before):\r\n");
    mem_view(dst, 0x0, 0x200, 0x8);*/

    nvdlaRegWrite(NVDLA_SDP_RDMA_S_POINTER, 0x0);
    nvdlaRegWrite(NVDLA_SDP_RDMA_S_STATUS, 0x0);
    nvdlaRegWrite(NVDLA_SDP_S_POINTER, 0x0);
    nvdlaRegWrite(NVDLA_SDP_S_STATUS, 0x0);
    nvdlaRegWrite(NVDLA_SDP_D_STATUS, 0x0);

    nvdlaRegWrite(NVDLA_SDP_RDMA_D_DATA_CUBE_WIDTH, 0x7);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_DATA_CUBE_HEIGHT, 0x7);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_DATA_CUBE_CHANNEL, 0x0);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_SRC_LINE_STRIDE, 0x40);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_SRC_SURFACE_STRIDE, 0x8);
    nvdlaRegWrite(NVDLA_SDP_D_DATA_CUBE_WIDTH, 0x7);
    nvdlaRegWrite(NVDLA_SDP_D_DATA_CUBE_HEIGHT, 0x7);
    nvdlaRegWrite(NVDLA_SDP_D_DATA_CUBE_CHANNEL, 0x0);
    nvdlaRegWrite(NVDLA_SDP_D_DST_LINE_STRIDE, 0x40);
    nvdlaRegWrite(NVDLA_SDP_D_DST_SURFACE_STRIDE, 0x8);

    nvdlaRegWrite(NVDLA_SDP_RDMA_D_SRC_BASE_ADDR_LOW, (uint32_t)(pri_mem + 0x0));
    nvdlaRegWrite(NVDLA_SDP_D_DST_BASE_ADDR_LOW, (uint32_t)(dst + 0x0));

    nvdlaRegWrite(NVDLA_SDP_D_CVT_SHIFT, 0x0);
    nvdlaRegWrite(NVDLA_SDP_D_CVT_OFFSET, 0x0);
    nvdlaRegWrite(NVDLA_SDP_D_CVT_SCALE, 0x1);

    nvdlaRegWrite(NVDLA_SDP_RDMA_D_BN_BASE_ADDR_HIGH, 0x2f);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_BN_LINE_STRIDE, 0x40);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_BN_SURFACE_STRIDE, 0x80);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_BRDMA_CFG, 0x13);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_ERDMA_CFG, 0x3);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_FEATURE_MODE_CFG, 0x0);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_NRDMA_CFG, 0xd);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_PERF_BRDMA_READ_STALL, 0x0);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_PERF_ENABLE, 0x2);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_PERF_ERDMA_READ_STALL, 0x0);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_PERF_MRDMA_READ_STALL, 0x0);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_PERF_NRDMA_READ_STALL, 0x0);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_SRC_BASE_ADDR_HIGH, 0x0);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_SRC_DMA_CFG, 0x1);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_STATUS_INF_INPUT_NUM, 0x0);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_STATUS_NAN_INPUT_NUM, 0x0);
    nvdlaRegWrite(NVDLA_SDP_D_DATA_FORMAT, 0x0);
    nvdlaRegWrite(NVDLA_SDP_D_DST_BASE_ADDR_HIGH, 0x0);
    nvdlaRegWrite(NVDLA_SDP_D_DST_DMA_CFG, 0x1);
    nvdlaRegWrite(NVDLA_SDP_D_FEATURE_MODE_CFG, 0x8);
    nvdlaRegWrite(NVDLA_SDP_D_PERF_ENABLE, 0xe);
    nvdlaRegWrite(NVDLA_SDP_D_PERF_LUT_HYBRID, 0x0);
    nvdlaRegWrite(NVDLA_SDP_D_PERF_LUT_LE_HIT, 0x0);
    nvdlaRegWrite(NVDLA_SDP_D_PERF_LUT_LO_HIT, 0x0);
    nvdlaRegWrite(NVDLA_SDP_D_PERF_LUT_OFLOW, 0x0);
    nvdlaRegWrite(NVDLA_SDP_D_PERF_LUT_UFLOW, 0x0);
    nvdlaRegWrite(NVDLA_SDP_D_PERF_OUT_SATURATION, 0x0);
    nvdlaRegWrite(NVDLA_SDP_D_PERF_WDMA_WRITE_STALL, 0x0);
    nvdlaRegWrite(NVDLA_SDP_D_STATUS_INF_INPUT_NUM, 0x0);
    nvdlaRegWrite(NVDLA_SDP_D_STATUS_NAN_INPUT_NUM, 0x0);
    nvdlaRegWrite(NVDLA_SDP_D_STATUS_NAN_OUTPUT_NUM, 0x0);

    nvdlaRegWrite(NVDLA_SDP_D_OP_ENABLE, 0x1);
    nvdlaRegWrite(NVDLA_SDP_RDMA_D_OP_ENABLE, 0x1);

	flush_caches();

	/*
    while(nvdlaRegRead(NVDLA_SDP_RDMA_S_STATUS)!=0)
    {
    	sleep(1);
    	sleepCnt++;
    	if(sleepCnt > 3) {
    		Status = 0xFF;
    		break;
    	}
    }

    uint32_t ret = nvdlaRegRead(NVDLA_SDP_RDMA_S_STATUS);
    printf("-I: Test terminated with NVDLA_SDP_RDMA_S_STATUS == %d\n\r", ret);

    */

	sleep(3);

    for(int j=0;j<2;j++)
        for(int i=0;i<256;i++)
            if(*(volatile uint8_t*)(pri_mem + j*256 + i)!=*(volatile uint8_t*)(dst + j*256 + i))
                return -1;

    //intr_notify(SDP_0, sync_id_0);
    //check_crc(sync_id_0, 1, 0x90000040, 0x8, 0xcb0ea2db);

    /*printf("-I: Displaying output memory content:\r\n");
    mem_view(dst, 0x0, 0x200, 0x8);*/


    return Status;
}


#endif
