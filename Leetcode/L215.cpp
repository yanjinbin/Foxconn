#include "../QuikTemplate.cpp"

class Solution {
public:
  int findKthLargest(vector<int> nums, int k) {
    int left = 0, right = nums.size() - 1;
    while (true) {
      int pos = partition(nums, left, right);
      if (pos == k - 1)
        return nums[pos];
      if (pos < k - 1) {
        left = pos + 1;
      } else {
        right = pos - 1;
      }
    }
  }

  void swap(vector<int> &nums, int i, int j) {
    if (i == j)
      return;
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }
  // ⚠️ 要传递指针变量
  int partition(vector<int> &nums, int lo, int hi) {
    int pivot = nums[lo];
    int l = lo + 1, r = hi;
    while (l <= r) {
      if (nums[l] < pivot && pivot < nums[r]) {
        swap(nums, l++, r--);
      }
      if (nums[l] >= pivot)
        l++;
      if (nums[r] <= pivot)
        r--;
    }
    // l-r=1
    // 为什么必须要 交换的是R呢
    // 分三种情况
    // l=r的时候 nums[l]>=pivot 或者 nums[r]<=pivot
    // l+1=r的时候 l++,r--此时 此时l = r ,r = l,那么 此时需要交交还的依旧是因为nums[r]>nums[l]
    swap(nums, lo, r);
    return r;
  }
};

int main() {
  Solution INSTANCE;
  auto nums = {3, 2, 1, 5, 6, 4};
  int k = 2;
  cout << INSTANCE.findKthLargest(nums, k);
  return 0;
}