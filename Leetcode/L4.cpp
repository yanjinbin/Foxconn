#include "../QuikTemplate.cpp"

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int len1 = nums1.size(), len2 = nums2.size();
    int left = (len1 + len2 + 1) / 2;
    int right = (len1 + len2 + 2) / 2;
    int ans1 = getKthNumber(nums1, 0, len1 - 1, nums2, 0, len2 - 1, left);
    int ans2 = getKthNumber(nums1, 0, len1 - 1, nums2, 0, len2 - 1, right);
    return (ans1 + ans2) / 2.0;
  }

  int getKthNumber(vector<int> &nums1, int s1, int e1, vector<int> &nums2, int s2, int e2, int k) {
    int len1 = e1 - s1 + 1;
    int len2 = e2 - s2 + 1;
    if (len1 > len2)
      return getKthNumber(nums2, s2, e2, nums1, s1, e1, k);
    if (len1 == 0)
      return nums2[k + s2 - 1];
    if (k == 1)
      return min(nums1[s1], nums2[s2]);
    int i = min(k / 2, len1) + s1 - 1;
    int j = min(k / 2, len2) + s2 - 1;
    if (nums1[i] > nums2[j]) { // 排除  前J个
      return getKthNumber(nums1, s1, e1, nums2, j + 1, e2, k - (j - s2 + 1));
    } else {
      return getKthNumber(nums1, i + 1, e1, nums2, s2, e2, k - (i - s1 + 1));
    }
  }
};

int main() {
  Solution INSTANCE;
  vector<int> nums1 = {1, 2};
  vector<int> nums2 = {3, 4};
  int ans = INSTANCE.findMedianSortedArrays(nums1, nums2);
  cout << ans << endl;
  return 0;
}