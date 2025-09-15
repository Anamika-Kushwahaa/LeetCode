// Given an integer x, return true if x is a palindrome, and false otherwise.

// Example 1:
// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

// Constraints:

// -231 <= x <= 231 - 1

// CODE:-
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10 == 0 && x != 0 ))
        return false;

        long long rev=0;       // yaha pe int rev krne pe integer overflow aaega jisko avoid krne ke liye long long use kiye h
        int orignal = x;      //for final comparison
        while(x>0){
            int dig = x%10 ;
            rev= rev * 10 + dig ; 
            x /= 10;
        }
        return orignal == rev;
    }
};
