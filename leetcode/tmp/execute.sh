#!/run/current-system/sw/bin/bash



# Check if the user provided filenames as arguments
if [ "$#" -eq 0 ]; then
    echo "Usage: $0 file1.cpp [file2.cpp ...]"
    exit 1
fi

# Compile each provided C++ file
outputname="output"
for filename in "$@"; do
    # Check if the file exists
    if [ ! -f "$filename" ]; then
        echo "File $filename not found."
        continue  # Move to the next file
    fi

    # Extract the file name without the extension
    basename=$(basename -- "$filename")
    extension="${basename##*.}"
    filename_without_extension="${basename%.*}"
done
    echo "Compiling $basefile..."
    g++ -std=c++23 -o "$outputname" "$@"

    # Check if compilation was successful
    if [ $? -ne 0 ]; then
        echo "Compilation of $outputname failed."
    else
        # Execute the compiled file
        echo "Executing $outputname..."
        ./"$outputname"

        # Clean up the compiled executable
        rm "$outputname"
    fi

echo "Script execution complete."

