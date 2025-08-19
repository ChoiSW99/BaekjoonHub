#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;


// 암호 만들기, L개의 서로 다른 알파벳 소문자로 구성
// 최소 1개의 모음과 최소 2개의 자음으로 구성됨
// 암호 알파벳은 오름차순 정렬

// 사용한 문자 C 개

int L; // 서로 다른 L개의 소문자로 암호 구성
int C; // 암호 후보 문자 종류 C가지

bool Comp(char& c1, char& c2)
{ 
    return c1 < c2; // 오름차순
} 

void Solv(string str, vector<char>& alphabets, int lastIdx)
{
    // base case) L자릿수 다 뽑음!
    int l = str.size();
    if (l == L)
    {
        int aeiouCnt = 0; //모음 숫자
        for (char c : str)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                ++aeiouCnt;
        }
        if(aeiouCnt >= 1 && l - aeiouCnt >= 2)
            cout << str << "\n";
        return;
    }
    
    //int leftAlphabetCnt = (C - (lastIdx+1));
    
    //if ((l + leftAlphabetCnt) < C) 
    //    return;
    
    for (int i=lastIdx+1; i<C; ++i)
    {
        Solv(str + alphabets[i], alphabets, i);
    }
}

int main()
{
    cin >> L >> C; // C개의 알파벳 사용 -> L 자리수 암호 만듦.
    vector<char> alphabets(C);
    
    for (int c=0; c<C; ++c)
        cin >> alphabets[c];
        
    // 오름차순 정렬
    sort(alphabets.begin(), alphabets.end(), Comp);
    
    Solv("", alphabets, -1);
    return 0;
}