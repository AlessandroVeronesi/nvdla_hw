# ===================================================================
# File: NV_nvdla.sdc
# NVDLA Open Source Project
#
# Copyright (c) 2016 – 2017 NVIDIA Corporation. Licensed under the
# NVDLA Open Hardware License; see the "LICENSE.txt" file that came
# with this distribution for more information.
# ===================================================================

set_max_area 0
create_clock [get_ports nvdla_core_clk]  -period 4000  -waveform {0 2000}
set_ideal_network [get_ports nvdla_core_rstn]
#set_ideal_network -no_propagate [get_nets nvdla_core_rstn]
#set_false_path   -from [get_ports direct_reset_]
set_false_path   -from [get_ports nvdla_core_rstn]
set_false_path   -from [get_ports tmc2slcg_disable_clock_gating]
set_false_path   -from [get_ports global_clk_ovr_on_sync]
set_false_path   -from [get_ports dla_clk_ovr_on_sync]
