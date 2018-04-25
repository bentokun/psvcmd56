#include "SceAppMgr.h"

#include "Constants.h"

#include "SceThreadmgr.h"
#include "SceSysmem.h"
#include "SceSysmemGlobalVariables.h"
#include "SceIofilemgr.h"
#include "SceSblACMgr.h"
#include "SceSblSsMgr.h"
#include "SceFios2Kernel.h"
#include "SceProcessmgr.h"
#include "ScePfsMgr.h"

#include <string>
#include <cstdint>

//==============================

int loc_23D5220()
{
   /*
   MOV             R0, R5
   BL              sub_23EFA40
   MOVS            R0, #0
   BLX             SceAppMgr.SceKernelSuspendForDriver._imp_2bb92967
   LDR             R2, [SP,#0x88+var_2C]
   MOV             R0, R4
   LDR.W           R3, [R10]
   CMP             R2, R3
   */

   //return r0 or stack fail

   return 0;
}

int loc_23D52BC()
{
   //MOVS            R4, 0x80800034
   return loc_23D5220();
}

int loc_23D518E()
{
   //  more code

   return 0;
}

int loc_23D50A0()
{
   /*
   ADD.W           R8, SP, #0x88+var_78
   ADD             R7, SP, #0x88+var_70
   ADD.W           R9, SP, #0x88+var_68
   MOVW            R1, #(aCategory_0 AND 0xFFFF) ; "CATEGORY"
   MOV             R2, R8
   MOV             R3, R7
   STR.W           R9, [SP,#0x88+arg_0]
   MOVT.W          R1, #high16(aCategory_0) ; "CATEGORY"
   MOV             R0, R5
   BL              sub_23EF8DC
   SUBS            R4, R0, #0
   */

   //if(r4 < 0)
   //{
   //   return loc_23D5220();
   //}
   //else
   //{
      /*
      LDR             R3, [SP,#0x88+var_70]
      */

      //if(r3 <= 2)
      //{
      //   return loc_23D52BC();
      //}
      //else
      //{
         /*
         LDR             R4, [SP,#0x88+var_68]
         */

         //if(r4 != 4)
         //{
         //   return loc_23D52BC();
         //}
         //else
         //{
            /*
            LDR             R3, [SP,#0x88+var_78]
            MOV             R1, dword_24047E0 ; 024047E0 data reference 00007067
            MOV             R2, R4
            MOV             R0, R3
            STR             R3, [SP,#0x88+var_7C]
            BLX             SceAppMgr.SceSysclibForDriver._imp_strncmp_12cee649
            */

            //if(r0 == 0)
            //{
               /*
               LDR.W           R2, [R6,#0x160]
               LSLS            R3, R2, #0x1F
               */

               //if(!true) //NOT BPL
               //{
                  /*
                  MOVW            R1, #(dword_24047E4 AND 0xFFFF) ; 024047E4 data reference 00006467
                  MOV             R2, R4
                  MOVT.W          R1, #high16(dword_24047E4) ; 024047E4 data reference 00006467
                  ADD.W           R0, R6, #0x298
                  BLX             SceAppMgr.SceSysclibForDriver._imp_6d286146
                  */
               //}
            //}
            //else
            //{
               /*
               MOVW            R1, #(aGpc AND 0xFFFF) ; "gpc"
               LDR             R0, [SP,#0x88+var_7C]
               MOVT.W          R1, #high16(aGpc) ; "gpc"
               MOV             R2, R4
               BLX             SceAppMgr.SceSysclibForDriver._imp_strncmp_12cee649
               */

               //if(r0 != 0)
               //{
                  /*
                  MOVW            R1, #(aGpd AND 0xFFFF)
                  LDR             R0, [SP,#0x88+var_7C]
                  MOVT.W          R1, #high16(aGpd) ; "gpd"
                  MOV             R2, R4
                  BLX             SceAppMgr.SceSysclibForDriver._imp_strncmp_12cee649
                  */

                  //if(r0 != 0)
                  //{
                     /*
                     LDR             R1, [SP,#0x88+var_7C]
                     MOV             R2, R4
                     ADD.W           R0, R6, #0x298
                     BLX             SceAppMgr.SceSysclibForDriver._imp_6d286146
                     MOVS            R3, #0
                     STRB.W          R3, [R6,#0x29B]
                     */
                  //}
                  //else
                  //{
                     /*
                     LDR.W           R3, [R6,#0x160]
                     LSLS            R0, R3, #0x1F
                     */

                     //if(!true) //NOT BPL
                     //{
                        /*
                        MOV             R3, aGdd ; "gdd"
                        LDR             R0, [R3]
                        STR.W           R0, [R6,#0x298]
                        */
                     //}
                  //}
               //}
               //else
               //{
                  /*
                  LDR.W           R3, [R6,#0x160]
                  LSLS            R4, R3, #0x1F
                  */

                  //if(true) //BMI
                  //{
                     /*
                     MOV             R3, aGdc ; "gdc"
                     LDR             R0, [R3]
                     STR.W           R0, [R6,#0x298]
                     */
                  //}
               //}
            //}

            //loc_23D5110:

            /*
            MOVW            R1, #(aTitle_id AND 0xFFFF) ; "TITLE_ID"
            STR.W           R9, [SP,#0x88+arg_0]
            MOVT.W          R1, #high16(aTitle_id) ; "TITLE_ID"
            MOV             R0, R5
            MOV             R2, R8
            MOV             R3, R7
            BL              sub_23EF8DC
            SUBS            R4, R0, #0
            */

            //if(r4 < 0)
            //{
               //return loc_23D5220();
            //}
            //else
            //{
               /*
               LDR             R3, [SP,#0x88+var_70]
               */

               //if(r3 <= 9)
               //{
                  //return  loc_23D52BC();
               //}
               //else
               //{
                  /*
                  LDR             R3, [SP,#0x88+var_68]
                  */
                  //if(r3 != 0x0C)
                  //{
                     //return loc_23D52BC();
                  //}
                  //else
                  //{
                     /*
                     ADD.W           R4, R6, #0x378
                     LDR             R1, [SP,#0x88+var_78]
                     MOVS            R2, #0xA
                     MOV             R0, R4
                     BLX             SceAppMgr.SceSysclibForDriver._imp_6d286146
                     MOVS            R3, #0
                     LDR.W           LR, [R6,#0x37C]
                     STRB.W          R3, [R6,#0x381]
                     LDR.W           R1, [R6,#0x384]
                     LDR.W           R0, [R6,#0x380]
                     LDR.W           R12, [R6,#0x378]
                     STR.W           LR, [R6,#0x38C]
                     STR.W           R0, [R6,#0x390]
                     STR.W           R1, [R6,#0x394]
                     LDR.W           LR, [R6,#0x378]
                     LDR.W           R0, [R6,#0x37C]
                     LDR.W           R1, [R6,#0x380]
                     LDR.W           R2, [R6,#0x384]
                     STR.W           R12, [R6,#0x388]
                     STR.W           LR, [R6,#0x498]
                     STR.W           R0, [R6,#0x49C]
                     STR.W           R1, [R6,#0x4A0]
                     STR.W           R2, [R6,#0x4A4]
                     */

                     //return loc_23D518E();
                  //}
               //}
            //}
         //}
      //}
   //}

   return 0;
}

int proc_parse_param_sfo_23D5028(SceUID pid, char *param_sfo_path, int ignore_overlay, phys_ctx_t *gdat_ctx)
{
   /*
   MOV             R10, 0x9EA004
   MOVS            R4, #0
   MOV             R5, R0  ; arg0
   MOVW            R0, #0x4780 ; 023D5038 : external reference: 022D4780
   LDR.W           R7, [R10]
   SUB             SP, SP, #0x64
   MOV             R8, R1  ; arg1
   MOV             R11, R2 ; arg2
   MOV             R1, R4
   MOVT.W          R0, #0x22D ; 023D5048 : external reference: 022D4780
   MOV.W           R2, #0x124
   MOV             R6, R3  ; arg3
   STR             R7, [SP,#0x88+var_2C]
   STRD.W          R4, R4, [SP,#0x30]
   STR             R4, [SP,#0x88+var_50]
   STR             R4, [SP,#0x88+var_78]
   STR             R4, [SP,#0x88+var_70]
   STR             R4, [SP,#0x88+var_68]
   BLX             SceAppMgr.SceSysclibForDriver._imp_memset_0ab9bf5c
   */

   //if(r5 == 0)
   //{
      //BLX             SceAppMgr.SceThreadmgrForDriver._imp_sceKernelGetProcessId_9dcb4b7a
      //MOV             R5, R0
   //}
   
   /*
   MOVS            R0, #0
   BLX             SceAppMgr.SceKernelSuspendForDriver._imp_4df40893
   */

   //if(r11 == 0)
   //{
      /*
      MOVS            R0, #0x80
      BLX             SceAppMgr.SceThreadmgrForDriver._imp_02eedf17
      MOV.W           R1, #0x124
      MOVW            R3, #0x4780 ; 023D524A : external reference: 022D4780
      MOV             R7, R0
      MOV             R2, R8  ; unk2
      MOV             R0, R5  ; unk0
      STR             R1, [SP,#0x88+arg_0] ; arg_0
      MOVT.W          R3, #0x22D ; 023D5256 : external reference: 022D4780
      MOV             R1, R11 ; unk1
      BLX             SceAppMgr.SceFios2KernelForDriver._imp_sceFiosKernelOverlayResolveSyncForDriver_0f456345
      MOV             R4, R0
      MOV             R0, R7
      BLX             SceAppMgr.SceThreadmgrForDriver._imp_02eedf17
      ADD             R5, SP, #0x88+var_58
      */
      //if(r4 != 0)
      //{
         //return loc_23D5220();
      //}
      //else
      //{
         /*
         MOVW            R0, #0x4780 ; 023D526E : external reference: 022D4780
         MOV             R1, R5
         MOVT.W          R0, #0x22D ; 023D5274 : external reference: 022D4780
         BL              sub_23EF934
         SUBS            R4, R0, #0
         */
         //if(r4 < 0)
         //{
            //return loc_23D5220();
         //}
         //else
         //{
            /*
            LDR.W           R3, [R6,#0x160]
            LSLS            R2, R3, #0x1F
            */
            //if(true) //BMI
            //{
               //return loc_23D50A0();
            //}
            //else
            //{
               /*
               ADD.W           R8, SP, #0x88+var_78
               ADD             R7, SP, #0x88+var_70
               ADD.W           R9, SP, #0x88+var_68
               */

               //return loc_23D518E();
            //}
         //}
      //}
   //}
   //else
   //{
      /*
      MOVW            R0, #0x4780 ; 023D5078 : external reference: 022D4780
      MOV             R1, R8
      MOV.W           R2, #0x124
      MOVT.W          R0, #0x22D ; 023D5082 : external reference: 022D4780
      BLX             SceAppMgr.SceSysclibForDriver._imp_6d286146
      ADD             R5, SP, #0x88+var_58
      MOVW            R0, #0x4780 ; 023D508C : external reference: 022D4780
      MOV             R1, R5
      MOVT.W          R0, #0x22D ; 023D5092 : external reference: 022D4780
      BL              sub_23EF934
      SUBS            R4, R0, #0
      */
      //if(r4 < 0)
      //{
         //return loc_23D5220();
      //}
      //else
      //{
         //return loc_23D50A0();
      //}
   //}

   return 0;
}

SceUID SceAppMgrMount_pool_22A0008;

SceUID SceAppMgrMount_mutex_22A000C;

char* PD_str_2404BBC = "PD";

mount_point_data_entry* mount_point_entries_22D470C;

//this function tries to OverlayResolveSync input path
//then checks that it is not a PD path (temp mount point probably aquired by PFS)
//then takes beginning of path until symbol ":"
//then tries to do a lookup by that path copy in mount_point_entries_22D470C item array
//if item is found then path from mount_point_entries_22D470C item is copied to result
//in any other case OverlayResolveSync result path is copied to result

int iofilemgr_1914_callback_23DDE64(const char *path, SceUID pid, char *result_path, int size)
{
   int result = 0;

   int cookie = var_009EA004;
  
   //clear path copy

   char path_copy[33];
   memset(path_copy,0, 0x21); 
 
   int mutex_res = SceThreadmgrForDriver_ksceKernelLockMutex_16AC80C5(SceAppMgrMount_mutex_22A000C, 1, 0);

   if (mutex_res >= 0)
   {
      //allocate buffer for overlay path

      ctx_49D4DD9B alloc_ctx;
      alloc_ctx.unk4 = 0;
      alloc_ctx.unkC = 0;
      alloc_ctx.unk10 = 0;
      alloc_ctx.unk0 = 0x14;
      alloc_ctx.unk8 = 0x20;

      char* overlay_resolve_sync_path = (char*)SceSysmemForDriver_sceKernelAllocHeapMemory3ForDriver_49D4DD9B(SceAppMgrMount_pool_22A0008, 0x124u, &alloc_ctx);
    
      if ( overlay_resolve_sync_path )
      {
         //get pid if not specified

         SceUID pid_local = pid;
         if (!pid_local)
            pid_local = SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a();

         //overlay resolve sync - input path

         int prev_perm = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(0x80); //set permission
         int overlay_res = SceFios2KernelForDriver_sceFiosKernelOverlayResolveSyncForDriver_0f456345(pid_local, 0, path, overlay_resolve_sync_path, 0x124);
         SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm); //restore permission

         if (overlay_res >= 0 )
         {
            //limit max size

            unsigned int size_local = size;
            if (size >= 0x124 )
               size_local = 0x124;

            //compare to PD string (PFS temp mount point)

            int pd_cmp_result = strncmp(overlay_resolve_sync_path,PD_str_2404BBC, 2u);
            if (pd_cmp_result)
            {
               // copy path from heap to result path

               strncpy(result_path, overlay_resolve_sync_path, size_local);
               result_path[size_local - 1] = 0;// terminate with 0

               //cleanup

               SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, overlay_resolve_sync_path);

               SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);

               if(var_009EA004 == cookie)
                  return 0;
               else
                  return STACK_CHECK_FAIL;
            }

            //clear path copy

            memset(path_copy, 0x21, 0);

            int str_index = 0;

            //copy path till ":"
            while ( 1 )
            {
               char str_symbol = overlay_resolve_sync_path[str_index];
               path_copy[str_index] = str_symbol;
               
               //check end symbol
               if ( str_symbol == ':' )
                  break;

               //check max length
               if (++str_index == 0x21 )
               {
                  // copy path from heap to result path

                  strncpy(result_path, overlay_resolve_sync_path, size_local);
                  result_path[size_local - 1] = 0;// terminate with 0

                  //cleanup

                  SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, overlay_resolve_sync_path);

                  SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);

                  if(var_009EA004 == cookie)
                     return 0;
                  else
                     return STACK_CHECK_FAIL;
               }
            }

            //terminate path with 0
            path_copy[15] = 0;

            mount_point_data_entry *global_buffer = mount_point_entries_22D470C;

            // if global item is set
            if (global_buffer)
            {
               // do path lookup while strings are not equal
               while (strncmp(global_buffer->gen_mount_point, path_copy, 0x10u) )
               {
                  global_buffer = global_buffer->next; // get pointer to next item
                  if (!global_buffer)
                  {
                     //when there is no next item

                     // copy path from heap to result path

                     strncpy(result_path, overlay_resolve_sync_path, size_local);
                     result_path[size_local - 1] = 0;// terminate with 0

                     //cleanup

                     SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, overlay_resolve_sync_path);

                     SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);

                     if(var_009EA004 == cookie)
                        return 0;
                     else
                        return STACK_CHECK_FAIL;
                  }
               }

               // copy path from global to result path

               strncpy(result_path, global_buffer->path, size_local);
               result = 0;
               result_path[size_local - 1] = 0;// terminate with 0
            }
            else
            {
               // copy path from heap to result path

               strncpy(result_path, overlay_resolve_sync_path, size_local);
               result = 0;
               result_path[size_local - 1] = 0;// terminate with 0
            }
         }
         
         SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, overlay_resolve_sync_path);
      }
      else
      {
         result = 0x80801006;
      }

      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
   }
  
   //check cookie and return result

   if(var_009EA004 == cookie)
      return result;
   else
      return STACK_CHECK_FAIL;
}

int proc_generate_random_path_23D4FBC(char *prefix, char *result_path)
{   
   int result;
   char random_buffer[8]; // [sp+18h] [bp-28h]

   result = SceSblSsMgrForDriver_sceKernelGetRandomNumberForDriver_4f9bfbe5(random_buffer, 8);
   if(result < 0)
      return result;

   _snprintf(result_path, 0x10u, "%s%02x%02x%02x%02x%02x%02xd", prefix, random_buffer[0], random_buffer[1], random_buffer[2], random_buffer[3], random_buffer[4], random_buffer[5]);
   return 0;
}

int AppMgr_decrypt_str_constant_23D59D4(char* input, char* output)
{
   if(output == 0)
      return 0x80800001;

   if(input == 0)
      return 0x80800001;

   memset(output, 0, 0x20);

   int index = 0;

   while(input[index])
   {
      output[index] = ~input[index];
      if (++index == 0x20)
         return 0x80800001;
   }
  
   output[index] = 0;
   return 0;
}

int AppMgr_decrypt_str_constant_23D5998(char *input, char *output)
{
  if(output == 0)
     return 0x80800001;

  if(input == 0)
     return 0x80800001;

  memset(output, 0, 0x40u);

  int index = 0;

  while (input[index])
  {
    output[index] = ~input[index];
    if (++index == 0x40)
      return 0x80800001;
  }
  
  output[index] = 0;
  return 0;
}

global_ctx_item *__cdecl get_global_ctx_item_23C2DE0(ctx_23C2960 *ctx, SceUID pid)
{
   return 0;
}

int verify_copy_23D5A10(char *src, char *dst)
{
   return 0;
}

//----------------

int create_mountpoint_base_23D9B50(SceUID pid, mount_ctx_holder_t *mount_ctx_holder, int mount_id, char *title_id, char *physical_path, char *mount_drive, void *klicensee, const char *gen_mount_point)
{
  char *title_id_local; // r10
  unsigned int mount_id_local; // r4
  int mount_drive_chunk1; // r1
  int mount_drive_chunk2; // r2
  int mount_drive_chunk3; // r3
  mount_ctx_t *mount_ctx_local0; // r7
  char *gen_mount_point1; // r8
  int gen_mount_point_chunk11; // r1
  int gen_mount_point_chunk12; // r2
  int gen_mount_point_chunk13; // r3
  mount_ctx_t *mount_ctx_local1; // r7
  int result2; // r8
  int result; // r0
  mount_ctx_t *mctx_alloc0; // r0
  int mount_drive_local_chunk11; // r1
  int mount_drive_local_chunk12; // r2
  int mount_drive_local_chunk13; // r3
  SceUID mount_mutex; // r0
  char *physical_path_copy; // r0
  SceFiosOverlayID overlay_id; // r4
  mount_point_data_entry *mpd_entry0; // r6
  mount_ctx_t *mount_ctx_local2; // r3
  int result1; // r0
  __int64 auth_id1; // r1
  SceUID pid0; // r5
  int prev_perm0; // r7
  mount_point_data_entry *glb_mpd_entry0; // r6
  signed int initialized_global_item_index; // r3
  __int64 auth_id2; // r1
  int pfs_mount_res; // r0
  bool check0; // r10
  mount_ctx_t *mount_ctx_local3; // r3
  int gen_mount_point_chunk21; // r1
  int gen_mount_point_chunk22; // r2
  int gen_mount_point_chunk23; // r3
  mount_point_data_entry *mpd_entry_alloc0; // r0
  mount_point_data_entry *mpd_entry_alloc1; // r6
  int title_id_chunk1; // r2
  int title_id_chunk2; // r3
  int title_id_chunk3; // lr
  char *gen_pfs_drive0; // r10
  unsigned int mount_id0; // r3
  int klicensee_chunk1; // r1
  unsigned int pfs_mount_type; // r7
  int klicensee_chunk2; // r2
  int klicensee_chunk3; // r3
  signed int initialized_allocated_item_index; // r3
  int prev_perm3; // r9
  mount_point_data_entry *mpd_entry1; // r1
  int rnd_path_gen_res0; // r0
  int rnd_path_gen_res1; // r0
  mount_ctx_t *mount_ctx_local4; // r4
  mount_point_data_entry *mpd_entry2; // r6
  int prev_perm1; // r9
  unsigned int mkdir_res0; // r0
  unsigned int mkdir_res1; // r2
  int mkdir_res2; // r3
  mount_point_data_entry *mpd_entry3; // r6
  mount_point_data_entry *glb_mpd_entry1; // r2
  int klicensee_chunk1_1; // r1
  int klicensee_chunk1_2; // r2
  int klicensee_chunk1_3; // r3
  int prev_perm2; // r6
  char *klicensee1; // r1
  __int64 auth_id3; // r1
  unsigned int pfs_mount_res0; // r0
  __int64 auth_id4; // r1
  unsigned int pfs_mount_res1; // r3
  int pfs_mount_res2; // r3
  char *gen_pfs_drive1; // r0
  unsigned int pfs_mount_res30; // r0
  __int64 auth_id5; // r1
  unsigned int pfs_mount_res31; // r3
  signed int pfs_mount_res32; // r3
  int pfs_mount_res40; // r0
  __int64 auth_id6; // r1
  bool pfs_mount_res41; // r3
  char *gen_pfs_drive2; // r0
  unsigned int pfs_mount_res50; // r0
  unsigned int pfs_mount_res51; // r3
  int klicensee_chunk10; // r1
  int klicensee_chunk20; // r2
  int klicensee_chunk30; // r3
  mount_ctx_holder_t *mount_ctx_holder_local; // [sp+14h] [bp-124h]
  mount_point_data_entry *mpd_entry_alloc2; // [sp+18h] [bp-120h]
  mount_ctx_t *mctx_alloc1; // [sp+1Ch] [bp-11Ch]
  SceUID pid_local; // [sp+20h] [bp-118h]
  char *gen_mount_point_local2; // [sp+28h] [bp-110h]
  char *physical_path_copy2; // [sp+2Ch] [bp-10Ch]
  uint64_t auth_id; // [sp+30h] [bp-108h]
  char *mountpoint; // [sp+38h] [bp-100h]
  ctx_49D4DD9B alloc_ctx0; // [sp+44h] [bp-F4h]
  char mount_drive_local[16]; // [sp+58h] [bp-E0h]
  char klicensee0[4]; // [sp+68h] [bp-D0h]
  int klicensee_chunk11; // [sp+6Ch] [bp-CCh]
  int klicensee_chunk22; // [sp+70h] [bp-C8h]
  int klicensee_chunk33; // [sp+74h] [bp-C4h]
  SceSelfAuthInfo auth_ctx; // [sp+78h] [bp-C0h]
  int cookie; // [sp+10Ch] [bp-2Ch]

  title_id_local = title_id;
  mount_id_local = mount_id;
  cookie = MEMORY[0x9EA004];
  pid_local = pid;
  mount_ctx_holder_local = mount_ctx_holder;
  *(_DWORD *)mount_drive_local = 0;
  *(_DWORD *)&mount_drive_local[4] = 0;
  *(_DWORD *)&mount_drive_local[8] = 0;
  *(_DWORD *)&mount_drive_local[12] = 0;
  if ( !gen_mount_point )
    goto LABEL_58;
  if ( mount_drive )
  {
    mount_drive_chunk1 = *((_DWORD *)mount_drive + 1);
    mount_drive_chunk2 = *((_DWORD *)mount_drive + 2);
    mount_drive_chunk3 = *((_DWORD *)mount_drive + 3);
    *(_DWORD *)mount_drive_local = *(_DWORD *)mount_drive;
    *(_DWORD *)&mount_drive_local[4] = mount_drive_chunk1;
    *(_DWORD *)&mount_drive_local[8] = mount_drive_chunk2;
    *(_DWORD *)&mount_drive_local[12] = mount_drive_chunk3;
    goto LABEL_4;
  }
  if ( (unsigned int)mount_id <= 0x192 )
  {
    if ( (unsigned int)mount_id >= 0x190 )
    {
LABEL_163:
      result1 = proc_generate_random_path_23D4FBC(ad_string_2404C3C, mount_drive_local);
      if ( result1 )
        goto LABEL_41;
      goto LABEL_164;
    }
    if ( (unsigned int)mount_id <= 0xCC )
    {
      if ( (unsigned int)mount_id < 0xCB )
      {
        if ( (unsigned int)mount_id > 0xC9 )
        {
          if ( SceSblACMgrForDriver_sceSblACMgrCheckAuthIdForDriver_0b6e6cd7(0) )
          {
            strcpy(mount_drive_local, "ms0:");
            goto LABEL_4;
          }
          rnd_path_gen_res0 = proc_generate_random_path_23D4FBC(ms_string_2404C54, mount_drive_local);
          if ( rnd_path_gen_res0 )
          {
            result2 = rnd_path_gen_res0;
            goto LABEL_13;
          }
          goto LABEL_168;
        }
        if ( (unsigned int)mount_id < 0xC8 )
        {
          if ( (unsigned int)(mount_id - 100) > 0xC )
            goto LABEL_58;
          goto LABEL_163;
        }
      }
    }
    else
    {
      if ( (unsigned int)mount_id > 0xCF )
      {
        switch ( mount_id )
        {
          case 0x12F:
            strcpy(mount_drive_local, "trophy_dat0:");
            break;
          case 0x130:
            strcpy(mount_drive_local, "trophy_dbk0:");
            break;
          case 0x12E:
            strcpy(mount_drive_local, "trophy_sys0:");
            break;
          default:
            goto LABEL_58;
        }
        goto LABEL_4;
      }
      if ( (unsigned int)mount_id < 0xCE )
      {
        strcpy(mount_drive_local, "cache0:");
        goto LABEL_4;
      }
    }
    result1 = proc_generate_random_path_23D4FBC(td_string_2404C44, mount_drive_local);
    if ( result1 )
    {
      result2 = result1;
      goto LABEL_13;
    }
LABEL_164:
    mount_drive_local[15] = result1;
    mount_drive_local[14] = 0x3A;
    goto LABEL_4;
  }
  if ( (unsigned int)mount_id > 0x3E9 )
  {
    if ( (unsigned int)mount_id <= 0x3EE )
    {
      if ( (unsigned int)mount_id > 0x3EC )
      {
        _snprintf(mount_drive_local, 0x10u, aSavedata1u, 0);
      }
      else
      {
        if ( (unsigned int)mount_id >= 0x3EC )
          goto LABEL_58;
        _snprintf(mount_drive_local, 0x10u, aAddcont1u, 0);
      }
      goto LABEL_4;
    }
    if ( (unsigned int)mount_id <= 0x3F0 )
    {
      rnd_path_gen_res1 = proc_generate_random_path_23D4FBC(sd_string_2404AAC, mount_drive_local);
      if ( rnd_path_gen_res1 )
      {
        result2 = rnd_path_gen_res1;
        goto LABEL_13;
      }
    }
    else
    {
      if ( mount_id != 0x3F1 )
        goto LABEL_58;
      result1 = proc_generate_random_path_23D4FBC(ud_string_2404C40, mount_drive_local);
      if ( result1 )
        goto LABEL_41;
    }
LABEL_168:
    mount_drive_local[15] = 0;
    mount_drive_local[14] = 0x3A;
    goto LABEL_4;
  }
  if ( (unsigned int)mount_id >= 0x3E8 )
  {
    _snprintf(mount_drive_local, 0x10u, aApp1u, 0);
    goto LABEL_4;
  }
  if ( mount_id == 0x1F8 )
  {
    strcpy(mount_drive_local, "sdimport0:");
    goto LABEL_4;
  }
  if ( (unsigned int)mount_id <= 0x1F8 )
  {
    if ( (unsigned int)(mount_id - 0x1F4) > 1 )
      goto LABEL_58;
    goto LABEL_163;
  }
  if ( mount_id != 0x1F9 )
  {
    if ( mount_id == 0x258 )
    {
      result1 = proc_generate_random_path_23D4FBC(lm_string_2404C50, mount_drive_local);
      if ( !result1 )
      {
        mount_drive_local[14] = 0x3A;
        mount_drive_local[15] = 0;
        goto LABEL_4;
      }
LABEL_41:
      result2 = result1;
      goto LABEL_13;
    }
LABEL_58:
    result2 = 0x80800001;
    goto LABEL_13;
  }
  strcpy(mount_drive_local, "sdimport_tmp0:");
LABEL_4:
  mount_ctx_local0 = mount_ctx_holder_local->mount;
  if ( mount_ctx_local0 )
  {
    if ( mount_id_local >= 0x3E8 )
    {
      while ( 1 )
      {
        if ( mount_id_local == mount_ctx_local0->mnt_entry->mount_id )
        {
          gen_mount_point1 = mount_ctx_local0->mountDrive;
          if ( !strncmp(
                  mount_ctx_local0->mountDrive,
                  mount_drive_local,
                  0x10u) )
            break;
        }
        mount_ctx_local0 = mount_ctx_local0->next;
        if ( !mount_ctx_local0 )
          goto LABEL_18;
      }
    }
    else
    {
      while ( mount_id_local != mount_ctx_local0->mnt_entry->mount_id )
      {
        mount_ctx_local0 = mount_ctx_local0->next;
        if ( !mount_ctx_local0 )
          goto LABEL_18;
      }
      gen_mount_point1 = mount_ctx_local0->mountDrive;
    }
    gen_mount_point_chunk11 = *((_DWORD *)gen_mount_point1 + 1);
    gen_mount_point_chunk12 = *((_DWORD *)gen_mount_point1 + 2);
    gen_mount_point_chunk13 = *((_DWORD *)gen_mount_point1 + 3);
    *(_DWORD *)gen_mount_point = *(_DWORD *)gen_mount_point1;
    *((_DWORD *)gen_mount_point + 1) = gen_mount_point_chunk11;
    *((_DWORD *)gen_mount_point + 2) = gen_mount_point_chunk12;
    *((_DWORD *)gen_mount_point + 3) = gen_mount_point_chunk13;
    if ( mount_drive )
    {
      mount_ctx_local1 = mount_ctx_holder_local->mount;
      if ( !mount_ctx_local1 )
      {
LABEL_12:
        result2 = 0x80800002;
        goto LABEL_13;
      }
      while ( 1 )
      {
        mpd_entry0 = mount_ctx_local1->mnt_entry;
        if ( mount_ctx_local1->mnt_entry )
        {
          if ( mount_id_local == mpd_entry0->mount_id
            && !strncmp(
                  mount_ctx_local1->mountDrive,
                  mount_drive_local,
                  0x10u) )
          {
            break;
          }
        }
        mount_ctx_local1 = mount_ctx_local1->next;
        if ( !mount_ctx_local1 )
          goto LABEL_12;
      }
    }
    else
    {
      mount_ctx_local2 = mount_ctx_holder_local->mount;
      if ( !mount_ctx_local2 )
        goto LABEL_12;
      while ( 1 )
      {
        mpd_entry0 = mount_ctx_local2->mnt_entry;
        if ( mount_ctx_local2->mnt_entry )
        {
          if ( mount_id_local == mpd_entry0->mount_id )
            break;
        }
        mount_ctx_local2 = mount_ctx_local2->next;
        if ( !mount_ctx_local2 )
          goto LABEL_12;
      }
    }
    if ( !mpd_entry0->gen_mount_point[0]
      || (result1 = SceProcessmgrForKernel_sceKernelGetSelfAuthInfoForKernel_e4c83b0d(pid_local, &auth_ctx),
          result1 >= 0)
      && ((HIDWORD(auth_id1) = auth_ctx.auth_id,
           result1 = ScePfsMgrForKernel_find_pmi_check_auth_id_d8d0fee5(
                       mpd_entry0->gen_mount_point,
                       auth_id1),
           result1 == 0x80010011)
       || result1 >= 0) )
    {
      result2 = 0x80800003;
      goto LABEL_13;
    }
    goto LABEL_41;
  }
LABEL_18:
  alloc_ctx0.unk4 = 0;
  alloc_ctx0.unkC = 0;
  alloc_ctx0.unk10 = 0;
  alloc_ctx0.unk0 = 0x14;
  alloc_ctx0.unk8 = 0x20;
  mctx_alloc0 = (mount_ctx_t *)SceSysmemForDriver_sceKernelAllocHeapMemory3ForKernel_49D4DD9B(
                                 MEMORY[0x22A0008],
                                 0x24u,
                                 &alloc_ctx0);
  mctx_alloc1 = mctx_alloc0;
  if ( !mctx_alloc0 )
  {
    result2 = 0x80801006;
    goto LABEL_13;
  }
  memset(mctx_alloc0, 0, 0x24u);
  alloc_ctx0.unk4 = 0;
  mount_drive_local_chunk11 = *(_DWORD *)&mount_drive_local[4];
  mount_drive_local_chunk12 = *(_DWORD *)&mount_drive_local[8];
  mount_drive_local_chunk13 = *(_DWORD *)&mount_drive_local[12];
  gen_mount_point_local2 = mctx_alloc1->mountDrive;
  alloc_ctx0.unkC = 0;
  alloc_ctx0.unk10 = 0;
  *(_DWORD *)mctx_alloc1->mountDrive = *(_DWORD *)mount_drive_local;
  mount_mutex = MEMORY[0x22A0008];
  alloc_ctx0.unk0 = 0x14;
  *((_DWORD *)gen_mount_point_local2 + 1) = mount_drive_local_chunk11;
  *((_DWORD *)gen_mount_point_local2 + 2) = mount_drive_local_chunk12;
  *((_DWORD *)gen_mount_point_local2 + 3) = mount_drive_local_chunk13;
  alloc_ctx0.unk8 = 0x20;
  physical_path_copy = (char *)SceSysmemForDriver_sceKernelAllocHeapMemory3ForKernel_49D4DD9B(
                                 mount_mutex,
                                 0x124u,
                                 &alloc_ctx0);
  physical_path_copy2 = physical_path_copy;
  if ( !physical_path_copy )
  {
    result2 = 0x80801006;
    goto LABEL_21;
  }
  memset(physical_path_copy, 0, 0x124u);
  result2 = verify_copy_23D5A10(physical_path, physical_path_copy2);
  if ( result2 > 0 )
  {
LABEL_21:
    overlay_id = mctx_alloc1->overlay_id;
    if ( overlay_id )
    {
      pid0 = pid_local;
      if ( !pid_local )
        pid0 = SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a();
      prev_perm0 = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(0x80);
      SceFios2KernelForDriver_sceFiosKernelOverlayRemoveForProcessForDriver_23247efb(pid0, overlay_id);
      SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm0);
    }
    if ( mctx_alloc1->mnt_entry )
      w_unmount_23D5F44(pid_local, mctx_alloc1->mnt_entry, 1);
    SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(MEMORY[0x22A0008], mctx_alloc1);
    if ( physical_path_copy2 )
      SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(MEMORY[0x22A0008], physical_path_copy2);
    goto LABEL_13;
  }
  if ( (unsigned int)strnlen(physical_path_copy2, 0x124) >= 0x124 )
  {
    result2 = 0x80800001;
    goto LABEL_21;
  }
  result2 = SceProcessmgrForKernel_sceKernelGetSelfAuthInfoForKernel_e4c83b0d(pid_local, &auth_ctx);
  if ( result2 < 0 )
  {
LABEL_111:
    check0 = result2 != 0x80800003;
    goto LABEL_112;
  }
  auth_id = auth_ctx.auth_id;
  if ( MEMORY[0x22D470C] )
  {
    glb_mpd_entry0 = (mount_point_data_entry *)MEMORY[0x22D470C];
    while ( mount_id_local != glb_mpd_entry0->mount_id
         || strncmp(glb_mpd_entry0->path, physical_path_copy2, 0x124u) )
    {
      glb_mpd_entry0 = glb_mpd_entry0->next;
      if ( !glb_mpd_entry0 )
        goto LABEL_124;
    }
    if ( glb_mpd_entry0->auth_ids[0] )
    {
      if ( glb_mpd_entry0->auth_ids[1] )
      {
        if ( glb_mpd_entry0->auth_ids[2] )
        {
          if ( glb_mpd_entry0->auth_ids[3] )
          {
            if ( glb_mpd_entry0->auth_ids[4] )
            {
              if ( glb_mpd_entry0->auth_ids[5] )
              {
                if ( glb_mpd_entry0->auth_ids[6] )
                {
                  if ( glb_mpd_entry0->auth_ids[7] )
                  {
                    if ( glb_mpd_entry0->auth_ids[8] )
                    {
                      if ( glb_mpd_entry0->auth_ids[9] )
                      {
                        if ( glb_mpd_entry0->auth_ids[10] )
                        {
                          if ( glb_mpd_entry0->auth_ids[11] )
                          {
                            if ( glb_mpd_entry0->auth_ids[12] )
                            {
                              if ( glb_mpd_entry0->auth_ids[13] )
                              {
                                if ( glb_mpd_entry0->auth_ids[14] )
                                {
                                  if ( glb_mpd_entry0->auth_ids[15] )
                                  {
                                    result2 = 0x8080001E;
                                    goto LABEL_21;
                                  }
                                  initialized_global_item_index = 15;
                                }
                                else
                                {
                                  initialized_global_item_index = 14;
                                }
                              }
                              else
                              {
                                initialized_global_item_index = 13;
                              }
                            }
                            else
                            {
                              initialized_global_item_index = 12;
                            }
                          }
                          else
                          {
                            initialized_global_item_index = 11;
                          }
                        }
                        else
                        {
                          initialized_global_item_index = 10;
                        }
                      }
                      else
                      {
                        initialized_global_item_index = 9;
                      }
                    }
                    else
                    {
                      initialized_global_item_index = 8;
                    }
                  }
                  else
                  {
                    initialized_global_item_index = 7;
                  }
                }
                else
                {
                  initialized_global_item_index = 6;
                }
              }
              else
              {
                initialized_global_item_index = 5;
              }
            }
            else
            {
              initialized_global_item_index = 4;
            }
          }
          else
          {
            initialized_global_item_index = 3;
          }
        }
        else
        {
          initialized_global_item_index = 2;
        }
      }
      else
      {
        initialized_global_item_index = 1;
      }
    }
    else
    {
      initialized_global_item_index = 0;
    }
    glb_mpd_entry0->auth_ids[initialized_global_item_index] = auth_id;
    if ( !glb_mpd_entry0->gen_mount_point[0]
      || (result2 = SceProcessmgrForKernel_sceKernelGetSelfAuthInfoForKernel_e4c83b0d(pid_local, &auth_ctx),
          result2 >= 0)
      && ((HIDWORD(auth_id2) = auth_ctx.auth_id,
           pfs_mount_res = ScePfsMgrForKernel_find_pmi_check_auth_id_d8d0fee5(
                             glb_mpd_entry0->gen_mount_point,
                             auth_id2),
           result2 = pfs_mount_res,
           pfs_mount_res == 0x80010011)
       || pfs_mount_res >= 0) )
    {
      mctx_alloc1->mnt_entry = glb_mpd_entry0;
      goto LABEL_113;
    }
    if ( auth_id == glb_mpd_entry0->auth_ids[0] )
    {
      glb_mpd_entry0->auth_ids[0] = 0LL;
    }
    else if ( auth_id == glb_mpd_entry0->auth_ids[1] )
    {
      glb_mpd_entry0->auth_ids[1] = 0LL;
    }
    else if ( auth_id == glb_mpd_entry0->auth_ids[2] )
    {
      glb_mpd_entry0->auth_ids[2] = 0LL;
    }
    else if ( auth_id == glb_mpd_entry0->auth_ids[3] )
    {
      glb_mpd_entry0->auth_ids[3] = 0LL;
    }
    else if ( auth_id == glb_mpd_entry0->auth_ids[4] )
    {
      glb_mpd_entry0->auth_ids[4] = 0LL;
    }
    else if ( auth_id == glb_mpd_entry0->auth_ids[5] )
    {
      glb_mpd_entry0->auth_ids[5] = 0LL;
    }
    else if ( auth_id == glb_mpd_entry0->auth_ids[6] )
    {
      glb_mpd_entry0->auth_ids[6] = 0LL;
    }
    else if ( auth_id == glb_mpd_entry0->auth_ids[7] )
    {
      glb_mpd_entry0->auth_ids[7] = 0LL;
    }
    else if ( auth_id == glb_mpd_entry0->auth_ids[8] )
    {
      glb_mpd_entry0->auth_ids[8] = 0LL;
    }
    else if ( auth_id == glb_mpd_entry0->auth_ids[9] )
    {
      glb_mpd_entry0->auth_ids[9] = 0LL;
    }
    else if ( auth_id == glb_mpd_entry0->auth_ids[10] )
    {
      glb_mpd_entry0->auth_ids[10] = 0LL;
    }
    else if ( auth_id == glb_mpd_entry0->auth_ids[11] )
    {
      glb_mpd_entry0->auth_ids[11] = 0LL;
    }
    else if ( auth_id == glb_mpd_entry0->auth_ids[12] )
    {
      glb_mpd_entry0->auth_ids[12] = 0LL;
    }
    else if ( auth_id == glb_mpd_entry0->auth_ids[13] )
    {
      glb_mpd_entry0->auth_ids[13] = 0LL;
    }
    else if ( auth_id == glb_mpd_entry0->auth_ids[14] )
    {
      glb_mpd_entry0->auth_ids[14] = 0LL;
    }
    else if ( auth_id == glb_mpd_entry0->auth_ids[15] )
    {
      glb_mpd_entry0->auth_ids[15] = 0LL;
    }
    goto LABEL_111;
  }
LABEL_124:
  alloc_ctx0.unk4 = 0;
  alloc_ctx0.unkC = 0;
  alloc_ctx0.unk10 = 0;
  alloc_ctx0.unk0 = 20;
  alloc_ctx0.unk8 = 32;
  mpd_entry_alloc0 = (mount_point_data_entry *)SceSysmemForDriver_sceKernelAllocHeapMemory3ForKernel_49D4DD9B(
                                                 MEMORY[0x22A0008],
                                                 0x1D0u,
                                                 &alloc_ctx0);
  mpd_entry_alloc2 = mpd_entry_alloc0;
  if ( !mpd_entry_alloc0 )
  {
    result2 = 0x80801006;
    check0 = 1;
    goto LABEL_158;
  }
  mpd_entry_alloc1 = mpd_entry_alloc0;
  memset(mpd_entry_alloc0, 0, 0x1D0u);
  mpd_entry_alloc1->mount_id = mount_id_local;
  mountpoint = mpd_entry_alloc1->path;
  strncpy(mpd_entry_alloc1->path, physical_path_copy2, 0x123u);
  title_id_chunk1 = *((_DWORD *)title_id_local + 1);
  title_id_chunk2 = *((_DWORD *)title_id_local + 2);
  title_id_chunk3 = *((_DWORD *)title_id_local + 3);
  *(_DWORD *)mpd_entry_alloc2->title_id = *(_DWORD *)title_id_local;
  *(_DWORD *)&mpd_entry_alloc2->title_id[4] = title_id_chunk1;
  *(_DWORD *)&mpd_entry_alloc2->title_id[8] = title_id_chunk2;
  *(_DWORD *)&mpd_entry_alloc2->title_id[12] = title_id_chunk3;
  if ( mount_id_local == 0x258 )
  {
    mpd_entry_alloc2->gen_mount_point[0] = 0;
    prev_perm1 = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(0x80);
    result2 = SceIofilemgrForDriver_sceIoMountForDriver_d070bc48(
                0x10000,
                physical_path_copy2,
                0,
                0,
                0,
                0);
    if ( result2 < 0
      || ((mkdir_res0 = SceIofilemgrForDriver_sceIoMkdirForDriver_7f710b25(
                          aLma0Mpe_root,
                          0x186),               // lma0:MPE_ROOT
           mkdir_res1 = mkdir_res0 >> 31,
           mkdir_res0 != 0x80010011) ? (mkdir_res2 = mkdir_res1 & 1) : (mkdir_res2 = 0),
          result2 = mkdir_res0,
          mkdir_res2) )
    {
      SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm1);
      check0 = result2 != 0x80800003;
      goto LABEL_157;
    }
    SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm1);
    goto LABEL_136;
  }
  gen_pfs_drive0 = mpd_entry_alloc2->gen_mount_point;
  result2 = proc_generate_random_path_23D4FBC(PD_str_2404BBC, mpd_entry_alloc2->gen_mount_point);// PD string
  if ( result2 < 0 )
    goto LABEL_213;
  if ( !strncmp(mountpoint, aHost0, 6u) )
    mpd_entry_alloc2->gen_mount_point[0] = 0;
  *(_DWORD *)klicensee0 = 0;
  klicensee_chunk33 = 0;
  mount_id0 = mpd_entry_alloc2->mount_id;
  klicensee_chunk11 = 0;
  klicensee_chunk22 = 0;
  if ( mount_id0 > 0x192 )
  {
    if ( mount_id0 >= 0x3EC )
    {
      if ( mount_id0 == 0x3EE )
        goto LABEL_319;
      if ( mount_id0 <= 0x3EE )
      {
        if ( mount_id0 == 0x3EC )
        {
          klicensee_chunk1 = *((_DWORD *)klicensee + 1);
          pfs_mount_type = 0xD;
          klicensee_chunk2 = *((_DWORD *)klicensee + 2);
          klicensee_chunk3 = *((_DWORD *)klicensee + 3);
          *(_DWORD *)klicensee0 = *(_DWORD *)klicensee;
          klicensee_chunk11 = klicensee_chunk1;
          klicensee_chunk22 = klicensee_chunk2;
          klicensee_chunk33 = klicensee_chunk3;
LABEL_135:
          if ( !mpd_entry_alloc2->gen_mount_point[0] )
            goto LABEL_136;
          prev_perm2 = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(0x80);
          result2 = SceProcessmgrForKernel_sceKernelGetSelfAuthInfoForKernel_e4c83b0d(pid_local, &auth_ctx);
          if ( result2 < 0 )
            goto LABEL_213;
          if ( klicensee0[0]
            || klicensee0[1]
            || klicensee0[2]
            || klicensee0[3]
            || (_BYTE)klicensee_chunk11
            || __PAIR__(BYTE1(klicensee_chunk11), 0) != BYTE2(klicensee_chunk11)
            || __PAIR__(HIBYTE(klicensee_chunk11), 0) != (unsigned __int8)klicensee_chunk22
            || __PAIR__(BYTE1(klicensee_chunk22), 0) != BYTE2(klicensee_chunk22)
            || __PAIR__(HIBYTE(klicensee_chunk22), 0) != (unsigned __int8)klicensee_chunk33
            || __PAIR__(BYTE1(klicensee_chunk33), 0) != BYTE2(klicensee_chunk33) )
          {
            klicensee1 = klicensee0;
          }
          else
          {
            klicensee1 = HIBYTE(klicensee_chunk33) ? klicensee0 : 0;
          }
          result2 = ScePfsMgrForKernel_mount_a772209c(
                      mountpoint,
                      gen_pfs_drive0,
                      auth_ctx.auth_id,
                      klicensee1,
                      pfs_mount_type);
          SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm2);
          if ( result2 )
            goto LABEL_213;
          HIDWORD(auth_id3) = 1;
          pfs_mount_res0 = ScePfsMgrForKernel_find_pmi_check_auth_id_d8d0fee5(gen_pfs_drive0, auth_id3);
          pfs_mount_res1 = pfs_mount_res0 >> 31;
          result2 = pfs_mount_res0;
          if ( pfs_mount_res0 == 0x80010011 )
            pfs_mount_res2 = 0;
          else
            pfs_mount_res2 = pfs_mount_res1 & 1;
          gen_pfs_drive1 = mpd_entry_alloc2->gen_mount_point;
          if ( pfs_mount_res2 )
            goto LABEL_310;
          HIDWORD(auth_id4) = 0x7001;
          pfs_mount_res30 = ScePfsMgrForKernel_find_pmi_check_auth_id_d8d0fee5(gen_pfs_drive0, auth_id4);
          pfs_mount_res31 = pfs_mount_res30 >> 31;
          result2 = pfs_mount_res30;
          pfs_mount_res32 = pfs_mount_res30 == 0x80010011 ? 0 : pfs_mount_res31 & 1;
          gen_pfs_drive1 = mpd_entry_alloc2->gen_mount_point;
          if ( pfs_mount_res32 )
            goto LABEL_310;
          HIDWORD(auth_id5) = 0x2D;
          pfs_mount_res40 = ScePfsMgrForKernel_find_pmi_check_auth_id_d8d0fee5(gen_pfs_drive0, auth_id5);
          result2 = pfs_mount_res40;
          if ( pfs_mount_res40 == 0x80010011 )
            pfs_mount_res41 = 0;
          else
            pfs_mount_res41 = pfs_mount_res40 < 0;
          if ( pfs_mount_res41 )
          {
LABEL_309:
            gen_pfs_drive1 = mpd_entry_alloc2->gen_mount_point;
LABEL_310:
            ScePfsMgrForKernel_unmount_680bc384(gen_pfs_drive1);
            goto LABEL_213;
          }
          if ( pfs_mount_type == 4 )
          {
            gen_pfs_drive2 = mpd_entry_alloc2->gen_mount_point;
            HIDWORD(auth_id6) = 0x10;
          }
          else
          {
            if ( pfs_mount_type != 5 )
              goto LABEL_136;
            gen_pfs_drive2 = mpd_entry_alloc2->gen_mount_point;
            HIDWORD(auth_id6) = 0x39;
          }
          pfs_mount_res50 = ScePfsMgrForKernel_find_pmi_check_auth_id_d8d0fee5(gen_pfs_drive2, auth_id6);
          result2 = pfs_mount_res50;
          if ( pfs_mount_res50 == 0x80010011 )
            pfs_mount_res51 = 0;
          else
            pfs_mount_res51 = pfs_mount_res50 >> 31;
          if ( pfs_mount_res51 )
            goto LABEL_309;
LABEL_136:
          if ( mpd_entry_alloc2->auth_ids[0] )
          {
            if ( mpd_entry_alloc2->auth_ids[1] )
            {
              if ( mpd_entry_alloc2->auth_ids[2] )
              {
                if ( mpd_entry_alloc2->auth_ids[3] )
                {
                  if ( mpd_entry_alloc2->auth_ids[4] )
                  {
                    if ( mpd_entry_alloc2->auth_ids[5] )
                    {
                      if ( mpd_entry_alloc2->auth_ids[6] )
                      {
                        if ( mpd_entry_alloc2->auth_ids[7] )
                        {
                          if ( mpd_entry_alloc2->auth_ids[8] )
                          {
                            if ( mpd_entry_alloc2->auth_ids[9] )
                            {
                              if ( mpd_entry_alloc2->auth_ids[10] )
                              {
                                if ( mpd_entry_alloc2->auth_ids[11] )
                                {
                                  if ( mpd_entry_alloc2->auth_ids[12] )
                                  {
                                    if ( mpd_entry_alloc2->auth_ids[13] )
                                    {
                                      if ( mpd_entry_alloc2->auth_ids[14] )
                                      {
                                        if ( mpd_entry_alloc2->auth_ids[15] )
                                        {
                                          result2 = 0x8080001E;
                                          check0 = 1;
LABEL_154:
                                          prev_perm3 = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(128);
                                          if ( mount_id_local == 0x258 )
                                            SceIofilemgrForDriver_sceIoUmountForDriver_20574100(
                                              0x10000,
                                              0,
                                              0,
                                              0);
                                          else
                                            ScePfsMgrForKernel_unmount_680bc384(mpd_entry_alloc2->gen_mount_point);
                                          SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm3);
                                          goto LABEL_157;
                                        }
                                        initialized_allocated_item_index = 15;
                                      }
                                      else
                                      {
                                        initialized_allocated_item_index = 14;
                                      }
                                    }
                                    else
                                    {
                                      initialized_allocated_item_index = 13;
                                    }
                                  }
                                  else
                                  {
                                    initialized_allocated_item_index = 12;
                                  }
                                }
                                else
                                {
                                  initialized_allocated_item_index = 11;
                                }
                              }
                              else
                              {
                                initialized_allocated_item_index = 10;
                              }
                            }
                            else
                            {
                              initialized_allocated_item_index = 9;
                            }
                          }
                          else
                          {
                            initialized_allocated_item_index = 8;
                          }
                        }
                        else
                        {
                          initialized_allocated_item_index = 7;
                        }
                      }
                      else
                      {
                        initialized_allocated_item_index = 6;
                      }
                    }
                    else
                    {
                      initialized_allocated_item_index = 5;
                    }
                  }
                  else
                  {
                    initialized_allocated_item_index = 4;
                  }
                }
                else
                {
                  initialized_allocated_item_index = 3;
                }
              }
              else
              {
                initialized_allocated_item_index = 2;
              }
            }
            else
            {
              initialized_allocated_item_index = 1;
            }
          }
          else
          {
            initialized_allocated_item_index = 0;
          }
          glb_mpd_entry1 = (mount_point_data_entry *)MEMORY[0x22D470C];
          mpd_entry_alloc2->auth_ids[initialized_allocated_item_index] = auth_id;
          if ( glb_mpd_entry1 )
          {
            if ( mpd_entry_alloc2 == glb_mpd_entry1 )
            {
LABEL_252:
              result2 = 0x80800003;
              check0 = 0;
              goto LABEL_154;
            }
            while ( glb_mpd_entry1->next )
            {
              if ( mpd_entry_alloc2 == glb_mpd_entry1 )
                goto LABEL_252;
              glb_mpd_entry1 = glb_mpd_entry1->next;
            }
            glb_mpd_entry1->next = mpd_entry_alloc2;
            *(_QWORD *)&mpd_entry_alloc2->prev = (unsigned int)glb_mpd_entry1;
          }
          else
          {
            MEMORY[0x22D470C] = mpd_entry_alloc2;
            mpd_entry_alloc2->prev = 0;
            mpd_entry_alloc2->next = 0;
          }
          check0 = 0;
          result2 = 0;
          goto LABEL_158;
        }
        if ( mount_id0 == 0x3ED )
          goto LABEL_313;
LABEL_262:
        result2 = 0x80800001;
        check0 = 1;
        goto LABEL_157;
      }
      if ( mount_id0 > 0x3F0 )
      {
        if ( mount_id0 != 0x3F1 )
          goto LABEL_262;
LABEL_319:
        pfs_mount_type = 0x15;
        goto LABEL_135;
      }
LABEL_267:
      pfs_mount_type = 0x14;
      goto LABEL_135;
    }
    if ( mount_id0 >= 0x3EA )
    {
      if ( strncmp(mountpoint, aGro0_0, 5u) )// gro0:
        pfs_mount_type = 4;
      else
        pfs_mount_type = 0xC;
      result2 = read_sealedkey_23D6EA0(mountpoint, klicensee0);
      goto LABEL_212;
    }
    if ( mount_id0 >= 0x1FA )
    {
      if ( mount_id0 < 0x3E8 )
        goto LABEL_262;
      if ( clearsign_exists_23D9A4C(mountpoint) )
      {
        pfs_mount_type = 2;
        klicensee_chunk1_1 = *((_DWORD *)klicensee + 1);
        klicensee_chunk1_2 = *((_DWORD *)klicensee + 2);
        klicensee_chunk1_3 = *((_DWORD *)klicensee + 3);
        *(_DWORD *)klicensee0 = *(_DWORD *)klicensee;
        klicensee_chunk11 = klicensee_chunk1_1;
        klicensee_chunk22 = klicensee_chunk1_2;
        klicensee_chunk33 = klicensee_chunk1_3;
        goto LABEL_135;
      }
      goto LABEL_267;
    }
    if ( mount_id0 < 0x1F8 )
    {
      if ( mount_id0 - 0x1F4 <= 1 )
      {
        pfs_mount_type = 4;
        result2 = read_sealedkey_23D6EA0(mountpoint, klicensee0);
        goto LABEL_212;
      }
      goto LABEL_262;
    }
LABEL_264:
    pfs_mount_type = 6;
    result2 = read_sealedkey_23D6EA0(mountpoint, klicensee0);
    goto LABEL_212;
  }
  if ( mount_id0 >= 0x190 )
  {
LABEL_324:
    pfs_mount_type = 0x16;
    goto LABEL_135;
  }
  if ( mount_id0 != 0x6E )
  {
    if ( mount_id0 > 0x6E )
    {
      if ( mount_id0 <= 0xCF )
      {
        if ( mount_id0 < 0xC8 && mount_id0 > 0x70 )
          goto LABEL_262;
        goto LABEL_319;
      }
      if ( mount_id0 - 0x12E > 2 )
        goto LABEL_262;
      goto LABEL_264;
    }
    if ( mount_id0 <= 0x6C )
    {
      if ( mount_id0 >= 0x6B )
        goto LABEL_319;
      if ( mount_id0 < 0x64 )
        goto LABEL_262;
    }
    goto LABEL_324;
  }
LABEL_313:
  if ( klicensee )
  {
    klicensee_chunk10 = *((_DWORD *)klicensee + 1);
    klicensee_chunk20 = *((_DWORD *)klicensee + 2);
    pfs_mount_type = 5;
    klicensee_chunk30 = *((_DWORD *)klicensee + 3);
    *(_DWORD *)klicensee0 = *(_DWORD *)klicensee;
    klicensee_chunk11 = klicensee_chunk10;
    klicensee_chunk22 = klicensee_chunk20;
    klicensee_chunk33 = klicensee_chunk30;
    goto LABEL_135;
  }
  pfs_mount_type = 5;
  result2 = read_sealedkey_23D6EA0(mountpoint, klicensee0);
LABEL_212:
  if ( !result2 )
    goto LABEL_135;
LABEL_213:
  check0 = result2 != 0x80800003;
LABEL_157:
  mpd_entry1 = mpd_entry_alloc2;
  mpd_entry_alloc2 = 0;
  SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(MEMORY[0x22A0008], mpd_entry1);
LABEL_158:
  mctx_alloc1->mnt_entry = mpd_entry_alloc2;
LABEL_112:
  if ( check0 )
    goto LABEL_21;
LABEL_113:
  SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(MEMORY[0x22A0008], physical_path_copy2);
  if ( mount_id_local != 0x3E9 )
  {
    if ( mount_id_local != 0x3EB )
      goto LABEL_115;
    mount_ctx_local4 = mount_ctx_holder_local->mount;
    if ( mount_ctx_local4 )
    {
      while ( 1 )
      {
        mpd_entry2 = mount_ctx_local4->mnt_entry;
        if ( mount_ctx_local4->mnt_entry )
        {
          if ( mpd_entry2->mount_id == 0x3EA
            && !strncmp(
                  mount_ctx_local4->mountDrive,
                  mount_drive_local,
                  0x10u) )
          {
            break;
          }
        }
        mount_ctx_local4 = mount_ctx_local4->next;
        if ( !mount_ctx_local4 )
          goto LABEL_225;
      }
      mctx_alloc1->unk18 = (int)mpd_entry2;
      goto LABEL_115;
    }
LABEL_225:
    result2 = 0x80800002;
    physical_path_copy2 = (char *)mount_ctx_local4;
    goto LABEL_21;
  }
  mount_ctx_local4 = mount_ctx_holder_local->mount;
  if ( !mount_ctx_local4 )
    goto LABEL_225;
  while ( 1 )
  {
    mpd_entry3 = mount_ctx_local4->mnt_entry;
    if ( mount_ctx_local4->mnt_entry )
    {
      if ( mpd_entry3->mount_id == 0x3E8
        && !strncmp(mount_ctx_local4->mountDrive, mount_drive_local, 0x10u) )
      {
        break;
      }
    }
    mount_ctx_local4 = mount_ctx_local4->next;
    if ( !mount_ctx_local4 )
      goto LABEL_225;
  }
  mctx_alloc1->unk18 = (int)mpd_entry3;
LABEL_115:
  result2 = proc_fios2kernel_overlay_add_for_process_23D4DDC(pid_local, mctx_alloc1);
  if ( result2 )
  {
    physical_path_copy2 = 0;
    goto LABEL_21;
  }
  mount_ctx_local3 = mount_ctx_holder_local->mount;
  if ( mount_ctx_local3 )
  {
    if ( mctx_alloc1 == mount_ctx_local3 )
    {
      result2 = 0x80800003;
      physical_path_copy2 = 0;
    }
    else
    {
      while ( 1 )
      {
        if ( !mount_ctx_local3->next )
        {
          mount_ctx_local3->next = mctx_alloc1;
          mctx_alloc1->unk1C = (int)mount_ctx_local3;
          mctx_alloc1->next = 0;
          goto LABEL_123;
        }
        if ( mctx_alloc1 == mount_ctx_local3 )
          break;
        mount_ctx_local3 = mount_ctx_local3->next;
      }
      result2 = 0x80800003;
      physical_path_copy2 = 0;
    }
    goto LABEL_21;
  }
  mount_ctx_holder_local->mount = mctx_alloc1;
  mctx_alloc1->unk1C = 0;
  mctx_alloc1->next = 0;
LABEL_123:
  result2 = 0;
  gen_mount_point_chunk21 = *(_DWORD *)&mctx_alloc1->mountDrive[4];
  gen_mount_point_chunk22 = *(_DWORD *)&mctx_alloc1->mountDrive[8];
  gen_mount_point_chunk23 = *(_DWORD *)&mctx_alloc1->mountDrive[12];
  *(_DWORD *)gen_mount_point = *(_DWORD *)gen_mount_point_local2;
  *((_DWORD *)gen_mount_point + 1) = gen_mount_point_chunk21;
  *((_DWORD *)gen_mount_point + 2) = gen_mount_point_chunk22;
  *((_DWORD *)gen_mount_point + 3) = gen_mount_point_chunk23;
LABEL_13:
  result = result2;

  return (cookie == var_009EA004) ? result : STACK_CHECK_FAIL;
}

//----------------

void * alloc_mem_23DDFF8(SceSize size)
{
   return 0;
}

int clearsign_exists_23D9A4C(char *mountpoint)
{
   return 0;
}

int get_klicensee_23D642C(char *rif_file_path, rif_info *rif_info_arg)
{
   return 0;
}

int sceAppMgrCheckRifGD_base_23D9704(char *path, char *titleid, void *dest_with_klicensee)
{
   return 0;
}

int check_package_bin_and_clearsign_23D6314(char *physical_path, int *unk1)
{
   return 0;
}

int get_patch_path_23D6A48(char *path, char *titleId, int some_flag, char *prefix, char *result_path)
{
   return 0;
}

int w_unmount_23D8E80(SceUID pid, mount_ctx_holder_t *mount_ctx_holder, char *gen_mount_point, int umountArg)
{
   return 0;
}

ctx_23C2960 global_contexts_22A0500[20];

int w_SceAppMgrForDriver_sceAppMgrGameDataMountForDriver_ce356b2d(char *app_path, char *patch_path, char *rif_file_path, char *mount_point, char* physical_path_copy, char* alloc_buffer, phys_ctx_t *gdat_ctx)
{
   char md_mount_drive[16];
   char md_mount_point[16];

   memset(md_mount_drive, 0, 0x10);
   memset(md_mount_point, 0, 0x10);

   int last_error;

   global_ctx_item *gctxi = get_global_ctx_item_23C2DE0(global_contexts_22A0500, SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a());

   if (!gctxi)
      return 0x80801002;

   //not sure what this lookup is supposed to do

   last_error = verify_copy_23D5A10(app_path, physical_path_copy);
   if(last_error < 0)
   {
      if (last_error != 0x80800002 )
      {
         //weird check - last_error is already < 0
         if (!last_error)
            return 0x80800017;
         else
            return last_error;
      }
   }
   else
   {
      mount_point_data_entry *mpe = mount_point_entries_22D470C;
      if (mpe)
      {
         bool mpe_found = false;

         // lookup first mpe entry that has id not 0x384 and path not equal to physical path
         while (mpe->mount_id != 0x384 || strncmp(mpe->path, physical_path_copy, 0x124u))
         {
            mpe = mpe->next;
            if (!mpe)
            {
               mpe_found = true;
               break;
            }
         }

         if(!mpe_found)
            return 0x80800017;
      }
   }

   // read and parse param sfo first time - ignore overlay

   char* param_sfo_path = alloc_buffer;
   _snprintf(param_sfo_path, 0x124u, "%s/%s", app_path, "sce_sys/param.sfo");
   
   int prev_perm = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(0x80);
   last_error = proc_parse_param_sfo_23D5028(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), param_sfo_path, 1, gdat_ctx);
   SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm);

   if (last_error < 0)
   {
      if (last_error == 0x80010002)
         last_error = 0x8080000D;

      return last_error;
   }

   // check if clearsign exists

   int prev_perm2 = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(0x80);
   int clearsign_exists = clearsign_exists_23D9A4C(app_path);
   SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm2);

   // retrieve klicensee if clearsign exists

   if (clearsign_exists)                       
   {
      if (rif_file_path)
      {
         last_error = get_klicensee_23D642C(rif_file_path, &gdat_ctx->rif);
         if (last_error < 0)
            return last_error;
      }
      else
      {
         last_error = sceAppMgrCheckRifGD_base_23D9704(app_path, gdat_ctx->titleId_378, &gdat_ctx->rif);
         if (last_error < 0)
            return last_error;
      }

      //check package - maybe drm free check? (since zeroes dec_rif_key below)

      int package_check_flag = 1;

      int prev_perm3 = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(128);
      last_error = check_package_bin_and_clearsign_23D6314(app_path, &package_check_flag);
      SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm3);
      
      if(last_error < 0)
         return last_error;

      if(package_check_flag)
      {
         memset(gdat_ctx->rif.dec_rif_key, 0, 0x10u);
      }
   }

   // generate random mount drive

   last_error = proc_generate_random_path_23D4FBC("gp", md_mount_drive);
   if (last_error < 0)
      return last_error;

   // if generation was successful

   md_mount_drive[13] = 'd';
   md_mount_drive[14] = ':';
   md_mount_drive[15] = 0;
       
   // mount physical path (probably XX0:app/ variants)

   last_error = create_mountpoint_base_23D9B50(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), 
                                               &gctxi->unk_558.mctx_hldr_28, 
                                               0x3E8, 
                                               gdat_ctx->titleId_378, 
                                               app_path, 
                                               md_mount_drive, 
                                               gdat_ctx->rif.dec_rif_key, 
                                               md_mount_point);

   if(last_error < 0)
      return last_error;

   // read and parse param sfo second time - do not ignore overlay

   last_error = proc_parse_param_sfo_23D5028(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), param_sfo_path, 0, gdat_ctx);
   if(last_error < 0)
   {
      w_unmount_23D8E80(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), &gctxi->unk_558.mctx_hldr_28, md_mount_point, 0);
      return last_error;
   }

   // finally copy temp mount point to result

   memcpy(mount_point, md_mount_point, 0x10);

   //try to mount patch directory

   char* patch_path_copy = alloc_buffer;

   //if path is provided or not

   if(patch_path)
   {
      strncpy(patch_path_copy, patch_path, 0x124u);
      patch_path_copy[291] = 0;

      // simple check that dir exists

      SceIoStat stat;
      int prev_perm4 = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(128);
      int stat_res0 = SceIofilemgrForDriver_sceIoGetstatForDriver_75c96d25(patch_path_copy, &stat);
      SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm4);
      
      //try to mount if directory exists

      if(stat_res0 >= 0)
      {
         last_error = create_mountpoint_base_23D9B50(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), 
                                                     &gctxi->unk_558.mctx_hldr_28, 
                                                     0x3E9, 
                                                     gdat_ctx->titleId_378, 
                                                     patch_path_copy, 
                                                     md_mount_drive, 
                                                     gdat_ctx->rif.dec_rif_key, 
                                                     md_mount_point);

         if(last_error < 0)
         {
            //unmount previous app_path if patch directory mount has failed - this is an error

            w_unmount_23D8E80(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), &gctxi->unk_558.mctx_hldr_28, md_mount_point, 0);
            return last_error;
         }
         else
         {
            //copy new temp mount point - this is success

            memcpy(mount_point, md_mount_point, 0x10);
            return last_error;
         }
      }
      else
      {
         //not sure what is this check for invalid - maybe you can set an argument as invalid?

         int cmp_res = strncmp(patch_path_copy, "invalid:", 9u);
         if (cmp_res)
         {
            //unmount previous app_path if patch directory was invalid

            w_unmount_23D8E80(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), &gctxi->unk_558.mctx_hldr_28, md_mount_point, 0);
            return 0x8080000F;
         }
         else
         {
            //do not unmount previous mount of app_path if patch directory did not exist - this is still a success

            return 0;
         }
      }
   }
   else
   {
      //if path is not provided - try to constuct it

      int get_patch_res = get_patch_path_23D6A48(app_path, gdat_ctx->titleid_388, gdat_ctx->flag_29C, gdat_ctx->prefix_298, patch_path_copy);
      if (get_patch_res >= 0)
      {
         // simple check that dir exists

         SceIoStat stat;
         int prev_perm5 = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(128);
         int stat_res1 = SceIofilemgrForDriver_sceIoGetstatForDriver_75c96d25(patch_path_copy, &stat);
         SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm5);
         
         if (stat_res1 >= 0)
         {
            last_error = create_mountpoint_base_23D9B50(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), 
                                                        &gctxi->unk_558.mctx_hldr_28, 
                                                        0x3E9, 
                                                        gdat_ctx->titleId_378, 
                                                        patch_path_copy, 
                                                        md_mount_drive, 
                                                        gdat_ctx->rif.dec_rif_key, 
                                                        md_mount_point);
            if (last_error < 0)
            {
               //unmount previous app_path if patch directory mount has failed - this is an error

               w_unmount_23D8E80(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), &gctxi->unk_558.mctx_hldr_28, md_mount_point, 0);
               return last_error;
            }
            else
            {
               //copy new temp mount point - this is success

               memcpy(mount_point, md_mount_point, 0x10);
               return last_error;
            }
         }
         else
         {
            //do not unmount previous mount of app_path if patch directory did not exist - this is still a success

            return 0;
         }
      }
      else
      {
         //do not unmount previous mount of app_path if unable to construct path to patch directory - this is still a success

         return 0;
      }
   }
}

//a user probably have to setup an overlay with fios2 prior to calling this function
//if he wants to use a patch_path argument

int SceAppMgrForDriver_sceAppMgrGameDataMountForDriver_ce356b2d(char *app_path, char *patch_path, char *rif_file_path, char *mount_point)
{ 
   int cookie = var_009EA004;

   //check args

   if (mount_point == 0 || app_path == 0)
      return var_009EA004 == cookie ? 0x80800001 : STACK_CHECK_FAIL;

   //lock mutex

   int lock_res = SceThreadmgrForDriver_ksceKernelLockMutex_16AC80C5(SceAppMgrMount_mutex_22A000C, 1, 0);
   if (lock_res < 0)
      return var_009EA004 == cookie ? lock_res : STACK_CHECK_FAIL;

   //allocate buffer

   ctx_49D4DD9B alloc_ctx0;
   alloc_ctx0.unk0 = 0x14;
   alloc_ctx0.unk4 = 0;
   alloc_ctx0.unkC = 0;
   alloc_ctx0.unk10 = 0;
   alloc_ctx0.unk8 = 0x20;

   char* physical_path_copy = (char*)SceSysmemForDriver_sceKernelAllocHeapMemory3ForDriver_49D4DD9B(SceAppMgrMount_pool_22A0008, 0x124u, &alloc_ctx0);
   if (!physical_path_copy)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return var_009EA004 == cookie ? 0x80801006 : STACK_CHECK_FAIL;
   }

   //allocate buffer

   ctx_49D4DD9B alloc_ctx1;
   alloc_ctx1.unk0 = 20;
   alloc_ctx1.unk4 = 0;
   alloc_ctx1.unk8 = 32;
   alloc_ctx1.unkC = 0;
   alloc_ctx1.unk10 = 0;
   
   char* alloc_buffer = (char *)SceSysmemForDriver_sceKernelAllocHeapMemory3ForDriver_49D4DD9B(SceAppMgrMount_pool_22A0008, 0x124u, &alloc_ctx1);
   if (!alloc_buffer)
   {
      SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, physical_path_copy);

      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return var_009EA004 == cookie ? 0x80801006 : STACK_CHECK_FAIL;
   }

   //allocate object

   phys_ctx_t *gdat_ctx = (phys_ctx_t *)alloc_mem_23DDFF8(0x508u);
   if(!gdat_ctx)
   {
      SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, physical_path_copy);
      SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, alloc_buffer);

      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return var_009EA004 == cookie ? 0x80801006 : STACK_CHECK_FAIL;
   }

   memset(gdat_ctx, 0, 0x508u);

   int result = w_SceAppMgrForDriver_sceAppMgrGameDataMountForDriver_ce356b2d(app_path, patch_path, rif_file_path, mount_point, physical_path_copy, alloc_buffer, gdat_ctx);

   SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, physical_path_copy);
   SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, alloc_buffer);
   SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, gdat_ctx);

   SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
   return var_009EA004 == cookie ? result : STACK_CHECK_FAIL;
}

