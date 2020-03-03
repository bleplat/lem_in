# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    lem_in_runfolder.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 19:42:40 by bleplat           #+#    #+#              #
#    Updated: 2020/03/03 19:42:41 by bleplat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RST_FILE=lem_in_runfolder_results.tmp

DIR=$1
if [ -z "$DIR" ]; then
	printf "\e[31mYou must specify a folder!\e[0m\n"
	exit 1
fi

# Is lem_in missing:
if [ -z "$(ls -1 . | grep 'lem-in$')" ]; then
	printf "\e[31mMissing lem-in, you should do 'make'!\e[0m\n"
	exit 1
fi

# Run with all files in the folder:
for f in $DIR/* ; do
	printf "\n\e[35mrunning ./lem-in < $f\e[0m\n" >> $RST_FILE 2>&1
	./lem_in < $f >> $RST_FILE 2>&1
done

# Show results
less $RST_FILE

exit 0
