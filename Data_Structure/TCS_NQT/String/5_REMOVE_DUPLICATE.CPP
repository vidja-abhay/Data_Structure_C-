#include <bits/stdc++.h>
using namespace std;
// Function to remove vowels from a string
string RemoveVowels(string str)
{
    map<char, bool> visited;
  for (int i = 0; i < str.length(); i++)
  {
    if (!visited[str[i]])
    {
      visited[str[i]] = true;
    }
    
    else{
      str = str.substr(0, i) + str.substr(i + 1);
      i--;
    }
  }
  return str;
}
int main()
{
  string str = "bcabc";
  cout <<"String after removing the vowels \n" <<RemoveVowels(str) << endl;
  return 0;
}