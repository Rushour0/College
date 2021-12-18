choice=0

while [ $choice -ne 5 ]
clear 
do 
	echo -n "	MENU
1)	Addition
2)	Subtraction 
3)	Division
4)	Multiplication
5)	Exit

Enter your choice : "
	
	# Reading the choice
	read choice
	
	# Case options
	case $choice in
		
		1) echo "Addition Choice is selected"
		echo -n "Enter first number : "
		read a
		echo -n "Enter second number : "
		read b
		echo "The addition of $a & $b is : " `expr  $a + $b`;;

		2) echo "Subtraction Choice is selected"
		echo -n "Enter first number : "
		read a
		echo -n "Enter second number : "
		read b
		echo "The subtraction of $b from $a is : " `expr  $a - $b`;;

		3) echo "Division Choice is selected"
		echo -n "Enter first number : "
		read a
		echo -n "Enter second number : "
		read b
		echo "The division of $a / $b is : " `expr  $a / $b`;;

		4) echo "Multiplication Choice is selected"
		echo -n "Enter first number : "
		read a
		echo -n "Enter second number : "
		read b
		echo "The multiplication of $a & $b is : " `expr  $a \* $b`;;
		
		5) echo "Exiting..." 
		exit;;
		*) echo "Out of bound";;
	esac
	echo "Press any key to continue..."
	
	# Taking input to proceed
	read buffer
	
done
