# CENG3420 Homework 3

*ZHOU, Yixiang*

*09/03/2022*



## Q1

1. **By how much must we reduce the CPI of L/S instructions if we want the program to run two times faster?**

   We have the total clock cycles as follows:

   $$\text{Clock cycles} = \sum_{\text{instr. type}} \text{CPI} \times \text{No. instr.} = 512 \times 10^6$$.

   $$\text{T}_\text{CPU} = \frac{\text{Clock cycles}}{\text{Clock rate}} = 0.256\text{s}$$

   In order to have the program running faster without changing the clock rate, we have reduce the clock cycles needed to half the original.

   $$\begin{align*}\text{New Clock cycles} &= \text{CPI}_\text{FP} \times \text{No. FP instr.} \\ &+ \text{CPI}_\text{INT} \times \text{No. INT instr.} \\ &+\text{CPI}_\text{branch} \times \text{No. branch instr.} \\ &+\text{New CPI}_\text{L/S} \times \text{No. L/S instr.} = 256 \times 10^6 \end{align*}$$

   $$\Rightarrow \text{New CPI}_\text{L/S} = 0.8$$

2. **By how much is the execution time of the program improved if the CPI of INT and FP instructions is reduced by 40% and the CPI of L/S and Branch is reduced by 30%?**

   We have the new total clock cycles as follows:

   $$\text{New Clock cycles} = \sum_{\text{instr. type}} \text{New CPI} \times \text{No. instr.} = 352 \times 10^6$$.

   $$\text{improved T}_\text{CPU} = 0.176\text{s}$$

   The improvement over the original time is $0.08\text{s}$.

   

## Q2

1. **What is the clock cycle time in a pipelined and non-pipelined processor?**

   $$\begin{align*} \text{Pipelined} &= 350\text{ps} \ \text{(determined by the slowest stage)} \\ \text{Non-Pipelined} &= \sum\text{All Stages} = 1250 \text{ps}\end{align*}$$

2. **What is the total latency of an ``lw`` instruction in a pipelined and non-pipelined processor? Assuming there is no data hazard.**

   $$\begin{align*} \text{Pipelined} &= 5 \times 350\text{ps} = 1750\text{ps} \\ \text{Non-Pipelined} &= \sum\text{All Stages} = 1250 \text{ps}\end{align*}$$

   

## Q3

1. **If there is no forwarding, draw a pipeline diagram to show where to insert NOPs to ensure correct execution.**

   | cycle   | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 10   | 11   |
   | ------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
   | ``add`` | IM   | Reg  | ALU  | DM   | Reg  |      |      |      |      |      |      |
   | ``nop`` |      |      |      |      |      |      |      |      |      |      |      |
   | ``nop`` |      |      |      |      |      |      |      |      |      |      |      |
   | ``lw``  |      |      |      | IM   | Reg  | ALU  | DM   | Reg  |      |      |      |
   | ``nop`` |      |      |      |      |      |      |      |      |      |      |      |
   | ``nop`` |      |      |      |      |      |      |      |      |      |      |      |
   | ``or``  |      |      |      |      |      |      | IM   | Reg  | ALU  | DM   | Reg  |

   

2. **If there is forwarding, draw a pipeline diagram with forwarding to ensure correct execution. You can insert NOPs if necessary.**

   Remarks: the forwardings are marked with **Carets (^)**.

   | cycle   | 1    | 2    | 3    | 4    | 5    | 6     | 7    | 8    |
   | ------- | ---- | ---- | ---- | ---- | ---- | ----- | ---- | ---- |
   | ``add`` | IM   | Reg  | ALU^ | DM   | Reg  |       |      |      |
   | ``lw `` |      | IM   | Reg  | ^ALU | DM^^ | Reg   |      |      |
   | ``nop`` |      |      |      |      |      |       |      |      |
   | ``or `` |      |      |      | IM   | Reg  | ^^ALU | DM   | Reg  |

   | Forwardings                                                  |
   | ------------------------------------------------------------ |
   | ^: the output of ALU, which is ``x15``, is forwarded as the input to calculate ``4(x15)`` in the next instruction. |
   | ^^: the output of DM, which is ``x13``, is forwarded to ALU as the input in the next instruction. |



## Q4

1. **What is the accuracy of always-taken and always-not-taken predictors for this sequence of branch outcomes?**

   | always-taken        | always-not-taken    |
   | ------------------- | ------------------- |
   | $\dfrac{3}{5}=60\%$ | $\dfrac{2}{5}=40\%$ |

2. **What is the accuracy of the 2-bit predictor if this pattern is repeated forever, assuming that the predictor starts off in the top right state of the FSM on slide page 36, lec12?**

   | No.  | Prediction    | Branch Outcomes | Correctness |
   | ---- | ------------- | --------------- | ----------- |
   | 1    | T (top right) | T               | C           |
   | 2    | T (top left)  | NT              | I           |
   | 3    | T (top right) | T               | C           |
   | 4    | T (top left)  | T               | C           |
   | 5    | T (top left)  | NT              | I           |
   | 6    | T (top right) | T               | C           |

   The 2-bit predictor goes on a loop of length 5 after the 5th time, always giving T prediction.

   The accuracy is $\dfrac{3}{5}=60\%$.

   

## Q5

1. **Which variable references exhibit temporal locality?**

   ``I, J, and B[I][0]``

2. **Which variable references exhibit spatial locality?**

   ``A[I][J]``

3. **Which variable references exhibit temporal locality in the Matlab version?**

   ``I, J, and B(I,0)``

4. **Which variable references exhibit spatial locality in the Matlab version?**

   ``B(I,0) and A(J,I)``

   

## Q6

**How many total bits are required for a direct-mapped cache with 8 KiB of data and four-word blocks, assuming a 32-bit address?**

We have ``8 KiB`` data that is ``2048`` words, therefore there are ``512`` blocks with the block size being ``4``, where each block contains ``128`` bits of data plus a tag.

We need ``9`` bits to index ``512`` blocks and ``2`` bits for the word within a block, hence the total bits are:

$$2^9 \times (2^2 \times 32 + (32 - 9- 2 - 2) + 1) = 75,776$$.

