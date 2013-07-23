gcc gen_test.c -o gen_test.out
g++ karatsuba.cpp -o karatsuba.out

rm -rf results.dat
for i in 10 100 1000 10000 100000
do
    ./gen_test.out $i > test.inp
    ./karatsuba.out < test.inp 2>> results.dat > res_karatsuba
    time ./mult.bc < test.inp | tr -d '\\' | tr -d '\n' > res_bc
    diff res_karatsuba res_bc
done
rm -rf res_* 
