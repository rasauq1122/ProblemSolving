// 2020.07.01

#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int len = s.size(), len2 = t.size();
    stack < pair <char, int> > st;
    st.push({0,0});
    for (int i = 0 ; i < len ; i++) {
        if (s[i] == t[st.top().second]) st.push({s[i],st.top().second+1});
        else if (s[i] == t[0]) st.push({s[i],1});
        else st.push({s[i],0});

        if (st.top().second == len2) for (int j = 0 ; j < len2 ; j++) st.pop();
    }

    string new_s = "";
    stack < char > st2;
    while (st.top().first != 0) {
        st2.push({st.top().first});
        st.pop();
    }
    while (!st2.empty()) {
        new_s += st2.top();
        st2.pop();
    }

    if (new_s.size()) cout << new_s;
    else cout << "FRULA";
}