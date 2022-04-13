* Binary search program in MMIX assembly
* According to TAOCP3 page 411
N		IS		16
K		IS		154		* Number to compare
t		IS		$255
i		GREG	0
u		GREG	0
l		GREG	0
ki		GREG	0
k		GREG	K
argv 	IS 		$1
FailStr	BYTE	"Key not found!",0,#a
SuccStr	BYTE	"Key found!",0,#a
		LOC		Data_Segment
KA		OCTA	061
		OCTA	087
		OCTA  	154
		OCTA	170
		OCTA	275
		OCTA	426
		OCTA	503
		OCTA	509
		OCTA	512
		OCTA	612
		OCTA	653
		OCTA	677
		OCTA	703
		OCTA	765
		OCTA	897
		OCTA	908
k0		GREG	KA

		LOC   	#100
Main	SET   	l,0			* 1		S1.Initialize
		SET		u,N			* 1
		JMP		2F			* 1
5H		CMP		t,k,ki		* C1		k == k[i]
		BZ		t,3F		* C1
		ADD		l,l,1		* C1		l <- l -1
		CMP		t,u,l		* C1
		BN		t,9F		* C1
2H		ADD		t,u,l		* C+1-S
		DIV		i,t,2		* C+1-S
		SL		t,i,3		* C+1-S
		LDO   	ki,k0,t		* C+1-S		S2.Compare
		CMP   	t,k,ki		* C+1-S
		PBNN   	t,5B		* C2		Go to 5 IF K >= K[i]
		SUB   	u,u,1		* C2		S3.Advance
		JMP		2B			* C2
9H		GETA	$255,FailStr
		TRAP	0,Fputs,StdOut
Exit	TRAP	0,Halt,0	* 1
3H		GETA	$255,SuccStr
		TRAP	0,Fputs,StdOut
		JMP		Exit
