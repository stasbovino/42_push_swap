ARG=$*; ./push_swap $ARG
ARG=$*; ./push_swap $ARG | ./checker $ARG
ARG=$*; ./push_swap $ARG | wc -l
