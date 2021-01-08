#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

double r=0;
double tot=0;
void creatstring(string &a, string &b)
{
	ifstream ina("/root/OpenJudge/Check/answer");
	while (ina.peek()!=EOF)
		a+=ina.get();
	ifstream inb("/root/OpenJudge/Check/stdans");
	while (inb.peek()!=EOF)
		b+=inb.get();
}

void creatstr(string &ans, string &standard, string &no_ans, string &no_standard)
{
    for (int i=0; i<ans.size(); i++)
    {
        if (ans[i] == ' ' || ans[i] == '\n' || ans[i] == '\r')  continue;
        no_ans += ans[i];
    }
    for (int i=0; i<standard.size(); i++)
	{
        if (standard[i] == ' ' || standard[i] == '\n' || standard[i] == '\r')  continue;
        no_standard += standard[i];
    }
}

void oj(string &ans, string &standard, string &no_ans, string &no_standard)
{
	tot++;
    if (no_standard != no_ans)
        cout <<"Wrong answer";
    else if (ans!=standard)
        cout <<"Form Error";
    else
	{
		r++;
		cout <<"Accepted!";
	}	//AC
    cout <<endl;
}

int main()
{
	string ans, standard, no_ans, no_standard;
   	creatstring(ans, standard); 
    int i = 1;
    string head, next_head, counts;
	do 
	{
		no_ans.clear(), no_standard.clear();
		stringstream temp;
		temp <<i;
        string tail;
	    temp >>tail;
        head = "answer" + tail + ":";
        counts = "test" + tail + ":";
	    i++;    temp.clear();
        temp <<i;
		temp >>tail;
        next_head="answer" + tail + ":";
        int p=ans.find(head)+head.size(), q=standard.find(head)+head.size();
		int	pend=ans.find(next_head), qend=standard.find(next_head);
		if (pend==ans.npos || qend==standard.npos)
        {
	        string a(ans, p), s(standard, q);
            creatstr(a, s, no_ans, no_standard);
            cout <<counts;
            oj(a, s, no_ans, no_standard);
        }
        else
		{
			string a(ans, p, pend-p), s(standard, q, qend-q);
            creatstr(a, s, no_ans, no_standard);
            cout <<counts;
            oj(a, s, no_ans, no_standard);
        }
	} while (standard.find(next_head)!=standard.npos && ans.find(next_head)!=ans.npos);
	double res=(double)(r/tot)*100;
	cout <<setiosflags(ios::fixed) <<setprecision(1);
	cout <<"Total Score:" <<res <<"/100" <<endl;
	return 0;
}
