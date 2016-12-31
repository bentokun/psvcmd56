#include <string>

#include "DmacLayer.h"
#include "GlobalVariables.h"
#include "Constants.h"

struct global_008FE000
{
   int unk_00;
   int unk_04;
   int unk_08;
   int unk_0C;
   int unk_10;
   int unk_14;
   int unk_18;
   int unk_1C;
   int unk_20;
};

//==========================================================================

//arg can be char*
int SceKernelDmacMgr_SceIntrmgrForDriver_imp_182ee3e3(int r0)
{
   return 0;
}

//==========================================================================

int SceKernelDmacMgr_SceThreadmgrForDriver_imp_4336baa4(int unk0, int unk1, int unk2, int unk3)
{
   return 0;
}

int SceKernelDmacMgr_SceThreadmgrForDriver_imp_0c1d3f20(int unk0, int unk1, int unk2, int unk3)
{
   return 0;
}

int SceKernelDmacMgr_SceThreadmgrForDriver_imp_76c6555b(int unk0, int unk1, int unk2, int unk3)
{
   return 0;
}

int SceKernelDmacMgrSceThreadmgrForDriver_imp_71ecb352(int unk0)
{
   return 0;
}

typedef unsigned int SceUInt;

int SceKernelDmacMgr_SceThreadmgrForDriver_imp_sceKernelDelayThread_4b675d05(SceUInt delay)
{
   return 0;
}

//==========================================================================

struct result_c8672a3d
{
   int unk_00;
   int unk_04;
   int unk_08;
   int unk_0C;
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
};

result_c8672a3d* SceKernelDmacMgr_SceSysmemForKernel_imp_c8672a3d(int unk0)
{
   return 0;
}

int SceKernelDmacMgr_SceSysmemForKernel_imp_571660aa(int r0, int r1)
{
   return 0;
}

//==========================================================================

int SceKernelDmacMgr_SceSysmemForDriver_imp_e655852f(int unk0)
{
   return 0;
}

typedef unsigned int SceUID;
typedef unsigned int SceSize;

void* SceKernelDmacMgr_SceSysmemForDriver_imp_sceKernelMemPoolAlloc_7b4cb60a(SceUID pool, SceSize size)
{
   return 0;
}

void SceKernelDmacMgr_SceSysmemForDriver_imp_sceKernelMemPoolFree_3ebce343(SceUID pool, void *ptr)
{
}

int SceKernelDmacMgr_SceSysmemForDriver_imp_sceKernelGetPaddr_8d160e65(int unk0, int unk1)
{
   //wrapper for SceSysmem.SceCpuForKernel._exp_67343a07 - very interesting
   return 0;
}

int SceKernelDmacMgr_SceSysmemForDriver_imp_sceKernelGetPaddrList_e68beebd(int unk0, int unk1)
{
   return 0;
}

//==========================================================================

int SceKernelDmacMgr_SceCpuForDriver_imp_lock_int_d32ace9e(int *addr)
{
   return 0;
}

int SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(int *addr, int prev_state)
{
   return 0;
}

int SceKernelDmacMgr_SceCpuForDriver_imp_lock_bf82deb2(int *addr)
{
   return 0;
}

int SceKernelDmacMgr_SceCpuForDriver_imp_unlock_d6ed0c46(int *addr)
{
   return 0;
}

int SceKernelDmacMgr_SceCpuForDriver_imp_cda96e81(int unk0, int unk1, int unk2)
{
   return 0;
}

//==========================================================================

global_008FE000 _008FE000;

char* unk_994808 = "SceDmacDefault";

int _008FE278;

int _008FE02C;

int _008FE060;

int _008FE254;

//==========================================================================

int SceKernelDmacMgr_SceDmacmgrForDriver_exp_7cd5088a(const char* name)
{
   int r0 = name;
   int r6 = r0;
   int r0 = SceKernelDmacMgr_SceIntrmgrForDriver_imp_182ee3e3(r0);
   if(r0 != 0)
      return 0x80027101;

   global_008FE000* r5 = &_008FE000;
   int r3 = unk_994808;
   int r0 = r5->unk_20;

   if(r6 == 0)
      r6 = r3;
   result_c8672a3d* r0 = SceKernelDmacMgr_SceSysmemForKernel_imp_c8672a3d(r0);
   result_c8672a3d* r4 = r0;
   if(r0 == 0)
      return 0x8002710B;

   int r3 = r0 >> 1;
   int r1 = r7;
   int r2 = 0x30;
   int r8 = r3 | 0x01;
   memset(r0, r1, r2);
   int r1 = r7;
   int r7 = r5 | 0x01;
   int r0 = r6;
   int r2 = r1;
   int r3 = r1;
   r4->unk_30 = r7;
   int r0 = SceKernelDmacMgr_SceThreadmgrForDriver_imp_4336baa4(r0, r1, r2, r3);
   int r6 = r0 - 0;
   if(r6 < 0)
   {
      int r0 = r5->unk_20;
      int r1 = r4;
      int r0 = SceKernelDmacMgr_SceSysmemForKernel_imp_571660aa(r0, r1);
      int r0 = r6;
      return r0;
   }

   int r6 = r4->unk_34;
   int r0 = SceKernelDmacMgr_SceSysmemForDriver_imp_e655852f(r0);
   int r3 = 0x01;
   r4->unk_3C = r0;
   r4->unk_38 = r3;
   int r0 = r8;
   return r0;
}

//==========================================================================

//TODO: MARK KNOWN ERRORS WITH CONSTANTS

int exit_loc_992EAC()
{
   int r0 = r6;
   int r1 = r2;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(r0, r1);
   int r0 = 0x80027201; //SCE_KERNEL_ERROR_ALREADY_QUEUED
   return r0;
}

//default case
int exit_loc_992EC2()
{
   int r0 = r6;
   int r1 = r2;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(r0, r1);
   int r0 = 0x80020005; //SCE_KERNEL_ERROR_INVALID_FLAGS
   return r0;
}

int exit_loc_992ED6()
{
   int r0 = r6;
   int r1 = r2;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(r0, r1);
   int r0 = 0x80027207; //SCE_KERNEL_ERROR_NOT_UNDER_CONTROL
   return r0;
}

int exit_loc_992EE8()
{
   int r0 = r6;
   int r1 = r2;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(r0, r1);
   int r0 = 0x80027205; //SCE_KERNEL_ERROR_NOT_INITIALIZED
   return r0;
}

int exit_loc_992EFA()
{
   int r0 = r6;
   int r1 = r2;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(r0, r1);
   int r0 = 0x80027208; //SCE_UNKNOWN_ERROR_80027208
   return r0;
}

int SceKernelDmacMgr_SceDmacmgrForDriver_exp_fce4171a(void* unk0, int unk1, int unk2, int unk3)
{
   int r0 = r0 >> 1;
   int r5 = _008FE000;
   int r4 = r0 << 2;
   int r0 = r5 | 1;
   int r3 = r4[0x30]
   //SUB		SP, SP,	#0xC

   int r10 = r1;
   int r11 = r2;

   if(r3 != r0)
      return 0x80020005;

   int r6 = r4 + 0x2C;
   int r0 = r6;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_lock_int_d32ace9e(r0);
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
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(r0, r1);
   int r0 = 0;

   return r0;
}

//========================================

int sub_99214C()
{
   return 0;
}

int sub_99214C()
{
   return 0;
}

int sub_992288()
{
   return 0;
}

int sub_99289C()
{
   return 0;
}

int sub_9921FC()
{
   return 0;
}

int SceKernelDmacMgr_SceDmacmgrForDriver_exp_167079fc(int r0, int r1, int r2, int r3)
{
   return 0;
}

//==========================================================================

int exit_loc_993152(int r0)
{
   int r2 = var24;
   int r3 = r10[0];
   if(r2 == r3)
      return r0;
   else
      return STACK_CHECK_FAIL;
}

int exit_loc_993162()
{
   int r0 = 0x80020005; //SCE_KERNEL_ERROR_INVALID_FLAGS
   return exit_loc_993152(r0);
}

int SceKernelDmacMgr_SceDmacmgrForDriver_exp_01a599e0(int unk0, int unk1, int unk2)
{
   int r10 = &var_009EA004;
   int r4 = r1;
   int r1 = r10[0];
   var24 = r1;

   if(r4 = 0)
      return exit_loc_993162();

   int r9 = r0 >> 1;
   int r1 = &_008FE000;
   int r9 = r9 << 2;
   int r1 = r1 | 1;
   int r3 = r9[0x30];
   int r3 = r1;

   if(r3 != r1)
      return exit_loc_993162();

   int r3 = r9[0x3A];
   int r5 = -1;

   if(r3 == 0x13)
   {
      //LDREQD.W	R1, R3,	[R4,#0x1C]
		//STREQD.W	R1, R3,	[SP,#0x14]
   }

   int r3 = r2;
   //LDRD.W		R7, R6,	[R4]
   int r1 = &var44;
   int r2 = 0;
   //STRD.W		R7, R6,	[SP,#4]
   int r6 = r4[8];
   var3C = r6;
   int r6 = r4[0xC];
   var38 = r6;
   int r6 = r4[0x10];
   //STRD.W		R6, R5,	[SP,#0x1C]
   int r0 = SceKernelDmacMgr_SceDmacmgrForDriver_exp_167079fc(r0, r1, r2, r3);

   if(r0 < 0)
      return exit_loc_993152(r0);

   int r3 = r9[0x3A];
   int r0 = 0;
   int r2 = r9[0x20];

   if(r3 != 0x13)
   {
      //LDRNE		R3, [R4,#0x18]
   }
   else
   {
      //ADDEQ.W		R3, R4,	#0x1C
   }

   r9[0x28] = r3;
   r4[0x14] = r3;
   //BFC.W		R3, #0x12, #9

   int r3 = r3 | r2;
   r9[0x20] = r3;

   return exit_loc_993152(r0);
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
   int unk_0;
   int unk_4;
   int unk_8;
   int unk_C;

   // ...

   int unk_10C;
};

void sub_992460(input1_992460* r0, input2_992460* r1)
{
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
}

//========================================

int exit_loc_99330A()
{
   int r0 = r4;
   return r0;
}

int exit_loc_993310()
{
   int r4 = 0x80020005;
   int r0 = r4;
   return r0;
}

int exit_loc_993352()
{
   int r0 = r6;
   int r1 = r8;
   int r4 = 0x80027205;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(r0, r1);
   return loc_99330A();
}

int exit_loc_993386()
{
   int r0 = r6;
   int r1 = r8;
   int r4 = 0x80027203;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(r0, r1);
   return exit_loc_99330A();
}

int exit_loc_99331C()
{
   int r4 = 0x80027201;
   int r0 = r6;
   int r1 = r8;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(r0, r1);
   int r0 = r4;
   return r0;
}  

int exit_loc_993364()
{
   int r0 = r6;
   int r1 = r8;
   int r4 = 0x80027206;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(r0, r1);
   return exit_loc_99330A();
}

int exit_loc_993340()
{
   int r0 = r6;
   int r1 = r8;
   int r4 = 0x80027208;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(r0, r1);
   return exit_loc_99330A();
}

int exit_loc_993302()
{
   int r0 = r6;
   int r1 = r8;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(r0, r1);
   return exit_loc_99330A();
}

int exit_loc_993376()
{
   int r0 = r7;
   int r4 = 0x80027207;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_d6ed0c46(r0);
   return exit_loc_993302();
}

int exit_loc_9932FA()
{
   int r0 = r7;
   int r4 = 0;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_d6ed0c46(r0);
   return exit_loc_993302();
}

int exit_loc_993332()
{
   int r4 = r5[4];
   int r0 = r5;
   r5[0] = r4;
   int r1 = r4;
   sub_992460(r0, r1);
   return exit_loc_9932FA();
}

int exit_loc_9932F4()
{
   int r4 = r3[4];
   int r3 = r4[0];
   int r4 = r5[4];
   return exit_loc_9932FA();
}

int SceKernelDmacMgr_SceDmacmgrForDriver_exp_543f54cf(int unk0)
{
   int r0 = r0 >> 1;
   int r3 = &_008FE000;
   int r4 = r0 << 2;
   int r3 = r3 | 1;
   int r2 = r4[0x30];

   if(r2 != r3)
      return exit_loc_993310();

   int r6 = r4 = 0x2C;
   int r0 = r6;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_lock_int_d32ace9e(r0);

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
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_lock_bf82deb2(r0);
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
}

//========================================

int SceKernelDmacMgr_SceDmacmgrForDriver_exp_397a917c(int unk0, int unk1, int unk2, int unk3)
{
   
   return 0;
}

//========================================

int sub_992000()
{
   return 0;
}

int sub_992100()
{
   return 0;
}

int SceKernelDmacMgr_SceDmacmgrForDriver_exp_adff1186(int unk)
{
   return 0;
}