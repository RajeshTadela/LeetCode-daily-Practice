class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>values;
        for(int i=0;i<n;i++){
            if(tokens[i] != "+" && tokens[i] != "-" &&
               tokens[i] != "*" && tokens[i] != "/") {
                int num = stoi(tokens[i]);
                values.push(num);
            }
                
            else{
                int b=values.top();
                values.pop();
                int a=values.top();
                values.pop();
                if(tokens[i]=="+") values.push(a+b);
                if(tokens[i]=="-") values.push(a-b);
                if(tokens[i]=="*") values.push(a*b);
                if(tokens[i]=="/") values.push(a/b);
            }
        }
        return values.top();
    }
};