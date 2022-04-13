LATEX	:= xelatex
PDF2SWF	:= pdf2swf
DOTS	:= $(wildcard *.dot)
PDOTS	:= $(patsubst %.dot, %.pdf, $(DOTS))

.SECONDEXPANSION:
$(PDOTS): $$(patsubst %.pdf, %.dot, $$@)
	dot -Tpdf $< > $@

%.pdf: %.tex
	$(LATEX) $<

%.swf: %.pdf
	$(PDF2SWF) $<

#I-APPENDIX
.PHONY: $(phonies)

trash += *.png *.swf

# output format of the presentation and graphviz produced files
T=pdf
# program to create undirected graphs
GRAPH=neato
# program to create directed graphs
DIGRAPH=dot
# directory of graphviz dot files
VIZDIR=dot

.PHONY: clean

lec: 01southam 01list
	$(LATEX) lec.tex

01southam:
	$(GRAPH) -T$(T) -Gepsilon=.00001 01southam_color.dot >01southam_color.$(T)
	$(GRAPH) -T$(T) -Gepsilon=.00001 01southam_nocolor.dot >01southam_nocolor.$(T)

01list:
	$(DIGRAPH) -T$(T) 01list_graph.dot >01list_graph.$(T)
	$(DIGRAPH) -T$(T) 01list_digraph.dot >01list_digraph.$(T)

include ../../Makefile
