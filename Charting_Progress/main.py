try:
    while True:
        matrix = []
        line = input()
        while line != '':
            matrix.append(line)
            line = input()
        N = len(matrix[0])
        M = len(matrix)
        rotated_matrix = ['' for _ in range(N)]
        for i in range(N):
            for j in range(M):
                rotated_matrix[i] += matrix[j][i]
        rotated_matrix = sorted(rotated_matrix, reverse=True)
        sorted_matrix = ['' for _ in range(N)]
        for i in range(N):
            for j in range(N):
                sorted_matrix[j] += rotated_matrix[j][i]
        for row in sorted_matrix:
            print(row)
        print()
except:
    pass