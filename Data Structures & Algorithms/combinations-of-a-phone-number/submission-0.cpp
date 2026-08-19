class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> out;
        if (digits.empty()) return out;

        // Seu mapeamento indexado pelo próprio número (índice 2 = 'a','b','c', etc.)
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        string path = "";
        dfs(digits, 0, mapping, path, out);
        return out;
    }

    void dfs(const string& digits, int index, const vector<string>& mapping, string& path, vector<string>& out) {
        // Caso base: preencheu todas as posições
        if (path.size() == digits.size()) {
            out.push_back(path);
            return;
        }

        // Converte o char atual (ex: '2') para o int correspondente (2) para usar no mapeamento
        int digit = digits[index] - '0';
        string letters = mapping[digit];

        for (int k = 0; k < letters.size(); k++) {
            path.push_back(letters[k]);           // Escolhe a letra
            dfs(digits, index + 1, mapping, path, out); // Passa para o próximo dígito
            path.pop_back();                      // Desfaz a escolha
        }
    }
};