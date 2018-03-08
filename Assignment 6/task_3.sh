declare -a drawn=(0 0 0 0 0 0) # stores numbers drawn so far
num_drawn=0 # how many draws have been made already

lowest=1
highest=45

for i in {0..5}
do
	ran=$(( (RANDOM % ($highest + 1 - $lowest) + $lowest) ))
	echo "$ran"
done
