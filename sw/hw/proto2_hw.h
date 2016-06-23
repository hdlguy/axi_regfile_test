/** @file */  // This line is to make doxygen happy.
/* **********************
This file should document the register map for the MAX2580 RF Prototype Board.
We will try to use Doxygen compatible comments wherever possible.
************************** */

/// This is the base address of the AXI I/O 
#define		BASE_ADDRESS		0x40000000

/// This is the size of the memory hole we need to talk to the FPGA.
#define		PROTO_SIZE		0x00100000

#define     AXI_REGFILE     0x00010000

#define     FPGA_ID         (AXI_REGFILE+0x00)
#define     FPGA_VERSION    (AXI_REGFILE+0x04)

