class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();

        vector<pair<double, int>> v;
        priority_queue<int> pq;

        for (int i=0; i<n; i++) {
            v.push_back({wage[i]/((double)quality[i]), quality[i]});
        }

        sort(v.begin(), v.end());
        double sum = 0;
        double res = DBL_MAX;
        for (int i = 0; i< n; i++) {
            pq.push(v[i].second);
            sum += v[i].second;

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                res = min(res, sum * v[i].first);
            }
        
        }

        return res;
    }
};
