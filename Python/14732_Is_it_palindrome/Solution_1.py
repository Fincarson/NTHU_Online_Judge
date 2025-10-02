S = ""
reverse_S = ""
for T in range(int(input())):
    S = input()
    reverse_S = S[::-1]
    
    if(S == reverse_S): print("Yes")
    else: print("No")