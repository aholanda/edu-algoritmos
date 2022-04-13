		.data
		.align	2
ki:		.word	061 087 154 170 275 426 503 509 512 612 653 677 703 765 897 908
N:		.word	16
s1:		.word	653	# first search
s2:		.word	400 # second search
prompt:	.asciiz	"Enter the key: "
sstr:	.asciiz	"The key was found!\n"
fstr:	.asciiz	"The key was not found!\n"
nl:		.asciiz	"\n"
		.text
.globl	main
main: 	li $v0, 4           # Print prompt.
		la $a0, prompt
		syscall

		li $v0, 5           # Read K.
        syscall
        move $a0, $v0       # K in $a0.

		la	$s1,ki			# load the address of K[0]
		lw	$s2,N			# $s1 <- N = 16
	
B:		move	$t0,$zero	# B1.Initialize, l <- 0
		addi	$t1,$s2,0	# u <- N
		jal 	B2

B4:		beq		$a0,$s4,succ	# Compare K = Ki
		# B4.Adjust u
		sub		$t1,$t1,1	# u <- u - 1
		# B2.Get midpoint
B2:		slt		$t3,$t1,$t0	# $t3 <- 1 IF u < l
		beq		$t3,1,fail
		add		$t3,$t1,$t0 # u + l 
		div		$t3,$t3,2	# i($t3) = [(u + l)/2].Lo, Hi = mod
		mflo	$t4		#  move quantity in special register Lo to $t4:   $t4 = Lo
	
		sll		$t5,$t4,2	# i <- i * 4
		add		$t6,$s1,$t5	# address of K[i]
		lw		$s4,0($t6)	# load K[i]
		# B3. Compare
B3:		slt		$t7,$s4,$a0	# $t8 <- 1 IF Ki < K
		beq		$t7,0,B4    # to B4 if Ki>=K

		add		$t0,$t0,1	# l <- l + 1
		jal		B2

succ:	li		$v0,4 		# syscall for print_string
		la		$a0,sstr	
		syscall
	
exit:	li $v0, 10           # Exit.
        syscall
		# oops, not found
fail:	li		$v0,4 		# syscall for print_string
		la		$a0,fstr	# address of the string to print
		syscall
		jal		exit