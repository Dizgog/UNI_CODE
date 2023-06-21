#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <string.h>
#include <vector>


// other includes and definitions

/* YOUR CODE HERE */

using namespace std;
#include "Hybrid.h"
template <class T>
void mySort(vector<T> &v){
	hybridSort(v, 0, v.size() - 1);
}



/* DO NOT MODIFY CODE BELOW */

int main(){	
	int x = -1;
	while(1){
		cin >> x;
		if (x == 0){
			break;
		} else {
			int n;
			cin >> n;			
			
			switch(x){
				case 1:	{
					cout << endl;
					vector <int> v1;
					for (int i = 0; i < n; ++i){
						int y1;
						cin >> y1;
						v1.push_back(y1);
					}
					mySort<int>(v1);
					cout << endl;						
					for (int i = 0; i < n; ++i){
						cout << v1[i] << endl;
					}
					cout << endl;
					break;
				}
				case 2:	{
					std::cout << std::endl;
					vector <string> v2;
					for (int i = 0; i < n; ++i){
						string y2;
						cin >> y2;
						v2.push_back(y2);
					}					
					mySort<string>(v2);					
					for (int i = 0; i < n; ++i){
						cout << v2[i] << endl;
					}
					std::cout << std::endl;
					break;
				}
			}	
			//cout << endl;	
		}
	}
	return 0;	
}
