echo "Enter Number:"
read n

first=0
second=1

for (( i=0; i < n; i++))
do 
    echo -n "$first "
    temp=$((first + second))
    first=$second
    second=$temp
done
