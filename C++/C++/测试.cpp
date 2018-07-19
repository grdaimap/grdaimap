#include"grd.h"
#include<iostream>
using namespace std;
void sta(grd_map& m) {
	short i = 2;
	while (i != 0)
	{
		m.mapchoose(i);
		cout << "\n1.show map; 2.run map; 0.exit;" << endl;
		cin >> i;
	}
};
int main()
{
	//初始化map
	grd_map mymap(1, 1, 200, 2);
	mymap.reshape(2);
	sta(mymap);
	return 0;
}


