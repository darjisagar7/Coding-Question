class Solution {
public:
    
    int distance(vector<int> a) {
        return (a[0] * a[0]) + (a[1] * a[1]);
        
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<int> dists;

        if (points.size() <= k) {
            return points;
        }

        for (int i=0; i<points.size() ; i++) {

            dists.push_back(distance(points[i]));
        }
        
        sort(dists.begin(), dists.end());
        int distK = dists[k-1];
        
        vector<vector<int>> ans;
        for (int i=0; i<points.size() ; i++) {
            if (distance(points[i]) <= distK) {
                ans.push_back(points[i]);
            }
        }

        return ans;
    }
};
