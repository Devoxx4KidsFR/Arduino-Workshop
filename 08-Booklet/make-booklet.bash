#!/bin/bash
sudo apt-get update
sudo apt-get install ghostscript
sudo apt-get install psutils

## faire le combine a la main avec imposition

#rm -rf ps
#mkdir -p ps

#./convertFile.bash ../Cover-Presentations.pdf
#find ../00-Presentations -name "PR*.pdf"  -exec ./convertFile.bash '{}' \;
#psmerge -oCombined.ps Cover-Presentations.ps $(ls ps/PR*.ps)

#pdf2ps Presentations-01-07.pdf - | psbook | psnup -s1 -2 | ps2pdf - Presentations-01-07_booklet.pdf

####pdf2ps Presentations.pdf - | psbook | psnup  -2 | ps2pdf - Presentations_booklet.pdf
####pdf2ps Lumiere.pdf - | psbook | psnup  -2 | ps2pdf - Lumiere_booklet.pdf
pdf2ps Musique.pdf - | psbook | psnup  -2 | ps2pdf - Musique_booklet.pdf
