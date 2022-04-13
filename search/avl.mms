* Program A
* Balanced tree (AVL) search and insertion
* Based on MIX version of "The Art of Computer Programming" v.3
* Pages 464, 465 and 466
tt		IS	 $255
key		GREG	 0	* key load/stored
b	GREG	0	 * balance factor reg
t	GREG	0	 * points to parent of s
s	GREG	0	 * points to where to rebalance
p	GREG	0	 * move down the tree
q	GREG	0
r	GREG	0
a	GREG	0	 * balance factor of the transformation
na	GREG	0	 * negate a
of	GREG	0	 * offset of load/store
fo	GREG	0	 * opposite direction of offset
k	GREG	0	 * key arg
avail	GREG	0  * available address
Chunk	IS	 #1000
LENGTH	IS	8 * length of main fields
LLINK	IS	0*LENGTH  * left node pointer
KEY		IS	1*LENGTH
RLINK	IS	2*LENGTH * right node pointer
B	IS	3*LENGTH	 * balance factor
NODESIZE	IS	B+LENGTH
chunk	GREG	Chunk
rkey	GREG	KEY	 * register containing key value
NULL	IS	0	* means zero or NULL or empty set (all the same)
null	GREG	NULL	* NULL/zero register
nodesize	GREG NODESIZE
head		GREG Chunk	* LLINK(HEAD)=H, RLINK(HEAD)=root
root		GREG Chunk+NODESIZE
K1		IS		256
k1		GREG	K1

	LOC		#100
A	SET		k,$0
	SET		t,head	* T <- HEAD
	LDO		p,head,RLINK   * P <- RLINK(HEAD)
	SET		s,p		* S <- P
2H	LDO		key,p,KEY	* K <- KEY(P)
	CMP		tt,k,key		* A2.[Compare]
	BZ		tt,Ret	* K = KEY(P)
	MUL		of,tt,LENGTH	* Offset direction
	ADD		of,of,KEY	* Symmetric shift
	LDO		q,p,of	* Q <- LINK(a,P)
	BZ		q,5F	* To 5F if Q = NULL
	LDO		b,q,B
	BZ		b,0F	* To A34 if B(Q) = 0
	SET		t,p
	SET		s,q
0H	SET		p,q
	JMP		2B
5H	SET		q,avail	* Q <- AVAIL
	STO		q,p,of	* LINK(a,P) <- Q
	STO		k,q,KEY		* A5.[Insert] KEY(Q) <- Q
	STO		null,q,LLINK  * LLINK(Q) <- NULL
	STO		null,q,RLINK  * RLINK(Q) <- NULL
	STO		null,q,B	  * B(Q) <- 0
	ADDU	avail,avail,nodesize	* AVAIL <- AVAIL + NODESIZE
	LDO		key,s,KEY
	CMP		tt,k,key
	SET		a,tt	* A6.[Adjust balance factors.] a <- +|- 1
	MUL		of,a,LENGTH	* Offset direction
	ADD		of,of,KEY	* Symmetric shift
	LDO		tt,s,of	* LINK(a,S)
	SET		p,tt	* P <- LINK(a,S)
	SET		r,p		* R <- P

6H	LDO		key,p,KEY * KEY(P)
	CMP		tt,k,key
	BZ 		tt,7F	* To 7H if P = Q
	STO		tt,p,B	* B(P) <- +|- 1
	MUL		tt,tt,LENGTH   * temp Offset direction
	ADD		tt,tt,KEY	* temp Symmetric shift
	LDO		p,p,tt	* P <- LINK(a,P)
	JMP		6B

7H	LDO		b,s,B	* B(S)
	PBNZ	b,A72	* To A7.ii if B(S) = 0
	STO		a,s,B	* B(S) <- a
	LDO		tt,head,LLINK  * LLINK(HEAD)
	INCL	tt,1	
	STO		tt,head,LLINK	* LLNK(HEAD) + 1
	JMP		Ret
A72	CMP		tt,b,a
	PBZ		tt,8F	* B(S) = a ?
	STO		null,s,B	* B(S) = -a /\ S(B) <- 0
	JMP		Ret
8H 	LDO		b,r,B		* B(R)
	CMP		tt,b,a
	NEG		na,a	* -a
	MUL		fo,na,LENGTH
	ADD		fo,rkey,fo	* LINK(-a)
	PBNZ	tt,9F		* To A9 if B(R) = -a
	SET		p,r		* P <- R
	LDO		tt,r,fo	* LINK(-a,R)
	STO		tt,s,of * LINK(a,S) <- LINK(-a,R)
	STO		s,r,fo	* LINK(-a,R) <- S
	STO		null,s,B  * B(S) <- 0
	STO		null,r,B  * B(R) <- 0
	JMP		A10
9H	STO		p,r,fo	  * P <- LINK(-a,R)
	LDO		tt,p,of	  * LINK(a,P)
	STO		tt,r,fo	  * LINK(-a,R) <- LINK(a,P)
	STO		r,p,of	  * LINK(a,P) <- R
	LDO		tt,p,fo	  * LINK(-a,P)
	STO		tt,s,of	* LINK(a,S) < LINK(-a,P)
	STO		s,p,fo	* LINK(-a,P) <- S
	LDO		b,p,B	* B(P)
	BZ		b,9F	* To 9H if B(P) != 0
	STO		null,s,B  * B(S) <- 0
	STO		null,r,B  * B(R) <- 0
9H	CMP		tt,b,a
	PBZ		tt,0F	* To 0F if B(P) = a
	STO		null,s,B  * B(S) <- 0
	STO		a,r,B	  * B(R) <- a
	JMP		1F
0H	STO		na,s,B	  * B(S) <- -a
	STO		null,r,B  * B(R) <- 0
1H	STO		null,p,B  * and then set B(P) <- 0
					  * A10. [Finshing touch]
A10	LDO		tt,t,RLINK * RLINK(T)
	CMP		tt,tt,s	   * S = RLINK(T)?
	PBNZ	tt,0F
	STO		p,t,RLINK	* RLINK(T) <- P
	JMP 	Ret
0H	STO		p,t,LLINK	* LLINK(T) <- P
Ret	POP		1,0

Main	SET		avail,root		* Initialize avail
								* Initialize at all
		STOU	k1,root,KEY   	* ROOT <- K1
		STO		null,root,LLINK	* LLINK(ROOT) <- NULL
		STO		null,root,RLINK	* RLINK(ROOT) <- NULL
		STO		null,root,B		* B(ROOT) <- 0
		ADDU	avail,root,nodesize	* avail %$\leftarrow$% avail + nodesize
		STO		root,head,RLINK		* LLINK(HEAD) <- ROOT
		ADDU	tt,null,1	* H <- 0 + 1
		STO		tt,head,LLINK * LLINK(HEAD) <- H
		SET		$1,128
		PUSHJ	$0,A			* Call T
		SET		$1,96
		PUSHJ	$0,A
		SET		$1,104
		PUSHJ	$0,A
		SET		$1,100
		PUSHJ	$0,A
		TRAP	0,Halt,0
	