if [ $# -eq 0 ]
then
	echo "Please enter a number of args to generate"
	exit 1
fi
for ((i=$1 - 1; i>=0; i--));
do 
	if (( $i == 0 ))
	then
		printf $i;
	else
		printf "$i ";
	fi
done > descending_args.txt
ARG=`cat descending_args.txt`; ./push_swap $ARG | wc -l
