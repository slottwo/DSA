# Remove old
rm -i matrix
# Compile
gcc -c matrix.c
gcc -c main.c
# Montage
gcc -o matrix main.o matrix.o
# Remove *.o
rm *.o
# Execute
./matrix
