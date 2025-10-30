s = input()
L = s.split()
legs, tails = map(int, L)

legs = legs - (tails * 4)

horses = tails
cowboys = legs // 2

print(cowboys, horses)