#include <bits/stdc++.h>
#include <map>
#include <ctime>
#include <time.h>
#include <cstring>
#include <iomanip>
using namespace std;
void convert_matrix_to_sparse_matrix(vector<vector<int>>&a,float s)
{
   int non_zero_element= a.size()*a[0].size()-s* a.size()*a[0].size();
   while(non_zero_element!=0)
   {
       int i=rand()%a.size();
       int j=rand()%a[0].size();
       if(a[i][j]!=0)
       {
          a[i][j]=0;
          non_zero_element--;
       }
   }
}
 void store_matrix_in_map(unordered_map<string,pair<pair<int,int>,int>>&ma,vector<vector<int>>&a)
        {
            int m=a.size();
            int n=a[0].size();
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(a[i][j]!=0)
                    {
                        ma[to_string(i)+","+to_string(j)]={{i,j},a[i][j]};
                    }
                }
            }
        }
int matrix_multiply(unordered_map<string,pair<pair<int,int>,int>>&x,unordered_map<string,pair<pair<int,int>,int>>&y,vector<vector<int>>&c)
    {   int count=0;
        for(auto i:x)
        {
            int r=i.second.first.first;int s=i.second.first.second;int t=i.second.second;
            for(auto j:y)
            {
              int r1=j.second.first.first;int s1=j.second.first.second;int t1=j.second.second;
              if(s==r1)
              {
                  c[r][s1]+=t*t1;
                  count++;
              }
            }
        }return count;
    }
int matrixMultiply(vector<vector<int>>&A, vector<vector<int>>&B, vector<vector<int>>&C, int m, int n, int p)
{
    int count=0; 
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < n; k++)
            {
                
                C[i][j] += A[i][k] * B[k][j];
               count++;
            }
        }
    }
    return count;
    
}
int main(int argc, char* argv[])
{   srand(time(0));

    int m,n,p;float sa,sb;
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    p = atoi(argv[3]);
    sa = atof(argv[4]);
    sb = atof(argv[4]);
  
    vector<vector<int>>a(m,vector<int>(n));
    vector<vector<int>>b(n,vector<int>(p));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=rand()%100;
            
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
        {   b[i][j]=rand()%100;
            
        }
    }
    /*for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
            //cout<<b[i][j]<<" "<<endl;
        }
    }cout<<endl;
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
        {
            //cout<<a[i][j]<<" ";
            cout<<b[i][j]<<" ";
        }
    }cout<<endl;*/

    convert_matrix_to_sparse_matrix(a,sa);
    convert_matrix_to_sparse_matrix(b,sb);
   /* for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
           // cout<<a[i][j]<<" ";
            //cout<<b[i][j]<<" "<<endl;
        }
    }
    cout<<endl;*/
     /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
        {
            //cout<<a[i][j]<<" ";
            cout<<b[i][j]<<" ";
        }
    }*/
    unordered_map<string,pair<pair<int,int>,int>>x;
    unordered_map<string,pair<pair<int,int>,int>>y;
    store_matrix_in_map(x,a);
    store_matrix_in_map(y,b);
    //cout<<"*****************"<<endl;
   /* for(auto i:x)
    {
        cout<<i.first<<" "<<i.second.second<<" "<<i.second.first.first<<" "<<i.second.first.second<<endl;
    }
        for(auto i:y)
    {
        cout<<i.first<<" "<<i.second.second<<" "<<i.second.first.first<<" "<<i.second.first.second<<endl;
    }*/
       
    vector<vector<int>>c(m,vector<int>(p));
     
    
    vector<vector<int>>C(m,vector<int>(p));
    clock_t start1 = clock();
    int count1=matrixMultiply(a,b, C, m, n, p);//dense matrix
    clock_t end1 = clock();
    /*for(int i=0;i<m;i++)
    {
        for(int j=0;j<p;j++)
        {
            cout<<C[i][j]<<" ";
        }
    }cout<<endl;*/
    clock_t start2 = clock();
    int count2= matrix_multiply(x,y,c);//sparse matrix
    clock_t end2 = clock();
   /* for(int i=0;i<m;i++)
    {
        for(int j=0;j<p;j++)
        {
            cout<<c[i][j]<<" ";
        }
    }cout<<endl;*/
    cout << (end2 - start2) << "," << count2 << ","<< (end1 - start1) << "," << count1 <<endl;
    
}
