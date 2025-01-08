// Online C++ compiler to run C++ program online
#include <iostream>
#include <fstream>
using namespace std;

//Function to check if they are one edit away.
bool oneAway(string s, string t){
    int editCount=0;
    int diff_size = s.size() - t.size();
    int shorterIndex=0, longerIndex=0; 


    if(abs(diff_size) > 1){
        return false;
    }
    string &shorter = (s.size() < t.size()) ? s : t;
    string &longer = (s.size() < t.size()) ? t : s;
    int shorter_size = shorter.size();
    while(shorterIndex < shorter_size){ //itterate through the smallest word
        if(shorter[shorterIndex] != longer[longerIndex]){ //mismatch in characters
            editCount++;
            if(editCount > 1){
                return false;
            }
            if(shorter.size() != longer.size()){ //removal of character, move the longest index
                longerIndex++;
            } 
        }
        shorterIndex++;
        longerIndex++;
    }
    
    return true;
}

void printResult(bool res,string s, string t){
    if(res){
        cout<<s<<", "<<t<<" -> true"<<endl;
    }
    else{ cout<<s<<", "<<t<<" -> false"<<endl; }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }
    ifstream inputFile(argv[1]);

    if (!inputFile.is_open()) {
        cerr << "ERROR: Could not open input file: " << argv[1] << endl;
        return 1;
    }

    string line1,line2;

    while(getline(inputFile, line1) && getline(inputFile, line2)) {
        bool result = oneAway(line1,line2);
        printResult(result,line1,line2);
    }
   
    inputFile.close();
   
    
    return 0;
}