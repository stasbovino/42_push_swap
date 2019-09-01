for ((i=99; i>=0; i--));
do 
	if (( $i == 0 ))
	then
		echo -n $i;
	else
		echo -n "$i ";
	fi
done > b.txt
