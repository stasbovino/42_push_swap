awk -v loop=$1 -v range=10000 'BEGIN{
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
}' > kek.txt
ARG=`cat kek.txt`; ./push_swap $ARG 