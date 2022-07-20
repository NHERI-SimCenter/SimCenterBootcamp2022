def fib(n):
    if n==0 or n==1:
        ans = 1
    else:
        ans = fib(n-2) + fib(n-1)
    return ans

for k in range(10):
    print(fib(k))

fibSeries = [ fib(k) for k in range(10) ]
print(fibSeries)