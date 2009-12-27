/***********************************************************************/
/*                                                                     */
/*  FILE        :intprg.c                                              */
/*  DATE        :Sun, Dec 27, 2009                                     */
/*  DESCRIPTION :Interrupt Program                                     */
/*  CPU TYPE    :Other                                                 */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.16).    */
/*                                                                     */
/***********************************************************************/
                  


#include <machine.h>
#include "vect.h"
#pragma section IntPRG

// 4 Illegal code
void INT_Illegal_code(void){/* sleep(); */}
// 5 Reserved

// 6 Illegal slot
void INT_Illegal_slot(void){/* sleep(); */}
// 7 Reserved

// 8 Reserved

// 9 CPU Address error
void INT_CPU_Address(void){/* sleep(); */}
// 10 DMAC Address error
void INT_DMAC_Address(void){/* sleep(); */}
// 11 NMI
void INT_NMI(void){/* sleep(); */}
// 12 User breakpoint trap
void INT_User_Break(void){/* sleep(); */}
// 13 Reserved

// 14 H-UDI
void INT_HUDI(void){/* sleep(); */}
// 15 Register bank over
void INT_Bank_Overflow(void){/* sleep(); */}
// 16 Register bank under
void INT_Bank_Underflow(void){/* sleep(); */}
// 17 ZERO DIV
void INT_Divide_by_Zero(void){/* sleep(); */}
// 18 OVER DIV
void INT_Divide_Overflow(void){/* sleep(); */}
// 19 Reserved

// 20 Reserved

// 21 Reserved

// 22 Reserved

// 23 Reserved

// 24 Reserved

// 25 Reserved

// 26 Reserved

// 27 Reserved

// 28 Reserved

// 29 Reserved

// 30 Reserved

// 31 Reserved

// 32 TRAPA (User Vecter)
void INT_TRAPA32(void){/* sleep(); */}
// 33 TRAPA (User Vecter)
void INT_TRAPA33(void){/* sleep(); */}
// 34 TRAPA (User Vecter)
void INT_TRAPA34(void){/* sleep(); */}
// 35 TRAPA (User Vecter)
void INT_TRAPA35(void){/* sleep(); */}
// 36 TRAPA (User Vecter)
void INT_TRAPA36(void){/* sleep(); */}
// 37 TRAPA (User Vecter)
void INT_TRAPA37(void){/* sleep(); */}
// 38 TRAPA (User Vecter)
void INT_TRAPA38(void){/* sleep(); */}
// 39 TRAPA (User Vecter)
void INT_TRAPA39(void){/* sleep(); */}
// 40 TRAPA (User Vecter)
void INT_TRAPA40(void){/* sleep(); */}
// 41 TRAPA (User Vecter)
void INT_TRAPA41(void){/* sleep(); */}
// 42 TRAPA (User Vecter)
void INT_TRAPA42(void){/* sleep(); */}
// 43 TRAPA (User Vecter)
void INT_TRAPA43(void){/* sleep(); */}
// 44 TRAPA (User Vecter)
void INT_TRAPA44(void){/* sleep(); */}
// 45 TRAPA (User Vecter)
void INT_TRAPA45(void){/* sleep(); */}
// 46 TRAPA (User Vecter)
void INT_TRAPA46(void){/* sleep(); */}
// 47 TRAPA (User Vecter)
void INT_TRAPA47(void){/* sleep(); */}
// 48 TRAPA (User Vecter)
void INT_TRAPA48(void){/* sleep(); */}
// 49 TRAPA (User Vecter)
void INT_TRAPA49(void){/* sleep(); */}
// 50 TRAPA (User Vecter)
void INT_TRAPA50(void){/* sleep(); */}
// 51 TRAPA (User Vecter)
void INT_TRAPA51(void){/* sleep(); */}
// 52 TRAPA (User Vecter)
void INT_TRAPA52(void){/* sleep(); */}
// 53 TRAPA (User Vecter)
void INT_TRAPA53(void){/* sleep(); */}
// 54 TRAPA (User Vecter)
void INT_TRAPA54(void){/* sleep(); */}
// 55 TRAPA (User Vecter)
void INT_TRAPA55(void){/* sleep(); */}
// 56 TRAPA (User Vecter)
void INT_TRAPA56(void){/* sleep(); */}
// 57 TRAPA (User Vecter)
void INT_TRAPA57(void){/* sleep(); */}
// 58 TRAPA (User Vecter)
void INT_TRAPA58(void){/* sleep(); */}
// 59 TRAPA (User Vecter)
void INT_TRAPA59(void){/* sleep(); */}
// 60 TRAPA (User Vecter)
void INT_TRAPA60(void){/* sleep(); */}
// 61 TRAPA (User Vecter)
void INT_TRAPA61(void){/* sleep(); */}
// 62 TRAPA (User Vecter)
void INT_TRAPA62(void){/* sleep(); */}
// 63 TRAPA (User Vecter)
void INT_TRAPA63(void){/* sleep(); */}
// 64 Interrupt IRQ0
void INT_IRQ0(void){/* sleep(); */}
// 65 Interrupt IRQ1
void INT_IRQ1(void){/* sleep(); */}
// 66 Interrupt IRQ2
void INT_IRQ2(void){/* sleep(); */}
// 67 Interrupt IRQ3
void INT_IRQ3(void){/* sleep(); */}
// 68 Interrupt IRQ4
void INT_IRQ4(void){/* sleep(); */}
// 69 Interrupt IRQ5
void INT_IRQ5(void){/* sleep(); */}
// 70 Interrupt IRQ6
void INT_IRQ6(void){/* sleep(); */}
// 71 Interrupt IRQ7
void INT_IRQ7(void){/* sleep(); */}
// 72 Reserved

// 73 Reserved

// 74 Reserved

// 75 Reserved

// 76 Reserved

// 77 Reserved

// 78 Reserved

// 79 Reserved

// 80 Interrupt PINT0
void INT_PINT0(void){/* sleep(); */}
// 81 Interrupt PINT1
void INT_PINT1(void){/* sleep(); */}
// 82 Interrupt PINT2
void INT_PINT2(void){/* sleep(); */}
// 83 Interrupt PINT3
void INT_PINT3(void){/* sleep(); */}
// 84 Interrupt PINT4
void INT_PINT4(void){/* sleep(); */}
// 85 Interrupt PINT5
void INT_PINT5(void){/* sleep(); */}
// 86 Interrupt PINT6
void INT_PINT6(void){/* sleep(); */}
// 87 Interrupt PINT7
void INT_PINT7(void){/* sleep(); */}
// 88 Reserved

// 89 Reserved

// 90 Reserved

// 91 ROM FIFE
void INT_ROM_FIFE(void){/* sleep(); */}
// 92 A/D ADI0
void INT_AD_ADI0(void){/* sleep(); */}
// 93 Reserved

// 94 Reserved

// 95 Reserved

// 96 A/D ADI1
void INT_AD_ADI1(void){/* sleep(); */}
// 97 Reserved

// 98 Reserved

// 99 Reserved

// 100 Reserved

// 101 Reserved

// 102 Reserved

// 103 Reserved

// 104 RCANET0 ERS_0
void INT_RCANET0_ERS_0(void){/* sleep(); */}
// 105 RCANET0 OVR_0
void INT_RCANET0_OVR_0(void){/* sleep(); */}
// 106 RCANET0 RM01_0
void INT_RCANET0_RM01_0(void){/* sleep(); */}
// 107 RCANET0 SLE_0
void INT_RCANET0_SLE_0(void){/* sleep(); */}
// 108 DMAC0 DEI0
void INT_DMAC0_DEI0(void){/* sleep(); */}
// 109 DMAC0 HEI0
void INT_DMAC0_HEI0(void){/* sleep(); */}
// 110 Reserved

// 111 Reserved

// 112 DMAC1 DEI1
void INT_DMAC1_DEI1(void){/* sleep(); */}
// 113 DMAC1 HEI1
void INT_DMAC1_HEI1(void){/* sleep(); */}
// 114 Reserved

// 115 Reserved

// 116 DMAC2 DEI2
void INT_DMAC2_DEI2(void){/* sleep(); */}
// 117 DMAC2 HEI2
void INT_DMAC2_HEI2(void){/* sleep(); */}
// 118 Reserved

// 119 Reserved

// 120 DMAC3 DEI3
void INT_DMAC3_DEI3(void){/* sleep(); */}
// 121 DMAC3 HEI3
void INT_DMAC3_HEI3(void){/* sleep(); */}
// 122 Reserved

// 123 Reserved

// 124 DMAC4 DEI4
void INT_DMAC4_DEI4(void){/* sleep(); */}
// 125 DMAC4 HEI4
void INT_DMAC4_HEI4(void){/* sleep(); */}
// 126 Reserved

// 127 Reserved

// 128 DMAC5 DEI5
void INT_DMAC5_DEI5(void){/* sleep(); */}
// 129 DMAC5 HEI5
void INT_DMAC5_HEI5(void){/* sleep(); */}
// 130 Reserved

// 131 Reserved

// 132 DMAC6 DEI6
void INT_DMAC6_DEI6(void){/* sleep(); */}
// 133 DMAC6 HEI6
void INT_DMAC6_HEI6(void){/* sleep(); */}
// 134 Reserved

// 135 Reserved

// 136 DMAC7 DEI7
void INT_DMAC7_DEI7(void){/* sleep(); */}
// 137 DMAC7 HEI7
void INT_DMAC7_HEI7(void){/* sleep(); */}
// 138 Reserved

// 139 Reserved

// 140 CMT CMI0
void INT_CMT_CMI0(void){/* sleep(); */}
// 141 Reserved

// 142 Reserved

// 143 Reserved

// 144 CMT CMI1
void INT_CMT_CMI1(void){/* sleep(); */}
// 145 Reserved

// 146 Reserved

// 147 Reserved

// 148 BSC CMTI
void INT_BSC_CMTI(void){/* sleep(); */}
// 149 Reserved

// 150 USB EP4FULL
void INT_USB_EP4FULL(void){/* sleep(); */}
// 151 USB EP5EMPTY
void INT_USB_EP5EMPTY(void){/* sleep(); */}
// 152 WDT ITI
void INT_WDT_ITI(void){/* sleep(); */}
// 153 E-DMAC EINT0
void INT_EDMAC_EINT0(void){/* sleep(); */}
// 154 USB EP1FULL
void INT_USB_EP1FULL(void){/* sleep(); */}
// 155 USB EP2EMPTY
void INT_USB_EP2EMPTY(void){/* sleep(); */}
// 156 MTU2 MTU0 TGI0A
void INT_MTU2_MTU0_TGI0A(void){/* sleep(); */}
// 157 MTU2 MTU0 TGI0B
void INT_MTU2_MTU0_TGI0B(void){/* sleep(); */}
// 158 MTU2 MTU0 TGI0C
void INT_MTU2_MTU0_TGI0C(void){/* sleep(); */}
// 159 MTU2 MTU0 TGI0D
void INT_MTU2_MTU0_TGI0D(void){/* sleep(); */}
// 160 MTU2 MTU0 TGI0V
void INT_MTU2_MTU0_TGI0V(void){/* sleep(); */}
// 161 MTU2 MTU0 TGI0E
void INT_MTU2_MTU0_TGI0E(void){/* sleep(); */}
// 162 MTU2 MTU0 TGI0F
void INT_MTU2_MTU0_TGI0F(void){/* sleep(); */}
// 163 Reserved

// 164 MTU2 MTU1 TGI1A
void INT_MTU2_MTU1_TGI1A(void){/* sleep(); */}
// 165 MTU2 MTU1 TGI1B
void INT_MTU2_MTU1_TGI1B(void){/* sleep(); */}
// 166 Reserved 

// 167 Reserved

// 168 MTU2 MTU1 TGI1V
void INT_MTU2_MTU1_TGI1V(void){/* sleep(); */}
// 169 MTU2 MTU1 TGI1U
void INT_MTU2_MTU1_TGI1U(void){/* sleep(); */}
// 170 Reserved 

// 171 Reserved

// 172 MTU2 MTU2 TGI2A
void INT_MTU2_MTU2_TGI2A(void){/* sleep(); */}
// 173 MTU2 MTU2 TGI2B
void INT_MTU2_MTU2_TGI2B(void){/* sleep(); */}
// 174 Reserved 

// 175 Reserved

// 176 MTU2 MTU2 TGI2V
void INT_MTU2_MTU2_TGI2V(void){/* sleep(); */}
// 177 MTU2 MTU2 TGI2U
void INT_MTU2_MTU2_TGI2U(void){/* sleep(); */}
// 178 Reserved 

// 179 Reserved

// 180 MTU2 MTU3 TGI3A
void INT_MTU2_MTU3_TGI3A(void){/* sleep(); */}
// 181 MTU2 MTU3 TGI3B
void INT_MTU2_MTU3_TGI3B(void){/* sleep(); */}
// 182 MTU2 MTU3 TGI3C
void INT_MTU2_MTU3_TGI3C(void){/* sleep(); */}
// 183 MTU2 MTU3 TGI3D
void INT_MTU2_MTU3_TGI3D(void){/* sleep(); */}
// 184 MTU2 MTU3 TGI3V
void INT_MTU2_MTU3_TGI3V(void){/* sleep(); */}
// 185 Reserved 

// 186 Reserved

// 187 Reserved 

// 188 MTU2 MTU4 TGI4A
void INT_MTU2_MTU4_TGI4A(void){/* sleep(); */}
// 189 MTU2 MTU4 TGI4B
void INT_MTU2_MTU4_TGI4B(void){/* sleep(); */}
// 190 MTU2 MTU4 TGI4C
void INT_MTU2_MTU4_TGI4C(void){/* sleep(); */}
// 191 MTU2 MTU4 TGI4D
void INT_MTU2_MTU4_TGI4D(void){/* sleep(); */}
// 192 MTU2 MTU4 TGI4V
void INT_MTU2_MTU4_TGI4V(void){/* sleep(); */}
// 193 Reserved 

// 194 Reserved

// 195 Reserved 

// 196 MTU2 MTU5 TGI5U
void INT_MTU2_MTU5_TGI5U(void){/* sleep(); */}
// 197 MTU2 MTU5 TGI5V
void INT_MTU2_MTU5_TGI5V(void){/* sleep(); */}
// 198 MTU2 MTU5 TGI5W
void INT_MTU2_MTU5_TGI5W(void){/* sleep(); */}
// 199 Reserved 

// 200 POE2 OEI1
void INT_POE2_OEI1(void){/* sleep(); */}
// 201 POE2 OEI2 
void INT_POE2_OEI2(void){/* sleep(); */}
// 202 Reserved 

// 203 Reserved

// 204 MTU2S MTU3S TGI3A 
void INT_MTU2S_MTU3S_TGI3A(void){/* sleep(); */}
// 205 MTU2S MTU3S TGI3B
void INT_MTU2S_MTU3S_TGI3B(void){/* sleep(); */}
// 206 MTU2S MTU3S TGI3C
void INT_MTU2S_MTU3S_TGI3C(void){/* sleep(); */}
// 207 MTU2S MTU3S TGI3D 
void INT_MTU2S_MTU3S_TGI3D(void){/* sleep(); */}
// 208 MTU2S MTU3S TGI3V
void INT_MTU2S_MTU3S_TGI3V(void){/* sleep(); */}
// 209 Reserved 

// 210 Reserved 

// 211 Reserved

// 212 MTU2S MTU4S TGI4A 
void INT_MTU2S_MTU4S_TGI4A(void){/* sleep(); */}
// 213 MTU2S MTU4S TGI4B 
void INT_MTU2S_MTU4S_TGI4B(void){/* sleep(); */}
// 214 MTU2S MTU4S TGI4C 
void INT_MTU2S_MTU4S_TGI4C(void){/* sleep(); */}
// 215 MTU2S MTU4S TGI4D 
void INT_MTU2S_MTU4S_TGI4D(void){/* sleep(); */}
// 216 MTU2S MTU4S TGI4V 
void INT_MTU2S_MTU4S_TGI4V(void){/* sleep(); */}
// 217 Reserved 

// 218 Reserved

// 219 Reserved 

// 220 MTU2S MTU5S TGI5U 
void INT_MTU2S_MTU5S_TGI5U(void){/* sleep(); */}
// 221 MTU2S MTU5S TGI5V
void INT_MTU2S_MTU5S_TGI5V(void){/* sleep(); */}
// 222 MTU2S MTU5S TGI5W 
void INT_MTU2S_MTU5S_TGI5W(void){/* sleep(); */}
// 223 Reserved

// 224 POE2 OEI3
void INT_POE2_OEI3(void){/* sleep(); */}
// 225 Reserved

// 226 USB USI0
void INT_USB_USI0(void){/* sleep(); */}
// 227 USB USI1
void INT_USB_USI1(void){/* sleep(); */}
// 228 IIC3 STPI
void INT_IIC3_STPI(void){/* sleep(); */}
// 229 IIC3 NAKI 
void INT_IIC3_NAKI(void){/* sleep(); */}
// 230 IIC3 RXI 
void INT_IIC3_RXI(void){/* sleep(); */}
// 231 IIC3 TXI
void INT_IIC3_TXI(void){/* sleep(); */}
// 232 IIC3 TEI 
void INT_IIC3_TEI(void){/* sleep(); */}
// 233 RSPI SPERI
void INT_RSPI_SPERI(void){/* sleep(); */}
// 234 RSPI SPRXI
void INT_RSPI_SPRXI(void){/* sleep(); */}
// 235 RSPI SPTXI
void INT_RSPI_SPTXI(void){/* sleep(); */}
// 236 SCI SCI4 ERI4
void INT_SCI_SCI4_ERI4(void){/* sleep(); */}
// 237 SCI SCI4 RXI4
void INT_SCI_SCI4_RXI4(void){/* sleep(); */}
// 238 SCI SCI4 TXI4
void INT_SCI_SCI4_TXI4(void){/* sleep(); */}
// 239 SCI SCI4 TEI4
void INT_SCI_SCI4_TEI4(void){/* sleep(); */}
// 240 SCI SCI0 ERI0
void INT_SCI_SCI0_ERI0(void){/* sleep(); */}
// 241 SCI SCI0 RXI0
void INT_SCI_SCI0_RXI0(void){/* sleep(); */}
// 242 SCI SCI0 TXI0
void INT_SCI_SCI0_TXI0(void){/* sleep(); */}
// 243 SCI SCI0 TEI0
void INT_SCI_SCI0_TEI0(void){/* sleep(); */}
// 244 SCI SCI1 ERI1
void INT_SCI_SCI1_ERI1(void){/* sleep(); */}
// 245 SCI SCI1 RXI1
void INT_SCI_SCI1_RXI1(void){/* sleep(); */}
// 246 SCI SCI1 TXI1
void INT_SCI_SCI1_TXI1(void){/* sleep(); */}
// 247 SCI SCI1 TEI1
void INT_SCI_SCI1_TEI1(void){/* sleep(); */}
// 248 SCI SCI2 ERI2
void INT_SCI_SCI2_ERI2(void){/* sleep(); */}
// 249 SCI SCI2 RXI2
void INT_SCI_SCI2_RXI2(void){/* sleep(); */}
// 250 SCI SCI2 TXI2
void INT_SCI_SCI2_TXI2(void){/* sleep(); */}
// 251 SCI SCI2 TEI2
void INT_SCI_SCI2_TEI2(void){/* sleep(); */}
// 252 SCIF SCIF3 BRI3
void INT_SCIF_SCIF3_BRI3(void){/* sleep(); */}
// 253 SCIF SCIF3 ERI3
void INT_SCIF_SCIF3_ERI3(void){/* sleep(); */}
// 254 SCIF SCIF3 RXI3
void INT_SCIF_SCIF3_RXI3(void){/* sleep(); */}
// 255 SCIF SCIF3 TXI3
void INT_SCIF_SCIF3_TXI3(void){/* sleep(); */}
// Dummy
void Dummy(void){/* sleep(); */}

/* End of File */
