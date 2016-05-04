    #include<bits/stdc++.h>



    using namespace std;


    vector<int>v[100005];
    bool visit[100005];


    void dfs(int x){

        visit[x]=true;
        for(int i=0;i<v[x].size();i++){
            if(!visit[v[x][i]])
                dfs(v[x][i]);
        }

    }


    int main(){
        int t;
        t=10;
        FILE *op,*ip;
        op=fopen("op.txt","w");
        ip=fopen("ip.txt","w");
        fprintf(ip,"%d\n",t);
        while(t--){
            int n,m;
            n=(rand()%99999)+2;
            m=(rand()%(2*n))+1;
            fprintf(ip,"%d ",n);
            fprintf(ip,"%d\n",m);

            int cnt=0;

            for(int i=0;i<m;i++){
                int x,y;
                x=(rand()%n)+1;
                y=(rand()%n)+1;
                fprintf(ip,"%d ",x);
                fprintf(ip,"%d\n",y);
                v[x].push_back(y);
                v[y].push_back(x);
            }

            for(int i=1;i<=n;i++)
                visit[i]=false;

            for(int i=1;i<=n;i++){
                if(!visit[i]){
                    cnt++;
                    dfs(i);
                }
            }

            fprintf(op,"%d\n",cnt);

            for(int i=0;i<=100000;i++){
                v[i].clear();
            }
        }


        return 0;
    }



