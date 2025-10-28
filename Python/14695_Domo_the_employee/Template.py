def extract_columns(csv: str, indices: str):
    #TODO:  

# Read the CSV input until EOF
csv_lines = []
while True:
    try:
        line = input()
        if line.strip() == "":
            continue
        csv_lines.append(line)
    except EOFError:
        break

# First line = indices
ind_line = csv_lines[0]
ind = list(map(int, ind_line.split()))

# Remaining lines = CSV data
csv_str = "\n".join(csv_lines[1:])

# Process
print(extract_columns(csv_str, ind_line))