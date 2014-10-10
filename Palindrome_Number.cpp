class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(0 <= x && x <= 9)
            return true;
        if(x % 10 == 0)
            return false;
        int y = 0;
        while(x > y) {
            if(y == x / 10)
                return true;
            y = y * 10 + x % 10;
            x /= 10;
            if(x == y)
                return true;
        }
        return false;
    }
};
