s = input()
l, r = map(int, input().split())
print(s[:l] + s[r+1:] + s[l:r+1])