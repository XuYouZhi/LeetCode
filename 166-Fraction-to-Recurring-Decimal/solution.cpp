/*
思路：
     设置一个哈希表，存储每一次的余数，以及该余数在返回结果result中的下标。每一次得到新的余数，就查询该余数是否已经在哈希表中，是的话说明
     开始循环了，那么直接在result中该余数对应的位置后面插入‘（’，result末尾加上‘）’，结束运算。如果在哈希表中没找到，则继续正常运运算。
     
注意：
    1、负数的处理
    2、INT_MIN的处理，将INT_MIN转化为正数会溢出，因此要使用long long int来计算。
    3、分为整数部分和小数部分，重点在于小数部分的处理，因为小数部分有可能会出现循环。
*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        string result;
        
        if(numerator<0^denominator<0) result+='-'; 
        long long int n=numerator, d=denominator;  // INT_MIN转化为正数会溢出，故用long long int
        n=abs(n); d=abs(d);
        
        result+=to_string(n/d); // 整数部分
        long long int r=n%d; // 余数
        if(r==0) return result;
        else result+='.';
        
        //下面处理小数部分，用哈希表 
        unordered_map<int,int> map;
        while(r){
            if(map.find(r)!=map.end()){
                result.insert(map[r],1,'(');
                result+=')';
                break;
            }
            
            map[r]=result.size();
            
            r*=10;
            result+=to_string(r/d);
            r=r%d;
        }
        
        return result;
    }
};