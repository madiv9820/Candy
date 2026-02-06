from libc.stdlib cimport calloc, free   # 🏗️ For allocating and freeing memory in C

# 🔗 Declare the external C function from "solution.h"
cdef extern from "solution.h":
    int candy(int* ratings, int ratingsSize)  # 🍬 Computes minimum candies needed

# 🎯 Cython wrapper class to call our C function safely
cdef class cSolution:
    # 🍭 Wrapper method to call the C 'candy' function
    def c_Candy(self, ratings):
        cdef int n = len(ratings)   # 📏 Number of children
        cdef int i                  # 🔁 Loop variable for copying elements

        # 🧰 Allocate memory for a C array of ints
        # calloc initializes everything to 0
        cdef int* ratingsArray = <int*> calloc(n, sizeof(int))
        if ratingsArray == NULL:  
            raise MemoryError("Memory Allocation Failed")       # 💥 Memory allocation failed!
        
        try:
            for i in range(n): ratingsArray[i] = ratings[i]     # 🔄 Copy Python list to C array for the C function
            return candy(ratingsArray, n)                       # 🍬 Call the C function and return the result
        finally: free(ratingsArray)                             # 🧹 Free allocated memory to prevent leaks