from collections import deque

class Solution:
    def shortestPathBinaryMatrix(self, grid):
        n = len(grid)
        
        # Edge case
        if grid[0][0] == 1 or grid[n-1][n-1] == 1:
            return -1
        
        directions = [(-1,-1), (-1,0), (-1,1),
                      (0,-1),           (0,1),
                      (1,-1),  (1,0),   (1,1)]
        
        queue = deque([(0, 0, 1)])  # (row, col, distance)
        grid[0][0] = 1  # mark visited
        
        while queue:
            r, c, dist = queue.popleft()
            
            if r == n-1 and c == n-1:
                return dist
            
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                
                if 0 <= nr < n and 0 <= nc < n and grid[nr][nc] == 0:
                    grid[nr][nc] = 1  # mark visited
                    queue.append((nr, nc, dist + 1))
        
        return -1