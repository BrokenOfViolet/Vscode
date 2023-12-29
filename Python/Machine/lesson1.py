class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)):
            if nums[i] == 0:
                nums.append(nums.pop(i))
        print(nums)

a = Solution().moveZeroes([0,0,1])