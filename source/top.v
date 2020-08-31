module top (
    inout   logic    [14:0]DDR_addr,
    inout   logic    [2:0]DDR_ba,
    inout   logic    DDR_cas_n,
    inout   logic    DDR_ck_n,
    inout   logic    DDR_ck_p,
    inout   logic    DDR_cke,
    inout   logic    DDR_cs_n,
    inout   logic    [3:0]DDR_dm,
    inout   logic    [31:0]DDR_dq,
    inout   logic    [3:0]DDR_dqs_n,
    inout   logic    [3:0]DDR_dqs_p,
    inout   logic    DDR_odt,
    inout   logic    DDR_ras_n,
    inout   logic    DDR_reset_n,
    inout   logic    DDR_we_n,
    inout   logic    FIXED_IO_ddr_vrn,
    inout   logic    FIXED_IO_ddr_vrp,
    inout   logic    [53:0]FIXED_IO_mio,
    inout   logic    FIXED_IO_ps_clk,
    inout   logic    FIXED_IO_ps_porb,
    inout   logic    FIXED_IO_ps_srstb
);

    logic   spi_slave_sck, spi_slave_mosi, spi_slave_miso;
    logic   [0:0]   spi_slave_ss_n;
    logic   axi_aclk;
    logic [15:0][31:0] slv_reg, slv_read;

    system system_i(
        .DDR_addr(DDR_addr),
        .DDR_ba(DDR_ba),
        .DDR_cas_n(DDR_cas_n),
        .DDR_ck_n(DDR_ck_n),
        .DDR_ck_p(DDR_ck_p),
        .DDR_cke(DDR_cke),
        .DDR_cs_n(DDR_cs_n),
        .DDR_dm(DDR_dm),
        .DDR_dq(DDR_dq),
        .DDR_dqs_n(DDR_dqs_n),
        .DDR_dqs_p(DDR_dqs_p),
        .DDR_odt(DDR_odt),
        .DDR_ras_n(DDR_ras_n),
        .DDR_reset_n(DDR_reset_n),
        .DDR_we_n(DDR_we_n),
        .FIXED_IO_ddr_vrn(FIXED_IO_ddr_vrn),
        .FIXED_IO_ddr_vrp(FIXED_IO_ddr_vrp),
        .FIXED_IO_mio(FIXED_IO_mio),
        .FIXED_IO_ps_clk(FIXED_IO_ps_clk),
        .FIXED_IO_ps_porb(FIXED_IO_ps_porb),
        .FIXED_IO_ps_srstb(FIXED_IO_ps_srstb),
        .axi_aclk(axi_aclk),
        .slv_read0(slv_read[0]),
        .slv_read1(slv_read[1]),
        .slv_read10(slv_read[10]),
        .slv_read11(slv_read[11]),
        .slv_read12(slv_read[12]),
        .slv_read13(slv_read[13]),
        .slv_read14(slv_read[14]),
        .slv_read15(slv_read[15]),
        .slv_read2(slv_read[2]),
        .slv_read3(slv_read[3]),
        .slv_read4(slv_read[4]),
        .slv_read5(slv_read[5]),
        .slv_read6(slv_read[6]),
        .slv_read7(slv_read[7]),
        .slv_read8(slv_read[8]),
        .slv_read9(slv_read[9]),
        .slv_reg0(slv_reg[0]),
        .slv_reg1(slv_reg[1]),
        .slv_reg10(slv_reg[10]),
        .slv_reg11(slv_reg[11]),
        .slv_reg12(slv_reg[12]),
        .slv_reg13(slv_reg[13]),
        .slv_reg14(slv_reg[14]),
        .slv_reg15(slv_reg[15]),
        .slv_reg2(slv_reg[2]),
        .slv_reg3(slv_reg[3]),
        .slv_reg4(slv_reg[4]),
        .slv_reg5(slv_reg[5]),
        .slv_reg6(slv_reg[6]),
        .slv_reg7(slv_reg[7]),
        .slv_reg8(slv_reg[8]),
        .slv_reg9(slv_reg[9])
    );
    
    assign slv_read[0]  = 32'hDEADBEEF;
    assign slv_read[1]  = 32'h76543210;
    assign slv_read[15:2] = slv_reg[15:2];


endmodule
