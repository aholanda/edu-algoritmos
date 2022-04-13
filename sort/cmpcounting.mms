% status=todo_test
% Algorithm S from TAOCP3 pg 76
% Comparison counting program
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
LENGTH 	IS  8	% KEY|COUNT
SIZE   	IS  15*LENGTH
Record	GREG	@
		OCTA	Data_Segment,Data_Segment+LENGTH,Data_Segment+LENGTH*2
		OCTA	Data_Segment+LENGTH*3,Data_Segment+LENGTH*4,Data_Segment+LENGTH*5
		OCTA	Data_Segment+LENGTH*6,Data_Segment+LENGTH*7,Data_Segment+LENGTH*8
		OCTA	Data_Segment+LENGTH*9,Data_Segment+LENGTH*10,Data_Segment+LENGTH*11
		OCTA	Data_Segment+LENGTH*12,Data_Segment+LENGTH*13,Data_Segment+LENGTH*14
record	IS		Record
Count	GREG	@
count	IS		@n

		
		LOC	 #100
Main	SET	 ii,0		% 1		i <- 0
1H		LDOU 0,count,ii	% N		C1. Clear COUNTs
		ADDU ii,ii,8	% N		i++
		CMP	 t,ii,SIZE	% N		
		PBNN t,1B		% N
		SET	 ii,SIZE	% i <- N
2H		LDO	 ri,record,ii % Ri
		SUB	 jj,ii,8	% j <- i - 1

		

Return	TRAP 0,Halt,0		* 1
