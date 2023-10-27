class Solution {
public:

    bool ispalindrome(int start,int end,string &s){  //simple function to check if string
        
        while(start < end){   //is palindrome or not
            if(s[start] != s[end])
                return false;
            else{
                start++;
                end--;
            }
        }
        return true;
    }

    string longestPalindrome(string s) {
        
        string ans;

        for(int i=0;i<s.size();i++){  //chk for each possiblity
            for(int j=i;j<s.size();j++){
                if(ispalindrome(i,j,s)){  //if is palindrome store it in temp string
                    string temp = s.substr(i,j-i+1);  //if size of temp is greater then 
                    if(temp.size() > ans.size())  //the prev substring then change it 
                        ans = temp;   //to the longest
                }
            }
        }
        return ans;
    }
};