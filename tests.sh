run_test(){
    echo $1
    ./main $1
}

echo "no args"
./main

run_test one,plus
run_test un,plus,tree
run_test one,plus,three
run_test four,times,six
run_test ten,times,ten
run_test eight,divided,three
run_test four,modulo,seven
run_test zero,minus,ten
run_test one,minus,ten