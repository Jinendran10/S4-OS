x=1
while [ $x -eq 1 ]
do
	echo "1.Addition
	      2.Subtraction
	      3.Multiplication
	      4.Division
	      5.Exit
	      Enter your choice:"
	read ch
	echo "Enter the numbers to operate"
	read n1 n2
	case $ch in
	1) echo $(( $n1 + $n2 ));;
	2) echo $(( $n1 - $n2 ));;
	3) echo $(( $n1 * $n2 ));;
	4) echo $(( $n1 / $n2 ));;
	5) x=0;;
	*) echo "Invalid choice";;
	esac
done


	 
	      
	   
