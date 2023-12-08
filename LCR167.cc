class Solution {
public:
    int dismantlingAction(string arr) {
        int ans = 0;
        unordered_set<char> sets;
        int i = 0, j = 0;
        while(j < arr.size())
        {
            while(sets.count(arr[j]))
                sets.erase(arr[i++]);
            sets.insert(arr[j++]);
            ans = max(j - i, ans); 
        }
        return ans;
    }
};