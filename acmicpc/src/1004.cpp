#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct circle
{
	int x,y;
	int r;
};

bool cmp_circle(circle &first,circle &second) {return first.r<second.r;}
int square(int x);

class dot
{
public:
	int x,y;
	vector<int> including_idx;
	dot()
	{
		cin >> this->x >> this->y;
	}
	bool is_contained(circle &c)
	{
		return (square(c.x-this->x)+square(c.y-this->y)<square(c.r));
	}
};

int square(int x)
{
	return x*x;
}



int t;

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		dot s,d;
		int p;
		circle c[50];
		cin >> p;
		for(int j = 0; j < p; j++) cin >> c[j].x >> c[j].y >> c[j].r;
		sort(c,c+p,cmp_circle);
		for(int j=0;j<p;j++)
		{
			if(s.is_contained(c[j]))
				s.including_idx.push_back(j);
			if(d.is_contained(c[j]))
				d.including_idx.push_back(j);
		}
		if(!(s.including_idx.empty() || d.including_idx.empty()))
		{
			while(s.including_idx.back()==d.including_idx.back())
			{
				s.including_idx.pop_back();
				d.including_idx.pop_back();
				if(s.including_idx.empty() || d.including_idx.empty())
					break;
			}
		}
		cout << s.including_idx.size()+d.including_idx.size()<<endl;

	}
	return 0;
}
