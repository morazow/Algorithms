gcc gen_test.c -o gen_test.out
g++ karatsuba.cpp -o karatsuba.out

for i in $1 
do
    ./gen_test.out $i > test.inp
    ./karatsuba.out < test.inp > res_karatsuba
    ./mult.bc < test.inp > res_bc
    diff res_karatsuba res_bc
done
rm -rf res_*

