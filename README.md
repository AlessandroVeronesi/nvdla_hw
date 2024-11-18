# NVDLA - HARDWARE

Simpified NVDLA repository with clean and simple hardware instantiations.
The verilog model in this repository is not scalable and most of the original scripts and testbenches have been removed.
Every branch contains a different design point generated from the original NVDLA repository.

## Directory Structure

    dc/              -- Design Compiler scripts for Synthesis
    dc/scripts/      -- Bash and DC scripts for synthesis
    dc/cons/         -- Synthesis constraint files
    dc/config/       -- Configuration scripts for synthesis

    hdl/             -- HDL files
    hdl/dsg/         -- Verilog NVDLA files
    hdl/dsg/include/ -- HDL files common to the entire design
    hdl/dsg/nvdla/   -- NVDLA verilog description
    hdl/dsg/rams/    -- Design memories
    hdl/dsg/vlibs/   -- Verilog library of simple components

    sw/              -- Baremetal Software for NVDLA programming
    sw/tests/        -- Example Testing applications
    sw/src/          -- NVDLA Baremetal HAL
    sw/src/include/  -- Register Layout
    sw/src/port/     -- Portability layers