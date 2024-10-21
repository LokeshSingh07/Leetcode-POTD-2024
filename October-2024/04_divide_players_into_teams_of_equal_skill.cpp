// 2491. Divide Players Into Teams of Equal Skill

class Solution {
public:
    long long dividePlayers(vector<int>& skill){
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int sum = 0;
        int i=0, j=n-1;
        sum = skill[i++] + skill[j--];

        while(i<j){
            if(sum != skill[i] + skill[j]){
                return -1;
            }
            i++;
            j--;
        }

        i=0; j=n-1;
        long long result = 0;
        while(i<j){
            result += (skill[i] * skill[j]);
            i++;
            j--;
        }

        return result;
    }
};