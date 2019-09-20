# -*- coding: utf-8 -*-
"""
Created on Thu Sep 19 17:07:39 2019

@author: Tushar

@title: CS5800 - ps1 (fast modular exp)
"""

"""
###########Hackerank initialization##########
my_string = input()
a, x, n = list(map(int, my_string.split()))

i, a1 = [1,1]
"""

a,x,n,i = [3,1844674300000000000,187987,1]

def decToBin(num):
    strbin = []
    while num >= 1:
        strbin.append(num%2)
        num = num // 2
    return(strbin)

binList = decToBin(x)

print(int(''.join(str(i) for i in reversed(binList))))

#for k in binList:
#    if k == 1:
#        a1 *= (a%n)
#    a *= a
#    i *= 2

modList = []

while i<=x:
    print(a % n)
    modList.append(a % n)
    a = modList[-1] * modList[-1]
    i *= 2

binList = decToBin(x)
a1 = 1
for k in range(len(binList)):
    if binList[k] == 1:
        a1 *= (modList[k])
print(a1 % n)

