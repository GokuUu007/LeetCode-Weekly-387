#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        map<int, int> ca, cb;
        oset<array<int, 2>> sa, sb;
        vector<int> a, b, c;
        
        a.push_back(nums[0]) , b.push_back(nums[1]);
        sa.insert({nums[0], 0}), sb.insert({nums[1], 1});
        ca[nums[0]]++, cb[nums[1]]++;
        for (int i = 2; i < (int)nums.size(); ++i) {
            int ga = sa.size() - sa.order_of_key({nums[i], -1}) - ca[nums[i]];
            int gb = sb.size() - sb.order_of_key({nums[i], -1}) - cb[nums[i]];
            if (ga > gb) {
                a.push_back(nums[i]), sa.insert({nums[i], i}), ca[nums[i]]++;
            } else if (ga < gb) {
                b.push_back(nums[i]), sb.insert({nums[i],i}), cb[nums[i]]++;
            } else {
                if (a.size() <= b.size()) {
                    a.push_back(nums[i]), sa.insert({nums[i],i}), ca[nums[i]]++;
                } else {
                    b.push_back(nums[i]), sb.insert({nums[i],i}), cb[nums[i]]++;
                }
            }
        }
        for (auto &x : a) {
            c.push_back(x);
        }
        for (auto &x : b) {
            c.push_back(x);
        }
        return c;
    }
};
