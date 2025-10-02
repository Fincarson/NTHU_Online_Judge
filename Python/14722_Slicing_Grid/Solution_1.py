def solve(n, d, grid):
    ans = ""
    diagonal_grid = [[] for _ in range(2 * n - 1)]
    for i in range (n):
        for j in range (n):
            diagonal_grid[i+j].append(grid[i][j])
    
    for i in range (2 * n - 1):
        if(d == 1):
            ans += "".join(diagonal_grid[i][::-1])
            d = 0
        else:
            ans += "".join(diagonal_grid[i][0:])
            d = 1
    return ans

_n, _d = map(int, input().split())

_grid = []
for _ in range(_n):
    _row = []
    for num in input().split():
        _row.append(num) # Remove int()
    _grid.append(_row)

print(solve(_n, _d, _grid))