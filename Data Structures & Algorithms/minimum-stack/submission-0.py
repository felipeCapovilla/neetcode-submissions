class MinStack:

    def __init__(self):
        self.values = []
        self.minValues = []
        
    def push(self, val: int) -> None:
        self.values.append(val)
        val = min(val,self.minValues[-1] if self.minValues else val)
        self.minValues.append(val)



    def pop(self) -> None:
        self.values.pop()
        self.minValues.pop()
        

    def top(self) -> int:
        return self.values[len(self.values)-1]

    def getMin(self) -> int:
        return self.minValues[-1]
        
