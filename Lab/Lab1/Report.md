# Lab 1 Report

*ZHOU, Yixiang*

*04/02/2022*

- You can find detailed comments in the code files, so I will skip explaining the expected outcome of each instruction here.
- Lab 1-1 was relatively straightforward.
- For Lab 1-2, we want to implement a function that takes an array and the position of a pivot and rearrange the elements in this array based on their magnitude to the provided pivot. I translated the provided pseudo code into RISC-V assembly, with an extra step of moving the pivot to the end of the array before the rearrangement process, preventing the tedious matter of keeping track of the changing location of the pivot itself.