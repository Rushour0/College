clear

echo -n "Enter string : "
read string

opt=0

while [ $opt -ne 5 ]
do
	clear
	echo "	Menu
1. Convert to Uppercase
2. Convert to Lowercase
3. Convert first alphabet to Uppercase
4. Convert first alphabet to Lowercase
5. Exit"

	read opt

	case $opt in
	
	1)	echo $string | tr '[a-z]' '[A-Z]'
		;;
		
	2)	echo $string | tr '[A-Z]' '[a-z]'
		;;
		
	3)	echo "${string^}"
		;;
		
	4)	echo "${string,}"
		;;
		
	5)	echo "Exiting"
		exit
		;;
	esac
	echo "Press any key to continue"
	read buffer
done
    