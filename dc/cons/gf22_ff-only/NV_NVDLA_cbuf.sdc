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
#create_clock [get_ports dla_csb_clk]  -period 4000  -waveform {0 2000}
#create_clock [get_ports nvdla_core_clk]  -period 10000  -waveform {0 5000}
#set_clock_transition -max -rise 0.1 [get_clocks nvdla_core_clk]
#set_clock_transition -max -fall 0.1 [get_clocks nvdla_core_clk]
#set_clock_transition -min -rise 0.1 [get_clocks nvdla_core_clk]
#set_clock_transition -min -fall 0.1 [get_clocks nvdla_core_clk]
#create_clock [get_ports nvdla_csb_clk]  -period 10000  -waveform {0 5000}
#set_clock_transition -max -rise 0.1 [get_clocks nvdla_csb_clk]
#set_clock_transition -max -fall 0.1 [get_clocks nvdla_csb_clk]
#set_clock_transition -min -rise 0.1 [get_clocks nvdla_csb_clk]
#set_clock_transition -min -fall 0.1 [get_clocks nvdla_csb_clk]
#set_ideal_network [get_ports test_mode]
#set_ideal_network [get_ports direct_reset_]
#set_ideal_network [get_ports dla_reset_rstn]
set_ideal_network -no_propagate [get_nets nvdla_core_rstn]
set_false_path   -from [get_ports nvdla_core_rstn]
set_false_path   -from [get_ports pwrbus_ram_*]
#set_false_path   -from [get_clocks dla_core_clk] -to [get_clocks dla_csb_clk]
#set_false_path   -from [get_clocks dla_csb_clk] -to [get_clocks dla_core_clk]