------------------------------- MODULE BinarySearchTree ----------------------------- 
EXTENDS BinaryTree
--------------------------------------------------------------------------------
Find(k) ==
  LET S[n \in node] ==
  	IF k = n.key THEN n
	   ELSE	 IF k < n.key THEN S[n.left]
	   ELSE	 S[n.right]
  IN S[root]
Insert(k) ==
  /\ Search(k) = <<>>
  /\ LET I[n \in node] ==
  	 	 IF root = <<>> THEN (root = <<k>>) /\ (node \union root)
	 	 	ELSE IF k < n.key /\ n.left = <<>> THEN n.left = <<k>>
	   	 		 ELSE	 IF k > n.key /\ n.right = <<>> THEN n.right = <<k>>
	   			 ELSE	 I[n.right]
  	 IN I[root]

BSTNext == \E k \in Key : \/ Search(k) \/ Insert(k)
--------------------------------------------------------------------------------
BSTSpec == [][BSTNext]_<<root,node>>
--------------------------------------------------------------------------------
THEOREM BSTSpec => [] BTTypeInv
================================================================================