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
//   float2 xe_tessellation_factor_range;// Offset:    4 Size:     8
//   uint xe_line_loop_closing_index;   // Offset:   12 Size:     4 [unused]
//   uint xe_vertex_index_endian;       // Offset:   16 Size:     4 [unused]
//   uint xe_vertex_index_offset;       // Offset:   20 Size:     4 [unused]
//   uint2 xe_vertex_index_min_max;     // Offset:   24 Size:     8 [unused]
//   float4 xe_user_clip_planes[6];     // Offset:   32 Size:    96 [unused]
//   float3 xe_ndc_scale;               // Offset:  128 Size:    12 [unused]
//   float xe_point_vertex_diameter_min;// Offset:  140 Size:     4 [unused]
//   float3 xe_ndc_offset;              // Offset:  144 Size:    12 [unused]
//   float xe_point_vertex_diameter_max;// Offset:  156 Size:     4 [unused]
//   float2 xe_point_constant_radius;   // Offset:  160 Size:     8 [unused]
//   float2 xe_point_screen_to_ndc;     // Offset:  168 Size:     8 [unused]
//   uint xe_interpolator_sampling_pattern;// Offset:  176 Size:     4 [unused]
//   uint xe_ps_param_gen;              // Offset:  180 Size:     4 [unused]
//   uint2 xe_sample_count_log2;        // Offset:  184 Size:     8 [unused]
//   uint4 xe_texture_swizzled_signs[2];// Offset:  192 Size:    32 [unused]
//   uint xe_textures_resolved;         // Offset:  224 Size:     4 [unused]
//   float xe_alpha_test_reference;     // Offset:  228 Size:     4 [unused]
//   uint xe_alpha_to_mask;             // Offset:  232 Size:     4 [unused]
//   uint xe_edram_32bpp_tile_pitch_dwords_scaled;// Offset:  236 Size:     4 [unused]
//   float4 xe_color_exp_bias;          // Offset:  240 Size:    16 [unused]
//   float2 xe_edram_poly_offset_front; // Offset:  256 Size:     8 [unused]
//   float2 xe_edram_poly_offset_back;  // Offset:  264 Size:     8 [unused]
//   uint xe_edram_depth_base_dwords_scaled;// Offset:  272 Size:     4 [unused]
//   uint4 xe_edram_stencil[2];         // Offset:  288 Size:    32 [unused]
//   uint4 xe_edram_rt_base_dwords_scaled;// Offset:  320 Size:    16 [unused]
//   uint4 xe_edram_rt_format_flags;    // Offset:  336 Size:    16 [unused]
//   float4 xe_edram_rt_clamp[4];       // Offset:  352 Size:    64 [unused]
//   uint4 xe_edram_rt_keep_mask[2];    // Offset:  416 Size:    32 [unused]
//   uint4 xe_edram_rt_blend_factors_ops;// Offset:  448 Size:    16 [unused]
//   float4 xe_edram_blend_constant;    // Offset:  464 Size:    16 [unused]
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
// Patch Constant signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_TessFactor            0   x           0 QUADEDGE   float   x   
// SV_TessFactor            1   x           1 QUADEDGE   float   x   
// SV_TessFactor            2   x           2 QUADEDGE   float   x   
// SV_TessFactor            3   x           3 QUADEDGE   float   x   
// SV_InsideTessFactor      0   x           4  QUADINT   float   x   
// SV_InsideTessFactor      1   x           5  QUADINT   float   x   
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// XEVERTEXID               0   x           0     NONE   float   x   
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// XEVERTEXID               0   x           0     NONE   float   x   
//
// Tessellation Domain   # of control points
// -------------------- --------------------
// Quadrilateral                           4
//
// Tessellation Output Primitive  Partitioning Type 
// ------------------------------ ------------------
// Clockwise Triangles            Even Fractional   
//
hs_5_1
hs_decls 
dcl_input_control_point_count 4
dcl_output_control_point_count 4
dcl_tessellator_domain domain_quad
dcl_tessellator_partitioning partitioning_fractional_even
dcl_tessellator_output_primitive output_triangle_cw
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[0:0][1], immediateIndexed, space=0
hs_fork_phase 
dcl_hs_fork_phase_instance_count 4
dcl_input vForkInstanceID
dcl_output_siv o0.x, finalQuadUeq0EdgeTessFactor
dcl_output_siv o1.x, finalQuadVeq0EdgeTessFactor
dcl_output_siv o2.x, finalQuadUeq1EdgeTessFactor
dcl_output_siv o3.x, finalQuadVeq1EdgeTessFactor
dcl_temps 1
dcl_indexrange o0.x 4
mov r0.x, vForkInstanceID.x
mov o[r0.x + 0].x, CB0[0][0].z
ret 
hs_fork_phase 
dcl_hs_fork_phase_instance_count 2
dcl_input vForkInstanceID
dcl_output_siv o4.x, finalQuadUInsideTessFactor
dcl_output_siv o5.x, finalQuadVInsideTessFactor
dcl_temps 1
dcl_indexrange o4.x 2
mov r0.x, vForkInstanceID.x
mov o[r0.x + 4].x, CB0[0][0].z
ret 
// Approximately 6 instruction slots used
#endif

const BYTE continuous_quad_hs[] =
{
     68,  88,  66,  67,  41,  61, 
     68, 236, 233,  38, 162, 138, 
    209,  48, 160, 247, 155, 238, 
     65,  82,   1,   0,   0,   0, 
     12,  14,   0,   0,   6,   0, 
      0,   0,  56,   0,   0,   0, 
    216,  10,   0,   0,  12,  11, 
      0,   0,  64,  11,   0,   0, 
      4,  12,   0,   0, 112,  13, 
      0,   0,  82,  68,  69,  70, 
    152,  10,   0,   0,   1,   0, 
      0,   0, 120,   0,   0,   0, 
      1,   0,   0,   0,  60,   0, 
      0,   0,   1,   5,  83,  72, 
      0,   5,   0,   0, 110,  10, 
      0,   0,  19,  19,  68,  37, 
     60,   0,   0,   0,  24,   0, 
      0,   0,  40,   0,   0,   0, 
     40,   0,   0,   0,  36,   0, 
      0,   0,  12,   0,   0,   0, 
      0,   0,   0,   0, 100,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 120, 101,  95, 115, 
    121, 115, 116, 101, 109,  95, 
     99,  98, 117, 102, 102, 101, 
    114,   0, 171, 171, 100,   0, 
      0,   0,  32,   0,   0,   0, 
    144,   0,   0,   0, 224,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 144,   5, 
      0,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0, 160,   5,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 196,   5,   0,   0, 
      4,   0,   0,   0,   8,   0, 
      0,   0,   2,   0,   0,   0, 
    232,   5,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     12,   6,   0,   0,  12,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0, 160,   5, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  39,   6, 
      0,   0,  16,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0, 160,   5,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  62,   6,   0,   0, 
     20,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
    160,   5,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     85,   6,   0,   0,  24,   0, 
      0,   0,   8,   0,   0,   0, 
      0,   0,   0,   0, 116,   6, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 152,   6, 
      0,   0,  32,   0,   0,   0, 
     96,   0,   0,   0,   0,   0, 
      0,   0, 180,   6,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 216,   6,   0,   0, 
    128,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    236,   6,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     16,   7,   0,   0, 140,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,  52,   7, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  88,   7, 
      0,   0, 144,   0,   0,   0, 
     12,   0,   0,   0,   0,   0, 
      0,   0, 236,   6,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 102,   7,   0,   0, 
    156,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
     52,   7,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    131,   7,   0,   0, 160,   0, 
      0,   0,   8,   0,   0,   0, 
      0,   0,   0,   0, 232,   5, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 156,   7, 
      0,   0, 168,   0,   0,   0, 
      8,   0,   0,   0,   0,   0, 
      0,   0, 232,   5,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 179,   7,   0,   0, 
    176,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
    160,   5,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    212,   7,   0,   0, 180,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0, 160,   5, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 228,   7, 
      0,   0, 184,   0,   0,   0, 
      8,   0,   0,   0,   0,   0, 
      0,   0, 116,   6,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 249,   7,   0,   0, 
    192,   0,   0,   0,  32,   0, 
      0,   0,   0,   0,   0,   0, 
     28,   8,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     64,   8,   0,   0, 224,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0, 160,   5, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  85,   8, 
      0,   0, 228,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,  52,   7,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 109,   8,   0,   0, 
    232,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
    160,   5,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    126,   8,   0,   0, 236,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0, 160,   5, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 166,   8, 
      0,   0, 240,   0,   0,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0, 184,   8,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 220,   8,   0,   0, 
      0,   1,   0,   0,   8,   0, 
      0,   0,   0,   0,   0,   0, 
    232,   5,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    247,   8,   0,   0,   8,   1, 
      0,   0,   8,   0,   0,   0, 
      0,   0,   0,   0, 232,   5, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  17,   9, 
      0,   0,  16,   1,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0, 160,   5,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  51,   9,   0,   0, 
     32,   1,   0,   0,  32,   0, 
      0,   0,   0,   0,   0,   0, 
     68,   9,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    104,   9,   0,   0,  64,   1, 
      0,   0,  16,   0,   0,   0, 
      0,   0,   0,   0, 136,   9, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 172,   9, 
      0,   0,  80,   1,   0,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0, 136,   9,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 197,   9,   0,   0, 
     96,   1,   0,   0,  64,   0, 
      0,   0,   0,   0,   0,   0, 
    216,   9,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    252,   9,   0,   0, 160,   1, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,  20,  10, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  56,  10, 
      0,   0, 192,   1,   0,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0, 136,   9,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  86,  10,   0,   0, 
    208,   1,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
    184,   8,   0,   0,   0,   0, 
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
    153,   5,   0,   0, 120, 101, 
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
    225,   5,   0,   0, 120, 101, 
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
      0,   0, 109,   6,   0,   0, 
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
    172,   6,   0,   0, 120, 101, 
     95, 110, 100,  99,  95, 115, 
     99,  97, 108, 101,   0, 102, 
    108, 111,  97, 116,  51,   0, 
      1,   0,   3,   0,   1,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 229,   6,   0,   0, 
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
      0,   0,  45,   7,   0,   0, 
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
     95, 114,  97, 100, 105, 117, 
    115,   0, 120, 101,  95, 112, 
    111, 105, 110, 116,  95, 115, 
     99, 114, 101, 101, 110,  95, 
    116, 111,  95, 110, 100,  99, 
      0, 120, 101,  95, 105, 110, 
    116, 101, 114, 112, 111, 108, 
     97, 116, 111, 114,  95, 115, 
     97, 109, 112, 108, 105, 110, 
    103,  95, 112,  97, 116, 116, 
    101, 114, 110,   0, 120, 101, 
     95, 112, 115,  95, 112,  97, 
    114,  97, 109,  95, 103, 101, 
    110,   0, 120, 101,  95, 115, 
     97, 109, 112, 108, 101,  95, 
     99, 111, 117, 110, 116,  95, 
    108, 111, 103,  50,   0, 120, 
    101,  95, 116, 101, 120, 116, 
    117, 114, 101,  95, 115, 119, 
    105, 122, 122, 108, 101, 100, 
     95, 115, 105, 103, 110, 115, 
      0, 117, 105, 110, 116,  52, 
      0, 171, 171, 171,   1,   0, 
     19,   0,   1,   0,   4,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     19,   8,   0,   0, 120, 101, 
     95, 116, 101, 120, 116, 117, 
    114, 101, 115,  95, 114, 101, 
    115, 111, 108, 118, 101, 100, 
      0, 120, 101,  95,  97, 108, 
    112, 104,  97,  95, 116, 101, 
    115, 116,  95, 114, 101, 102, 
    101, 114, 101, 110,  99, 101, 
      0, 120, 101,  95,  97, 108, 
    112, 104,  97,  95, 116, 111, 
     95, 109,  97, 115, 107,   0, 
    120, 101,  95, 101, 100, 114, 
     97, 109,  95,  51,  50,  98, 
    112, 112,  95, 116, 105, 108, 
    101,  95, 112, 105, 116,  99, 
    104,  95, 100, 119, 111, 114, 
    100, 115,  95, 115,  99,  97, 
    108, 101, 100,   0, 120, 101, 
     95,  99, 111, 108, 111, 114, 
     95, 101, 120, 112,  95,  98, 
    105,  97, 115,   0,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    172,   6,   0,   0, 120, 101, 
     95, 101, 100, 114,  97, 109, 
     95, 112, 111, 108, 121,  95, 
    111, 102, 102, 115, 101, 116, 
     95, 102, 114, 111, 110, 116, 
      0, 120, 101,  95, 101, 100, 
    114,  97, 109,  95, 112, 111, 
    108, 121,  95, 111, 102, 102, 
    115, 101, 116,  95,  98,  97, 
     99, 107,   0, 120, 101,  95, 
    101, 100, 114,  97, 109,  95, 
    100, 101, 112, 116, 104,  95, 
     98,  97, 115, 101,  95, 100, 
    119, 111, 114, 100, 115,  95, 
    115,  99,  97, 108, 101, 100, 
      0, 120, 101,  95, 101, 100, 
    114,  97, 109,  95, 115, 116, 
    101, 110,  99, 105, 108,   0, 
      1,   0,  19,   0,   1,   0, 
      4,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  19,   8,   0,   0, 
    120, 101,  95, 101, 100, 114, 
     97, 109,  95, 114, 116,  95, 
     98,  97, 115, 101,  95, 100, 
    119, 111, 114, 100, 115,  95, 
    115,  99,  97, 108, 101, 100, 
      0, 171,   1,   0,  19,   0, 
      1,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  19,   8, 
      0,   0, 120, 101,  95, 101, 
    100, 114,  97, 109,  95, 114, 
    116,  95, 102, 111, 114, 109, 
     97, 116,  95, 102, 108,  97, 
    103, 115,   0, 120, 101,  95, 
    101, 100, 114,  97, 109,  95, 
    114, 116,  95,  99, 108,  97, 
    109, 112,   0, 171,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    172,   6,   0,   0, 120, 101, 
     95, 101, 100, 114,  97, 109, 
     95, 114, 116,  95, 107, 101, 
    101, 112,  95, 109,  97, 115, 
    107,   0, 171, 171,   1,   0, 
     19,   0,   1,   0,   4,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     19,   8,   0,   0, 120, 101, 
     95, 101, 100, 114,  97, 109, 
     95, 114, 116,  95,  98, 108, 
    101, 110, 100,  95, 102,  97, 
     99, 116, 111, 114, 115,  95, 
    111, 112, 115,   0, 120, 101, 
     95, 101, 100, 114,  97, 109, 
     95,  98, 108, 101, 110, 100, 
     95,  99, 111, 110, 115, 116, 
     97, 110, 116,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  49,  48,  46, 
     49,   0, 171, 171,  73,  83, 
     71,  78,  44,   0,   0,   0, 
      1,   0,   0,   0,   8,   0, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   1,   1, 
      0,   0,  88,  69,  86,  69, 
     82,  84,  69,  88,  73,  68, 
      0, 171,  79,  83,  71,  78, 
     44,   0,   0,   0,   1,   0, 
      0,   0,   8,   0,   0,   0, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   1,  14,   0,   0, 
     88,  69,  86,  69,  82,  84, 
     69,  88,  73,  68,   0, 171, 
     80,  67,  83,  71, 188,   0, 
      0,   0,   6,   0,   0,   0, 
      8,   0,   0,   0, 152,   0, 
      0,   0,   0,   0,   0,   0, 
     11,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      1,  14,   0,   0, 152,   0, 
      0,   0,   1,   0,   0,   0, 
     11,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
      1,  14,   0,   0, 152,   0, 
      0,   0,   2,   0,   0,   0, 
     11,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
      1,  14,   0,   0, 152,   0, 
      0,   0,   3,   0,   0,   0, 
     11,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
      1,  14,   0,   0, 166,   0, 
      0,   0,   0,   0,   0,   0, 
     12,   0,   0,   0,   3,   0, 
      0,   0,   4,   0,   0,   0, 
      1,  14,   0,   0, 166,   0, 
      0,   0,   1,   0,   0,   0, 
     12,   0,   0,   0,   3,   0, 
      0,   0,   5,   0,   0,   0, 
      1,  14,   0,   0,  83,  86, 
     95,  84, 101, 115, 115,  70, 
     97,  99, 116, 111, 114,   0, 
     83,  86,  95,  73, 110, 115, 
    105, 100, 101,  84, 101, 115, 
    115,  70,  97,  99, 116, 111, 
    114,   0, 171, 171,  83,  72, 
     69,  88, 100,   1,   0,   0, 
     81,   0,   3,   0,  89,   0, 
      0,   0, 113,   0,   0,   1, 
    147,  32,   0,   1, 148,  32, 
      0,   1, 149,  24,   0,   1, 
    150,  32,   0,   1, 151,  24, 
      0,   1, 106,   8,   0,   1, 
     89,   0,   0,   7,  70, 142, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 115,   0, 
      0,   1, 153,   0,   0,   2, 
      4,   0,   0,   0,  95,   0, 
      0,   2,   0, 112,   1,   0, 
    103,   0,   0,   4,  18,  32, 
     16,   0,   0,   0,   0,   0, 
     11,   0,   0,   0, 103,   0, 
      0,   4,  18,  32,  16,   0, 
      1,   0,   0,   0,  12,   0, 
      0,   0, 103,   0,   0,   4, 
     18,  32,  16,   0,   2,   0, 
      0,   0,  13,   0,   0,   0, 
    103,   0,   0,   4,  18,  32, 
     16,   0,   3,   0,   0,   0, 
     14,   0,   0,   0, 104,   0, 
      0,   2,   1,   0,   0,   0, 
     91,   0,   0,   4,  18,  32, 
     16,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,  54,   0, 
      0,   4,  18,   0,  16,   0, 
      0,   0,   0,   0,  10, 112, 
      1,   0,  54,   0,   0,   8, 
     18,  32, 144,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     42, 128,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  62,   0, 
      0,   1, 115,   0,   0,   1, 
    153,   0,   0,   2,   2,   0, 
      0,   0,  95,   0,   0,   2, 
      0, 112,   1,   0, 103,   0, 
      0,   4,  18,  32,  16,   0, 
      4,   0,   0,   0,  15,   0, 
      0,   0, 103,   0,   0,   4, 
     18,  32,  16,   0,   5,   0, 
      0,   0,  16,   0,   0,   0, 
    104,   0,   0,   2,   1,   0, 
      0,   0,  91,   0,   0,   4, 
     18,  32,  16,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
     54,   0,   0,   4,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10, 112,   1,   0,  54,   0, 
      0,   9,  18,  32, 208,   0, 
      4,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     42, 128,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  62,   0, 
      0,   1,  83,  84,  65,  84, 
    148,   0,   0,   0,   6,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     11,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   3,   0,   0,   0, 
      4,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0
};
