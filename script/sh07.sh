export BASH
echo "The script name is ==> $0"
echo "Total parameter number is ==> $#"
[ "$#" -lt 2 ] && echo "The number of parameter is less than 2. Stop here." && exit 0
echo "Your whole parameter is ==> $@"
echo "Your 1st parameter     ==>$1"
echo "Your 2nd parameter     ==>$2"
