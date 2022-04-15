# CENG3420 Homework 4

*ZHOU, Yixiang*

*14/03/2022*

## Q1

| **Cache id** | $m$  | $C$  | $B$  | $E$  | $S$  | $t$  | $s$  | $b$  |
| :----------: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
|      1.      |  32  | 1024 |  4   |  1   | 256  |  22  |  8   |  2   |
|      2.      |  32  | 1024 |  8   |  4   |  32  |  24  |  5   |  3   |
|      3.      |  32  | 1024 |  32  |  32  |  1   |  27  |  0   |  5   |

## Q2

1. How many blocks can the cache store?

   The cache can store $\dfrac{16\text{K}}{32}=512$ blocks.

   Each block contains eight 4-byte words.

2. Assuming the cache uses **direct-mapping**, how many bits are there in each of the Tag, Block, and Byte offset fields of the address.

   | Tag  | Block | Byte offset |
   | :--: | :---: | :---------: |
   |  18  |   9   |      2      |

   

3. Assuming the cache uses **2-way set associative mapping**, how many bits are there in each of the Tag, Set, and Byte offset fields fields of the address.

   | Tag  | Set  | Byte offset |
   | :--: | :--: | :---------: |
   |  19  |  8   |      2      |

4. **Direct mapping**

   (a) "0, 4, 0, 4, 0, 4, 0, 4"

   0 and 4 are mapped to the same block; each time block tag is different.

   **The hit rate is 0%.**

   (b) “0, 3, 0, 3, 0, 3, 0, 3”

   0 is mapped to ID 0 while 3 is mapped to ID 3; cache hits apart from first two references.

   **The hit rate is 75%.**

   **$2$-way set associate mapping**

   (a) "0, 4, 0, 4, 0, 4, 0, 4"

   0 and 4 are mapped to the same set with 2 tags available; cache hits apart from first two references.

   **The hit rate is 75%.**

   (b) “0, 3, 0, 3, 0, 3, 0, 3”

   0 and 3 are mapped to different sets; cache hits apart from first two references.

   **The hit rate is 75%.**

## Q3

1. **A block=2, 4-way cache with the LRU replacement.**

   ![image-20220415225325812](C:\Users\zepto\AppData\Roaming\Typora\typora-user-images\image-20220415225325812.png)

   ![image-20220415225337881](C:\Users\zepto\AppData\Roaming\Typora\typora-user-images\image-20220415225337881.png)

   ![image-20220415225345516](C:\Users\zepto\AppData\Roaming\Typora\typora-user-images\image-20220415225345516.png)

2. **A block=4, 2-way cache with the FIFO replacement.**

   ![image-20220415230417561](C:\Users\zepto\AppData\Roaming\Typora\typora-user-images\image-20220415230417561.png)

   ![image-20220415230421068](C:\Users\zepto\AppData\Roaming\Typora\typora-user-images\image-20220415230421068.png)



<div class="page-break"></div>

## Q4

Suppose we have $H$ hits and $M$ misses,

$$\left\{\begin{align*} H + 2M &= 2000\\ M &= 50 \end{align*}\right. \Rightarrow H = 1900.$$

Hence, the hit rate $h = \dfrac{H}{H+M} = 97.44\%$.

The average memory access time is $h \times50 + (1-h)\times(50+200+50) = 56.41$.

Thus, the access efficiency of this cache-main memory system is $\dfrac{50}{56.41} = 88.64\%$.

## Q5

**Process A**

|      | Valid | PFN  |
| ---- | ----- | ---- |
| 0    | 0     |      |
| 1    | 0     |      |
| 2    | 1     | 0    |
| 3    | 0     |      |
| 4    | 0     |      |
| 5    | 0     |      |
| 6    | 0     |      |
| 7    | 1     | 2    |

**Process B**

|      | Valid | PFN  |
| ---- | ----- | ---- |
| 0    | 1     | 1    |
| 1    | 1     | 6    |
| 2    | 0     |      |
| 3    | 1     | 4    |
| 4    | 1     | 5    |
| 5    | 0     |      |
| 6    | 0     |      |
| 7    | 0     |      |

<div class="page-break"></div>

## Q6

1. Using the scheduled instruction to calculate IPC (instructions per clock cycle).

   |         | ALU or branch         | Data transfer    | CC   |
   | ------- | --------------------- | ---------------- | ---- |
   | `LOOP:` |                       | `lw x31, 0(x20)` | 1    |
   |         | `addi x20, x20, -8`   |                  | 2    |
   |         | `add  x31, x31, x21`  |                  | 3    |
   |         | `blt  x22, x20, LOOP` | `sw x31, 8(x20)` | 4    |
   |         |                       |                  | 5    |

   **IPC is 1.25.**

2. Suppose we have four registers (x28, x29, x30, x31), please design a solution to unroll the loop for better IPC.

   |         | ALU or branch         | Data transfer      | CC   |
   | ------- | --------------------- | ------------------ | ---- |
   | `LOOP:` | `addi x20, x20, -32`  | `lw x31, 0(x20)`   | 1    |
   |         |                       | `lw x28, 24(x20) ` | 2    |
   |         | `add x31, x31, x21`   | `lw x29, 16(x20) ` | 3    |
   |         | `add x28, x28, x21`   | `lw x30, 8(x20) `  | 4    |
   |         | `add x29, x29, x21`   | `sw x31, 32(x20)`  | 5    |
   |         | `add x30, x30, x21`   | `sw x28, 24(x20)`  | 6    |
   |         |                       | `sw x29, 16(x20)`  | 7    |
   |         | `blt  x22, x20, LOOP` | `sw x30, 8(x20)`   | 8    |

   **IPC is 1.8**.

<div class="page-break"></div>

## Q7

1. ![image-20220415215008533](C:\Users\zepto\AppData\Roaming\Typora\typora-user-images\image-20220415215008533.png)
2. The maximal speedup is $1000\%$.
