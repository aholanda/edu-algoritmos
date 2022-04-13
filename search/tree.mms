* Tree search and insertion program in MMIX assembly
* According to TAOCP3 page 429
t 	   IS	  $255
root   GREG		 0
avail  GREG		 0
p	   GREG		 0
q	   GREG		 0
k	   GREG		 0
key	   GREG		 0
Chunk  IS		 #1000
nodesize	IS 3*8
chunk		GREG	Chunk
KEY		IS	0
LLINK	IS	8
RLINK	IS	16
NULL	IS	0
null	GREG	NULL
K1		IS		128
k1		GREG	K1

T		SET		k,$0		* 1		T1.Initialize
		SET		p,root		* 1
		JMP		2F			* 1
4H		LDOU	q,p,RLINK	* C2	T4.Move right. Q %$\leftarrow$% RLINK(P)
		PBZ		q,5F		* C2	To T5 if Q =%$\Lambda$%
1H		SET		p,q			* C-1	T1%$^\prime$%.Reinitialize, P %$\leftarrow$% Q
2H		LDOU	key,p,KEY	* C		K=KEY(P)
		CMP		t,k,key		* C		T2.Compare
		PBP		t,4B		* C		To 	T4 if K>KEY(P)
		BZ		t,Return  	* C1 	Return IF K=KEY(P)
		LDOU	q,p,LLINK 	* C1-S	Q %$\leftarrow$% LLINK(P)
		PBNZ	q,1B		* C1-S	To T1 if Q%$\neq\Lambda$%
5H		SET		q,avail		* 1-S	Q %$\leftarrow$% AVAIL
		STOU	k,q,KEY 	* 1-S	KEY(Q) %$\leftarrow$% K
		STO		null,q,LLINK * 1-S	LLINK(Q)%$\leftarrow\Lambda$%
		STO		null,q,RLINK * 1-S	RLINK(Q)%$\leftarrow\Lambda$%
		ADDU	avail,avail,nodesize	* 1-S	avail %$\leftarrow$% avail + nodesize
		BP		t,1F		* 1-S	Was K > KEY(P)
		STOU	q,p,LLINK 	* A		LLINK(P) %$\leftarrow$% Q
		JMP		Return		* A
1H		STOU	q,p,RLINK	* 1-S-A	RLINK(P) %$\leftarrow$% Q
Return	POP		1,0			* 1

Main	SET		avail,Chunk		* Initialize avail
		SET	 	root,avail i  	* ROOT %$\leftarrow$% #10000
		STOU	k1,root,KEY   	* ROOT %$\leftarrow$% #10000
		STO		null,root,LLINK	* LLINK(Q)%$\leftarrow\Lambda$%
		STO		null,root,RLINK	* RLINK(Q)%$\leftarrow\Lambda$%
		ADDU	avail,chunk,nodesize	* avail %$\leftarrow$% avail + nodesize
		SET		$1,53
		PUSHJ	$0,T			* Call T
		SET		$1,232
		PUSHJ	$0,T
		SET		$1,75
		PUSHJ	$0,T
		SET		$1,218
		PUSHJ	$0,T
		TRAP	0,Halt,0
