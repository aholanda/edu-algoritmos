------------------------------- MODULE BinaryTree ----------------------------- 
EXTENDS Tree, DataInterface
VARIABLE root, node
RECURSIVE Node
Node == [key:Key, left:Node, info:Info, right:Node]
--------------------------------------------------------------------------------
BTInit == 
  /\ node = <<>>
  /\ root = node
BTTypeInv ==
  /\ node \in Node
  /\ root \in node 
RootConstraint ==
  \A n \in node : n.left # root /\ n.right # root
--------------------------------------------------------------------------------
TransversePreorder(r) == (* visit the root, transverse the left subtree, and the the right *)
  LET TP[P, R, n \in node] ==
   	  /\ Append(P, r)
  	  /\ IF n.left # <<>> /\ n.right # <<>> THEN TP[P, R, n.left] /\ Append(R, n.right)
  	  	 	ELSE IF n.right # <<>> \/ R # <<>> THEN TP[P, R, Head(R)]
				 ELSE P
  IN TP[<<>>, <<>>, r]

Next == \E n \in Node : TransversePreorder(n)
Spec == [][Next]_<<node, root>>
--------------------------------------------------------------------------------
THEOREM Spec => []BTTypeInv /\ []RootConstraint
================================================================================