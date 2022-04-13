# Quick sequential search program in MIPS assembly
# According to TAOCP3 page 308
		.data
		.align	2
ki:		.word	503,509,512,612,061,087,677,703,154,170,275,426,653,765,897,908
N:		.byte	16
prompt:	.asciiz	"Enter key: "
sstr:	.asciiz	"The key was found!\n"
fstr:	.asciiz	"The key was not found!\n"
		.text
.globl	main
main: 	li $v0, 4           # Print prompt.
		la $a0, prompt
		syscall

		li $v0, 5           # Read K.
        syscall
        move $s0, $v0       # K in $s0.

		la	$s1,ki			# load the address of K[0]
		lb	$s2,N			# $s1 <- N = 16

Q:		sll	$t0,$s2,2		# $t0 <- N * 4
		add	$t1,$s1,$t0		# address of K[N]
		sw	$s0,0($t1)		# K[N] <- K
		move	$t0,$zero	# i <- 0
loop:	sll	$t1,$t0,2		# $t1 <- i * 4
		add	$t2,$s1,$t1		# address of K[i]
		lw	$t3,0($t2)		# read K[i]
		beq	$t3,$s0,found	# K[i] != K ?
		addi	$t0,$t0,1	# i <- i + 1
		jal	loop
found:	slt	$t4,$t0,$s2		# $t4 <- 1 if (i < N) else 0 
		beq	$t4,1,succ

		li		$v0,4 		# syscall for print_string
		la		$a0,fstr	# address of FAIL string
		syscall

exit:	li $v0, 10           # Exit.
        syscall
succ:	li		$v0,4 		# syscall for print_string
		la		$a0,sstr	# address of the SUCCESS string
		syscall
		jal	exit
