#!/bin/bash

# Check if exactly one argument is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: ./run.sh <filename.py>"
    exit 1
fi

filename=$1

# Check if the file exists
if [ ! -f "$filename" ]; then
    echo "Error: File '$filename' not found!"
    exit 1
fi

# Execute the Python script
python3 "$filename"

