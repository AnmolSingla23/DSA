class Solution {
public:
    
     int next(int n){   //function to calculate next number
       int newnum = 0; 
       while(n){
           int num = n%10;
           newnum += num*num;
           n = n/10;
       }
       return newnum;
   }
    
    bool isHappy(int n) {
        
        //by using floyds finding cycle
        int slow = n;
        int fast = next(n);  //this finds the next num of n
        // cout<<fast<<endl;
        while(fast != 1 && fast != slow){  //loop breaks if fast reaches 1 or slow and fast are equal
            slow = next(slow);             //this means we are in loop so exit, else we calulate next of
            fast = next(next(fast));   //like floyds we hop twice and slow hops once
            // cout<<fast<<endl;       //slow and next of fast and run throught while loop
        }
        if(fast == 1) return 1;
        else return 0;
    }
};