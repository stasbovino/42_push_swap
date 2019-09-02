num=(0 1 2)
s=0
n=0
last=0
if [ $# -eq 0 ]
then
	echo "Please enter a number of args to generate"
	exit 1
fi
while [ ${#num[@]} -lt $1 ]
do
	for ((i=0;i<${#num[@]};i++))
	do
		s=`expr $s + ${num[$i]}`
		if (( last < ${num[$i]} ));
		then
			last=${num[$i]}
		fi
	done
	n=$(((${#num[@]} + 1) * $last))
	n=`expr $n - $s`
	num+=( $n )
	s=0
done
for ((i=$1 - 1;i>=0;i--));
do
	if (( $i == 0 ))
	then
		printf ${num[$i]};
	else
		printf "${num[$i]} ";
	fi
done > worst_case.txt
ARG=`cat worst_case.txt`; ./push_swap $ARG | wc -l
