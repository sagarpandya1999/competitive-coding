#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;
int main()
{
	
	int n;
	double r;
	scanf("%d %lf", &n, &r);
	int x[n];
	map<int, int> xval;
	for(int i=0; i<n; i++)
	{	scanf("%d",&x[i]);
	}
	double y[n];
	y[0]= r;
	xval[x[0]] = 0;//index.
	for(int i=1; i<n; i++)
	{	y[i]= r;
	    for(double j=x[i]; j>=x[i]-(2*r)-EPS; j--)
		{	auto iter =xval.find(j);
			if(iter!=xval.end())
			{	int index = iter->second;  
			    int xmin = iter->first; 
			    y[i] = max(y[i], y[index] + sqrt(4*r*r - (xmin - x[i])*(xmin-x[i])));
			}
		}
		for(double j=x[i]+1; j<=x[i]+(2*r)+EPS; j++)
		{	auto iter =xval.find(j);
			if(iter!=xval.end())
			{   int index = iter->second;  
			    int xmin = iter->first; 
			    y[i] = max(y[i], y[index] + sqrt(4*r*r - (iter->first - x[i])*(xmin-x[i])));
			}
		}
		xval[x[i]] = i;
	}
	for(int i=0; i<n; i++)
		printf("%.10lf ", y[i]);
}
