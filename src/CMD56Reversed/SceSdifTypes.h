#pragma once

#include "Constants.h"
#include <stdint.h>

#pragma pack(push, 1)

typedef struct sdif_context_general //size is 0x40
{
    SceUID suspend_callback_id;
    uint32_t max_array_index; //typically 3
    uint32_t unk_8;
    uint32_t unk_C; 

    uint32_t unk_10;
    uint32_t unk_14;
    uint32_t unk_18;
    uint32_t unk_1C; 

    uint32_t unk_20;
    uint32_t unk_24;
    uint32_t unk_28;
    uint32_t unk_2C; 

    uint32_t unk_30;
    uint32_t unk_34;
    uint32_t unk_38;
    uint32_t unk_3C; 
}sdif_context_general;

typedef struct cmd_input // size is 0x240
{
   uint32_t size; // 0x240
   uint32_t state_flags; // interrupt handler completion flag
   uint32_t command;
   uint32_t argument;
   
   char response[0x10]; //stores normal response without command index and crc-7
                        //can also store CID or CSD. crr-7 will be cleared
                        //storage order is reversed

   void* buffer; // cmd data buffer ptr - dest for vaddr_1C0
   uint16_t b_size; // cmd buffer size
   uint16_t flags; // unknown
   uint32_t error_code; //from interrupt handler
   uint32_t unk_2C;

   uint8_t data0[0x30];   
   
   struct cmd_input* next_cmd;
   uint32_t unk_64;
   uint32_t array_index;
   int(*set_event_flag_callback)(void* ctx);
   
   SceUID evid; // event id SceSdif0, SceSdif1, SceSdif2 (SceSdif3 ?)
   struct cmd_input* secondary_cmd; // (when multiple commands are sent)
   struct sd_context_global* gctx_ptr;
   uint32_t unk_7C;
   
   char vaddr_80[0x80]; //3 - mapped to paddr_184 (invalidate 0x80)

   void* vaddr_100;
   uint8_t data_104[0x7C];

   uint32_t unk_180;
   void* paddr_184; //3 - phys address of vaddr_80
   SceUID mem_188; //SceSdif memblock
   uint32_t unk_18C;

   uint32_t unk_190;
   uint32_t unk_194;
   void* base_198; //dest base for vaddr_200 (also ptr for invalidate)
   uint32_t offset_19C; //dest offset for vaddr_200 (also size for invalidate)

   uint32_t size_1A0; //size of vaddr_1C0
   uint32_t size_1A4; //size of vaddr_200
   void* paddr_1A8; //1 - phys address of vaddr_1C0
   void* paddr_1AC; //2 - phys address of vaddr_200

   SceInt64 wide_time; // 0x1B0
   uint32_t unk_1B8;
   uint32_t unk_1BC;

   char vaddr_1C0[0x40]; //1 - mapped to paddr_1A8 (invalidate 0x40)

   char vaddr_200[0x40]; //2 - mapped to paddr_1AC (invalidate 0x40)
} cmd_input;

typedef struct sd_context_data // size is 0xC0
{
    struct cmd_input* cmd_ptr;
    struct cmd_input* cmd_ptr_next;
    uint32_t unk_8;
    uint32_t unk_C;
    
    uint32_t dev_type_idx; // (1,2,3)
    void* ctx; //pointer to custom context (sd_context_part_mmc*, sd_context_part_sd*, sd_context_part_wlanbt*)
    uint32_t unk_18;
    uint32_t unk_1C;

    uint32_t array_idx; // (0,1,2)
    uint8_t unk_24;
    uint8_t unk_25;
    uint8_t unk_26;
    uint8_t unk_27;
    cmd_input* cmd_28;
    cmd_input* cmd_2C;

    void* membase_1000; // membase of SceSdif (0,1,2) memblock of size 0x1000
    uint32_t unk_34;
    uint32_t unk_38;
    SceUID uid_1000; // UID of SceSdif (0,1,2) memblock of size 0x1000

    SceUID evid; // event id SceSdif0, SceSdif1, SceSdif2 (SceSdif3 ?)
    uint32_t sdif_fast_mutex; // SceSdif0, SceSdif1, SceSdif2 (SceSdif3 ?)
    uint32_t unk_48;
    uint32_t unk_4C;

    uint32_t unk_50;
    uint32_t unk_54;
    uint32_t unk_58;
    uint32_t unk_5C;

    uint32_t unk_60;
    uint32_t unk_64;
    uint32_t unk_68;
    uint32_t unk_6C;

    uint32_t unk_70;
    uint32_t unk_74;
    uint32_t unk_78;
    uint32_t unk_7C;      

    //it looks like this chunk is separate structure since offset 0x2480 is used too often

    uint32_t unk_80;
    SceUID uid_10000; // UID of SceSdif (0,1,2) memblock of size 0x10000
    void* membase_10000; // membase of SceSdif (0,1,2) memblock of size 0x10000
    uint32_t unk_8C;

    uint32_t unk_90;
    int lockable_int;
    uint32_t unk_98;
    uint32_t unk_9C;

    uint32_t unk_A0;
    uint32_t unk_A4;
    uint32_t unk_A8;
    uint32_t unk_AC;

    uint32_t unk_B0;
    uint32_t unk_B4;
    uint32_t unk_B8;
    uint32_t unk_BC;
} sd_context_data;

typedef struct sd_context_part_base
{
   struct sd_context_global* gctx_ptr;
   uint32_t unk_4;
   uint32_t size; //cmd buffer size
   uint32_t unk_C; //0 for mmc however 0x200 for sd, can be size

   uint8_t unk_10; //can be padding
   uint8_t CID[15]; //this is CID data but in reverse

   uint8_t unk_20; //can be padding
   uint8_t CSD[15]; //this is CSD data but in reverse
}sd_context_part_base;

typedef struct sd_context_part_mmc // size is 0x398
{
   sd_context_part_base ctxb;
   
   uint8_t data[0x360];
   
   void* unk_390;
   uint32_t unk_394;
} sd_context_part_mmc;

typedef struct sd_context_part_sd // size is 0xC0
{
   sd_context_part_base ctxb;

   uint8_t data[0x90];
} sd_context_part_sd;

typedef struct sd_context_part_wlanbt // size is 0x398
{
   struct sd_context_global* gctx_ptr;
   
   uint8_t data[0x394];
} sd_context_part_wlanbt;

typedef struct sd_context_global // size is 0x24C0
{
    struct cmd_input commands[16];
    struct sd_context_data ctx_data;
} sd_context_global;

#pragma pack(pop)