#ifndef OPCODES_H
#define OPCODES_H

// move immediate 32-bit
#define OP_MOV_R0_IMM32         0x0001
#define OP_MOV_R1_IMM32         0x0011
#define OP_MOV_R2_IMM32         0x0021
#define OP_MOV_R3_IMM32         0x0031
#define OP_MOV_R4_IMM32         0x0041
#define OP_MOV_R5_IMM32         0x0051
#define OP_MOV_R6_IMM32         0x0061
#define OP_MOV_R7_IMM32         0x0071
#define OP_MOV_R8_IMM32         0x0081
#define OP_MOV_R9_IMM32         0x0091
#define OP_MOV_R10_IMM32        0x00A1
#define OP_MOV_R11_IMM32        0x00B1
#define OP_MOV_R12_IMM32        0x00C1
#define OP_MOV_R13_IMM32        0x00D1
#define OP_MOV_R14_IMM32        0x00E1
#define OP_MOV_R15_IMM32        0x00F1

// move immediate 16-bit
#define OP_MOV_R0_IMM16         0x0002
#define OP_MOV_R1_IMM16         0x0012
#define OP_MOV_R2_IMM16         0x0022
#define OP_MOV_R3_IMM16         0x0032
#define OP_MOV_R4_IMM16         0x0042
#define OP_MOV_R5_IMM16         0x0052
#define OP_MOV_R6_IMM16         0x0062
#define OP_MOV_R7_IMM16         0x0072
#define OP_MOV_R8_IMM16         0x0082
#define OP_MOV_R9_IMM16         0x0092
#define OP_MOV_R10_IMM16        0x00A2
#define OP_MOV_R11_IMM16        0x00B2
#define OP_MOV_R12_IMM16        0x00C2
#define OP_MOV_R13_IMM16        0x00D2
#define OP_MOV_R14_IMM16        0x00E2
#define OP_MOV_R15_IMM16        0x00F2

// move immediate 8-bit
#define OP_MOV_R0_IMM8          0x0003
#define OP_MOV_R1_IMM8          0x0013
#define OP_MOV_R2_IMM8          0x0023
#define OP_MOV_R3_IMM8          0x0033
#define OP_MOV_R4_IMM8          0x0043
#define OP_MOV_R5_IMM8          0x0053
#define OP_MOV_R6_IMM8          0x0063
#define OP_MOV_R7_IMM8          0x0073
#define OP_MOV_R8_IMM8          0x0083
#define OP_MOV_R9_IMM8          0x0093
#define OP_MOV_R10_IMM8         0x00A3
#define OP_MOV_R11_IMM8         0x00B3
#define OP_MOV_R12_IMM8         0x00C3
#define OP_MOV_R13_IMM8         0x00D3
#define OP_MOV_R14_IMM8         0x00E3
#define OP_MOV_R15_IMM8         0x00F3

// move immediate float
#define OP_MOV_RF0_IMM          0x00FC
#define OP_MOV_RF1_IMM          0x00FD
#define OP_MOV_RF2_IMM          0x00FE
#define OP_MOV_RF3_IMM          0x00FF

// integer register to register move
#define OP_MOV_R0_R1            0x0110
#define OP_MOV_R0_R2            0x0120
#define OP_MOV_R0_R3            0x0130
#define OP_MOV_R0_R4            0x0140
#define OP_MOV_R0_R5            0x0150
#define OP_MOV_R0_R6            0x0160
#define OP_MOV_R0_R7            0x0170
#define OP_MOV_R0_R8            0x0180
#define OP_MOV_R0_R9            0x0190
#define OP_MOV_R0_R10           0x01A0
#define OP_MOV_R0_R11           0x01B0
#define OP_MOV_R0_R12           0x01C0
#define OP_MOV_R0_R13           0x01D0
#define OP_MOV_R0_R14           0x01E0
#define OP_MOV_R0_R15           0x01F0

#define OP_MOV_R1_R0            0x0101
#define OP_MOV_R1_R2            0x0121
#define OP_MOV_R1_R3            0x0131
#define OP_MOV_R1_R4            0x0141
#define OP_MOV_R1_R5            0x0151
#define OP_MOV_R1_R6            0x0161
#define OP_MOV_R1_R7            0x0171
#define OP_MOV_R1_R8            0x0181
#define OP_MOV_R1_R9            0x0191
#define OP_MOV_R1_R10           0x01A1
#define OP_MOV_R1_R11           0x01B1
#define OP_MOV_R1_R12           0x01C1
#define OP_MOV_R1_R13           0x01D1
#define OP_MOV_R1_R14           0x01E1
#define OP_MOV_R1_R15           0x01F1

#define OP_MOV_R2_R0            0x0102
#define OP_MOV_R2_R1            0x0112
#define OP_MOV_R2_R3            0x0132
#define OP_MOV_R2_R4            0x0142
#define OP_MOV_R2_R5            0x0152
#define OP_MOV_R2_R6            0x0162
#define OP_MOV_R2_R7            0x0172
#define OP_MOV_R2_R8            0x0182
#define OP_MOV_R2_R9            0x0192
#define OP_MOV_R2_R10           0x01A2
#define OP_MOV_R2_R11           0x01B2
#define OP_MOV_R2_R12           0x01C2
#define OP_MOV_R2_R13           0x01D2
#define OP_MOV_R2_R14           0x01E2
#define OP_MOV_R2_R15           0x01F2

#define OP_MOV_R3_R0            0x0103
#define OP_MOV_R3_R1            0x0113
#define OP_MOV_R3_R2            0x0123
#define OP_MOV_R3_R4            0x0143
#define OP_MOV_R3_R5            0x0153
#define OP_MOV_R3_R6            0x0163
#define OP_MOV_R3_R7            0x0173
#define OP_MOV_R3_R8            0x0183
#define OP_MOV_R3_R9            0x0193
#define OP_MOV_R3_R10           0x01A3
#define OP_MOV_R3_R11           0x01B3
#define OP_MOV_R3_R12           0x01C3
#define OP_MOV_R3_R13           0x01D3
#define OP_MOV_R3_R14           0x01E3
#define OP_MOV_R3_R15           0x01F3

#define OP_MOV_R4_R0            0x0104
#define OP_MOV_R4_R1            0x0114
#define OP_MOV_R4_R2            0x0124
#define OP_MOV_R4_R3            0x0134
#define OP_MOV_R4_R5            0x0154
#define OP_MOV_R4_R6            0x0164
#define OP_MOV_R4_R7            0x0174
#define OP_MOV_R4_R8            0x0184
#define OP_MOV_R4_R9            0x0194
#define OP_MOV_R4_R10           0x01A4
#define OP_MOV_R4_R11           0x01B4
#define OP_MOV_R4_R12           0x01C4
#define OP_MOV_R4_R13           0x01D4
#define OP_MOV_R4_R14           0x01E4
#define OP_MOV_R4_R15           0x01F4

#define OP_MOV_R5_R0            0x0105
#define OP_MOV_R5_R1            0x0115
#define OP_MOV_R5_R2            0x0125
#define OP_MOV_R5_R3            0x0135
#define OP_MOV_R5_R4            0x0145
#define OP_MOV_R5_R6            0x0165
#define OP_MOV_R5_R7            0x0175
#define OP_MOV_R5_R8            0x0185
#define OP_MOV_R5_R9            0x0195
#define OP_MOV_R5_R10           0x01A5
#define OP_MOV_R5_R11           0x01B5
#define OP_MOV_R5_R12           0x01C5
#define OP_MOV_R5_R13           0x01D5
#define OP_MOV_R5_R14           0x01E5
#define OP_MOV_R5_R15           0x01F5

#define OP_MOV_R6_R0            0x0106
#define OP_MOV_R6_R1            0x0116
#define OP_MOV_R6_R2            0x0126
#define OP_MOV_R6_R3            0x0136
#define OP_MOV_R6_R4            0x0146
#define OP_MOV_R6_R5            0x0156
#define OP_MOV_R6_R7            0x0176
#define OP_MOV_R6_R8            0x0186
#define OP_MOV_R6_R9            0x0196
#define OP_MOV_R6_R10           0x01A6
#define OP_MOV_R6_R11           0x01B6
#define OP_MOV_R6_R12           0x01C6
#define OP_MOV_R6_R13           0x01D6
#define OP_MOV_R6_R14           0x01E6
#define OP_MOV_R6_R15           0x01F6

#define OP_MOV_R7_R0            0x0107
#define OP_MOV_R7_R1            0x0117
#define OP_MOV_R7_R2            0x0127
#define OP_MOV_R7_R3            0x0137
#define OP_MOV_R7_R4            0x0147
#define OP_MOV_R7_R5            0x0157
#define OP_MOV_R7_R6            0x0167
#define OP_MOV_R7_R8            0x0187
#define OP_MOV_R7_R9            0x0197
#define OP_MOV_R7_R10           0x01A7
#define OP_MOV_R7_R11           0x01B7
#define OP_MOV_R7_R12           0x01C7
#define OP_MOV_R7_R13           0x01D7
#define OP_MOV_R7_R14           0x01E7
#define OP_MOV_R7_R15           0x01F7

#define OP_MOV_R8_R0            0x0108
#define OP_MOV_R8_R1            0x0118
#define OP_MOV_R8_R2            0x0128
#define OP_MOV_R8_R3            0x0138
#define OP_MOV_R8_R4            0x0148
#define OP_MOV_R8_R5            0x0158
#define OP_MOV_R8_R6            0x0168
#define OP_MOV_R8_R7            0x0178
#define OP_MOV_R8_R9            0x0198
#define OP_MOV_R8_R10           0x01A8
#define OP_MOV_R8_R11           0x01B8
#define OP_MOV_R8_R12           0x01C8
#define OP_MOV_R8_R13           0x01D8
#define OP_MOV_R8_R14           0x01E8
#define OP_MOV_R8_R15           0x01F8

#define OP_MOV_R9_R0            0x0109
#define OP_MOV_R9_R1            0x0119
#define OP_MOV_R9_R2            0x0129
#define OP_MOV_R9_R3            0x0139
#define OP_MOV_R9_R4            0x0149
#define OP_MOV_R9_R5            0x0159
#define OP_MOV_R9_R6            0x0169
#define OP_MOV_R9_R7            0x0179
#define OP_MOV_R9_R8            0x0189
#define OP_MOV_R9_R10           0x01A9
#define OP_MOV_R9_R11           0x01B9
#define OP_MOV_R9_R12           0x01C9
#define OP_MOV_R9_R13           0x01D9
#define OP_MOV_R9_R14           0x01E9
#define OP_MOV_R9_R15           0x01F9

#define OP_MOV_R10_R0           0x010A
#define OP_MOV_R10_R1           0x011A
#define OP_MOV_R10_R2           0x012A
#define OP_MOV_R10_R3           0x013A
#define OP_MOV_R10_R4           0x014A
#define OP_MOV_R10_R5           0x015A
#define OP_MOV_R10_R6           0x016A
#define OP_MOV_R10_R7           0x017A
#define OP_MOV_R10_R8           0x018A
#define OP_MOV_R10_R9           0x019A
#define OP_MOV_R10_R11          0x01BA
#define OP_MOV_R10_R12          0x01CA
#define OP_MOV_R10_R13          0x01DA
#define OP_MOV_R10_R14          0x01EA
#define OP_MOV_R10_R15          0x01FA

#define OP_MOV_R11_R0           0x010B
#define OP_MOV_R11_R1           0x011B
#define OP_MOV_R11_R2           0x012B
#define OP_MOV_R11_R3           0x013B
#define OP_MOV_R11_R4           0x014B
#define OP_MOV_R11_R5           0x015B
#define OP_MOV_R11_R6           0x016B
#define OP_MOV_R11_R7           0x017B
#define OP_MOV_R11_R8           0x018B
#define OP_MOV_R11_R9           0x019B
#define OP_MOV_R11_R10          0x01AB
#define OP_MOV_R11_R12          0x01CB
#define OP_MOV_R11_R13          0x01DB
#define OP_MOV_R11_R14          0x01EB
#define OP_MOV_R11_R15          0x01FB

#define OP_MOV_R12_R0           0x010C
#define OP_MOV_R12_R1           0x011C
#define OP_MOV_R12_R2           0x012C
#define OP_MOV_R12_R3           0x013C
#define OP_MOV_R12_R4           0x014C
#define OP_MOV_R12_R5           0x015C
#define OP_MOV_R12_R6           0x016C
#define OP_MOV_R12_R7           0x017C
#define OP_MOV_R12_R8           0x018C
#define OP_MOV_R12_R9           0x019C
#define OP_MOV_R12_R10          0x01AC
#define OP_MOV_R12_R11          0x01BC
#define OP_MOV_R12_R13          0x01DC
#define OP_MOV_R12_R14          0x01EC
#define OP_MOV_R12_R15          0x01FC

#define OP_MOV_R13_R0           0x010D
#define OP_MOV_R13_R1           0x011D
#define OP_MOV_R13_R2           0x012D
#define OP_MOV_R13_R3           0x013D
#define OP_MOV_R13_R4           0x014D
#define OP_MOV_R13_R5           0x015D
#define OP_MOV_R13_R6           0x016D
#define OP_MOV_R13_R7           0x017D
#define OP_MOV_R13_R8           0x018D
#define OP_MOV_R13_R9           0x019D
#define OP_MOV_R13_R10          0x01AD
#define OP_MOV_R13_R11          0x01BD
#define OP_MOV_R13_R12          0x01CD
#define OP_MOV_R13_R14          0x01ED
#define OP_MOV_R13_R15          0x01FD

#define OP_MOV_R14_R0           0x010E
#define OP_MOV_R14_R1           0x011E
#define OP_MOV_R14_R2           0x012E
#define OP_MOV_R14_R3           0x013E
#define OP_MOV_R14_R4           0x014E
#define OP_MOV_R14_R5           0x015E
#define OP_MOV_R14_R6           0x016E
#define OP_MOV_R14_R7           0x017E
#define OP_MOV_R14_R8           0x018E
#define OP_MOV_R14_R9           0x019E
#define OP_MOV_R14_R10          0x01AE
#define OP_MOV_R14_R11          0x01BE
#define OP_MOV_R14_R12          0x01CE
#define OP_MOV_R14_R13          0x01DE
#define OP_MOV_R14_R15          0x01FE

#define OP_MOV_R15_R0           0x010F
#define OP_MOV_R15_R1           0x011F
#define OP_MOV_R15_R2           0x012F
#define OP_MOV_R15_R3           0x013F
#define OP_MOV_R15_R4           0x014F
#define OP_MOV_R15_R5           0x015F
#define OP_MOV_R15_R6           0x016F
#define OP_MOV_R15_R7           0x017F
#define OP_MOV_R15_R8           0x018F
#define OP_MOV_R15_R9           0x019F
#define OP_MOV_R15_R10          0x01AF
#define OP_MOV_R15_R11          0x01BF
#define OP_MOV_R15_R12          0x01CF
#define OP_MOV_R15_R13          0x01DF
#define OP_MOV_R15_R14          0x01EF

// float register to register copy
#define OP_MOV_RF0_RF1          0x0014
#define OP_MOV_RF0_RF2          0x0024
#define OP_MOV_RF0_RF3          0x0034

#define OP_MOV_RF1_RF0          0x0005
#define OP_MOV_RF1_RF2          0x0025
#define OP_MOV_RF1_RF3          0x0035

#define OP_MOV_RF2_RF0          0x0006
#define OP_MOV_RF2_RF1          0x0016
#define OP_MOV_RF2_RF3          0x0036

#define OP_MOV_RF3_RF0          0x0007
#define OP_MOV_RF3_RF1          0x0017
#define OP_MOV_RF3_RF2          0x0027

// move register to stack pointer
#define OP_MOV_SP_R0            0x0008
#define OP_MOV_SP_R1            0x0018
#define OP_MOV_SP_R2            0x0028
#define OP_MOV_SP_R3            0x0038
#define OP_MOV_SP_R4            0x0048
#define OP_MOV_SP_R5            0x0058
#define OP_MOV_SP_R6            0x0068
#define OP_MOV_SP_R7            0x0078
#define OP_MOV_SP_R8            0x0088
#define OP_MOV_SP_R9            0x0098
#define OP_MOV_SP_R10           0x00A8
#define OP_MOV_SP_R11           0x00B8
#define OP_MOV_SP_R12           0x00C8
#define OP_MOV_SP_R13           0x00D8
#define OP_MOV_SP_R14           0x00E8
#define OP_MOV_SP_R15           0x00F8

#define OP_MOV_BP_R0            0x0009
#define OP_MOV_BP_R1            0x0019
#define OP_MOV_BP_R2            0x0029
#define OP_MOV_BP_R3            0x0039
#define OP_MOV_BP_R4            0x0049
#define OP_MOV_BP_R5            0x0059
#define OP_MOV_BP_R6            0x0069
#define OP_MOV_BP_R7            0x0079
#define OP_MOV_BP_R8            0x0089
#define OP_MOV_BP_R9            0x0099
#define OP_MOV_BP_R10           0x00A9
#define OP_MOV_BP_R11           0x00B9
#define OP_MOV_BP_R12           0x00C9
#define OP_MOV_BP_R13           0x00D9
#define OP_MOV_BP_R14           0x00E9
#define OP_MOV_BP_R15           0x00F9

// move stack pointer to register
#define OP_MOV_R0_SP            0x000A
#define OP_MOV_R1_SP            0x001A
#define OP_MOV_R2_SP            0x002A
#define OP_MOV_R3_SP            0x003A
#define OP_MOV_R4_SP            0x004A
#define OP_MOV_R5_SP            0x005A
#define OP_MOV_R6_SP            0x006A
#define OP_MOV_R7_SP            0x007A
#define OP_MOV_R8_SP            0x008A
#define OP_MOV_R9_SP            0x009A
#define OP_MOV_R10_SP           0x00AA
#define OP_MOV_R11_SP           0x00BA
#define OP_MOV_R12_SP           0x00CA
#define OP_MOV_R13_SP           0x00DA
#define OP_MOV_R14_SP           0x00EA
#define OP_MOV_R15_SP           0x00FA

// move base pointer to address
#define OP_MOV_R0_BP            0x000B
#define OP_MOV_R1_BP            0x001B
#define OP_MOV_R2_BP            0x002B
#define OP_MOV_R3_BP            0x003B
#define OP_MOV_R4_BP            0x004B
#define OP_MOV_R5_BP            0x005B
#define OP_MOV_R6_BP            0x006B
#define OP_MOV_R7_BP            0x007B
#define OP_MOV_R8_BP            0x008B
#define OP_MOV_R9_BP            0x009B
#define OP_MOV_R10_BP           0x00AB
#define OP_MOV_R11_BP           0x00BB
#define OP_MOV_R12_BP           0x00CB
#define OP_MOV_R13_BP           0x00DB
#define OP_MOV_R14_BP           0x00EB
#define OP_MOV_R15_BP           0x00FB

// move immediate to pointers
#define OP_MOV_SP_IMM32         0x00F6
#define OP_MOV_BP_IMM32         0x00F7

#define OP_HALT                 0xFFFF

#endif // OPCODES_H