class Solution {
public:
    double findMedianSortedArrays(
        std::vector<int>& nums1,
        std::vector<int>& nums2
    ) {
        // Binary Search immer auf dem kleineren Array.
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int left = 0;
        int right = m;

        while (left <= right) {
            // Wie viele Elemente aus nums1 kommen nach links?
            int cut1 = std::midpoint(left, right);

            // Insgesamt sollen links (m+n+1)/2 Elemente liegen.
            int cut2 = (m + n + 1) / 2 - cut1;

            int left1 =
                cut1 == 0 ? INT_MIN : nums1[cut1 - 1];

            int right1 =
                cut1 == m ? INT_MAX : nums1[cut1];

            int left2 =
                cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

            int right2 =
                cut2 == n ? INT_MAX : nums2[cut2];

            // Richtiger Schnitt
            if (left1 <= right2 && left2 <= right1) {
                // Ungerade
                if ((m + n) % 2 == 1) {
                    return std::max(left1, left2);
                }

                // Gerade
                return (
                    std::max(left1, left2) +
                    std::min(right1, right2)
                ) / 2.0;
            }

            // Zu viele Elemente aus nums1 links
            if (left1 > right2) {
                right = cut1 - 1;
            }
            // Zu wenige Elemente aus nums1 links
            else {
                left = cut1 + 1;
            }
        }

        return 0.0;
    }
};