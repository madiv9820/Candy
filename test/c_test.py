import unittest
from timeout_decorator import timeout
from source.c.solution import cSolution

class test_c_Solution(unittest.TestCase):
    def setUp(self):
        self.__testcases = (
            ([1,0,2], 5),
            ([1,2,2], 4),
            ([1,3,4,5,2], 11),
            ([5,4,3,2,1], 15),
            ([1,2,2,3,1], 7),
            ([1], 1),
            ([1,2,3,2,1,2,3,2,1], 19)
        )
        self.__solution = cSolution()
        return super().setUp()
    
    @timeout(1)
    def test(self):
        for ratings, expectedOutput in self.__testcases:
            with self.subTest(ratings):
                actualOutput = self.__solution.c_Candy(ratings)
                self.assertEqual(actualOutput, expectedOutput)

if __name__ == '__main__': unittest.main()