# tclshlite

## What is this ?
This is a minimal implementation of TCL Language commands ( Most of it.. )using STL. Intention is not to really build a full fledge TCL Interpreter ( That would be unwise! ) but, to mainly focus on algorithms ( Recursive, Backtracking and so on.. ) that enables some of the basic features of tcl. And evetually learn in this process!.

### How to build ?
Need C++ compiler, that's all!.
```sh
git clone https://github.com/mistryalok/tclshlite.git
cd tclshlite
make
```

### How to launch ?
```sh
./tclshlite
########################################
# Welcome to tclshlite..               #
#                                                                               #
# Author: Alok Mistry                   #
# Type ./tclshlite -help for more info.#
########################################
%
```

### How to execute ?
```sh
% set a 4
% set b 5
% puts $a
4
% puts $b
5
% exit
```

### Executing from a file 
```sh
% source example.tcl
% exit
```

### Sourcing proc
```sh
% %proc abcd {a b c d} {
%puts $a
%puts $b
%puts $c
%puts $d
%}
%abcd 22 33 44 55
22
33
44
55
exit
```

## Features Supported 
1. puts & set
2. proc execution

## Limitations
Limitations on top of current supported features.
1. No error checking on user inputs
2. proc sourcing from script file is not supported