class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(int i=0;i<tokens.size();++i){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int a=std::stoi(s.top());
                s.pop();
                int b=std::stoi(s.top());
                s.pop();
                int c;
                if(tokens[i]=="+"){
                    c=b+a;
                }
                else if(tokens[i]=="-"){
                    c=b-a;
                }
                else if(tokens[i]=="*"){
                    c=b*a;
                }
                else{
                    c=b/a;
                }
                s.push(to_string(c));
            }
            else{
                s.push(tokens[i]);
            }
        }
        
        return std::stoi(s.top());
    }
};