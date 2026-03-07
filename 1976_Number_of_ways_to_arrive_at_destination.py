import heapq

class Solution:
    def countPaths(self, n, roads):
        MOD = 10**9 + 7
        
        graph = [[] for _ in range(n)]
        
        for u, v, w in roads:
            graph[u].append((v, w))
            graph[v].append((u, w))
        
        dist = [float('inf')] * n
        ways = [0] * n
        
        dist[0] = 0
        ways[0] = 1
        
        pq = [(0, 0)]  # (distance, node)
        
        while pq:
            d, node = heapq.heappop(pq)
            
            for nei, w in graph[node]:
                newDist = d + w
                
                if newDist < dist[nei]:
                    dist[nei] = newDist
                    ways[nei] = ways[node]
                    heapq.heappush(pq, (newDist, nei))
                
                elif newDist == dist[nei]:
                    ways[nei] = (ways[nei] + ways[node]) % MOD
        
        return ways[n-1] % MOD