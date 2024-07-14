#include <string>
#include <stack>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> stk;
        stk.push(unordered_map<string, int>());
        int n = formula.size();
        for (int i = 0; i < n; ) {
            if (formula[i] == '(') {
                stk.push(unordered_map<string, int>());
                i++;
            } else if (formula[i] == ')') {
                auto top = stk.top();
                stk.pop();
                int i_start = ++i;
                while (i < n && isdigit(formula[i])) i++;
                int multiplier = (i == i_start) ? 1 : stoi(formula.substr(i_start, i - i_start));
                for (auto &p : top) {
                    stk.top()[p.first] += p.second * multiplier;
                }
            } else {
                int i_start = i++;
                while (i < n && islower(formula[i])) i++;
                string atom = formula.substr(i_start, i - i_start);
                i_start = i;
                while (i < n && isdigit(formula[i])) i++;
                int count = (i == i_start) ? 1 : stoi(formula.substr(i_start, i - i_start));
                stk.top()[atom] += count;
            }
        }
        map<string, int> atomCounts;
        for (auto &p : stk.top()) {
            atomCounts[p.first] = p.second;
        }
        string result;
        for (auto &p : atomCounts) {
            result += p.first;
            if (p.second > 1) result += to_string(p.second);
        }
        return result;
    }
};
