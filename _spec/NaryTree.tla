------------------------------- MODULE NaryTree ------------------------------- 
EXTENDS Tree
VARIABLE root
-----------------------------------------------------------------------------
TypeInvariant ==
  /\ root \in [key:Key, children:Node\root]
Search(k) ==
  LET S[n \in Node] ==
  	  IF k = n.key THEN n.key
  	 	  		ELSE \A i \in Len(n.children) : 
					 	  	   	   /\ IF n.children[i] = k THEN k
								   	  	 ELSE S[n.children[i]]
  IN S[root]
=============================================================================
