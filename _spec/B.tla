------------------------------MODULE B------------------------------
EXTENDS Naturals, Sequences,Reals
CONSTANTS Key, Index
ASSUME (Key \in Nat) /\ (Index \in Nat) /\ (Index \geq 0)
VARIABLE key,u,l,i
--------------------------------------------------------------------
Init			==
	 			/\	key \in	[Index -> Key]
				/\	u = Len(key)
				/\	l = 0				
				/\	i = -1
				
TypeInvariant 	== 
	 			/\ key \in [Index -> Key]
				/\ (u = CHOOSE c : c \in Index)  (* choose one value from Index set *)
				/\ (l = CHOOSE c : c \in Index)
				/\ i \in {-1,Index}

BSearch(k)		== RETHINK
				LET BS[C \in SUBSET K] ==
					IF u < l THEN i = -1
					ELSE i = (u+l)/2  
						 IF k > key[i]
						 	THEN l = i + 1 /\ BSearch(k\{CHOOSE i : i \in Key})
						 	ELSE u = i - 1
									  
									  
Next == \exists k \in Key : BSearch(k)

Spec == Init /\ [][Next]_<<key,u,l,i>>
-------------------------------------------------------------------
THEOREM Spec => []TypeInvariant
===================================================================