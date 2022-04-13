main.pdf: main.tex binary.tex /tmp/pre.tex /tmp/in.tex /tmp/post.tex
	$(LATEX) $<

/tmp/pre.tex: src/tree.lua
	lua $< -pre > $@

/tmp/in.tex: src/tree.lua
	lua $< -in > $@

/tmp/post.tex: src/tree.lua
	lua $< -post > $@



include ../Makefile
