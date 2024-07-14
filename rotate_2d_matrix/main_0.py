#!/usr/bin/python3
"""
Test  - Rotate 2D Matrix
"""
rotate_2d_matrix = __import__('0-rotate_2d_matrix').rotate_2d_matrix

if __name__ == "__main__":
    matrix = [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]]

    for i in range(len(matrix)):
        print(matrix[i])
    print()
    rotate_2d_matrix(matrix)
    for i in range(len(matrix)):
        print(matrix[i])
    print()
    print()

    matrix = [[1, 11, 13, 19],
              [41, 32, 6, 22],
              [55, 21, 41, 66],
              [77, 29, 78, 2]]

    for i in range(len(matrix)):
        print(matrix[i])
    print()
    rotate_2d_matrix(matrix)
    for i in range(len(matrix)):
        print(matrix[i])
    print()
    print()

    matrix = [[5, 6], [7, 8]]

    for i in range(len(matrix)):
        print(matrix[i])
    print()
    rotate_2d_matrix(matrix)
    for i in range(len(matrix)):
        print(matrix[i])
    print()
    print()

    matrix = [[5, 8, 11, 14, 17, 20],
              [23, 26, 29, 32, 35, 38],
              [41, 44, 47, 50, 53, 56],
              [59, 62, 65, 68, 71, 74],
              [77, 80, 83, 86, 89, 92],
              [95, 98, 101, 104, 107, 110]]

    for i in range(len(matrix)):
        print(matrix[i])
    print()
    rotate_2d_matrix(matrix)
    for i in range(len(matrix)):
        print(matrix[i])
    print()
    print()
