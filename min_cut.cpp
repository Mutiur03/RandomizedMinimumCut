#include <bits/stdc++.h>

using namespace std;



struct edge
{
    long long int u;
    long long int v;
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    random_device rd;
    mt19937 gen(rd());

    string infile = "input.txt";
    string outfile= "output.txt";
    ifstream fin(infile);
    ofstream fout(outfile);

    long long int t=1,n,m,i,j,k,x,y,z;
    fin >> t ;
    while(t--)
    {
        fin >> n >> m ;
        
        vector<edge>gr,gr1;
        vector<long long int>a[n+6];
        edge e;
        
        for(i=0;i<m;i++)
        {
            fin >> x >> y ;
            e.u=x;
            e.v=y;
            gr.push_back(e);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        
        
        for(i=0;i<n-2;i++)
        {
            
            m=gr.size();
            uniform_int_distribution<>distribution(0,m-1);
            k=distribution(gen);
           // fout << k << "\n" ;
            swap(gr[k],gr[m-1]);
            x=gr[m-1].u;
            y=gr[m-1].v;
            //fout << x << " " << y << "\n" ;
            //vector<long long int>del;
            for(j=0;j<m;j++)
            {
                if(gr[j].u==y)
                {
                    gr[j].u=x;
                }
                if(gr[j].v==y)
                {
                    gr[j].v=x;
                }
                
            }
            
            for(j=0;j<gr.size();j++)
            {
                if(gr[j].u==gr[j].v)
                {
                    m=gr.size();
                    swap(gr[j],gr[m-1]);
                    gr.pop_back();
                    j--;
                }
            }
            for(j=0;j<gr.size();j++)
            {
                //fout << gr[j].u << " -- " << gr[j].v << "\n" ;
            }
        }
        
        fout << gr.size() << "\n" ;
        //fout << "Hello world!" << endl;
    }
    return 0;
}
