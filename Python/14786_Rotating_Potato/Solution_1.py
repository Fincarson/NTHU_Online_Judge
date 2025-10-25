# 90 Degrees
def ninety():
    output = [[] for _ in range(m)]
    for _ in range(n):
        row_input = input().split()
        for i in range(m): output[i].append(row_input[i])
    
    for out in output:
        out.reverse()
        print(" ".join(out))


# 180 Degrees
def one_eighty():
    output = [[] for _ in range(n)]
    for i in range(n):
        row_input = input().split()
        row_input.reverse()
        output[-1-i] = row_input
    
    for out in output: print(" ".join(out))


# 270 Degrees
def two_seventy():
    output = [[] for _ in range(m)]
    for _ in range(n):
        row_input = input().split()
        for i in range(m): output[i].append(row_input[i])
    
    output.reverse()
    for out in output: print(" ".join(out))


# 0/360 Degrees
def zero():
    output = []
    for _ in range(n): output.append(list(input().split()))
    for out in output: print(" ".join(out))


n, m , k = map(int, input().split())
k %= 4

if k == 0: zero()
if k == 1: ninety()
if k == 2: one_eighty()
if k == 3: two_seventy()