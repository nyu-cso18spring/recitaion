Tutorial 2
==========

## Exercise 1 
Compile **e1.c** and execute it. You should see the output is 1198. Carefully read e1.c and decide what is the correct number of **answer** on line 56 in order to print **3360153** instead of 1198. Note that you can only modify line 56.

Hint: To compile, type **gcc e1.c**.  
Hint: Some function calls can be ignore. After finding out the meanful function calls, this question becomes a simple algebra question.
Question: From the mathmetical view, there is only one solution. However, there are multiple solutions for e1.c. Why?

## Exercise 2
Compile **e2.c** and execute it. You should see the output is 0. For this exercise, you need to modify the values of **i** and **j** on line 6 and line 7 respectively so that the output is **-28**. It's easy to get the answer by trial and error but you should understand the meaning of the answer. Note that there are multiple answers. You can pick any one of them.

## Exercise 3
Compile **e3.c** and execute it. You should see the output is 0. Modify the value of **answer** so that the output is **1069547520**.

Hint: First convert the desired output to a 32-bit binary.  
Hint: Think about the meaning of a pointer.  
Hint: You may find the float point format useful.

## Exercise 4
Compile **e4.c** and execute it. You should see the output is 131072. Modify the value of **answer** so that the output is **39661568**. Note that there are multiple answers. You can pick any one of them.

Hint: First convert the desired output to a 32-bit binary.  
Hint: What are bitwise shift operators for?

## What to submit and how to submit??
Before submitting your solution, you can type **git diff** to see what you change. Be sure to change those lines specified in above descriptions.  
You need to submit all four modified files.  
**git add e1.c e2.c e3.c e4.c**  
**git commit -m "r02"**
**git push**
