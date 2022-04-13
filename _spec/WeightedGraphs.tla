------------------------------- MODULE WeightedGraphs ------------------------------- 
EXTENDS Graphs, Naturals
CONSTANT Distance
ASSUME (Distance \in Nat) /\ (Distance > 0)

IsWeightedDirectedGraph(W) ==
  /\ W = [node |-> W.node, edge |-> W.edge]
  /\ W.edge \subseteq (W.node \X W.node) \X SUBSET(Distance)

Dijkstra(v, W) ==
  /\ p \in Seq(W.node) :
  	 /\ p # <>
	 /\ LET [z \in W.node] ==
	 	I STOP HERE

--------------------------------------------------------------------------------
================================================================================