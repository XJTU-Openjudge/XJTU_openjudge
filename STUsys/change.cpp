#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	string a;
	string res;
	int cnt=0;
	ifstream in("Student.list");
	ofstream ou("STU.list");
	while (in.peek()!=EOF)
		a+=in.get();
	for (int i=0; i<a.size(); i++)
	{
		if ((a[i]>='0' && a[i]<='9')||(a[i]=='\n'))
			res+=a[i];
		else 
		{
			cout <<a[i];
			cnt++;
		}
	}
	cout <<cnt;
	ou <<res;
	return 0;
}
