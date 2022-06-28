class Solution:
    def minDeletions(self, s: str) -> int:
        # freq_map = {}
        # for i in s:
        #     if i not in freq_map:
        #         freq_map[i] = 0
        #     freq_map[i] += 1
        # freq = set()
        freq_map, m, freq = collections.Counter(s), 0, set() # using same thing but inbuilt is faster, way faster
        m = 0
        for i in freq_map.values():
            if i not in freq: freq.add(i)
            else:
                while i in freq and i > 0:
                    i -= 1
                    m += 1
                freq.add(i)
        return m
