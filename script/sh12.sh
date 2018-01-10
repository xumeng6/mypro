echo "This program will print your selection!"
# read -p "input youe choice:" choice
# case $choice in
case $1 in
  "one")
	echo "your choice is ONE"
	;;
  "two")
	echo "your choice is two"
	;;
  "three")
	echo "your choice is three"
	;;
  *)
	echo "Usage $0 {one|two|three}"
	;;
esac
