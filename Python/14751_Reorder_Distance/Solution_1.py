s = input().strip()
t = input().strip()

count_s = [0] * 26
count_t = [0] * 26

for ch in s: count_s[ord(ch) - 97] += 1
for ch in t: count_t[ord(ch) - 97] += 1

matches = sum(min(count_s[i], count_t[i]) for i in range(26))
print(len(s) - matches)