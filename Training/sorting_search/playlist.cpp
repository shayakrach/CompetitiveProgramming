#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    map<int,int> songs;
    
    int max_chain = 0, curr_chain=0;

    vector <int> check;
    for (int i = 0; i < N; ++i) {
        int song;
        cin >> song;
        if(songs.find(song) != songs.end()){
            
            curr_chain = min(curr_chain, i - songs[song]);
            
        }
        else{
            curr_chain++;max_chain = max(max_chain, curr_chain);
            //check.push_back(i);
        }
        
        songs[song] = i;
    }
    
    cout << endl << max(max_chain, curr_chain);
    return 0; 
}