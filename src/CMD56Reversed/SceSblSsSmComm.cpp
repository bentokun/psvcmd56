#include <string>

#include "SceSblSsSmComm.h"

#include "Constants.h"

// =============================

int sub_B86218()
{
   
   return 0;
}

int sub_B862A0()
{
   //many globals   
   return 0;
}

int sub_B864A8()
{
   
   return 0;
}

memory_block_data_entry g_B85010[0x20]; //there are 0x20 entries in SceSblSsSmComm module

int SceSblSmCommForKernel_sceSblSmCommStartSm_039c73b1(int r0, int r1, int r2, int r3, char* ctx, int* id)
{
   //many calls and subroutines

   

   return 0;
}

// =============================


int SceSblSmCommForKernel_sceSblSmCommCallFunc_db9fc204(int id, int mode, int* err_state, context_db9fc204* ctx, int size)
{
   //many globals, functionality is simplier

   //TODO: imitating size change and encryption - need to figure out what is going on here

   switch(ctx->command)
   {
   case KIRK_SERVICE_1B:
      //size is ok
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case KIRK_SERVICE_1C:
      ctx->size = 0x33;  // 0x40 -> 0x33
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case KIRK_SERVICE_1D:
      //size is ok
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case KIRK_SERVICE_1E:
      ctx->size = 0x33;  //0x51 -> 0x33
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case KIRK_SERVICE_1F:
      ctx->size = 0x20;  //0xB3 -> 0x20
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case KIRK_SERVICE_20:
      ctx->size = 0x34; //0x116 -> 0x34
      memset(ctx->data, 0xBB, ctx->size);
      break;
   }

   return 0;
}

// =============================


int SceSblSmCommForKernel_sceSblSmCommStopSm_0631f8ed(int id)
{
   
   return 0;
}