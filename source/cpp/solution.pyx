from libcpp.vector cimport vector  # 🗃️ Import C++ vector for dynamic arrays

# 🔗 Declare the C++ class from solution.hpp
cdef extern from "solution.hpp":
    cdef cppclass Solution:
        Solution() except +                 # 🏗️ Constructor, can throw exceptions
        int candy(vector[int]& ratings)     # 🍬 C++ method to compute minimum candies

# 🎯 Cython wrapper class for the C++ Solution
cdef class cppSolution:
    cdef Solution *ptr  # 🧩 Pointer to the C++ Solution object

    # 🏗️ Initialize the C++ object
    def __init__(self): ptr = new Solution()

    # 🧹 Clean up the C++ object when Python object is deleted
    def __dealloc__(self): del(ptr)

    # 🍭 Wrapper method to call the C++ candy function
    def cpp_Candy(self, ratings):
        cdef vector[int] ratingsArray           # 🗃️ Temporary C++ vector to hold ratings
        cdef int i                              # 🔁 Loop variable

        for i in range(len(ratings)):           # 🔄 Copy Python list into C++ vector
            ratingsArray.push_back(ratings[i])

        return self.ptr.candy(ratingsArray)      # 🍬 Call the C++ method and return result