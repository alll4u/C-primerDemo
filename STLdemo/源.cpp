#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
using namespace std;

//insert returnation to insert times
void insertRtn(){
	list<string> lst;
	string word;
	auto iter = lst.begin();
	while (cin >> word && word != "#"){
		iter = lst.insert(iter, word);
		cout << *iter << endl;
	}
	for (auto tmp : lst){
		cout << tmp << endl;
	}
}
void finda(){
	vector<string> vc = { "1", "2", "3", "4", "5", "6", "7" };
	cout << "vc.back():" << vc.back() << endl;
	cout << "vc.front():" << vc.front() << endl;
	cout << "vc[0]:" << vc[0] << endl;
	cout << "vc.at(0):" << vc.at(0) << endl;
	cout << "vc.*begin():" << *(vc.begin()) << endl;

	for (auto tmp : vc){
		cout << tmp << endl;
	}
	for (auto begin = vc.begin(); begin != vc.end()-1; ){
		begin = vc.erase(begin);
	}
	cout << "after erase " << endl;
	for (auto tmp : vc){
		cout << tmp << endl;
	}
	/*if (!vc.empty()){
		auto val = *vc.begin(), val2 = vc.front();
		auto last = vc.end();
		auto val3 = *(--last);
		auto val4 = vc.back();
		cout << "val:" << val << endl;
		cout << "val1:" << val2 << endl;
		cout << "val2:" << val3 << endl;
		cout << "val3:" << val4 << endl;
	}*/

	
}

//erase
void erase_elem(vector<string> vc){
	cout << "erase elems demo" << endl;
	for (auto tmp : vc){
		cout << tmp << endl;
	}
	auto elem1 = vc.begin(), elem2 = vc.end();
	vc.erase(elem1, elem1);
	cout << "after erasing" << endl;
	for (auto tmp : vc){
		cout << tmp << endl;
	}
}


void demo_9_26(){
	cout << "demo_9_26()" << endl;
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	vector<int> vc, vc2;
	list<int> lst, lst2;

	//eg 1
	/*vc.resize(11);
	memcpy(&vc[0], ia, 11 * sizeof(int));*/


	//eg2
	vc.assign(&ia[0], &ia[11]);
	vc2.assign(&ia[0], &ia[11]);
	lst.assign(&ia[0], &ia[11]);
	lst2.assign(&ia[0], &ia[11]);
	//erase odd in vc
	cout << "erase odd in vc" << endl;
	for (auto iter1 = vc.begin(); iter1 != vc.end();){
		if (*iter1 % 2){
			iter1 = vc.erase(iter1);
		}
		else{
			iter1++;
		}
	}
	for (auto tmp : vc){
		cout << tmp << endl;
	}

	//erase even in lst
	cout << "erase even in lst" << endl;
	for (auto iter1 = lst.begin(); iter1 != lst.end();){
		if (*iter1 % 2 == 0){
			iter1 = lst.erase(iter1);
		}
		else{
			iter1++;
		}
	}
	for (auto tmp : lst){
		cout << tmp << endl;
	}

	//erase odd, copy even in vc2
	cout << "erase odd, copy even in vc2" << endl;
	for (auto iter1 = vc2.begin(); iter1 != vc2.end();){
		if (*iter1 % 2){
			iter1 = vc2.erase(iter1);
		}
		else{
			iter1 = vc2.insert(iter1, *iter1++);
			//iter1+=2;
		}
	}
	for (auto tmp : vc2){
		cout << tmp << endl;
	}

	//demo_9_31 erase odd, copy even in lst2
	cout << "erase odd, copy even in vc2" << endl;
	for (auto iter1 = lst2.begin(); iter1 != lst2.end();){
		if (*iter1 % 2){
			iter1 = lst2.erase(iter1);
		}
		else{
			iter1 = lst2.insert(iter1, *iter1);
			iter1++;
			iter1++;
		}
	}
	for (auto tmp : lst2){
		cout << tmp << endl;
	}


}

int main(){
	list<string> lst;
	deque<string> dq;
	vector<string> vc = {"1","2","3","333","ddd","ddas"};
	forward_list<string> fl;

	vc.emplace_back("a");
	for (auto tmp : vc){
		cout << tmp << endl;
	}

	auto v = vc.front();
	v = "b";
	cout << vc[0] << endl;
	auto &v2 = vc.front();
	v2 = "c";
	cout << vc[0] << endl;

	vector<string>::iterator rtn = vc.begin();
	if (rtn == vc.end()){
		cout << "end" << endl;
	}
	else{
		cout << "not end" << endl;
	}
	rtn = vc.erase(vc.begin());
	if (rtn == vc.end()){
		cout << "end" << endl;
	}
	else{
		cout << "not end" << endl;
	}

	erase_elem(vc);
	demo_9_26();

	//finda();

	//cout << "insert RTN" << endl;
	//insertRtn();

	system("pause");
}