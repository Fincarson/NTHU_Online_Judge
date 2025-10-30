legs, tails = map(int, input().split())
legs = (legs - (tails * 4)) >> 1
print(legs, tails)