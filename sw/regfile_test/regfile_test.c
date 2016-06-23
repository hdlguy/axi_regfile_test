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

    fprintf(stdout,"FPGA ID: 0x%08X\n",read_reg(pcie_addr,FPGA_ID));
    fprintf(stdout,"VERSION: 0x%08X\n",read_reg(pcie_addr,FPGA_VERSION));

    uint32_t* reg_array;
    reg_array = (uint32_t *)AXI_REGFILE;

    uint32_t i;
    for(i=0;i<16;i++) write_reg(pcie_addr, (uint32_t)(&(reg_array[i])), ~i);
    for(i=0;i<16;i++) fprintf(stdout,"reg_array[%d] = 0x%08X\n",i, read_reg(pcie_addr,(uint32_t)(&(reg_array[i]))));


    //fprintf(stdout,"SPI    SRR: 0x%08X\n",read_reg(pcie_addr,TEST_SPI + 0x40));


    munmap(pcie_addr,pcie_bar0_size);

    return 0;
}
