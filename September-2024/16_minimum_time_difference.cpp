// 539. Minimum Time Difference

class Solution {
public:
    int findMinDifference(vector<string>& timePoints){
        int n = timePoints.size();
        vector<int> minutes(n);

        // step1: convert the HH:MM into minutes and store it in array
        for(int i=0; i<n; i++){
            string time = timePoints[i];
            int hrInt = stoi(time.substr(0,2));
            int minInt = stoi(time.substr(3));

            minutes[i] = 60*hrInt + minInt;
        }

        // step2: sort and then find minimum
        sort(begin(minutes), end(minutes));
        int mini = INT_MAX;
        for(int i=0; i<n-1; i++){
            mini = min(mini, minutes[i+1] - minutes[i]);
        }

        return min(mini, (24*60 + minutes[0]) - minutes[n-1]);      // catch
    }
};