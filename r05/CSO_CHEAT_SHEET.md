# Tutorial 4
I, nyu-student-test, will read the document and make sure I understand the course logistics and GIT instructions. In the future, I'll try to fix these issues with the instructions specified below. If I have any further question I'll ask on Piazza.

I can access this document through the [link](https://github.com/nyu-cso18spring/cso18spring-recitation-nyu-student-test/blob/master/r05/CSO_CHEAT_SHEET.md)

## Logistics
1. For all future labs and recitations, the scores will be released through NYU Classes. CSO graders will post on Piazza when the scores are ready. 
   * If I have any question about the score, I must contact CSO graders before the deadline specified in the post.
2. The deadline is 11:59 PM on the due date for every lab and recitation. Any late submission will not be considered.
   * For example, if I, nyu-student-test, submit at 0:06 AM for recitation, I realized that submission will be ignored.
   * Some students submitted the code 10 minutes late and got 0 for their recitation exercises.
3. All the future recitation deadlines will be on Thursday nights instead of Wednesday (this recitation is due on Friday).
4. I must follow all the instructions CSO graders and instructors post on Piazza, especially the pinned posts.
   * For example, CSO graders have posted how to use grace days for labs. In the future, any submission with a incorrect format will be ignored. 
5. When doing labs, I have to always follow the instructions. I, nyu-student-test, won't change the output format. If I don't understand the output format, I'll ask on Piazza.
6. When doing labs, I should only modify the files which the instructions ask us to modify.
7. Plagiarism examples:
   * For game of life, I can look up how to read a file in C language on the Internet. But the logic of game of life must be entirely implemented by myself.

## GIT instructions
I can learn how to use GIT through [Git tutorial](https://try.github.io/levels/1/challenges/1) and [Learning Git branching](https://learngitbranching.js.org/).

To prevent the repositories from corruption, I'll type the command `sync` in the virtualbox every time I finish (even I just want to take a break) my work (recitation and/or labs).

### What I can not do?
1. I'll never use `git add -A` or `git add *` or `git add .`. Instead, I should always specify what files I want to commit, e.g., `git add e1.c e2.c e3.c`. Using `git add -a` will result in future git conflicts.
2. I'll never modify files through https://github.com. I'll use the website only to check my updates.

### Initialize recitation repository
1. `git clone https://github.com/nyu-cso18spring/cso18spring-recitation-nyu-student-test`
2. `cd cso18spring-recitation-nyu-student-test`
3. `git remote add upstream https://github.com/nyu-cso18spring/recitation`
4. `git pull upstream master`
5. `git remote -v`  

The output should be  

```
origin  https://github.com/nyu-cso18spring/cso18spring-recitation-nyu-student-test (fetch)
origin  https://github.com/nyu-cso18spring/cso18spring-recitation-nyu-student-test (push)
upstream        https://github.com/nyu-cso18spring/recitation (fetch)
upstream        https://github.com/nyu-cso18spring/recitation (push)
```

### Initialize labs repository
1. `git clone https://github.com/nyu-cso18spring/cso18spring-labs-nyu-student-test`
2. `cd cso18spring-labs-nyu-student-test`
3. `git remote add upstream https://github.com/nyu-cso18spring/cso18-labs`
4. `git pull upstream master`
5. `git remote -v`  

The output should be: 

```
origin  https://github.com/nyu-cso18spring/cso18spring-labs-nyu-student-test (fetch)
origin  https://github.com/nyu-cso18spring/cso18spring-labs-nyu-student-test (push)
upstream        https://github.com/nyu-cso18spring/cso18-labs (fetch)
upstream        https://github.com/nyu-cso18spring/cso18-labs (push)
```

### How to fix the recitation repository when it is corrupt?
When performing any GIT command and getting a message like the figure, ![](https://github.com/nyu-cso18/cso18-recitation/blob/staff/r04/corrupt.png) I'll do following instructions to fix the problem.

1. I'll first backup the folder with the command `mv cso18spring-recitation-nyu-student-test cso18spring-recitation-nyu-student-test-backup`. I have to first switch to the folder which contains cso18spring-recitation-nyu-student-test before doing the command.
2. After backuping the folder, I'll do **Initialization recitation repository**(follow all the instructions in that section) described above.
3. I'll copy the files I already modified in cso18spring-recitation-nyu-student-test-backup back to cso18spring-recitation-nyu-student-test. I can only copy modified C files (.c, .h) back to the newly initialized folder.

### How to fix the labs repository if it is corrupted?
When performing any GIT command and getting a message like the figure, ![](https://github.com/nyu-cso18/cso18-recitation/blob/staff/r04/corrupt.png) I'll do following instructions to fix the problem.

1. I'll first backup the folder with the command `mv cso18spring-labs-nyu-student-test cso18spring-labs-nyu-student-test-backup`. I have to first switch the folder which contains cso18spring-labs-nyu-student-test before doing the command.
2. After backuping the folder, I'll do **Initialization labs repository**(follow all the instructions in that section) described above.
3. Copy the files I already modified in cso18spring-labs-nyu-student-test-backup back to cso18spring-labs-nyu-student-test. I can only copy modified C files (.c, .h) back to the newly initialized folder.

### How to fix labs/recitation repository when there are conflicts?
When performing any GIT command and I get a message like the figure, ![](https://github.com/nyu-cso18/cso18-recitation/blob/staff/r04/conflict.png) I'll do following instructions to fix the problem.

1. I'll first type the command `git commit`. The command will show me conflicted files.
2. If I don't care about the correctness of those files, I'll type the command `git add CONFLICT_FILE_PATHS`. I'll replace CONFLICT\_FILE\_PATH with the relative paths to those conflicted files.
3. If I care about the correctness of those files, I'll edit those files. Remove unwanted lines, e.g. <<<<, >>>>, HEAD and any other conflicted lines. And I'll use the same command discussed in step 2 to add the conflicted files.
4. Then I have to do the command `git commit`. If the command shows that there are still some conflict. I'll repeat from step 2.
   * When doing `git commit` there may be a new window which pops out, showing me some comments. Simply typing `ctrl+x` can leave the window.
5. Finally, I have to do the command `git push origin master`.

### How to deal with the merge message.
When doing `git pull upstream master` for ether labs or recitation repository and I see a message like the figure, ![](https://github.com/nyu-cso18/cso18-recitation/blob/staff/r04/merge.png)   
I'll type `ctrl+x` (or, `:wq`  if this screen opens up in vim).
