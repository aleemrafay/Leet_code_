//  aleem rafay
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        for (const auto& inv : invocations) {
            graph[inv[0]].push_back(inv[1]);
        }

        unordered_set<int> suspicious;
        queue<int> q;

        q.push(k);
        suspicious.insert(k);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : graph[curr]) {
                if (suspicious.find(neighbor) == suspicious.end()) {
                    suspicious.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];

            if (suspicious.find(u) == suspicious.end() && suspicious.find(v) != suspicious.end()) {
                vector<int> all_methods(n);
                for (int i = 0; i < n; ++i) {
                    all_methods[i] = i;
                }
                return all_methods;
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (suspicious.find(i) == suspicious.end()) {
                result.push_back(i);
            }
        }

        return result;
    }
};