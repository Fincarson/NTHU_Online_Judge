def solve(n, d, grid):
    """
    This is the explanation of the template code

    We've read the input for you.

    this function will take in 3 parameters:
        - n:
            a integer representing the size of the grid
        - d:
            a integer representing the starting direction
        - grid:
            a 'nxn' grid filled with integers
            a.k.a, for any grid[i][j] is int

    you need to return a string that satisfies the problem's requirement.

    Feel free to delete this explanation after reading it.
    """

    ans = ""

    # your
    # code
    # here

    return ans

_n, _d = map(int, input().split())

_grid = []
for _ in range(_n):
    _row = []
    for num in input().split():
        _row.append(int(num))
    _grid.append(_row)

print(solve(_n, _d, _grid))