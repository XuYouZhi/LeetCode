class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        const int n=words.size();
        if(n<1) return vector<string>(1,"");
        
        vector<string> result;
        
        vector<int> word_lens(n);
        for(int i=0;i<n;++i){
            word_lens[i]=words[i].length();
            if(word_lens[i]>maxWidth) return vector<string>(1,"");
        }
        
        int start=0;
        int length=0;
        for(int i=0;i<n;++i){
            if(length+word_lens[i]+(i-start)>maxWidth){
                
                fullJustify(words,word_lens,maxWidth-length,start,i,result);
                
                start=i;
                length=0;
            }
            length+=word_lens[i];
        }
        
        fullJustify(words,word_lens,maxWidth-length,start,n,result);
        
        return result;
    }
    
    
    void fullJustify(const vector<string>& words, const vector<int>& word_lens,int space_len, int start, int end, vector<string>& result){
        string str="";
        int space_count=end-start-1;
        
        if(end!=words.size()){
            for(int i=start;i<end;++i){
                str+=words[i];
                if(space_count==0){
                    str.append(space_len,' ');
                    break;
                }
                int space=ceil((space_len)/float(space_count));
                str.append(space,' ');
                space_len-=space;
                --space_count;
            }
        }
        else{
            for(int i=start;i<end-1;++i){
                str+=words[i];
                str.append(1,' ');
                --space_len;
            }
            str+=words[end-1];
            str.append(space_len,' ');
        }
        
        result.push_back(str);
    }
};