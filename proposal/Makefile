proposal.pdf : proposal.dvi
	pdflatex proposal

proposal.dvi : proposal.bib proposal.tex
	latex proposal
	bibtex proposal
	latex proposal
	latex proposal

clean : 
	rm proposal.pdf proposal.dvi proposal.aux proposal.bbl proposal.blg proposal.log proposal.toc
