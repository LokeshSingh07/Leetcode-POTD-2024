// 1106. Parsing A Boolean Expression

class Solution {
public:
    void solveOp(vector<char> &vec, char op, stack<char> &st){
        bool res = vec[0] == 't' ? 1 : 0;
        if(op == '&'){
            for(int i=1; i<vec.size(); i++){
                bool ch = vec[i] == 't' ? 1 : 0;
                res = res & ch;
            }
        }
        else if(op == '|'){
            for(int i=1; i<vec.size(); i++){
                bool ch = vec[i] == 't' ? 1 : 0;
                res = res | ch;
            }
        }
        else if(op == '!') res = !res;

        if(res == 1) st.push('t');
        else st.push('f');

    }

    bool parseBoolExpr(string exp) {
        stack<char> st;
        int n = exp.size();

        for(int i=0; i<n; i++){
            char ch = exp[i];
            vector<char> vec;    
            if(ch == ',') continue;
            else if(ch == ')'){
                while(!st.empty() && st.top() != '('){
                    vec.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                solveOp(vec, op, st);
            }
            else{
                st.push(ch);
            }
        }

        return st.top() == 't' ? true : false;
    }
};