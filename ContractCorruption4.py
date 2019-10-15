import sys
from collections import defaultdict
import copy
import heapq

userInput = sys.stdin.readlines()

N,C = list(map(int, userInput[0].split()))

#print(N,C)
graphM = defaultdict(list)
graphD = defaultdict(list)
graph = defaultdict(dict)

for i in range(1,C+1):
    arr = list(map(str, userInput[i].split()))
    graph[int(arr[0])][int(arr[1])] = str(arr[2][0])
    if (arr[2] == 'MAVERICK'):
        graphM[int(arr[0])].append(int(arr[1]))
    if (arr[2] == 'DESPERADO'):
        graphD[int(arr[0])].append(int(arr[1]))


def create_spanning_tree(graph, starting_vertex):
    m=d=0
    mst = defaultdict(dict)
    visited = set([starting_vertex])
    edges = [
        (company, starting_vertex, to)
        for to,company in graph[starting_vertex].items()
    ]
    heapq.heapify(edges)
    while edges:
        cmpny, frm, to = heapq.heappop(edges)
        if to not in visited:
            if cmpny == 'M':
                m += 1
            else:
                d += 1
            visited.add(to)
            mst[frm][to] = cmpny
            for to_next, cost in graph[to].items():
                if to_next not in visited:
                    heapq.heappush(edges, (cost, to, to_next))
    #print(m,d)
    return (mst, abs(m-d), m,d)

mst,diff,m,d = create_spanning_tree(graph, 1)
mst = dict(mst)
#print('mst',mst, d)

def create_tree(edges):
    mstgraph = copy.deepcopy(dict(edges))
    for i in edges.keys():
        for j in edges[i].keys():
            if j in mstgraph.keys():
                mstgraph[j][i] = mstgraph[i][j]
            else:
                mstgraph[j] = {i: None}
                mstgraph[j][i] = mstgraph[i][j]
    return(mstgraph)

mstgraph = create_tree(mst)
#print('mstgraph', mstgraph)

#- Spanning tree VALIDITY
def isSpanning(tree):
    """
    Count the edges in the tree
    """
    edges = 0
    for i in tree:
        edges += len(tree[i])
    """
    Count the nodes in the tree
    """
    nodes = []
    for i in tree:
        if i not in nodes:
            nodes.append(i)
        for j in tree[i]:
            if j not in nodes:
                nodes.append(j)
    nodes = len(nodes)
    if abs(nodes-edges) == 1:
        return True
    else:
        return False

def bfs_connected_component(graph, start):
    # keep track of all visited nodes
    explored = []
    # keep track of nodes to be checked
    queue = [start]
 
    # keep looping until there are nodes still to be checked
    while queue:
        # pop shallowest node (first node) from queue
        node = queue.pop(0)
        if node not in explored:
            # add node to list of checked nodes
            explored.append(node)
            if node in graph.keys():
                neighbours = graph[node]
 
            # add neighbours of node to queue
            for neighbour in neighbours:
                queue.append(neighbour)
    
    if len(explored) == N:
        return True
    else:
        return False

#mstSPN = isSpanning(dict(mst))
#mstConnected = isConnected(dict(mst),1)
#print(mstSPN, mstConnected)

e1 = [2,3,'D']
e2 = [1,4,'M']
Tree = dict(mstgraph)


"""
del(Tree[e1[0]][e1[1]])
Tree[e2[0]][e2[1]] = e2[2]
if Tree[e1[0]] == {}:
    del(Tree[e1[0]])
mstSPN = isSpanning(dict(mst))
#mstConnected = isConnected(Tree,1)
mstConnected2 =  bfs_connected_component(Tree,1)
print(mstSPN, mstConnected2)
"""

"""
SWAP
- consider all edges of lower company
"""
def swap(e1,e2): 
    del(mst[e1[0]][e1[1]])
    if e2[0] in mst.keys():
        mst[e2[0]][e2[1]] = e2[2]
    else:
        mst[e2[0]] = {e2[1]: None}
        mst[e2[0]][e2[1]] = e2[2]
    mst[e2[0]][e2[1]] = e2[2]
    if mst[e1[0]] == {}:
        del(mst[e1[0]])
    #print(mst)
    graph = create_tree(mst)
    #print(isSpanning(dict(mst)), bfs_connected_component(dict(graph ),1))
    if isSpanning(dict(mst)) == True and bfs_connected_component(dict(graph),1) == True:
        #print('yes')
        return True
    else:
        try:
            #print('no')
            mst[e1[0]][e1[1]] = e1[2]
            del(mst[e2[0]][e2[1]])
        except:
            pass
        return False

#newtree = swap(dict(mst), [2,3,'D'],[1,4,'M'])
#newtree = swap(dict(mst), [4,5,'D'],[6,1,'D'])
#print("new",newtree)



############### DRIVER #################
if m<d:
    switch = 'M'
else:
    switch = 'D'
swap_edges = []
for i in graph:
    for j in graph[i]:
        if graph[i][j] == switch:
            swap_edges.append([i, j, switch])

current_edges = []
for i in mst:
    for j in mst[i]:
        current_edges.append([i, j, mst[i][j]])


for i in swap_edges:
    for j in current_edges:
        if swap(j, i) == True and abs(diff-1)<diff:
            if switch == 'M':
                m+=1
                d-=1
            else:
                d+=1
                m-=1
            diff = abs(m-d)

print(diff)



