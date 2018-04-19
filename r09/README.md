Recitation 9
============
Prerequisite
------------
1. Save all your jobs (recitation and labs) in the virtual box.
2. Do **sudo shutdown -h now**.
3. After the Linux in virtual box is shutdown. Change the setting of the virtual box.
    1. Machine -> Settings -> System -> Processor
    2. Change the number of Processor to 4.

Multi-thread programming
--------------------------
Please read this [simplified pthread tutorial](https://vcansimplify.wordpress.com/2013/03/08/pthread-tutorial-simplified/) to get the basic knowledge of pthread. For further information, please read [pthread tutorial](http://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html)

You have two jobs. First, answer questions in e1.c. Second, fix the two FIXMEs parts in e2.c. You need to know to use pthread in order to finish the second part.

What to submit and how to submit??
----------------------------------
Before submitting your solution, you can type **git diff** to see what you change. Be sure to change those lines or functions specified in above descriptions.  
You need to submit all two modified files.  
**git add e1.c e2.c**   
**git commit -m "r09"**  
**git push**
