number = input()
float_zeros = ""
for _ in range(6 - len(number)): float_zeros += '0'
number = int(number) if '.' not in number else number + float_zeros
print("%05d" % number if type(number) == int else number)