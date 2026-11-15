
class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        string ans = "";

        for(int i = n-1; i >= 0; i--) {
            string temp = "";
            int carry = 0;

            for(int j = m-1; j >= 0; j--) {
                int dig1 = num1[i]-'0';
                int dig2 = num2[j]-'0';

                int res = dig1*dig2 + carry;

                temp += to_string(res%10);
                carry = res/10;
            }

            if(carry > 0) {
                temp += to_string(carry);
            }

            reverse(temp.begin(), temp.end());

            // Shifting
            temp += string(n-1-i, '0');

            // Adding tempstring and  ans
            int p = temp.size()-1;
            int q = ans.size()-1;

            int add_carry = 0;
            string add = "";

            while(p >= 0 || q >= 0 || add_carry > 0) {
                int sum = add_carry;

                if(p >= 0) {
                    sum += temp[p]-'0';
                    p--;
                }

                if(q >= 0) {
                    sum += ans[q]-'0';
                    q--;
                }

                add += to_string(sum%10);
                add_carry = sum/10;
            }

            reverse(add.begin(), add.end());
            ans = add;
        }

        // Removing leading zeros
        int pos = ans.find_first_not_of('0');

        if(pos == string::npos) {
            return "0";
        }

        return ans.substr(pos);
    }
};
