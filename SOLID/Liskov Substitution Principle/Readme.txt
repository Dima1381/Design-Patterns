
===========================================================
	L - Liskov Substitution Principle (LSP)
===========================================================

LSP is specify that subtypes should be immediatly substitutable for their base type. 
	
======================
	Example
======================

Here are some simple real-world examples from “Car Service”

Base class: CarService
Represents any type of service that can be done to a car (like washing, oil change, engine repair).
Subclasses: ChangeOil, RepairEngine, Wash

This is exactly what LSP is about:

“You can substitute the base class (CarService) with any derived class (ChangeOil, RepairEngine, Wash) without breaking the program.”

Here you can find the file "LSP.cpp" where I will show the use of LSP with a simple example.
