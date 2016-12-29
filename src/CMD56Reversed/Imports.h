#pragma once

#include <stdint.h>

struct sd_context
{
   char data[0x24C0];
};

#define PACKET_2_INDEX 2
#define PACKET_4_INDEX 4
#define PACKET_6_INDEX 6
#define PACKET_8_INDEX 8
#define PACKET_10_INDEX 10
#define PACKET_12_INDEX 12
#define PACKET_14_INDEX 14
#define PACKET_16_INDEX 16
#define PACKET_18_INDEX 18
#define PACKET_20_INDEX 20

void* SceSblGcAuthMgr_SceSysclibForDriver_imp_8a0b0815(void * destination, const void * source, size_t num, int assert_size);

sd_context* SceSblGcAuthMgr_SceSdifForDriver_imp_6a71987f(int index);

int SceSblGcAuthMgr_SceSdifForDriver_imp_22c82e79(int index, sd_context** element);

int SceSblGcAuthMgr_SceSdifForDriver_imp_b0996641(sd_context* ctx, char* buffer, int size);

int SceSblGcAuthMgr_SceSdifForDriver_imp_134e06c4(sd_context* ctx, char* buffer, int size, int index);