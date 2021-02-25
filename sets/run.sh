# Remove old
rm -i set
# Compile
gcc -c set.c
gcc -c main.c
# Montage
gcc -o set main.o set.o
# Remove *.o
rm *.o
# Execute
./set
