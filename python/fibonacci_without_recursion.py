def fibo(n):
    if(n <= 1):
        return n
    fibo = 1
    fiboPrev = 1
    for x in range(2, n):
        temp = fibo
        fibo += fiboPrev
        fiboPrev = temp

    return fibo

n = input("Calculate Fibonacci number: ")
n = int(float(n))
print(fibo(n))
