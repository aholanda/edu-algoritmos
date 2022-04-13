local BinaryTree = {}
local BinaryTreeNode = {}
local step = 0
local level = 0

function metaprint(str)
   if tex then
      tex.sprint(str)
   else
      print(str)
   end
end

function BinaryTreeNode.new (key)
   return {key = key, left = nil, right = nil};
end

function BinaryTree.add (tree, key)   
   if key < tree.key then
      if tree.left then
	 BinaryTree.add(tree.left, key)
      else
	 tree.left = BinaryTreeNode.new(key)
	 return tree.left
      end
   elseif key > tree.key then
      if tree.right then
	 BinaryTree.add(tree.right, key)
      else
	 tree.right = BinaryTreeNode.new(key)
	 return tree.right
      end
   else
      return tree
   end
end

function BinaryTree.visit(tree, step)
   metaprint(string.format('\\fill<%d>[visit] (T%d) circle (10pt);', step, tree.key))
end

-- pre-order traversal
function BinaryTree.pre (tree)
   if (tree) then
      step = step + 1
      BinaryTree.visit(tree, step)
      BinaryTree.pre(tree.left)
      BinaryTree.pre(tree.right)
   end
end

-- simetric traversal
function BinaryTree.simet (tree)
   if (tree) then
      BinaryTree.simet(tree.left)
      step = step + 1
      BinaryTree.visit(tree, step)
      BinaryTree.simet(tree.right)
   end
end


-- post-order traversal
function BinaryTree.post (tree)
   if (tree) then
      BinaryTree.post(tree.left)
      BinaryTree.post(tree.right)
      step = step + 1
      BinaryTree.visit(tree, step)
   end
end

local function indent(n)
   local spc = ""
   for i=1,n do spc = spc .."\t" end
   return spc
end

local str = ""
function tikz_traverse(tree)
   local spc = nil

   if not tree then
      return
   end
   
   if level == 0 then
      str = str..string.format('\\node[treenode] (T%d) {%d}', tree.key, tree.key)
   else
      spc = indent(level)
      str = str..string.format('\n%schild { node[treenode] (T%d) {%d}', spc, tree.key, tree.key)
   end

   level = level + 1
   
   tikz_traverse(tree.left)
   tikz_traverse(tree.right)

   level = level - 1
   
   if level==0 then
      str = str..";"
   else
      str = str..string.format('\n%s}',spc)
   end
end
   
function bintree_create()
   local tikz = ""
   local root = BinaryTreeNode.new(55)
   BinaryTree.add(root, 23)
   BinaryTree.add(root, 44)
   BinaryTree.add(root, 17)
   BinaryTree.add(root, 66)
   BinaryTree.add(root, 77)
   BinaryTree.add(root, 60)

   tikz_traverse(root)
   metaprint(str)
   
   return root;
end

function main()
   metaprint("\\tikzset{->,>=latex"..
		",every node/.style={font=\\sffamily,text width=1.5em,circle,draw}"..
		",visit/.style={fill=red,opacity=0.5}"..
		",level/.style={sibling distance=3cm, level distance=1.5cm }"..
		",treenode/.style={align=center, inner sep=0pt, text centered, very thick}"..
		"}")

   root = bintree_create()

   if arg[1] == "-pre" then
      BinaryTree.pre(root, BinaryTree.visit)
   elseif arg[1] == "-in" then
      BinaryTree.simet(root, BinaryTree.visit)
   elseif arg[1] == "-post" then
      BinaryTree.post(root, BinaryTree.visit)
   else
      error(string.format("usage: %s [ -pre -in -post ]", arg[-1]))
   end
end

if not tex then
   main()
end
