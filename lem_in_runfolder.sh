DIR=$1
if [ -z "$DIR" ]; then
	printf "\e[31mYou must specify a folder!\e[0\n"
	exit 1
fi

# Is lem_in missing:
if [ -z "$(ls -1 . | grep 'lem_in$')" ]; then
	printf "\e[31mMissing lem_in, you should do 'make'!\e[0\n"
	exit 1
fi

# Run with the folder itself:
printf "\n\e[35mrunning ./lem_in < $DIR\e[0m\n"
./lem_in < "$DIR"

# Run with all files in the folder:
for f in $DIR/* ; do printf "\n\e[35mrunning ./lem_in < $f\e[0m\n"
	./lem_in < $f
done

exit 0
