#include<bits/stdc++.h>
#include<chrono>

using namespace std;

class Timer{
public:
    Timer(){
        start_time_point = chrono::high_resolution_clock::now();
    }

    ~Timer(){
        stop();
    }

    void stop(){
        auto end_time_point = chrono::high_resolution_clock::now();
        auto start = chrono::time_point_cast<chrono::microseconds>(start_time_point).time_since_epoch().count();
        auto end = chrono::time_point_cast<chrono::microseconds>(end_time_point).time_since_epoch().count();
        auto duration = end-start;
        double ms = duration*0.001;
        
        printf("%lf", ms);
    }

private:
    chrono::time_point< chrono::high_resolution_clock> start_time_point;
};


int main(){ios_base::sync_with_stdio(false);
    int const n = 1000000;
    string s = "abcdefghij";
    {
        Timer timer;
        for(int i=0; i<n; ++i){
            puts(s.c_str()); 
        }
    }
    
    return 0;
}
