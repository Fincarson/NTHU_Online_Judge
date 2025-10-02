S = input()
l, r = map(int, input().split())

sub_S = S[l:r]
ret_S = ""

for i in range(r-l): ret_S += sub_S
print(ret_S)