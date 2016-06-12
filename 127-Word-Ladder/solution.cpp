// 代码一 求最短路径用广搜  单队列 
struct state_t{
    string word;
    int level;
    
    state_t(){word="";level=0;}
    state_t(const string& word, int level){
        this->word=word;
        this->level=level;
    }
    
    bool operator==(const state_t &other) const{
        return this->word==other.word;
    }
};


//模板特化
namespace std{
    template<>
    struct hash<state_t>{
    public:
        size_t operator()(const state_t &s) const{
            return str_hash(s.word);
        }
        
    private:
        std::hash<std::string> str_hash;
    };
}


class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        queue<state_t> q;
        unordered_set<state_t> visited;//判重
        
        auto state_is_valid=[&](const state_t &s){
            return wordList.find(s.word)!=wordList.end()||s.word==endWord;
        };
        
        auto state_is_target=[&](const state_t &s){
            return s.word==endWord;
        };
        
        auto state_extend=[&](const state_t &s){
            unordered_set<state_t> result;
            
            for(size_t i=0;i<s.word.size();++i){
                state_t new_state(s.word,s.level+1);
                for(char c='a';c<='z';++c){
                    if(c==s.word[i]) continue;
                    swap(c,new_state.word[i]);
                    
                    if(state_is_valid(new_state)&&visited.find(new_state)==visited.end()){
                        result.insert(new_state);
                    }
                    
                    swap(c,new_state.word[i]);
                }
            }
            
            return result;
        };
        
        
        state_t start_state(beginWord,0);
        q.push(start_state);
        visited.insert(start_state);
        while(!q.empty()){
            const auto state=q.front();
            q.pop();
            
            if(state_is_target(state)){
                return state.level+1;
            }
            
            const auto& new_states=state_extend(state);
            for(const auto& new_state:new_states){
                q.push(new_state);
                visited.insert(new_state);
            }
        }
        
        return 0;
    }
};