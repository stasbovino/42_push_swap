if [ $# -eq 0 ]
then
	echo "Please enter a number of args to generate"
	exit 1
fi
awk -v loop=$1 -v range=$1 'BEGIN{
  srand()
  do {
    numb = 1 + int(rand() * range)
    if (!(numb in prev)) {
		{printf "%d", numb}
       prev[numb] = 1
       count++
	   if (count != loop)
		   {printf " "}
    }
  } while (count<loop)
}' > args.txt
echo "args are:"
cat args.txt
printf "\n\n"
if [ "$2" == "full" ]
then
	ARG=`cat args.txt`; ./push_swap $ARG
	exit 0
fi
printf "checker: "
ARG=`cat args.txt`; ./push_swap $ARG | ./checker $ARG
printf "operations: "
ARG=`cat args.txt`; ./push_swap $ARG | wc -l
printf "if you want to watch all operations rerun with *arg* full\n"
