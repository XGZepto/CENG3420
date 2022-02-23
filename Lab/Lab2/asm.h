/***************************************************************/
/*                                                             */
/*                  RISCV-LC Assembler                         */
/*                                                             */
/*                     CEG3420 Lab2                            */
/*                 cbai@cse.cuhk.edu.hk                        */
/*           The Chinese University of Hong Kong               */
/*                                                             */
/***************************************************************/


#ifndef __LC_ASM_H__
#define __LC_ASM_H__


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include "util.h"


/*
 * Macros
 */
#define MAX_LABELS 255
#define MAX_LABEL_LENGTH 20
#define MAX_LINE_LENGTH 255
#define MASK11_0(x) ((x) & 0xFFF)


/*
 * RV32I instruction identifiers
 * you can check it in the function `is_opcode`
 */
enum {
    ADDI, SLLI, XORI, SRLI, SRAI, ORI, ANDI, LUI, ADD, SUB,
    SLL, XOR, SRL, SRA, OR, AND, JALR, JAL, BEQ, BNE,
    BLT, BGE, LB, LH, LW, SB, SH, SW, LA, FILL, HALT /* 31 */
};


/*
 * assembler identifiers
 */
enum {
    /* source code line idenfifiers */
    END_OF_FILE, DONE, COMMENT_LINE,
    /* type identifiers */
    LABEL, OPCODE, ARGS,
    /* label identifiers */
    INVALID_LABEL, VALID_LABEL,
    /* arguments identifiers */
    ARCH_REGS, IMM, REGS_INDIRECT_ADDR,
    /* immediate value identifiers */
    DEC, HEX,
    /* special identifiers */
    MIS_MATCH
};


/*
 * general-purpose architectural registers
 */
static const char *arch_regs[] = {
    "zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2", "t3", "t4",
    "t5", "t6", "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7",
    "s8", "s9", "s10", "s11", "fp", "a0", "a1", "a2", "a3", "a4",
    "a5", "a6", "a7", "x0", "x1", "x2", "x3", "x4", "x5", "x6",
    "x7", "x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15", "x16",
    "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26",
    "x27", "x28", "x29", "x30", "x31"
};


/*
 * encodings for general-purpose architectural registers
 */
static const int arch_regs_encode[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 28, 29,
    30, 31, 8, 9, 18, 19, 20, 21, 22, 23,
    24, 25, 26, 27, 8, 10, 11, 12, 13, 14,
    15, 16, 17, 0, 1, 2, 3, 4, 5, 6,
    7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
    17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
    27, 28, 29, 30, 31
};


/*
 * RV32I instructions
 */
static const char *opcode_table[] = {
    "addi", "slli", "xori", "srli", "srai", "ori", "andi", "lui", "add", "sub",
    "sll", "xor", "srl", "sra", "or", "and", "jalr", "jal", "beq", "bne",
    "blt", "bge", "lb", "lh", "lw", "sb", "sh", "sw", "la", ".fill", "halt" /* 31 */
};


/*
 * `struct_label_table` is the label table
 * `line_cnt` saves line no. of the source code
 * `address` saves line address of labels
 * `fill` distinguishes between a FILL definition and other labels
 * `label` saves labels' names
 * Example:
 *      struct_label_table label_table[MAX_LABELS], *p_label_table = label_table;
 *      // construct `label_table`
 *      // when p_lable_table->label == label or label names are the same
 *      // p_label_table->line_cnt saves the line no. when the label emerges.
 *      // p_label_table->address saves the address of the label. empty lines in the
 *         source code do not have addresses.
 *      // p_label_table->fill is set when the label is ".fill"
 */
typedef struct {
    int line_cnt;
    int address;
	bool fill;
    char label[MAX_LABEL_LENGTH + 1];
} struct_label_table;


/*
 * `struct_regs_indirect_addr` supports register indirect addressing
 * Example:
 *      8(t0)
 *      struct_regs_indirect_addr regs_indirect_addr;
 *      // construct `regs_inidrect_addr` with `parse_regs_indirect_addr`
 *      regs_indirect_addr->reg = "t0";
 *      regs_indirect_addr->imm = 8
 */
typedef struct {
    int imm;
    char reg[5];
} struct_regs_indirect_addr;


/*
 * LA is the only pseudo instruction translated into two instructions, i.e., lui and addi
 * to calculate addresses of labels correctly, we need to add one address offset when LA emerges
 * in the source code
 * Example:
 *      // construct `la_cnt` and `la_inst` with `calc_la`
 *      la_inst[12] = 2;
 *      // util the line 12 of the source code, LA has emerged twice
 */
int la_cnt;
int la_inst[MAX_LINE_LENGTH];


/*
 * map an architectural register to its encoding
 */
int reg_to_num(char *, int);


/*
 * given a bit width, check whether the bit width can hold the signed value
 */
int is_imm_in_range(int, int);


/*
 * map a label to its corresponding number, refer to `label_to_num`
 * or map an immediate value to its appropriate number, e.g., base conversion
 * e.g., LA instruction
 */
int handle_label_or_imm(char *, struct_label_table *, int, int);


/*
 * do the base conversion or given a bit width,
 * validate whether it can hold the immediate value
 */
int validate_imm(char *, int, int);


/*
 * get the lower 5 bits
 */
int lower5bit(char *, int);


/*
 * get the address of the label
 */
int label_to_num(char *, int, struct_label_table *, int, int);


/*
 * parse the register indirect addressing syntax
 * Example:
 *      8(t0)
 *      struct_regs_indirect_addr regs_indirect_addr;
 *      // construct `regs_inidrect_addr` with `parse_regs_indirect_addr`
 *      regs_indirect_addr->reg = "t0";
 *      regs_indirect_addr->imm = 8
 */
struct_regs_indirect_addr * parse_regs_indirect_addr(char *, int);


/*
 * handle pseudo instructions
 */
void handle_pseudo_inst(FILE *, int , int , char *, char *, char *, char *, struct_label_table *);


/*
 * translate from RV32I instructions to machine binaries
 */
int inst_to_binary(int, int, char *, char *, char *, char *, struct_label_table *);


/*
 * check whether it is a label
 */
int is_label(char *);


/*
 * check whether it is a opcode
 */
int is_opcode(char *);


/*
 * check whether it is a architectural register
 */
int is_reg(char *);


/*
 * check whether it is an immediate value
 */
int is_imm(char *);


/*
 * check whether it is a register indirect addressing
 */
int is_regs_indirect_addr(char *);


/*
 * check whether it is an argument
 */
int is_arg(char *);


/*
 * calulate number of LA instructions
 * LA is the only pseudo instruction translated into two instructions, i.e., lui and addi
 * to calculate addresses of labels correctly, we need to add one address offset when LA emerges
 * in the source code
 * refer to `la_cnt` and `la_inst`;
 */
void calc_la(FILE *);


/*
 * parse RV32I instructions
 */
int parse_inst(FILE *, char **, char **, char **, char **, char **);


/*
 * errors handler
 */
void handle_err(int, int);


/*
 * assembler main function
 */
void assemble(char *, char *);


#endif
