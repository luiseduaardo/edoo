def binarySearch(nums: int, target: int) -> int:
    lo, hi = 0, len(nums)
    steps = 0

    while lo < hi:
        steps += 1
        mid = int((lo + hi)/2)

        if nums[mid] == target:
            print(steps)
            return mid
        elif nums[mid] < target:
            lo = mid + 1
        else:
            hi = mid
    
    return -1

a = [1,2,3,4,5]
b = [1,2,3,4,5,6,7,8,9,10]
c = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
d = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40]

binarySearch(a,3)  # retorna 1 passo
binarySearch(b,3)  # retorna 2 passos
binarySearch(c,3)  # retorna 3 passos
binarySearch(d,3)  # retorna 4 passos
