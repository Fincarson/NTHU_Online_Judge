n, m = map(int, input().split())

horses = (n * 4 - m) // 2
cowboys = n - horses
print(f"{horses} {cowboys}")