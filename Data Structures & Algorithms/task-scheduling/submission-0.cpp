#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char t : tasks) {
            freq[t - 'A']++;
        }

        priority_queue<int> heap;
        for (int f : freq) {
            if (f > 0) heap.push(f);
        }

        // Fila guarda pares: {frequência restante, momento em que volta a ficar disponível}
        queue<pair<int, int>> cooldown;
        int cont = 0;

        while (!heap.empty() || !cooldown.empty()) {
            cont++;

            if (!heap.empty()) {
                int curr_freq = heap.top();
                heap.pop();
                if (curr_freq - 1 > 0) {
                    cooldown.push({curr_freq - 1, cont + n});
                }
            }

            // Libera tarefas cujo tempo de cooldown já passou
            if (!cooldown.empty() && cooldown.front().second == cont) {
                heap.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return cont;
    }
};