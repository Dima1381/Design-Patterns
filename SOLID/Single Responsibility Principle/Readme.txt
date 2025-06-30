
===========================================================
	S - Single Responsibility Principle (SRP)
===========================================================

SRP basically states that a class should have a single reason/responsibility for changing.
In other words, the class should have the primary responsibility and should not take on other responsibilities.


======================
	Example
======================

Here are some simple real-world examples from “Car Service”

A bad approach (without SRP) is that the mechanic:
- Check the car
- Repair the car
- Write a check to the customer
- Accept payment

A good approach (with SRP):
- Mechanic: Work with the car.
- Manager: Work with the customer.
- Cashier: Accept payment.


Here you can find the file "SRP.cpp" where I will show the use of SRP with a simple example.
