import sys
import copy
from collections import defaultdict
T = int(input().strip())

for a0 in range(T):
    n = int(input().strip())
    tri = [[] for i in range(n)]
    #path = {}
    for a1 in range(n):
        c = input().strip()
        C = list(map(int, c.split()))
        tri[a1] = C
    
    #print(tri)
    #path = copy.deepcopy(tri)
    #print(dict(path))
    for i in range(len(tri) - 2, -1, -1):
        #print(i)
        for j in range(i+1):
            #print(tri[i][j])
            tri[i][j]+= max(tri[i+1][j], tri[i+1][j+1])
    print (tri[0][0])
