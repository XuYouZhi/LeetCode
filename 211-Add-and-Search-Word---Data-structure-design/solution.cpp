class WordDictionary {
public:
    
    class TrieNode{
    public:
        TrieNode* child[26];
        bool isWord;
        
        TrieNode(){
            isWord=false;
            for(auto &a:child) a=nullptr;
        }
    };
    
    
    WordDictionary(){
        root=new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *p=root;
        for(auto c:word){
            int i=c-'a';
            if(!p->child[i]) p->child[i]=new TrieNode();
            p=p->child[i];
        }
        p->isWord=true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchWord(word,root,0);
    }
    
    bool searchWord(string word, TrieNode *p, int i){
        if(i==word.length()) return p->isWord;
        if(word[i]=='.'){
            for(auto c:p->child){
                if(c&&searchWord(word,c,i+1)) return true;
            }
            return false;
        }
        else{
            return p->child[word[i]-'a']&&searchWord(word, p->child[word[i]-'a'], i+1);
        }
    }
    
private:
    TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");