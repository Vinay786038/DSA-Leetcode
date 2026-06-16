class Solution {
public:
    vector<string>result;
    void backtrack(string &digits,int index,string &current,unordered_map<char,string>&phone)
    {
        if(index==digits.size())
        {
            result.push_back(current);
            return;
        }
        string letters=phone[digits[index]];
        for(char ch:letters)
        {
            current.push_back(ch);
            backtrack(digits,index+1,current, phone);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if(digits.size()==0)
        {
            return {};
        }
        unordered_map<char,string>phone;
        phone['2']="abc";
        phone['3']="def";
        phone['4']="ghi";
        phone['5']="jkl";
        phone['6']="mno";
        phone['7']="pqrs";
        phone['8']="tuv";
        phone['9']="wxyz";
        
        string current="";
        backtrack(digits,0,current,phone);
        return result;
        
    }
};