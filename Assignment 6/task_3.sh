# Stores numbers drawn so far
declare -a drawn=(0 0 0 0 0 0)

# How many draws have been made already
num_drawn=0 

lowest=1
highest=45

# Generate a random number then check if the above array already contains it.
# If so then continue to generate random numbers until an unused one is found
for i in {0..5}
do
	number_unused=0
	while [ $number_unused -ne 1 ]; do
		number_unused=1
		ran=$(( (RANDOM % ($highest + 1 - $lowest) + $lowest) ))
		n=0
		while [ $n -lt $num_drawn ]; do
			if [ ${drawn[$n]} -eq $ran ]; then
				number_unused=0
			fi
			n=$(( n + 1 ))
		done
	done
	drawn[i]=$ran
	num_drawn=$(( num_drawn + 1 ))
	echo "$ran"
done
