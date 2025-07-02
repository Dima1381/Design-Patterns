
===========================================================
	I - Interface Segregation Principle (ISP)
===========================================================

ISP says that we shouldn't create are too large Interface, instead just break up your interface into separate interfaces 
or just at least make them smaller. 
	
======================
	Example
======================

Here are some simple real-world examples from “Car Service”

You run a car service center that offers different kinds of services:
- Oil change
- Engine repair
- Car wash
Each service is usually done by a different specialist. A person who washes cars shouldn't be expected to repair engines or change oil.

Problem (ISP violation):
Now imagine that you create one common checklist that every technician must follow. It includes:
- Oil change step
- Engine repair stp
- Car wash step

Even if someone only washes cars, they still have to review and skip irrelevant steps (oil change, engine repair), or worse, be forced to do something they are not trained to do.
This is inefficient, confusing, and risky.
Therefore, it would be right to separate the interface for each service job.

Here you can find the file "ISP.cpp" where I will show the use of LSP with a simple example.
