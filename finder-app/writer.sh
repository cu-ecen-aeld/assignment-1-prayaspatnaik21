#!/bin/bash

# Check if both arguments are provided
if [ $# -ne 2 ]; then
    echo "Error: Two arguments required. First: path to file, Second: text string to write."
    exit 1
fi

writefile=$1
writestr=$2

# Create the directory path if it doesn't exist
mkdir -p "$(dirname "$writefile")"

# Write the string to the file, overwriting if it exists
echo "$writestr" > "$writefile"

# Check if the write operation was successful
if [ $? -ne 0 ]; then
    echo "Error: Could not create or write to $writefile."
    exit 1
fi

echo "Successfully wrote to $writefile."
