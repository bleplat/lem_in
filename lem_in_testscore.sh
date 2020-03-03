FLOW=$1
if [ -z "$FLOW" ]; then
	printf "\e[31mYou must specify the generator's flow argument!\e[0m\n"
	printf "\e[91mPossible values are:\e[0m\n"
	printf "\e[91m\t--flow-one\e[0m\n"
	printf "\e[91m\t--flow-ten\e[0m\n"
	printf "\e[91m\t--flow-thousand\e[0m\n"
	printf "\e[91m\t--big\e[0m\n"
	printf "\e[91m\t--big-superposition\e[0m\n"
	exit 1
fi
CNT=$2
if [ -z "$CNT" ]; then
	printf "\e[31mYou must specify a test count!\e[0m\n"
	exit 1
fi

# Is lem_in missing:
if [ -z "$(ls -1 . | grep 'lem-in$')" ]; then
	printf "\e[31mMissing lem-in, you should do 'make'!\e[0m\n"
	exit 1
fi

# Run with all files in the folder:
for (( i=0; i<$CNT; ++i)); do
	if [ $i -gt 0 ]; then sleep 1; fi
	./generator $FLOW > map.tmp
	EXPECTED=$(cat map.tmp | tail -n 1 | sed "s/^.*: \(.*\)$/\1/")
	LINES=$(cat map.tmp | wc -l | sed "s/^ *\(.*\)$/\1/")
	printf "\e[97mTesting a map of $LINES lines:\n\e[0m"
	printf "\e[92mExpect: $EXPECTED\n\e[0m"
	RST=$(./lem-in < map.tmp | grep '^L' | wc -l | sed "s/^ *\(.*\)$/\1/")
	printf "\e[93mResult: $RST\n\e[0m"
	printf "\n"
done


exit 0
