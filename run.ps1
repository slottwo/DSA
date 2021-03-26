<#
.SYNOPSIS
Shows when last your PC started up.
.DESCRIPTION
This is a WMI wrapper function to get the time that your PC last started up.
.PARAMETER ProjectName
Name of folder and TDA module file
.EXAMPLE
run -ProjectName matrix
.LINK
https://github.com/slottwo/DSA/
#>

$ProjectName=$args[0]

echo "Go to $ProjectName\" ""

cd $ProjectName

echo "Compiling *.c" ""

gcc -c main.c
gcc -c "$ProjectName.c"

echo "Montage $ProjectName" ""

gcc main.o "$ProjectName.o" -o "$ProjectName.exe"

echo "Removing *.o" ""
rm *.o

echo "Running $ProjectName" ""

$ProjectName.exe

cd ..
