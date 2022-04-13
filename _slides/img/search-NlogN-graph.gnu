set terminal pngcairo  font "arial,10" fontscale 1.0 size 500, 350 
set output 'search-NlogN-graph.png'
set key inside left top vertical Right noreverse enhanced autotitles box linetype -1 linewidth 1.000
set samples 50, 50
#set logscale y
plot [2:256] x,log10(x)/log10(2)
