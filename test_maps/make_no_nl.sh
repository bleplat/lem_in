file=$1
if [ -z "$file" ]; then
	printf "\e[31mA file name is needed!\e[0m\n"
fi

length=$(wc -c <$file)
if [ "$length" -ne 0 ] && [ -z "$(tail -c -1 <$file)" ]; then
  dd if=/dev/null of=$file obs="$((length-1))" seek=1
fi
