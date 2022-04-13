* Algorithm D from TAOCP3 pg 84
* Shellsort
t IS $255
i GREG
ih	GREG
j GREG
ri GREG
r GREG
ki GREG
k GREG
s GREG
ss	GREG
hs	GREG

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
H		GREG	@
		BYTE	8*LENGTH,4*LENGTH,2*LENGTH,1*LENGTH
h		IS		H
HLEN	IS		3

		LOC		#100
Main	SET		s,0
1H		LDB		hs,h,s	* D1. Loop on s.	LOAD hs
		SET		j,hs
		JMP		3F
2H		ADD		j,j,LENGTH	* D2. Loop on j.	j <- h + 1
3H		LDO		r,record,j	* LOAD R
		LDO		k,r,0		* LOAD K

		SUB		i,j,hs	* i <- j - h
4H		LDO		ri,record,i	* Ri
		LDO		ki,ri,0		* Ki
		CMP		t,k,ki		* D4. Compare K : Ki
		PBNN	t,6F		* To D6 if K >= Ki
		ADD		ih,i,hs		* i <- i + h
		STO		ri,record,ih * Ri+h <- Ri
		SUB		i,i,hs	* i <- i - h
		PBNN	i,4B	* To D4 if i < 0
6H		ADD		ih,i,hs		* i <- i + h
		STO		r,record,ih	 * Ri+h <- Rj
		CMP		t,j,SIZE	 * j == upper bound
		PBNP	t,2B	* To D2 if j < N
		CMP		t,s,HLEN
		BZ		t,Return
		INCL	s,1	* s <- s + 1
		JMP		1B
Return	TRAP	0,Halt,0
