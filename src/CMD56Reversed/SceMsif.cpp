#include <stdint.h>
#include <string.h>

#include "SceSblSsMgr.h"

typedef struct SceMsif_subctx
{
}SceMsif_subctx;

#define MS_TPC_48 0x48
#define MS_TPC_49 0x49
#define MS_TPC_4A 0x4A
#define MS_TPC_4B 0x4B

int food_execute_f00d_command_1_rmauth_sm_C8D908(int* f00d_data)
{
   return 0;
}

int ms_execute_ex_set_cmd_write_short_data_C8A3A8(SceMsif_subctx *subctx, int cmd, int size, const char* source, int delay)
{
   return 0;
}

int ms_execute_ex_set_cmd_read_short_data_C8A448(SceMsif_subctx *subctx, int cmd, int size, char* dest, int delay)
{
   return 0;
}

int execute_f00d_command_2_rmauth_sm_C8D988(const char input[0x10])
{
   return 0;
}

int w_dmac5_command_0x41_C8D2F0(char* result, const char* data, int size)
{
   return 0;
}

#pragma pack(push,1)

typedef struct dmac5_41_req1 //size is 0x28
{
   char F00D_cmd2_buffer_98[0x10];
   char var_88[0x10];
   char rand_value[8];
}dmac5_41_req1;

#pragma pack(pop)

int get_sha224_digest_source_validate_card_init_f00D_C8D5FC(SceMsif_subctx *subctx, char *sha224_digest_source)
{
   int cmd1_res = 0;

   int fdres1 = food_execute_f00d_command_1_rmauth_sm_C8D908(&cmd1_res);
   if(fdres1 < 0)
      return fdres1;

   //----------------
   dmac5_41_req1 d5req1;

   //generate random number
   
   memset(d5req1.rand_value, 0, 8);

   int rdgenres1 = SceSblSsMgrForDriver_4dd1b2e5(d5req1.rand_value, 8, 1);
   if(rdgenres1 < 0)
      return rdgenres1;

   //----------------

   //save rand to temp
   char rand_B8[8];
   memset(rand_B8, 0, 8);
   memcpy(rand_B8, d5req1.rand_value, 0);

   //prepare cmd 0x48 request
   char cmd48_src[0x20];
   memset(cmd48_src, 0, 0x20);

   //8 + 1 + 0x17 = 0x20 total in bytes
   memcpy(cmd48_src, rand_B8, 8); //copy rand
   cmd48_src[8] = cmd1_res; //copy cmd1 resp 1 byte
   memset(cmd48_src + 9, 0, 0x17); //fill rest with 0

   //execute command 48
   int res48 = ms_execute_ex_set_cmd_write_short_data_C8A3A8(subctx, MS_TPC_48, 0x20, cmd48_src, 1000);
   if(res48 != 0)
      return res48; //returns not exactly this, but we dont care here

   //----------------

   char cmd49_dest[0x40];
   memset(cmd49_dest, 0, 0x40);
   
   int res49 = ms_execute_ex_set_cmd_read_short_data_C8A448(subctx, MS_TPC_49, 0x40, cmd49_dest, 1000); //gets 0x40 bytes of response

   //----------------

   memset(d5req1.F00D_cmd2_buffer_98, 0, 0x10);
   memcpy(d5req1.F00D_cmd2_buffer_98, cmd49_dest, 0x10); //copy first 0x10 bytes of 0x49 resp

   //

   memset(d5req1.var_88, 0, 0x10);
   memcpy(d5req1.var_88, cmd49_dest + 0x10, 0x10); //copy second 0x10 bytes of 0x49 resp

   int var_DC = *(d5req1.var_88 + 7);

   //

   char var_C8[8];
   memset(var_C8, 0, 8);
   memcpy(var_C8, cmd49_dest + 0x20, 8); //copy last 8 bytes of 0x49 resp

   //

   int fdres2 = execute_f00d_command_2_rmauth_sm_C8D988(d5req1.F00D_cmd2_buffer_98); //sends first 0x10 bytes of 0x49 resp to f00d
   if(fdres2 < 0)
      return fdres2;

   //----------------

   char dmac5_result_1[0x8];
   memset(dmac5_result_1, 0, 0x8);

   int dmc5res1 = w_dmac5_command_0x41_C8D2F0(dmac5_result_1, (char*)&d5req1, 0x28); //send dmac5 request with 0x20 bytes of 0x49 response and 8 bytes of random data
   if(dmc5res1 != 0)
      return dmc5res1;

   //----------------

   //verify hash, signature ?

   if(memcmp(dmac5_result_1, var_C8, 8) != 0)
      return -1; //returns not exactly this, but we dont care here

   //----------------
 
   char dmac_5_result_2[0x8];
   memset(dmac_5_result_2, 0, 0x8);

   //

   char dmac5_input[0x10];
   memset(dmac5_input, 0, 0x10);

   memcpy(dmac5_input, d5req1.rand_value, 8);
   memcpy(dmac5_input+8, d5req1.var_88 + 8, 8);

   //

   int dmc5res2 = w_dmac5_command_0x41_C8D2F0(dmac_5_result_2, dmac5_input, 0x10);
   if(dmc5res2 != 0)
      return dmc5res2;
   
   //----------------

   int D16[0] = dmac_5_result_2[0];
   int D16[4] = dmac_5_result_2[4];

   char var_B0[8];
   memset(var_B0, 0, 8);
   
   char* lr = var_B0;

   char cmd4A_src[0x20];
   memset(cmd4A_src, 0, 0x20);

   cmd4A_src[8] = 0;

   int r0 = D16[0];
   int r1 = D16[4];

   var_B0[0] = r0;
   var_B0[4] = r1;
   
   int r0 = lr[0];
   int r1 = lr[4];

   cmd4A_src[0xC] = 0;
   cmd4A_src[0x10] = 0;

   cmd4A_src[0] = r0;
   cmd4A_src[4] = r1;
   
   cmd4A_src[0x14] = 0;
      
   cmd4A_src[0x18] = 0;
   cmd4A_src[0x1C] = 0;
   
   int res4A = ms_execute_ex_set_cmd_write_short_data_C8A3A8(subctx, MS_TPC_4A, 0x20, cmd4A_src, 1000);
   if(res4A < 0)
      return res4A; //returns not exactly this, but we dont care here
   





  


   return 0;
}