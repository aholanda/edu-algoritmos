------------------------------ MODULE MCGraph ------------------------------
EXTENDS Graphs
CONSTANTS Node
VARIABLE gr
NoNode == CHOOSE n : n \notin Node
Edge == SUBSET(Node \X Node)
NoEdge == CHOOSE e : e \notin Edge
----------------------------------------------------------------------
MCTypeInvariant ==
 /\ gr \in [node : Node \cup {NoNode}, edge : Edge \cup {NoEdge}, v : BOOLEAN]
MCInit ==
 /\ gr = [node |-> NoNode, edge |-> NoEdge, v |-> FALSE]

isGraph(g) == g = [node |-> g.node, edge |-> g.edge, v |-> g.v]

MCNext ==
  \/ IsDirectedGraph(gr) \/ IsUndirectedGraph(gr)
  \/ IsTreeWithRoot(gr, gr.node)
----------------------------------------------------------------------------
MCSpec == MCInit /\ [][MCNext]_<<gr>> /\ []isGraph(gr)
THEOREM MCSpec => MCTypeInvariant
======================================================================
