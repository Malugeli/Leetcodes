class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::array<int, 26> frequency{};

        for (char task : tasks) {
            ++frequency[task - 'A'];
        }

        using Task = std::pair<int, char>;

        std::priority_queue<Task> available;

        for (int i = 0; i < 26; ++i) {
            if (frequency[i] > 0) {
                available.push({
                    frequency[i],
                    static_cast<char>('A' + i)
                });
            }
        }

        struct CooldownTask {
            int readyTime;
            int remaining;
            char task;
        };

        std::queue<CooldownTask> cooldown;

        int time = 1;

        while (!available.empty() || !cooldown.empty()) {

            // Tasks deren Cooldown vorbei ist,
            // werden wieder verfügbar.
            while (!cooldown.empty() &&
                   cooldown.front().readyTime <= time) {

                auto task = cooldown.front();
                cooldown.pop();

                available.push({
                    task.remaining,
                    task.task
                });
            }

            if (!available.empty()) {
                auto [remaining, task] = available.top();
                available.pop();

                --remaining;

                if (remaining > 0) {
                    cooldown.push({
                        time + n + 1,
                        remaining,
                        task
                    });
                }
            }

            ++time;
        }

        return time - 1;
    }
};