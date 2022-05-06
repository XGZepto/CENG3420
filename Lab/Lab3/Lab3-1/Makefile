# /***************************************************************/
# /*                                                             */
# /*                  RISCV-LC Simulator                         */
# /*                                                             */
# /*                     CEG3420 Lab3                            */
# /*                 cbai@cse.cuhk.edu.hk                        */
# /*           The Chinese University of Hong Kong               */
# /*                                                             */
# /***************************************************************/

OS := $(shell uname -s)
SRC := $(shell find . -name "*.c")
TGT := riscv-lc
OPT := -Wall -std=c99 -Wno-return-type -O3

.default: all

all: $(TGT)

$(TGT): $(SRC)
	$(CC) $(OPT) $^ -o $@

.PHONY: clean
clean:
	rm -f $(TGT)
