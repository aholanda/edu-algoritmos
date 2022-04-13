	.data
	.align	2
k1:	.word	128
alloc:	.word	96
root:	.word	0x10000
	.text
.globl	main
main:	lw	$t0,k1
		move	$a0,$gp # Initialize alloc
		sw	$t0,0($a0)
		sw	$zero,32($a0)
		sw	$zero,64($a0)
		lw	$t0,alloc	# increment avail
		add $gp,$gp,$t0	# 

		addi $a1,$zero,53
		jal	T

		addi $a1,$zero,232
		jal	T

		addi $a1,$zero,75
		jal	T

		addi $a1,$zero,218
		jal	T

		li $v0, 10           # Exit.
        syscall
		
T:	move	$t0,$a0
	move	$t1,$a1
	j	T2
T4:	beq	$t2,$t1,ret	# K=KEY(P)
	lw	$t4,64($t0)	# Q <- RLINK(P)
	j	T5
T1:	move $t0,$t4
T2:	lw	$t2,0($t0)	# KEY(P)
	slt	$t3,$t2,$t1	# T2.Compare
	beq	$t3,1,T4	# To T4 if K>KEY(P)
	lw	$t4,32($t0)	# Q <- LLINK(P)
T5:	bne	$t4,0,T1	# To T1 if LLINK != NULL
	move	$t5,$gp
	sw	$t1,0($t5)	# KEY(Q) <- K
	sw	$zero,32($t5) # LLINK(Q) <- NULL
	sw	$zero,64($t5) #	RLINK(Q) <- NULL
	addi $gp,$gp,96 # avail <- avail + alloc (3*32)
	beq	$t3,1,RL	# To RLINK if K>KEY(P)	
	sw	$t5,32($t0)	# LLINK(P) <- Q
ret:	jr	$ra
RL:	sw	$t5,64($t0)	# RLINK(P) <- Q
	j ret