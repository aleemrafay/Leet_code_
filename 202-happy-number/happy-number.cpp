class Solution {
public:
    bool isHappy(int n) {
        set<int> seen;
        int n1 = n;

        while(n1 != 1 && seen.find(n1) == seen.end())
        {
            seen.insert(n1);
            int num = 0;
            int temp = n1;

            while(temp > 0)
            {
                int digit = temp % 10;
                num = num + (digit * digit);
                temp = temp / 10;
            }

            n1 = num;
        }

        return n1 == 1;
    }
};