Recitation 10
=============

Multi-thread programming
--------------------------
In this recitation, we are going to solve a race condition problem. e1.c and e2.c are the same programs but the implementation is incorrect. When executing them, you'll get a segmentation fault due to a race condition issue. Your first job is to locate where is the race condition. Next, for e1.c, use pthread\_mutex\_t to solve the issue (we already define a global mutex variable, use it). For e1.c, you can only insert pthread\_lock() and pthread\_unlock(). All other modifications are forbidden. For e2.c, instead of using pthread\_mutex\_t, try to modify producer() to solve the race condition. You need to keep the logic of producer. Note that, the solution for e2.c may only work on Intel CPU because some CPUs(ARM, MIPS) may buffer and reorder memory write.

After finishing your implementation, try **time ./e1** and **time ./e2**. Can you explain why one of them is so slow?

What to submit and how to submit??
----------------------------------
Before submitting your solution, you can type **git diff** to see what you change. Be sure to change those lines or functions specified in above descriptions.  
You need to submit all two modified files.  
**git add e1.c e2.c**   
**git commit -m "r010"**  
**git push**
