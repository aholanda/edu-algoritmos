import numpy as np

# Couting sorting in python based on lecture
# MIT OpenCourseWare: Counting Sort, Radix Sort, Lower Bounds for Sorting
# by Erik Demaine
# Available at: https://www.youtube.com/watch?v=Nz1KZXbghj8

def countingsort(V):
        '''Executa o counting sort no vetor de inteiros V.'''
        n = len(V)
        L = [[]] * (np.max(V) + 1)
        for i in range(len(L)):
                L[i] = []
        output = []
        
        for j in range(n):
                L[V[j]].append(V[j])

        for i in range(len(L)):
                output.extend(L[i])
        
        return output

if __name__ ==  "__main__":
        V = [11, 70, 82, 72, 34, 25, 5, 9]
        print('Original:', V)
        print('Sorted:\t', countingsort(V))
