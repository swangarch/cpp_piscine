#!/bin/bash

for n in {1..3000}; do
    echo -n "Testing n=$n  "
    ./PmergeMe $(shuf -i 1-100000 -n $n | tr "\n" " ") | grep "After:" | awk '{print "After:", $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, "..."}'
done

echo "Done, PmergeMe can sort from 1 to 3000 numbers"

for n in {1..100}; do
    echo "Testing n=$n"
    ./PmergeMe $(shuf -i 1-100000 -n $n | tr "\n" " ") | grep "After:" | awk '{print "After:", $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, "..."}'
    ./PmergeMe $(shuf -i 1-100000 -n $n | tr "\n" " ") | grep "After:" | awk '{print "After:", $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, "..."}'
    ./PmergeMe $(shuf -i 1-100000 -n $n | tr "\n" " ") | grep "After:" | awk '{print "After:", $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, "..."}'
done

echo "Done, PmergeMe can sort from 1 to 100 numbers"

#./PmergeMe 4 12 10 1 19 9 17 8 13 3 11 15 16 2 7 5 18 14 6 20 21