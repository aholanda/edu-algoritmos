* Straight insertion sort program in MMIX assembly
* According to TAOCP3 page 81
N		IS		16
K		IS		509			* Number to compare
t		IS		$255
i		GREG	0
ki		GREG	0
ii		GREG	0
k		GREG	K
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
Main	SET   	i,0			* 1		S1.Initialize
2H		SL		ii,i,3		* C		i <- i * 8
		LDO   	ki,k0,ii	* C		S2.Compare
		CMP   	t,k,ki		* C
		BZ   	t,3F		* C
		ADD   	i,i,1		* C-S	S3.Advance
		CMP		t,i,N		* C-S	S4.End of file?
		PBN   	t,2B		* C-S
		GETA	$255,FailStr
		TRAP	0,Fputs,StdOut
Exit	TRAP	0,Halt,0
3H		GETA	$255,SuccStr
		TRAP	0,Fputs,StdOut
		JMP		Exit
