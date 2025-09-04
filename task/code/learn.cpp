#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
/**/
int main()
{
    vector <int> s(10);
 for(int i=0;i<10;i++)
 {
    s[i]=i;
 }
 sort(s.begin(),s.end(),[](int a, int b){return a > b;});
 for(auto p=s.begin();p!=s.end();p++)
 {
    cout<< *p<<" ";
 }
}