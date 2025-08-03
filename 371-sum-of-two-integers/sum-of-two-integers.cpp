class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int ans = 0;
        for(int i=0; i<32; i++){
            if(a&(1<<i) && b&(1<<i) && carry==0){
                carry = 1;
            }
            else if(a&(1<<i) && b&(1<<i) && carry==1){
                ans = ans | (1<<i);
                carry = 1;
            }
            else if(a&(1<<i) && (b&(1<<i))==0 && carry==0){
                ans = ans | (1<<i);
                carry = 0;
            }
            else if((a&(1<<i))==0 && b&(1<<i) && carry==0){
                ans = ans | (1<<i);
                carry = 0;
            }
            else if((a&(1<<i))==0 && b&(1<<i) && carry==1){
                // ans = ans | (1<<i);
                carry = 1;
            }
            else if(a&(1<<i) && (b&(1<<i))==0 && carry==1){
                // ans = ans | (1<<i);
                carry = 1;
            }
            else if((a&(1<<i))==0 && (b&(1<<i))==0 && carry==1){
                ans = ans | (1<<i);
                carry = 0;
            }
        }
        return ans;
    }
};