# CENG3420 Homework 2

*ZHOU, Yixiang*
*04/03/2022*

## Q1

1. What is 5ED4 - 07A4 when these values represent unsigned 16-bit hexadecimal numbers? The result should be written in hexadecimal. Show your work.

   ```
   Since these values are unsigned numbers, we perform by-bit subtraction.
   	5ED4
   -	07A4
   ---------
   	5730
   ```

   

2. What is 5ED4 - 07A4 when these values represent signed 16-bit hexadecimal numbers stored in sign-magnitude format? The result should be written in hexadecimal. Show your work.

   ````
   In sign-magnitude format, these values are all postive due to the highest bit being zero. The result remains the same.
   	5ED4
   -	07A4
   ---------
   	5730
   ````

## Q2

1. | Repetition | Multiplier  | Multiplier0 | Multiplicand                 |         Product |
   | ---------- | ----------- | ----------- | ---------------------------- | --------------: |
   | [Start]    | 0111        |             | 0011                         |            0000 |
   | 1st        | 0111        | 1           | 0011                         |  0000+0011=0011 |
   | 2nd        | 0011        | 1           | 0110                         |  0011+0110=1001 |
   | 3rd        | 0001        | 1           | 1100                         | 1001+1100=10101 |
   | 4th        | 0000        | 0           | 11000                        |           10101 |
   | 5th - 32nd | [unchanged] | [unchanged] | [shift left by 1 bit a time] |     [unchanged] |

   Terminated with the product being ``10101``.

2. Here we demonstrate the processes with 8-bit registers.

   | Repetition | Remainder | Divisor   | Quotient |
   | ---------- | --------- | --------- | -------: |
   | [Start]    | 0000 0111 | 0010 0000 |      N/A |
   | 1st - 1    | 1110 0111 | 0010 0000 |     0000 |
   | 1st - 2b   | 0000 0111 | 0010 0000 |     0000 |
   | 1st - 3    | 0000 0111 | 0001 0000 |     0000 |
   | 2nd - 1    | 1111 0111 | 0001 0000 |     0000 |
   | 2nd - 2b   | 0000 0111 | 0001 0000 |     0000 |
   | 2nd - 3    | 0000 0111 | 0000 1000 |     0000 |
   | 3rd - 1    | 1111 1111 | 0000 1000 |     0000 |
   | 3rd - 2b   | 0000 0111 | 0000 1000 |     0000 |
   | 3rd - 3    | 0000 0111 | 0000 0100 |     0000 |
   | 4th - 1    | 0000 0011 | 0000 0100 |     0000 |
   | 4th - 2a   | 0000 0011 | 0000 0100 |     0001 |
   | 4th - 3    | 0000 0011 | 0000 0010 |     0001 |
   | 5th - 1    | 0000 0001 | 0000 0010 |     0001 |
   | 5th - 2a   | 0000 0001 | 0000 0010 |     0011 |
   | 5th - 3    | 0000 0001 | 0000 0001 |     0011 |

## Q3

```si
-1.5625 x 10^{-1} = -0.15625

0.15625	->	0
0.3125	->	0
0.625	->	0
1.25	->	1
0.5		->	0
1.0		->	1

0.15625 = 2^{-3} 1.01

|	sign bit	|	exponent	|	mantissa	|
	1				01100			0100000000
```



## Q4

```
Let A = 
2.6125 x 10^1			=	26.125	=	2^4 x 1.1010001
						=	0 10011 1010001000

Let B =
4.150390625 x 10^{-1}	=	0.4150390625 = 2^{-2} x 1.1010100100
						
Shifting B by 6 positions            GRS
						1.1010001000 000
						0.0000011010 101 (Guard = 1, Round = 0, Sticky = 1)
						-----------------
						1.1010100010 101
The value is rounded up =>
						1.1010100011 x 2^4
					=	2.6546875 x 10^1
						
```



## Q5

```
Both add instructions have a hazard because of their respective dependence on the immediately preceding ld instruction. 

Moving the third ld instruction up after the second ld instruction eliminates both hazards, without the need of any pipeline stalls.
```



## Q6

1. The values of the signals are as follows:

   | RegWrite | ALUSrc  | ALU Control | MemWrite | MemRead | MemToReg |
   | -------- | ------- | ----------- | -------- | ------- | -------- |
   | 1        | 0 (Reg) | 0000 (Add)  | 0        | 0       | 0 (ALU)  |

   

2. The resources with no outputs / unused output:

   | No Output   | Output Not Used |
   | ----------- | --------------- |
   | Data Memory | ImmGen          |

    