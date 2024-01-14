#include <bits/stdc++.h>

using namespace std;

class Trie {
private:
    bool isEnd;  // 단어의 끝인지 여부
    unordered_map<char, Trie*> child; // 자식 링크들을 담은 해시 맵  Key : 자식 문자(다음 글자)  Value : 자식 객체 주소
public:
    /* 트라이 만들기 */
    void Insert(string str) {
        Trie* now = this;
        for (int i = 0; i < str.length(); ++i) {
            if (now->child[str[i]] == nullptr)
                now->child[str[i]] = new Trie();
            now = now->child[str[i]];
            
            if (i == str.length() - 1)
                now->isEnd = true;
        }
    }
    /* 버튼 직접 수동으로 눌러야 하는 개수 */
    int AutoComplete(string str) {
        int count = 1; // 모든 첫 문자들은 무조건 입력해야하니.. 1 에서 시작
        Trie* now = child[str[0]]; // 루트 말고 첫 문자에서 시작하기
        for (int i = 1; i < str.length(); ++i) { 
            if (now->isEnd || now->child.size() > 1) // 현재 문자가 끝이거나 혹은 현재 문자의 자식 문자 개수가 2 이상이라면 수동으로 입력해야 한다. count += 1
                count++;
            now = now->child[str[i]]; // 다음 자식으로 타고 내려가기
        }
        return count; 
    }

public:
};

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin >> n) {  // 원하는 만큼 입력 받기!! 
        vector<string> words(n);
        for (int i = 0; i < n; ++i)
            cin >> words[i];
        
        // 트라이 만들기
        Trie* root = new Trie();
        for (int i = 0; i < n; ++i)
            root->Insert(words[i]);

        // 모든 입력 횟수 합
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += root->AutoComplete(words[i]);
        
        double result = (double)sum / words.size();
        cout << fixed << setprecision(2) << result << '\n'; // 출력 정밀도 2 자리로 설정
    }
}