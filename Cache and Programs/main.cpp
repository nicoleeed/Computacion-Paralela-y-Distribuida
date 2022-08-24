#include <bits/stdc++.h>
using namespace std;

random_device rd; 
mt19937 gen(rd()); 
uniform_int_distribution<> distrib(1, 100);

int generadorAleatorio(){
    return distrib(gen);
}

int main(){
    srand(time(NULL));
    vector<int> v_numbers={100,1000,10000,20000,30000};
    chrono::time_point<std::chrono::high_resolution_clock> start, end;

    for(int n=0; n<v_numbers.size();n++){
        int max=v_numbers[n];

        cout<<"------------ "<< max <<" Items in matrix ------------"<<endl;
        vector<vector<double>> A(max, vector<double>(max, 0));
        vector<double> x(max);
        vector<double> y(max);

        for(int i=0; i<max ;i++){
            x[i]=generadorAleatorio();
            y[i]=0;
            for(int j=0; j<max ;j++){
                A[i][j]=generadorAleatorio();
            }
        }

        cout<<"** First Loop Time -> "<<endl;
        start = chrono::high_resolution_clock::now();
        for(int i=0; i<max ;i++){
            for(int j=0; j<max ;j++){
                y[i]+= A[i][j] * x[j];
            }
        }
        end = chrono::high_resolution_clock::now();
        int64_t duration = chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        cout<<duration<<endl;

        cout<<"** Second Loop Time -> "<<endl;
        start = chrono::high_resolution_clock::now();
        for(int j=0; j<max ;j++){
            for(int i=0; i<max ;i++){
                y[i]+= A[i][j] * x[j];
            }
        }
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        cout<<duration<<endl;
    }
}