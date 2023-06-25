class Solution {
public:
    bool wordPattern(string pattern, string s) {
     
        unordered_map<char,int> mp;  //take two maps for each
        unordered_map<string,int> ms;

        istringstream in(s);  //use isstringstream stl it it used to traverse a string 
        int i=0;
        int n = pattern.size();

        for(string word; in>>word;i++){  //  this is the format for for loop ti use stl
            if(i == n || mp[pattern[i]] != ms[word])  //if i reaches n or words does not exist return false
                return false;

            mp[pattern[i]] = ms[word] = i+1;  //else start givng then numbers from 1 
        }
        return i==n;  //if i reaches the length of pattern the return true;
    }
};