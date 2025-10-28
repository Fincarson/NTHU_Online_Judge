synonyms = {
    "big": "large",
    "small": "tiny",
    "fast": "quick",
    "slow": "sluggish",
    "happy": "joyful",
    "sad": "unhappy",
    "angry": "furious",
    "good": "great",
    "bad": "awful",
    "hot": "warm",
    "cold": "chilly",
    "smart": "clever",
    "stupid": "dumb",
    "easy": "simple",
    "hard": "difficult",
    "friend": "buddy",
    "enemy": "foe",
    "child": "kid",
    "dog": "puppy",
    "cat": "kitten"
}

article = input().split()
output = ""
for word in article:
    if output != "": output += " "
    output += synonyms[word] if word in synonyms else word
print (output)