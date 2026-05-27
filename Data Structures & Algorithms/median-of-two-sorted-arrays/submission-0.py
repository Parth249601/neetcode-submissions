class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        
        m, n = len(nums1), len(nums2)
        half = (m + n + 1) // 2
        lo, hi = 0, m

        while lo <= hi:
            i = (lo + hi) // 2
            j = half - i

            maxLeft1  = nums1[i-1] if i > 0 else float('-inf')
            minRight1 = nums1[i]   if i < m else float('inf')
            maxLeft2  = nums2[j-1] if j > 0 else float('-inf')
            minRight2 = nums2[j]   if j < n else float('inf')

            if maxLeft1 <= minRight2 and maxLeft2 <= minRight1:
                # Found the correct partition
                if (m + n) % 2 == 1:
                    return max(maxLeft1, maxLeft2)
                else:
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2
            elif maxLeft1 > minRight2:
                hi = i - 1
            else:
                lo = i + 1