#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <algorithm>
#include <numeric>

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
//demo_9_34
void erase_elem(vector<int> vc){
	cout << "//demo_9_34" << endl;
	auto iter = vc.begin();
	while (iter != vc.end())
	{
	
		if (*iter % 2){
			cout << "*iter" << *iter << endl;
			iter = vc.insert(iter, *iter);
		
		}
		else{
			cout << "nothing" << endl;
		}
		++iter;
	}
	for (auto tmp : vc){
		cout << tmp << endl;
	}
}

//vector's size capacity and reserve
void vectorSize(){
	vector<int> a;
	cout << "a.size " << a.size() << endl;
	cout << "a.capacity " << a.capacity() << endl;
	
	for (int i = 0; i < 25; i++){
		a.push_back(10);
	}
	cout << "a.size " << a.size() << endl;
	cout << "a.capacity " << a.capacity() << endl;

	a.reserve(50);
	cout << "a.size " << a.size() << endl;
	cout << "a.capacity " << a.capacity() << endl;


	while (a.size() != a.capacity()){
		a.push_back(10);
	}
	cout << "a.size " << a.size() << endl;
	cout << "a.capacity " << a.capacity() << endl;

	a.push_back(10);
	cout << "a.size " << a.size() << endl;
	cout << "a.capacity " << a.capacity() << endl;
}

//string constructor
void noNull(){
	const char*cp = "hello World!";
	char cp2[] = { 'H', 'e', 'l' };
	vector<char> vc = { 'H', 'e', 'l' };

	string a1(cp);
	string a2(cp, 4);
	string a3(cp, 4, 3);
	string a4(cp2);
	string a5(cp2, 111);
	string a6(vc.cbegin(), vc.cend());
	cout << "a is " << a1 << endl;
	cout << a2 << endl;
	cout << a3 << endl;
	cout << a4 << endl;
	cout << a5 << endl;
	cout << a6 << endl;

	a6.append("123").append("456").append("456").append("456").append("456");
	cout << a6 << endl;
}

//replace long string with short string
void replaceStr(string s, string oldVal, string newVal){
	
	auto pos = s.find(oldVal);
	cout << "old s is" << s << endl;
	while (pos <= s.size())
	{
		s.erase(pos, oldVal.size());
		s.insert(pos, newVal);
		pos = s.find(oldVal);
	}
	cout << "new s is " << s << endl;
}
void replaceStr(string s, string oldVal, string newVal){
	7h
}
int main(){
	list<string> lst;
	deque<string> dq;
	vector<string> vc = {"1","2","3","333","ddd","ddas"};
	vector<int> i_vc = {  2, 3, 4, 5, 6, 7, 8 };
	forward_list<string> fl;

	//erase_elem(vc);
	//demo_9_26();

	//finda();

	//cout << "insert RTN" << endl;
	//insertRtn();

	//vectorSize();
	//noNull();

	string s = "feijichangfeijichangfeijichangfeiji";
	replaceStr(s, "fei", "ji");

	system("pause");
}