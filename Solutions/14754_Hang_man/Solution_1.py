n = int(input())
k = int(input())

word = input().strip()
guess = ['_'] * n

alphabet = [[] for _ in range(26)]
for i in range (len(word)): alphabet[ord(word[i]) - 65].append(i)

win = False
hint_used = False

while k > 0:
    cmmd = input().split()

    if cmmd[0] == "check":
        found = False
        ch = ord(cmmd[1]) - 65
        if(alphabet[ch]): 
            for i in alphabet[ch]: guess[i] = chr(ch + 65)
        print("".join(guess))
        k -= 1
    
    elif cmmd[0] == "guess":
        if (len(cmmd) >= 2 and cmmd[1] == "".join(word)):
            win = True
            break
        print("Wrong")
        k -= 1

    elif cmmd[0] == "chance":
        print(k)

    elif cmmd[0] == "hint":
        if hint_used: print("Already used")
        else:
            hint_used = True
            if '_' in guess:
                index = guess.index('_')
                ch = ord(word[index]) - 65
                for i in alphabet[ch]: guess[i] = chr(ch + 65)
            print("".join(guess))
            k -= 1

if win: print("You win")
else: print("You lose")