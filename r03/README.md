Tutorial 3
==========

Array and pointer are hard topics in C language. Especially when you use both of them in the program. This tutorial give you more exercises about pointer and array.

Exercise 1
----
**e1.c** shows different ways to access an array. Do you understand all of them? Why do these syntax work? Replace all three **0**s in line 11 - 14 with some other numbers so that the **printf** will print out 1.

Exercise 2
----
You should already know that a pointer is a variable which contains the address in memory of another variable. You may also know that not only data(variables) but also programs are are stored in memory. If so, can a pointer point to a function? The answer is yes. Please check compile **e2.c** and execute it. You will get 0 as the output. Carefully read **e2.c** and replace all four **0**s in line 30 - 33 with some other numbers so that the **printf** will print out 1.

Readings:
* [Function Pointers](https://en.wikipedia.org/wiki/Function_pointer)

Exercise 3
----
First compile **e3.c** and execute it to see what happen. Do you know the reason why **e3** crashes? Please fix the bug so that the **printf** will print out 5 (please don't modify the **printf**, that will make this exercise meaningless...).  

Readings:
* [Segmentation Fault](https://en.wikipedia.org/wiki/Segmentation_fault)

Exercise 4
-----
Write the function printb() that takes a pointer to a 4 byte value and prints its binary representation (preceded by `0b`). The skeleton code is in **e4.c**.  

Question: Can you not print out any of the leading zeros? (Don't worry, you will get the full score even if you print out the leading zeros.)


## What to submit and how to submit??
Before submitting your solution, you can type **git diff** to see what you change. Be sure to change those lines or functions specified in above descriptions.  
You need to submit all four modified files.  
**git add e1.c e2.c e3.c e4.c**  
**git commit -m "r03"**
**git push**
