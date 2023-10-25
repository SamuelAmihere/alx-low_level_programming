#!/usr/bin/python3
"""
module for perimeter
"""


def island_perimeter(grid):
    """returns a perimeter of an Island
    Args:
         grid (list) = [integers]
    """

    height = len(grid)
    width = len(grid[0])
    size = 0
    edges = 0

    for k in range(height):
        for l in range(width):
            if grid[k][l] == 1:
                size += 1
                if (l > 0 and grid[k][l - 1] == 1):
                    edges += 1
                if (k > 0 and grid[k - 1][l] == 1):
                    edges += 1
    return ((size * 4) - (edges * 2))
