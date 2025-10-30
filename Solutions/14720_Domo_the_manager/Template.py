def merge_col(current_csv, extracted_col):
    #TODO: Merge the combined columns to our original csv string
   
def combine_col(csv, indices, col_name):
    #TODO: Combine the extracted columns with the modified header
   
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
#
num_col = int(csv_lines[0])                     #first line number of col
indices = csv_lines[1:num_col+1]                #indices
col_name = csv_lines[num_col+1: 2*num_col+1]    #new colname
 
# Remaining lines = CSV data
csv_str = "\n".join(csv_lines[2*num_col+1:])
new_csv = csv_str
for i in range(num_col):
   #TODO: use the functions to create our new csv string

print(new_csv)

'''
print(num_col)
print(indices)
print(col_name)
print(csv_str)
'''