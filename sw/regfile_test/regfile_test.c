#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>

#include "mem-io.h"
#include "utils.h"
#include "proto2_hw.h"

int main(int argc,char** argv)
{
    void* pcie_addr;

    uint32_t pcie_bar0_addr=BASE_ADDRESS;
    uint32_t pcie_bar0_size=PROTO_SIZE;

    pcie_addr=phy_addr_2_vir_addr(pcie_bar0_addr,pcie_bar0_size);
    if(pcie_addr==NULL)
    {
       fprintf(stderr,"can't mmap phy_addr 0x%08x with size 0x%08x to viraddr. you must be in root.\n",pcie_bar0_addr,pcie_bar0_size);
       exit(-1);
    }
   fprintf(stdout,"phy_addr 0x%08x with size 0x%08x to viraddr 0x%8p.\n",pcie_bar0_addr,pcie_bar0_size, pcie_addr);
   //fprintf(stdout,"phy_addr 0x%08x with size 0x%08x to viraddr 0x%08x.\n",pcie_bar0_addr,pcie_bar0_size, (uint32_t)pcie_addr);

    //fprintf(stdout,"FPGA ID: 0x%08X\n",read_reg(pcie_addr,FPGA_ID));
    //fprintf(stdout,"VERSION: 0x%08X\n",read_reg(pcie_addr,FPGA_VERSION));

    //printf("%u err for checking FPGA segment 0x%08X\n",check_fgpa_segment(pcie_addr,TEST_BRAM_OFFSET,TEST_BRAM_SIZE),TEST_BRAM_OFFSET);

    //fprintf(stdout,"SPI    SRR: 0x%08X\n",read_reg(pcie_addr,TEST_SPI + 0x40));
    //fprintf(stdout,"SPI  SPICR: 0x%08X\n",read_reg(pcie_addr,TEST_SPI + 0x60));
    //fprintf(stdout,"SPI  SPISR: 0x%08X\n",read_reg(pcie_addr,TEST_SPI + 0x64));
    //fprintf(stdout,"SPI    DTR: 0x%08X\n",read_reg(pcie_addr,TEST_SPI + 0x68));
    //fprintf(stdout,"SPI SPISSR: 0x%08X\n",read_reg(pcie_addr,TEST_SPI + 0x70));
    //fprintf(stdout,"SPI TXOCCU: 0x%08X\n",read_reg(pcie_addr,TEST_SPI + 0x74));
    //fprintf(stdout,"SPI RXOCCU: 0x%08X\n",read_reg(pcie_addr,TEST_SPI + 0x78));
    //fprintf(stdout,"SPI  DGIER: 0x%08X\n",read_reg(pcie_addr,TEST_SPI + 0x1C));
    //fprintf(stdout,"SPI  IPISR: 0x%08X\n",read_reg(pcie_addr,TEST_SPI + 0x20));
    //fprintf(stdout,"SPI  IPIER: 0x%08X\n",read_reg(pcie_addr,TEST_SPI + 0x28));

    //fprintf(stdout,"SPI    DRR: 0x%08X\n",read_reg(pcie_addr,TEST_SPI + 0x6C)); // this one crashes the program


    munmap(pcie_addr,pcie_bar0_size);

    return 0;
}
