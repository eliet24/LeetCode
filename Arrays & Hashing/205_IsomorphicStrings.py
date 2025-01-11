

class Solution:
    def  isIsomorphic(self, s: str, t: str) -> bool:
        map_st, map_ts = {}, {}

        for c1, c2 in zip(s,t):
            if (c1 in map_st and map_st[c1] != c2) or (c2 in map_ts and map_ts[c2] != c1):
                return False
            map_st[c1] = c2
            map_ts[c2] = c1

        return True

def main():
    # Create an instance of the Solution class
    solution = Solution()

    # Define test cases
    test_cases = [
        ("egg", "add", True),
        ("foo", "bar", False),
        ("paper", "title", True),
        ("ab", "aa", False),
        ("abcd", "efgh", True),
        ("", "", True),
    ]

    # Test the isIsomorphic function with the test cases
    for s, t, expected in test_cases:
        result = solution.isIsomorphic(s, t)
        print(f"isIsomorphic({s}, {t}) = {result} (expected: {expected})")

if __name__ == "__main__":
    main()