import sys

S = input().strip()
k = int(input())
T = input().strip()

if k > len(S) or k < len(T):
    print("NO")
    sys.exit(0)

if len(T) == 0:
    print("YES")
    sys.exit(0)

diff = [0]*26
for ch in T: diff[ord(ch)-97] += 1
for ch in S[:k]: diff[ord(ch)-97] -= 1

deficits = sum(1 for x in diff if x > 0)
if deficits == 0:
    print("YES")
    sys.exit(0)

def upd(idx, delta):
    nonlocal_deficits = 0
    old = diff[idx]
    was_pos = (old > 0)
    new = old + delta
    diff[idx] = new
    now_pos = (new > 0)
    
    if was_pos and not now_pos: nonlocal_deficits = -1
    elif not was_pos and now_pos: nonlocal_deficits = +1
    return nonlocal_deficits



deficits_var = deficits
for r in range(k, len(S)):
    deficits_var += upd(ord(S[r]) - 97, -1)
    deficits_var += upd(ord(S[r-k]) - 97, +1)

    if deficits_var == 0:
        print("YES")
        sys.exit(0)

print("NO")
