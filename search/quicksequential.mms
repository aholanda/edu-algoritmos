* Quick sequential search program in MMIX assembly
* According to TAOCP3 page 308
N		IS		16
K		IS		908			* Number to compare
t		IS		$255
i		GREG	0
ki		GREG	0
ii		GREG	0
k		GREG	K
n		GREG	N
argv 	IS 		$1
FailStr	BYTE	"Key not found!",0,#a
SuccStr	BYTE	"Key found!",0,#a
		LOC		Data_Segment
KA		OCTA	503 
		OCTA	509
		OCTA  	512 
		OCTA	612 
		OCTA	061 
		OCTA	087 
		OCTA	677 
		OCTA	703 
		OCTA	154 
		OCTA	170 
		OCTA	275 
		OCTA	426 
		OCTA	653 
		OCTA	765 
		OCTA	897 
		OCTA	908
k0		GREG	KA

		LOC   	#100
Main	SL		t,n,3
		STO		k,k0,t			* 1		%$K_{n+1} \leftarrow K$%
		SET   	i,0				* 1		S1.Initialize
3H		SL		t,i,3
		LDO   	ki,k0,t			* C	
		CMP   	t,k,ki			* C		S2.Compare
		BZ   	t,2F			* C
		ADD   	i,i,1			* C-S	S3.Advance
		JMP   	3B			* C-S
2H		CMP		t,i,N			* 1
		BNZ		t,9F			* 1		Branch if i <= N
		GETA	$255,FailStr
		TRAP	0,Fputs,StdOut
Exit	TRAP	0,Halt,0
9H		GETA	$255,SuccStr
		TRAP	0,Fputs,StdOut
		JMP		Exit
