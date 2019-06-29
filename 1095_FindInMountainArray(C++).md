# [1095. Find in Mountain Array](https://leetcode.com/problems/find-in-mountain-array/)

(This problem is an interactive problem.)

You may recall that an array ```A``` is a mountain array if and only if:

- ```A.length >= 3```
- There exists some ```i``` with ```0 < i < A.length - 1``` such that:
  - ```A[0] < A[1] < ... A[i-1] < A[i]```
  - ```A[i] > A[i+1] > ... > A[A.length - 1]```
  
Given a mountain array ```mountainArr```, return the minimum ```index```
such that ```mountainArr.get(index) == target```.
If such an ```index``` doesn't exist, return ```-1```.

You can't access the mountain array directly.
You may only access the array using a ```MountainArray``` interface:

```MountainArray.get(k)``` returns the element of the array at index ```k``` (0-indexed).

```MountainArray.length()``` returns the length of the array.

Submissions making more than ```100``` calls to ```MountainArray.get``` will be judged *Wrong Answer*. 

Also, any solutions that attempt to circumvent the judge will result in disqualification.
 

## Example 1:

```
Input: array = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
```

## Example 2:

```
Input: array = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.
```
 

## Constraints:

```
3 <= mountain_arr.length() <= 10000
0 <= target <= 10^9
0 <= mountain_arr.get(index) <= 10^9
```


# Code:
```C++
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 1, right = mountainArr.length() - 2;

        while (left < right) {
            int middle = (left + right) / 2;
            int first_val = mountainArr.get(middle);
            int second_val = mountainArr.get(middle + 1);
            if (first_val <= second_val) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }
        int mount_ind = left;
        int res = Search(target, 0, mount_ind, mountainArr);
        if (res == -1) {
            res = Search2(target, mount_ind + 1, mountainArr.length() - 1, mountainArr);
        }
        return res;
    }
    int Search(int target, int beg, int end, MountainArray &mountainArr) {
        while (beg < end) {
            int mid = (beg + end) / 2;
            if (mountainArr.get(mid) < target) {
                beg = mid + 1;
            } else {
                end = mid;
            }
        }
        if (mountainArr.get(beg) == target) {
            return beg;
        }
        return - 1;
    }
    int Search2(int target, int beg, int end, MountainArray &mountainArr) {
        while (beg < end) {
            int mid = (beg + end) / 2;
            if (mountainArr.get(mid) > target) {
                beg = mid + 1;
            } else {
                end = mid;
            }
        }
        if (mountainArr.get(beg) == target) {
            return beg;
        }
        return - 1;
    }
};
```
