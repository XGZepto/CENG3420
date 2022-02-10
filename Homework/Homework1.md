# CENG3420 Homework 1

*ZHOU, Yixiang*
*04/02/2022*

## Q1

1. Find the yield of this wafer.

   $$\begin{align*}\text{Wafer area } &= \pi \cdot 10^2 \text{cm}^2 \\ \text{Die area} &= \text{Wafer area} / \text{Dies per wafer} \\ &= \pi \text{cm}^2 \\ \text{Yield} &= \frac{1}{[1+(\text{Defects per area} \cdot \text{Die area}/2)]^2} \\ &= 91.20\% \end{align*}$$

2. Find the cost per die for this wafer.

   $$\text{Cost per die} = \frac{\text{Cost per wafer}}{\text{Dies per wafer} \cdot \text{Yield}} = 0.1645$$

## Q2

$$\begin{align*} \frac{\text{Power}_\text{new procesor}}{\text{Power}_\text{old procesor}} = (75\%) \cdot(1-20\%)^2 =  48\%\end{align*}$$

## Q3

```assembly
add		x5, x6, x7
addi	x5, x5, -8
```

## Q4

1. ```assembly
   slli	x7, x5, 4
   # x7 = 0xAAAAAAA0
   # x6 = 0x12345678
   or		x7, x7, x6
   # x7 = 0xBABEFEF8
   ```

2. ```assembly
   srli	x7, x5, 3
   # x7 = 0x15555555
   andi	x7, x7, 0xFEF
   # x7 = 0x545

## Q5

1. ```assembly
   # x5 = 20
   ```

2. ```c
   for (; i != 0; --i)
   	acc += 2;
   ```

3. $4N + 1$ instructions if $N \ge 0$; $4\cdot(2^{32}+N)+1$ instructions if $N \lt 0$.

4. ```c
   for (; i >= 0; --i)
   	acc += 2;
   ```

## Q6

1. ```assembly
   addi	x12, x30, 4
   # x12 = x30 + 4
   # x12 = &A[f+1]
   lw		x30, 0(x12)
   # load the content in the address indicated by x12 to x30
   # x30 = A[f+1]
   add		x30, x30, x5
   # x30 = A[f+1] + A[f]
   sw`		x30, 0(x31)
   # B[g] = A[f+1] + A[f]
   # save the value in x30 to the address indicated by x31
   ```

2. ```c
   B[g] = A[f+1] + A[f]
   ```
