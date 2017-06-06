#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	vector<string> a = { "a", "b", "c" };
	for (auto temp : a){
		cout << temp << endl;
	}
	system("pause");
}