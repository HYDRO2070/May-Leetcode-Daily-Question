class Solution {
public:
    string pushDominoes(string d) {
        int n = d.size();
        vector<int> empty;
        vector<bool> processed(
            n, false); // Tracks which empty indices have been processed
        vector<pair<int, char>> to_do;

        // Step 1: Collect all empty positions ('.')
        for (int i = 0; i < n; ++i) {
            if (d[i] == '.') {
                empty.push_back(i);
            }
        }

        // Step 2: Initial processing of immediate pushes
        for (int i : empty) {
            if (i == 0 && i + 1 < n && d[i + 1] == 'L') {
                to_do.push_back(make_pair(i, 'L'));
                processed[i] = true;
            } else if (i == n - 1 && i - 1 >= 0 && d[i - 1] == 'R') {
                to_do.push_back(make_pair(i, 'R'));
                processed[i] = true;
            } else if (i > 0 && i < n - 1) {
                if (d[i - 1] == 'R' && d[i + 1] == 'L') {
                    continue; // Balanced, stays as '.'
                } else if (d[i - 1] == 'R') {
                    to_do.push_back(make_pair(i, 'R'));
                    processed[i] = true;
                } else if (d[i + 1] == 'L') {
                    to_do.push_back(make_pair(i, 'L'));
                    processed[i] = true;
                }
            }
        }

        // Step 3: Simulation loop
        while (!to_do.empty()) {
            vector<pair<int, char>> next_round;

            // Apply the forces
            for (auto [i, ch] : to_do) {
                d[i] = ch;
            }

            // Try to influence remaining unprocessed positions
            for (int i : empty) {
                if (processed[i])
                    continue;

                if (i == 0 && i + 1 < n && d[i + 1] == 'L') {
                    next_round.push_back(make_pair(i, 'L'));
                    processed[i] = true;
                } else if (i == n - 1 && i - 1 >= 0 && d[i - 1] == 'R') {
                    next_round.push_back(make_pair(i, 'R'));
                    processed[i] = true;
                } else if (i > 0 && i < n - 1) {
                    if (d[i - 1] == 'R' && d[i + 1] == 'L') {
                        continue; // Balanced
                    } else if (d[i - 1] == 'R') {
                        next_round.push_back(make_pair(i, 'R'));
                        processed[i] = true;
                    } else if (d[i + 1] == 'L') {
                        next_round.push_back(make_pair(i, 'L'));
                        processed[i] = true;
                    }
                }
            }

            to_do = move(next_round);
        }

        return d;
    }
};
