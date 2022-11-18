echo "Enter Number"
read n
rem=$((n % 4))
case $rem in 
    0) echo "Zero";;
    1) echo "One";;
    2) echo "Two";;
    *) echo "Three"
esac
