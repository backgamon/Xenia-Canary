#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.1
//
//
// Buffer Definitions: 
//
// cbuffer xe_system_cbuffer
// {
//
//   uint xe_flags;                     // Offset:    0 Size:     4 [unused]
//   float2 xe_tessellation_factor_range;// Offset:    4 Size:     8 [unused]
//   uint xe_line_loop_closing_index;   // Offset:   12 Size:     4 [unused]
//   uint xe_vertex_index_endian;       // Offset:   16 Size:     4
//   uint xe_vertex_index_offset;       // Offset:   20 Size:     4
//   uint2 xe_vertex_index_min_max;     // Offset:   24 Size:     8
//   float4 xe_user_clip_planes[6];     // Offset:   32 Size:    96 [unused]
//   float3 xe_ndc_scale;               // Offset:  128 Size:    12 [unused]
//   float xe_point_vertex_diameter_min;// Offset:  140 Size:     4 [unused]
//   float3 xe_ndc_offset;              // Offset:  144 Size:    12 [unused]
//   float xe_point_vertex_diameter_max;// Offset:  156 Size:     4 [unused]
//   float2 xe_point_constant_diameter; // Offset:  160 Size:     8 [unused]
//   float2 xe_point_screen_diameter_to_ndc_radius;// Offset:  168 Size:     8 [unused]
//   uint4 xe_texture_swizzled_signs[2];// Offset:  176 Size:    32 [unused]
//   uint xe_textures_resolved;         // Offset:  208 Size:     4 [unused]
//   uint2 xe_sample_count_log2;        // Offset:  212 Size:     8 [unused]
//   float xe_alpha_test_reference;     // Offset:  220 Size:     4 [unused]
//   uint xe_alpha_to_mask;             // Offset:  224 Size:     4 [unused]
//   uint xe_edram_32bpp_tile_pitch_dwords_scaled;// Offset:  228 Size:     4 [unused]
//   uint xe_edram_depth_base_dwords_scaled;// Offset:  232 Size:     4 [unused]
//   float4 xe_color_exp_bias;          // Offset:  240 Size:    16 [unused]
//   float2 xe_edram_poly_offset_front; // Offset:  256 Size:     8 [unused]
//   float2 xe_edram_poly_offset_back;  // Offset:  264 Size:     8 [unused]
//   uint4 xe_edram_stencil[2];         // Offset:  272 Size:    32 [unused]
//   uint4 xe_edram_rt_base_dwords_scaled;// Offset:  304 Size:    16 [unused]
//   uint4 xe_edram_rt_format_flags;    // Offset:  320 Size:    16 [unused]
//   float4 xe_edram_rt_clamp[4];       // Offset:  336 Size:    64 [unused]
//   uint4 xe_edram_rt_keep_mask[2];    // Offset:  400 Size:    32 [unused]
//   uint4 xe_edram_rt_blend_factors_ops;// Offset:  432 Size:    16 [unused]
//   float4 xe_edram_blend_constant;    // Offset:  448 Size:    16 [unused]
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim      ID      HLSL Bind  Count
// ------------------------------ ---------- ------- ----------- ------- -------------- ------
// xe_system_cbuffer                 cbuffer      NA          NA     CB0            cb0      1 
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_VertexID              0   x           0   VERTID    uint   x   
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// XEVERTEXID               0   x           0     NONE   float   x   
//
vs_5_1
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[0:0][2], immediateIndexed, space=0
dcl_input_sgv v0.x, vertex_id
dcl_output o0.x
dcl_temps 1
ieq r0.xyz, CB0[0][1].xxxx, l(1, 2, 3, 0)
or r0.xy, r0.yzyy, r0.xyxx
if_nz r0.x
  ishl r0.x, v0.x, l(8)
  ushr r0.z, v0.x, l(8)
  and r0.xz, r0.xxzx, l(0xff00ff00, 0, 0x00ff00ff, 0)
  iadd r0.x, r0.z, r0.x
else 
  mov r0.x, v0.x
endif 
if_nz r0.y
  ushr r0.y, r0.x, l(16)
  bfi r0.x, l(16), l(16), r0.x, r0.y
endif 
iadd r0.x, r0.x, CB0[0][1].y
and r0.x, r0.x, l(0x00ffffff)
umax r0.x, r0.x, CB0[0][1].z
umin r0.x, r0.x, CB0[0][1].w
utof o0.x, r0.x
ret 
// Approximately 20 instruction slots used
#endif

const BYTE tessellation_indexed_vs[] =
{
     68,  88,  66,  67,  15, 204, 
    253,  55, 194, 237,  44, 241, 
    152, 177,  62,  72, 200, 136, 
     71,  87,   1,   0,   0,   0, 
    168,  13,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    104,  10,   0,   0, 156,  10, 
      0,   0, 208,  10,   0,   0, 
     12,  13,   0,   0,  82,  68, 
     69,  70,  44,  10,   0,   0, 
      1,   0,   0,   0, 120,   0, 
      0,   0,   1,   0,   0,   0, 
     60,   0,   0,   0,   1,   5, 
    254, 255,   0, 133,   0,   0, 
      2,  10,   0,   0,  19,  19, 
     68,  37,  60,   0,   0,   0, 
     24,   0,   0,   0,  40,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    100,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 120, 101, 
     95, 115, 121, 115, 116, 101, 
    109,  95,  99,  98, 117, 102, 
    102, 101, 114,   0, 171, 171, 
    100,   0,   0,   0,  30,   0, 
      0,   0, 144,   0,   0,   0, 
    208,   1,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     64,   5,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,  80,   5, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 116,   5, 
      0,   0,   4,   0,   0,   0, 
      8,   0,   0,   0,   0,   0, 
      0,   0, 152,   5,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 188,   5,   0,   0, 
     12,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
     80,   5,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    215,   5,   0,   0,  16,   0, 
      0,   0,   4,   0,   0,   0, 
      2,   0,   0,   0,  80,   5, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 238,   5, 
      0,   0,  20,   0,   0,   0, 
      4,   0,   0,   0,   2,   0, 
      0,   0,  80,   5,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,   5,   6,   0,   0, 
     24,   0,   0,   0,   8,   0, 
      0,   0,   2,   0,   0,   0, 
     36,   6,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     72,   6,   0,   0,  32,   0, 
      0,   0,  96,   0,   0,   0, 
      0,   0,   0,   0, 100,   6, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 136,   6, 
      0,   0, 128,   0,   0,   0, 
     12,   0,   0,   0,   0,   0, 
      0,   0, 156,   6,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 192,   6,   0,   0, 
    140,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
    228,   6,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
      8,   7,   0,   0, 144,   0, 
      0,   0,  12,   0,   0,   0, 
      0,   0,   0,   0, 156,   6, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  22,   7, 
      0,   0, 156,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0, 228,   6,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  51,   7,   0,   0, 
    160,   0,   0,   0,   8,   0, 
      0,   0,   0,   0,   0,   0, 
    152,   5,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     78,   7,   0,   0, 168,   0, 
      0,   0,   8,   0,   0,   0, 
      0,   0,   0,   0, 152,   5, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 117,   7, 
      0,   0, 176,   0,   0,   0, 
     32,   0,   0,   0,   0,   0, 
      0,   0, 152,   7,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 188,   7,   0,   0, 
    208,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
     80,   5,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    209,   7,   0,   0, 212,   0, 
      0,   0,   8,   0,   0,   0, 
      0,   0,   0,   0,  36,   6, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 230,   7, 
      0,   0, 220,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0, 228,   6,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 254,   7,   0,   0, 
    224,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
     80,   5,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     15,   8,   0,   0, 228,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,  80,   5, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  55,   8, 
      0,   0, 232,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,  80,   5,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  89,   8,   0,   0, 
    240,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
    108,   8,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    144,   8,   0,   0,   0,   1, 
      0,   0,   8,   0,   0,   0, 
      0,   0,   0,   0, 152,   5, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 171,   8, 
      0,   0,   8,   1,   0,   0, 
      8,   0,   0,   0,   0,   0, 
      0,   0, 152,   5,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 197,   8,   0,   0, 
     16,   1,   0,   0,  32,   0, 
      0,   0,   0,   0,   0,   0, 
    216,   8,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    252,   8,   0,   0,  48,   1, 
      0,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,  28,   9, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  64,   9, 
      0,   0,  64,   1,   0,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0,  28,   9,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  89,   9,   0,   0, 
     80,   1,   0,   0,  64,   0, 
      0,   0,   0,   0,   0,   0, 
    108,   9,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    144,   9,   0,   0, 144,   1, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0, 168,   9, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 204,   9, 
      0,   0, 176,   1,   0,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0,  28,   9,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 234,   9,   0,   0, 
    192,   1,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
    108,   8,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    120, 101,  95, 102, 108,  97, 
    103, 115,   0, 100, 119, 111, 
    114, 100,   0, 171,   0,   0, 
     19,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     73,   5,   0,   0, 120, 101, 
     95, 116, 101, 115, 115, 101, 
    108, 108,  97, 116, 105, 111, 
    110,  95, 102,  97,  99, 116, 
    111, 114,  95, 114,  97, 110, 
    103, 101,   0, 102, 108, 111, 
     97, 116,  50,   0,   1,   0, 
      3,   0,   1,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    145,   5,   0,   0, 120, 101, 
     95, 108, 105, 110, 101,  95, 
    108, 111, 111, 112,  95,  99, 
    108, 111, 115, 105, 110, 103, 
     95, 105, 110, 100, 101, 120, 
      0, 120, 101,  95, 118, 101, 
    114, 116, 101, 120,  95, 105, 
    110, 100, 101, 120,  95, 101, 
    110, 100, 105,  97, 110,   0, 
    120, 101,  95, 118, 101, 114, 
    116, 101, 120,  95, 105, 110, 
    100, 101, 120,  95, 111, 102, 
    102, 115, 101, 116,   0, 120, 
    101,  95, 118, 101, 114, 116, 
    101, 120,  95, 105, 110, 100, 
    101, 120,  95, 109, 105, 110, 
     95, 109,  97, 120,   0, 117, 
    105, 110, 116,  50,   0, 171, 
      1,   0,  19,   0,   1,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  29,   6,   0,   0, 
    120, 101,  95, 117, 115, 101, 
    114,  95,  99, 108, 105, 112, 
     95, 112, 108,  97, 110, 101, 
    115,   0, 102, 108, 111,  97, 
    116,  52,   0, 171,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      6,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     92,   6,   0,   0, 120, 101, 
     95, 110, 100,  99,  95, 115, 
     99,  97, 108, 101,   0, 102, 
    108, 111,  97, 116,  51,   0, 
      1,   0,   3,   0,   1,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 149,   6,   0,   0, 
    120, 101,  95, 112, 111, 105, 
    110, 116,  95, 118, 101, 114, 
    116, 101, 120,  95, 100, 105, 
     97, 109, 101, 116, 101, 114, 
     95, 109, 105, 110,   0, 102, 
    108, 111,  97, 116,   0, 171, 
      0,   0,   3,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 221,   6,   0,   0, 
    120, 101,  95, 110, 100,  99, 
     95, 111, 102, 102, 115, 101, 
    116,   0, 120, 101,  95, 112, 
    111, 105, 110, 116,  95, 118, 
    101, 114, 116, 101, 120,  95, 
    100, 105,  97, 109, 101, 116, 
    101, 114,  95, 109,  97, 120, 
      0, 120, 101,  95, 112, 111, 
    105, 110, 116,  95,  99, 111, 
    110, 115, 116,  97, 110, 116, 
     95, 100, 105,  97, 109, 101, 
    116, 101, 114,   0, 120, 101, 
     95, 112, 111, 105, 110, 116, 
     95, 115,  99, 114, 101, 101, 
    110,  95, 100, 105,  97, 109, 
    101, 116, 101, 114,  95, 116, 
    111,  95, 110, 100,  99,  95, 
    114,  97, 100, 105, 117, 115, 
      0, 120, 101,  95, 116, 101, 
    120, 116, 117, 114, 101,  95, 
    115, 119, 105, 122, 122, 108, 
    101, 100,  95, 115, 105, 103, 
    110, 115,   0, 117, 105, 110, 
    116,  52,   0, 171, 171, 171, 
      1,   0,  19,   0,   1,   0, 
      4,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 143,   7,   0,   0, 
    120, 101,  95, 116, 101, 120, 
    116, 117, 114, 101, 115,  95, 
    114, 101, 115, 111, 108, 118, 
    101, 100,   0, 120, 101,  95, 
    115,  97, 109, 112, 108, 101, 
     95,  99, 111, 117, 110, 116, 
     95, 108, 111, 103,  50,   0, 
    120, 101,  95,  97, 108, 112, 
    104,  97,  95, 116, 101, 115, 
    116,  95, 114, 101, 102, 101, 
    114, 101, 110,  99, 101,   0, 
    120, 101,  95,  97, 108, 112, 
    104,  97,  95, 116, 111,  95, 
    109,  97, 115, 107,   0, 120, 
    101,  95, 101, 100, 114,  97, 
    109,  95,  51,  50,  98, 112, 
    112,  95, 116, 105, 108, 101, 
     95, 112, 105, 116,  99, 104, 
     95, 100, 119, 111, 114, 100, 
    115,  95, 115,  99,  97, 108, 
    101, 100,   0, 120, 101,  95, 
    101, 100, 114,  97, 109,  95, 
    100, 101, 112, 116, 104,  95, 
     98,  97, 115, 101,  95, 100, 
    119, 111, 114, 100, 115,  95, 
    115,  99,  97, 108, 101, 100, 
      0, 120, 101,  95,  99, 111, 
    108, 111, 114,  95, 101, 120, 
    112,  95,  98, 105,  97, 115, 
      0, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  92,   6, 
      0,   0, 120, 101,  95, 101, 
    100, 114,  97, 109,  95, 112, 
    111, 108, 121,  95, 111, 102, 
    102, 115, 101, 116,  95, 102, 
    114, 111, 110, 116,   0, 120, 
    101,  95, 101, 100, 114,  97, 
    109,  95, 112, 111, 108, 121, 
     95, 111, 102, 102, 115, 101, 
    116,  95,  98,  97,  99, 107, 
      0, 120, 101,  95, 101, 100, 
    114,  97, 109,  95, 115, 116, 
    101, 110,  99, 105, 108,   0, 
    171, 171,   1,   0,  19,   0, 
      1,   0,   4,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 143,   7, 
      0,   0, 120, 101,  95, 101, 
    100, 114,  97, 109,  95, 114, 
    116,  95,  98,  97, 115, 101, 
     95, 100, 119, 111, 114, 100, 
    115,  95, 115,  99,  97, 108, 
    101, 100,   0, 171,   1,   0, 
     19,   0,   1,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    143,   7,   0,   0, 120, 101, 
     95, 101, 100, 114,  97, 109, 
     95, 114, 116,  95, 102, 111, 
    114, 109,  97, 116,  95, 102, 
    108,  97, 103, 115,   0, 120, 
    101,  95, 101, 100, 114,  97, 
    109,  95, 114, 116,  95,  99, 
    108,  97, 109, 112,   0, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  92,   6,   0,   0, 
    120, 101,  95, 101, 100, 114, 
     97, 109,  95, 114, 116,  95, 
    107, 101, 101, 112,  95, 109, 
     97, 115, 107,   0, 171, 171, 
      1,   0,  19,   0,   1,   0, 
      4,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 143,   7,   0,   0, 
    120, 101,  95, 101, 100, 114, 
     97, 109,  95, 114, 116,  95, 
     98, 108, 101, 110, 100,  95, 
    102,  97,  99, 116, 111, 114, 
    115,  95, 111, 112, 115,   0, 
    120, 101,  95, 101, 100, 114, 
     97, 109,  95,  98, 108, 101, 
    110, 100,  95,  99, 111, 110, 
    115, 116,  97, 110, 116,   0, 
     77, 105,  99, 114, 111, 115, 
    111, 102, 116,  32,  40,  82, 
     41,  32,  72,  76,  83,  76, 
     32,  83, 104,  97, 100, 101, 
    114,  32,  67, 111, 109, 112, 
    105, 108, 101, 114,  32,  49, 
     48,  46,  49,   0, 171, 171, 
     73,  83,  71,  78,  44,   0, 
      0,   0,   1,   0,   0,   0, 
      8,   0,   0,   0,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   1,   0,   0,  83,  86, 
     95,  86, 101, 114, 116, 101, 
    120,  73,  68,   0,  79,  83, 
     71,  78,  44,   0,   0,   0, 
      1,   0,   0,   0,   8,   0, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   1,  14, 
      0,   0,  88,  69,  86,  69, 
     82,  84,  69,  88,  73,  68, 
      0, 171,  83,  72,  69,  88, 
     52,   2,   0,   0,  81,   0, 
      1,   0, 141,   0,   0,   0, 
    106,   8,   0,   1,  89,   0, 
      0,   7,  70, 142,  48,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,  96,   0,   0,   4, 
     18,  16,  16,   0,   0,   0, 
      0,   0,   6,   0,   0,   0, 
    101,   0,   0,   3,  18,  32, 
     16,   0,   0,   0,   0,   0, 
    104,   0,   0,   2,   1,   0, 
      0,   0,  32,   0,   0,  12, 
    114,   0,  16,   0,   0,   0, 
      0,   0,   6, 128,  48,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   1,   0, 
      0,   0,   2,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  60,   0,   0,   7, 
     50,   0,  16,   0,   0,   0, 
      0,   0, 150,   5,  16,   0, 
      0,   0,   0,   0,  70,   0, 
     16,   0,   0,   0,   0,   0, 
     31,   0,   4,   3,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     41,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,  16,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      8,   0,   0,   0,  85,   0, 
      0,   7,  66,   0,  16,   0, 
      0,   0,   0,   0,  10,  16, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   8,   0, 
      0,   0,   1,   0,   0,  10, 
     82,   0,  16,   0,   0,   0, 
      0,   0,   6,   2,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0, 255,   0, 255, 
      0,   0,   0,   0, 255,   0, 
    255,   0,   0,   0,   0,   0, 
     30,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  18,   0, 
      0,   1,  54,   0,   0,   5, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,  16,  16,   0, 
      0,   0,   0,   0,  21,   0, 
      0,   1,  31,   0,   4,   3, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  85,   0,   0,   7, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,  16,   0,   0,   0, 
    140,   0,   0,  11,  18,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,  16,   0, 
      0,   0,   1,  64,   0,   0, 
     16,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  21,   0,   0,   1, 
     30,   0,   0,   9,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  26, 128,  48,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
    255, 255, 255,   0,  83,   0, 
      0,   9,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     42, 128,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  84,   0, 
      0,   9,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     58, 128,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  86,   0, 
      0,   5,  18,  32,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 148,   0,   0,   0, 
     20,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      7,   0,   0,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0
};
