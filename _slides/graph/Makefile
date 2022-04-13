main.pdf: main.tex search.tex /tmp/bfs.tex /tmp/dfs.tex
	$(LATEX) $<

/tmp/bfs.tex: src/graph.lua
	lua $< > $@

/tmp/dfs.tex: src/graph.lua
	lua $< > $@

include ../Makefile

