class Solution {
public:
    int num_digits(long long x){
        if(x < 0) x = -1*x;
        int count = 0;
        while(x){
            count += 1;
            x /= 10;
        }
        return count;
    }
    int reverse(int x) {
        long long tmp = x;
        long long rev = 0; int i = 1;
        int digits = num_digits(tmp);
        bool negative = tmp < 0;
        if(negative) tmp = -1*tmp;
        while(tmp){
            rev += tmp%10 * pow(10, digits-i);
            tmp = tmp/10; i++;
        }
        if(negative) rev = - rev;

        if(rev > INT_MAX || rev < INT_MIN) return 0;
        else return rev;

    }
};
