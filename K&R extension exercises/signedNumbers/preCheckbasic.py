def check_indentation_and_brackets(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    mixed_indentation = False
    spaces_indent = None
    tab_indent = None
    issues = []

    for i, line in enumerate(lines):
        stripped_line = line.lstrip()
        
        # Check for consistent indentation
        if line.startswith("    "):  # Line starts with 4 spaces
            if tab_indent is None and spaces_indent is None:
                spaces_indent = True
            elif tab_indent:
                mixed_indentation = True
                issues.append((i + 1, '4 spaces'))
        elif line.startswith("\t"):  # Line starts with a TAB
            if tab_indent is None and spaces_indent is None:
                tab_indent = True
            elif spaces_indent:
                mixed_indentation = True
                issues.append((i + 1, 'TAB'))

        # Check for bracket spacing
        if stripped_line.startswith("}"):
            expected_indent = line.find("}") + 1
            if expected_indent % 4 != 0:  # Check if it's a multiple of 4 spaces
                issues.append((i + 1, 'Incorrect bracket spacing'))

    if mixed_indentation:
        print("Mixed indentation detected:")
        for line_num, indent_type in issues:
            print(f"Line {line_num}: Expected consistent indenting, found {indent_type} instead.")

    if issues:
        print("Bracket spacing issues detected:")
        for line_num, _ in issues:
            if 'Incorrect bracket spacing' in _:
                print(f"Line {line_num}: Incorrect spacing before closing bracket")

    if not mixed_indentation and not any('Incorrect bracket spacing' in _ for _ in issues):
        print("Indentation and bracket spacing are consistent.")

# Example usage:
file_path = 'Q4_sum_formatted.c'  # Replace with your C file path
check_indentation_and_brackets(file_path)
