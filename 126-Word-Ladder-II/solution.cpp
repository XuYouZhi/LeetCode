// 代码一 单队列
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

namespace std{
    template<>
    struct hash<state_t>{
    public:
       size_t operator()(const state_t& s) const{
           return str_hash(s.word);
       } 
    private:
        std::hash<string> str_hash;
    };
};

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        queue<state_t> q;
        unordered_set<state_t> visited;
        
        unordered_map<state_t,vector<state_t>> father;
        
        auto state_is_valid=[&](const state_t& s){
            return wordList.find(s.word)!=wordList.end()||s.word==endWord;
        };
        
        auto state_is_target=[&](const state_t& s){
            return s.word==endWord;
        };
        
        auto state_extend=[&](const state_t& s){
          unordered_set<state_t> result;
          for(size_t i=0;i<s.word.size();++i){
              state_t new_state(s.word,s.level+1);
              for(char c='a';c<='z';++c){
                  if(c==new_state.word[i]) continue;
                  
                  swap(c,new_state.word[i]);
                  
                //   if(state_is_valid(new_state)&&visited.find(new_state)==visited.end()){
                //       result.insert(new_state);
                //   }
                
                  //与word ladder不用的地方，允许一个子节点有多个父节点  hog->hot   dot->hot
                  if(state_is_valid(new_state)){
                      auto visited_iter=visited.find(new_state);
                      if(visited_iter!=visited.end()){
                          if(visited_iter->level==new_state.level){
                              result.insert(new_state);
                          }
                      }
                      else{
                          result.insert(new_state);
                      }
                  }
                      
                  swap(c,new_state.word[i]);
              }
          }
          
          return result;
        };
        
        
        
        
        vector<vector<string>> result;
        state_t start_state(beginWord,0);
        q.push(start_state);
        visited.insert(start_state);
        while(!q.empty()){
            const auto state=q.front();
            q.pop();
            
            if(!result.empty()&&state.level+1>result[0].size()) break; //剪
            
            if(state_is_target(state)){
                vector<string> path;
                gen_path(father,start_state,state,path,result);
                continue;
            }
            
            const auto& new_states=state_extend(state);
            for(const auto& new_state:new_states){
                if(visited.find(new_state)==visited.end()){ //与word ladder不用的地方
                    q.push(new_state);
                }
                visited.insert(new_state);
                father[new_state].push_back(state);
            }
        }
        return result;
    }
    
    
private:
    void gen_path(unordered_map<state_t, vector<state_t>> &father, const state_t &start, const state_t &state, vector<string>& path, vector<vector<string>> &result){
        path.push_back(state.word);
        
        if(state==start){
            if(!result.empty()){
                if(path.size()<result[0].size()){
                    result.clear();
                    result.push_back(path);
                    reverse(result.back().begin(),result.back().end());
                }
                else if(path.size()==result[0].size()){
                    result.push_back(path);
                    reverse(result.back().begin(),result.back().end());
                }
                else{
                    
                }
            }
            else{
                result.push_back(path);
                reverse(result.back().begin(),result.back().end());
            }
        }
        else{
            for(const auto& f:father[state]){
                gen_path(father,start,f,path,result);
            }
        }
        
        path.pop_back();
    }
    
    
};