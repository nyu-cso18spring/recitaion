Recitation 7
============

MMU(Memory Management Unit)
---------------------------
In this recitation, we are going to implement a MMU simulator to help us better understand virtual memory management. Please read **mmu\_lib.c** and **mmu.c**. Before diving into the code, read the comments in **mmu\_lib.c** first. After understanding the code, fix the FIXMEs in **mmu\_lib.c**. If your implementation is correct, executing "./mmu" won't cause any errors. After finishing the implementation, answer the questions inside questions.c. 

Make sure you understand the questions and implementation in this recitation, some of them may be related to the final exam. You can use **./mmu\_test** to test some different virtual addresses to help you understand more about virtual memory address translation.

Buffer Overflow
---------------
**buffer_overflow.c** gives you an example of buffer overflow. By carefully constructing the input, you can let the program jump to **HACK**. You are not required to modify **buffer_overflow.c**. We will go through how to hijack the flow control for this program. To do this by yourself, you need to first execute following commands:

1. Execute the command **sudo bash -c "echo 0 > /proc/sys/kernel/randomize_va_space"**.

What to submit and how to submit??
----------------------------------
Before submitting your solution, you can type **git diff** to see what you change. Be sure to change those lines or functions specified in above descriptions.  

This is a two part recitation. For the first week, due April 5th at 11:59pm, please only answer question 5 in **questions.c** then commit and push. 
**git commit -m "First part of r07" questions.c**  
**git push**

For the second week of this recitation, due on April 12th at 11:59pm, you need to submit all two modified files. Please make sure all questions in the questions file are answered at this point.
**git add mmu\_lib.c questions.c**   
**git commit -m "r07"**  
**git push**
