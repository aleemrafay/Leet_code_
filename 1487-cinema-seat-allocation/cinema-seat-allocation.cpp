//aleem_rafay
class Solution {
public:
    int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats) {
        std::unordered_map<int, int> reserved;
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            reserved[row] |= (1 << col);
        }

        int maxFamilies = n * 2;

        int leftMask   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int rightMask  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9); 
        int middleMask = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7); 
        for (const auto& [row, mask] : reserved) {
            bool leftFree   = (mask & leftMask) == 0;
            bool rightFree  = (mask & rightMask) == 0;
            bool middleFree = (mask & middleMask) == 0;

            if (leftFree && rightFree) {
                continue;
            } else if (leftFree || rightFree || middleFree) {
                maxFamilies -= 1;
            } else {
                maxFamilies -= 2;
            }
        }

        return maxFamilies;
    }
};