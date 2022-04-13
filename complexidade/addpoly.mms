% status=nope
% name=Algorithm A
% task=Addition of polynomials

q2		IS 		$255   % Q2
tp		GREG	0	   % Temporary register for P
tq		GREG	0	   % Same for Q
t		GREG	0	   % Temporary register
p 		IS		$0	   % P polynomial
q 		IS		$1	   % Q
q1		IS		$3	   % Q1
COEF	IS	0
ABC		IS	4
LINK	IS	8
	LOC		#100
	SET		q1,q		% Q1 <- Q
	LDO		q,q,LINK	% Q <- LINK(Q)
0H	LDO		p,p,LINK	% P <- LINK(P)
	LDT		tp,p,ABC	% $254 <- ABC(P)
	LDT		tq,q,ABC	% $253 <- ABC(Q)
2H	CMP		t,ep,eq		% A2. ABC(P):ABC(Q)
	PBZ		t,3F		% If equal, go to A3
	PBP		t,5F		% If greater, go to A5
	SET		q1,q		% If less, set Q1 <- Q
	LDO		q,q1,LINK	% Q <- LINK(Q1)
	JMP		2B			% Repeat
3H	LDT		tp,p,COEF	% $254 <- COEF(P)
	LDT		tq,q,COEF	% $254 <- COEF(P)
	ADD		t,tp,tq		% $255 <- COEF(P) + COEF(Q)
	STT		t,q,COEF	% COEF(Q) <- $255
	PBNZ	t,1B		% Probably branch if nonzero
	SET		q2,q		% A4. Delete zero term. Q2 <- Q
						%%% must add AVAIL <-- Q2 ?
	STO		q1,q,LINK	% LINK(Q1) <- Q
	JMP		0B			% Go to advance P.
5H	SET		q2,AVAIL
	LDT		t,p,COEF	% $255 <- COEF(P)
	STT		t,q2,COEF	% COEF(Q2) <- COEF(P)
	STO		q,q2,LINK	% LINK(Q2) <- Q
	STO		q2,q1,LINK	% LINK(Q1) <- Q2
	SET		q1,q2		% Q1 <- Q2
	JMP		0B			% Go to advance P. [[]]
	