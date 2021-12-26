#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int number_of_test;
    cin >> number_of_test;
    
    vector<int> out(number_of_test, 0);
    
    for (int i = 0; i < number_of_test; i++) {
        int number_of_par_games;  
        cin >> number_of_par_games; 
        
        for(int j = 0; j< number_of_par_games; j++){
            int number_of_piles;
            cin >> number_of_piles;
            
            for(int k = 0; k< number_of_piles; k++){
                int pile; 
                cin >> pile;
                
                out[i] += (pile -1) /2;
            }
        }
    }  
    
    for (auto& line : out) {
        if(line % 2 == 0){
            cout << "Bob" << "\n";
        }
        else{
            cout << "Alice" << "\n";
        }
    }
    return 0;
}
