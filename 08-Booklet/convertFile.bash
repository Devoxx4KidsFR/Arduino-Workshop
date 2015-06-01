#!/bin/bash

pdfname=$1
echo "converting $pdfname"
name=$(basename "$pdfname" .pdf)
psname=$( echo "ps/${name}.ps" | sed -e 's/ /_/g' )
echo "to $psname"
pdf2ps "$pdfname" "$psname"
