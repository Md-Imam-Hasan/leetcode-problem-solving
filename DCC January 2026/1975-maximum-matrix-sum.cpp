class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        vector<int> v;
        bool good = true;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0;j < matrix[i].size(); j++) {
                int temp = matrix[i][j];
                if (temp < 0) {
                    good = !good;
                    // cout<<"good: "<<good<<endl;
                    temp = -1 * temp;
                }
                v.push_back(temp);
                sum += temp;
            }
        }

        sort(v.begin(), v.end());

        // cout<<"final good: "<<good<<endl;

        if (!good) {
            sum -= v[0]*2;
        }

        return sum;
    }
};