# Pattern Oriented Software Design
#### Fall, 2018
#### Prof Y C Cheng
#### Dept. of Computer Science and Information Engineering
#### Taipei Tech

### TA's webpage
You Don't now
## Synapsis

We will learn object-oriented design patterns by solving two problems in class:
- Review of C++/OOP - Problem 1
  - git/gitlab/jenkins
  - unit testing with googletest  
  - strong-styled pair programming/mob programming
  - STL, lambda
- Design patterns: an object-oriented file system API - Problem 2
  - Composite, Iterator, Visitor, Proxy, Builder, and Interpreter
  - GUI (with wxWidgets) MVC, Observer, Mediator, and Adapter

## Textbook:
Gamma, Erich, et al. Design patterns: elements of reusable object-oriented software. Pearson Education, 1994.

## Grading policy

- Homework 40%
- Online programming test x2, 20% each
- Final (written) 20%

## Alternative course 通訊軟體設計

 Spends more time on OOP basics in C++) to elect : 資工所(必修二選一)

## Problems:

### Problem 1: sorting shapes

A simple geometry application called _geo_ is needed to sort shapes such as triangles, circles, rectangles and others. As a command line application, _geo_ reads shapes from an input file, sorts the shapes by area or perimeter in increasing order or decreasing order, and write the result to an output file. For example,
```
geo input.txt output.txt area inc
```
sorts the shapes in file _input.txt_ in increasing order by area, and writes the result to the file _output.txt_. And
```
geo input.txt output.txt perimeter dec
```
sorts the shapes in file _input.txt_ in decreasing order by perimeter, and writes the result to the file _output.txt_.

### Problem 2: object-oriented file system API

The file system is used in many apps ranging from document editors (e.g., Atom), file/directory browser, file sync/storage applications (e.g., Dropbox), etc. In these applications, it is necessary to open/save document(s) from/to a selected location in the file system. Many operations on the file system are needed; for example, adding/deleting a file to/from a directory; moving selected files from one directory to another, searching files with a given name, compressing or encrypting a file or a directory, etc. Also, certain information about the files and directories are often needed, for example, the storage space used by a file or a directory, the organization of a directory, etc.

File systems differ in different operating systems. In this problem, we shall assume that Unix file system is used. To be sure, it is possible to provide all of the above operations by invoking system calls and functions that comes in C-binding on Unix systems. Unfortunately, the API bindings are usually terse and difficult to understand and are not suitable for use in the applications. Thus, the problem is to develop an object-oriented API in C++ that is easier to understand and work with. In particular, we want to organize the file system into a tree structure, and allow the client of the API to use nodes inside the tree uniformly. We also want it to be easy to add various operations to the file system.

## Week 1

- Simple tooling
  - Atom, g++, make, git
- Organizing project directory: We will work with projects with many files
  - From:
```
  hello.cpp a.out
```
  - To:
```
  src/hello.cpp      // folder for production code
  bin/hello          // folder for executables
  test/              // folder for test code
  obj/               // folder for object code
  makefile
  readme.md // project info
```
- makefile objectives:
  - maintaining project structure
  - enabling recompilation when dependent files changes
  - actions:
    - compile
    - link
    - cleanup
    - statistics
- jenkins/gitlab/googletest

## Tasks for problem 1
- Take care of command line parameters
- Select sorting algorithm
- Representation of Shapes
  - install gtest, run it
  - org project folder
  - make/makefile: target, .PHONY

__Check TA's webpage for first assignment!!__

You Don't now
