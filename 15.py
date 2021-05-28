n = int(input())
nums = [int(x) for x in input().split()]
cur = nums[0]
cur_auto = nums[0]
count = 0

for i in range(1, n):
    if nums[i] < cur:
        count += cur - nums[i]
    elif nums[i] > cur_auto:
        count += nums[i] - cur_auto
        cur_auto = nums[i]
    cur = nums[i]
print(count)