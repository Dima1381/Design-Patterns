
===========================================================
	O - Open-Close Principle (OCP)
===========================================================

OSP basically states that our system should be open to extention (so we should able to extence system),
but close to modifications.
	
======================
	Example
======================

Here are some simple real-world examples from “Car Service”

A bad approach (without OCP) is that class include all the futures:
- Check the car
- Repair the car
- Write a check to the customer
- Accept payment
- etc.

And here we will modifive the class to inctude new futures.


A good approach (with OCP):
- All futures implementing outside the class, where each function is united by a common interface


Here you can find the file "OCP.cpp" where I will show the use of OCP with a simple example.
