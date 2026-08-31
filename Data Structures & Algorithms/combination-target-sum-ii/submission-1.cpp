//Frequency Map

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(
        std::vector<int>& candidates,
        int target
    ) {
        std::map<int, int> frequency;

        for (int num : candidates) {
            ++frequency[num];
        }

        std::vector<std::pair<int, int>> values(
            frequency.begin(),
            frequency.end()
        );

        std::vector<std::vector<int>> result;
        std::vector<int> current;

        backtrack(values, 0, target, current, result);

        return result;
    }

private:
    void backtrack(
        const std::vector<std::pair<int, int>>& values,
        int index,
        int remaining,
        std::vector<int>& current,
        std::vector<std::vector<int>>& result
    ) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }

        if (index == values.size()) {
            return;
        }

        auto [value, count] = values[index];

        // 0 Mal verwenden
        backtrack(
            values,
            index + 1,
            remaining,
            current,
            result
        );

        // 1, 2, ..., count Mal verwenden
        for (int used = 1;
             used <= count && used * value <= remaining;
             ++used) {

            current.push_back(value);

            backtrack(
                values,
                index + 1,
                remaining - used * value,
                current,
                result
            );
        }

        // Backtracking: alle hinzugefügten Werte wieder entfernen
        for (int used = 1;
             used <= count && used * value <= remaining;
             ++used) {
            current.pop_back();
        }
    }
};