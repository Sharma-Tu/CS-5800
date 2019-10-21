# -*- coding: utf-8 -*-
"""
Created on Fri Oct 18 01:34:22 2019

@author: Tushar
"""


N=10e80
memo = {}

def fib(n):
    if n in memo:
        return memo[n]
    if n<=2:
        return 1
    else:
        f = fib(n-1)+fib(n-2)
        memo[n] = f
    return f

memo[0] = 0
memo[1] = 1
memo[2] = 1
n = 3
fib(n)

while memo[n-1] <= N:
    fib(n)
    n += 1
    
s = 0
for i in memo:
    if memo[i] <= N and memo[i]%2 == 0:
        s += memo[i]

print(s)