# ===================================================================
# File: syn/templates/config.sh
# NVDLA Open Source Project
# Template configuration file for reference synthesis methodology
#
# Copyright (c) 2016 – 2017 NVIDIA Corporation. Licensed under the
# NVDLA Open Hardware License; see the "LICENSE.txt" file that came
# with this distribution for more information.
# ===================================================================

# ===========================
# DESIGN RELATED VARIABLES
# ===========================

#export TOP_NAMES="NV_NVDLA_partition_a NV_NVDLA_partition_c NV_NVDLA_partition_o NV_NVDLA_partition_m NV_NVDLA_partition_p"
#export TOP_NAMES="NV_nvdla"
#export TOP_NAMES="NV_NVDLA_sdp NV_NVDLA_cmac NV_NVDLA_cbuf"
export TOP_NAMES="NV_NVDLA_cbuf"

export TB_PATH="top.nvdla_top"
#TOP_INSTS_NV_NVDLA_partition_a="u_partition_a"
#TOP_INSTS_NV_NVDLA_partition_c="u_partition_c"
#TOP_INSTS_NV_NVDLA_partition_o="u_partition_o"
#TOP_INSTS_NV_NVDLA_partition_m="u_partition_ma u_partition_mb"
#TOP_INSTS_NV_NVDLA_partition_p="u_partition_p"

export NVDLA_ROOT="`dirname $0`/../..";

export FPGARAMSDIR="${NVDLA_ROOT}/outdir/${PROJECT}/vmod/rams/fpga/small_rams"

# Where do I find the RTL source verilog/system verilog files?
export RTL_SEARCH_PATH=" \
    $(ls -d ${NVDLA_ROOT}/outdir/${PROJECT}/vmod/nvdla/*) \
    ${NVDLA_ROOT}/outdir/${PROJECT}/vmod/vlibs \
    ${FPGARAMSDIR} \
"

# For verilog source files that do not match the module name. 
export EXTRA_RTL=" \
    ${NVDLA_ROOT}/outdir/${PROJECT}/vmod/nvdla/nocif/NV_NVDLA_XXIF_libs.v \
"

# If there are verilog header files, where do I find them?
export RTL_INCLUDE_SEARCH_PATH=" \
    ${NVDLA_ROOT}/outdir/${PROJECT}/vmod/include \
"


# File extensions for source files...
export RTL_EXTENSIONS=".v .sv .gv"
export RTL_INCLUDE_EXTENSIONS=".vh .svh"

# FLoorplans and constraints
export DEF=""
export CONS="${NVDLA_ROOT}/syn/cons/gf22_ff-only/"

# Power related files
#export SAIF_FILE="$NVDLA_ROOT/outdir/nv_large/verif/synth_tb_sim/googlenet_conv2_3x3_int16/top0.snps.saif"
export SAIF_FILE=""

# ===========================
# TOOL RELATED VARIABLES
# ===========================


# Design Compiler Installation - Where do I find the dc_shell executable
export DC_PATH="/ihp/ihpusr/synopsys/syn202009/bin"
export PT_PATH="/ihp/ihpusr/synopsys/pt201912/bin"


# ===========================
# LIBRARY RELATED VARIABLES
# ===========================

export RELEASE_DIR="/ihp/projects/_COMMON/GF22FDX/22FDX-EXT_IP"
export RAM_LIB_DIR=""
export TARGET_LIB="${RELEASE_DIR}/GF22FDX_SC8T_104CPP_BASE_CSC20L_FDK_RELV06R60/model/timing/db/GF22FDX_SC8T_104CPP_BASE_CSC20L_SSG_0P72V_0P00V_0P00V_0P00V_125C.db"
export LINK_LIB="\
    ${RELEASE_DIR}/GF22FDX_SC8T_104CPP_BASE_CSC20L_FDK_RELV06R60/model/timing/db/GF22FDX_SC8T_104CPP_BASE_CSC20L_SSG_0P72V_0P00V_0P00V_0P00V_125C.db \
    ${RELEASE_DIR}/IN22FDX_GPIO33_10M3S40PI_FDK_RELV03R00SZ/model/timing/db/IN22FDX_GPIO33_10M3S40PI_SSG_0P72_2P97_125.db \
    ${RELEASE_DIR}/IN22FDX_GPIO33_5VFSFT_INLINE_10M3S_FE_RELV01R00SZ/model/timing/db/IN22FDX_GPIO33_5VFSFT_INLINE_SSG_0P72_2P97_125.db \
"

export MW_LIB=""

#export SIM_OPTIONS= "\
#    ${RELEASE_DIR}/GF22FDX_SC8T_104CPP_BASE_CSC20L_FDK_RELV06R60/model/verilog/prim.v \
#    ${RELEASE_DIR}/GF22FDX_SC8T_104CPP_BASE_CSC20L_FDK_RELV06R60/model/verilog/GF22FDX_SC8T_104CPP_BASE_CSC20L.v \
#    +define+CLK_PERIOD_PS=4000 \
#"
#    ${FPGARAMSDIR}/nv_ram_rws_128x18.v \
#    ${FPGARAMSDIR}/nv_ram_rws_128x256.v \
#    ${FPGARAMSDIR}/nv_ram_rws_128x64.v \
#    ${FPGARAMSDIR}/nv_ram_rws_16x256.v \
#    ${FPGARAMSDIR}/nv_ram_rws_16x272.v \
#    ${FPGARAMSDIR}/nv_ram_rws_16x64.v \
#    ${FPGARAMSDIR}/nv_ram_rws_256x3.v \
#    ${FPGARAMSDIR}/nv_ram_rws_256x512.v \
#    ${FPGARAMSDIR}/nv_ram_rws_256x64.v \
#    ${FPGARAMSDIR}/nv_ram_rws_256x7.v \
#    ${FPGARAMSDIR}/nv_ram_rws_32x16.v \
#    ${FPGARAMSDIR}/nv_ram_rws_32x512.v \
#    ${FPGARAMSDIR}/nv_ram_rws_32x544.v \
#    ${FPGARAMSDIR}/nv_ram_rws_32x768.v \
#    ${FPGARAMSDIR}/nv_ram_rws_512x256.v \
#    ${FPGARAMSDIR}/nv_ram_rws_512x512.v \
#    ${FPGARAMSDIR}/nv_ram_rws_512x64.v \
#    ${FPGARAMSDIR}/nv_ram_rws_64x1024.v \
#    ${FPGARAMSDIR}/nv_ram_rws_64x1088.v \
#    ${FPGARAMSDIR}/nv_ram_rws_64x10.v \
#    ${FPGARAMSDIR}/nv_ram_rws_64x116.v \
#    ${FPGARAMSDIR}/nv_ram_rws_64x18.v \
#    ${FPGARAMSDIR}/nv_ram_rwsp_128x11.v \
#    ${FPGARAMSDIR}/nv_ram_rwsp_128x6.v \
#    ${FPGARAMSDIR}/nv_ram_rwsp_160x16.v \
#    ${FPGARAMSDIR}/nv_ram_rwsp_160x514.v \
#    ${FPGARAMSDIR}/nv_ram_rwsp_160x65.v \
#    ${FPGARAMSDIR}/nv_ram_rwsp_20x289.v \
#    ${FPGARAMSDIR}/nv_ram_rwsp_245x514.v \
#    ${FPGARAMSDIR}/nv_ram_rwsp_256x11.v \
#    ${FPGARAMSDIR}/nv_ram_rwsp_32x32.v \
#    ${FPGARAMSDIR}/nv_ram_rwsp_61x514.v \
#    ${FPGARAMSDIR}/nv_ram_rwsp_61x64.v \
#    ${FPGARAMSDIR}/nv_ram_rwsp_61x65.v \
#    ${FPGARAMSDIR}/nv_ram_rwsp_80x14.v \
#    ${FPGARAMSDIR}/nv_ram_rwsp_80x16.v \
#    ${FPGARAMSDIR}/nv_ram_rwsp_80x256.v \
#    ${FPGARAMSDIR}/nv_ram_rwsp_80x514.v \
#    ${FPGARAMSDIR}/nv_ram_rwsp_80x65.v \
#    ${FPGARAMSDIR}/nv_ram_rwsp_8x65.v \
#    ${FPGARAMSDIR}/nv_ram_rwst_256x8.v \
#    ${FPGARAMSDIR}/nv_ram_rwsthp_19x32.v \
#    ${FPGARAMSDIR}/nv_ram_rwsthp_19x4.v \
#    ${FPGARAMSDIR}/nv_ram_rwsthp_19x80.v \
#    ${FPGARAMSDIR}/nv_ram_rwsthp_60x168.v \
#    ${FPGARAMSDIR}/nv_ram_rwsthp_60x21.v \
#    ${FPGARAMSDIR}/nv_ram_rwsthp_80x15.v \
#    ${FPGARAMSDIR}/nv_ram_rwsthp_80x72.v \
#    ${FPGARAMSDIR}/nv_ram_rwsthp_80x9.v \
#"

export TF_FILE=""
export TLUPLUS_FILE=""
export TLUPLUS_MAPPING_FILE=""
export MIN_ROUTING_LAYER=""
export MAX_ROUTING_LAYER=""
export HORIZONTAL_LAYERS=""
export VERTICAL_LAYERS=""
export WIRELOAD_MODEL_NAME=""
export WIRELOAD_MODEL_FILE=""
export DONT_USE_LIST=""

# ==========================
# MISCELLANEOUS VARIABLES 
#===========================
# Flatten the syn output (must be hierarchical for verification). 
export FLATTEN_OUTPUT="0"

# Set host options in the DC session. 
export DC_NUM_CORES="8"

# Apply constraints to tighten CG enable paths to model post-CTS insertion delays
export TIGHTEN_CGE="0"

# Enable Area recovery (run optimize_netlist -area)
export AREA_RECOVERY="0"

# Number of incremental recompile loops
export INCREMENTAL_RECOMPILE_COUNT="0"

# For Job management
export COMMAND_PREFIX=""
export PTPX_COMMAND_PREFIX=""

#export CGLUT_FILE=""
