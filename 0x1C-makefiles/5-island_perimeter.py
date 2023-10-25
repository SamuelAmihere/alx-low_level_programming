#!/usr/bin/python3
"""
module for function calculating perimeter
"""


def island_perimeter(grid):
    """returns the perimeter of an island

    Args:
         grid (list) = a list of integers
    """

    height = len(grid)
    width = len(grid[0])
    size = 0
    edges = 0

    i = 0
    while (i < height):
        for j in range(width):
            if grid[i][j] == 1:
                size += 1
                if (j > 0 and grid[i][j - 1] == 1):
                    edges += 1
                if (i > 0 and grid[i - 1][j] == 1):
                    edges += 1
        i++
    return size * 4 - edges * 2
