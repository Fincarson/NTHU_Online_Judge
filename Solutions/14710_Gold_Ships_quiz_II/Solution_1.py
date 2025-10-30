def count(inStr: str)->dict:
    #Write your code here
    inStr = inStr.replace("'", " '").replace('.', '').replace(',', '').replace('-', '')
    str = inStr.split()

    gold_ship = {}
    for key in str:
        key = key.lower()
        gold_ship[key] = 1 if key not in gold_ship else gold_ship[key] + 1
    return gold_ship
        

print(sorted(count(input()).items()))