#include <string>

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

typedef struct vfs_mount_point_info_base
{
  char* unixMount;
  char* unk_4; //zero
  uint32_t devMajor;
  uint32_t devMinor;

  char* filesystem;
  uint32_t unk_14; //zero
  vfs_block_dev_info* blockDev1;
  node_ops2* unk_1C; //zero
} vfs_mount_point_info_base;

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
   
   uint32_t unk_D0; //is this field present ? most likely it is not (need to find some D0 constants)

} vfs_node;

typedef struct vfs_nb_cc
{
   uint32_t unk_0;
   uint32_t unk_4;
   uint32_t unk_8;
   uint32_t unk_C;
} vfs_nb_cc;

typedef struct vfs_node_base
{
   //TODO: THIS STRUCTURE CONTAINS ONLY MAJOR FIELDS WITHOUT GAPS

   uint32_t unk_48; //some number like 0x101
   
   union _devMajor
   {
      struct _dmDword
      {
         uint32_t unk_4C;
      } dw;
      struct _dmWord
      {
         uint16_t unk_4C;
         uint16_t unk_4E;
      } w;
      struct _dmByte
      {
         uint8_t unk_4C;
         uint8_t unk_4D;
         uint8_t unk_4E;
         uint8_t unk_4F;
      } b;
   } devMajor;

   uint32_t devMinor; //50

   uint32_t unk_60; //counter

   vfs_node_base* unk_70; //next ?
   vfs_node_base* unk_74; //prev ?

   vfs_block_dev_info* blockDev; //7C

   char unk_80[0x40];

   uint32_t unk_C4; //mountInfo->unk_14

   vfs_nb_cc* unk_CC;

} vfs_node_base;

typedef struct vfs_r_70
{
   uint32_t unk_0;
   uint32_t unk_4;
   uint32_t unk_8;
   vfs_r_70* unk_C; //zero or pointer to next element

   void* unk_10; //pointer to struct of at least size 0x94
   uint32_t unk_14; //number
};

typedef struct vfs_root
{
   vfs_node_base* node; //4C 
   vfs_root* unk_50;

   vfs_r_70* unk_70;

   uint32_t unk_78;

   uint32_t unk_58; //counter

}vfs_root;

//==========================

int sub_BECE80(void* a0)
{
   return 0;
}

int sub_BEC808(char* filesystem)
{
   return 0;
}

int sub_BE5814(vfs_root* a0)
{
   return 0;
}

int SceIofilemgrForDriver_6b3ca9f7(vfs_node_base* a0)
{
   return 0;
}

int SceIofilemgrForDriver_dc2d8bce(vfs_node_base* a0)
{
   return 0;
}

int sub_BEC578(vfs_node_base* a0, vfs_node_base* a1)
{
   return 0;
}

int sub_BEC620(vfs_node_base* a0)
{
   return 0;
}

int sub_BEC010(vfs_node_base* a0)
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

int proc_find_vfs_node_BE6788(void* unk0, int unk1, vfs_root** vnode, void* unk3, int unk4)
{
   return 0;
}

int sub_BE5F10(vfs_root* a0, void* a1, void* a2, int a3, vfs_root** a4)
{
   return 0;
}

int sub_BEE364(vfs_root* a0)
{
   return 0;
}

int sub_BEE3C8(vfs_root* n0)
{
   return 0;
}

vfs_node_base* proc_get_arg0_for_sceVfsGetNewNode_BEBAC0()
{
   return 0;
}

int proc_init_SceVfsMnt_BEBB84(void* a0, vfs_root* a1, SceUID a2, vfs_add_data* a3)
{
   return 0;
}

//links 2 nodes
void sub_BEC56C(vfs_node_base* r0, vfs_node_base* r1)
{
   vfs_node_base* temp = r0->unk_70;
   if(temp != 0)
      r1->unk_74 = temp;
   r0->unk_70 = r1;
}

int SceIofilemgrForDriver_sceVfsGetNewNode_d60b5c63(vfs_node_base* cur_node, node_ops2 *ops, int unused, vfs_root **node)
{
   return 0;
}

int SceIofilemgrForDriver_21d57633(vfs_root* a0)
{
   return 0;
}

//searches some tree
int sub_BE61C4(vfs_r_70* a0)
{
   return 0;
}

int sub_BE5A38(vfs_r_70* a0, int a1)
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

int sub_BEDEB0(uint32_t* a0, int a1, vfs_root* a2, int a3)
{
   return 0;
}

int SceIofilemgrForDriver_aa45010b(vfs_root* a0)
{
   return 0;
}

int sub_BE59BC(vfs_root* a0, void* a1)
{
   return 0;
}

int sub_BEDF5C(uint32_t* a0, int a1)
{
   return 0;
}

int sub_BE5B30(vfs_root* a0, vfs_root* a1, void* a2, int a3, int a4)
{
   return 0;
}

int sub_BEBC1C()
{
   return 0;
}
    
int sub_BEC51C(vfs_node_base* a0)
{
   return 0;
}
    
int sub_BEBC2C()
{
   return 0;
}

int sub_BF18CC(vfs_node_base* a0, uint32_t* a1)
{
   return 0;
}

int sub_BEC530(vfs_node_base* a0)
{
   return 0;
}

int SceIofilemgrForDriver_6048f245(vfs_root* a0)
{
   return 0;
}

int vfs_node_func3_BF1AF0(vfs_node_base *cur_node, int unk1, vfs_root *node)
{
   return 0;
}

vfs_add_data* proc_findVfsNodeByFilesystem_BEC7C0(char* filesystem)
{
   return 0;
}

//==========================

SceUID get_SceIoVfsHeap_id()
{
   //dereference 0x99C0D8
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

int loc_BE7252(vfs_root* n0, char* filesystem, int errorCode, vfs_root* unk2, void* unk3, void* var_D8, int cookie)
{
   sub_BE5814(n0);
   
   if(unk2 == 0)
      return loc_BE6C96(filesystem, errorCode, unk3, var_D8, cookie);
    
   sub_BE5814(unk2);
   
   return loc_BE6C96(filesystem, errorCode, unk3, var_D8, cookie);
}

int loc_BE76C8(vfs_root* n0, vfs_node_base* r7, char* filesystem, int errorCode, vfs_root* unk2, void* unk3, void* var_D8, int cookie)
{
   SceIofilemgrForDriver_6b3ca9f7(n0->node); //4C mutex lock print

   n0->node->unk_60--; //counter
   
   sub_BEC578(n0->node, r7);
   
   SceIofilemgrForDriver_dc2d8bce(n0->node); //4C mutex  unlock print

   sub_BEC620(r7);
   
   sub_BEC010(r7);
   
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

//TODO:
//1 - looks like vfs_node is merged with some other type? or it has multi purpose fields ?
//2 - use counters, field copy routines to identify types that are similar
//3 - fix function signatures in ida after clarification
//4 - fix locals, especially 'node' which is located on stack - arrange fields properly

//----------

//explanation to type derivation 1
//it looks like vfs_node variables are messed up and there is actually one more type here that is involved
//by looking through the code it can be derived that bnode->node, bnode->prev_node, bnode->dev_info fields should be numbers
//bnode->node = (vfs_node*)mountInfo->devMajor; //0x4C 
//bnode->prev_node = (vfs_node*)(mountInfo->devMinor & 0xFFFFF); //0x50 - take first 0x14 bits
//bnode->dev_info = (void*)0x101; //0x48   
//bnode->dev_info = (uint32_t)bnode->dev_info & (~0x100); //0x48
//bnode->prev_node = (uint32_t)bnode->prev_node & (~0x20000); //50
//bnode->prev_node = bnode->prev_node | 0x20000; //50

//bnode and n0->node share many traits:
//n0->node->unk_60++;
//n0->node->unk_60--;
//bnode->unk_60--;

//bnode->unk_CC[0x08] = n0->node->unk_CC[0x08];
//bnode->unk_CC[0x0C] = n0->node->unk_CC[0x0C];

//if(((short)bnode[0x4E] & 0xF00) != 0x200)
//bnode->unk_4C.w.unk_4C = bnode->unk_4C.w.unk_4C | (n0->node->unk_4C.w.unk_4E << 16);

//if((bnode->unk_50 << 0x0E) < 0)
//if((((uint32_t)n0->node->prev_node) << 0x0E) < 0) //4C 50

//also procedure BEC56C is used to link two items of same type together

//this means that bnode and n0->node are of same type which is different from vfs_node

//----------

//explanation to type derivation 2
//based on BEC56C code we can derive that there should be fields unk_70 and unk_74 in vfs_node_base which are also of type vfs_node_base
//based on calls sub_BE5A38(n0->unk_70, 1); and sub_BE5A38(vnode->unk_70, 0);
//we can derive that n0->unk_70 has same type as vnode->unk_70 and most likely n0 is same type as vnode

//we can derive that unk2 and n0 are of same type vfs_root
//int result1 = proc_find_vfs_node_BE6788(unk0, unk1 - 1, &unk2, unk3, 0x3000);
//int result2 = proc_find_vfs_node_BE6788(unk0, unk1, &n0, unk3, 0x3000);

//there is also one important assignment:
//vnode->unk_4C = bnode; 
//vnode->unk_50 = unk2;

//so here what we have:
//n0 == unk2 = vfs_root*
//n0 == vnode = vfs_root*
//however we see that vnode->unk_50 must also be of type vfs_root* because of the assignment
//it would be logically correct if vnode->unk_4C was also vfs_root* because these fields are near
//however bnode is of type vfs_node_base*
//we know that it should not be of type vfs_node* because it has different layout
//howeer it can not be of type vfs_root* also because in vfs_root* field unk_4C is pointer, not number

//some important observations that should be made:
//one of the types definitely must be vfs_ode that contains ops2
//int result11 = vfs_node_func3_BF1AF0(bnode, 0, vnode);

//can this be useful?
//int result10 = sub_BF18CC(bnode, &node);

//can this be useful?
//int result9 = sub_BE59BC(vnode, var_D4);

//other important observation is to investigate function proc_init_SceVfsMnt_BEBB84

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

    vfs_root* unk2;
    
    void* var_D4 = unk0 + ((unk1 - 1) << 3);

    int result1 = proc_find_vfs_node_BE6788(unk0, unk1 - 1, &unk2, unk3, 0x3000);

    vfs_root* n0;

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
    
   if(n0->node->devMajor.b.unk_4C == 3) //vfs_node most likely has several variations depending on leaf level. have already encountered this
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

      if((n0->node->devMinor << 0x13) < 0) //vfs_node most likely has several variations depending on leaf level. have already encountered this
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
    
   uint32_t node; // = r2[-0x84];   // D0 - 84 = 4C - can be part of vfs_node ?
   uint32_t var_B8; // = r2[-0x80]; // D0 - 80 = 50 - can be part of vfs_node ?


   void* var_B4 = unk3;
    
   int result4 = sub_BE62E8(mountInfo->unixMount, var_D8, unk0, &unk1, 0x01);
   if(result4 < 0)
      return loc_BE7252(n0, mountInfo->filesystem, result4, unk2, unk3, var_D8, cookie);
        
   int r3 = unk1;
   if(r3 == 0)
      return loc_BE7252(n0, mountInfo->filesystem, result4, unk2, unk3, var_D8, cookie);
        
//loc_BE74F4:        
   vfs_node_base* bnode = proc_get_arg0_for_sceVfsGetNewNode_BEBAC0();
   if(bnode == 0)
      return loc_BE7252(n0, mountInfo->filesystem, 0x8001000C, unk2, unk3, var_D8, cookie);    

   proc_init_SceVfsMnt_BEBB84(bnode, n0, get_SceIoVfsHeap_id(), addData); // important initialization function
  
   bnode->blockDev = mountInfo->blockDev1;
    
   strncpy(bnode->unk_80, (char*)var_D8, 0x40); //it should be string since it is terminated with 0 explicitly

   bnode->unk_80[0x3F] = (char)0; //terminate with 0

   bnode->unk_C4 = mountInfo->unk_14;

   bnode->devMajor.dw.unk_4C = mountInfo->devMajor; //0x4C 
   bnode->devMinor = (mountInfo->devMinor & 0xFFFFF); //0x50 - take first 0x14 bits

   bnode->unk_48 = 0x101; //0x48    
    
   SceIofilemgrForDriver_6b3ca9f7(n0->node); //0x4C mutex lock print
   
   n0->node->unk_60++; //counter
    
   sub_BEC56C(n0->node, bnode);
    
   SceIofilemgrForDriver_dc2d8bce(n0->node); //0x4C mutex unlock print
    
   bnode->devMajor.w.unk_4C = bnode->devMajor.w.unk_4C | (n0->node->devMajor.w.unk_4E << 16);
    
   vfs_add_data* r6 = addData;

   node_ops2* ops2 = mountInfo->unk_1C == 0 ? addData->funcs2 : mountInfo->unk_1C;

   vfs_root* vnode;

//loc_BE7576:    
   int result5 = SceIofilemgrForDriver_sceVfsGetNewNode_d60b5c63(bnode, ops2, 0, &vnode);
   if(result5 < 0)
      return loc_BE76C8(n0, bnode, mountInfo->filesystem, result5, unk2, unk3, var_D8, cookie);
    
   if((bnode->devMinor << 0x0E) < 0) //50
   {
      if((bnode->devMajor.w.unk_4E & 0xF00) != 0x200)
      {
         bnode->devMinor = bnode->devMinor & (~0x20000); //50
      }
   }
    
//loc_BE75A4:    
    
   if((n0->node->devMinor << 0x0E) < 0) //4C 50
   {
      if((n0->node->devMajor.w.unk_4E & 0xF00) == 0x200)
      {
         //this code proves that 'bnode' and 'node' have same type

         bnode->unk_CC->unk_8 = n0->node->unk_CC->unk_8;
         bnode->unk_CC->unk_C = n0->node->unk_CC->unk_C;
         bnode->devMinor = bnode->devMinor | 0x20000; //50
      }
   }
    
//loc_BE75D4:   
    
   //important assignment of nodes
   vnode->node = bnode; //4C
   vnode->unk_50 = unk2; //50
    
   vnode->unk_78 = 0x1002;
 
   if(n0->unk_70 != 0)
   {
      int result6 = sub_BE61C4(n0->unk_70);
      if(result6 < 0)
      {
         SceIofilemgrForDriver_21d57633(vnode);
         return loc_BE76C8(n0, bnode, mountInfo->filesystem, result6, unk2, unk3, var_D8, cookie);
      }
            
      sub_BE5A38(n0->unk_70, 1);
   }
 
//loc_BE75FA:    

   sub_BEE2C4(); //lock SceVfsRfsLock
    
   if(n0->unk_70 != 0)
   {
      int result7 = sub_BE61C4(n0->unk_70);
      if(result7 < 0)
      {
         sub_BEE2D4(); //unlock SceVfsRfsLock
    
         SceIofilemgrForDriver_21d57633(vnode);
         return loc_BE76C8(n0, bnode, mountInfo->filesystem, result7, unk2, unk3, var_D8, cookie);
      }
   }
   
//loc_BE760E:

   int result8 = sub_BEDEB0(unk0, unk1, vnode, 0xD8);
    
   sub_BEE2D4(); //unlock SceVfsRfsLock
    
   if(result8 < 0)
   {
      SceIofilemgrForDriver_21d57633(vnode);
      return loc_BE76C8(n0, bnode, mountInfo->filesystem, result8, unk2, unk3, var_D8, cookie);
   }

   SceIofilemgrForDriver_aa45010b(vnode);
     
   if(unk2 == 0)
   {
      //loc_BE79F4:
      
      int result9 = sub_BE59BC(vnode, var_D4);
      if(result9 < 0)
      {
         sub_BEE2C4(); //lock SceVfsRfsLock
    
         sub_BEDF5C(unk0, unk1);

         sub_BEE2D4(); //unlock SceVfsRfsLock
    
         SceIofilemgrForDriver_21d57633(vnode);
         return loc_BE76C8(n0, bnode, mountInfo->filesystem, result9, unk2, unk3, var_D8, cookie);
      }
   }
   else
   {
      int result9 = sub_BE5B30(unk2, vnode, var_D4, 1, 1); //calls  SceIofilemgr.SceIofilemgrForDriver._exp_vfs_func13_f7dac0f5 inside - COULD BE USEFUL TO DERIVE op1 field location
      if(result9 < 0)
      {
         sub_BEE2C4(); //lock SceVfsRfsLock
    
         sub_BEDF5C(unk0, unk1);

         sub_BEE2D4(); //unlock SceVfsRfsLock
    
         SceIofilemgrForDriver_21d57633(vnode);
         return loc_BE76C8(n0, bnode, mountInfo->filesystem, result9, unk2, unk3, var_D8, cookie);
      }
   }
    
//loc_BE7646:    

    sub_BEBC1C(); //lock SceVfsMntlistLock
    
    sub_BEC51C(bnode);
    
    sub_BEBC2C(); //unlock SceVfsMntlistLock
       
    int result10 = sub_BF18CC(bnode, &node);
    if(result10 != 0)
    {
       sub_BEBC1C(); //lock SceVfsMntlistLock
    
       sub_BEC530(bnode);
    
       sub_BEBC2C(); //unlock SceVfsMntlistLock
     
       sub_BE5A38(vnode->unk_70, 0);
    
       sub_BEE2C4(); //lock SceVfsRfsLock
    
       sub_BEDF5C(unk0, unk1);

       sub_BEE2D4(); //unlock SceVfsRfsLock
    
       SceIofilemgrForDriver_21d57633(vnode);
       return loc_BE76C8(n0, bnode, mountInfo->filesystem, result10, unk2, unk3, var_D8, cookie);
    }
    
    int result11 = vfs_node_func3_BF1AF0(bnode, 0, vnode);
    if(result11 < 0)
    {
       sub_BEBC1C(); //lock SceVfsMntlistLock
    
       sub_BEC530(bnode);
    
       sub_BEBC2C(); //unlock SceVfsMntlistLock
     
       sub_BE5A38(vnode->unk_70, 0);
    
       sub_BEE2C4(); //lock SceVfsRfsLock
    
       sub_BEDF5C(unk0, unk1);

       sub_BEE2D4(); //unlock SceVfsRfsLock
    
       SceIofilemgrForDriver_21d57633(vnode);
       return loc_BE76C8(n0, bnode, mountInfo->filesystem, result11, unk2, unk3, var_D8, cookie);
    }
    
    SceIofilemgrForDriver_6b3ca9f7(bnode); //print lock
    
    bnode->unk_48 = bnode->unk_48 & (~0x100); //0x48
    bnode->unk_60--; //counter - one of fields that can identify type by logic
    
    SceIofilemgrForDriver_dc2d8bce(bnode); //print unlock
    
    vnode->unk_58 = vnode->unk_58 -1; //counter - one of fields that can identify type by logic
    
    SceIofilemgrForDriver_6048f245(vnode);
   
    return loc_BE7252(n0, mountInfo->filesystem, result11, unk2, unk3, var_D8, cookie);
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

