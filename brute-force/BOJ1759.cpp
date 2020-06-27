// 2019.12.27

#include <iostream>
#include <algorithm>
#define and &&
#define or ||
#define not !
using namespace std;

int l, c, ptr[15];
char k[15];

void add()
{
	int chk = 0;
	ptr[l-1]++;
	if (ptr[l-1] == c)
	{
		for (int i = 1 ; i < l ; i++) if (ptr[l-1-i] != c-i-1)
		{
			chk = i;
			break;
		}
		
		ptr[l-1-chk]++;
		for (int i = l-chk ; i < l ; i++) ptr[i] = ptr[i-1] + 1;
	}
}

bool end()
{
	return ptr[0] == c-l;
}

string show()
{
	string s = "";
	for (int i = 0 ; i < l ; i++) s = s + k[ptr[i]];
	return s;
}

bool chk(string s)
{
	int mo = 0, ja = 0, len = s.size();
	for (int i = 0 ; i < len ; i++)
	{
		if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u') mo++;
		else ja++;
	}
	
	return mo >= 1 and ja >= 2;
}

int main()
{
	cin >> l >> c;
	for (int i = 0 ; i < c ; i++) cin >> k[i];
	sort(k, k+c);
	
	for (int i = 0 ; i < l ; i++) ptr[i] = i;
	while (true)
	{
		string s = show();
		if (chk(s)) cout << s << '\n';
		if (end()) break;
		add();
	}
}