//给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。 
//
// 注意：该题与 1081 https://leetcode-cn.com/problems/smallest-subsequence-of-distinct
//-characters 相同 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "bcabc"
//输出："abc"
// 
//
// 示例 2： 
//
// 
//输入：s = "cbacdcbc"
//输出："acdb" 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 104 
// s 由小写英文字母组成 
// 
// Related Topics 栈 贪心算法 字符串 
// 👍 283 👎 0


#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string removeDuplicateLetters(string s) {

        //采用单调栈方式，用字符串作为栈使用
        //初始化已使用的字符串
        bool visited[26];
        for (int i = 0; i < 26; ++i) {
            visited[i] = false;
        }

        //初始化各个字符串的数量
        char charCount[26];
        for (int i = 0; i < 26; ++i) {
            charCount[i] = 0;
        }

        for (int i = 0; i < s.size(); ++i) {
            charCount[s[i] - 'a']++;
        }

        string str;
        str.clear();

        //进行程序操作
        for (int i = 0; i < s.size(); ++i) {
            if (visited[s[i] - 'a']) {
                charCount[s[i] - 'a']--;
                continue;
            }

            //当字符串不为空，且字符串中最后一个字符大于当前字符，且字符串中最后一个字符还有更多的时候 则弹出最后一个字符
            while ((!str.empty()) && str[str.size() - 1] > s[i] && charCount[str[str.size() - 1] - 'a'] > 0) {
                visited[str[str.size() - 1] - 'a'] = false;
                str.pop_back();
            }

            str.append(1, s[i]);
            charCount[s[i] - 'a']--;
            visited[s[i] - 'a'] = true;
        }
        return str;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;

    const string &basicString = solution.removeDuplicateLetters("bcabc");

    cout << basicString << endl;
}