# Computer Systems Organization : Tutorial 1

- [Basic UNIX](#basic-unix-usage)
- [Program development](#program-development)
   * [Editor](#editor)
   * [Compile](#compile)
   * [Debug](#debug)
   * [Tmux](#tmux)
   * [Version control](#version-control)
   * [What to submit for today's recitation](#what-to-submit-for-todays-recitation)

# Basic UNIX usage

Most of you are used to interacting with computers and smartphones by GUI and
the touch interface.  As a developer / programmer / advanced user, you
can do your job more efficiently by mastering the commandline interface.  In
UNIX, most of the interesting things you want to do can be accomplished by skillfully combining
various commands.  

Your lab virtual machine is a Linux box.  Your MacOS laptop is based on BSD
UNIX.  Most UNIX commands you learn apply to both, but there are
variations.

Please read this [ guide on using UNIX commands ](https://github.com/jlevy/the-art-of-command-line).
Below is a short list of the most basic commands you will typically use on a day to day basis:

* `man`
* **`ls`**
* **`cd`** `pwd`
* `mkdir`
* `cp` **`mv`** `rm`
* **`echo`** `cat`
* **`wc`**
* **`|`** `>` `<`
* **`grep`**
* `tail` `head` `awk`
* **`find`**
* `ctrl-c` `ctrl-z` `fg` `bg`
* **`tar`**
* `curl` **`wget`**
* `apt-get install` (This is a Linux-distribution specific command, and hence not available on Mac or other non-Ubuntu based distributions; for Mac, a similar package manager called Brew exists)
* `apt-cache search` (same as above)

Despite attending this recitation, many times you will have questions about "how do I do this?"
"is there a command for doing X?".  The answer to all of these questions can usually
be discovered by Googling.  Click on those Stackoverflow links.  It has many helpful answers.

**Please always Google your question first before asking any program environment (Linux, VIM/Emacs and Git) questions on Piazza. Most of the time, what you need are some specific commands and/or options.**

---
### Exercise 1 (Nothing to submit for this exercise).

* Using the command line only, download and extract the source code of Nginx, a web server. The code's URL is at here: http://nginx.org/download/nginx-1.9.2.tar.gz

* Using the command line only, figure out how many C source files there are in Nginx's code base. C source files have filenames that end of `.c` suffix.

* Using the command line only, find out which C source file contains the `main` function for Nginx.

* Using the command line only, find out how many lines are inside the nginx.c file (hint: one solution requires you to run multiple commands separately).
   * An un-related but interesting tool is cloc which can show you the summary of the code base.

* How would you rename a file? Create a file and rename it.

---

# Program development

You've probably all learned programming using IDE, which packages up the whole
development process, i.e. writing the code, turning it into something runnable, and
actually running and debugging into one graphically appealing bundle. The UNIX
people do things differently.  We tend not to use IDE, but rather, we use
separate tools for each of these development steps.

## Editor
You *have to* learn to use one editor, either `vim` or `emacs`.  We introduce `vim` here because
that's the editor we use.  `vim` is a text-editor; all the stuff you want to do
can be typically accomplished without using the mouse (that is much faster than
having to click around).

Here is a tutorial on vim https://wiki.gentoo.org/wiki/Vim/Guide. (If you prefer learning
emacs, here's a tutorial on emacs http://www.gnu.org/software/emacs/tour/)
You can also search online for other tutorials.

`vim` has several modes, three of them you will regularly use:
* insert mode (whatever you type end up in the file buffer you are editing)
  - to enter insert mode, hit `i` (insert at), `a`(insert after) or `o`(insert next line)
* normal mode (whatever you type are interpreted as vim commands)
  - to enter normal mode, hit `<ESC>`
* command line mode (for entering editor commands)
  - to enter command line mode, hit `:` when being in the normal mode.

Readings:
* [Learning the vi Editor/Vim/Modes](http://vim.rtorr.com/)

Key commands:
* `h` `j` `k` `l` for left, down, up, right. Once you mastered using these keys, it becomes as natural as riding a bicycle.
* `w` to move forward one word at a time, `b` to move backward one word at a time.
* `x` to delete the character under the cursor. `dw` to delete the current word. `u` to undo.
* `:set number` to show line numbers. `:set nonumber` to turn it off.
* `:w` to save the buffer into the file.
* `:q` to quit vim. `:wq` to write and quit.

Useful settings to put in `$USER/.vimrc`:
* `filetype on`           " Enable filetype detection
* `filetype indent on`    " Enable filetype-specific indenting
* `filetype plugin on`    " Enable filetype-specific plugins
* `syntax on`             " syntax highlight
* `set autoindent`        " auto indentation
* `set smarttab`          " insert tabs on the start of a line according to context
* `set relativenumber`    " Turn on relative and absolute number at the same time.
* `set number`            " 
* `set expandtab`         " replace <TAB> with spaces
* `autocmd FileType Makefile set noexpandtab` " You MUST set this if you set expandtab
* `set softtabstop=4` 
* `set shiftwidth=4` 

Other readings:
* [Vim keyboard image](http://www.viemu.com/vi-vim-cheat-sheet.gif)
* [vim adventures](https://vim-adventures.com/)
* [Vim keyboard cheatsheet](http://vim.rtorr.com/)
* [Getting started with vim](http://www.sitepoint.com/getting-started-vim/)
* [Your problem with vim is that you don't grok vi](http://stackoverflow.com/questions/1218390/what-is-your-most-productive-shortcut-with-vim/1220118#1220118)

There many useful plug-ins that one can install on top of the basic vim. If you want to be fancy and more productive, try these out:
* [NERDtree] (https://github.com/scrooloose/nerdtree)

## Compile

You use the C compiler, command `gcc`, to compile your C programs.  The C compiler `gcc`, as well as many key pieces of development software (e.g. the C library, make), have been developed by [GNU](http://www.gnu.org/). That's why you hear people sometimes refer to GNU/Linux since strictly speaking, Linux is just the kernel of the OS and not the complete system.

* To compile a simple `hello.c` C file, type `gcc hello.c`. This generates an executable `a.out`. Execute it by typing `./a.out`
* If you want to compile the program to a different name, `gcc -o hello hello.c`

Typically, we do not directly type `gcc` to compile programs. There are several reasons for why not:
- The gcc command for large software is very long
- We need to compile many source files individually and combine them into a single executable later.
- We need to obey dependencies during compilation. e.g. First compile x, then compile Y (if Y uses X).
- We only want to compile those source files that have changed.  

To address all above problems, we use a classic tool called `make`, developed by GNU. To use `make`, you write
a Makefile.  The meat of a Makefile consists of a bunch of rules.  Here's what a rule looks like
```
target: dependency1 dependency2
         commands
```

In this repo, I have a Makefile that compiles foo.c into foo:
```
foo: foo.o main.o
	gcc -o foo foo.o main.o
main.o: main.c
	gcc -c main.c
foo.o: foo.c
	gcc -c foo.c
clean:
	rm -f foo.o foo
```
**Question:**  type `make`, what is the order of the commands being run? why?

To make writing such rules more succinct, you use variables and do [pattern matching]([https://www.gnu.org/software/make/manual/html_node/Pattern-Match.html)in Makefile.
- Define variables as `FILES:=file1 file2`, use it later as `$FILES`

There are several important [automatic variables](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html).
- `$@` (target name)
- `$^` (name of all pre-requisites, i.e. dependencies)
- Pattern-matching using `%` and `*`. As an example:
```
  %.b: %.a
       cp  $*.a $*.b
```
  Above rule copies any file with suffix `.a` into another file with the same name except having suffix `.b`

### Exercise 2 (Please submit the Makefile and hello.c. The Makefile should also contain the debug flag discussed in exercise 3)

* Rewrite the given Makefile using pattern matching and variables. Make it as clean and re-usable as possible.

* Write the classic "Hello world!" program in C. The file name should be hello.c.

## Tmux

It's tedious to switch between vim and command line. Unfortunately, you need to do so all the time to compile, run and debug the programs. It is possible to do all these in the editor. But it usually requires you to install extra plugins. I personally recommend using tmux or screen which can split the terminal into several tabs/windows/panes and provide hot-key to switch among different area quickly.

Key commands of tmux:
* `tmux` to launch tmux environment.
* `ctrl+b c` to create a new window.
* `ctrl+b 0/1/2/3/4/5/6/7/8/9` to jump 0th-9th window.
* `ctrl+b n` to jump to next window.
* `ctrl+b p` to jump to previous window.
* `ctrl+b %` to split current window into two vertical panes.
* `ctrl+b "` to split current window into two horizontal panes.
* `ctrl+b o` to swap panes.

Other readings:
* [tmux tutorial](http://www.hamvocke.com/blog/a-quick-and-easy-guide-to-tmux/)
* [tmux shortcuts & cheatsheet](https://gist.github.com/MohamedAlaa/2961058)

## Debug

The debugger for C/C++ is `gdb`, developed by GNU, again.  In order to use gdb, we need to compile the
source code using the `-g` flag to include appropriate debug information in the generated binary files.
An example, `gcc -c -g foo.c`.

My foo program is buggy, and does not even terminate!
To debug, type `gdb foo`.  The most basic gdb commands are: (I give their shortcut form)
- `r` (run the program)
- `<ctrl-c>` to stop the program inside gdb
- `bt` (print out the stack, i.e. where in the program's execution it is being stopped at)
- `l` (print lines from the relevant source file)
- `p <variable name>` (print out the content of the variable)
- `b` (set breakpoints, e.g. `b foo.c:7` stops the program when it is about to execute line 7 at foo.c
- `n` (continue execution to the next source line) `s` (continue until control reaches a different source file)
- `c` (continue execution)

### Exercise 3 (Submit the fixed foo.c and Makefile. Makefile should contain the debug flag and the pattern match rules discussed in exercise 2)

* Modify your Makefile to include the `-g` flag

* Use gdb to debug foo (it is supposed to calculate and print the sum from 1 to 10) (how can you interrupt foo while it is running?).

* Compile above "Hello world!" program with debugging enabled.

## Version control

We recommend using `git`, developed by Linus Torvalds. You can read this [git tutorial](https://www.atlassian.com/git/tutorials).

After making the modifications, you can check in the changes in your (local) git repo, by typing
`git add Makefile foo.c hello.c` then `git commit -m "recitation 01"`.

**Please do not put any code in this class on a Github public repo (or other public repositories)**

### Exercise 4 (Here is where you submit all your files)

* Commit your "Hello world!" program's source code to your Github repository.
* Commit the modified Makefile to your Github repository.
* Commit the fixed foo.c to your Github repository.
* Remember to PUSH your commits to the remote repository (**git push**).
(Github's [student developer pack](https://education.github.com) gives you free private repo(s))

## What to submit for today's recitation
1. Makefile (with -g and pattern match rules)
2. foo.c (with the bug fixed)
3. hello.c (which prints "Hello World")
