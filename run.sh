cp KryzstofKudlakIndex.c KryzstofKudlakIndex.lex;
flex KryzstofKudlakIndex.lex;
gcc lex.yy.c;

./a.out < grettis_saga.en.txt > index.csv
sort index.csv -t "," -k1,1d -k2,2g -k3,3g > indexSorted.csv
