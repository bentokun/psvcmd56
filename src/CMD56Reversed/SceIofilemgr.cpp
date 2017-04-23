#include "SceIofilemgr.h"

#include "Constants.h"
#include "SceSysmemGlobalVariables.h"


typedef struct vfs_block_dev_info //size is 0x14
{
  char* vitaMount;
  char* filesystem; // Some name, I guess it is filesystem
  char* blockDevicePrimary;
  char* blockDeviceSecondary; // can be 0
  uint32_t vshMountId; //must be same as in mount_point_info
}vfs_block_dev_info;

typedef struct vfs_mount_point_info_base
{
  char* unixMount;
  char* unk_4; //zero
  uint32_t devMajor;
  uint32_t devMinor;

  char* filesystem;
  uint32_t unk_14; //zero
  vfs_block_dev_info* blockDev1;
  uint32_t unk_1C; //zero
} vfs_mount_point_info_base;

//probably vfsops
typedef struct node_ops1 // size is 0x34 (13 pointers)
{
  int (*func1)(void* ctx);
  int (*func2)(void* ctx); // ?
  int (*func3)(void* ctx);
  int (*func4)(void* ctx);
  int (*func5)(void* ctx); // not implemented by all
  int (*func6)(void* ctx); // not implemented by all
  int (*func7)(void* ctx);
  int (*func8)(void* ctx); // not implemented by all
  int (*func9)(void* ctx); // called by sceVfsAddVfs
  int (*func10)(void* ctx); // called by sceVfsDeleteVfs
  int (*func11)(void* ctx); // not implemented by all
  int (*func12)(void* ctx); // sceIoDevctlForDriver
  int (*func13)(void* ctx); // (initialize partition entry in table)(map block device name on numeric name)
} node_ops1;

//probably vnodeops
typedef struct node_ops2 // size is 0x74 (29 pointers)
{
  int (*func1)(void* ctx); // sceIoOpenForDriver (this function creates device handle) (It operates with normal block device name and unix mount)
  int (*func2)(void* ctx); // sceIoOpenForDriver (another one ?)
  int (*func3)(void* ctx); // sceIoOpenForDriver (another one ?) or sceIoCloseForDriver
  int (*func4)(void* ctx); // add partition (add vfsNode) (initialize partition entry in table) (for example happens on card insert exclusively) (operates with numeric names)
  int (*func5)(void* ctx); // sceIoReadForDriver
  int (*func6)(void* ctx); // sceIoWriteForDriver
  int (*func7)(void* ctx); // sceIoLseekForDriver or sceIoLseek32?
  int (*func8)(void* ctx); // sceIoIoctlForDriver
  int (*func9)(void* ctx); // remove partition (remove vfsNode) (deinitialize partition entry in table) (for example happens on card remove exclusively) (operates with numeric names)
  int (*func10)(void* ctx); // sceIoMkdirForDriver
  int (*func11)(void* ctx); // sceIoRmdirForDriver
  int (*func12)(void* ctx); // sceIoDopenForDriver
  int (*func13)(void* ctx); // sceIoDcloseForDriver
  int (*func14)(void* ctx); // sceIoDreadForDriver
  int (*func15)(void* ctx); // sceIoGetstatForDriver or sceIoGetstatByFdForDriver
  int (*func16)(void* ctx); // sceIoChstatForDriver or sceIoChstatByFdForDriver
  int (*func17)(void* ctx); // sceIoRenameForDriver
  int (*func18)(void* ctx); // not implemented by all
  int (*func19)(void* ctx); // sceIoPreadForDriver
  int (*func20)(void* ctx); // sceIoPwriteForDriver
  int (*func21)(void* ctx); // ?
  int (*func22)(void* ctx); // not referenced
  int (*func23)(void* ctx); // not referenced
  int (*func24)(void* ctx); // sceIoSyncForDriver or sceIoSyncByFdForDriver
  int (*func25)(void* ctx); // sceIoGetstatByFdForDriver
  int (*func26)(void* ctx); // sceIoChstatByFdForDriver
  int (*func27)(void* ctx); // ?
  int (*func28)(void* ctx); // ?
  int (*func29)(void* ctx); // not implemented by all
} node_ops2;

typedef struct vfs_add_data
{
    node_ops1* funcs1;
    const char *name; //max size is 0x20
    int flags; //0x0E
    int unk_C; //0x01 / 0x00 (root, leaf ?)
    
    int unk_10; //0x10
    node_ops2* funcs2;
    int unk_18; //0x00
    vfs_add_data* next_element; //ptr to next element, confirmed
} vfs_add_data;

typedef struct vfs_node
{
   uint8_t data1[0x40];
   
   node_ops2 *ops;
   uint32_t unk_44;
   void* dev_info; //allocated on heap with uid from uid field
                   //this is device specific / node specific data
                   //for partition node this will be vfs_device_info*
   vfs_node* node;

   vfs_node* prev_node;
   uint32_t unk_54;
   uint32_t unk_58;
   uint32_t unk_5C;

   uint32_t unk_60;
   uint32_t unk_64;
   uint32_t unk_68;
   SceUID pool_uid;
   
   uint8_t data2[0x60];
   
   uint32_t unk_D0;

} vfs_node;

//==========================

int sub_BECE80(void* a0)
{
   return 0;
}

int sub_BEC808(char* filesystem)
{
   return 0;
}

int sub_BE5814(vfs_node* a0)
{
   return 0;
}

int SceIofilemgrForDriver_6b3ca9f7(int a0)
{
   return 0;
}

int SceIofilemgrForDriver_dc2d8bce(int a0)
{
   return 0;
}

int sub_BEC578(int a0, int a1)
{
   return 0;
}

int sub_BEC620(int a0)
{
   return 0;
}

int sub_BEC010(int a0)
{
   return 0;
}

void* sub_BECE0C()
{
   return 0;
}

int sub_BE62E8(char* mount, void* a1, uint32_t* a2, uint32_t* a3, int a4)
{
   return 0;
}

int proc_find_vfs_node_BE6788(void* unk0, int unk1, vfs_node** vnode, void* unk3, int unk4)
{
   return 0;
}

int sub_BE5F10(vfs_node* a0, void* a1, void* a2, int a3, vfs_node** a4)
{
   return 0;
}

int sub_BEE364(vfs_node* a0)
{
   return 0;
}

int sub_BEE3C8(vfs_node* n0)
{
   return 0;
}

void* proc_get_arg0_for_sceVfsGetNewNode_BEBAC0()
{
   return 0;
}

int proc_init_SceVfsMnt_BEBB84(int a0, int a1, int a2, int a3)
{
   return 0;
}

int sub_BEC56C(int a0, int a1)
{
   return 0;
}

int SceIofilemgrForDriver_sceVfsGetNewNode_d60b5c63(int a0, int a1, int a2, int a3)
{
   return 0;
}

int SceIofilemgrForDriver_21d57633(int a0)
{
   return 0;
}

int sub_BE61C4(int a0)
{
   return 0;
}

int sub_BE5A38(int a0, int a1)
{
   return 0;
}

int sub_BEE2C4()
{
   return 0;
}

int sub_BEE2D4()
{
   return 0;
}

int sub_BEDEB0(int a0, int a1, int a2, int a3)
{
   return 0;
}

int SceIofilemgrForDriver_aa45010b(int a0)
{
   return 0;
}

int sub_BE59BC(int a0, int a1)
{
   return 0;
}

int sub_BEDF5C(int a0, int a1)
{
   return 0;
}

int sub_BE5B30(int a0, int a1, int a2, int a3, int a4)
{
   return 0;
}

int sub_BEBC1C()
{
   return 0;
}
    
int sub_BEC51C(int a0)
{
   return 0;
}
    
int sub_BEBC2C()
{
   return 0;
}

int sub_BF18CC(int a0, int a1)
{
   return 0;
}

int sub_BEC530(int a0)
{
   return 0;
}

int SceIofilemgrForDriver_6048f245(int a0)
{
   return 0;
}

int vfs_node_func3_BF1AF0(int a0, int a1, int a2)
{
   return 0;
}

vfs_add_data* proc_findVfsNodeByFilesystem_BEC7C0(char* filesystem)
{
   return 0;
}

//==========================

int loc_BE6C96(char* filesystem, int errorCode, void* unk3, void* var_D8, int cookie)
{
   sub_BECE80(unk3);
    
   sub_BECE80(var_D8);
    
   if(errorCode == 0)
   {
      if(cookie == var_009EA004)
         return 0;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
   }
   else
   {
      sub_BEC808(filesystem);
   
      if(cookie == var_009EA004)
         return errorCode;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
   }
}

int loc_BE7252(vfs_node* n0, char* filesystem, int errorCode, vfs_node* unk2, void* unk3, void* var_D8, int cookie)
{
   sub_BE5814(n0);
   
   if(unk2 == 0)
      return loc_BE6C96(filesystem, errorCode, unk3, var_D8, cookie);
    
   sub_BE5814(unk2);
   
   return loc_BE6C96(filesystem, errorCode, unk3, var_D8, cookie);
}

int loc_BE76C8(vfs_node* n0, int r7, char* filesystem, int errorCode, vfs_node* unk2, void* unk3, void* var_D8, int cookie)
{
   /*
   SceIofilemgrForDriver_6b3ca9f7(n0[0x4C]); //lock print

   n0[0x4C][0x60] = n0[0x4C][0x60] - 1; //counter ?
   
   sub_BEC578(n0[0x4C], r7);
   
   SceIofilemgrForDriver_dc2d8bce(n0[0x4C]); //unlock print

   sub_BEC620(r7);
   
   sub_BEC010(r7);
   */
   
   return loc_BE7252(n0, filesystem, errorCode, unk2, unk3, var_D8, cookie);
}

//==========================

int loc_BE6AA2_default_case(char* filesystem, int cookie)
{
   sub_BEC808(filesystem);
   
   if(cookie == var_009EA004)
      return 0x80010016;
   else
      return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
}

//==========================

//loc_BE6C50 - jumptable 00BE6A86 case 1
int mount_switch_case_1(vfs_mount_point_info_base *mountInfo, vfs_add_data* addData, int cookie)
{
   uint32_t majorIndex = (0x000000FF & mountInfo->devMajor);
   if(majorIndex != 0x03)
   return loc_BE6AA2_default_case(mountInfo->filesystem, cookie);

   void* unk3 = sub_BECE0C(); //alloc memory
   
   if(unk3 == 0)
   {
      sub_BEC808(mountInfo->filesystem);
   
      if(cookie == var_009EA004)
         return 0x8001000C;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
   }

   void* var_D8 = sub_BECE0C(); //alloc memory
    
   if(var_D8 == 0)
   {
      sub_BECE80(unk3);
   
      sub_BEC808(mountInfo->filesystem);
   
      if(cookie == var_009EA004)
         return 0x8001000C;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
   }

   uint32_t* unk0;
   uint32_t unk1;
   uint32_t str1;
    
   unk0 = &str1;

   int result0 = sub_BE62E8(mountInfo->unk_4, unk3, unk0, &unk1, 0x01);

   if(result0 < 0)
      return loc_BE6C96(mountInfo->filesystem, result0, unk3, var_D8, cookie);

   if(unk1 == 0)
      return loc_BE6C96(mountInfo->filesystem, result0, unk3, var_D8, cookie);

//loc_BE71B0:

    vfs_node* unk2;
    
    void* var_D4 = unk0 + ((unk1 - 1) << 3);

    int result1 = proc_find_vfs_node_BE6788(unk0, unk1 - 1, &unk2, unk3, 0x3000);

    vfs_node* n0;

    if(result1 < 0)
    {
        if(result1 != 0x80010002)
            return loc_BE6C96(mountInfo->filesystem, result1, unk3, var_D8, cookie);

        int result2 = proc_find_vfs_node_BE6788(unk0, unk1, &n0, unk3, 0x3000);
        if(result2 < 0)
            return loc_BE6C96(mountInfo->filesystem, result2, unk3, var_D8, cookie);
            
        unk2 = 0;
    }
    else
    {   
        int result2 = sub_BE5F10(unk2, var_D4, unk3, 0x3000, &n0);
        if(result2 < 0)
        {
           if(unk2 == 0)
               return loc_BE6C96(mountInfo->filesystem, result2, unk3, var_D8, cookie);
    
           sub_BE5814(unk2);
   
           return loc_BE6C96(mountInfo->filesystem, result2, unk3, var_D8, cookie);
        }
    }

//loc_BE71F6:    
    
   if(((char)n0->node->node) == 3) //vfs_node most likely has several variations depending on leaf level. have already encountered this
      return loc_BE7252(n0, mountInfo->filesystem, 0x80010010, unk2, unk3, var_D8, cookie);
    
   if((mountInfo->devMinor & 0x1000) == 0)
   {
      //loc_BE7446:
      int result3 = sub_BEE364(n0);
      
      if(result3 < 0)
      {
         if(result3 != 0x800F090D && result3 != 0x8001000D)
            return loc_BE7252(n0, mountInfo->filesystem, result3, unk2, unk3, var_D8, cookie);
         else
            return loc_BE7252(n0, mountInfo->filesystem, 0x8001001E, unk2, unk3, var_D8, cookie);
      }

      if(((uint32_t)n0->node->prev_node << 0x13) < 0) //vfs_node most likely has several variations depending on leaf level. have already encountered this
         return loc_BE7252(n0, mountInfo->filesystem, 0x8001001E, unk2, unk3, var_D8, cookie);
   }
   else
   {
      int result3 = sub_BEE3C8(n0);
      if(result3 < 0)
         return loc_BE7252(n0, mountInfo->filesystem, result3, unk2, unk3, var_D8, cookie);
   }
    
    //loc_BE7216:
    
    uint32_t var_28;

    void* r2 = (&var_28) + ((unk1 - 1) << 3);
    
    uint32_t node = r2[-0x84];   // D0 - 84 = 4C - can be part of vfs_node ?
    uint32_t var_B8 = r2[-0x80]; // D0 - 80 = 50 - can be part of vfs_node ?

    void* var_B4 = unk3;
    
    int result4 = sub_BE62E8(mountInfo->unixMount, var_D8, unk0, &unk1, 0x01);
    if(result4 < 0)
        return loc_BE7252(n0, mountInfo->filesystem, result4, unk2, unk3, var_D8, cookie);
        
    int r3 = unk1;
    if(r3 == 0)
        return loc_BE7252(n0, mountInfo->filesystem, result4, unk2, unk3, var_D8, cookie);
        
/*
//loc_BE74F4:        
    void* r0 = proc_get_arg0_for_sceVfsGetNewNode_BEBAC0();
    
    int r7 = r0;
    if(r0 == 0)
        return loc_BE7252(n0, mountInfo->filesystem, 0x8001000C, unk2, unk3, var_D8, var_2C);
    
    int r2 = 0x99C0D8; //SceIoVfsHeap SceUID*

    //vfs_add_data* r6 = addData;
    
    int r3 = r6; //vfs_add_data* ?
    int r1 = n0;
    int r2 = *r2;
    
    proc_init_SceVfsMnt_BEBB84(n0, r1, r2, r3); //!!!!!!!!!!!!!!!!
    
    int r0 = mountInfo->blockDev1;
    
    int r2 = 0x40;
    int r1 = var_D8;
    
    r7[0x7C] = r0;
    
    int r0 = r7 + 0x80;
    strncpy(r0, r1, r2);
    
    int r1 = mountInfo->unk_14;
    int r3 = 0;
    
    R7[0xBF] = (char)r3;
    
    int r3 = 0x101
    
    R7[0xC4] = r1;
    
    int r1 = UBFX( mountInfo->devMinor, 0, 0x14); //!!!!!!!!!!!!!!
    
    int r2 = n0;
    
    //STRD.W		mountInfo->devMajor, R1, [R7,#0x4C]; //!!!!!!!!!!!!!!!!!!!!!
    
    void* r0 = r2[0x4C]; //mutex
    R7[0x48] = r3;
    
    SceIofilemgrForDriver_6b3ca9f7(r0); //lock print
    
    int r3 = n0;
    int r1 = r7;
    int r3 = r3[0x4C];
    int r2 = r3[0x60];
    int r0 = r3;
    int r2 = r2 + 1; //counter ???
    r3[0x60] = r2;
    
    sub_BEC56C(r0, r1);
    
    int r3 = n0;
    void* r0 = R3[0x4C]; //mutex
    SceIofilemgrForDriver_dc2d8bce(r0); //unlock print
    
    int r2 = n0;
    int r3 = r7[0x4C];
    int r2 = r2[0x4C];
    
    short r2 = r2[0x4E];
    
    r3 = r3 | (r2 << 16)
    
    r7[0x4C] = r3;
    
    uint32_t r11 = mountInfo->unk_1C;
    if(r11 == 0)
    {
        r11 = r6[0x14]; //vfs_add_data* ? node_ops2* ?
    }

//loc_BE7576:    
    node_ops2* r1 = r11;
    vfs_node* r0 = r7;
    int r2 = 0;
    vfs_node** r3 = &vnode;
    int r0 = SceIofilemgrForDriver_sceVfsGetNewNode_d60b5c63(r0, r1, r2, r3);
    int r9 = r0;
    if(r9 < 0)
        return loc_BE76C8(n0, r7, mountInfo->filesystem, r9, unk2, unk3, var_D8, var_2C, r4);
    
    int r3 = r7[0x50];
    int r0 = r3 << 0x0E
    if(r0 < 0)
    {
       short r2 = r7[0x4E];
       int r2 = r2 & 0xF00;
       if(r2 != 0x200)
       {
         r3 = r3 & (~0x20000);
         r7[0x50] = r3;
       }
    }
    
//loc_BE75A4:    
    int r2 = n0;
    int r3 = r2[0x4C];
    int r1 = r3[0x50];
    int r1 = r1 << 0x0E;
    
    if(r1 < 0)
    {
        short r1 = r3[0x4E];
        int r1 = r1 & 0xF00;
        if(r1 == 0x200)
        {
            int r3 = r3[0xCC];
            int r0 = r7[0x50];
            int r6 = r7[0xCC];
            int r1 = r3[0x08];
            int r3 = r3[0x0C];
            int r0 = r0 | 0x20000;
            
            r6[0x08] = r1;
            r6[0x0C] = r3;
            r7[0x50] = r0;
        }
    }
    
//loc_BE75D4:    
    int r0 = r2[0x70];
    int r1 = 0x1002;
    
    //LDRD.W		R2, R3,	[SP,#0x40] //!!!!!!!!!!!!!!
    
    r3[0x4C] = r7;
    r3[0x50] = r2;
    
    r3[0x78] = r1;
    
    if(r0 != 0)
    {
        int r0 = sub_BE61C4(r0);
        int r9 = r0;
        if(r9 < 0)
        {
            SceIofilemgrForDriver_21d57633(vnode);
            return loc_BE76C8(n0, r7, mountInfo->filesystem, r9, unk2, unk3, var_D8, var_2C);
        }
            
        int r3 = n0;
        int r1 = 1;
        int r0 = r3[0x70];
        sub_BE5A38(r0, r1);
    }
    
//loc_BE75FA:    
    sub_BEE2C4() //lock SceVfsRfsLock
    
    int r3 = n0;
    int r0 = r3[0x70];
    if(r0 != 0)
    {
        int r0 = sub_BE61C4(r0);
        int r9 = r0;
        if(r9 < 0)
        {
            sub_BEE2D4(); //unlock SceVfsRfsLock
    
            SceIofilemgrForDriver_21d57633(vnode);
            return loc_BE76C8(n0, r7, mountInfo->filesystem, r9, unk2, unk3, var_D8, var_2C);
        }
    }
    
//loc_BE760E:
    int r1 = unk1;
    int r3 = 0xD8;
    int r2 = vnode;
    int r0 = unk0;
    
    int r0 = sub_BEDEB0(r0, r1, r2, r3);
    int r9 = r0;
    
    sub_BEE2D4(); //unlock SceVfsRfsLock
    
    if(r9 < 0)
    {
        SceIofilemgrForDriver_21d57633(vnode);
        return loc_BE76C8(n0, r7, mountInfo->filesystem, r9, unk2, unk3, var_D8, var_2C);
    }
    
    vfs_node* r0 = vnode;
    SceIofilemgrForDriver_aa45010b(r0);
    
    int r0 = unk2;
    if(r0 == 0)
    {
        //loc_BE79F4:
        int r1 = var_D4;
        int r0 = vnode;
        int r0 = sub_BE59BC(r0, r1);
        int r9 = r0;
        if(r9 < 0)
        {
          sub_BEE2C4(); //lock SceVfsRfsLock
    
          sub_BEDF5C(unk0, unk1);

          sub_BEE2D4(); //unlock SceVfsRfsLock
    
          SceIofilemgrForDriver_21d57633(vnode);
          return loc_BE76C8(n0, r7, mountInfo->filesystem, r9, unk2, unk3, var_D8, var_2C);
        }
    }
    else
    {
        int r3 = 1;
        int r2 = var_D4;
        unk4 = r3;
        int r1 = vnode;
        int r0 = sub_BE5B30(r0, r1, r2, r3, unk4);
        int r9 = r0;
        if(r9 < 0)
        {
             sub_BEE2C4(); //lock SceVfsRfsLock
    
             sub_BEDF5C(unk0, unk1);

             sub_BEE2D4(); //unlock SceVfsRfsLock
    
             SceIofilemgrForDriver_21d57633(vnode);
             return loc_BE76C8(n0, r7, mountInfo->filesystem, r9, unk2, unk3, var_D8, var_2C);
        }
    }
    
//loc_BE7646:    
    sub_BEBC1C(); //lock SceVfsMntlistLock
    
    int r0 = r7;
    
    sub_BEC51C(r0);
    
    sub_BEBC2C(); //unlock SceVfsMntlistLock
    
    int r0 = r7;
    int* r1 = &node;
    
    int r0 = sub_BF18CC(r0, r1);
    int r9 = r0;
    if(r9 != 0)
    {
       sub_BEBC1C(); //lock SceVfsMntlistLock
    
       sub_BEC530(r7);
    
       sub_BEBC2C(); //unlock SceVfsMntlistLock
     
       sub_BE5A38(vnode[0x70], 0);
    
       sub_BEE2C4(); //lock SceVfsRfsLock
    
       sub_BEDF5C(unk0, unk1);

       sub_BEE2D4(); //unlock SceVfsRfsLock
    
       SceIofilemgrForDriver_21d57633(vnode);
       return loc_BE76C8(n0, r7, mountInfo->filesystem, r9, unk2, unk3, var_D8, var_2C);
    }
    
    int r1 = r0;
    vfs_node* r2 = vnode;
    vfs_node* r0 = r7;
    int r0 = vfs_node_func3_BF1AF0(r0, r1, r2);
    int r9 = r0;
    if(r9 < 0)
    {
       sub_BEBC1C(); //lock SceVfsMntlistLock
    
       sub_BEC530(r7);
    
       sub_BEBC2C(); //unlock SceVfsMntlistLock
     
       sub_BE5A38(vnode[0x70], 0);
    
       sub_BEE2C4(); //lock SceVfsRfsLock
    
       sub_BEDF5C(unk0, unk1);

       sub_BEE2D4(); //unlock SceVfsRfsLock
    
       SceIofilemgrForDriver_21d57633(vnode);
       return loc_BE76C8(n0, r7, mountInfo->filesystem, r9, unk2, unk3, var_D8, var_2C);
    }
    
    void* r0 = r7;
    SceIofilemgrForDriver_6b3ca9f7(); //print lock
    
    int r2 = r7[0x48];
    void* r0 = r7;
    int r3 = r7[0x60];
    int r2 = r2 & (~0x100);
    int r3 = r3 - 1;
    r7[0x48] = r2;
    r7[0x60] = r3;
    
    SceIofilemgrForDriver_dc2d8bce(r0); //print unlock
    
    int r3 = vnode;
    int r2 = r3[0x58];
    int r0 = r3;
    int r2 = r2 -1; //counter ?
    r3[0x58] = r2;
    
    SceIofilemgrForDriver_6048f245(r0);
   
    return loc_BE7252(n0, mountInfo->filesystem, r9, unk2, unk3, var_D8, cookie);
    */

    return -1;
}

//==========================

//loc_BE6A96 - jumptable 00BE6A86 case 2
int mount_switch_case_2(vfs_mount_point_info_base *mountInfo, int cookie)
{
    uint32_t majorIndex = (0x000000FF & mountInfo->devMajor) - 1;
    
    if(majorIndex > 0x01)
       return loc_BE6AA2_default_case(mountInfo->filesystem, cookie);

    return -1; //not implemented
}

//==========================

//loc_BE6CAA - jumptable 00BE6A86 case 3
int mount_switch_case_3(vfs_mount_point_info_base *mountInfo, vfs_add_data* addData, int cookie)
{
    int r3 = addData->unk_10;

    if(r3 != 0x10)
        return loc_BE6AA2_default_case(mountInfo->filesystem, cookie);
    
    return -1; //not implemented
}

//==========================

//loc_BE6D40 - jumptable 00BE6A86 case 4
int mount_switch_case_4(vfs_mount_point_info_base *mountInfo, int cookie)
{
    if(mountInfo->unk_4 == 0x00)
        return loc_BE6AA2_default_case(mountInfo->filesystem, cookie);

   if(cookie == var_009EA004)
      return 0;
   else
      return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
}

//==========================

//loc_BE6D4C - case 5
int mount_switch_case_5(vfs_mount_point_info_base *mountInfo, int cookie)
{
    uint32_t majorIndex = (0x000000FF & mountInfo->devMajor) - 1;

    if(majorIndex > 0x01)
        return loc_BE6AA2_default_case(mountInfo->filesystem, cookie);

    if(mountInfo->unk_4 == 0x00)
        return loc_BE6AA2_default_case(mountInfo->filesystem, cookie);
    
    return -1; //not implemented
}

//==========================

//loc_BE6AC2 - case 6
int mount_switch_case_6(vfs_mount_point_info_base *mountInfo, int cookie)
{
    uint32_t majorIndex = (0x000000FF & mountInfo->devMajor);
    if(majorIndex != 0x04)
        return loc_BE6AA2_default_case(mountInfo->filesystem, cookie);
    
    return -1; //not implemented
}

//==========================

int sceVfsMount(vfs_mount_point_info_base *mountInfo)
{
    int cookie = var_009EA004;

    if(mountInfo == 0x00) //compare input pointer to 0
    {
      if(cookie == var_009EA004)
         return 0x80010016;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
    }
    
    if(mountInfo->unixMount == 0x00) //compare unixMount pointer to 0
    {
      if(cookie == var_009EA004)
         return 0x80010016;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
    }
    
    vfs_add_data* addData = proc_findVfsNodeByFilesystem_BEC7C0(mountInfo->filesystem);
    
    if(addData == 0x00) //compare node pointer to 0
    {
      if(cookie == var_009EA004)
         return 0x80010016;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
    }
    
    int minorIndex = (0x000000FF & mountInfo->devMinor) - 1;
    
    switch(minorIndex)
    {
    case 0:
        return mount_switch_case_1(mountInfo, addData, cookie);
    case 1:
        return mount_switch_case_2(mountInfo, cookie);
    case 2:
        return mount_switch_case_3(mountInfo, addData, cookie);
    case 3:
        return mount_switch_case_4(mountInfo, cookie);
    case 4:
        return mount_switch_case_5(mountInfo, cookie);
    case 5:
        return mount_switch_case_6(mountInfo, cookie);
    default:
        return loc_BE6AA2_default_case(mountInfo->filesystem, cookie); //default case
    }
}

