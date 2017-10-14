#include "Constants.h"
#include "SceIofilemgr.h"

#include <stdint.h>
#include <string>

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
    uint16_t flag; //0x94 = 0
    
    char klicensee[0x10]; //0x96
    
    uint16_t key_id; // = 0
    uint32_t salt0; // 0xA8 = 0
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
   const char* klicensee;
   uint32_t salt0;
   uint32_t salt1;
   uint16_t type;
   uint16_t flag; // 0xE - flag that selects decryption type ?
   
   uint16_t key_id; // 0x10
   uint16_t seed1_base; // 0x12 iv seed
   
   uint32_t unk_14;
   uint32_t unk_18;
   uint32_t unk_1C;
   
   uint32_t unk_20;
   uint32_t unk_24;
   uint32_t size1; //0x28
   char key[0x10]; //0x2C
   
   char iv_xor_key[0x10]; //0x3C
   
   char hmac_key[0x14]; //0x4C

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
   
   uint32_t size1; //0x40
   uint32_t unk_44;
   uint32_t size3; //0x48
   char* hmac_sha1_digest; // 0x4C digest to verify (possibly table)
   
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

struct derive_keys_ctx;

typedef int(derive_keys_sub_219A29C_cb)(const derive_keys_ctx*);

typedef struct derive_keys_ctx
{
   derive_keys_sub_219A29C_cb* unk_14; //function pointer

   uint32_t unk_40;


   uint32_t unk_58;
   uint32_t unk_68;

   char base_key[0x14]; // 0x84

}derive_keys_ctx;

typedef struct ctx_12f8d58e
{
   uint32_t unk_28;
   uint32_t unk_2C;

}ctx_12f8d58e;

//----------------------

typedef struct arm_lldiv_t
{
   long long q;
   long long r;
}arm_lldiv_t;

arm_lldiv_t SceSysclibForDriver__aeabi_ldivmod_7554ab04(long long n, long long d)
{
   return arm_lldiv_t();
}

ctx_12f8d58e* SceIofilemgrForDriver_thread_related_12f8d58e()
{
   return 0;
}

int SceKernelUtilsForDriverksceSha1Digest_87dc7f2f(const char *source, int size, char *result)
{
   return 0;
}

int SceKernelUtilsForDriver_sceHmacSha1DigestForDriver_29a28957(const char* key, int key_len, const char* data, int data_len, char* digest)
{
   return 0;
}

//----------------------

int SceKernelUtilsForDriver_aes_init_2_eda97d6d(void *ctx, uint32_t blocksize, uint32_t keysize, const char *key)
{
   return 0;
}

int SceKernelUtilsForDriver_aes_encrypt_2_302947b6(void* ctx, const char* src, char* dst)
{
   return 0;
}

//############## LEVEL 0 - CRYPTO PRIMITIVES ###############

int SceSblSsMgrForDriver_sceSblSsMgrAESCBCDecryptWithKeygenForDriver_1901cb5e(const char* src, char* dst, int size, const char* key, int key_size, char* iv, uint16_t key_id, int mask_enable)
{
   return 0;
}

int SceSblSsMgrForDriver_sceSblSsMgrAESCBCEncryptWithKeygenForDriver_711c057a(const char* src, char* dst, int size, const char* key, int key_size, char* iv, uint16_t key_id, int mask_enable)
{
   return 0;
}

//

int SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptWithKeygenForDriver_0f7d28af(const char* src, char* dst, int size, const char* key, int key_size, uint16_t key_id, int mask_enable)
{
   return 0;
}

//---------------------

int SceSblSsMgrForDriver_sceSblSsMgrAESCBCDecryptForDriver_121fa69f(const char* src, char* dst, int size, const char* key, int key_size, char* iv, int mask_enable)
{
   return 0;
}

int SceSblSsMgrForDriver_sceSblSsMgrAESCBCEncryptForDriver_e6e1ad15(const char* src, char* dst, int size, const char* key, int key_size, char* iv, int mask_enable)
{
   return 0;
}

//

int SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptForDriver_c517770d(const char* src, char* dst, int size, const char* key, int key_size, int mask_enable)
{
   return 0;
}

int SceSblSsMgrForDriver_sceSblSsMgrAESECBDecryptForDriver_7c978be7(const char* src, char* dst, int size, const char* key, int key_size, int mask_enable)
{
   return 0;
}

//---------------------

int SceSblSsMgrForDriver_sceSblSsMgrAESCMACForDriver_1b14658d(const char* src, char* dst, int size, const char* key, int key_size, char* iv, int mask_enable, int command_bit)
{
   return 0;
}

int SceSblSsMgrForDriver_sceSblSsMgrAESCMACWithKeygenForDriver_83b058f5(const char* src, char* dst, int size, const char* key, int key_size, char* iv, uint16_t key_id, int mask_enable, int command_bit)
{
   return 0;
}

int SceSblSsMgrForDriver_sceSblSsMgrSHA1ForDriver_eb3af9b5(const char* src, char* dst, int size, char* iv, int mask_enable, int command_bit)
{
   return 0;
}

int SceSblSsMgrForDriver_sceSblSsMgrHMACSHA1ForDriver_6704d985(const char* src, char* dst, int size, const char* key, char* iv, int mask_enable, int command_bit)
{
   return 0;
}

//############## LEVEL 1 - CRYPTO BASE WRAPPERS ###############

//#### GROUP 1 (hw dec/enc) ####

//encrypt / decrypt

int AESCBCEncrypt_base_219D8AC(const char* key, char* iv, uint32_t size, const char* src, char* dst)
{
   int size_tail = size & 0xF;
   int size_block = size & (~0xF);

   //encrypt N blocks of source data with key and iv
   
   if(size_block != 0)
   {
      int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCBCEncryptForDriver_e6e1ad15(src, dst, size_block, key, 0x80, iv, 1);
      if(result0 != 0)
         return result0;
   }

   //handle tail section - do a Cipher Text Stealing

   if(size_tail == 0)
      return 0;

   //align destination buffer

   char iv_enc[0x10] = {0};
   char* iv_enc_aligned = iv_enc + ((0 - (int)iv_enc) & 0x3F);

   //encrypt iv using key

   int result1 = SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptForDriver_c517770d(iv, iv_enc_aligned, 0x10, key, 0x80, 1);
   if(result1 != 0)
      return result1;

   for(int i = 0; i < size_tail; i++)
      dst[size_block + i] = src[size_block + i] ^ iv_enc_aligned[i]; 

   return 0;
}

int AESCBCDecrypt_base_219D950(const char* key, char* iv, uint32_t size, const char* src, char* dst)
{
   int size_tail = size & 0xF; // get size of tail
   int size_block = size & (~0xF); // get block size aligned to 0x10 boundary

   //decrypt N blocks of source data with key and iv

   if(size_block != 0)
   {
      int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCBCDecryptForDriver_121fa69f(src, dst, size_block, key, 0x80, iv, 1);
      if(result0 != 0)
         return result0;
   }

   //handle tail section - do a Cipher Text Stealing

   if(size_tail == 0)
      return 0;

   //align destination buffer

   char iv_enc[0x10] = {0};
   char* iv_enc_aligned = iv_enc + ((0 - (int)iv_enc) & 0x3F);
   
   //encrypt iv using key

   int result1 = SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptForDriver_c517770d(iv, iv_enc_aligned, 0x10, key, 0x80, 1);
   if(result1 != 0)
      return result1;

   //produce destination tail by xoring source tail with encrypted iv

   for(int i = 0; i < size_tail; i++)
      dst[size_block + i] = src[size_block + i] ^ iv_enc_aligned[i];

   return 0;
}

//encrypt / decrypt with key_id

int AESCBCDecryptWithKeygen_base_219DAAC(const char* key, char* iv, uint32_t size, const char* src, char* dst, uint16_t key_id)
{
   uint16_t kid = 0 - (key_id - 1) + (key_id - 1);

   int size_tail = size & 0xF;
   int size_block = size & (~0xF);
   
   //decrypt N blocks of source data with key and iv

   if(size_block != 0)
   {
      int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCBCDecryptWithKeygenForDriver_1901cb5e(src, dst, size_block, key, 0x80, iv, kid, 1);
      if(result0 != 0)
         return result0;
   }

   //handle tail section - do a Cipher Text Stealing

   if(size_tail == 0)
      return 0;

   //align destination buffer

   char iv_enc[0x10] = {0};
   char* iv_enc_aligned = iv_enc + ((0 - (int)iv_enc) & 0x3F);

   //encrypt iv using key

   int result1 = SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptWithKeygenForDriver_0f7d28af(iv, iv_enc_aligned, 0x10, key, 0x80, kid, 1);
   if(result1 != 0)
      return result1;

   //produce destination tail by xoring source tail with encrypted iv

   for(int i = 0; i < size_tail; i++)
      dst[size_block + i] = src[size_block + i] ^ iv_enc_aligned[i];

   return 0;
}

int AESCBCEncryptWithKeygen_base_219D9F4(const char* klicensee, char* iv, uint32_t size, const char* src, char* dst, uint16_t key_id)
{
   uint16_t kid = 0 - (key_id - 1) + (key_id - 1); // ???

   int size_tail = size & 0xF; // get size of tail
   int size_block = size & (~0xF); // get block size aligned to 0x10 boundary
   
   //encrypt N blocks of source data with klicensee and iv

   if(size_block != 0)
   {
      int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCBCEncryptWithKeygenForDriver_711c057a(src, dst, size_block, klicensee, 0x80, iv, kid, 1);
      if(result0 != 0)
         return result0;  
   }

   //handle tail section - do a Cipher Text Stealing

   if(size_tail == 0)
      return 0;

   //align destination buffer

   char iv_enc[0x10] = {0};
   char* iv_enc_aligned = iv_enc + ((0 - (int)iv_enc) & 0x3F);

   //encrypt iv using klicensee
     
   int result1 = SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptWithKeygenForDriver_0f7d28af(iv, iv_enc_aligned, 0x10, klicensee, 0x80, kid, 1);
   if(result1 != 0)
      return result1;

   //produce destination tail by xoring source tail with encrypted iv

   for(int i = 0; i < size_tail; i++)
      dst[size_block + i] = src[size_block + i] ^ iv_enc_aligned[i];

   return 0;
}

//#### GROUP 2 (hw cmac) ####

// FUNCTIONS ARE SIMILAR

int AESCMAC_base_1_219DC08(const char* cmac_key, char* iv, uint32_t size, const char* cmac_src, char* cmac_dst)
{
   int size_tail = size & 0xF;
   int size_block = size & (~0xF);
   
   //cmac N blocks of source data with klicensee and iv

   if(size_block != 0)
   {
      int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCMACForDriver_1b14658d(cmac_src, cmac_dst, size_block, cmac_key, 0x80, iv, 1, 0);
      if(result0 != 0)
         return result0;
   }

   //handle tail section - do a Cipher Text Stealing

   if(size_tail == 0)
      return 0;

   //align destination buffer

   char iv_enc[0x10] = {0};
   char* iv_enc_aligned = iv_enc + ((0 - (int)iv_enc) & 0x3F);

   //encrypt iv using key

   int result1 = SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptForDriver_c517770d(iv, iv_enc_aligned, 0x10, cmac_key, 0x80, 1);
   if(result1 != 0)
      return result1;

   //produce destination tail by xoring source tail with encrypted iv

   //CMAC result has constant size - that is why iv is xored with the beginning of dest buffer

   for(int i = 0; i < size_tail; i++)
      cmac_dst[i] = cmac_src[size_block + i] ^ iv_enc_aligned[i];

   return 0;
}

int AESCMAC_base_2_219DB64(const char* cmac_key, char* iv, uint32_t size, const char* cmac_src, char* cmac_dst)
{
   int size_tail = size & 0xF;
   int size_block = size & (~0xF);

   //cmac N blocks of source data with klicensee and iv

   if(size_block != 0)
   {
      int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCMACForDriver_1b14658d(cmac_src, cmac_dst, size_block, cmac_key, 0x80, iv, 1, 0);
      if(result0 != 0)
         return result0;
   }

   //handle tail section - do a Cipher Text Stealing

   if(size_tail == 0)
      return 0;

   //align destination buffer

   char iv_enc[0x10] = {0};
   char* iv_enc_aligned = iv_enc + ((0 - (int)iv_enc) & 0x3F);

   //encrypt iv using key

   int result1 = SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptForDriver_c517770d(iv, iv_enc_aligned, 0x10, cmac_key, 0x80, 1);
   if(result1 != 0)
      return result1;

   //produce destination tail by xoring source tail with encrypted iv

   //CMAC result has constant size - that is why iv is xored with the beginning of dest buffer

   for(int i = 0; i < size_tail; i++)
      cmac_dst[i] = cmac_src[size_block + i] ^ iv_enc_aligned[i];

   return 0;
}

// FUNCTIONS ARE SIMILAR

int AESCMACWithKeygen_base_1_219DCAC(const char* cmac_key, char* iv, uint32_t size, const char* cmac_src, char* cmac_dst, uint16_t key_id)
{
   uint16_t kid = 0 - (key_id - 1) + (key_id - 1);

   int size_tail = size & 0xF;
   int size_block = size & (~0xF);

   //cmac N blocks of source data with klicensee and iv

   if(size_block != 0)
   {
      int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCMACWithKeygenForDriver_83b058f5(cmac_src, cmac_dst, size_block, cmac_key, 0x80, iv, kid, 1, 0);
      if(result0 != 0)
         return result0;
   }

   //handle tail section - do a Cipher Text Stealing
   
   if(size_tail == 0)
      return 0;

   //align destination buffer

   char iv_enc[0x10] = {0};
   char* iv_enc_aligned = iv_enc + ((0 - (int)iv_enc) & 0x3F);

   //encrypt iv using key

   int result1 = SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptWithKeygenForDriver_0f7d28af(iv, iv_enc_aligned, 0x10, cmac_key, 0x80, kid, 1);
   if(result1 != 0)
      return result1;

   //produce destination tail by xoring source tail with encrypted iv

   //CMAC result has constant size - that is why iv is xored with the beginning of dest buffer

   for(int i = 0; i < size_tail; i++)
      cmac_dst[i] = cmac_src[size_block + i] ^ iv_enc_aligned[i];

   return 0;
}

int AESCMACWithKeygen_base_2_219DD64(const char* cmac_key, char* iv, uint32_t size, const char* cmac_src, char* cmac_dst, uint16_t key_id)
{
   uint16_t kid = 0 - (key_id - 1) + (key_id - 1);

   int size_tail = size & 0xF;
   int size_block = size & (~0xF);

   //cmac N blocks of source data with klicensee and iv

   if(size_block != 0)
   {
      int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCMACWithKeygenForDriver_83b058f5(cmac_src, cmac_dst, size_block, cmac_key, 0x80, iv, kid, 1, 0);
      if(result0 != 0)
         return result0;
   }

   //handle tail section - do a Cipher Text Stealing

   if(size_tail == 0)
      return 0;

   //align destination buffer

   char iv_enc[0x10] = {0};
   char* iv_enc_aligned = iv_enc + ((0 - (int)iv_enc) & 0x3F);

   //encrypt iv using key
   
   int result1 = SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptWithKeygenForDriver_0f7d28af(iv, iv_enc_aligned, 0x10, cmac_key, 0x80, kid, 1);
   if(result1 != 0)
      return result1;

   //produce destination tail by xoring source tail with encrypted iv

   //CMAC result has constant size - that is why iv is xored with the beginning of dest buffer

   for(int i = 0; i < size_tail; i++)
      cmac_dst[i] = cmac_src[size_block + i] ^ iv_enc_aligned[i];

   return 0;
}

//#### GROUP 3 (sw dec/enc) ####

// this is most likely SW version of CMAC. both dec and enc functions are implemented
//https://crypto.stackexchange.com/questions/47223/xex-mode-how-to-perturb-the-tweak

int xor_219D624(int* src, int* iv, int* dst, uint32_t size)
{
   int iv_cpy[4] = {0};
   memcpy(iv_cpy, iv, 0x10);

   while(size != 0)
   {
      dst[0] = src[0] ^ iv_cpy[0];
      dst[1] = src[1] ^ iv_cpy[1];
      dst[2] = src[2] ^ iv_cpy[2];
      dst[3] = src[3] ^ iv_cpy[3];

      src += 4;
      dst += 4;
      
      iv_cpy[0] += iv_cpy[0];
      iv_cpy[1] += iv_cpy[1];
      iv_cpy[2] += iv_cpy[2];
      iv_cpy[3] += iv_cpy[3];

      if(true) // this condition should check carry bit after one of the 4 add operations
         iv_cpy[0] = iv_cpy[0] + 0x87;
      
      size = size - 0x10;
   }

   return 0;
}

//IV is a subkey base

int AESCMACDecryptSw_base_219D714(const char* subkey, const char* dst_key, const char* subkey_key, uint32_t key_size, uint32_t size, const char* src, char* dst)
{
   char aes_ctx[0x1F0] = {0};
   char drv_subkey[0x10] = {0};

   SceKernelUtilsForDriver_aes_init_2_eda97d6d(aes_ctx, 0x80, key_size, subkey_key); //initialize aes ctx with iv_key

   SceKernelUtilsForDriver_aes_encrypt_2_302947b6(aes_ctx, subkey, drv_subkey); //encrypt 0x10 bytes of subkey to derive drv_subkey

   xor_219D624((int*)src, (int*)drv_subkey, (int*)dst, size); // xor src with drv_iv to get dst

   int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESECBDecryptForDriver_7c978be7(dst, dst, size, dst_key, key_size, 1); //decrypt dst data using dst_key key
   if(result0 == 0)
      xor_219D624((int*)dst, (int*)drv_subkey, (int*)dst, size); //xor dst with drv_iv to get real dst

   return result0;
}

int AESCMACEncryptSw_base_219D694(const char* subkey, const char* dst_key, const char* subkey_key, uint32_t key_size, uint32_t size, const char* src, char* dst)
{
   char aes_ctx[0x1F0] = {0};
   char drv_subkey[0x10] = {0};

   SceKernelUtilsForDriver_aes_init_2_eda97d6d(aes_ctx, 0x80, key_size, subkey_key);

   SceKernelUtilsForDriver_aes_encrypt_2_302947b6(aes_ctx, subkey, drv_subkey);

   xor_219D624((int*)src, (int*)drv_subkey, (int*)dst, size);

   int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptForDriver_c517770d(dst, dst, size, dst_key, key_size, 1);
   if(result0 == 0)
      xor_219D624((int*)dst, (int*)drv_subkey, (int*)dst, size);

   return result0;
}

//#### GROUP 4 (sw cmac) ####

// this is some CMAC variation but I am not sure ? both functions are similar but most likely ment to be dec / enc

int xor_219D65C(int* src, int* iv, int* dst, uint32_t size)
{
   int iv_cpy[4] = {0};
   memcpy(iv_cpy, iv, 0x10);

   while(size != 0)
   {
      dst[0] = src[0] ^ iv_cpy[0];
      dst[1] = src[1] ^ iv_cpy[1];
      dst[2] = src[2] ^ iv_cpy[2];
      dst[3] = src[3] ^ iv_cpy[3];

      src += 4;
      dst += 4;

      iv_cpy[0] += iv_cpy[0];
      iv_cpy[1] += iv_cpy[1];
      iv_cpy[2] += iv_cpy[2];
      iv_cpy[3] += iv_cpy[3];

      if(true) // this condition should check carry bit after one of the 4 add operations
         iv_cpy[0] = iv_cpy[0] + 0x87;
      
      size = size - 0x10;
   }

   return 0;
}

int AESCMACSw_base_1_219D794(const char* subkey, const char* dst_key, const char* subkey_key, uint32_t keysize, uint32_t size, const char* src, char* dst)
{
   char aes_ctx[0x1F0] = {0};
   char drv_subkey[0x10] = {0};
   char iv[0x10] = {0}; //HOW IV IS INITIALIZED ?
   
   SceKernelUtilsForDriver_aes_init_2_eda97d6d(aes_ctx, 0x80, keysize, subkey_key);

   SceKernelUtilsForDriver_aes_encrypt_2_302947b6(aes_ctx, subkey, drv_subkey);

   xor_219D65C((int*)src, (int*)drv_subkey, (int*)dst, size); // WHAT DOES THIS DO IF dst IS OVERWRITTEN BY NEXT CMAC CALL ANYWAY ?

   int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCMACForDriver_1b14658d(src, dst, size, dst_key, keysize, iv, 1, 0);
   if(result0 == 0)
      xor_219D65C((int*)dst, (int*)drv_subkey, (int*)dst, size);

   return result0;
}

int AESCMACSw_base_2_219D820(const char* subkey, const char* dst_key, const char* subkey_key, uint32_t keysize, uint32_t size, const char* src, char* dst)
{
   char aes_ctx[0x1F0] = {0};
   char drv_subkey[0x10] = {0};
   char iv[0x10] = {0}; //HOW IV IS INITIALIZED ?

   SceKernelUtilsForDriver_aes_init_2_eda97d6d(aes_ctx, 0x80, keysize, subkey_key);

   SceKernelUtilsForDriver_aes_encrypt_2_302947b6(aes_ctx, subkey, drv_subkey);

   xor_219D65C((int*)src, (int*)drv_subkey, (int*)dst, size); // WHAT DOES THIS DO IF dst IS OVERWRITTEN BY NEXT CMAC CALL ANYWAY ?

   int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCMACForDriver_1b14658d(src, dst, size, dst_key, keysize, iv, 1, 0);
   
   if(result0 == 0)
      xor_219D65C((int*)dst, (int*)drv_subkey, (int*)dst, size);

   return result0;
}

//############## LEVEL 2 - CRYPTO WRAPPER SELECTORS ###############

#define PFS_CRYPTO_USE_CMAC   0x0001 //1
#define PFS_CRYPTO_USE_KEYGEN 0x0002 //2

//#### GROUP 1, GROUP 2 (hw dec/enc) ####

char g_1771100[0x10] = {0};

int pfs_decrypt_hw_219D480(const char* key, const char* iv_xor_key, int tweak_key0, int tweak_key1, uint32_t size, uint32_t block_size, const char* src, char* dst, uint16_t flag, uint16_t key_id)
{
   char iv[0x10] = {0};

   int tk_tmp00 = tweak_key0;
   int tk_tmp10 = tweak_key1;
   
   for(int i = 0; i < 8; i++)
   {
      iv[i] = tk_tmp00;

      tk_tmp00 = (tk_tmp00 >> 8) | (tk_tmp10 << 24);
      tk_tmp10 = tk_tmp10 >> 8;
   }

   memset(iv + 8, 0, 8);

   for(int i = 0; i < 0x10; i++)
      iv[i] = iv[i] ^ iv_xor_key[i];
  
   if(size != 0)
   {
      int offset = 0;
      int bytes_left = size;

      do
      {
         int tk_tmp01 = tweak_key0 + offset;
         int tk_tmp11 = tweak_key1 + 0;
         
         for(int i = 0; i < 8; i++)
         {
            iv[i] = tk_tmp01;
            
            tk_tmp01 = (tk_tmp01 >> 8) | (tk_tmp11 << 24);
            tk_tmp11 = tk_tmp11 >> 8;
         }

         memset(iv + 8, 0, 8);

         for(int i = 0; i < 0x10; i++)
            iv[i] = iv[i] ^ iv_xor_key[i];

         // select block_size if we did not yet reach tail of the data. 
         // or select bytes_left which will be the size of the tail in the end

         int size_arg = 0;
         if(block_size < bytes_left)
            size_arg = block_size;
         else
            size_arg = bytes_left;

         if((flag & PFS_CRYPTO_USE_KEYGEN) != 0)
         {
            if((flag & PFS_CRYPTO_USE_CMAC) != 0)
               AESCMACWithKeygen_base_2_219DD64(key, iv, size_arg, src + offset, g_1771100, key_id);
            else
               AESCBCDecryptWithKeygen_base_219DAAC(key, iv, size_arg, src + offset, dst + offset, key_id);
         }
         else
         {
            if((flag & PFS_CRYPTO_USE_CMAC) != 0)
               AESCMAC_base_1_219DC08(key, iv, size_arg, src + offset, g_1771100);
            else
               AESCBCDecrypt_base_219D950(key, iv, size_arg, src + offset, dst + offset);
         }

         offset = offset + block_size;
         bytes_left = bytes_left - block_size;
      }
      while(size > offset);
   }

   if((flag & PFS_CRYPTO_USE_CMAC) != 0)
   {
      if(dst != src)
      {
         memcpy(dst, src, size);
      }
   }

   return 0;
}

int pfs_encrypt_hw_219D2DC(const char* key, const char* iv_xor_key, int tweak_key0, int tweak_key1, uint32_t size, uint32_t block_size, const char* src, char* dst, uint16_t flag, uint16_t key_id)
{
   char iv[0x10] = {0};

   int tk_tmp00 = tweak_key0;
   int tk_tmp10 = tweak_key1;

   for(int i = 0; i < 8; i++)
   {
      iv[i] = tk_tmp00;

      tk_tmp00 = (tk_tmp00 >> 8) | (tk_tmp10 << 24);
      tk_tmp10 = tk_tmp10 >> 8;
   }

   memset(iv + 8, 0, 8);

   for(int i = 0; i < 0x10; i++)
      iv[i] = iv[i] ^ iv_xor_key[i];

   if(size != 0)
   {
      int offset = 0;
      int bytes_left = size;

      do
      {         
         int tk_tmp01 = tweak_key0 + offset;
         int tk_tmp11 = tweak_key1 + 0;

         for(int i = 0; i < 8; i++)
         {
            iv[i] = tk_tmp01;

            tk_tmp01 = (tk_tmp01 >> 8) | (tk_tmp11 << 24);
            tk_tmp11 = tk_tmp11 >> 8;
         }

         memset(iv + 8, 0, 8);

         for(int i = 0; i < 0x10; i++)
            iv[i] = iv[i] ^ iv_xor_key[i];

         // select block_size if we did not yet reach tail of the data. 
         // or select bytes_left which will be the size of the tail in the end

         int size_arg = 0;
         if(block_size < bytes_left)
            size_arg = block_size;
         else
            size_arg = bytes_left;

         if((flag & PFS_CRYPTO_USE_KEYGEN) != 0)
         {
            if((flag & PFS_CRYPTO_USE_CMAC) != 0)
               AESCMACWithKeygen_base_1_219DCAC(key, iv, size_arg, src + offset, g_1771100, key_id);
            else
               AESCBCEncryptWithKeygen_base_219D9F4(key, iv, size_arg, src + offset, dst + offset, key_id);
         }
         else
         {
            if((flag & PFS_CRYPTO_USE_CMAC) != 0)
               AESCMAC_base_2_219DB64(key, iv, size_arg, src + offset, g_1771100);
            else
               AESCBCEncrypt_base_219D8AC(key, iv, size_arg, src + offset, dst + offset);
         }

         offset = offset + block_size;
         bytes_left = bytes_left - block_size;
      }
      while(size > offset);
   }

   if((flag & PFS_CRYPTO_USE_CMAC) != 0)
   {
      if(dst != src)
      {
         memcpy(dst, src, size);
      }
   }

   return 0;
}

//#### GROUP 3, GROUP 4 (sw dec/enc) ####

int pfs_decrypt_sw_219D174(const char* key, const char* subkey_key, uint32_t keysize, int ignored, int tweak_key0, int tweak_key1, uint32_t size, uint32_t block_size, const char* src, char* dst, uint16_t flag)
{
   char iv[0x10] = {0};

   if(((block_size | size) << 0x1C) != 0)
      return 0x80140609;

   if(size <= 0xF)
      return 0x80140609;
   
   if((((int)src | (int)dst) << 0x1E) != 0)
      return 0x8014060E;

   int tk_tmp00 = tweak_key0;
   int tk_tmp10 = tweak_key1;

   for(int i = 0; i < 8; i++)
   {
      iv[i] = tk_tmp00;

      tk_tmp00 = (tk_tmp00 >> 8) | (tk_tmp10 << 24);
      tk_tmp10 = tk_tmp10 >> 8;
   }

   memset(iv + 8, 0, 8);

   int offset = 0;
   int bytes_left = size;

   do
   {
      // select block_size if we did not yet reach tail of the data. 
      // or select bytes_left which will be the size of the tail in the end

      int size_arg = 0;
      if(block_size < bytes_left)
         size_arg = block_size;
      else
         size_arg = bytes_left;

      int result0 = 0;
      if((flag & PFS_CRYPTO_USE_CMAC) != 0)
         result0 = AESCMACSw_base_2_219D820(iv, key, subkey_key, keysize, size_arg, src + offset, g_1771100);
      else
         result0 = AESCMACDecryptSw_base_219D714(iv, key, subkey_key, keysize, size_arg, src + offset, dst + offset);

      if(result0 != 0)
         return result0;

      for(int i = 0; i < 0x10; i++)
      {
         if(iv[i] == 0xFF)
         {
            iv[i] = 0;
         }
         else
         {
            iv[i] = iv[i] + 1;
            break;
         }
      }

      offset = offset + block_size;
      bytes_left = bytes_left - block_size;
   }
   while(size > offset);

   if((flag & PFS_CRYPTO_USE_CMAC) != 0)
   {
      if(dst != src)
      {
         memcpy(dst, src, size);
      }
   }

   return 0;
}

int pfs_encrypt_sw_219D00C(const char* key, const char* subkey_key, uint32_t keysize, int ignored, int tweak_key0, int tweak_key1, uint32_t size, uint32_t block_size, const char* src, char* dst, uint16_t flag)
{
   char iv[0x10] = {0};

   if(((block_size | size) << 0x1C) != 0)
      return 0x80140609;

   if(size <= 0xF)
      return 0x80140609;

   if((((int)src | (int)dst) << 0x1E) != 0)
      return 0x8014060E;

   int tk_tmp00 = tweak_key0;
   int tk_tmp10 = tweak_key1;

   for(int i = 0; i < 8; i++)
   {
      iv[i] = tk_tmp00;

      tk_tmp00 = (tk_tmp00 >> 8) | (tk_tmp10 << 24);
      tk_tmp10 = tk_tmp10 >> 8;
   }

   memset(iv + 8, 0, 8);
   
   int offset = 0;
   int bytes_left = size;
   
   do
   {
      // select block_size if we did not yet reach tail of the data. 
      // or select bytes_left which will be the size of the tail in the end

      int size_arg = 0;
      if(block_size < bytes_left)
         size_arg = block_size;
      else
         size_arg = bytes_left;

      int result0 = 0;
      if((flag & PFS_CRYPTO_USE_CMAC) != 0)
         result0 = AESCMACSw_base_1_219D794(iv, key, subkey_key, keysize, size_arg, src + offset, g_1771100);
      else
         result0 = AESCMACEncryptSw_base_219D694(iv, key, subkey_key, keysize, size_arg, src + offset, dst + offset);
      
      if(result0 != 0)
         return result0;

      for(int i = 0; i < 0x10; i++)
      {
         if(iv[i] == 0xFF)
         {
            iv[i] = 0;
         }
         else
         {
            iv[i] = iv[i] + 1;
            break;
         }
      }

      offset = offset + block_size;
      bytes_left = bytes_left - block_size;
   }
   while(size > offset);

   if((flag & PFS_CRYPTO_USE_CMAC) != 0)
   {
      if(dst != src)
      {
         memcpy(dst, src, size);
      }
   }

   return 0;
}

//----------------------

int sha1Digest_219DE54(char *result, const char *source, int size)
{
   return SceKernelUtilsForDriverksceSha1Digest_87dc7f2f(source, size, result);
}

int hmacSha1Digest_219DE68(char* digest, const char* key, const char* data, int data_len)
{
   return SceKernelUtilsForDriver_sceHmacSha1DigestForDriver_29a28957(key, 0x14, data, data_len, digest);
}

//----------------------

char hmac_key_21A93C8[0x14] = {0xE4, 0x62, 0x25, 0x8B, 0x1F, 0x31, 0x21, 0x56, 0x07, 0x45, 0xDB, 0x62, 0xB1, 0x43, 0x67, 0x23, 0xD2, 0xBF, 0x80, 0xFE}; 

char hmac_key_21A93DC[0x14] = {0xAF, 0xE6, 0x56, 0xBB, 0x3C, 0x17, 0x25, 0x6A, 0x3C, 0x80, 0x9F, 0x6E, 0x9B, 0xF1, 0x9F, 0xDD, 0x5A, 0x38, 0x85, 0x43};

char iv_21A93F0[0x10] = {0x74, 0xD2, 0x0C, 0xC3, 0x98, 0x81, 0xC2, 0x13, 0xEE, 0x77, 0x0B, 0x10, 0x10, 0xE4, 0xBE, 0xA7};

//-------------------------------------

int calculate_sha1_chain_219E008(char* key, char* iv_xor_key, const char* klicensee, uint32_t salt1)
{
   int saltin[2] = {0};
   char base0[0x14] = {0};
   char base1[0x14] = {0};
   char combo[0x28] = {0};
   char drvkey[0x14] = {0};

   saltin[0] = salt1;

   sha1Digest_219DE54(base0, klicensee, 0x10); //calculate hash of klicensee

   // derive key 0

   saltin[1] = 1;
   
   sha1Digest_219DE54(base1, (char*)saltin, 8); //calculate hash of salt 0

   memcpy(combo, base0, 0x14);
   memcpy(combo + 0x14, base1, 0x14);
   
   sha1Digest_219DE54(drvkey, combo, 0x28); //calculate hash from combination of salt 0 hash and klicensee hash

   memcpy(key, drvkey, 0x10);  //copy derived key

   // derive key 1
   
   saltin[1] = 2;

   sha1Digest_219DE54(base1, (char*)saltin, 8); //calculate hash of salt 1

   memcpy(combo, base0, 0x14);
   memcpy(combo + 0x14, base1, 0x14);

   sha1Digest_219DE54(drvkey, combo, 0x28); //calculate hash from combination of salt 1 hash and klicensee hash

   memcpy(iv_xor_key, drvkey, 0x10); //copy derived key

   return 0;
}

int calculate_sha1_chain_219E1CC(char* key, char* iv_xor_key, const char* klicensee, uint32_t ignored_salt0, uint32_t salt1)
{
   return calculate_sha1_chain_219E008(key, iv_xor_key, klicensee, salt1);
}

int hmac1_sha1_or_sha1_chain_219E0DC(char* key, char* iv_xor_key, const char* klicensee, uint32_t salt0, uint16_t flag, uint32_t salt1, uint16_t ignored_key_id)
{
   if((flag & 2) == 0)
   {
      calculate_sha1_chain_219E008(key, iv_xor_key, klicensee, salt1);
      return 0;
   }

   int saltin0[1] = {0};
   int saltin1[2] = {0};
   char drvkey[0x14] = {0};

   memcpy(key, klicensee, 0x10);

   if(salt0 == 0)
   {
      saltin0[0x00] = salt1;
      hmacSha1Digest_219DE68(drvkey, hmac_key_21A93C8, (char*)saltin0, 4); // derive key with one salt
   }
   else
   {
      saltin1[0] = salt0;
      saltin1[1] = salt1;
      hmacSha1Digest_219DE68(drvkey, hmac_key_21A93C8, (char*)saltin1, 8); // derive key with two salts
   }

   memcpy(iv_xor_key, drvkey, 0x10); //copy derived key

   return 0;
}

int hmac_sha1_219E164(char* key, char* iv_xor_key, const char* klicensee, uint16_t ignored_flag, uint16_t ignored_key_id, const char* base_key, uint32_t base_key_len)
{
   char drvkey[0x14] = {0};

   hmacSha1Digest_219DE68(drvkey, hmac_key_21A93C8, base_key, base_key_len);

   memcpy(key, klicensee, 0x10);

   memcpy(iv_xor_key, drvkey, 0x10);

   return 0;
}

int calculate_aes_cbc_encrypted_hmac_sha1_digest_219DF38(char* hmac_key, const char* klicensee, uint32_t salt0, uint32_t salt1, uint16_t key_id)
{
   char drvkey[0x14] = {0};
   char iv[0x10] = {0};
   char combo[0x14] = {0};

   //align buffers

   char* drvkey_aligned = drvkey + ((0 - (int)drvkey) & 0x3F);
   char* iv_aligned = iv + ((0 - (int)iv) & 0x3F);
   char* combo_aligned = combo + ((0 - (int)combo) & 0x3F);

   int saltin0[1] = {0};
   int saltin1[2] = {0};
   char base[0x14] = {0};

   if(salt0 == 0)
   {
      saltin0[0] = salt1;
      hmacSha1Digest_219DE68(base, hmac_key_21A93DC, (char*)saltin0, 4); // derive base with one salt
   }
   else
   {
      saltin1[0] = salt0;
      saltin1[1] = salt1;
      hmacSha1Digest_219DE68(base, hmac_key_21A93DC, (char*)saltin1, 8); // derive base with two salts
   }

   memcpy(combo_aligned, base, 0x14); // calculated digest will be src data

   memcpy(iv_aligned, iv_21A93F0, 0x10); //initialize iv

   AESCBCEncryptWithKeygen_base_219D9F4(klicensee, iv_aligned, 0x14, combo_aligned, drvkey_aligned, key_id);

   memcpy(hmac_key, drvkey_aligned, 0x14); // copy derived key
   
   return 0;
}

int combine_klicensee_digest_219E1D8(char* hmac_key, const char* klicensee, uint32_t salt0, uint16_t flag, uint32_t salt1, uint16_t key_id)
{
   if((flag << 0x1F) < 0) // check bit 0
   {
      memset(hmac_key, 0, 0x14);
      return 0;
   }

   if((flag << 0x1E) < 0) // check bit 1
   {
      calculate_aes_cbc_encrypted_hmac_sha1_digest_219DF38(hmac_key, klicensee, salt0, salt1, key_id);
      return 0;
   }

   int saltin[2] = {0};
   char base0[0x14] = {0};
   char base1[0x14] = {0};
   char combo[0x28] = {0};
   char drvkey[0x14] = {0};

   sha1Digest_219DE54(base0, klicensee, 0x10); // calculate digest of klicensee

   saltin[0] = 0xA;
   saltin[1] = salt1;

   sha1Digest_219DE54(base1, (char*)saltin, 8); // calculate digest of salt

   memcpy(combo, base0, 0x14);
   memcpy(combo + 0x14, base1, 0x14);
         
   sha1Digest_219DE54(drvkey, combo, 0x28); // calculate digest of combination of klicensee and salt digests
               
   memcpy(hmac_key, drvkey, 0x14); // copy derived key

   return 0;
}

//-------------------------------------

int sub_219A29C(const derive_keys_ctx* ctx)
{
   return ctx->unk_68;
}

int derive_keys_from_klicensee_219B4A0(CryptEngineData *data, uint32_t salt1, int unk2, int unk3, uint16_t seed1_base, int arg_4, const derive_keys_ctx* drv_ctx, const pfs_pmi_buffer_list_ctx *pfs_pmi_bcl)
{
   ctx_12f8d58e* ctx0 = SceIofilemgrForDriver_thread_related_12f8d58e();
   data->unk_18 = 0x100;
   if((ctx0 != 0) && (ctx0->unk_2C >= 0))
      data->unk_18 = (uint32_t)(ctx0->unk_2C & 0x0000FFFF);

   ctx_12f8d58e* ctx1 = SceIofilemgrForDriver_thread_related_12f8d58e();
   data->unk_14 = 0xF;
   if(ctx1 != 0)
      data->unk_14 = ctx1->unk_28;

   data->salt0 = pfs_pmi_bcl->salt0;
   data->salt1 = salt1;
   data->unk_1C = arg_4;

   data->type = pfs_pmi_bcl->type;
   data->flag = pfs_pmi_bcl->flag;
   data->key_id = pfs_pmi_bcl->key_id;
   data->seed1_base = seed1_base;
   
   data->unk_20 = unk2;
   data->unk_24 = unk3;

   data->klicensee = pfs_pmi_bcl->klicensee;

   data->size1 = drv_ctx->unk_14(drv_ctx);
   
   int some_flag_base = (uint32_t)(data->flag - 2);
   int some_flag = 0xC0000B03 & (1 << some_flag_base);

   if((some_flag_base > 0x1F) || (some_flag == 0))
   {
      calculate_sha1_chain_219E1CC(data->key, data->iv_xor_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->salt0, salt1);
      return combine_klicensee_digest_219E1D8(data->hmac_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->salt0, pfs_pmi_bcl->flag, salt1, pfs_pmi_bcl->key_id);
   }
   else
   {
      if((drv_ctx->unk_40 != 0 && drv_ctx->unk_40 != 3) || (drv_ctx->unk_58 <= 1))
      {    
         hmac1_sha1_or_sha1_chain_219E0DC(data->key, data->iv_xor_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->salt0, pfs_pmi_bcl->flag, salt1, pfs_pmi_bcl->key_id);
         return combine_klicensee_digest_219E1D8(data->hmac_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->salt0, pfs_pmi_bcl->flag, salt1, pfs_pmi_bcl->key_id);
      }
      else
      {
         if(drv_ctx->unk_40 == 0 || drv_ctx->unk_40 == 3)
         {
            hmac_sha1_219E164(data->key, data->iv_xor_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->flag, pfs_pmi_bcl->key_id, drv_ctx->base_key, 0x14);
            return combine_klicensee_digest_219E1D8(data->hmac_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->salt0, pfs_pmi_bcl->flag, salt1, pfs_pmi_bcl->key_id);
         }
         else
         {
            hmac_sha1_219E164(data->key, data->iv_xor_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->flag, pfs_pmi_bcl->key_id, 0, 0x14);
            return combine_klicensee_digest_219E1D8(data->hmac_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->salt0, pfs_pmi_bcl->flag, salt1, pfs_pmi_bcl->key_id);
         }
      }
   }
}

//-------------------------------------

void* proc_get_table_element_2198B1C(int index)
{
   return 0;
}

typedef struct init_res_219B934
{
   uint32_t unk_0;
   uint32_t unk_4;
}init_res_219B934;

/*
int init_crypto_context_219B934(CryptEngineSubctx *subctx, CryptEngineData *data, int unk2, int unk3, init_res_219B934* init_result)
{
   #pragma region

   int r4 = data->unk_20;
   int r5 = data->unk_24;
   
   unk1[0] = r4;
   unk1[4] = r5;

   int r5 = r5 - unk3;
   
   int r6 = data->size1; // 0x28
   
   int r9 = unk3;
   int r8 = unk2;
   
   subctx->opt_code = 4; // 0x08
   subctx->data = data; //0x0C
   
   subctx->unk_20 = 0x80;
   subctx->unk_24 = 0x80;

   subctx->unk_10 = 0;
   subctx->source = 0; //0x14

   subctx->unk_18 = 0;
   subctx->unk_1C = 0;

   subctx->size2 = 0; //0x28
   subctx->nDigests = 0; //0x2C
   
   subctx->unk_30 = 0;
   subctx->seed0_base = 0; //0x34

   subctx->dest_offset = 0; //0x38
   subctx->size0 = 0; //0x3C

   subctx->size1 = 0; //0x40
   subctx->unk_44 = 0;

   subctx->size3 = 0; //0x48
   subctx->hmac_sha1_digest = 0; //0x4C

   subctx->buffer0 = 0; //0x50
   subctx->buffer1 = 0; //0x54

   #pragma endregion

   int r10 = 0;
   int r3 = 4;

   if(r4 < unk2)
   {
      #pragma region

      int r1 = data->unk_14; //0x14
      int r0 = data->unk_18; //0x18
      int r0 = 8;
      int r0 = r0 - 1;
      
      int r2 = unk1[0];
      int r3 = unk1[4];
      
      int r0 = r6 * r0;
      int r2 = r2 + r0;
      int r3 = r3 + 0;
      int r4 = r2 + 1;
      int r5 = r3 + 0;
      int r0 = r5 - r9;
      
      if(r4 < r8)
      {
         int r3 = r10;
         int r0 = r4;
         int r1 = r5;
         int r2 = r6;

         SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);

         int r8 = r4 - r2;
         int r9 = r5 - r3;
      }

      #pragma endregion

      #pragma region
      
      int r1 = unk1[0];
      int r2 = r6;
      
      subctx->unk_20 = r8;
      subctx->unk_24 = r9;

      int r3 = r8 - r1;

      int r0 = unk1[0];
      int r1 = unk1[4];
      
      subctx->size2 = r3; //0x28
      
      int r3 = 0;
      
      int r0 = SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);
      int r4 = r0;

      int r0 = r8 + 0xFFFFFFFF;

      int r2 = r6;
      int r3 = 0;
      int r5 = r1;
      int r1 = r9 + 0xFFFFFFFF;

      int r0 = SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);
      
      int r0 = r0 - r4;
      
      subctx->seed0_base = r4; //0x34
      
      int r3 = r0 + 1;
      
      int r2 = r6;
      
      subctx->nDigests = r3; //0x2C
      
      int r3 = 0;

      int r0 = unk1[0];
      int r1 = unk1[1];
      int r10 = r3;
      
      SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);
      
      int r1 = data->unk_1C;

      subctx->dest_offset = r2; //0x38
      subctx->size1 = r10; //0x40

      #pragma endregion

      if(r1 == 1)
      {
         #pragma region

         int r0 = r2 | r3;
         if(r0 == 0)
         {
            r4 = r10;
         }

         if(r0 != 0)
         {
            var_38[0] = r4;
            var_38[1] = r10;
            
            int r0 = var_38[0];
            int r1 = var_38[1];

            if((r5 == r1) && (r4 == r0))
            {
               int r4 = r2;
            }
            else
            {
               int r4 = r6;
            }
         }

         int r3 = 0;
         subctx->size0 = r4; //0x3C
         subctx->size3 = r3; //0x48

         int r0 = r8;
         int r1 = r9;
         int r2 = r6;
         int r0 = SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);

         int r1 = r3 - 0; //why this line. does it influence comparison ?
         if(r2 < 1)
         {
            int r2 = r6;
         }
         
         subctx->unk_44 = r2; //0x44

         init_result->unk_0 = r8;
         init_result->unk_4 = r9;

         #pragma endregion
         
         return r0;
      }
      else
      {
         #pragma region

         int r4 = r2 | r3;
         int r0 = r8;
         
         if(r4 != 0)
         {
            int r3 = r6;
         }
         else
         {
            int r3 = 0;
         }

         int r1 = r9;
         subctx->size0 = r3; //0x3C
         int r2 = r6;
         int r3 = r10;
         int r0 = SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);
         
         int r5 = r3 - 0; //why this line. does it influence comparison ?
         if(r2 >= 1)
         {
            int r4 = r6 - r2;
         }
         else
         {
            int r4 = r10;
         }

         subctx->unk_44 = r6;
         subctx->size3 = r4; //0x48
         
         init_result->unk_0 = r8;
         init_result->unk_4 = r9;

         #pragma endregion
         
         return r0;
      }
   }
   else
   {
      #pragma region

      subctx->unk_20 = r8;
      subctx->unk_24 = r9;

      int r3 = r10;
      int r0 = r2;
      int r1 = r9;
      int r2 = r6;

      int r0 = SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);

      var_38 = r0;
      int r1 = r9;
      int r5 = var_38;

      int r0 = r8;
      int r2 = r6;
      int r3 = r10;

      subctx->seed0_base = r5; //0x34
      
      int r0 = SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);
      
      int r5 = r3;

      int r3 = data->unk_1C;
      int r4 = r2;
      
      int r0 = r4 | r5;

      subctx->dest_offset = r4; //0x38
      
      if(r0 == 0)
      {
         int r2 = 0;
      }
      else
      {
         int r2 = 1;
      }

      subctx->nDigests = r2; //0x2C

      #pragma endregion

      if(r3 == 1)
      {
         if(r2 == 0)
         {
            #pragma region

            subctx->size0 = r2; //0x3C
            subctx->unk_44 = r4;

            init_result->unk_0 = r8;
            init_result->unk_4 = r9;

            #pragma endregion
            
            return r0;
         }
         else
         {
            #pragma region

            int r1 = var_38;
            int r2 = 0;
            var_2C = r2;
            int r3 = r10;
            int r2 = r6;
            var_30 = r1;
            
            int r0 = unk1[0];
            int r1 = unk1[1];
            int r0 = SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);

            int r2 = var_30[0];
            int r3 = var_30[1];
            
            if((r1 == r3) && (r0 == r2))
            {
               int r0 = unk1[0];
               int r1 = unk1[1];

               int r2 = r6;
               int r3 = r10;
               int r0 = SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);
            }
            else
            {
               int r2 = r6;
            }

            subctx->size0 = r2; //0x3C
            subctx->unk_44 = r4;
            
            init_result->unk_0 = r8;
            init_result->unk_4 = r9;

            #pragma endregion

            return 0;
         }
      }
      else
      {
         #pragma region

         if(r2 == 0)
         {
            int r3 = 0;
         }
         else
         {
            subctx->size0 = r6; //0x3C
            int r3 = r5 - 0; //does this influence comparison?

            if(r4 < 1)
            {
               int r3 = 0;
            }
            else
            {
               int r3 = r6;
               int r4 = r6 - r4;
               subctx->size3 = r4; //0x48
            }
         }

         subctx->unk_44 = r3;

         init_result->unk_0 = r8;
         init_result->unk_4 = r9;

         #pragma endregion
         
         return 0;
      }
   }
}
*/

int validate_subctx_zero_pointers_219BB14(CryptEngineSubctx *subctx)
{
   return 0;
}

int subctx_enter_219AC0C(CryptEngineSubctx *subctx, int unk1, int unk2)
{
   return 0;
}

int dispatch_task_to_crypto_engine_219BD88(CryptEngineWorkCtx *work)
{
   return 0;
}

int wait_task_to_crypto_engine_219BEA0(CryptEngineWorkCtx *work)
{
   return 0;
}

int subctx_exit_219AB30(CryptEngineSubctx *subctx, int unk1, int unk2)
{
   return 0;
}

int crypto_ScePfsCryptBufVC_219BB70(void *unk0)
{
   return 0;
}

int clear_crypto_data_219B5C4(CryptEngineData *data)
{
   return 0;
}

//-------------------------------------

int ScePfsCryptEngineThread_219BBB0()
{
   return 0;
}


//dec sw ex
void loc_219C64C()
{
   /*
   LDR             R5, [SP,#0xC0+key]
   */

   if(r5 == 0)
   {
      /*
      MOVS            R3, #0
      LDR             R5, [SP,#0xC0+crypt_ctx]
      STR             R3, [R5,#0xC] ; set error to field 0xC
      */
      return;
   }

   /*
   LDR.W           R10, [SP,#0xC0+key]
   MOVS            R5, #0
   MOV             R6, R5
   MOV             R7, R9
   */

   while(true)
   {
      /*
      LDRD.W          R8, R9, [SP,#0x48]
      ADDS            R6, #1
      LDR             R2, [SP,#0xC0+hmac_key]
      MOV             R0, R11 ; cmac_key
      LDR             R3, [SP,#0xC0+ignored] ; ignored
      MOV             R1, R7  ; key
      ADDS.W          R8, R8, R5
      STR             R4, [SP,#0xC0+arg_8_i] ; size0
      ADD             R2, R5
      ADC.W           R9, R9, #0
      STRD.W          R2, R2, [SP,#0x10]
      MOVS            R2, #0x80 ; keysize
      STR             R4, [SP,#0xC0+arg_C_i] ; size1
      ADD             R5, R4
      STR             R3, [SP,#0xC0+arg_18_i] ; flag
      STRD.W          R8, R9, [SP]
      BL              pfs_decrypt_sw_219D174
      */

      if(r6 == r10)
         break;
   }

   /*
   MOVS            R3, #0
   LDR             R5, [SP,#0xC0+crypt_ctx]
   STR             R3, [R5,#0xC] ; set error to field 0xC
   */
}

//dec hw ex
void loc_0219C928()
{
   /*
   LDR             R6, [SP,#0xC0+key]
   */

   if(r6 == 0)
   {
      /*
      MOVS            R3, #0
      LDR             R5, [SP,#0xC0+crypt_ctx]
      STR             R3, [R5,#0xC] ; set error to field 0xC
      */
      return;
   }

   /*
   LDR             R7, [SP,#0xC0+key_id]
   MOV             R10, R9
   LDR.W           R9, [SP,#0xC0+hmac_key]
   MOV             R6, R5
   MOV             R8, R7
   MOV             R7, R11
   LDR.W           R11, [SP,#0xC0+key]
   */

   while(true)
   {
      /*
      ADD.W           R3, R9, R5
      LDR             R0, [SP,#0xC0+ignored]
      STR             R3, [SP,#0xC0+arg_8_i] ; src
      CMP             R4, R8
      ITE CC
      MOVCC           LR, R4
      MOVCS           LR, R8
      STR             R3, [SP,#0xC0+arg_C_i] ; dst
      ADDS            R6, #1
      LDRD.W          R2, R3, [SP,#0x48]
      SUB.W           R8, R8, R4
      LDR             R1, [SP,#0xC0+unk0]
      STR             R0, [SP,#0xC0+arg_10_i] ; flag
      MOV             R0, R7  ; key
      ADDS            R2, R2, R5 ; iv_seed0
      STR             R4, [SP,#0xC0+arg_4_i] ; size1
      STR             R1, [SP,#0xC0+arg_14_i] ; key_id
      ADC.W           R3, R3, #0
      MOV             R1, R10 ; iv_xor_key
      STR.W           LR, [SP,#0xC0+arg_0_i] ; size0
      BL              pfs_decrypt_hw_219D480
      ADD             R5, R4
      */

      if(r6 == r11)
         break;
   }

   /*
   MOVS            R3, #0
   LDR             R5, [SP,#0xC0+crypt_ctx]
   STR             R3, [R5,#0xC] ; set error to field 0xC
   */
   return;
}

//dec sw
void loc_219C7EA()
{
   /*
   LDR             R5, [SP,#0xC0+hmac_key]
   MOV             R1, R9  ; key
   LDR             R7, [SP,#0xC0+ignored]
   MOV             R0, R11 ; cmac_key
   STR             R2, [SP,#0xC0+arg_0_i] ; seed0
   MOVS            R2, #0x80 ; keysize
   STR             R3, [SP,#0xC0+arg_4_i] ; seed1
   STRD.W          R5, R5, [SP,#0x10]
   STRD.W          R4, R4, [SP,#8]
   STR             R7, [SP,#0xC0+arg_18_i] ; flag
   BL              pfs_decrypt_sw_219D174
   LDRD.W          R3, R5, [R10,#0x18]
   LDR.W           R1, [R10,#0x34]
   */
}

//dec hw
void loc_0219C6F8()
{
   /*
   LDR             R5, [SP,#0xC0+hmac_key]
   MOV             R1, R9  ; iv_xor_key
   LDR             R7, [SP,#0xC0+ignored] ; flag
   MOV             R0, R11 ; key
   STRD.W          R4, R4, [SP] ; int size0, int size1
   STRD.W          R5, R5, [SP,#0xC0+arg_8_i] ; char *src, char *dst
   LDR             R5, [SP,#0xC0+unk0] ; key_id
   STRD.W          R7, R5, [SP,#0xC0+arg_10_i] ; int flag, int key_id
   BL              pfs_decrypt_hw_219D480
   LDRD.W          R3, R5, [R10,#0x18]
   LDR.W           R1, [R10,#0x34]
   */
}

//dec sw
void loc_219C7C6()
{
   /*
   LDR             R7, [SP,#0xC0+ignored]
   MOV             R1, R9  ; key
   STR             R2, [SP,#0xC0+arg_0_i] ; seed0
   MOV             R0, R11 ; cmac_key
   STR             R3, [SP,#0xC0+arg_4_i] ; seed1
   MOVS            R2, #0x80 ; keysize
   STRD.W          R4, R5, [SP,#0xC]
   STR             R5, [SP,#0xC0+arg_14_i] ; dst_cmac_base
   STR             R4, [SP,#0xC0+arg_8_i] ; size0
   STR             R7, [SP,#0xC0+arg_18_i] ; flag
   BL              pfs_decrypt_sw_219D174
   LDRD.W          R3, R5, [R10,#0x18]
   LDR.W           R1, [R10,#0x34]
   */
}

//dec hw
void loc_0219C544()
{
   /*
   CMP             R0, R4
   IT CS
   MOVCS           R0, R4
   STR             R5, [SP,#0xC0+arg_C_i] ; size1
   STMEA.W         SP, {R0,R4,R5}
   MOV             R1, R9  ; iv_xor_key
   LDR             R5, [SP,#0xC0+ignored]
   MOV             R0, R11 ; key
   LDR             R6, [SP,#0xC0+unk0]
   STRD.W          R5, R6, [SP,#0x10]
   BL              pfs_decrypt_hw_219D480
   LDRD.W          R3, R5, [R10,#0x18]
   LDR.W           R1, [R10,#0x34]
   */
}

//dec sw ex
void loc_219C782()
{
   if(r5 == 0)
   {
      /*
      MOVS            R3, #0
      LDR             R5, [SP,#0xC0+crypt_ctx]
      STR             R3, [R5,#0xC] ; set error to field 0xC
      */
      return;
   }
   
   /*
   MOV             R3, R5
   MOVS            R6, #0
   MOV             R5, R6
   MOV             R10, R3
   */

   while(true)
   {
      /*
      LDRD.W          R2, R3, [SP,#0x28]
      ADD.W           R1, R8, R6
      ADD.W           LR, R7, R6
      STR             R1, [SP,#0xC0+arg_10_i] ; src_cmac_base
      STRD.W          R4, R4, [SP,#8]
      ADDS            R5, #1
      ADDS            R2, R2, R6
      MOV             R0, R11 ; cmac_key
      ADC.W           R3, R3, #0
      MOV             R1, R9  ; key
      STRD.W          R2, R3, [SP]
      MOVS            R2, #0x80 ; keysize
      LDR             R3, [SP,#0xC0+ignored] ; ignored
      ADD             R6, R4
      STRD.W          LR, R3, [SP,#0x14]
      BL              pfs_decrypt_sw_219D174
      */


      if(r5 == r10)
         break;
   }

   /*
   MOVS            R3, #0
   LDR             R5, [SP,#0xC0+crypt_ctx]
   STR             R3, [R5,#0xC] ; set error to field 0xC
   */
   return;
}

//dec hw ex
void loc_0219C5C6()
{
   if(r5 == 0)
   {
      /*
      MOVS            R3, #0
      LDR             R5, [SP,#0xC0+crypt_ctx]
      STR             R3, [R5,#0xC] ; set error to field 0xC
      */
      return;
   }

   /*
   MOV             R3, R5
   MOVS            R6, #0
   STR.W           R9, [SP,#0xC0+var_8C]
   MOV             R5, R11
   MOV             R9, R7
   MOV             R10, R6
   MOV             R7, R4
   MOV             R11, R3
   MOV             R4, R2
   */

   while(true)
   {
      /*
      CMP             R4, R7
      ITE CC
      MOVCC           R2, R4
      MOVCS           R2, R7
      ADD.W           R3, R8, R6
      STR             R2, [SP,#0xC0+arg_0_i] ; size0
      ADD.W           LR, R9, R6
      STR             R3, [SP,#0xC0+arg_8_i] ; src
      ADD.W           R10, R10, #1
      LDRD.W          R2, R3, [SP,#0x28]
      SUBS            R4, R4, R7
      LDR             R0, [SP,#0xC0+ignored]
      LDR             R1, [SP,#0xC0+unk0]
      ADDS            R2, R2, R6 ; iv_seed0
      STR             R7, [SP,#0xC0+arg_4_i] ; size1
      STR             R0, [SP,#0xC0+arg_10_i] ; flag
      ADC.W           R3, R3, #0
      STR             R1, [SP,#0xC0+arg_14_i] ; key_id
      MOV             R0, R5  ; key
      LDR             R1, [SP,#0xC0+var_8C] ; iv_xor_key
      ADD             R6, R7
      STR.W           LR, [SP,#0xC0+arg_C_i] ; dst
      BL              pfs_decrypt_hw_219D480
      */

      if(r10 == r11)
         break;
   }
   
   /*
   MOVS            R3, #0
   LDR             R5, [SP,#0xC0+crypt_ctx]
   STR             R3, [R5,#0xC] ; set error to field 0xC
   */
   return;
}


void loc_219C622()
{
   /*
   LDR             R6, [SP,#0xC0+iv_xor_key]
   AND.W           R5, R6, #0x4000
   UXTH            R5, R5
   */

   if(r5 == 0)
   {
      /*
      MOVS            R3, #0
      LDR             R5, [SP,#0xC0+crypt_ctx]
      STR             R3, [R5,#0xC] ; set error to field 0xC
      */
      return;
   }

   /*
   LDR             R7, [SP,#0xC0+iv_xor_key]
   LSLS            R1, R7, #0x10
   */

   if(r1 < 0)
   {
      /*
      MOVS            R3, #0
      LDR             R5, [SP,#0xC0+crypt_ctx]
      STR             R3, [R5,#0xC] ; set error to field 0xC
      */
      return;
   }

   /*
   LDR             R6, [SP,#0xC0+ignored]
   AND.W           R3, R6, #0x41
   */

   if(r3 == 0x41)
   {
      /*
      MOVS            R3, #0
      LDR             R5, [SP,#0xC0+crypt_ctx]
      STR             R3, [R5,#0xC] ; set error to field 0xC
      */
      return;
   }

   //LDR             R6, [SP,#0xC0+var_8C]

   if(r6 <= 0x1F)
   {
      /*
      LDR             R6, [SP,#0xC0+var_8C]
      MOVS            R2, #1
      MOV             R3, 0xC0000B03
      LSLS            R2, R6
      ANDS            R3, R2
      */

      if(r3 == 0)
      {
         return loc_219C64C();
      }
      else
      {
         return loc_0219C928();
      }
   }
   else
   {
      return loc_219C64C();
   }
}

void loc_0219C218()
{
   /*
   LDR             R7, [SP,#0xC0+iv_xor_key]
   LDR.W           R3, [R10,#0x18]
   AND.W           R6, R7, #0x4000
   */

   if(r3 == 0)
   {
      #pragma region

      /*
      UXTH            R6, R6
      LDR.W           R1, [R10,#0x34]
      */

      if(r6 == 0)
      {
         //LSLS            R2, R7, #0x10
         if(r2 >= 0)
         {
            /*
            LDR             R7, [SP,#0xC0+ignored]
            AND.W           R2, R7, #0x41
            */

            if(r2 != 0x41)
            {
               /*
               LDR             R5, [SP,#0xC0+var_8C]
               MUL.W           R2, R4, R1
               MOV             R3, R6  ; ignored
               */

               if(r5 > 0x1F)
               {
                  loc_219C7EA();
               }
               else
               {
                  /*
                  MOVS            R0, #1
                  MOVW            R1, #0xB03
                  LSLS            R0, R5
                  MOVT.W          R1, #0xC000
                  ANDS            R1, R0
                  */

                  if(r1 == 0)
                  {
                     loc_219C7EA();
                  }
                  else
                  {
                     loc_0219C6F8();
                  }
               }
            }
         }
      }

      #pragma endregion
   }
   else
   {
      /*
      LDR.W           R1, [R10,#0x34]
      UXTH            R6, R6
      */
   }

   /*
   LDR.W           R2, [R10,#0x2C]
   ADDS            R0, R5, R3
   CMP             R0, R2
   */

   if(r0 < r2)
   {
      /*
      LDR.W           R0, [R10,#0x40]
      */

      if(r6 != 0)
      {
         /*
         MUL.W           R3, R4, R3
         LDR.W           R1, [R10,#0x38]
         LDR.W           R7, [R10,#0x10]
         LDR.W           R8, [SP,#0xC0+hmac_key]
         MUL.W           R2, R4, R5
         SUBS            R1, R3, R1
         ADD             R8, R3
         ADD             R7, R1
         */

         if(r8 == r7)
         {
            //MOVS            R3, #0
            //LDR             R5, [SP,#0xC0+crypt_ctx]
            //STR             R3, [R5,#0xC] ; set error to field 0xC
            return;
         }
         else
         {
            /*
            MOV             R0, R7  ; destination
            MOV             R1, R8  ; source
            BLX             ScePfsMgr.SceSysclibForDriver._imp_memcpy_40c88316
            */

            //MOVS            R3, #0
            //LDR             R5, [SP,#0xC0+crypt_ctx]
            //STR             R3, [R5,#0xC] ; set error to field 0xC
            return;
         }
      }
      else
      {
         #pragma region

         /*
         LDR             R7, [SP,#0xC0+iv_xor_key]
         SXTH            R7, R7
         STR             R7, [SP,#0xC0+key]
         */

         if(r7 >= 0)
         {
            /*
            LDR             R7, [SP,#0xC0+ignored]
            AND.W           LR, R7, #0x41
            */

            if(lr != 0x41)
            {
               /*
               SUBS            R5, R2, #1
               LDR             R7, [SP,#0xC0+var_8C]
               ADDS            R2, R1, R5
               LDR             R1, [SP,#0xC0+hmac_key]
               MOV             R3, R6  ; ignored
               MUL.W           R2, R4, R2
               MLA.W           R5, R4, R5, R1
               */

               if(r7 > 0x1F)
               {
                  loc_219C7C6();
               }
               else
               {
                  /*
                  MOV.W           LR, #1
                  MOVW            R1, #0xB03
                  LSL.W           LR, LR, R7
                  MOVT.W          R1, #0xC000
                  AND.W           R1, LR, R1
                  */

                  if(r1 == 0)
                  {
                     loc_219C7C6();
                  }
                  else
                  {
                     loc_0219C544();
                  }
               }
            }
         }

         #pragma endregion

         /*
         MUL.W           R8, R4, R3
         LDR.W           R7, [R10,#0x38]
         LDR.W           R0, [R10,#0x10]
         LDR             R6, [SP,#0xC0+hmac_key]
         MUL.W           R2, R4, R5
         SUB.W           R7, R8, R7
         ADD             R7, R0
         ADD             R8, R6
         */

         //goto loc_219C582
      }
   }
   else
   {
      /*
      MUL.W           R8, R4, R3
      LDR.W           R7, [R10,#0x38]
      LDR.W           LR, [R10,#0x10]
      LDR             R0, [SP,#0xC0+hmac_key]
      MUL.W           R2, R4, R5
      SUB.W           R7, R8, R7
      ADD             R7, LR
      ADD             R8, R0
      */

      if(r6 != 0)
      {
         if(r8 == r7)
         {
            //MOVS            R3, #0
            //LDR             R5, [SP,#0xC0+crypt_ctx]
            //STR             R3, [R5,#0xC] ; set error to field 0xC
            return;
         }
         else
         {
            /*
            MOV             R0, R7  ; destination
            MOV             R1, R8  ; source
            BLX             ScePfsMgr.SceSysclibForDriver._imp_memcpy_40c88316
            */

            //MOVS            R3, #0
            //LDR             R5, [SP,#0xC0+crypt_ctx]
            //STR             R3, [R5,#0xC] ; set error to field 0xC
            return;
         }
      }
      else
      {
         /*
         LDR             R6, [SP,#0xC0+iv_xor_key]
         SXTH            R6, R6
         STR             R6, [SP,#0xC0+key]
         */

         //goto loc_219C582
      }
   }

   //loc_219C582

   /*
   LDR             R6, [SP,#0xC0+key]
   */

   if(r6 < 0)
   {
      if(r8 == r7)
      {
         //MOVS            R3, #0
         //LDR             R5, [SP,#0xC0+crypt_ctx]
         //STR             R3, [R5,#0xC] ; set error to field 0xC
         return;
      }
      else
      {
         /*
         MOV             R0, R7  ; destination
         MOV             R1, R8  ; source
         BLX             ScePfsMgr.SceSysclibForDriver._imp_memcpy_40c88316
         */

         //MOVS            R3, #0
         //LDR             R5, [SP,#0xC0+crypt_ctx]
         //STR             R3, [R5,#0xC] ; set error to field 0xC
         return;
      }
   }
   else
   {
      /*
      LDR             R6, [SP,#0xC0+ignored]
      AND.W           R0, R6, #0x41
      */

      if(r0 == 0x41)
      {
         if(r8 == r7)
         {
            //MOVS            R3, #0
            //LDR             R5, [SP,#0xC0+crypt_ctx]
            //STR             R3, [R5,#0xC] ; set error to field 0xC
            return;
         }
         else
         {
            /*
            MOV             R0, R7  ; destination
            MOV             R1, R8  ; source
            BLX             ScePfsMgr.SceSysclibForDriver._imp_memcpy_40c88316
            */

            //MOVS            R3, #0
            //LDR             R5, [SP,#0xC0+crypt_ctx]
            //STR             R3, [R5,#0xC] ; set error to field 0xC
            return;
         }
      }
      else
      {
         /*
         ADD             R3, R1
         LDR             R6, [SP,#0xC0+var_8C]
         MUL.W           R3, R4, R3
         VDUP.32         D16, R3
         VSHR.U64        D16, D16, #0x20
         VSTR            D16, [SP,#0xC0+key]
         */

         if(r6 > 0x1F)
         {
            loc_219C782();
         }
         else
         {
            /*
            LDR             R6, [SP,#0xC0+var_8C]
            MOVS            R1, #1
            MOV             R3, 0xC0000B03
            LSLS            R1, R6
            ANDS            R3, R1
            */

            if(r3 == 0)
            {
               loc_219C782();
            }
            else
            {
               loc_0219C5C6();
            }
         }
      }
   }
}


void loc_219C206()
{
   /*
   LDR.W           R5, [R10,#0x1C]
   ADD.W           R11, R9, #0x2C
   ADD.W           R9, R9, #0x3C
   */

   if(r5 == 0)
   {
      loc_219C622();
   }
   else
   {
      loc_0219C218();
   }
}

void loc_219C3A0()
{
   /*
   LDR             R5, [SP,#0xC0+ignored]
   AND.W           R3, R5, #0x41
   */

   if(r3 == 0x41)
   {
      return loc_219C206();
   }

   //LDR             R5, [SP,#0xC0+key]

   if(r5 == 0)
   {
      return loc_219C206();
   }

   /*
   LDR             R0, [SP,#0xC0+ignored]
   MOV             R8, R6  ; real digest for comparison
   STRD.W          R10, R9, [SP,#0x5C]
   MOV.W           R11, #0
   MOV             R9, R4  ; hmac_src_size
   LDR             R6, [SP,#0xC0+hmac_key] ; hmac_src
   AND.W           R7, R0, #9
   ADD             R5, SP, #0xC0+bytes14 ; hmac_digest
   MOV             R4, R7
   LDR.W           R10, [SP,#0xC0+unk1] ; hmac_key
   LDR             R7, [SP,#0xC0+key]
   */

   //loc_219C3E4
   while(true)
   {
      /*
      MOV             R1, R10
      MOV             R0, R5  ; digest_result
      MOV             R2, R6  ; src
      MOV             R3, R9  ; size
      BL              hmac_sha1_digest_219DE7C
      MOV             R0, R8  ; unk0
      MOV             R1, R5  ; unk1 - calculated result
      BL              proc_verify_14_bytes_219DE44
      */

      if((r0 != 0) || (r4 == 1))
      {
         /*
         ADD.W           R11, R11, #1
         ADD             R6, R9
         ADD.W           R8, R8, #0x14
         */
         if(r11 == r7)
            break;
      }
      else
      {
         //MOV             R3, 0x80140F02
         //LDR             R5, [SP,#0xC0+crypt_ctx]
         //STR             R3, [R5,#0xC] ; set error to field 0xC
         return;
      }
   }

   /*
   MOV             R4, R9
   LDRD.W          R10, R9, [SP,#0x5C]
   */

   return loc_219C206();
}

void loc_0219C176()
{
   /*
   LDR             R7, [SP,#0xC0+ignored]
   AND.W           R3, R7, #0x41
   */

   if(r3 == 0x41)
   {
      return  loc_219C206();
   }

   /*
   LDRD.W          R0, R1, [SP,#0x48]
   MOV             R2, R4  ; unk2
   MOV             R3, R5  ; unk3
   BLX             ScePfsMgr.SceSysclibForDriver._imp_7554ab04
   STR             R0, [SP,#0xC0+data]
   LDR             R0, [SP,#0xC0+key]
   */

   if(r0 == 0)
   {
      return loc_219C206();
   }

   /*
   LDR             R1, [SP,#0xC0+ignored]
   ADD.W           R12, SP, #0xC0+data
   MOV             R8, R6
   MOV             R11, R5
   STR.W           R9, [SP,#0xC0+var_5C]
   ADD             R5, SP, #0xC0+bytes14
   AND.W           R1, R1, #9
   LDR             R7, [SP,#0xC0+hmac_key]
   STRD.W          R1, R10, [SP,#0x5C]
   MOV             R10, R12
   LDRD.W          R6, R9, [SP,#0x54]
   */

   //loc_219C1CE 
   while(true)
   {
      /*
      MOV             R1, R9
      MOV             R2, R10 ; data
      MOVS            R3, #4  ; data_len
      ADD             R0, SP, #0xC0+digest ; digest
      BL              hmacSha1Digest_219DE68
      ADD             R1, SP, #0xC0+digest ; key_ctx_klicensee
      MOV             R0, R5  ; digest_result
      MOV             R2, R7  ; src
      CMP             R4, R6
      ITE CC
      MOVCC           R3, R4
      MOVCS           R3, R6  ; size
      BL              hmac_sha1_digest_219DE7C
      MOV             R0, R8  ; unk0
      MOV             R1, R5  ; unk1
      BL              proc_verify_14_bytes_219DE44
      */

      //LDR             R2, [SP,#0xC0+var_64]

      if((r0 != 0) || (r2 == 1))
      {
         /*
         LDR             R3, [SP,#0xC0+data]
         ADD.W           R11, R11, #1
         SUBS            R6, R6, R4
         ADD             R7, R4
         ADD.W           R8, R8, #0x14
         ADDS            R3, #1
         STR             R3, [SP,#0xC0+data]
         LDR             R3, [SP,#0xC0+key]
         */

         if(r11 == r3)
            break;
      }
      else
      {
         //MOV             R3, 0x80140F02
         //LDR             R5, [SP,#0xC0+crypt_ctx]
         //STR             R3, [R5,#0xC] ; set error to field 0xC
         return;
      }
   }

   //LDRD.W          R10, R9, [SP,#0x60]

   return loc_219C206();
}


void crypt_engine_work_3()
{
   /*
   LDR.W           R9, [R10,#0xC]
   LDR.W           R2, [R10,#0x34]
   LDR.W           R5, [R10,#0x2C]
   LDR.W           R4, [R9,#0x28]
   LDRH.W          R1, [R9,#0xC]
   LDRH.W          R6, [R9,#0xE]
   SUBS            R7, R5, #1
   LDR.W           R3, [R10,#0x40]
   MUL.W           R2, R4, R2
   STR             R5, [SP,#0xC0+key]
   SUBS            R1, #2
   LDRH.W          R5, [R9,#0x10]
   UXTH            R1, R1
   STR             R6, [SP,#0xC0+ignored]
   LDRH.W          R6, [R9,#0x12]
   MLA.W           R3, R4, R7, R3
   VDUP.32         D16, R2
   STR             R5, [SP,#0xC0+unk0]
   
   VSHR.U64        D16, D16, #0x20
   STR             R6, [SP,#0xC0+iv_xor_key]
   STR             R1, [SP,#0xC0+var_8C]
   LDR.W           R6, [R10,#0x4C]
   STR             R3, [SP,#0xC0+key_id]
   VSTR            D16, [SP,#0xC0+unk3]
   */

   if(r1 > 0x1F)
   {
      /*
      LDR.W           R5, [R10,#0x50]
      STR             R5, [SP,#0xC0+hmac_key]
      */
   }
   else
   {
      /*
      MOVS            R2, #1
      MOVW            R3, #0xB03
      LSLS            R2, R1
      MOVT.W          R3, #0xC000
      ANDS            R3, R2
      */

      if(r3 == 0)
      {
         /*
         LDR.W           R5, [R10,#0x50]
         STR             R5, [SP,#0xC0+hmac_key]
         */
      }
      else
      {
         /*
         LDR.W           R5, [R10,#0x54] ; R10 = CryptEngineSubctx*
         STR             R5, [SP,#0xC0+hmac_key]
         */
      }
   }

   /*
   LDR             R5, [SP,#0xC0+iv_xor_key]
   LSLS            R5, R5, #0x12
   */

   if(r5 < 0)
   {
      return loc_219C206();
   }

   /*
   LDR             R7, [SP,#0xC0+iv_xor_key]
   LSLS            R0, R7, #0x10
   */

   if(r0 < 0)
   {
      return loc_219C206();
   }

   /*
   LDR             R7, [SP,#0xC0+ignored]
   AND.W           R5, R7, #0x20
   UXTH            R5, R5
   */

   if(r5 != 0)
   {
      return  loc_219C206();
   }

   /*
   LDR             R7, [SP,#0xC0+var_8C]
   ADD.W           R0, R9, #0x4C
   STR             R0, [SP,#0xC0+unk1]
   */

   if(r7 > 0x1F)
   {
      return loc_219C3A0();
   }
   else
   {
      /*
      MOVS            R2, #1
      MOVW            R3, #0xB03
      LSLS            R2, R7
      MOVT.W          R3, #0xC000
      ANDS            R3, R2
      */

      if(r3 == 0)
      {
         return loc_219C3A0();
      }
      else
      {
         return loc_0219C176();
      }
   }
}

void crypt_engine_work_2_4()
{

}

void ScePfsCryptEngineThread_work_219BF20(CryptEngineWorkCtx *work_ctx)
{
   /*
   LDR.W           R10, [R0,#8] ; get CryptEngineSubctx*
   LDR.W           R3, [R10,#8] ; get opt code
   STR             R0, [SP,#0xC0+crypt_ctx]
   */

   switch(r3)
   {
   case 2:
      crypt_engine_work_2_4();
      break;
   case 3:
      crypt_engine_work_3();
      break;
   case 4:
      crypt_engine_work_2_4();
      break;
   default:
      break;
   }
}