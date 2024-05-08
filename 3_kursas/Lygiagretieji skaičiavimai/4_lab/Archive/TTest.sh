#!/bin/bash

# Compile Java file
javac TTest.java

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # Run the compiled Java program
    java TTest
else
    echo "Compilation failed"
fi