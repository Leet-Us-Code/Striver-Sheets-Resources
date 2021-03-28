class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        //OM GAN GANAPATHAYE NAMO NAMAH
        //JAI SHRI RAM
        //JAI BAJRANGBALI
        //AMME NARAYANA, DEVI NARAYANA, LAKSHMI NARAYANA, BHADRE NARAYANA
        int p1 = 0, p2 = 0;
        int n = intervals.size();
        vector<pair<int, int>> inter;
        for (int i = 0; i < n; i++)
        {
            inter.push_back(make_pair(intervals[i][0], intervals[i][1]));
        }
        sort(inter.begin(), inter.end());
        int k = 0;
        while (p1 < n && p2 < n)
        {
            inter[k].first = inter[p2].first;
            inter[k].second = inter[p2].second;
            while (p1 < n && inter[k].second >= inter[p1].first)
            {
                inter[k].first = min(inter[k].first, inter[p1].first);
                inter[k].second = max(inter[k].second, inter[p1].second);
                p1++;
            }
            k++;
            p2 = p1;
        }
        vector<vector<int>> res;
        for (int i = 0; i < k; i++)
        {
            vector<int> temp;
            temp.push_back(inter[i].first);
            temp.push_back(inter[i].second);
            res.push_back(temp);
        }
        return res;
    }
};
