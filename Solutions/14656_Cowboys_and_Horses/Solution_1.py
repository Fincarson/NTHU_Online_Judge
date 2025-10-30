legs, tails = map(int, input().split())
legs = (legs - (tails * 4)) // 2
print(legs, tails)