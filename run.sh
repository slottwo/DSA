cd $1
echo ======== Compilation ======== && echo
echo - Remove $1
rm -f $1
echo - Compiling *.c
gcc -c $1.c
gcc -c main.c
echo - Montage $1
gcc -o $1 main.o $1.o
echo - Removing *.o
rm *.o 
echo - Running $1
echo && echo ========== Running ========== && echo
./$1
echo && echo ============ End ============