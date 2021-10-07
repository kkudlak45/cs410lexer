./compile.sh
./a.out < grettis_saga.en.txt > unsorted.csv
sort unsorted.csv -t "," -k1,1d -k2,2g -k3,3g > sorted.csv
