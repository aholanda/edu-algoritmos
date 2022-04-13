% status=OK
% name=Program S
% task=Straight insertion sorting
% from TAOCP3 pg 81
% B is the number of moves
% A is the number of times i decreases to zero in step S4
t IS $255
i 	GREG
ii	GREG
j 	GREG
ri 	GREG
r  	GREG
ki	GREG
k	GREG

		LOC		Data_Segment
Data	GREG	@
		OCTA	503,87,512,061,908
		OCTA	170,897,275,653,426
		OCTA	154,509,677,765,703
data	IS		Data
Record	GREG	@
LENGTH 	IS  8	* record length
SIZE   	IS  15*LENGTH
Record	GREG	@
		OCTA	Data_Segment,Data_Segment+LENGTH,Data_Segment+LENGTH*2
		OCTA	Data_Segment+LENGTH*3,Data_Segment+LENGTH*4,Data_Segment+LENGTH*5
		OCTA	Data_Segment+LENGTH*6,Data_Segment+LENGTH*7,Data_Segment+LENGTH*8
		OCTA	Data_Segment+LENGTH*9,Data_Segment+LENGTH*10,Data_Segment+LENGTH*11
		OCTA	Data_Segment+LENGTH*12,Data_Segment+LENGTH*13,Data_Segment+LENGTH*14
record	IS		Record
		
		LOC	 #100
Main	SET	 j,0			* 1
1H		INCL j,LENGTH		* N - 1		S1. Loop on j. j <- j + 1
		SUB	 i,j,LENGTH	  	* N - 1		S2. Set up i,K,R. i <- j -1
		LDO	 r,record,j		* N - 1		R
		LDO	 k,r,0			* N - 1		K
3H		LDO	 ri,record,i	* B + N - 1 - A		S3. Compare K : Ki.
		LDO	 ki,ri,0		* B + N - 1 - A
		CMP	 t,k,ki			* B			If K >= Ki
		PBNN t,5F			* B
		ADD	 ii,i,LENGTH	* B			ii <- i + 1
		STO	 ri,record,ii  	* B			S4. Move R, decrease i. Ri+1 <- Ri
		SUB	 i,i,LENGTH		* B			i <- i - 1
		PBNN i,3B			* B
5H		STO	 r,record,ii	* S5. R into Ri+1. Ri+1 <- R
		CMP	 t,j,SIZE		* N - 1 	% j starts at 1
		BZ	 t,Return		* N - 1
		JMP	 1B				* N - 1
Return	TRAP 0,Halt,0		* 1
