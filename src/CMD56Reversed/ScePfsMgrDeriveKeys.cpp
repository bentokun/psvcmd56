#include "Constants.h"
#include "SceIofilemgr.h"

#include <stdint.h>

typedef struct buffer_list
{
    SceUID mutex_id;
    uint32_t unk_4;
    uint32_t unk_8;
    uint32_t unk_C;
    uint32_t unk_10;
    void* bcl; //0x14 - one of versions is pfs_pmi_buffer_list_ctx
}buffer_list;

typedef struct pfs_pmi_buffer_list_ctx
{
    buffer_list* blist;
    uint32_t unk_4;
    SceUID ScePfsPmi_mutex_id; // 0x08
    char original_path[0x3F];  // 0xC
    
    char mount_point1[0x22]; // 0x4C - /%s
    
    char mount_point2[0x23];  // 0x6E - %s0:
    
    char unk_91;
    
    uint16_t type;   //0x92
    uint16_t unk_94; //0x94 = 0
    
    char klicensee[0x10]; //0x96
    
    uint16_t unk_A6; // = 0
    uint32_t unk_A8; // = 0
    uint32_t unk_AC; // = 0
    
    SceUID ScePfsFilesDb_mutex_id; // 0xB0
    
    char unk_data1[0xBC]; // 0xB4
    
    pfs_pmi_buffer_list_ctx *bcl; //0x170
    uint32_t unk_174;
    SceUInt64 auth_id;
    
    char unk_data2[0x78]; // 0x180

    vfs_block_dev_info block_dev; // 0x1F8

    uint32_t unk_20C;
    
    //further fields are unknown
} pfs_pmi_buffer_list_ctx;

typedef struct CryptEngineData //size is 0x60
{
   uint32_t unk_0;
   uint32_t unk_4;
   uint32_t unk_8;
   uint16_t unk_C;
   uint16_t flag; // 0xE - flag that selects decryption type ?
   
   uint16_t key_id; //0x10
   uint16_t seed1_base; //iv seed
   
   uint32_t unk_14;
   uint32_t unk_18;
   uint32_t unk_1C;
   
   uint32_t unk_20;
   uint32_t unk_24;
   uint32_t size1;
   char key[0x10]; //0x2C
   
   char iv_xor_key[0x10]; //0x3C
   
   char hmac_key[0x10]; //0x4C

   uint32_t unk_5C;

}CryptEngineData;

typedef struct CryptEngineSubctx //size is 0x58
{
   uint32_t unk_0;
   uint32_t unk_4;
   uint32_t opt_code; // 0x8 - if 3 then decrypt, if 4 then encrypt, if 2 then encrypt
   CryptEngineData* data; // 0xC
   
   uint32_t unk_10;
   uint32_t source; // 0x14
   uint32_t unk_18;
   uint32_t unk_1C;
   
   uint32_t unk_20;
   uint32_t unk_24;
   uint32_t size2; //0x28
   uint32_t nDigests; // 0x2C - also digest table index
   
   uint32_t unk_30;
   uint32_t seed0_base; // 0x34
   uint32_t dest_offset; // 0x38
   uint32_t size0; // 0x3C
   
   uint32_t size1;
   uint32_t unk_44;
   uint32_t size3; //0x48
   char* hmac_sha1_digest; // digest to verify (possibly table)
   
   void* buffer0; // 0x50
   void* buffer1; // 0x54
   
}CryptEngineSubctx;

typedef struct CryptEngineWorkCtx //size is 0x18
{
   void* unk_0; // pointer to data 0x140 + 0x18 ?
   void* unk_4; // pointer to data 0x140 + 0x18 ?
   CryptEngineSubctx* subctx; // 0x8
   uint32_t error; //set to 0 or error code after executing crypto task
   
   SceUID threadId; // = set with sceKernelGetThreadIdForDriver. used with ksceKernelSignalCondTo
   uint32_t unk_14;
   
}CryptEngineWorkCtx;

int combine_klicensee_digest_219E1D8(char *sha1_combined_digest, char *klicensee, uint32_t unk2, uint16_t flags, uint32_t salt, uint16_t arg_4)
{
   return 0;
}

int calculate_sha1_chain_219E1CC(char *result0, char *result1, char *klicensee, uint32_t ignored, uint32_t salt)
{
   return 0;
}

int hmac1_sha1_or_sha1_chain_219E0DC(char *result0, char *result1, char *klicensee, uint32_t unk3, uint16_t arg_0, uint32_t salt, uint16_t unused_arg_8)
{
   return 0;
}

int hmac_sha1_219E164(char *result0, char *result1, char *klicensee, uint16_t unk3, uint16_t arg_0, void *data, uint32_t data_len)
{
   return 0;
}

typedef struct derive_keys_r7_ctx
{
   uint32_t unk_40;


   uint32_t unk_58;

}derive_keys_r7_ctx;

int derive_subroutine(int r2, CryptEngineData* r4, pfs_pmi_buffer_list_ctx * r5, char* r6, derive_keys_r7_ctx* r7, uint32_t r8)
{
   int some_flag = 0xC0000B03 & (1 << r2);

   if((r2 > 0x1F) || (some_flag == 0))
   {
      calculate_sha1_chain_219E1CC(r4->key, r4->iv_xor_key, r6, r5->unk_A8, r8);
      return combine_klicensee_digest_219E1D8(r4->hmac_key, r6, r5->unk_A8, r5->unk_94, r8, r5->unk_A6);
   }
   else
   {
      if((r7->unk_40 != 0 && r7->unk_40 != 3) || (r7->unk_58 <= 1))
      {    
         hmac1_sha1_or_sha1_chain_219E0DC(r4->key, r4->iv_xor_key, r6, r5->unk_A8, r5->unk_94, r8, r5->unk_A6);
         return combine_klicensee_digest_219E1D8(r4->hmac_key, r6, r5->unk_A8, r5->unk_94, r8, r5->unk_A6);
      }
      else
      {
         if(r2 == 0 || r2 == 3)
         {
            hmac_sha1_219E164(r4->key, r4->iv_xor_key, r6, r5->unk_94, r5->unk_A6, r7 + 0x84, 0x14);
            return combine_klicensee_digest_219E1D8(r4->hmac_key, r6, r5->unk_A8, r5->unk_94, r8, r5->unk_A6);
         }
         else
         {
            hmac_sha1_219E164(r4->key, r4->iv_xor_key, r6, r5->unk_94, r5->unk_A6, 0, 0x14);
            return combine_klicensee_digest_219E1D8(r4->hmac_key, r6, r5->unk_A8, r5->unk_94, r8, r5->unk_A6);
         }
      }
   }
}

int derive_keys_from_klicensee_219B4A0(CryptEngineData *data, int salt, int unk2, int unk3, int arg_0, int arg_4, derive_keys_r7_ctx* arg_8, pfs_pmi_buffer_list_ctx *pfs_pmi_bcl)
{
   int r0 = data;
   int r1 = salt;
   int r2 = unk2;
   int r3 = unk3;

   int r4 = r0;
   int r8 = r1;

   //VMOV            D8, R2, R3
   
   short r10 = arg_0;
   int r7 = arg_8;
   int r5 = pfs_pmi_bcl;
   
   int r0 = ScePfsMgr.SceIofilemgrForDriver._imp_thread_related_12f8d58e();
   int r3 = 0x100;
   
   if(r0 != 0)
   {
      int r3 = r0[0x2C];
      if(r3 >= 0)
      {
         //UXTH          R3, R3
      }
   }

   r4[0x18] = r3;

   int r0 = ScePfsMgr.SceIofilemgrForDriver._imp_thread_related_12f8d58e();
   
   int r3 = 0xF;

   if(r0 != 0)
   {
      int r3 = r0[0x28];
   }

   short r12 = r5[0x92] ;
   int r6 = r5 + 0x96;
   short lr = r5[0x94];
   int r0 = r7;
   short r1 = r5[0xA6];
   int r2 = r5[0xA8];

   r4[0x14] = r3;

   int r3 = arg_4;

   r4[4] = r2;
   r4[8] = r8;
   r4[0x1C] = r3;

   r4[0xC] = (short) r12;
   r4[0xE] = (short)lr;
   r4[0x12] = (short) r10;
   r4[0x10] = (short) r1;
   
   //VSTR            D8, [R4,#0x20]

   r4[0x00] = r6;

   int r3 = r7[0x14]

   int r0 = r3(); //call callback
   
   short r2 = r4[0xE];
   r4[0x28] = r0;
   
   int r2 = r2 - 2;
   //UXTH            R2, R2

   return derive_subroutine(r2, r4, r5, r6, r8);
}