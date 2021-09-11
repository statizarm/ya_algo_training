import sys

fib = [1, 1]
nums = {1}
n = int(sys.stdin.readline())

for i in range(n):
  num = int(sys.stdin.readline())
  while num > fib[1]:
    tmp = fib[1]
    fib[1] = fib[0] + fib[1]
    fib[0] = tmp;
    nums.add(fib[1])

  if num in nums:
    print('Yes')
  else:
    print('No')

