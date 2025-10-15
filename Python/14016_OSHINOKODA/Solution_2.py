T = int(input())
N = int(input())

array = [[0] * N for _ in range(N)]
sum_row = [0] * N
sum_col = [0] * N
sum_diag_a = [0] * (2 * N - 1)
sum_diag_b = [0] * (2 * N - 1)  

for i in range(N):
    array[i] = list(map(int, input().split()))
    row = array[i]
    for j in range(N):
        value = row[j]
        sum_row[i] += value
        sum_col[j] += value
        sum_diag_a[i + j] += value
        sum_diag_b[i - j + N - 1] += value

output = [[0] * N for _ in range(N)]
for i in range(N):
    for j in range(N):
        output[i][j] = sum_row[i] + sum_col[j] + sum_diag_a[i+j] + sum_diag_b[i-j+N-1] - 3*array[i][j]

for t in range(T):
    x, y = map(int, input().split())
    print(output[x][y])