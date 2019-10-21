# -*- coding: utf-8 -*-
"""
Created on Sat Oct 19 03:41:44 2019

@author: Tushar
"""

#from collections import defaultdict
import copy
N=100

f  = open("p067_triangle.txt", "r")
tri = {}
for i in range(N):
    c = f.readline()
    C = list(map(int, c.split()))
    tri[i] = C


#tri = {0:[3], 1:[7,4], 2:[2,4,6], 3: [8,5,9,3]}
path = copy.deepcopy(tri)

def maxPathSum(triangle):    
    #print(dict(path))
    for i in triangle:
        if i>0:
            for j in range(len(triangle[i])):
                path[i][j] = triangle[i][j] + max(path[i-1][j],path[i-1][j+1])
    return max(path[N-1])

print(maxPathSum(tri))

"""
if j == 0:
                    path[i][j] = triangle[i][j] + path[i-1][j]
                if j == i:
                    path[i][j] = triangle[i][j] + path[i-1][j-1]
                else:
"""