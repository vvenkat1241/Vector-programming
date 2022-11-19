#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
    vector<int> v;
    int a;
    double alpha,beta,gamma;
    // cout<<"Enter row ";
    // cin>>row;
    // cout<<endl<<"Enter column ";
    // cin>>column;
    // taking input into 2D vector from user
    for(int i=0 ; i< 3; i++) {
        cin>>a;
        v.push_back(a);
    }
    // // displaying 2D vector value
    // for(auto q: v) {
    //     for(auto it: q) {
    //         cout<<it<<" ";
    //      } 
    //      cout<<endl;
    //  }
    cout<<endl<<"Enter alpha, beta and gamma ";
    cin>>alpha>>beta>>gamma;
    double alphadeg=alpha*3.14159/180;
    double betadeg=beta*3.14159/180;
    double gammadeg=gamma*3.14159/180;

    double sina=sin(alphadeg);
    double cosa=cos(alphadeg);
    double sinb=sin(betadeg);
    double cosb=cos(betadeg);
    double sinc=sin(gammadeg);
    double cosc=cos(gammadeg);

vector<vector<double>> R_x {
               {1,       0,              0},
               {0,       cosa,   -sina},
               {0,       sina,   cosa}
};

vector<vector<double>> R_y {
    {cosb,    0,      sinb},
    {0,       1,      0},
    {-sinb,   0,      cosb}
};

vector<vector<double>> R_z {
    {cosc,    -sinc,      0},
    {sinc,    cosc,       0},
    {0,               0,                  1}
};

vector<vector<double>> R_xy {
    {0,0,0},
    {0,0,0},
    {0,0,0}
};

vector<vector<double>> R {
    {0,0,0},
    {0,0,0},
    {0,0,0}
};

vector<double> Rotat {
    {0,0,0},
};

for (int i=0;i<R_y.size();i++){
    for(int j=0;j<R_x[0].size();j++){
        for(int k=0;k<R_x.size();k++){
            R_xy[i][j] += R_x[i][k] * R_y[k][j];
        }
    }
}

for (int i=0;i<R_z.size();i++){
    for(int j=0;j<R_xy[0].size();j++){
        for(int k=0;k<R_xy.size();k++){
             R[i][j] = R_xy[i][k] * R_z[k][j];
        }
    }
}

cout<<"The Rotated vector is:"<<endl;

for (int i=0;i<v.size();i++){
        for(int k=0;k<R.size();k++){
            Rotat[i] += R[i][k] * v[i];
        }
    
}

for(auto q: Rotat) {
    cout<<setw(0);         
    cout<<q<<endl;
     }

return 0;
}