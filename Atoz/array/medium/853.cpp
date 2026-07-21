// https://leetcode.com/problems/car-fleet/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;

        for (int i =0; i < position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), greater<pair<int, int>>());

        int fleets = 0;
        double lastTime = 0.0;

        for (auto &car : cars) {
            double time = (double)(target - car.first) / car.second;

            if (time > lastTime) {
                fleets++;
                lastTime = time;
            }
        }
        return fleets;
    }
};