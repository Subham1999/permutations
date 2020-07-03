/*
	@author Subham Santra
	______________________________________________________________________________________
	Objective : Permutation of all strings stored in input.csv file in the same directory.

	Steps followed:
		1. First taking input from file, filename is passed in cimmandline.
		2. Filter out all strings from CSV formatted string.
		3. pass the each filtered string to permute function along with start index as zero and end index as length - 1, 
			and a vector which will store all permutation of the given string;
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> filter_strings(string line){
	vector<string> out;
	int start = 0;
	for(int i = 0; i < line.length(); i++){
		if(line[i] == ',' or line[i] == '\n'){
			out.push_back(line.substr(start, i - start));
		}
		if(line[i] == ' '){
			start = i+1;
		}
	}
	return out;
}
void permute(string s, int start, int end, vector<string>& result){
	if(start == end){
		result.push_back(s);
	} else{
		for(int position = start; position <= end; ++position){
			swap(s[start], s[position]);
			permute(s, start+1, end, result);
			swap(s[start], s[position]);
		}
	}

}
int main(int argc, const char **argv){
	ifstream infile(argv[1]);
	// file name mentioned opened
    if (infile.is_open() && infile.good()) {
        string line = "";
        vector<string> input;
        while (getline(infile, line)){			// input from file is taken
            input = filter_strings(line);		// filtering process is done here
            vector<string> result;
            for(string each_input : input){
            	result = vector<string>{};		// this will store all permutation of a string
            	permute(each_input, 0, each_input.length() - 1, result);	// this is main utility function for permutation
            	cout << "Permutation of \'" << each_input << "\' ==>"; 
            	cout << "[";
            	for(string each_result : result){
            		cout << each_result << " ";
            	}
            	cout << "]\n\n\n";
            }
        }
        infile.close();
    } else {
        cout << "Failed!!";
    }
	return 0;
}