#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.0.10011.16384
//
//
// Buffer Definitions: 
//
// cbuffer SharedInputData
// {
//
//   int2 Dimensions;                   // Offset:    0 Size:     8
//
// }
//
// cbuffer YUVInputData
// {
//
//   int3 Strides;                      // Offset:    0 Size:    12
//   int Padding1;                      // Offset:   12 Size:     4 [unused]
//   float3 CoeffY;                     // Offset:   16 Size:    12
//   int Padding2;                      // Offset:   28 Size:     4 [unused]
//   float3 CoeffU;                     // Offset:   32 Size:    12
//   int Padding3;                      // Offset:   44 Size:     4 [unused]
//   float3 CoeffV;                     // Offset:   48 Size:    12
//
// }
//
// Resource bind info for WorkBuffer
// {
//
//   struct WorkBufferData
//   {
//       
//       float3 Color;                  // Offset:    0
//       float Padding;                 // Offset:   12
//
//   } $Element;                        // Offset:    0 Size:    16
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim      HLSL Bind  Count
// ------------------------------ ---------- ------- ----------- -------------- ------
// WorkBuffer                        texture  struct         r/o             t0      1 
// ChannelY                              UAV    uint         buf             u0      1 
// ChannelU                              UAV    uint         buf             u1      1 
// ChannelV                              UAV    uint         buf             u2      1 
// SharedInputData                   cbuffer      NA          NA            cb0      1 
// YUVInputData                      cbuffer      NA          NA            cb1      1 
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Input
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Output
cs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[1], immediateIndexed
dcl_constantbuffer CB1[4], immediateIndexed
dcl_resource_structured t0, 16
dcl_uav_typed_buffer (uint,uint,uint,uint) u0
dcl_uav_typed_buffer (uint,uint,uint,uint) u1
dcl_uav_typed_buffer (uint,uint,uint,uint) u2
dcl_input vThreadID.xy
dcl_temps 4
dcl_thread_group 8, 8, 1
imad r0.x, vThreadID.y, cb0[0].x, vThreadID.x
ld_structured_indexable(structured_buffer, stride=16)(mixed,mixed,mixed,mixed) r0.xyz, r0.x, l(0), t0.xyzx
iadd r0.w, -vThreadID.y, cb0[0].y
iadd r0.w, r0.w, l(-1)
mul r1.xyz, r0.xyzx, cb1[1].xyzx
dp3 r1.x, r1.xyzx, l(255.000000, 255.000000, 255.000000, 0.000000)
iadd r1.y, -r0.w, cb0[0].y
iadd r1.y, r1.y, l(-1)
imad r1.y, r1.y, cb1[0].x, vThreadID.x
round_ne r1.x, r1.x
ftou r1.x, r1.x
store_uav_typed u0.xyzw, r1.yyyy, r1.xxxx
and r1.xy, vThreadID.xyxx, l(1, 1, 0, 0)
ieq r1.xy, r1.xyxx, l(0, 0, 0, 0)
and r1.x, r1.y, r1.x
if_nz r1.x
  iadd r1.xyzw, vThreadID.xxyy, l(1, 1, 0, 1)
  ult r1.xw, r1.xxxw, cb0[0].xxxy
  imad r1.y, r1.z, cb0[0].x, r1.y
  ld_structured_indexable(structured_buffer, stride=16)(mixed,mixed,mixed,mixed) r2.xyz, r1.y, l(0), t0.xyzx
  movc r2.xyz, r1.xxxx, r2.xyzx, r0.xyzx
  iadd r3.xyzw, vThreadID.xyxy, l(0, 1, 1, 1)
  imad r1.yz, r3.yywy, cb0[0].xxxx, r3.xxzx
  ld_structured_indexable(structured_buffer, stride=16)(mixed,mixed,mixed,mixed) r3.xyz, r1.y, l(0), t0.xyzx
  movc r3.xyz, r1.wwww, r3.xyzx, r0.xyzx
  and r1.x, r1.w, r1.x
  ld_structured_indexable(structured_buffer, stride=16)(mixed,mixed,mixed,mixed) r1.yzw, r1.z, l(0), t0.xxyz
  movc r1.xyz, r1.xxxx, r1.yzwy, r0.xyzx
  add r0.xyz, r0.xyzx, r2.xyzx
  add r0.xyz, r3.xyzx, r0.xyzx
  add r0.xyz, r1.xyzx, r0.xyzx
  ushr r1.x, vThreadID.x, l(1)
  ishr r0.w, r0.w, l(1)
  ishr r1.y, cb0[0].y, l(1)
  iadd r0.w, -r0.w, r1.y
  iadd r0.w, r0.w, l(-1)
  mul r0.xyz, r0.xyzx, l(63.750000, 63.750000, 63.750000, 0.000000)
  mad r1.y, r0.x, cb1[2].x, l(128.000000)
  mad r1.y, r0.y, cb1[2].y, r1.y
  mad r1.y, r0.z, cb1[2].z, r1.y
  mad r0.x, r0.x, cb1[3].x, l(128.000000)
  mad r0.x, r0.y, cb1[3].y, r0.x
  mad r0.x, r0.z, cb1[3].z, r0.x
  imad r0.yz, r0.wwww, cb1[0].yyzy, r1.xxxx
  round_ne r0.w, r1.y
  ftou r0.w, r0.w
  store_uav_typed u1.xyzw, r0.yyyy, r0.wwww
  round_ne r0.x, r0.x
  ftou r0.x, r0.x
  store_uav_typed u2.xyzw, r0.zzzz, r0.xxxx
endif 
ret 
// Approximately 52 instruction slots used
#endif

const BYTE CSBlob_YUV420[] =
{
     68,  88,  66,  67,   3,  12, 
     18, 224, 148, 233, 216, 121, 
     61,  33,  33,  37,  92, 184, 
    140, 186,   1,   0,   0,   0, 
    184,  12,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
      4,   5,   0,   0,  20,   5, 
      0,   0,  36,   5,   0,   0, 
     28,  12,   0,   0,  82,  68, 
     69,  70, 200,   4,   0,   0, 
      3,   0,   0,   0,  64,   1, 
      0,   0,   6,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
     83,  67,   0,   1,   0,   0, 
    148,   4,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    252,   0,   0,   0,   5,   0, 
      0,   0,   6,   0,   0,   0, 
      1,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   7,   1,   0,   0, 
      4,   0,   0,   0,   4,   0, 
      0,   0,   1,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,  16,   1, 
      0,   0,   4,   0,   0,   0, 
      4,   0,   0,   0,   1,   0, 
      0,   0, 255, 255, 255, 255, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     25,   1,   0,   0,   4,   0, 
      0,   0,   4,   0,   0,   0, 
      1,   0,   0,   0, 255, 255, 
    255, 255,   2,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  34,   1,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,  50,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     87, 111, 114, 107,  66, 117, 
    102, 102, 101, 114,   0,  67, 
    104,  97, 110, 110, 101, 108, 
     89,   0,  67, 104,  97, 110, 
    110, 101, 108,  85,   0,  67, 
    104,  97, 110, 110, 101, 108, 
     86,   0,  83, 104,  97, 114, 
    101, 100,  73, 110, 112, 117, 
    116,  68,  97, 116,  97,   0, 
     89,  85,  86,  73, 110, 112, 
    117, 116,  68,  97, 116,  97, 
      0, 171,  34,   1,   0,   0, 
      1,   0,   0,   0, 136,   1, 
      0,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  50,   1,   0,   0, 
      7,   0,   0,   0, 228,   1, 
      0,   0,  64,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 252,   0,   0,   0, 
      1,   0,   0,   0, 184,   3, 
      0,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0, 176,   1,   0,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,   2,   0,   0,   0, 
    192,   1,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     68, 105, 109, 101, 110, 115, 
    105, 111, 110, 115,   0, 105, 
    110, 116,  50,   0,   1,   0, 
      2,   0,   1,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    187,   1,   0,   0, 252,   2, 
      0,   0,   0,   0,   0,   0, 
     12,   0,   0,   0,   2,   0, 
      0,   0,  12,   3,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  48,   3,   0,   0, 
     12,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
     64,   3,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    100,   3,   0,   0,  16,   0, 
      0,   0,  12,   0,   0,   0, 
      2,   0,   0,   0, 116,   3, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 152,   3, 
      0,   0,  28,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,  64,   3,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 161,   3,   0,   0, 
     32,   0,   0,   0,  12,   0, 
      0,   0,   2,   0,   0,   0, 
    116,   3,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    168,   3,   0,   0,  44,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,  64,   3, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 177,   3, 
      0,   0,  48,   0,   0,   0, 
     12,   0,   0,   0,   2,   0, 
      0,   0, 116,   3,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  83, 116, 114, 105, 
    100, 101, 115,   0, 105, 110, 
    116,  51,   0, 171, 171, 171, 
      1,   0,   2,   0,   1,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   4,   3,   0,   0, 
     80,  97, 100, 100, 105, 110, 
    103,  49,   0, 105, 110, 116, 
      0, 171, 171, 171,   0,   0, 
      2,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     57,   3,   0,   0,  67, 111, 
    101, 102, 102,  89,   0, 102, 
    108, 111,  97, 116,  51,   0, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 107,   3, 
      0,   0,  80,  97, 100, 100, 
    105, 110, 103,  50,   0,  67, 
    111, 101, 102, 102,  85,   0, 
     80,  97, 100, 100, 105, 110, 
    103,  51,   0,  67, 111, 101, 
    102, 102,  86,   0, 224,   3, 
      0,   0,   0,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 112,   4,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  36,  69, 108, 101, 
    109, 101, 110, 116,   0,  87, 
    111, 114, 107,  66, 117, 102, 
    102, 101, 114,  68,  97, 116, 
     97,   0,  67, 111, 108, 111, 
    114,   0, 171, 171,   1,   0, 
      3,   0,   1,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    107,   3,   0,   0,  80,  97, 
    100, 100, 105, 110, 103,   0, 
    102, 108, 111,  97, 116,   0, 
    171, 171,   0,   0,   3,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  44,   4, 
      0,   0, 248,   3,   0,   0, 
      0,   4,   0,   0,   0,   0, 
      0,   0,  36,   4,   0,   0, 
     52,   4,   0,   0,  12,   0, 
      0,   0,   5,   0,   0,   0, 
      1,   0,   4,   0,   0,   0, 
      2,   0,  88,   4,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 233,   3, 
      0,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  49,  48,  46,  48,  46, 
     49,  48,  48,  49,  49,  46, 
     49,  54,  51,  56,  52,   0, 
     73,  83,  71,  78,   8,   0, 
      0,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,  79,  83, 
     71,  78,   8,   0,   0,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,  83,  72,  69,  88, 
    240,   6,   0,   0,  80,   0, 
      5,   0, 188,   1,   0,   0, 
    106,   8,   0,   1,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  89,   0,   0,   4, 
     70, 142,  32,   0,   1,   0, 
      0,   0,   4,   0,   0,   0, 
    162,   0,   0,   4,   0, 112, 
     16,   0,   0,   0,   0,   0, 
     16,   0,   0,   0, 156,   8, 
      0,   4,   0, 224,  17,   0, 
      0,   0,   0,   0,  68,  68, 
      0,   0, 156,   8,   0,   4, 
      0, 224,  17,   0,   1,   0, 
      0,   0,  68,  68,   0,   0, 
    156,   8,   0,   4,   0, 224, 
     17,   0,   2,   0,   0,   0, 
     68,  68,   0,   0,  95,   0, 
      0,   2,  50,   0,   2,   0, 
    104,   0,   0,   2,   4,   0, 
      0,   0, 155,   0,   0,   4, 
      8,   0,   0,   0,   8,   0, 
      0,   0,   1,   0,   0,   0, 
     35,   0,   0,   8,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,   2,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  10,   0, 
      2,   0, 167,   0,   0, 139, 
      2, 131,   0, 128, 131, 153, 
     25,   0, 114,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  70, 114,  16,   0, 
      0,   0,   0,   0,  30,   0, 
      0,   8, 130,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
      2, 128,  65,   0,   0,   0, 
     26, 128,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     30,   0,   0,   7, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
    255, 255, 255, 255,  56,   0, 
      0,   8, 114,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     70, 130,  32,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     16,   0,   0,  10,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 127,  67,   0,   0, 
    127,  67,   0,   0, 127,  67, 
      0,   0,   0,   0,  30,   0, 
      0,   9,  34,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,  26, 128, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  30,   0, 
      0,   7,  34,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0, 255, 255, 
    255, 255,  35,   0,   0,   9, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  10, 128, 
     32,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  10,   0, 
      2,   0,  64,   0,   0,   5, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  28,   0, 
      0,   5,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
    164,   0,   0,   7, 242, 224, 
     17,   0,   0,   0,   0,   0, 
     86,   5,  16,   0,   1,   0, 
      0,   0,   6,   0,  16,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   9,  50,   0,  16,   0, 
      1,   0,   0,   0,  70,   0, 
      2,   0,   2,  64,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  32,   0, 
      0,  10,  50,   0,  16,   0, 
      1,   0,   0,   0,  70,   0, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   7, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     31,   0,   4,   3,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     30,   0,   0,   9, 242,   0, 
     16,   0,   1,   0,   0,   0, 
      6,   5,   2,   0,   2,  64, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     79,   0,   0,   8, 146,   0, 
     16,   0,   1,   0,   0,   0, 
      6,  12,  16,   0,   1,   0, 
      0,   0,   6, 132,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  35,   0,   0,  10, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
    167,   0,   0, 139,   2, 131, 
      0, 128, 131, 153,  25,   0, 
    114,   0,  16,   0,   2,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     70, 114,  16,   0,   0,   0, 
      0,   0,  55,   0,   0,   9, 
    114,   0,  16,   0,   2,   0, 
      0,   0,   6,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  30,   0,   0,   9, 
    242,   0,  16,   0,   3,   0, 
      0,   0,  70,   4,   2,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  35,   0,   0,  10, 
     98,   0,  16,   0,   1,   0, 
      0,   0,  86,   7,  16,   0, 
      3,   0,   0,   0,   6, 128, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   6,   2, 
     16,   0,   3,   0,   0,   0, 
    167,   0,   0, 139,   2, 131, 
      0, 128, 131, 153,  25,   0, 
    114,   0,  16,   0,   3,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     70, 114,  16,   0,   0,   0, 
      0,   0,  55,   0,   0,   9, 
    114,   0,  16,   0,   3,   0, 
      0,   0, 246,  15,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,   1,   0,   0,   7, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
    167,   0,   0, 139,   2, 131, 
      0, 128, 131, 153,  25,   0, 
    226,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 121,  16,   0,   0,   0, 
      0,   0,  55,   0,   0,   9, 
    114,   0,  16,   0,   1,   0, 
      0,   0,   6,   0,  16,   0, 
      1,   0,   0,   0, 150,   7, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,   7, 
    114,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
      0,   0,   0,   7, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   3,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   7, 114,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  85,   0,   0,   6, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,   2,   0, 
      1,  64,   0,   0,   1,   0, 
      0,   0,  42,   0,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   1,   0,   0,   0, 
     42,   0,   0,   8,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     26, 128,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   1,   0, 
      0,   0,  30,   0,   0,   8, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  30,   0, 
      0,   7, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0, 255, 255, 
    255, 255,  56,   0,   0,  10, 
    114,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 127,  66, 
      0,   0, 127,  66,   0,   0, 
    127,  66,   0,   0,   0,   0, 
     50,   0,   0,  10,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  10, 128,  32,   0, 
      1,   0,   0,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,  67,  50,   0, 
      0,  10,  34,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     26, 128,  32,   0,   1,   0, 
      0,   0,   2,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,  42, 128, 
     32,   0,   1,   0,   0,   0, 
      2,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     50,   0,   0,  10,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  10, 128,  32,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,  67,  50,   0, 
      0,  10,  18,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     26, 128,  32,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  50,   0,   0,  10, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,  42, 128, 
     32,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     35,   0,   0,  10,  98,   0, 
     16,   0,   0,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,  86, 134,  32,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   6,   0,  16,   0, 
      1,   0,   0,   0,  64,   0, 
      0,   5, 130,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     28,   0,   0,   5, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0, 164,   0,   0,   7, 
    242, 224,  17,   0,   1,   0, 
      0,   0,  86,   5,  16,   0, 
      0,   0,   0,   0, 246,  15, 
     16,   0,   0,   0,   0,   0, 
     64,   0,   0,   5,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  28,   0,   0,   5, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0, 164,   0, 
      0,   7, 242, 224,  17,   0, 
      2,   0,   0,   0, 166,  10, 
     16,   0,   0,   0,   0,   0, 
      6,   0,  16,   0,   0,   0, 
      0,   0,  21,   0,   0,   1, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 148,   0,   0,   0, 
     52,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  15,   0, 
      0,   0,  16,   0,   0,   0, 
      5,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      6,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0
};
