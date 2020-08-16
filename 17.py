# -*- coding:utf-8 -*-

class Solution(object):
    def __init__(self):
        self.map = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
        '8': 'tuv',
            '9': 'wxyz',
        }
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if digits:
            if len(digits)%2 == 1:
                return self.cutHead([""], digits)
            else:
                return self.cutTail(digits, [""])
        else:
            return []


    def cutHead(self, ret, head):
        if not head:
            return ret

        newRet = []
        for c in self.map[head[0]]:
            for line in ret:
                newRet.append(line + c)
        head = head[1:]
        return self.cutHead(newRet, head)

    def cutTail(self, head, ret):
        "基于后面字符串的结果，继续向前面增加"
        if not head:
            return ret

        newRet = []
        for c in self.map[head[-1]]:
            for line in ret:
                newRet.append(c + line)

        head = head[:-1]
        return self.cutTail(head, newRet)



s = Solution()
print(s.letterCombinations("293"))
