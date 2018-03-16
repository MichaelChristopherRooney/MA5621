if [ "$#" -ne 1 ]; then
	num_runs=100
else
	if [ "$1" -eq 0 ]; then
		echo "ERROR: parameter must be > 0"
		exit
	fi
	num_runs=$1
fi

# Validate file exists
if [ ! -f simple_mc ]; then
	echo "Cannot find simple_mc program - please ensure it is in this directory"
	exit
fi

num_correct=0

for num in $(seq 1 1 $num_runs); do
	output=`./simple_mc $RANDOM`
	result=${output: -2:1} # get either "y" or "n" from the output
	if [ "$result" == "y" ]; then
		num_correct=$(( num_correct + 1 ))
	fi
done

# Note use of scale to limit precision to 2 decimal places.
ratio=`echo "scale=2; ($num_correct * 100) / $num_runs" | bc -l`
echo "$ratio%"
