#include <string>

#include "GlobalVariables.h"
#include "Constants.h"
#include "Errors.h"

#include "SceKernelDmacMgr.h"
#include "SceKernelDmacMgrGlobalConstants.h"
#include "SceKernelDmacMgrGlobalVariables.h"

#include "SceIntrmgr.h"
#include "SceSysmem.h"
#include "SceKernelDmacMgr.h"
#include "SceThreadmgr.h"
#include "SceCpu.h"

//==========================================================================

dmac_id SceDmacmgrForDriver_7cd5088a(const char* efName)
{
   int ctx = SceIntrmgrForDriver_getCurrentCpuUnkData_182ee3e3();
   if(ctx != 0)
      return SCE_KERNEL_ERROR_ILLEGAL_CONTEXT;

   result_c8672a3d* r4 = SceSysmemForKernel_functor_c8672a3d(g_008FE000.unk_20);
   
   if(r4 == 0)
      return SCE_KERNEL_ERROR_NO_MEMORY;

   memset(r4, 0x00, 0x30); //set first 12 fields to 0

   r4->gxor_30 = (((int)&g_008FE000) | 0x01);

   const char* eventFlagName = (efName == 0) ? unk_994808 : efName;

   SceUID eventFlagUid = SceThreadmgrForDriver_ksceKernelCreateEventFlag_4336baa4(eventFlagName, 0x00, 0x00, 0x00);
   if(eventFlagUid < 0)
   {
      SceSysmemForKernel_functor_571660aa(g_008FE000.unk_20, r4);
      return eventFlagUid;
   }

   r4->eventFlagUid_34 = eventFlagUid;
   r4->unk_3C = SceSysmemForDriver_udiv_e655852f(eventFlagUid);
   r4->unk_38 = 0x01;
   
   return SCE_DMAC_PACK_ID(r4);
}

//==========================================================================

int exit_loc_992EAC(int r2, int* r6)
{
   int* r0 = r6;
   int r1 = r2;
   int r0_res = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   int r0_ret = SCE_KERNEL_ERROR_ALREADY_QUEUED;
   return r0_ret;
}

//default case
int exit_loc_992EC2(int r2, int* r6)
{
   int* r0 = r6;
   int r1 = r2;
   int r0_res = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   int r0_ret = SCE_KERNEL_ERROR_INVALID_ARGUMENT;
   return r0_ret;
}

int exit_loc_992ED6(int r2, int* r6)
{
   int* r0 = r6;
   int r1 = r2;
   int r0_res = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   int r0_ret = SCE_KERNEL_ERROR_NOT_UNDER_CONTROL;
   return r0_ret;
}

int exit_loc_992EE8(int r2, int* r6)
{
   int* r0 = r6;
   int r1 = r2;
   int r0_res = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   int r0_ret = SCE_KERNEL_ERROR_NOT_INITIALIZED;
   return r0_ret;
}

int exit_loc_992EFA(int r2, int* r6)
{
   int* r0 = r6;
   int r1 = r2;
   int r0_res = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   int r0_ret = SCE_KERNEL_ERROR_CANCELING;
   return r0_ret;
}

int SceDmacmgrForDriver_fce4171a(dmac_id unk0, int unk1, int unk2)
{
   /*
   int r0 = r0 >> 1;
   int r5 = _008FE000;
   int r4 = r0 << 2;
   int r0 = r5 | 1;
   int r3 = r4[0x30]
   //SUB		SP, SP,	#0xC

   int r10 = r1;
   int r11 = r2;

   if(r3 != r0)
      return SCE_KERNEL_ERROR_INVALID_ARGUMENT;

   int r6 = r4 + 0x2C;
   int r0 = r6;
   int r0 = SceCpuForDriver_lock_int_d32ace9e(r0);
   int r3 = r4[0x38];
   int r2 = r0;
   int r0 = r3 << 0x1F;
   if(true) //BPL
      return exit_loc_992EE8();

   int r3 = r4[0x38];
   int r1 = r3 << 0x1C;
   if(true) //BMI
      return exit_loc_992EAC();

   int r3 = r4[0x14];
   if(r3 != 0)
      return exit_loc_992EAC();

   int r3 = r4[0x38];
   int r3 = r3 << 0x19;
   if(true) //BMI
      return exit_loc_992EFA();

   int r3 = r10 - 0x10;
   if(r3 > 0x04)
      return exit_loc_992EC2();

   //this are not exactly switch constants - just imitation for now
   switch(r3)
   {
   case 20: // loc_992E32
      {
         int r3 = r5[0x18];
         if(r3 == 0)
            return exit_loc_992EC2();

         int r3 = var2C;
         int r3 = &_008FE278;
         int r7 = r3;
         var2C = r3;
         r4[0x10] = r3;
      }
      break;
   case 0: //loc_992E6C
      {
         int r9 = &_008FE02C;
         r4[0x10] = r9;
         int r7 = r9;
      }
   case 0: //loc_992E7C
      {
         int r8 = &_008FE060;
         r4[0x10] = r4;
         int r7 = r8;
      }
      break;
   case 18: //loc_992E8C
      {
         if(r11 > 0x0F)
            return exit_loc_992EC2();
         //RSB.W		R11, R11, R11,LSL#3
         int r7 = r5 + (r1 << 2);
         int r7 = r7 + 0x94;
         r4[0x10] = r7;
      }
      break;
   case 0: //loc_992E48
      {
         int r7 = _008FE254;
         r4[0x10] = 74;
      }
      break;
   }
  
	int r3 = r7[0x10];
   if(r3 == 0)
      return exit_loc_992ED6();

   int r5 = r4[0x38];
   int r3 = 0xFFDF;
   int r0 = r6;
   r4[0x3A] = r10;
   int r1 = r2;
   int r3 = r3 & r5;
   r4[0x34] = r3;
   int r0 = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   int r0 = 0;

   return r0;
   */

   return 0;
}

//========================================

int exit_loc_992172(int r4)
{
   int r0 = r4;
   return r0;
}

int sub_99214C()
{
   /*
   int r5 = &_008FE000;
   
   //loc_992156:
   while(true)
   {
      int r4 = r5[0x28];
      int r3 = &_008FE000;
      int r0 = r3 + 0x28;
      int r1 = r4;
   
      if(r4 == 0)
      {
         r0 = r3[0x20];
         SceSysmemForKernel_functor_c8672a3d(r0);
         int r4 = r0;
         if(r0 == 0)
            return exit_loc_992172(r4);
         
         int r0 = r0 + 0x20;
         int r1 = r4 + 0x10;
         int r0 = SceSysmemForDriver_ksceKernelGetPaddr_8d160e65(r0, r1);
         int r3 = r4[0x10];
         int r2 = 0;
         r4[0x10] = r2;
         int r3 = r3 | 1;
         r4[0x10] = r3;
         return exit_loc_992172(r4);
      }
      else
      {
         int r2 = r4[0x00];
         int r0 = SceCpuForDriver_atomic_set_xor_cda96e81(r0, r1, r2);
         if(r4 == r0)
            return exit_loc_992172(r4);

         //goto loc_992156
      }
   }
   */

   return 0;
}

//========================================

int exit_loc_992402()
{
   int r3 = SCE_KERNEL_ERROR_INVALID_ARGUMENT;
   int r0 = r3;
   return r0;
}

int exit_loc_992368()
{
   int r3 = SCE_KERNEL_ERROR_NO_MEMORY;
   int r0 = r3;
   return r0;
}

int exit_loc_9923E8()
{
   /*
   int r7 = arg_C;
   int r2 = 0;
   r0[0x2C] = r3;
   int r1 = 0xFFFFFFFF;
   int r3 = r2;
   r0[0x3C] = r1;
   r0[0x00] = r2;
   r7[0x00] = r0;
   int r0 = r3;
   return r0;
   */

   return 0;
}

int sub_992288(int unk0, int unk1, int unk2, int unk3,
               int arg_0, int arg_4, int arg_8, int arg_C)
{
   /*
   int var_40;
   int var_3C;
   int var_38;
   int var_34;
   int var_30;
   int var_2C;

   //-----------------------

   int r0 = unk0;
   int r1 = unk1;
   int r2 = unk2;
   int r3 = unk3;

   int r7 = r0;
   int r10 = arg_4;

   if(r1 == 0)
      return exit_loc_992402();
   
   int r5 = r3[0];
   if(r5 == 0)
      return exit_loc_992402();

   int r4 = r2[0];
   int r2 = arg_0;
   int r0 = r10[0x18];
   int r3 = r10[0x08];
   int r6 = r2[0x00];
   int r1 = r4 + (r1 << 3);
   var_3C = r1;
   int r1 = r3 & 0xFF000000;
   int r9 = r6 + (r5 << 3);
   var_34 = r1;
  
   if(r2 != 0)
   {
      int r2 = r2 - 1;
   }

   int r0 = r0 >> 0x10;
   int r5 = 0;
   int r11 = r9;
   var_40 = r7;
   if(r0 != 0) //not sure
   {
      int r0 = r0 + 0xFFFFFFFF;
   }

   int r8 = r5;
   int r0 = r0 | r2;
   int r2 = r3 & 0x0F000000;
   int r3 = r3 & 0xF0000000;
   var_38 = r0;
   var_2C = r2;
   int r9 = r5;
   var_30 = r3;
   int r0 = sub_99214C();
   if(r0 == 0)
      return exit_loc_992368();

   //loc_9922F4:
   int r1 = r4[0];
   r0[0x0C] = r8;
   r0[0x20] = r1;
   int lr = r6[0];
   r0[0x24] = lr;
   int r3 = r4[0x04];
   int r2 = r6[0x04];
   if(r3 < r2)
   {
      if(r3 <= r2) //why this check ?
      {
         r4 = r4 + 0x08;
         r6 = r6 + 0x08;
      }

      if(true) //do not understand this
      {
         //goto loc_99231C
      }
      else
      {
         int r7 = var_2C;
         if(r7 == 0)
         {
            int r1 = r1 + r2;
            int r3 = r3 - r2;
            r4[0x00] = r1;
            r4[0x04] = r2;
            r4[0x08] = r3;
         }

         r1 = var_40;
         int r3 = r2;
         int r6 = r6 + 0x08;
         int r8 = r8 + r3;
         int r2 = r10[0x0C];
         if(r1 != 0x13)
         {
            //goto loc_992328
         }
         else
         {
            //goto loc_99239C
         }
      }
   }
   else
   {
      int r7 = var_30;
      if(r7 == 0)
      {
         int r1 = r3 + lr;
         int r2 = r2 - r3;
         r6[0x00] = r1;
         r6[0x04] = r2;
      }

      int r4 = r4 + 0x08;

      //goto loc_99231C
   }

   //loc_99231C
   {
      int r1 = var_40;
      int r8 = r8 + r3;
      int r2 = r10[0x0C];
      if(r1 == 0x13)
      {
         //goto loc_99239C
      }
      else
      {
         //goto loc_992328
      }
   }

   //loc_992328
   {
      int r7 = var_38;
      int r3 = r3 & r7; //tst - probably r3 is not touched
      if(r3 != 0) //not sure
         return loc_992402();

      int r1 = var_34;
      int r3 = r3 | r1;
      r0[0x28] = r3;

      //goto loc_992334
   }

   //loc_99239C
   {
      int r1 = r10[0x10];
      int lr = r2 & 0x07;
      r0[0x28] = r3;
      int r3 = r10[0x14];
      r0[0x30] = r1;
      r0[0x34] = r3;

      if(lr != 3)
      {
         //goto loc_992334
      }
      else
      {
         int r3 = r2 & 0xC00;
         if(r3 = 0x400)
         {
            if(r9 == 0)
            {
               //goto loc_992334
            }
            else
            {
               int r2 = r2 | 0xC00;
               //goto loc_992334
            }
         }
         else
         {
            if(r3 == 0x800)
            {
               int r2 = r2 | 0xC00;
               //goto loc_992334
            }
            else
            {
               if(r3 != 0)
               {
                  //goto loc_992334
               }
               else
               {
                  if(r9 == 0)
                  {
                     int r2 = r2 & (~0xC00);
                     int r2 = r2 | 0x400;
                     //goto loc_992334
                  }
                  else
                  {
                     int r2 = r2 | 0xC00;
                     //goto loc_992334
                  }
               }
            }
         }
      }
   }

   //goto loc_992334
   {
      int r3 = r10[0x18];
      int r2 = r2 & ~(0x3000);
      r0[0x2C] = r2;
      r0[0x04] = r5;
      r0[0x38] = r3;
      
      if(r5 == 0)
      {
         int r2 = arg_8;
         r2[0] = r0;
      }
      else
      {
         int r3 = r0[0x10];
         r5[0] = r0;
         r5[0x3C] = r3;
      }

      int r3 = var_3C;
      int r9 = r9 + 1;
      r0[0x08] = r10;
      if(r11 > r6)
      {
         if(r3 > r4)
         {
            int r5 = r0;
            int r0 = sub_99214C();
            if(r0 == 0)
               return exit_loc_992368();
            
            //goto loc_9922F4
         }
         else
         {
            //goto loc_9923DE
         }
      }
      else
      {
         //goto loc_9923DE
      }
   }

   //loc_9923DE
   {
      int r7 = var_40;
      int r3 = r10[0x0C];
      if(r7 != 0x13)
         return exit_loc_9923E8();

      int r2 = r3 & 0x07;
      if(r2 != 3)
         return exit_loc_9923E8();

      int r2 = r3 & 0xC00;
      if(r2 == 0x400)
      {
         if(r9 > 1)
            int r3 = r3 | 0xC00;

         return exit_loc_9923E8();
      }
      else
      {
         if(r2 != 0x800)
         {
            if(r2 != 0)
               return exit_loc_9923E8();

            if(r9 <= 1)
               return exit_loc_9923E8();
         }
         
         int r3 = r3 & (~0xC00);
         int r3 = r3 | 0x800;
         return exit_loc_9923E8();
      }
   }
   */

   return 0;
}

//========================================

int exit_loc_9928F6(int r0, int* r5, int var_14)
{
   int r2 = var_14;
   int r3 = r5[0];
   if(r2 == r3)
      return r0;
   else
      return STACK_CHECK_FAIL;
}

int sub_99289C(int unk0)
{
   /*
   int var_1C;
   int var_18;
   int var_14;

   int r5 = &var_009EA004;
   int r4 = r2;
   int r6 = 0x14;
   int r3 = r5[0];
   int r2 = r1 & (~0xFF000000);
   var_1C = r0;
   int r1 = r4;
   r4[0] = r6;
   int r0 = &var_1C;
   var_18 = r2;
   var_14 = r3;
   int r0 = SceSysmemForDriver_ksceKernelGetPaddrList_e68beebd(r0, r1);
   if(r0 < 0)
   {
      return exit_loc_9928F6(r0, r5, var_14);
   }
   else
   {
      int r1 = r4[0x0C];
      if(r1 == 1)
         int r0 = 0;
      
      if(r1 == 1)
      {
         return exit_loc_9928F6(r0, r5, var_14);
      }
      else
      {
         int r3 = &_008FE000;
         int r1 = r1 << 3;
         int r0 = r3[0x24];
         int r0 = SceSysmemForDriver_ksceKernelMemPoolAlloc_7b4cb60a(r0, r1);
         int r3 = r0;
         if(r3 == 0)
         {
            int r0 = SCE_KERNEL_ERROR_NO_MEMORY;
            return exit_loc_9928F6(r0, r5, var_14);
         }
         else
         {
            int r2 = r4[0x0C];
            int r0 = &var_1C;
            r4[0x10] = r3;
            int r1 = r4;
            r4[0x04] = r2;
            int r0 = SceSysmemForDriver_ksceKernelGetPaddrList_e68beebd(r0, r1);
            //AND.W           R0, R0, R0,ASR#31

            return exit_loc_9928F6(r0, r5, var_14);
         }
      }
   }
   */

   return 0;
}

//========================================

int sub_9921FC(int unk0, int unk1)
{
   /*
   int r5 = r0;
   int r3 = r0[0x14];
   int r6 = &008FE000;
   int r9 = r1;
   int r7 = r0;
   int r8 = r5[0];
   if(r3 == 0)
   {
      //goto loc_99224A
   }
   else
   {
      //loc_992216:
      if(r5 != r9)
      {
         int r3 = r8[0x14];
         if(r3 != 0)
         {
            //goto loc_992240
         }
      }
      
      //loc_992220:
      int r4 = r6[0x28];
      int r0 = 0x008FE028;
      int r2 = r7;
      r5[0] = r4;
      int r1 = r4;
      int r0 = SceCpuForDriver_atomic_set_xor_cda96e81(r0, r1, r2);
      if(r4 != r0)
      {
         //goto loc_992220
      }
      
      if(r5 == r9)
         return r0;

      //loc_99223C:
      int r3 = r8[0x14];

      //loc_992240:
      int r5 = r8;
      int r8 = r5[0];
      if(r3 != 0)
      {
         //goto loc_992216
      }
   }

   //loc_99224A
   int r0 = r6[0x20];
   int r1 = r5;
   int r0 = SceSysmemForKernel_functor_571660aa(r0, r1);
   int r7 = r8;
   if(r5 != r9)
   {
      //goto loc_99223C
   }
   else
   {
      return r0;
   }
   */

   return 0;
}

//========================================

int exit_loc_992A7C(int r0, int var_74, int var_2C)
{
   /*
   int r5 = var_74;
   int r2 = var_2C;
   int r3 = r5[0];
   if(r2 == r3)
   {
      return r0;
   }
   else
   {
      return STACK_CHECK_FAIL;
   }
   */

   return 0;
}

int exit_loc_992A76(int var_74, int var_2C)
{
   return exit_loc_992A7C(SCE_KERNEL_ERROR_INVALID_ARGUMENT, var_74, var_2C);
}

int exit_loc_992C20(int var_74, int var_2C)
{
   return exit_loc_992A7C(SCE_KERNEL_ERROR_NO_MEMORY, var_74, var_2C);
}

int exit_loc_992C10(int r9, int var_74, int var_2C)
{
   int r0 = r9;
   return exit_loc_992A7C(r0, var_74, var_2C);
}

int sub_992910(int unk0, int unk1, int unk2)
{
   /*
   //these are most likely arguments
   int var_90;
   int var_8C;
   int var_88;
   int var_84;

   int var_80;
   int var_7C;
   int var_78;
   int var_74;
   int var_70;
   int var_6C;
   int var_68;
   int var_64;
   int var_60;
   int var_5C;
   int var_58;
   int ptr_54;
   int var_50;
   int var_4C;
   int var_48;
   int var_44;
   int var_40;
   int var_3C;
   int var_38;
   int var_34;
   int var_30;
   int var_2C;

   //-----------------------------

   int r0 = unk0;
   int r1 = unk1;
   int r2 = unk2;

   int r5 = &var_009EA004;
   int r3 = r2 - 1;
   int r4 = r2;
   int r3 = r3 + 3;
   int r2 = r5[0];

   var_74 = r5;
   var_7C = r0;
   var_2C = r2;

   if(true) //bhi - do not understand - complex comparison
      return exit_loc_992A76(var_74, var_2C);

   if(r1 == 0x10)
   {
      #pragma region
      int r3 = 1;
      int r0 = &_008FE000;
      int r6 = 0;
      int r8 = r3;
      var_60 = r3;
      int r3 = &var_34;
      int r5 = r6;
      var_78 = r0;
      int r7 = &var_3C;
      int r11 = &var_40;
      int r10 = &var_6C;
      ptr_54 = r3;
      #pragma endregion

      //goto loc_992BB0 - down
   }
   else
   {
      if(r1 > 0x10)
      {
         if(r1 == 0x11)
         {
            #pragma region
            int r6 = 0;
            int r10 = &_008FE000;
            int r5 = r6;
            int r7 = &var_3C;
            int r11 = &var_64;
            int r8 = 1;
            #pragma endregion

            //goto loc_992ABA - down
         }
         else
         {
            #pragma region
            if(r1 != 0x100)
               return exit_loc_992A76(var_74, var_2C);

            int r0 = sub_99214C();
            int r5 = r0;
            if(r5 == 0)
               return exit_loc_992C20(var_74, var_2C);

            int r0 = sub_99214C();
            int r6 = r0;
            if(r0 == 0)
            {
               int r0 = r5;
               int r1 = r5;
               int r0 = sub_9921FC(r0, r1);
               return exit_loc_992C20(var_74, var_2C);
            }

            int r1 = r4[0x08];
            int r3 = 0;
            int r2 = r4[0x0C];
            int r12 = r4 + 0x20;
            int r0 = r4[0x00];
            int r11 = 0xFFFFFFFF;
            int r7 = r4[0x04];
            r5[0x28] = r1;

            int r1 = r4[0x18];
            r5[0x38] = r1;
            int r1 = r4[0x1C];
            r5[0x2C] = r2;
            r5[0x3C] = r1;
            int r1 = r4[0x2C];
            r5[0x20] = r0;
            r5[0x24] = r7;
            int r9 = r4[0x3C];
            int r8 = r4[0x20];
            int lr = r4[0x24];
            int r2 = r1;
            int r7 = r4[0x28];
            int r0 = r4[0x38];
            int r10 = r6[0x10];
            r5[0x00] = r6;
            r5[0x08] = r4;
            r5[0x0C] = r3;
            r5[0x04] = r3;
            r9[0x1C] = r10;
            r6[0x20] = r8;
            r6[0x24] = lr;
            r6[0x28] = r7;
            r6[0x2C] = r1;
            r6[0x38] = r0;
            r6[0x0C] = r3;
            
            r6[0x00] = r0;
            r6[0x04] = r1;
            r6[0x08] = r2;
            r6[0x0C] = r3;

            r6[0x3C] = r11;
            r6[0x08] = r12;

            #pragma endregion

            //goto loc_992A56 - down
         }
      }
      else
      {
         if(r1 == 0x00)
         {
            #pragma region
            int r5 = r1;
            int r7 = r1;
            int r6 = r1;
            #pragma endregion
            
            //goto loc_992B4E - down
         }
         else
         {
            #pragma region
            if(r1 != 0x01)
               return exit_loc_992A76(var_74, var_2C);

            int r0 = &_008FE000;
            int r6 = 0;
            r3 = &var_34;
            int r8 = r1;
            int r5 = r6;
            var_78 = r0;
            int r7 = &var_3C;
            int r11 = &var_64;
            int r10 = &var_40;
            var_4C = r1;
            var_40 = r3;
            #pragma endregion

            //goto loc_99297A - down
         }
      }
   }

   //loc_99297A
   {
      #pragma region
      int r1 = r4[0x08];
      int r2 = r11;
      int r3 = r4[0x04];
      var_60 = r8;
      int r0 = r1 & (~0xFF000000);
      ptr_54 = r7;
      var_34 = r3;
      var_30 = r0;
      int r0 = r4[0];
      int r0 = sub_99289C(r0);
      if(r0 < 0)
         return exit_loc_992A7C(r0, var_74, var_2C);

      int r1 = var_7C;
      int lr = &var_68;
      int r3 = &var_4C;
      int r2 = &ptr_54;
      short r0 = r1[0x3A];
      int r1 = &var_6C;
      var_88 = r1;
      var_90 = r10;
      var_8C = r4;
      
      int r1 = var_60;
      var_84 = lr;
      int r0 = sub_992288(r0, r1, r2,r3, ?, ?, ?, ?);
      int r3 = var_60;
      int r9 = r0;
      if(r3 > 1)
      {
         int r2 = var_78; //is this argument???
         int r1 = ptr_54;
         int r0 = r2[0x24];
         SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(r0, r1);
      }
      
      if(r9 <= 0)
         return exit_loc_992C10(r9, var_74, var_2C);

      if(r5 != 0)
      {
         int r3 = var_6C;
         int r2 = r3[0x10];
         r6[0x00] = r3;
         r6[0x3C] = r2;
         r3[0x04] = r6;
         int r6 = var_68;
      }
      else
      {
         int r5 = var_6C;
         int r6 = var_68;
      }

      #pragma endregion

      int r4 = r4[0x1C];
      int r2 = r1 + 1;
      if(r2 == 0) // is this correct
      {
         //goto loc_992C14 - down
      }
      else
      {
         //goto loc_99297A - up
      }
   }

   //loc_992C14
   {
      int r2 = r6[0x2C];
      //goto loc_992A56 - down
   }

   //loc_992A56
   {
      #pragma region

      int r0 = var_7C;
      int r2 = r2 | 0x1000;
      int r3 = r0[0x18];
      int r2 = r6[0x2C];
      if(r3 == 0)
      {
         r1 = var_7C;
         r1[0x18] = r5;
      }
      else
      {
         int r3 = r0[0x1C];
         int r2 = r5[0x10];
         r3[0x00] = r5;
         r3[0x3C] = r2;
      }

      int r5 = var_7C;
      int r0 = 0;
      r5[0x1C] = r6;
      return exit_loc_992A7C(r0, var_74, var_2C);

      #pragma endregion
   }

   //loc_992ABA
   {
      #pragma region

      var_60 = r8;
      int r2 = r11;
      ptr_54 = r7;
      int r1 = r4[0x08];
      int r0 = r4[0];
      int r0 = sub_99289C(r0);
      if(r0 < 0)
         return exit_loc_992A7C(r0, var_74, var_2C);

      int r0 = &var_34;
      var_4C = r8;
      var_40 = r0;
      int r2 = var_50;
      int r0 = r4[0x04];
      int r1 = r4[0x08];
      int r0 = sub_99289C(r0);
      if(r0 < 0)
      {
         int r3 = &_008FE000;
         int r9 = r0;
         int r1 = ptr_54;
         int r0 = r3[0x24];
         int r0 = SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(r0, r1);
         int r0 = r9;
         return exit_loc_992A7C(r0, var_74, var_2C);
      }

      int r1 = var_7C;
      int r2 = &var_40;
      int r3 = &var_6C;
      int lr = &var_68;
      short r0 = r1[0x3A];

      //stmea - not sure
      var_90 = r2;
      var_8C = r3;
      var_88 = r4;

      int r2 = &ptr_54;
      var_88 = r3;
      int r3 = &var_4C;
      int r1 = var_60;
      var_84 = lr;
      int r0 = sub_992288(r0, r1, r2,r3, ?, ?, ?, ?);
      int r3 = var_60;
      int r9 = r0;
      if(r3 > 1)
      {
         int r0 = r10[0x24];
         int r1 = ptr_54;
         int r0 = SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(r0, r1);
      }
            
      int r3 = var_4C;
      if(r3 > 1)
      {
         int r0 = r10[0x24];
         int r1 = var_40;
         int r0 = SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(r0, r1);
      }

      if(r9 < 0)
         return exit_loc_992C10(r9, var_74, var_2C);

      if(r5 != 0)
      {
         r3 = var_6C;
         int r2 = r3[0x10];
         r6[0x00] = r3;
         r6[0x3C] = r2;
         r3[0x04] = r6;
         r6 = var_68;
      }
      else
      {
         r5 = var_6C;
         r6 = var_68;
      }

      #pragma endregion

      int r4 = r4[0x1C];
      int r0 = r4 + 1;
      if(r0 == 0)
      {
         //goto loc_992C14 - up
      }
      else
      {
         //goto loc_992ABA - up
      }
   }

   //loc_992B4E
   {
      #pragma region
      int r0 = sub_99214C();
      if(r0 == 0)
         return exit_loc_992C20(var_74, var_2C);

      int r3 = r4[0x04];
      r0[0x24] = r3;
      int r3 = r4[0x18];
      int r1 = r4[0x08];
      int r2 = r4[0x0C];
      r0[0x38] = r3;
      int r3 = r4[0x00];
      r0[0x28] = r1;
      r0[0x2C] = r2;
      r0[0x0C] = r7;
      r0[0x20] = r3;
      r0[0x00] = r7;
      r0[0x04] = r6;
      r0[0x08] = r4;
      if(r5 != 0)
      {
         r3 = r0[0x10];
         r6[0x00] = r0;
         r6[0x3C] = r3;
      }
      else
      {
         r5 = r0;
      }

      #pragma endregion

      int r4 = r4[0x1C];
      int r6 = r6;
      int r3 = r4 + 1;
      if(r3 == 0)
      {
         r4 = r0[0x3C];
         //goto loc_992A56 - up
      }
      else
      {
         //goto loc_992B4E - up
      }
   }

   //loc_992BB0
   {
      #pragma region

      int r1 = r4[0x08];
      int r2 = &var_50;
      int r3 = r4[0x00];
      var_4C = r8;
      r0 = r1 & (~FF000000);
      var_40 = r7;
      var_34 = r3;
      var_30 = r0;
      int r0 = r4[0x04];
      int r0 = sub_99289C(r0);
      if(r0 < 0)
         return exit_loc_992A7C(r0, var_74, var_2C);

      int r1 = var_7C;
      int lr = &var_68;
      int r2 = &ptr_54;
      int r3 = &var_4C;
      short r0 = r1[0x3A];
      int r1 = var_60;
      int r11 = var_90;
      var_8C = r4;
      var_88 = r10;
      var_84 = lr;
      int r0 = sub_992288(r0, r1, r2,r3, ?, ?, ?, ?);
      int r2 = var_4C;
      int r9 = r0;
      if(r2 > 1)
      {
         int r2 = var_78;
         int r1 = var_40;
         int r0 = r4[0x24];
         int r0 = SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(r0, r1);
      }
      
      if(r9 < 0)
         return exit_loc_992C10(r9, var_74, var_2C);

      if(r5 != 0)
      {
         int r3 = var_6C;
         int r2 = r3[0x10];
         r6[0x00] = r3;
         r6[0x3C] = r2;
         r3[0x04] = r6;
         r6 = var_68;
      }
      else
      {
         int r5 =  var_6C;
         int r6 = var_68;
      }

      #pragma endregion

      //loc_992BAA:
      int r4 = r4[0x1C];
      int r1 = r4 + 1;
      if(r1 == 0)
      {
         //goto loc_992C14 - up
      }
      else
      {
         //goto loc_992BB0 - up
      }
   }

   */
   return 0;
}

//========================================

int exit_loc_993062(int* r6, int r10)
{
   SceCpuForDriver_unlock_int_7bb9d5df(r6, r10);
   return SCE_KERNEL_ERROR_INVALID_ARGUMENT_SIZE;
}

int exit_loc_993096(int* r6, int r10)
{
   SceCpuForDriver_unlock_int_7bb9d5df(r6, r10);
   return SCE_KERNEL_ERROR_NOT_INITIALIZED;
}

int exit_loc_993082(int* r6, int r10)
{
   SceCpuForDriver_unlock_int_7bb9d5df(r6, r10);
   return SCE_KERNEL_ERROR_ALREADY_QUEUED;
}

int exit_loc_9930AA(int* r6, int r10)
{
   SceCpuForDriver_unlock_int_7bb9d5df(r6, r10);
   return SCE_KERNEL_ERROR_CANCELING;
}

int exit_loc_993074(int r5, int* r6, int r10)
{
   SceCpuForDriver_unlock_int_7bb9d5df(r6, r10);
   return r5;
}

//r0 is id
//r1 is structure of size 0x20
//r2 is 0x00
//r3 is 0x01 or 0x11
int SceDmacmgrForDriver_167079fc(dmac_id id, local_01a599e0* r1, int r2, int r3)
{
   /*
   int r0 = r0 >> 1;
   int r5 = 0x8FE000;
   int r4 = r0 << 2;
   int r6 = r5 | 1;
   int r0 = r4[0x30];
   int r8 = r1;
   int r5 = r2;
   int r9 = r3;

   if(r0 != r6)
      return SCE_KERNEL_ERROR_INVALID_ARGUMENT;

   int r6 = r4 + 0x2C;
   int r0 = r6;
   int r0 = SceCpuForDriver_lock_int_d32ace9e(r0);
   int r10 = r0;

   if(r5 != 0)
   {
      int r3 = r5[0];
      if(r4[0x3A] == 0x13)
      {
         if(r3 != 0x5C)
            return exit_loc_993062(r6, r10);
      }
      else
      {
         if(r3 == 0x0C)
            return exit_loc_993062(r6, r10);
      }
   }
   
   //loc_992FDE:

   short r3 = r4[0x38];
   int r1 = r3 << 0x1F;
   if(r1 <= 0) // do not understand this check
      return exit_loc_993096(r6, r10);

   short r3 = r4[0x38];
   int r2 = r3 << 0x1C;
   if(r2 < 0) // do not understand this check
      return exit_loc_993082(r6, r10);

   int r3 = r4[0x14];
   if(r3 != 0)
      return exit_loc_993082(r6, r10);

   short r3 = r4[0x38];
   int r3 = r3 << 0x19;
   if(r3 < 0)
      return exit_loc_9930AA(r6, r10);

   int r0 = r4[0x18];
   if(r0 != 0)
   {
      int r1 = r4[0x1C];
      sub_9921FC(r0, r1);
   }

   int r2 = 0;
   int r3 = r2;
   int r2 = 0x07FC0000; // I SAW THIS CONSTANT ALREADY! - this is a bit mask

   r4[0x1C] = r3;
   r4[0x20] = r2;
   r4[0x18] = r3;

   if(r5 != 0)
   {
      short r3 = r4[0x3A];
      int r7 = r5[0x04];

      r7 = r7 | 0x7F80000; // this is also a bit mask

      if(r3 != 0x13)
         r3 = r5[0x08];

      r7 = r7 | 0x40000;
      if(r7 == 0x00) //not sure about this check
         r5 = r5 + 0x0C;

      r4[0x20] = r7;

      if(r7 == 0x00) //not sure about this check
         r4[0x28] = r5;
      else
         r4[0x28] = r3;
   }

   int r1 = r9;
   int r2 = r8;
   int r0 = r4;
   sub_992910(r0, r1, r2);
   int r5 = r0 - 0;
   if(r5 < 0)
   {
      return exit_loc_993074(r5, r6, r10);
   }
   else
   {
      short r2 = r4[0x38];
      short r3 = 0xFFDF;
      int r6 = r6;
      int r1 = r10;
      int r3 = r3 & r2;
      r4[0x38] = r3;
      SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
      int r0 = 0;
      return r0;
   }
   */
   return 0;
}

//==========================================================================

int exit_loc_993152(int r0, int var_24)
{
   if(var_24 == var_009EA004)
      return r0;
   else
      return STACK_CHECK_FAIL;
}

//id is a packed pointer to structure result_c8672a3d* created by SceSysmemForKernel_functor_c8672a3d
//data is structure of size 0x6C - it contains pointer to a buffer that will be copied as a key later in SblGcAuthMgr
//unk2 is 0x01 or 0x11 (int our case it is 0x11)
int SceDmacmgrForDriver_01a599e0(dmac_id id, locals_B99674* data, int unk2)
{
   int var_48; // TODO: is it used ?
   local_01a599e0 local;
   int var_24 = var_009EA004;

   if(data == 0)
      return exit_loc_993152(SCE_KERNEL_ERROR_INVALID_ARGUMENT, var_24);

   result_c8672a3d* ptr_9 = SCE_DMAC_UNPACK_ID(id);
   int gxor = (((int)&g_008FE000) | 1);
   
   if(ptr_9->gxor_30 != gxor)
      return exit_loc_993152(SCE_KERNEL_ERROR_INVALID_ARGUMENT, var_24);

   if(ptr_9->unk_3A == 0x13)
   {
      local.var_34 = data->unk_1C;
      local.paddr_30 = data->paddr_20;
   }

   local.source_vaddr_44 = data->source_vaddr_0;
   local.source_paddr_40 = data->source_paddr_4;
   local.size_3C = data->size_8;
   local.flag_38 = data->flag_C;
   local.var_2C = data->unk_10; //TODO: unknown and do not know how it is initialized
   local.var_28 = 0xFFFFFFFF;

   int res_0 = SceDmacmgrForDriver_167079fc(id, &local, 0x00, unk2);

   if(res_0 < 0)
      return exit_loc_993152(res_0, var_24);

   if(ptr_9->unk_3A != 0x13)
      ptr_9->unk_28 = data->unk_18;
   else
      ptr_9->unk_28 = &data->unk_1C;

   int bits = (data->unk_14) & (~0x07FC0000); // TODO: need to test this - BTW this mask is used in other places as well!
   ptr_9->unk_20 = bits | ptr_9->unk_20;

   return exit_loc_993152(0, var_24);
}

//========================================

struct input2_992460_r2
{
   int unk_0;
   int unk_4;
   int unk_8;
   int unk_C;
   int unk_10;
   int unk_14;
   int unk_18;
   int unk_1C;
   int unk_20;
   int unk_24;
   int unk_28;
   int unk_2C;
   int unk_30;
   int unk_34;
   
   //...

   int unk_200[16]; //0x40 bytes
};

struct input2_992460_4
{
   int unk_0;
   int unk_4;
   int unk_8;
   int unk_C;
   int unk_10;

   int unk_14;
   int unk_18;
   int unk_1C;
   int unk_20;
   int unk_24;
   int unk_28;
   int unk_2C;
   int unk_30;
   int unk_34;
   int unk_38;
   int unk_3C;
   int unk_40;
   int unk_44;
   int unk_48;
   int unk_4C;
};

struct input2_992460_28
{
   int unk_0;
   input2_992460_4* unk_4;
   int unk_8;
   int unk_C;
   int unk_10;
};

struct input2_992460_18
{
   int unk_0;
   int unk_4;
   int unk_8;
   int unk_C;

   int unk_10;
   int unk_14;
   int unk_18;
   int unk_1C;

   int unk_20;
   int unk_24;
   int unk_28;
   int unk_2C;
};

struct input2_992460
{
   int unk_0;
   int unk_4;
   int unk_8;
   int unk_C;

   int unk_10;
   int unk_14;
   input2_992460_18* unk_18;
   int unk_1C;

   int unk_20;
   int unk_24;
   input2_992460_28* unk_28;
   int unk_2C;

   int unk_30;
   int unk_34;
   
   char unk_38;
   char unk_39;

   int unk_3A;
};

struct input1_992460 //looks like to be array or contain array at offset 0
{
   input2_992460* unk_0;
   input2_992460* unk_4;
   int unk_8;
   int unk_C;

   // ...

   int unk_10C;
};

void sub_992460(input1_992460* r0, input2_992460* r1)
{
   /*
   int r3 = r0->unk_C;
   if(r3 == 0)
      return;

   //CLZ.W		R2, R3
   int r7 = r0 + 0x10C;
   int r2 = 2;
   int r5 = r1->unk_3A;
   int r2 = r0 + (r2 << 3);
   int lr = 1;
   int r6 = r1->unk_20;
   int r4 = r2 + 4;

   input2_992460_r2* r2 = r2[0x04];
   int r7 = r7 - r4;
   
   //MOV.W		R7, R7,ASR#3
   int r7 = lr << r7;
   int r3 = r3 - r7;

   r0->unk_C = r3;
   r4[0x04] = r1;
   r1->unk_14 = r4;
   r2->unk_2C = r6;

   if(r5 == 0x13)
   {
      #pragma region loc_9924D0
      input2_992460_28* r4 = r1->unk_28;
      int r3 = r4->unk_0;
      int r5 = r4->unk_8;
      int r6 = r4->unk_C;
      int r7 = r4->unk_10;
      input2_992460_4* r4 = r4->unk_4;

      int r5 = r4->unk_10;
      int r6 = r4->unk_8;

      r2->unk_10 = r3;
      r2->unk_14 = r7;
      r2->unk_30 = r6;
      r2->unk_200[0] = r5;

      int r3 = r4->unk_14;
      r2->unk_200[1] = r3;

      int r3 = r4->unk_18;
      r2->unk_200[2] = r3;

      int r3 = r4->unk_1C;
      r2->unk_200[3] = r3;
      
      int r3 = r4->unk_20;
      r2->unk_200[4] = r3;
      
      int r3 = r4->unk_24;
      r2->unk_200[5] = r3;

      int r3 = r4->unk_28;
      r2->unk_200[6] = r3;

      int r3 = r4->unk_2C;
      r2->unk_200[7] = r3;

      int r3 = r4->unk_30;
      r2->unk_200[8] = r3;

      int r3 = r4->unk_34;
      r2->unk_200[9] = r3;

      int r3 = r4->unk_38;
      r2->unk_200[10] = r3;

      int r3 = r4->unk_3C;
      r2->unk_200[11] = r3;

      int r3 = r4->unk_40;
      r2->unk_200[12] = r3;

      int r3 = r4->unk_44;
      r2->unk_200[13] = r3;

      int r5 = r4->unk_48;
      input2_992460_18* r3 = r1->unk_18;

      r2->unk_200[14] = r5;

      int r4 = r4->unk_4C;

      r2->unk_200[15] = r4;
      #pragma endregion
   }
   else
   {
      #pragma region
      input2_992460_18* r3 = r1->unk_18;
      int r4 = r3->unk_2C;
      int r4 = r4 & 0x0C;
      if(r4 == 0x0C)
      {
         r4 = r1->unk_28;
         r2->unk_34 = r4;
      }
      #pragma endregion
   }

   int r3 = r3->unk_10; //input2_992460_18*
   r2->unk_20 = r3; // input2_992460_r2*
   //DSB.W		SY // Data Synchronization Barrier

   int r3 = r1->unk_4; //input2_992460*
   r0->unk_0 = r3;
   if(r3 == 0)
   {
      r0->unk_4 = r3;
   }

   int r0 = r1->unk_38;
   int r3 = 0xFFF7;
   int r2 = 0;
   //STRD.W		R2, R2,	[R1]
   int r2 = r2 & r0;
   r1->unk_38 = r3;
   */
}

//========================================

int exit_loc_99330A(int r4)
{
   int r0 = r4;
   return r0;
}

int exit_loc_993310()
{
   int r4 = SCE_KERNEL_ERROR_INVALID_ARGUMENT;
   int r0 = r4;
   return r0;
}

int exit_loc_993352(int* r6, int r8)
{
   int* r0 = r6;
   int r1 = r8;
   int r4 = SCE_KERNEL_ERROR_NOT_INITIALIZED;
   int r0_ret = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   return exit_loc_99330A(r4);
}

int exit_loc_993386(int* r6, int r8)
{
   int* r0 = r6;
   int r1 = r8;
   int r4 = SCE_KERNEL_ERROR_NOT_SETUP;
   int r0_ret = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   return exit_loc_99330A(r4);
}

int exit_loc_99331C(int* r6, int r8)
{
   int r4 = SCE_KERNEL_ERROR_ALREADY_QUEUED;
   int* r0 = r6;
   int r1 = r8;
   int r0_res = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   int r0_ret = r4;
   return r0_ret;
}  

int exit_loc_993364(int* r6, int r8)
{
   int* r0 = r6;
   int r1 = r8;
   int r4 = SCE_KERNEL_ERROR_TRANSFERRED;
   int r0_res = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   return exit_loc_99330A(r4);
}

int exit_loc_993340(int* r6, int r8)
{
   int* r0 = r6;
   int r1 = r8;
   int r4 = SCE_KERNEL_ERROR_CANCELING;
   int r0_res = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   return exit_loc_99330A(r4);
}

int exit_loc_993302(int r4, int* r6, int r8)
{
   int* r0 = r6;
   int r1 = r8;
   int r0_res = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   return exit_loc_99330A(r4);
}

int exit_loc_993376(int* r6, int* r7, int r8)
{
   int* r0 = r7;
   int r4 = SCE_KERNEL_ERROR_NOT_UNDER_CONTROL;
   int r0_res = SceCpuForDriver_unlock_d6ed0c46(r0);
   return exit_loc_993302(r4, r6, r8);
}

int exit_loc_9932FA(int* r6, int* r7, int r8)
{
   int* r0 = r7;
   int r4 = 0;
   int r0_res = SceCpuForDriver_unlock_d6ed0c46(r0);
   return exit_loc_993302(r4, r6, r8);
}

int exit_loc_993332(input1_992460* r5, int* r6, int* r7, int r8)
{
   input2_992460* r4 = r5->unk_4;
   input1_992460* r0 = r5;
   r5->unk_0 = r4;
   input2_992460* r1 = r4;
   sub_992460(r0, r1);
   return exit_loc_9932FA(r6, r7, r8);
}

int exit_loc_9932F4()
{
   /*
   int r4 = r3[4];
   int r3 = r4[0];
   int r4 = r5[4]; //WHAT?
   return exit_loc_9932FA();
   */

   return 0;
}

int SceDmacmgrForDriver_543f54cf(dmac_id id)
{
   /*
   int r0 = r0 >> 1;
   int r3 = &_008FE000;
   int r4 = r0 << 2;
   int r3 = r3 | 1;
   int r2 = r4[0x30];

   if(r2 != r3)
      return exit_loc_993310();

   int r6 = r4 = 0x2C;
   int r0 = r6;
   int r0 = SceCpuForDriver_lock_int_d32ace9e(r0);

   int r3 = r4[0x38];
   int r8 = r0;
   int r0 = r3 << 0x1F;
   if(true) //BPL
      return exit_loc_993352(r0);

   int r3 = r4[0x18];
   if(r3 == 0)
      return exit_loc_993386();

   int r3 = r4[0x38];
   int r1 = r3 << 0x1C;
   if(true) //BMI
      return exit_loc_99331C();

   int r3 = r4[0x14];
   if(r3 != 0)
      return exit_loc_99331C();

   int r3 = r4[0x38];
   int r2 = r3 << 0x1A;
   if(true) // BMI
      return exit_loc_993364();

   int r3 = r4[0x38];
   int r3 = r3 << 0x19;
   if(true) // BMI
      return exit_loc_993340();

   int r5 = r4[0x10];
   int r7 = r5 & 8;
   int r0 = r7;
   int r0 = SceCpuForDriver_lock_bf82deb2(r0);
   int r3 = r5[0x10];
   if(r3 == 0)
      return exit_loc_993376();

   int r2 = r4[0x38];
   int r3 = r5[0];
   int r2 = r2 | 8;
   r4[0x38] = r2;

   if(r3 == 0)
      return exit_loc_993332();

   int r3 = r5[4];
   int r2 = r3[4];
   if(r2 == 0)
      return exit_loc_9932F4();

   r2[0] = r4;
   r4[4] = r2;

   return exit_loc_9932F4();
   */

   return 0;
}

//========================================

int exit_loc_993846(int r0)
{
   return r0;
}

int exit_loc_993840()
{
   int r0 = SCE_KERNEL_ERROR_INVALID_ARGUMENT;
   return exit_loc_993846(r0);
}

int exit_loc_9938DC(int* r5, int r1)
{
   SceCpuForDriver_unlock_int_7bb9d5df(r5, r1);
   return exit_loc_993846(SCE_KERNEL_ERROR_NOT_INITIALIZED);
}

int exit_loc_9938BC(int* r5, int r1)
{
   SceCpuForDriver_unlock_int_7bb9d5df(r5, r1);
   return exit_loc_993846(SCE_KERNEL_ERROR_NOT_SETUP);
}

int exit_loc_9938CC(int* r5, int r1)
{
   SceCpuForDriver_unlock_int_7bb9d5df(r5, r1);
   return exit_loc_993846(SCE_KERNEL_ERROR_CANCELING);
}

int SceDmacmgrForDriver_397a917c(dmac_id id, int num, int unk2, int unk3)
{
   /*

   int var_38;
   int var_2C;

   int r0 = r0 >> 1;
   int r5 = _008FE000;
   int r4 = r0 << 2;
   int r5 = r5 | 1;
   int r7 = r4[0x30];
   var_2C = r2;
   int r6 = r1;
   int r9 = r3;
   if(r7 != r5)
      return exit_loc_993840(); //invalid flags

   int r5 = r4 + 0x2C;
   int r0 = r5;
   int r0 = SceCpuForDriver_lock_int_d32ace9e(r0);
   int r3 = r4[0x38];
   int r1 = r0;
   int r2 = r3 << 0x1F;
   if(r2 >=0 )
      return exit_loc_9938DC(); // not initialized

   int r3 = r4[0x18];
   if(r3 == 0)
   {
      int r3 = r4[0x14];
      if(r3 == 0)
      {
         int r3 = r4[0x38];
         int r3 = r3 << 0x1A;
         if(r3 >=0 )
            return exit_loc_9938BC(); //not setup
      }
   }

   //loc_993812:
   short r8 = r4[0x38];
   int r8 = r8 & 0x40;
   if(r8 != 0)
      return exit_loc_9938CC();

   short r3 = r4[0x38];
   int r0 = r5;
   int r10 = r4[0x34];
   int r11 = r3;
   int r0 = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   if(r6 == 2)
   {
      var_38 = r8;
      int r0 = r10;
      int r3 = r8;
      //goto loc_993854
   }
   else
   {
      if(r6 == 3)
      {
         int r0 = r10;
         int r3 = r8;
         int r2 = &var_2C;
         var_38 = r2;
         //goto loc_993854
      }
      else
      {
         if(r6 == 1)
         {
            int temp_tst =  r11 & 0x20; //r11 is not touched
            if(temp_tst == 0) //not sure
               int r0 = r6;

            if(temp_tst == 0)
            {
               return exit_loc_993846(r0);
            }
            else
            {
               SceUID r0 = r10;
               int r1 = r6;
               unsigned int* r3 = r8;
               int r2 = SCE_EVENT_WAIT_5;
               int r0 = SceThreadmgrForDriver_ksceKernelPollEventFlag_76c6555b(r0, r1, r2, r3);
               if(r0 >= 0)
               {
                  //goto loc_993860
               }
               else
               {
                  return exit_loc_993846(r0);
               }
            }
         }
         else
         {
            return exit_loc_993840();
         }
      }
   }

   //loc_993854:
   {
      int r1 = 1;
      int r2 = SCE_EVENT_WAIT_5;
      int r0 = SceThreadmgrForDriver_ksceKernelWaitEventFlag_0c1d3f20(r0, r1, r2, r3, ?);
      if(r0 == 0)
      {
         return exit_loc_993846(r0);
      }
      else
      {
         //goto loc_993860
      }
   }

   //loc_993860:
   {
      int r0 = r9;
      if(r9 == 0)
      {
         return exit_loc_993846(r0);
      }
      else
      {
         int r0 = r5;
         int r0 = SceCpuForDriver_lock_int_d32ace9e(r0);
         int r3 = r4[0x30];
         int r1 = r0;
         int r0 = r5;

         if(r7 == r3)
         {
            int r3 = r4[0x24];
            r9[0x00] = r3;
         }

         int r0 = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
         int r0 = 0;
         return r0;
      }
   }

   */

   return 0;
}

//========================================

void sub_992000(result_c8672a3d* r0)
{
   int C0 = (int)r0->unk_38 & 0x40; //UXTH
   if(C0 != 0)
      return;

   r0->unk_38 = (r0->unk_38 | 0x40);

   unk_14_pair_0* ptr2 = r0->unk_14->unk_0;
   
   ptr2->unk_1C = C0;
   
   DSB(SY);

   while(true) //this looks like infinite loop that waits for sync ?
   {
      int C1 = ptr2->unk_24 << 0x1F;
      if(C1 >= 0)
         break;
   }

   if(ptr2->unk_28 != 0)
      return;

   result_c8672a3d_10_unk* ptr3 = r0->unk_10;
   result_c8672a3d_14_pair* ptr1 = r0->unk_14;

   int V1 = (int)ptr3 + 0x10C;
   int V2 = V1 - (int)ptr1;
   int V3 = V2 >> 3; //ASRS
   int V4 = 0x01 << (V3);

   ptr3->unk_C = ptr3->unk_C | V4;
   r0->unk_38 = 0xFFBF & r0->unk_38;
   
   ptr1->unk_4 = 0;
   r0->unk_14 = 0;
}

//----------------------

//looks like this procedure does some operations with linked list

void sub_992100(result_c8672a3d* r0)
{
   result_c8672a3d_10_unk* N5 = r0->unk_10;
   
   SceCpuForDriver_lock_bf82deb2(&N5->lockable_8);

   //this looks like some linked list operations

   if(N5->unk_0 == r0)
      N5->unk_0 = r0->unk_04;

   if(N5->unk_4 == r0)
      N5->unk_4 = r0->unk_00;

   result_c8672a3d* N3 = r0->unk_00;
   if(N3 != 0)
      N3->unk_04 = r0->unk_04;

   result_c8672a3d* N2 = r0->unk_04;
   if(N2 != 0)
      N2->unk_00 = N3;

   result_c8672a3d* r4 = r0;

   r0->unk_00 = 0x00;
   r0->unk_04 = 0x00;
   SceCpuForDriver_unlock_d6ed0c46(&N5->lockable_8);

   r0->unk_38 = 0xFFF7 & r0->unk_38;
}

//----------------------

int SceDmacmgrForDriver_adff1186(dmac_id id)
{
   int ctx = SceIntrmgrForDriver_getCurrentCpuUnkData_182ee3e3();
   if(ctx != 0)
      return SCE_KERNEL_ERROR_ILLEGAL_CONTEXT;

   result_c8672a3d* r4 = SCE_DMAC_UNPACK_ID(id);
   int gxor = (((int)&g_008FE000) | 1);

   if(r4->gxor_30 != gxor)
      return SCE_KERNEL_ERROR_INVALID_ARGUMENT;

   int prev_state = SceCpuForDriver_lock_int_d32ace9e(&r4->lockable_int_2C);
   
   int C0 = r4->unk_38 << 0x1F; //what is the point shifting short to 31 bits ?
   if(C0 >= 0)
   {
      SceCpuForDriver_unlock_int_7bb9d5df(&r4->lockable_int_2C, prev_state);
      return SCE_KERNEL_ERROR_NOT_INITIALIZED;
   }

   int C1 = r4->unk_38 << 0x19; //what is the point shifting short to 25 bits ?
   if(C1 < 0)
   {
      SceCpuForDriver_unlock_int_7bb9d5df(&r4->lockable_int_2C, prev_state);
      return SCE_KERNEL_ERROR_CANCELING;
   }

   if(r4->unk_14 != 0)
   {
      sub_992000(r4);

      int C2 = (r4->unk_38) << 0x19;

      if(C2 < 0)
      {
         SceCpuForDriver_unlock_int_7bb9d5df(&r4->lockable_int_2C, prev_state);

         int ctr = 5;

         while(true)
         {
            SceThreadmgrForDriver_sceKernelDelayThread_4b675d05(0x0A); //10 ms
            
            prev_state = SceCpuForDriver_lock_int_d32ace9e(&r4->lockable_int_2C);

            int C3 = (r4->unk_38) << 0x19;
            if(C3 >= 0)
               break;

            SceCpuForDriver_unlock_int_7bb9d5df(&r4->lockable_int_2C, prev_state);
            ctr = ctr - 1;

            if(ctr == 0)
               return SCE_ERROR_ERRNO_EBUSY;
         }
      }
   }

   int C5 = r4->unk_38 << 0x1C;
   if(C5 < 0)
      sub_992100(r4);
   
   SceThreadmgrForDriver_ksceKernelDeleteEventFlag_71ecb352(r4->eventFlagUid_34);

   r4->unk_38 = 0x00;
   r4->gxor_30 = 0x00;
   
   SceCpuForDriver_unlock_int_7bb9d5df(&r4->lockable_int_2C, prev_state);

   SceSysmemForKernel_functor_571660aa(g_008FE000.unk_20, r4);
   
   return 0;
}