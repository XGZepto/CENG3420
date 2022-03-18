# CENG3420 Midterm

*ZHOU, Yixiang*

*SID: 1155157100*

**Remarks:** `NUM_1 = 10` , `NUM_2 = NUM_3 = 100`

## Q1

1. ```assembly
   xor	a2, a0, a1
   # a2 = 0x66
   ori a2, a2, 2
   # a2 = 0x66
   ```

2. ```assembly
   slli	a2, a0, 2
   # a2 = 0x2E8
   andi	a2, a2, 0x1E
   # a2 = 8
   ```

## Q2

1. ```c
   	f = f + 1;
   	c = e << 2;
   	if (a >= c){
   		d = b * c;
   	} else {
   		d = b + c;
       }
   	d = d - 100;
   ```

2. **The Reason**: When pipelined, `ALU` stage of `bge` needs to have access to the value stored in `t2`, which needs to be written back in the previous instruction (without forwarding), hence the stall.

   **The Fix**:

   - We can move `slli` up to be the first instruction, or
   - we can add forwarding.

## Q3

1. Find the yield of this wafer.

   $$\begin{align*}\text{Wafer area } &= \pi \cdot 10^2 \text{cm}^2 \\ \text{Die area} &= \text{Wafer area} / \text{Dies per wafer} \\ &= \pi \text{cm}^2 \\ \text{Yield} &= \frac{1}{[1+(\text{Defects per area} \cdot \text{Die area}/2)]^2} \\ &= 94.00\% \end{align*}$$

2. Find the cost per die for this wafer.

   $$\text{Cost per die} = \frac{\text{Cost per wafer}}{\text{Dies per wafer} \cdot \text{Yield}} = 1.0638$$

## Q4

1. What's the meaning of the last four instructions?

   ```assembly
   addi	x12, x30, 8
   # x12 = &A[f+2]
   lw		x30, 0(x12)
   # load the value of A[f+2] into x30
   sub		x30, x30, x5
   # x30 = x30 - x5
   # or we could say x30 = A[f+2] - A[f]
   sw		x30, 0(x31)
   # save the value in x30 to the address indicated by x31
   # B[g] = A[f+2] - A[f]
   ```

2. What is the corresponding C statement?

   ```
   B[g] = A[f+2] - A[f]
   ```

## Q5

```
	4.36525 x 10^1 = 43.6525 = 2^5 x 1.364140625
	1.364140625	1 (hidden)
	0.72828125	0
	1.4565625	1
	0.913125	0
	1.82625		1
	1.6525		1
	1.305		1
	0.61		0
    1.22		1
    0.44		0
    0.88		0
    ...
    The bit pattern is as follows.
    0 10100 0101110100
```

## Q6

1. Find all data dependences in this instruction sequence.

   ```assembly
   sub	a2, a1, a3		(1)
   and	a12, a2, a5		(2)
   or	a13, a6, a2		(3)
   add	a14, a2, a2		(4)
   sd	a15, 100(a2)	(5)
   ```

   (2) -> (1); (3) -> (1); (4) -> (1); (5) -> (1)

2. As followings.

   (2) -> (1): 1a

   (3) -> (1): 1b

   (4) -> (1): 1a/1b

   (5) -> (1): 1a

3. Flush.

## Q7

In both CPUs, a conditional branch instruction takes 2 clock cycles, while all other instructions take 1 clock cycle. For CPUA, branch instructions account for 20% of the executed instructions and since a comparison instruction is required before each branch instruction, the comparison instruction also accounts for 20%. For CPUB, no comparison instruction is needed since the comparison process is already included in the branch instruction. And assume the clock cycle time of CPUB is 1.25 times the clock cycle time of CPUA, which
is clock_cycleB = 1.25 × clock_cycleA.

1. **Which CPU is faster?**

   Suppose $CPU_A$ executes $N$ instructions.

   => total clock_cycleA = 0.4N + 0.8N = 1.2N

   $CPU_B$ would then executes $0.8N$ instructions with $0.2N$ branches.

   => total clock_cyclesB = 0.4N + 0.6N = N

   => *converted into clock_cycleA* = 1.25N

   Hence, $CPU_A$ is faster.

2. **If $\text{CPU}_\text{B}$'s clock cycle time is only 1.1 times that of $\text{CPU}_\text{A}$, which $\text{CPU}$** is faster?

   $CPU_B$ cycles converted into clock_cyclesA = 1.1N

   Hence, $CPU_B$ is faster.

## Q8

1. What is the accuracy of always-taken and always-not-taken predictors for this sequence of branch outcomes?

   | always-taken        | always-not-taken    |
   | ------------------- | ------------------- |
   | $\dfrac{2}{5}=40\%$ | $\dfrac{3}{5}=60\%$ |

2. What is the accuracy of the 2-bit predictor if this pattern is repeated forever, assuming that the predictor starts off from State **3** of the FSM?

   | No.  | State | Prediction | Branch Outcome |
   | ---- | ----- | ---------- | -------------- |
   | 1    | 3     | Not Taken  | Not Taken      |
   | 2    | 3     | Not Taken  | Not Taken      |
   | 3    | 3     | Not Taken  | Taken          |
   | 4    | 4     | Not Taken  | Taken          |
   | 5    | 1     | Taken      | Not Taken      |
   | 6    | 2     | Taken      | Not Taken      |
   | 7    | 3     | Not Taken  | Not Taken      |
   | 8    | 3     | Not Taken  | Taken          |
   | 9    | 4     | Not Taken  | Taken          |
   | 10   | 1     | Taken      | Not Taken      |

   The 2-bit predictor goes on a loop of length 5 after the 5th time, with the accuracy of $20\%$.

## Q9

**This exercise examines memory module interleaving. To transfer a 8-byte block, assume it takes one clock to send address to DRAM memory and one clock to send data back. DRAM has 5 cycle latency for first byte, and 3 cycles for each of subsequent bytes in the block.**

1. **What is the total cycle number if we use a non-interleaved system? Please draw the diagram to illustrate the calculation.**

   ```
   |-1-|------5------|-1-|
                 |-1-|---3---|-1-|
                     |-1-|---3---|-1-|
                     		.......
                     			|-1-|---3---|-1-|
   ```

   We need $1 + 5 + 3 \times 7 + 1 = 29$ cycles.

2. **How many interleaved modules (banks) do we need in minimal if we want to reduce the total cycle number to ≤ 50% of the cycle number in a non-interleaved system? Please draw the diagram to illustrate the calculation.**

   ```
   A	|-1-|------5------|-1-|
   B	    |-1-|------5------|-1-|
   A    	          |-1-|---3---|-1-|
   B        	          |-1-|---3---|-1-|
   A						  |-1-|---3---|-1-|
               	          ...
                   	          |-1-|---3---|-1-|
                         
   ```

   With $2$ modules, we need $1 + 5 + 8 = 14$ cycles, which already satisfies the condition.

3. **Please explain the main idea of interleaving.**

   We use multiple memory modules to store data with each module containing its own ABR and DBR. Hence, instead of sequencially read words in a module, we can access data parallelly across modules without the need to wait due to latency.

4. **Does interleaving takes advantages of spatial locality or temporal locality?**

   Spatial Locality. We might access consecutive words, so it is faster to distributed them into different modules through interleaving.

5. **From your opinion, what’s the difference against using multiple main memory cards?**

   Interleaving provides the interface of one memory set, meaning the operating system only needs to manage one domain of memory addresses; while with multiple main memory cards, the CPU communicates with multiple controllers and the operating systems needs to manage different addresses across devices.

