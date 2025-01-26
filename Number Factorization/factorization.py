num = int(input("Enter a number: "))

factors = []

while num != 1:
    for i in range(2, num + 1):
        if num % i == 0:
            num //= i
            factors.append(i)
            break

print("num =", "*".join(map(str, factors)))
