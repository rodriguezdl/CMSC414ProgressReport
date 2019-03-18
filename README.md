# CMSC414ProgressReport
This is a simple demonstration of using `LD_PRELOAD` to hijack an arbitrary API.

## File overview
 * `cat.c` is a simple file that emulates the functionality of `cat`, being able to print the contents of files that are provided. Run `./cat fileToPrint.type` to print the file contents of `fileToPrint.type`.
 * `hijack.c` compiles into a shared library that intercepts the API interface of `<stdio.h>`, specifically the `fread` and `ftell` functions the `cat.c` uses. It replaces the legitimate functionality with returning hard-coded lorem ipsum sample text.
 * `run.sh` is a bash script that sets the `LD_PRELOAD` environment variable to `hijack.so` before running the command line arguments as a command, unsetting `LD_PRELOAD` upon command completion.
 * `sample.txt` is a sample text file that you can use to cat.

## Prerequisites
A system with gcc and clang installed.

## Build
Run `make`.

## Verification
Run `./cat sample.txt`. Observe that "`This is the real sample text.`" will be printed.
Run `./run.sh ./cat sample.txt`. Observe that the real output text is no longer being printed. Instead, lorem ipsum text is printed.
