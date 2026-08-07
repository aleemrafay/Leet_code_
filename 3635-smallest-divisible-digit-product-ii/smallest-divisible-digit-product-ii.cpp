//aleem_rafay_
class Solution {
    struct Factors {
        int a2 = 0, a3 = 0, a5 = 0, a7 = 0;
    };

    Factors getFactors(long long t) {
        Factors f;
        while (t % 2 == 0) { f.a2++; t /= 2; }
        while (t % 3 == 0) { f.a3++; t /= 3; }
        while (t % 5 == 0) { f.a5++; t /= 5; }
        while (t % 7 == 0) { f.a7++; t /= 7; }
        if (t > 1) return {-1, -1, -1, -1};
        return f;
    }

    int minDigitsNeeded(int a2, int a3, int a5, int a7) {
        a2 = max(0, a2); a3 = max(0, a3);
        a5 = max(0, a5); a7 = max(0, a7);

        int count = a5 + a7 + a3 / 2 + a2 / 3;
        int r3 = a3 % 2, r2 = a2 % 3;

        if (r3 == 0 && r2 == 0) return count;
        if (r3 == 1 && r2 == 1) return count + 1;
        if (r3 == 1 && r2 == 2) return count + 2;
        return count + 1;
    }

    void updateFactors(int d, int& a2, int& a3, int& a5, int& a7, int sign) {
        if (d == 2) a2 += sign * 1;
        else if (d == 3) a3 += sign * 1;
        else if (d == 4) a2 += sign * 2;
        else if (d == 5) a5 += sign * 1;
        else if (d == 6) { a2 += sign * 1; a3 += sign * 1; }
        else if (d == 7) a7 += sign * 1;
        else if (d == 8) a2 += sign * 3;
        else if (d == 9) a3 += sign * 2;
    }

    string buildSmallestSuffix(int a2, int a3, int a5, int a7, int len) {
        string res = "";
        for (int i = 0; i < len; ++i) {
            for (int d = 1; d <= 9; ++d) {
                int n2 = a2, n3 = a3, n5 = a5, n7 = a7;
                updateFactors(d, n2, n3, n5, n7, -1);
                if (minDigitsNeeded(n2, n3, n5, n7) <= len - 1 - i) {
                    res += to_string(d);
                    a2 = n2; a3 = n3; a5 = n5; a7 = n7;
                    break;
                }
            }
        }
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        Factors target = getFactors(t);
        if (target.a2 == -1) return "-1";

        int n = num.length();

        vector<Factors> pref(n + 1);
        int first_zero = -1;

        for (int i = 0; i < n; ++i) {
            if (num[i] == '0' && first_zero == -1) {
                first_zero = i;
            }
            pref[i + 1] = pref[i];
            if (num[i] != '0') {
                updateFactors(num[i] - '0', pref[i + 1].a2, pref[i + 1].a3, 
                              pref[i + 1].a5, pref[i + 1].a7, 1);
            }
        }

        if (first_zero == -1) {
            if (pref[n].a2 >= target.a2 && pref[n].a3 >= target.a3 && 
                pref[n].a5 >= target.a5 && pref[n].a7 >= target.a7) {
                return num;
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            if (first_zero != -1 && i > first_zero) continue;

            int cur2 = target.a2 - pref[i].a2;
            int cur3 = target.a3 - pref[i].a3;
            int cur5 = target.a5 - pref[i].a5;
            int cur7 = target.a7 - pref[i].a7;

            int start_digit = (num[i] - '0') + 1;
            if (i == first_zero) start_digit = 1;

            for (int d = start_digit; d <= 9; ++d) {
                int n2 = cur2, n3 = cur3, n5 = cur5, n7 = cur7;
                updateFactors(d, n2, n3, n5, n7, -1);

                if (minDigitsNeeded(n2, n3, n5, n7) <= n - 1 - i) {
                    string ans = num.substr(0, i);
                    ans += to_string(d);
                    ans += buildSmallestSuffix(n2, n3, n5, n7, n - 1 - i);
                    return ans;
                }
            }
        }

        int req_len = max(n + 1, minDigitsNeeded(target.a2, target.a3, target.a5, target.a7));
        return buildSmallestSuffix(target.a2, target.a3, target.a5, target.a7, req_len);
    }
};