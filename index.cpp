#include <bits/stdc++.h>
using namespace std;

//Creation of class 
class  StringCalculator{
public:
	//Function to add two numbers
    int add(string str){
        int n = str.size(), sum = 0; //Intialization of variables
        string num = "";

        bool negative_Found = false, new_Line = false, isNeg = false;
        vector<int> negativeNums;

        for(int i=0; i<n; i++){
            char ch = str[i];
            
			//Check if character is digit
            if(isdigit(ch)){
                num += ch;
            }
			//Check if character is alphabet
            else if(isalpha(ch)){
                int temp = ch - 'a' + 1;
                num += to_string(temp);
            }
            else if((int)ch == 10 || ch==';'){
                new_Line = true;
            }
			//Check if character is negative
            else if(ch == '-'){
                negative_Found = true;
                isNeg = true;
                continue;
            }
            else if(ch != ','){
                continue;
            }

            if((ch == ',' || i == n-1 || new_Line) && num.size()>0){
                // cout << num << " ";
                int number = stoi(num);
                num = "";

                if(isNeg){
                    negativeNums.push_back(-number);
                    isNeg = false;
                    continue;
                }
                new_Line = false;

                if(number > 1000) continue;
                sum += number;
            }
        }
		//If negative is found exception is thrown
        if(negative_Found){
            for(auto& negNum : negativeNums){
                cout << negNum << " ";
            }
            cout << endl;
            throw invalid_argument( "Negatives not allowed" );
        }

        return sum;
    }
};

int main()
{
    StringCalculator sc; //Object Creation
    int result = sc.add("1\n1,3;3"); //add Function call
    cout << result << endl;
    return 0;
}