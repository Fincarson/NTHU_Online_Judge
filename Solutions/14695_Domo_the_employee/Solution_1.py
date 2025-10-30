def extract_columns(csv: list, indices: list): # Change parameter str->list
    #TODO: 
    num_pop = 2 if '2' not in indices else 1 if '1' not in indices else 0
    for index in range(len(csv)):
        old = csv[index].split(',')
        new = []
        for i in indices: new += [old[i]] 
        csv[index] = ','.join(new)
    return '\n'.join(csv)

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
print(extract_columns(csv_lines[1:], ind)) # Change csv_str -> csv_lines and ind_line to ind