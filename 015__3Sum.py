from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = set()

        n, p, z = [], [], []
        for num in nums:
            if num > 0:
                p.append(num)
            elif num < 0:
                n.append(num)
            else:
                z.append(num)

        n_set, p_set = set(n), set(p)

        if z:
            for num in p_set:
                if -1 * num in n_set:
                    res.add((-1 * num, 0, num))

        if len(z) >= 3:
            res.add((0, 0, 0))

        for i in range(len(n)):
            for j in range(i+1, len(n)):
                target_sum = -1 * (n[i] + n[j])
                if target_sum in p_set:
                    res.add(tuple(sorted([n[i], n[j], target_sum])))

        for i in range(len(p)):
            for j in range(i+1, len(p)):
                target_sum = -1 * (p[i] + p[j])
                if target_sum in n_set:
                    res.add(tuple(sorted([p[i], p[j], target_sum])))

        return res


sol = Solution()
print(sol.threeSum([-1,1,0,2,3]))
