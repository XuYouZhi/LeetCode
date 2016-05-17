// O(m+n) O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int inums1=m-1,inums2=n-1,icur=m+n-1;
        while(inums1>=0&&inums2>=0){
            nums1[icur--]=nums1[inums1]>=nums2[inums2]?nums1[inums1--]:nums2[inums2--];
        }
        while(inums2>=0){
            nums1[icur--]=nums2[inums2--];
        }
    }
};