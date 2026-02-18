class Solution(object):
    def eventualSafeNodes(self, graph):
        n = len(graph) # 0 = unvisited, 1 = visited, 2 = safe
        state = [0] * n
        def dfs(node):
            if state[node] == 1:
                return False
            if state[node] == 2:
                return True
            state[node] = 1
            for nei in graph[node]:
                if not dfs(nei): # if not safe
                    return False
            state[node] = 2
            return True
        res = []
        for i in range(n):
            if dfs(i):
                res.append(i)
        return res