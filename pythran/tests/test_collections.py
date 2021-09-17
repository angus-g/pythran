from pythran.tests import TestEnv
from pythran.typing import Deque

class TestDeque(TestEnv):
    def test_deque_(self):
        self.run_test("def deque_(a): from collections import deque; return deque([a])",
                      5,
                      deque_=[Deque[int]])
