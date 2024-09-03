import subprocess
import shutil
import re
import os

def check_style_with_astyle(file_path):
    # Create a copy of the original file
    base, ext = os.path.splitext(file_path)
    output_path = f"{base}_formatted{ext}"
    shutil.copy(file_path, output_path)

    # Path to the astyle executable
    astyle_path = r"C:\Users\OKH20\OneDrive\Desktop\astyle-3.6-x64\astyle.exe"

    # Run astyle on the copied file
    result = subprocess.run([astyle_path, 
                             "--style=kr",  # Use K&R style for braces
                             "--indent=spaces=4",  # Indent with 4 spaces
                             "--convert-tabs",  # Convert TABs to spaces
                             "--suffix=none",  # Do not create a backup file
                             output_path],
                            capture_output=True, text=True)
    
    if result.returncode != 0:
        print("astyle encountered an issue:")
        print(result.stderr)
        return
    
    print(f"Code formatted successfully with astyle. Output saved to {output_path}")

    # Perform additional checks for golden rule and custom bracket style
    check_custom_style(output_path)

def check_custom_style(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    issues = []

    # Check each line for specific style issues
    for i, line in enumerate(lines):
        # Check for 4-space indentation or TAB consistency
        if line.startswith(' ') and (len(line) - len(line.lstrip(' '))) % 4 != 0:
            issues.append((i + 1, "Indentation should be a multiple of 4 spaces"))
        if '\t' in line:
            issues.append((i + 1, "Mixed TAB and space indentations"))

        # Check for correct placement of else brackets
        if re.match(r'^\s*else\s*\{', line):
            issues.append((i + 1, "The opening brace '{' should be on the same line as 'else'"))

    if issues:
        print("Custom style issues found:")
        for line_num, issue in issues:
            print(f"Line {line_num}: {issue}")
    else:
        print("No custom style issues detected.")

# Example usage:
file_path = r'C:\Users\OKH20\OneDrive - University of Canterbury\University\UC2024\Semester 2\ENCE260\Learning modules\Assignment 1\Q9\signMag.h'
check_style_with_astyle(file_path)

