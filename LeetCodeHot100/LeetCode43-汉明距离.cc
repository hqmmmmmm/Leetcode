class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        while(x != 0 && y != 0)
        {
            int a = x & 1, b = y & 1;
            if(a != b)
                ans++;
            x >>= 1, y >>= 1;
        }

        while(x)
        {
            if(x & 1) ans++;
            x >>= 1;
        }
        while(y)
        {
            if(y & 1) ans++;
            y >>= 1;
        }
        
        return ans;
    }
};