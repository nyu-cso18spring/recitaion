Tutorial 4
==========
This recitation mimics the format of our labs. You will add your own main function for debugging purposes (see strlen.c and dlist.c), but must remove it before submitting to github.com. Otherwise, you'll get 0 credit for this recitation. The second goal of this recitation is to let you review pointer and pointer to pointer. This is the last recitation to practice basic features of C language (unless you want more).

For each exercise, before compiling with **make** you should add you own test cases to the main function and test with your own test cases. Then use **make all** to generate executables that use our test cases and run them to be sure your implementation is correct.

Exercise 1
----
Unlike many other languages, there is no length field for a string. C language uses a special character, '\0', to denote the end of a string. Users can then use strlen() defined in string.h to get the length. In this exercise, you are asked to implement strlen() (you cannot call the built-in strlen()). Complete **cso\_strlen()** in strlen.c. Remember to do error handling. Use the Makefile ("**make all**") to generate **run\_strlen**. Run run\_strlen to see if your implementation is correct.

Exercise 2
----
In lab1, you have implemented a basic link list. Link list is useful when you want to create a new node in front of a list (prepend). But you sometimes need both prepend and append functionalities. Doing append with a link list is slow (why?). In this exercise, you are asked to implement the **append** and **prepend** functions for a double link list. I have provided the skeleton code (dlist.c and dlist.h) for the corner cases. Read it and think about how to implement both functions(they are symmetric). Remove (or delete) is slightly difficult and we are not going to implement it in this recitation. But you are encouraged to implement it and to reinforce your understanding of pointer. Use the Makefile("**make all**") to generate **run\_dlist**. Run run\_dlist to see if your implementation is correct.

## What to submit and how to submit??
Before submitting your solution, you can type **git diff** to see what you change. Be sure to change those lines or functions specified in above descriptions.  
You need to submit all two modified files.  
**git add strlen.c dlist.c**   
**git commit -m "r04"**  
**git push**
