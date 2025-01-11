from collections import deque

class MyStack:
    def __init__(self):
        self.q1 = deque()
        self.q2 = deque()

    def push(self, x: int) -> None:
        self.q1.append(x)

    def pop(self) -> int:
        while(len(self.q1) > 1):
            self.q2.append(self.q1.popleft())

        popped = self.q1.popleft()

        self.q1, self.q2 = self.q2, self.q1

        return popped

    def top(self) -> int:
        return self.q1[0]

    def empty(self) -> bool:
        return len(self.q1) == 0

obj = MyStack()
obj.push(1)
obj.push(2)
obj.push(3)
print(obj.pop())
print(obj.top())
print(obj.empty())
print(obj.pop())
print(obj.pop())
print(obj.empty())
