#!/run/current-system/sw/bin/bash


# Check if the user provided a filename as an argument
if [ $# -eq 0 ]; then
    echo "Usage: $0 filename.cpp"
    exit 1
fi

# Get the filename from the command-line argument
filename="$1"

# Check if the file exists
if [ ! -f "$filename" ]; then
    echo "File $filename not found."
    exit 1
fi

# Extract the file name without the extension
basename=$(basename -- "$filename")
extension="${basename##*.}"
filename="${basename%.*}"

# Compile the C++ file
echo "Compiling $filename.cpp..."
g++ -std=c++23 -o "$filename" "$filename.cpp"

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

# Execute the compiled file
echo "Executing $filename..."
./"$filename"

# Clean up the compiled executable
rm "$filename"

echo "Script execution complete."

