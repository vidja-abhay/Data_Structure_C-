// SIMPLFY PATH (wrong)

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     cout << "Enter a path : " << endl;
//     string path;
//     getline(cin, path);

//     stack<char> s;

//     s.push(-1);

//     int count = 0;

//     for (auto i : path)
//     {
//         if (i == '/' && s.top() == '/')
//         {
//             // kai nathi karvu loda
//         }

//         else if (i == '.')
//         {
//         }

//         else if (i == '/' && count == path.length() - 1)
//         {
//         }

//         else
//         {
//             s.push(i);
//         }

//         count++;
//     }

//     stack<char> s2;

//     while (s.top() != -1)
//     {
//         s2.push(s.top());
//         s.pop();
//     }

//     while (!s2.empty())
//     {
//         cout << s2.top();
//         s2.pop();
//     }

//     return 0;
// }

// MIN STACK

// #include <bits/stdc++.h>
// using namespace std;

// class Stack1
// {
// public:
//     stack<int> s, min;

//     Stack1(int s)
//     {
//         cout << s;
//     }

//     void push1(int val)
//     {
//         s.push(val);

//         if (min.size() == 0 || min.top() > val)
//         {
//             min.push(val);
//         }
//     }

//     void pop1()
//     {
//         if (min.top() == s.top())
//         {
//             min.pop();
//         }

//         s.pop();
//     }

//     int peek1()
//     {
//         return s.top();
//     }

//     int min1()
//     {
//         return min.top();
//     }
// };

// int main()
// {

//     Stack1 st(5);

//     st.push1(-1);
//     st.push1(2);
//     st.push1(3);
//     st.push1(-2);

//     cout << st.min1() << endl;

//     st.pop1();

//     cout << st.min1();

//     return 0;
// }

// Next Greater Element

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> nextGreaterElement(vector<int> v, int n)
// {
//     stack<int> s;
//     vector<int> ans(n);
//     s.push(-1);

//     for (int i = n - 1; i >= 0; i--)
//     {
//         int cur = v[i];

//         while (s.top() <= cur)
//         {
//             s.pop();

//         }

//         ans[i] = s.top();
//         s.push(cur);
//     }

//     return ans;
// }

// int main()
// {

//     vector<int> v;

//     for (int i = 0; i < 5; i++)
//     {
//         int x;
//         cin >> x;

//         v.push_back(x);
//     }

//     vector<int> a = nextGreaterElement(v, 5);

//     for (auto i : a)
//     {
//         cout << i << " ";
//     }

//     return 0;
// }

// Astroid Collision

// #include <bits/stdc++.h>
// using namespace std;

// int mode(int a)
// {
//     if (a < 0)
//     {
//         return a * -1;
//     }
//     else
//     {
//         return a;
//     }
// }

// int main()
// {

//     vector<int> v = {10, 2, -5};

//     stack<int> s;

//     s.push(v[0]);

//     int count = 0;

//     for (int i = 1; i < v.size(); i++)
//     {

//         if (s.top() * v[i] < 0)
//         {
//             if (mode(s.top()) > mode(v[i]))
//             {
//             }

//             else if (mode(s.top()) == mode(v[i]))
//             {
//                 s.pop();
//             }

//             else
//             {
//                 s.pop();
//                 s.push(v[i]);
//             }
//         }

//         else
//         {
//             s.push(v[i]);
//             count++;
//         }
//     }

//     while (!s.empty())
//     {
//         cout << s.top() << " ";
//         s.pop();
//     }

//     return 0;
// }

// Remove K Digit

// #include <bits/stdc++.h>
// using namespace std;

// int subSequence(string str, string output[])
// {
//     if (str.length() == 0)
//     {
//         output[0] = "";
//         return 1;
//     }

//     int smallerOutputSize = subSequence(str.substr(1), output);

//     for (int i = 0; i < smallerOutputSize; i++)
//     {
//         output[i + smallerOutputSize] = str[0] + output[i];
//     }

//     return 2 * smallerOutputSize;
// }

// int main()
// {
//     string output[1000];

//     string s;
//     cin >> s;

//     int outputSize = subSequence(s, output);

//     vector<int> v;

//     int k;
//     cin >> k;

//     for (int i = 0; i < outputSize; i++)
//     {

//         if (s.length() == k)
//         {
//             v.push_back(0);
//         }

//         else if (output[i].length() == s.length() - k)
//         {
//             v.push_back(stoi(output[i]));
//         }
//     }

//     sort(v.begin(), v.end());

//     string out = to_string(v[0]);

//     cout << out;
//     return 0;
// }

// Base Ball

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     vector<char> v;

//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         char x;
//         cin >> x;

//         v.push_back(x);
//     }

//     stack<int> s;

//     for (int i = 0; i < v.size(); i++)
//     {
//         if (v[i] != 'd' && v[i] != 'c' && v[i] != '+')
//         {
//             int k = v[i] - '0';
//             s.push(k);
//         }

//         else if (v[i] == 'c')
//         {
//             s.pop();
//         }

//         else if (v[i] == 'd')
//         {
//             s.push(s.top() * 2);
//         }

//         else
//         {

//             int x = s.top();
//             s.pop();
//             int y = s.top();
//             s.push(x);
//             s.push(x + y);
//         }
//     }

//     int count = 0;

//     while (!s.empty())
//     {
//         count += s.top();
//         s.pop();
//     }

//     cout << count;
// }

// Valid stack sequence

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     vector<int> push, pop;

//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         push.push_back(x);
//     }

//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         pop.push_back(x);
//     }

//     stack<int> s;
//     int j = 0;

//     for (int i = 0; i < n; i++)
//     {
//         s.push(push[i]);

//         while (s.size() > 0 && s.top() == pop[j])
//         {
//             s.pop();
//             j++;
//         }
//     }

//     if (s.empty())
//     {
//         cout << "True";
//     }

//     else
//     {
//         cout << "False";
//     }

//     return 0;
// }

// Minimum move to make a valid parenthesis

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     string s;
//     getline(cin, s);

//     stack<char> st;

//     for (int i = 0; i < s.length(); i++)
//     {
//         char ch = s[i];

//         if (st.empty())
//         {
//             st.push(ch);
//         }

//         else if (st.top() == '(' && ch == ')')
//         {
//             st.pop();
//         }

//         else if (ch == '(' || ch == ')')
//         {
//             st.push(ch);
//         }
//     }

//     cout << st.size();
//     return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     cout << "Enter Target";
//     int target;
//     cin >> target;

//     cout << "Enter a size of a vector";
//     int n;
//     cin >> n;

//     cout << "Enter a position vector";
//     vector<int> p;

//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         p.push_back(x);
//     }

//     cout << "Enter a speed vector";
//     vector<int> s;

//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         s.push_back(x);
//     }

//     vector<vector<int>> vec(n, vector<int>(2));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < 2; j++)
//         {
//             if (j == 0)
//             {
//                 vec[i][j] = p[i];
//             }

//             else
//             {
//                 vec[i][j] = s[i];
//             }
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < 2; j++)
//         {
//             cout << vec[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string s = to_string(n);

    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }

    string word = "";

    while (!st.empty())
    {
        word += st.top();
        st.pop();
    }

    int x;

    if (word[word.length() - 1] == '-')
    {
        x = stoi(word) * -1;
    }

    else
    {
        x = stoi(word);
    }

    cout << x;
}