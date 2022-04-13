# $Author: aholanda $, $Date: 2010-05-02 21:07:20 -0300 (Dom, 02 Mai 2010) $	
	.data
	.align	2
data:	.word	503,087,512,061,908,170,897,275,653,426,154,509,612,677,765,703
record:	.word	0x10010000,0x10010004,0x10010008,0x1001000C,0x10010010,0x10010014,0x10010018,0x1001001C,0x10010020,0x10010024,0x10010028,0x1001002C,0x10010030,0x10010034,0x10010038,0x1001003C
newline:	.asciiz "\n"
		.align	1
N:		.byte	15
	.text
.globl	main
main:	la		$s5,record	# lower bound = load address of record[0]
		lb		$t0,N
		mul		$t0,$t0,4	# N * 4
		add		$s6,$s5,$t0 # upper bound = address of record[N]

		move	$s4,$s5		# j <- 0 (lower bound)
S2:		addi	$s4,$s4,4	# j <- j + 1
		sub		$s3,$s4,4	# i <- j - 1
		lw		$s2,0($s4) 	# R
		lw		$t0,0($s2) 	# K
		
S3:		lw		$s1,0($s3)	# Ri
		lw		$t1,0($s1)	# Ki
		slt		$t3,$t0,$t1	# K < Ki ? 1 : 0
		beq		$t3,0,S5
		sw		$s1,4($s3)	# Ri+1 <- Ri
		sub		$s3,$s3,4	# i <- i - 1
		slt		$t3,$s3,$s5	# i < lower bound ? 1 : 0
		beq		$t3,0,S3	# To S3 IF i > 0
		
S5:		addi	$s3,$s3,4	# i <- i + 1
		sw		$s2,0($s3)	# Ri+1 <- Rj
		beq		$s4,$s6,show # IF j = N THEN Exit
		j		S2			 # ELSE JUMP TO S2
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
