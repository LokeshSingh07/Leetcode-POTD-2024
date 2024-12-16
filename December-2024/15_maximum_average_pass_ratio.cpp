// 1792. Maximum Average Pass Ratio

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<pair<double,int>> pq;       // maxHeap

        for(int i=0; i<n; i++){
            double PR = (double)classes[i][0]/classes[i][1];
            double new_PR = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double diff = new_PR - PR;
            pq.push({diff, i});
        }

        while(extraStudents--){
            pair<double,int> curr = pq.top();
            pq.pop();
            double diff = curr.first;
            int idx = curr.second;

            // update the classes[idx][]
            classes[idx][0]++;
            classes[idx][1]++;

            double PR = (double)classes[idx][0]/classes[idx][1];
            double new_PR = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            diff = new_PR - PR;
            pq.push({diff, idx});
        }

        // calculate the avg
        double result = 0.0;
        for(int i=0; i<n; i++){
            result += (double)classes[i][0]/classes[i][1];
        }

        return result/n;
    }
};