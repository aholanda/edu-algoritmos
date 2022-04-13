----------------------------------- MODULE DataInterface ----------------------------------------
EXTENDS Naturals
CONSTANT Key,
		 Info,
		 Send(_, _, _, _, _), \* Send(key, info, op, dataInt, dataInt'), info is optional
		 Reply(_, _, _, _) \* Reply(key, info, dataInt, dataInt')
ASSUME (Key \in Nat) /\ (Key \geq 0)
----------------------------------------------------------------------------------------------
DReq == [op : {"Fnd"}, key: Key] \* Find
	         \cup [op : {"Ins"}, key: Key, info : Info] \* Insert
			 \cup [op : {"Del"}, key: Key, info : Info] \* Delete
NoInfo == CHOOSE i : i \notin Info
=============================================================================================