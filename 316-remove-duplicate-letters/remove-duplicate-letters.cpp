class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        stack<char> s2;
        unordered_map<char,int> freq;
        unordered_set<char> visited;
        int n=s.length();
        for(char ch : s){
            freq[ch]++;
        }
        for(char ch : s){
            freq[ch]--;
            if(visited.count(ch)) continue;
            while(!st.empty() && st.top() > ch && freq[st.top()]>0){
                visited.erase(st.top());
                st.pop();
            }
            st.push(ch);
            visited.insert(ch);
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};