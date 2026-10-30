class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        for (int i = 1; i < asteroids.size(); i++) {
            if (asteroids[i] < 0) {
                int tocheck = asteroids[i];
                int j = i - 1;
                while (j >= 0 && tocheck < 0 && asteroids[j] >= 0) {
                    if (asteroids[j] == 0) {
                        j--;
                        continue;
                    }

                    if (abs(tocheck) > asteroids[j]) {
                        asteroids[j] = 0;
                        j--;
                    }

                    else if (abs(tocheck) == asteroids[j]) {
                        asteroids[i] = 0;
                        asteroids[j] = 0;
                        break;
                    } else {
                        tocheck = asteroids[j];
                        asteroids[i] = 0;
                        break;
                    }
                }
            }
        }
        vector<int> ans;
        for (int iter : asteroids) {
            if (iter != 0) {
                ans.push_back(iter);
            }
        }
        return ans;
    }
};