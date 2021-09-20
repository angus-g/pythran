from pythran.tests import TestEnv
from pythran.typing import Deque

class TestDeque(TestEnv):
    def test_deque_(self):
        self.run_test("def deque_(a): from collections import deque; return deque([a])",
                      5,
                      deque_=[int])

    def test_append_(self):
        self.run_test("def append_(a): from collections import deque; d = deque([1,2,3]); d.append(a); return d",
                      5,
                      append_=[int])
