#include<bits/stdc++.h>
using namespace std;
#define N 10
char grid[N][N];
// check horizontally
bool isValidHorizontal(int row,int col,string word){
	if(10-col < word.size()){
		return false;
	}
	for(int i = 0, j = col; i < word.size(); i++,j++){
		if(grid[row][j]!='-' && grid[row][j]!=word[i]){
			return false;
		}
	}
	return true;
}
// check vertically
bool isValidVertical(int row,int col,string word){
	if(10-row < word.size()){
		return false;
	}
	for(int i = row, j = 0; j < word.size(); i++,j++){
		if(grid[i][col]!='-' && grid[i][col]!=word[j]){
			return false;
		}
	}
	return true;
}

// set Horizontal
void setHorizontal(int row,int col,string word,bool *state){
	for(int i = 0, j = col; i < word.size(); i++,j++){
		if(grid[row][j]!='+'){
			if(grid[row][j]==word[i]){
				state[i] = false;
			}else{
				state[i] = true;
			}
			grid[row][j] = word[i];
		}
	}
	
}

// set Vertical
void setVertical(int row,int col,string word,bool *state){
	for(int i = 0, j = row; i < word.size(); i++,j++){
		if(grid[j][col]!='+'){
			if(grid[j][col]==word[i]){
				state[i] = false;
			}else{
				state[i] = true;
			}
			grid[j][col] = word[i];
		}
	}
	
}

// reset Horizontal
void resetHorizontal(int row,int col,bool *state,int len){
	for(int i = 0,j = col; i < len; i++,j++){
		if(state[i]==true){
			grid[row][j] = '-'; 
		}
	}
	return;
}
// set Vertical
void resetVertical(int row,int col,bool *state,int len){
	for(int i = 0, j = row; i < len; i++,j++){
		if(state[i]==true){
			grid[j][col] = '-'; 
		}
	}
	return;
}
// set state array
void setState(bool *state,int len){
	for(int i = 0; i < len; i++){
		state[i] = false;
	}
	return;
}
bool crosswordHelper(string input[],int size,int index){
	if(size == index){
		for(int i = 0; i < N;i++){
			for(int j = 0; j < N; j++){
				cout<<grid[i][j];
			}
			cout<<endl;
		}
		return true;
	}
	for(int r = 0; r < N; r++){
		for(int c = 0; c < N; c++){
			if(grid[r][c] == '-' || grid[r][c] == input[index][0]){
				int len = input[index].size();
				bool state[len];
				setState(state,len);
				if(isValidHorizontal(r,c,input[index])){
					setHorizontal(r,c,input[index],state);
					if(crosswordHelper(input,size,index+1)){
						return true;
					}
					resetHorizontal(r,c,state,len);
				}
				if(isValidVertical(r,c,input[index])){
					setVertical(r,c,input[index],state);
					if(crosswordHelper(input,size,index+1)){
						return true;
					}
					resetVertical(r,c,state,len);
				}
			}
		}
	}
	return false;
}
void crosswordSolver(string *input,int size){
	bool res = crosswordHelper(input,size,0);
	return;
}
int main(){
    // write your code here
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++){
        	grid[i][j] = s[j];
        }
    }
    char s[200];
    cin >> s;
    string input[10];
	string word = "";
	int a = 0;
    for(int i = 0; s[i]!='\0'; i++){
        if(s[i] == ';'){
        	input[a++] = word;
        	word = "";
		}else{
			word += s[i];
		}
    }
    input[a++] = word;
    crosswordSolver(input,a);
    
    return 0;
}