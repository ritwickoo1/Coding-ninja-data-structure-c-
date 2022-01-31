#include <iostream>
#include <string>
using namespace std;

#include<unordered_map>
string uniqueChar(string str) {
	// Write your code here
    unordered_map<char,bool> map;
    string str2 = "";
    for(int i = 0; i < str.size(); i++){
        if(map.count(str[i]) > 0){
            continue;
        }
        map[str[i]] = true;
        str2 += str[i];
    }
    return str2;
}
int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}