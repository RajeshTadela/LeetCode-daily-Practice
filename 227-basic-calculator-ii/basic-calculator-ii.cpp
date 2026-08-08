class Solution {
public:
    int precedence(char ch){
        if(ch=='*' || ch=='/' || ch=='%') return 2;
        if(ch=='+' || ch=='-') return 1;
        return 0;
    }
    int operation(stack<int>& values,stack<char>& operators){
        int b=values.top();
        values.pop();
        int a= values.top();
        values.pop();
        char op=operators.top();
        operators.pop();
        if(op=='+') return a+b;
        else if(op=='-') return a-b;
        else if(op=='*') return a*b;
        else if(op=='/') {
            if(b==0) return 0;
            return a/b;
        }
        else return a%b;
    }
    int calculate(string s) {
        stack<int> values;
        stack<char> operators;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                int num=0;

                while(i<s.length() && isdigit(s[i])){
                    num=num*10 + (s[i]-'0');
                    i++;
                }
                i--;
                values.push(num);
            }
            else if(s[i]==' '){
                continue;
            }
            else{
                while(!operators.empty() && precedence(operators.top())
                >= precedence(s[i]) ){
                    int result=operation(values,operators);
                    values.push(result);
                }
                operators.push(s[i]);
            }
        }
        while(!operators.empty()) {
            int result = operation(values, operators);
            values.push(result);
        }
        return values.top();

    }
};