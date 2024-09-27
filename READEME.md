To run my code, you must first have the file needed to execute the functions you want. Since we are using "Programmint-Project-1.txt", we don't need to create another file to run this program. You will also need to make and then type "./project1" as the executable.
The code will read the file and store the values in their correct places based on order. So it will store "ADD" "0x1" "0x1" and will exectute based on that program.
Next, you simply need to make sure that all operations in front of the numbers are the commands you want the program to execute. 
Once the program recognizes the order of values, it will store them so that i can convert the data into decimal.
After it converts into decimal, the program will add both numbers together and store that value in result.
For the overflow check, we simply use a string to display weather an result is overflowed or not.
The program than takes the two numbers and converts them into ulong data type casts with 64 bits. It then adds these two numbers together and checks if the result is larger than the max which is 4,294,967,295. If it is, then overflowed will return "Yes" and will return "No" if it doesn't exceed the limit.
Finally, the program will print out the result and the overflow check once the program runs.

