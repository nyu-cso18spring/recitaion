Tutorial 6
==========
In this tutorial, you are going to learn how to use **objdump** and **gdb** to do reverse engineering. The exercises here is the simplified version of lab3. You must understand how to solve the exercises by yourself so that you can do lab3. 


Steps
-----
1. Type **make**.
2. Type **./e1\_sol**, **./e2\_sol**, **./e3\_sol** and **./e4\_sol**. You should see **Correct answer** for all the commands.
  *  **eN\_sol** are made by **eN\_sol.o** and **eN\_tester.o** (in objs).
3. Type **./e1\_tester**, **./e2\_tester**, **./e3\_tester** and **./e4\_tester**. You should see **Wrong answer** for all the commands.
  *  **eN\_tester** are made by **eN\.o** and **eN\_tester.o**.
4. Your job is to use **objdump** and **gdb** to decipher what **eN\_sol.o** (in objs) do and write the corresponding C functions in **eN.c**. In other words, your implementation will let you get **Correct answer** when executing **./eN\_tester**.

Advice
-------
You will find [Intel instruction set manual](https://www.intel.com/content/dam/www/public/us/en/documents/manuals/64-ia-32-architectures-software-developer-instruction-set-reference-manual-325383.pdf) and [Google](https://google.com) useful. Google the meaning of the instruction when you really hate to look it up from the manual. When reading **Makefile** you will see that we pass **-Og** to gcc so that it uses [System V AMD64 ABI](https://en.wikipedia.org/wiki/X86_calling_conventions#System_V_AMD64_ABI) as the calling convention. You have to understand System V AMD64 ABI calling convention before digging into the assembly code. [Register table](https://www.tortall.net/projects/yasm/manual/html/arch-x86-registers.html) is also very useful.

Tips
----
If you see **shr 0x2 %eax**, it means right shift 2 bits of eax. But if you see **shr %eax**, it means right shift **1** bit of eax.

objdump
-------
Using objdump is easy. Just type **objdump -d TARGET.o**. For example, to decipher **e1\_sol.o**, simply type **objdump -d e1\_sol.o**. What you will see is purely assembly code. To know what does the function perform, you may have to write down the meaning of each instruction and the value of each register after each instruction.

gdb
---
Using gdb is less straightforward than objdump but can give you more information. First type **gdb TARGET**. For example, to use gdb to decipher **e1\_sol.o**, type **gdb ./e1\_sol** (question: why e1\_sol instead of e1\_sol.o?). Now you need to set a break point to the function in **./e1\_sol** so that you can debug instruction by instruction. What is the function name you need to set in gdb for **e1\_sol**? You can figure that out by using objdump (or just read e1.c :)). Below lists the GDB commands you will use in order to do this tutorial (and lab3).

1. Set a break point: **b FUNCTION\_NAME**, e.g. **b e1**.
2. Show the assembly: **layout asm**.
3. Run the program: **run**.
4. Run instruction by instruction: **si**.
  *  Usually we use **s** because we want to run line by line (one line in the C program) but we don't have the C source code. So we can only use **si**.
5. Show registers information: **i r REGISTER**, e.g. **i r eax**.

Resource
--------
1. [X86 Assembly/GAS Syntax](https://en.wikibooks.org/wiki/X86_Assembly/GAS_Syntax)
2. [System V AMD64 ABI](https://en.wikipedia.org/wiki/X86_calling_conventions#System_V_AMD64_ABI) 
3. [Register table](https://www.tortall.net/projects/yasm/manual/html/arch-x86-registers.html)

## What to submit and how to submit??
Before submitting your solution, you can type **git diff** to see what you change. Be sure to change those lines or functions specified in above descriptions.  
You need to submit all two modified files.  
**git add e1.c e2.c e3.c e4.c**   
**git commit -m "r05"**  
**git push**

**Due: Mar 20, 2018**
