for ((i=99; i>=0; i--));
do 
	if (( $i == 0 ))
	then
		printf $i;
	else
		printf "$i ";
	fi
done > b.txt
ARG=`cat b.txt`; ./push_swap $ARG | wc -l
