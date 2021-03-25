#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        route_.clear();
        trips_.clear();

        for (const auto &pair : tickets)
            trips_[pair.first].push_back(pair.second);

        for (auto &pair : trips_) {
            auto &dests = pair.second;
            sort(dests.begin(), dests.end());
        }

        const string kStart = "JFK";

        visit(kStart);

        return vector<string>(route_.crbegin(), route_.crend());
    }

private:
    // src -> {dst1, dest2, ..., destn}
    unordered_map<string, deque<string>> trips_;
    // ans (reversed)
    vector<string> route_;

    void visit(const string &src) {
        auto &dests = trips_[src];
        while (!dests.empty()) {
            // Get the smallest dest
            const string dest = dests.front();
            // Remove the ticket
            dests.pop_front();
            // Visit dest
            visit(dest);
        }
        // Add current node to the route
        route_.push_back(src);
    }
};
