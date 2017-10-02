Powers of Two
by Eva "Bunny" Conti
--------------------------

Hello! This is my first C++ project. It runs from the command line and allows users to enter a value, n, as the desired power of two. Then it prints out all of the values between 0 and n in both descending and ascending order.

It has some very basic user error mitigation, such as:

	- Limiting the max integer allowed
	- Refusing negative integers
	- Handling cases where a string is entered when expecting an integer
	- Dealing with fractions, floats, or other inputs where only the first part is a valid integer
	
Thanks to Ben Deane (@elbeno) for advising and helping me with some of the fancier bits.