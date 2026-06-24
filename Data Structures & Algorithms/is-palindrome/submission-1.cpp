class Solution {
public:
        bool isPalindrome(std::string s){
        int left = 0;
        int right = s.size() - 1;

        while(left < right){
            while(left < right && !isalnum(s[left])){
                left++;
            }
            while(right > left && !isalnum(s[right])){
                right--;
            }
            if(std::tolower(s[left]) != std::tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
