(* Specification of trees using set oriented view *)
------------------------------- MODULE TreeSet ------------------------------- 
CONSTANT Key
LOCAL INSTANCE Naturals
LOCAL INSTANCE Sequences
LOCAL INSTANCE FiniteSets
-----------------------------------------------------------------------------
IsTree(T) == \* True if T is a tree
  /\ T = [node |-> T.node, edge |-> T.edge]
  /\ \E r \in T.node : \A e \in T.edge : e[1] # r \* root existence
  /\ \E e, f \in T.edge : (e[1] = f[1]) => (e = f) \* e[1], f[1] = children,

Root(T) ==
  /\ IsTree(T)
  /\ {CHOOSE r \in T.node : \E e \in T.edge : e[1] = r}
-----------------------------------------------------------------------------
(* From now on, binary trees are focused *)
IsBinaryTree(T) == \* True if T is a tree
  /\ IsTree(T)
  /\ \A n \in T.node : Cardinality( {e \in T.edge : e[2] = n} ) <= 2

TransversePreorder(T) == (* visit the root, transverse the left subtree, and the the right *)
  /\ IsBinaryTree(T)
  /\ LET TP[P, R, n \in T.node] ==
  	  		 /\ Append(P, n)
  	  		 /\ \E e, f \in T.node : /\ e[2] = n /\ f[2] = n
			 	   	  			   	 /\ IF e[1] # <<>> /\ f[1] # <<>> THEN TP[P, R, e[1]]   /\ Append(R, f[1])
  	  	 	 						 	   		ELSE IF f[1] # <<>> \/ R # <<>> THEN TP[P, R, Head(R)]
				 	 								 	ELSE P
  		 IN TP[<<>>, <<>>, Root(T)]

IsBinarySearchTree(T) ==
  /\ IsBinaryTree(T)
  /\ \A e, f \in T.edge : (e[2] = f[2]) => (e[2] > e[1]) /\ (e[2] < f[1])

Path(T) ==
  {p \in Seq(T.node) : /\ p # <<>>
  	 	 			   /\ \A i \in 1..(Len(p)-1) : <<p[i], p[i+1]>> \in T.edge}

Find(T, k) ==
  CHOOSE n \in T.node : T.node.key = k


Insert(T, k) ==
  /\ Find(T, k) = <<>>
  /\ T.node' = Append(T.node, <<k>>)
  /\ LET T[n \in T.node] ==
  	 	 {c \in T.node\n : <<n,c>> \in T.edge} :
		 	
  
	 IN 

==========================================================================================
