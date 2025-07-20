
===========================================================
	D - Dependency Inversion Principle (DIP)
===========================================================

DIP have 2 ideas:
1) High-level modules should not depend on low-level modules.
	Both should depend on the abstraction.

2) Abstractions should not depend on details.
	Details should depend on abstractions.

======================
	Example
======================

Here are some simple real-world examples from “Car Service”

CarServiceManager does not depend on CarWashService or CarEngineService — it depends only on the ICarService abstraction.
Implementations (CarWashService, CarEngineService) — depend on the interface, not the other way around.

Here you can find the file "DIP.cpp" where I showed the use of DIP with a simple example.
