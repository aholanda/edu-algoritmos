# $Author: adriano j. holanda $, $Date: 2010-06-11 14:16:13 -0300 (Sex, 11 Jun 2010) $	
# Algorithm D from TAOCP3 pg 85
# Shellsort

	.data
	.align	2
data:	.word	503,087,512,061,908,170,897,275,653,426,154,509,612,677,765,703
record:	.word	0x10010000,0x10010004,0x10010008,0x1001000C,0x10010010,0x10010014,0x10010018,0x1001001C,0x10010020,0x10010024,0x10010028,0x1001002C,0x10010030,0x10010034,0x10010038,0x1001003C
newline:	.asciiz "\n"
		.align	1
N:		.byte	60 		# 15*4
h:		.byte	32,16,8,1
		.text
.globl	main
		
main:	la		$s7,h
		lb		$t7,0($s7)
		
		la		$s5,record	# lower bound = load address of record[0]
		lb		$t0,N
		add		$s6,$s5,$t0 # upper bound = address of record[N]
		j		j0
		
d1:		addi	$s7,$s7,1
		lb		$t7,0($s7)
		
j0:		move	$s4,$0		# j <- 0 (lower bound)
		j		jh
d2:		addi	$s4,$s4,4	# d2. Loop on j
jh:		add		$t4,$s4,$t7	# j <- j + h
		add		$t4,$s5,$t4	# Address(R)
		lw		$s2,0($t4) 	# R
		lw		$t0,0($s2) 	# K
		
		move	$s3,$s4		# i <- j - h
d3:		add		$s1,$s5,$s3	# Address(Ri)
		lw		$t1,0($s1)	# Ri
		lw		$t1,0($t1)	# Ki
		slt		$t3,$t0,$t1	# K < Ki ? 1 : 0
		beq		$t3,0,d6
		add		$t1,$s3,$t7	# i <- i + h
		sw		$s1,0($t1)	# Ri+h <- Ri
		sub		$s3,$s3,$t7	# i <- i - h
		slt		$t3,$s3,0	# i < 0 ? 1 : 0
		beq		$t3,1,d3	# To d3 IF i > 0
		
d6:		add		$s3,$s3,$t7	# i <- i + h
		sw		$s2,0($s3)	# Ri+1 <- Rj

		slt		$t5,$s4,$s6	# IF j < N THEN Advance j
		beq		$t5,1,d2
		
		bne		$t7,1,d1	 # IF h != 1 THEN Go to d1

		# print sorted data
show:	move	$t0,$s5		# i <- 0
loop:	lw		$t1,0($t0)

		li		$v0,1		# print_int syscall
		lw		$a0,0($t1)	# address to print
		syscall

							# code to print a newline
		li   	$v0, 4		# system call for print_str
		la   	$a0, newline	# address of str to print
		syscall			

		

		beq		$t0,$s6,Exit # IF i = N THEN Exit
		addi	$t0,$t0,4	# i <- i + 1
		j		loop
		
Exit:	li 		$v0, 10  	# Exit.
        syscall
