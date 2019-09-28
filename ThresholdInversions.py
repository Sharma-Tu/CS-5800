# -*- coding: utf-8 -*-
"""
Created on Wed Sep 25 02:01:15 2019

@author: Tushar
"""

"""
###########Hackerank initialization##########
import sys
userInput = sys.stdin.readlines()

t,n,array = [i for i in userInput]

t = int(t)
n = int(n)
array = [int(i) for i in array.split()]
#############################################
"""

t,n = [2,4]
array = [8,4,2,1]

"""
################## BRUTE FORCE #################
for k in range(n):
    for l in range(k+1,n):
        if(array[k] > t*array[l]):
            cntInv += 1

print(cntInv)
"""


def mergeSort(array):
    
    cntInv = 0
    if len(array) > 1: #base case
        
        #DIVIDE
        mid = len(array) // 2
        left = array[:mid]
        right = array[mid:]
        
        cntInv += mergeSort(left)
        cntInv += mergeSort(right)
        
        #CONQUER(COUNT T.INVERSIONS)
        i = j = 0
        while i < len(left):
            while j < len(right) and  left[i] > t * right[j]:
                j+=1
            cntInv += j
            i+=1
        
        #MERGE
        i = j = k = 0
        while i < len(left) and j < len(right): 
            if (left[i] < right[j]):
                array[k] = left[i] 
                i+=1
            else:                
                array[k] = right[j]
                j+=1                
            k+=1
        
        while i < len(left):
            array[k] = left[i]
            i+=1
            k+=1
        
        while j < len(right):
            array[k] = right[j]
            j+=1
            k+=1
        
    return cntInv

cntInversions = mergeSort(array)
print(cntInversions)