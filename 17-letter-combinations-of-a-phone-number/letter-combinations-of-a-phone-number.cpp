class Solution {
public:
    vector<string>result;
    void backtrack(string &digits,int index,string &current,vector<string>&phone)
    {
        if(index==digits.size())
        {
            result.push_back(current);
            return;
        }
        string letters=phone[digits[index]-'0'];
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
        vector<string>phone={"", "", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};

        
        string current="";
        backtrack(digits,0,current,phone);
        return result;
        
    }
};