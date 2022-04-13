------------------------------- MODULE Trees ------------------------------- 

CONSTANT Key
LOCAL INSTANCE Naturals
LOCAL INSTANCE Sequences
-----------------------------------------------------------------------------
IsTree(T) == \* True if T is a tree
  /\ T = [node |-> T.node, root |-> T.root]
  /\ T.node = [key |-> Key, children |-> T.node]
  /\ T.root = CHOOSE r \in T.node : \A n \in T.node : r \notin n.children \* root is not children of anyone
-----------------------------------------------------------------------------
(* From now on, binary trees are focused *)
IsBinaryTree(T) == \* True if T is a tree
  /\ T =  CHOOSE r \in T.node : \A n \in T.node : r \notin n.children \* root is not children of anyone
  /\ T.node = [left |-> T.node, key |-> Key, right |-> T.node]

TransversePreorder(T) == (* visit the root, transverse the left subtree, and the the right *)
  LET TP[P, R, n \in T.node] ==
  	  /\ IsBinaryTree(T)
  	  /\ Append(P, n)
  	  /\ IF n.left # <<>> /\ n.right # <<>> THEN TP[P, R, n.left]   /\ Append(R, n.right)
  	  	 	ELSE IF n.right # <<>> \/ R # <<>> THEN TP[P, R, Head(R)]
				 ELSE P
  IN TP[<<>>, <<>>, T]

Find(T, k) ==
  /\ IsBinaryTree(T)
  /\  LET S[n \in T.node] ==
  		IF k = n.key THEN n
	   	   ELSE	 IF k < n.key THEN S[n.left]
	   	   		 ELSE	 S[n.right]
  	IN S[T]

Insert(T, k) ==
  /\ IsBinaryTree(T)
  /\ Find(T, k) = <<>>
  /\ LET I[n \in T.node] ==
  	 	 IF T.root = <<>> THEN (T.root = <<k>>) /\ (T.node \union T.root)
	 	 	ELSE IF k < n.key /\ n.left = <<>> THEN n.left = <<k>>
	   	 		 ELSE	 IF k > n.key /\ n.right = <<>> THEN n.right = <<k>>
	   			 ELSE	 I[n.right]
  	 IN I[T]


=============================================================================
