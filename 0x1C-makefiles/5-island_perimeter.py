#!/usr/bin/python3
"""
module determining perimeter
"""


def island_perimeter(grid):
    """returns the perimeter of an island
    Args:
         grid (list) = [integers]
    """

    height = len(grid)
    width = len(grid[0])
    edges, size = 0, 0

    i = 0
    while i < height:
        for j in range(width):
            if grid[i][j] == 1:
                size += 1
                if (grid[i][j - 1] == 1 and j > 0):
                    edges += 1
                if (grid[i - 1][j] == 1 and i > 0):
                    edges += 1
        i++
    return ((size * 4) - (edges * 2))
