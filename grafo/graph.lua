local graph = {}
local step = 0

-- List definition: can be used as stack and queue
local List = {}
function List.new()
   return {first = 0, last = -1};
end

function List.pushfirst(list, value)
   local first = list.first - 1
   list.first = first
   list[first] = value
end

function List.pushlast(list, value)
   local last = list.last + 1
   list.last = last
   list[last] = value 
end

function List.popfirst(list, value)
   local first = list.first
   if first > list.last then return nil end
   local value = list[first]
   list[first] = nil -- allow garbage collection
   list.first = first + 1
   return value
end

function List.poplast(list, value)
   local last = list.last
   if list.first > last then return nil end
   local value = list[last]
   list[last] = nil
   list.last = last -1
   return value
end

local Stack = {}
function Stack.new ()
   return List.new()
end

function Stack.push (stack, value)
   List.pushlast(stack, value)
end

function Stack.pop (stack, value)
   return List.popfirst (stack, value)
end

local Queue = {}
function Queue.new ()
   return List.new()
end

function Queue.add (stack, value)
   List.pushfirst(stack, value)
end

function Queue.remove (stack, value)
   return List.popfirst (stack, value)
end


function metaprint(s)
   if tex then
      tex.print(s)
   else
      print(s)
   end
end

function id2node(graph, id)
   local node = graph[id]
   if not node then
      -- create a new node
      node = {id = id, adjs = {}, visited = false}
      graph[id] = node
   end
   return node
end  

function newarc(graph, u, v)
   local from = id2node(graph, u)
   local to = id2node(graph, v)
   from.adjs[v] = true
   metaprint(string.format('(V%d) %s (V%d);', u, "--", v))
end

function creategraph()
   metaprint("\\tikzset{V/.style={circle, draw},"..
		 "visit/.style={fill=red,opacity=.5},"..
		 "visited/.style={fill=gray,opacity=.5},"..
		 "walk/.style={line width=2pt, opacity=.5, red, draw},"..
		 "walked/.style={line width=2pt, opacity=.5, gray, draw}}")
   
   metaprint("\\node[V] (V1) at (0,0) {$1$};"..
		"\\node[V] (V2) at (-1,-1.2) {$2$};"..
		"\\node[V] (V3) at (0,-1.2) {$3$};"..
		"\\node[V] (V4) at (1,-1.2) {$4$};"..
		"\\node[V] (V5) at (-.8,-2.4) {$5$};"..
		"\\node[V] (V6) at (.3,-2.4) {$6$};"..
		"\\node[V] (V7) at (0,-3.4) {$7$};")
   
   metaprint("\\graph {")
   newarc(graph, 1, 2)
   newarc(graph, 1, 3)
   newarc(graph, 1, 4)
   newarc(graph, 2, 5)
   newarc(graph, 3, 6)
   newarc(graph, 4, 6)
   newarc(graph, 5, 6)
   newarc(graph, 5, 7)

   metaprint("};")
   return graph
end

function visit(step, node)
   metaprint(string.format('\\fill<%d>[visit] (V%d) circle (10pt);', step, node.id))
   metaprint(string.format('\\fill<%d->[visited] (V%d) circle (10pt);', step, node.id))
end

function dfs(graph, v)
   local from = id2node(graph, v)
   
   step = step + 1

   visit(step, from)
   from.visited = true
   
   for w in pairs(from.adjs) do
      local to = id2node(graph, w)
      if not to.visited then
   	 dfs(graph, to.id)
      end
   end
end

function rundfs()
   dfs(graph, 1)
end

function bfs(graph, v)
   local from = id2node(graph, v)
   local queue = Queue.new()
   local step = 1
   
   Queue.add(queue, from)
   visit(step, from)
   from.visited = true

   while true do
      local node = Queue.remove(queue)
      if not node then break end
         
      for w in pairs(node.adjs) do
	 local to = id2node(graph, w)
	 if not to.visited then
	    step = step + 1
	    Queue.add(queue, to)
	    visit(step, to)
	    to.visited = true
	 end
      end
   end
end
   
if not tex then
   graph = creategraph()
   dfs(graph, 1)
--   bfs(graph, 1)
end
