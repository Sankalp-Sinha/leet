class Solution {
public:

    long long int gcd (long long int a, long long int b){
        return b==0? a : gcd(b, a%b);
    }

    long long int lcm(long long int a, long long int b){
        return (a / gcd(a,b)) * b;
    }

    long long int count(long long int mid, int a, int b, int c){
        long long int ab = lcm(a,b);
        long long int bc = lcm(b,c);
        long long int ac = lcm(a,c);
        long long int abc = lcm(a,lcm(b,c));
        return mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ac + mid/abc;
    }


    int nthUglyNumber(int n, int a, int b, int c) {
        long long int left = 1;
        long long int right = 2 * 1e9;
        while(left<right){
            long long int mid = left + (right - left) / 2;
            if(count(mid, a, b, c) < n){
                left = mid + 1;
            }
            else right = mid; 
        }
        return left;
    }
};