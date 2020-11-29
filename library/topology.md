拓扑排序

// dfs+topology sort, 代表例题:https://www.bilibili.com/video/BV1Ut411a74a
`for each node
    if node not marked
        if dfs(node) == Cycle  return Cycle
return OK

dfs(node)
    if node is marked as VISITED ; return OK
    if node is marked as VISITING; return Cycle
    node marked as VISITING
    for each node in node.neighbors
        if dfs(new_node) == CYCLE return Cycle
    marked node as VISITED
    add node to the head of ordered list
    return OK

// BFS+topology sort, 

    
    