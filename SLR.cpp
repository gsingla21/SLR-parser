#include<bits/stdc++.h>
using namespace std;

class production
{
	public:
	char left;
	string right;
};

vector<production> get_productions(vector<string> input)
{
	vector<production> pros;
	for(int i=0;i<input.size();i++)
	{
		production p;
		p.left=input[i][0];
		vector<string> rights;
		string s="";
		int flag=0;
		for(int j=1;j<input[i].length();j++)
		{
			if(input[i][j]=='-' and input[i][j+1]=='>')
			{
				j+=1;
				continue;
			}
			if(input[i][j]=='/')
			{
				flag=1;
				rights.push_back(s);
				s.clear();		
				continue;			
			}	
			s+=input[i][j];
		}
		if(flag==1)
		rights.push_back(s);
		for(int j=0;j<rights.size();j++)
		{
			p.right=rights[j];
			pros.push_back(p);
		}
	}
	return pros;
}

vector<char> get_non_terminals(vector<production> pros)
{
	vector<char> nt;
	for(int i=0;i<pros.size();i++)
	{
		for(int j=0;j<pros[i].right.length();j++)
		{
			if(pros[i].right[j]>=65 and pros[i].right[j]<90)
			continue;
			if(find(nt.begin(),nt.end(),pros[i].right[j])==nt.end())
			nt.push_back(pros[i].right[j]);
		}
	}	
	return nt;
}	

vector<char> get_terminals(vector<production> pros)
{
	vector<char> nt;
	for(int i=0;i<pros.size();i++)
	{
		for(int j=0;j<pros[i].right.length();j++)
		{
			if(find(nt.begin(),nt.end(),pros[i].right[j])==nt.end() and (pros[i].right[j]>=65 and pros[i].right[j]<90))
			nt.push_back(pros[i].right[j]);
			else
			continue;
		}
	}	
	return nt;
}	

class firsts
{
	
};

int main()
{
	int n;
	cin>>n;
	vector<string> input;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		input.push_back(s);
	}
	vector<production> pros=get_productions(input);
	
	vector<char> non_terminal=get_non_terminals(pros);	
	
	vector<char> terminal=get_terminals(pros);
	
	
	
	return 0;
}