num = list(map(int, input().strip()))

output = 0
i = 0
while i < len(num):
    output += num[i] 
    i += 2

print(output)