#include <map>
#include <stdint.h>

#include "SceIofilemgr.h"

typedef struct ctx_21A27B8_70 //size is 0x160
{
   //8 + 44 + 14 = 60

   char unk_70[0x8]; //header
   
   uint32_t unk_78; //field
   uint32_t unk_7C;

   uint32_t unk_80; //field
   uint32_t unk_84;
   uint32_t unk_88; //field
   uint32_t unk_8C;

   uint32_t unk_90; //field
   uint32_t unk_94; //field
   uint32_t unk_98; //field
   uint32_t unk_9C; //field

   uint32_t unk_A0;
   uint32_t unk_A4;

   char unk_A8[0x14];
   char unk_BC[0x14];
   char unk_D0[0x100];

} ctx_21A27B8_70;

typedef struct ctx_21A27B8_18 //size is unknown
{
   uint32_t unk_0;
   uint32_t unk_4;

}ctx_21A27B8_18;

typedef struct ctx_21A27B8_20 //size is 0x20
{
   uint32_t unk_0;
   uint32_t unk_4;
   uint32_t unk_8;
   uint32_t unk_C;

   uint32_t unk_10;
   uint32_t unk_14;
   uint32_t unk_18;
   uint32_t unk_1C;

}ctx_21A27B8_20;

typedef struct ctx_21A27B8_40 //size is 0x28
{
   uint32_t unk_40;
   uint32_t unk_44;
   uint32_t unk_48;

   char unk_4C[0x14];

   uint32_t unk_60;
   uint32_t unk_64;

}ctx_21A27B8_40;

typedef struct ctx_21A27B8
{
   char data0[0x14];

   vfs_node ** unk_14;
   ctx_21A27B8_18* unk_18; //field
   uint32_t unk_1C;

   ctx_21A27B8_20 unk_20; //field

   ctx_21A27B8_40 unk_40; //field

   uint32_t unk_68; //field
   uint32_t unk_6C;

   ctx_21A27B8_70 unk_70;
   
   uint32_t unk_1D0;

}ctx_21A27B8;

int sub_2199144(vfs_node **node, std::pair<uint32_t, uint32_t>* result_pair)
{
   return 0;
}

//num0, num1 are probably offset
int read_wrapper_2199064(vfs_node **unk0, char *buffer, int size, int unk3, int num0, int num1, uint32_t *readBytes)
{
   return 0;
}

int sub_21A0E3C(ctx_21A27B8_20* unk0, ctx_21A27B8_18* unk1, vfs_node ** unk2, int unk3, int arg_0, int arg_4)
{
   /*
   var_8= -8
   var_4= -4
   arg_0=  0
   arg_4=  4

   PUSH            {R4,R5}
   LDRD.W          R4, R5, [SP,#8] ; arg_0, arg_4
   VMOV.I8         D17, #0xFF
   VMOV.I32        D16, #0x80
   STRD.W          R4, R5, [R0,#0x18] ; store arg_0, arg_4
   STMIA.W         R0, {R1,R2} ; store arg1, arg2
   VSTR            D17, [R0,#8]
   VSTR            D16, [R0,#0x10]
   POP             {R4,R5}
   BX              LR
   */

   return 0;
}

int proc_copy_14_bytes_219DE1C(char unk0[0x14], char unk1[0x14])
{
   return 0;
}

int proc_crypto_stuff_219DE7C(char unk0[0x14], ctx_21A27B8* unk1, ctx_21A27B8_70* unk2, int unk3)
{
   return 0;
}

int proc_verify_14_bytes_219DE44(char unk0[0x14], char unk1[0x14])
{
   return 0;
}

int sub_21A0E28(ctx_21A27B8_20* unk0, char unk1[0x14], int unk2, int unk3, int arg_0, int arg_4)
{
   return 0;
}

int sub_21A6A10(ctx_21A27B8_40* unk0, ctx_21A27B8* unk1, ctx_21A27B8_20* unk2, int unk3, int arg_0)
{
   return 0;
}

//----------------

int loc_21A292E(int r9, int var_2C)
{
   if(var_2C == var_009EA004)
      return r9;
   else
      return STACK_CHECK_FAIL;
}

int loc_21A292C(int r0, int var_2C)
{
   return loc_21A292E(r0, var_2C);
}

int proc_SCENGPFS_21A27B8(ctx_21A27B8* argument0, vfs_node **argument1, char argument2[0x14])
{
   //var_294= -0x294         
   //var_290= -0x290
   uint32_t var_28C; //read bytes value
   std::pair<uint32_t, uint32_t> result_p; //size is 0x8 bytes in total
   char unk0[0x14]; //0x14 bytes
   char destination[0x240]; //size is 0x100 or 0x200 aligned to 0x40 (that is why 0x240 in total). this is multipurpose buffer
   int var_2C = var_009EA004; //cookie

   argument0->unk_14 = argument1;

   int result0 = sub_2199144(argument1, &result_p); //call vfs_node_func15 (sceIoGetstatForDriver) - get some string from node field 70

   if(result0 != 0)
      return loc_21A292C(result0, var_2C);

   if((result_p.first | result_p.second) == 0)
      return loc_21A292E(0x80140904, var_2C);

   char* aligned_buffer = (char*)(((uint32_t)destination + 0x3F) & (~0x3F)); //align up to 0x40
   
   int result1 = read_wrapper_2199064(argument0->unk_14, aligned_buffer, 0x200, 0, 0x200, 0, &var_28C);

   if(result1 != 0)
      return loc_21A292C(result1, var_2C);

   if(var_28C != 0x200)
      return loc_21A292E(0x8014090A, var_2C);
    
   int some_value = aligned_buffer[0x60];
   argument0->unk_68 = some_value;

   if(some_value != 0)
      return loc_21A292E(0x8014090A, var_2C);

   int result2 = read_wrapper_2199064(argument0->unk_14, aligned_buffer, 0x200, 0, 0x80, 0x00, &var_28C); //not sure about 0x80 0x00

   if(result2 != 0)
      return loc_21A292C(result2, var_2C);

   if(var_28C != 0x200)
      return loc_21A292E(0x8014090A, var_2C);

   memcpy(&argument0->unk_70, aligned_buffer, 0x160);

   //-----------

   if(strncmp("SCENGPFS", argument0->unk_70.unk_70, 8) != 0)
      return loc_21A292E(0x8014090A, var_2C);

   memcpy(argument0->data0, argument2, 0x14);

   int r5 = argument0->unk_70.unk_80;

   if(r5 != argument0->unk_18->unk_4)
      return loc_21A292E(0x80140909, var_2C);

   int r3 = argument0->unk_70.unk_78 - 1;

   if(r3 <= 1)
      r5 = 0x160;

   sub_21A0E3C(&argument0->unk_20, argument0->unk_18, argument0->unk_14, r3, r5, 0);

   memcpy(destination, argument0->unk_70.unk_D0, 0x100);

   proc_copy_14_bytes_219DE1C(unk0, argument0->unk_70.unk_BC);

   memset(argument0->unk_70.unk_BC, 0, 0x14);

   memset(argument0->unk_70.unk_D0, 0, 0x100);

   proc_crypto_stuff_219DE7C(argument0->unk_70.unk_BC, argument0, &argument0->unk_70, 0x160);

   int result3 = proc_verify_14_bytes_219DE44(unk0, argument0->unk_70.unk_BC);

   if(result3 == 0)
      return loc_21A292E(0x80140902, var_2C);

   sub_21A0E28(&argument0->unk_20, argument0->unk_70.unk_BC, argument0->unk_70.unk_90, argument0->unk_70.unk_94, argument0->unk_70.unk_98, argument0->unk_70.unk_9C);

   int result4 = sub_21A6A10(&argument0->unk_40, argument0, &argument0->unk_20, argument0->unk_70.unk_88, argument0->unk_70.unk_78); //some vfs node functions inside

   if(result4 != 0)
      return loc_21A292C(result4, var_2C);

   int result5 = proc_verify_14_bytes_219DE44(argument0->unk_70.unk_A8, argument0->unk_40.unk_4C);

   if(result5 == 0)
      return loc_21A292E(0x80140902, var_2C);

   memcpy(argument0->unk_70.unk_D0, &destination, 0x100);

   memcpy(argument0->unk_70.unk_BC, unk0, 0x14);
   
   return loc_21A292E(0, var_2C);
}