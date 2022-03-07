#!/bin/bash

# /***************************************************************/
# /*                                                             */
# /*                  RISCV-LC Assembler                         */
# /*                                                             */
# /*                     CEG3420 Lab2                            */
# /*                 cbai@cse.cuhk.edu.hk                        */
# /*           The Chinese University of Hong Kong               */
# /*                                                             */
# /***************************************************************/

# set -e

root=`dirname ${BASH_SOURCE[0]}`
benchmarks=${root}/../benchmarks
asm=${root}/../asm
report=${root}/report

if [[ ! -e ${asm} ]]
then
	cd ${root}/..
	make
	cd -
fi

rm -f ${report}
for benchmark in `find ${benchmarks} -maxdepth 1 -name "*.asm"`
do
	echo ${benchmark}
	output=`basename ${benchmark}`
	output=${output%.*}.bin
	${asm} ${benchmark} ${output}
	echo -e "validating ${output}...\n" >> ${report}
	diff ${benchmark%.*}.bin ${output} >> ${report}
done

result=`wc -l ${report}`
if [[ `wc -l ${report}` == "6 ./report" ]]
then
	echo -e "[INFO]: You have passed the Lab.\n"
else
	echo -e "[ERROR]: You have failed the Lab.\n"
fi
