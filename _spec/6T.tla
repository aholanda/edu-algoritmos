-----------------------------------MODULE BinaryTree-----------------------------------
CONSTANTS Key, Node
VARIABLES T,p,q,head
---------------------------------------------------------------------------------------


TypeInvariant	==
	/\ T \in [Node]

Search[k \in Key,q \in Node] ==
	/\ IF T \in \emptyset THEN head' = head EXCEPT 
	   	  				  ELSE IF k = q.key THEN "Found"
						  ELSE IF k < q.key THEN Search[k,q.left]
						  ELSE Search[k,q.right]

-------------------------------------------------------------------
THEOREM Spec => []TypeInvariant
===================================================================