% status=PENDING
% name=Program Q
% task=Quicksort
% from TAOCP3 (2nd edition) pg 117
t IS $255
l 	GREG
i 	GREG
j 	GREG
r  	GREG
R	GREG
K	GREG
Ri	GREG
Ki	GREG
Rj	GREG
Kj	GREG

		LOC		Data_Segment
Data	GREG	@
		OCTA	503,87,512,061,908
		OCTA	170,897,275,653,426
		OCTA	154,509,677,765,703
data	IS		Data
Record	GREG	@
LENGTH 	IS  8	* record length
N	IS  15
N_1	IS  14
SIZE   	IS  N*LENGTH
Record	GREG	@
		OCTA	Data_Segment,Data_Segment+LENGTH
		OCTA	Data_Segment+LENGTH*2,Data_Segment+LENGTH*3
		OCTA	Data_Segment+LENGTH*4,Data_Segment+LENGTH*5
		OCTA	Data_Segment+LENGTH*6,Data_Segment+LENGTH*7
		OCTA	Data_Segment+LENGTH*8,Data_Segment+LENGTH*9
		OCTA	Data_Segment+LENGTH*10,Data_Segment+LENGTH*11
		OCTA	Data_Segment+LENGTH*12,Data_Segment+LENGTH*13
		OCTA	Data_Segment+LENGTH*14 
record	IS		Record
		
		LOC	 #100
Main	SET	 l,0			* Q1 $l\leftarrow 0$
	SET	 r,N_1			* Q1 $r\leftarrow N - 1$
	SET	 i,l			* Q2 $i\leftarrow l$	 
	ADD	 j,r,1			* Q2 $j\leftarrow r + 1$	 
	LDO	 R,Record,l		* Q2 $R\leftarrow R_l$
	LDO	 K,R,0			* Q2 $K\leftarrow K_l$
3H	INCL	 i,1			* Q3 Increase $i$ by $1$
	LDO	 Ri,Record,i		* Q3 $R_i$
	LDO	 Ki,R,0			* Q3 $K_i$
	CMP	 t,Ki,K			* Q3 Compare $K_i:K$
	BN	 t,2B			* Q3 Repeat if $Ki<K$
4H	SUB	 j,j,1			* Q4 Decrease $j$ by $1$	 	
	LDO	 Rj,Record,j		* Q3 $R_j$
	LDO	 Kj,R,0			* Q3 $K_j$
	CMP	 t,K,Kj			* Q4 Compare $K:Kj$
	BN	 t,4B			* Q4 Repeat if $K<Kj$

Return	TRAP 0,Halt,0			* Q9 []