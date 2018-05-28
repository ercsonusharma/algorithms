#include<bits/stdc++.h>
#define LL long long int
#define MAX(x, y) (x) < (y) ? (y) : (x)
using namespace std;

vector<int> pfactors[100005];
int prime[100005];
LL n;

void precompute() {
    LL i, j, k;

    //All Primes marked
    for(i=2;i*i<100005;i++) {
        if(!prime[i]) {
            for(j=i*i;j<100005;j+=i) {
                prime[j] = 1;
            }
        }
    }
    prime[0] = prime[1] = 1;

    //Prime factors to be pushed
    for(i=2;i*i<100005;i++) {
        if(!prime[i]) {
            pfactors[i].push_back(i);
        }
        for(j=i*2;j<100005;j+=i) {
            if(i*i <= j && (!prime[i]))
                pfactors[j].push_back(i);

            if(i*i < j && (!prime[j/i])) {
                pfactors[j].push_back(j/i);
            }
        }
    }

    for(i=2;i<100005;i++) {
        if(pfactors[i].empty()) {
            pfactors[i].push_back(i);
        }
    }
}

LL solve(LL m) {
    LL ans = 0;
    LL size = pfactors[m].size();
    LL i, j, mask;

    for(mask=0;mask<(1<<size);mask++) {
        LL cnt = 0, num = 1;
        for(j=0;j<size;j++) {
            if(!((1<<j) & mask)) {
                cnt++;
                num = num*pfactors[m][j];
            }
        }
        if(cnt) {
            i = (cnt&1) ? 1 : (-1);
            ans = ans + i*(n/num);
        }
    }
    return ans;
}

int main() {
    LL i, j, k, m, q;
    precompute();

    cin>>n;
    cin>>q;
    while(q--) {
        cin>>m;
        if(m == 0)
            cout<<n-1<<endl;
        else
            cout<<solve(m)<<endl;
    }
    return 0;
}
