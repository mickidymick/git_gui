#!/bin/bash
gcc -o git_gui.so git_gui.c $(yed --print-cflags) $(yed --print-ldflags)
