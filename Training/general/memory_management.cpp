#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

void handle_FIFO(list<int> &FIFO, int &FIFO_changes, int page, int num_of_pages)
{
    if(find(FIFO.begin() , FIFO.end() , page) == FIFO.end())
    {
        FIFO.push_back(page);
        if (FIFO.size() > (size_t)num_of_pages)
        {
            FIFO_changes++;
            FIFO.pop_front();
        }
    }
}


void handle_LRU(list<int> &LRU, int &LRU_changes, int page, int num_of_pages)
{   
    int curr_LRU_size = LRU.size();    
    LRU.remove(page);
    
    if((size_t)curr_LRU_size == LRU.size())
    {
        if(num_of_pages == curr_LRU_size)
        {
            LRU_changes++;
            LRU.pop_front();
        }
    }

    LRU.push_back(page);
}


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int tests;
    cin >> tests;
    
    for(int i=0; i<tests; i++)
    {
        list<int> LRU, FIFO; 
        int p, s, n ,LRU_changes = 0, FIFO_changes=0; 
        cin>>p>>s>>n;
        
        for(int j=0; j<n; j++)
        {
            int addr;
            cin >> addr;
            int page = addr/s;
    
            handle_LRU(LRU, LRU_changes, page, p);
            handle_FIFO(FIFO, FIFO_changes, page, p);
        }
       
        string advertised = FIFO_changes > LRU_changes ? "yes" : "no";
        cout << advertised << " " << FIFO_changes << " " << LRU_changes << endl;
    }
    
    return 0;

}