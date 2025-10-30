T = int(input())
for t in range(T):
    N = int(input())
    array = []
    array.extend(map(int, input().split()))
        

    sumMax = array[0]
    sumOutput = array[0]

    for i in range(1, N):
        if sumMax + array[i] > array[i]:
            sumMax = sumMax + array[i]
        else:
            sumMax = array[i]

        if sumMax > sumOutput:
            sumOutput = sumMax

    output = sumOutput
    print(output)