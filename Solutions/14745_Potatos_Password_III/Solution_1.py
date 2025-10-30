def solve(n, d, t, grid):
    ans = ""
    center = n // 2
    rhombus_lines = [[] for _ in range(n)]

    # OUTSIDE RHOMBUS
    for index in range(center):
        i = 0; j = 0 + index
        while((i >= 0 and i < n) and (j >= 0 and j < n)):
            rhombus_lines[index].append(grid[i][j])
            i += 1; j -= 1
        
        i = (n-1)-index; j = 0
        while((i >= 0 and i < n) and (j >= 0 and j < n)):
            rhombus_lines[index].append(grid[i][j])
            i += 1; j += 1
        
        i = (n-1); j = (n-1)-index
        while((i >= 0 and i < n) and (j >= 0 and j < n)):
            rhombus_lines[index].append(grid[i][j])
            i -= 1; j += 1
        
        i = index; j = n-1
        while((i >= 0 and i < n) and (j >= 0 and j < n)):
            rhombus_lines[index].append(grid[i][j])
            i -= 1; j -= 1

    # INSIDE RHOMBUS
    i = 0; j = center
    for index in range(center, n-1):
        for _ in range(n - index - 1):
            rhombus_lines[index].append(grid[i][j])
            i += 1; j -= 1

        for _ in range(n - index - 1):
            rhombus_lines[index].append(grid[i][j])
            i += 1; j += 1

        for _ in range(n - index -1):
            rhombus_lines[index].append(grid[i][j])
            i -= 1; j += 1

        for _ in range(n - index - 1):
            rhombus_lines[index].append(grid[i][j])
            i -= 1; j -= 1
        i += 1
    
    rhombus_lines[n-1] = [grid[center][center]]

    # FINAL ANSWER
    for index in reversed(range(n)):
        k = len(rhombus_lines[index]) // 4 * d
        if(index < center and t == 1): k -= 1
        if(t == 0): ans += "".join(rhombus_lines[index][k:]) + "".join(rhombus_lines[index][:k])
        elif(t == 1): ans += "".join(rhombus_lines[index][k::-1]) + "".join(rhombus_lines[index][:k:-1])

    return ans

_n, _d, _t = map(int, input().split())

_grid = []
for _ in range(_n):
    _row = []
    for num in input().split():
        _row.append(num)
    _grid.append(_row)

print(solve(_n, _d, _t, _grid))