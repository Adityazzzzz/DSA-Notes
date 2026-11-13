#include<iostream>
using namespace std;

// class FenwickTree{
//     vector<long long>bit;
//     long long n;
// public:
//     FenwickTree(long long n){
//         this->n = n;
//         bit.assign(n+1,0);
//     }

//     void update(long long i,long long val){
//         while(i<=n){
//             bit[i] = bit[i] + val;
//             i = i + (i & -i);
//         }
//     }

//     long long query(long long i){
//         long long sum = 0;
//         while(i>0){
//             sum += bit[i];
//             i = i - (i & -i);
//         }
//         return sum;
//     }
// };

class SegmentTree{
    vector<long long>seg;
    vector<long long>&arr;
public:
    SegmentTree(vector<long long>& a):arr(a){
        seg.resize(4*a.size());
    }
    void build(long long ind,long long low,long long high){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }
        long long mid = (low+high)/2;

        build(2*ind+1,low,mid);
        build(2*ind+2,mid+1,high);
        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }

    long long query(long long ind,long long low,long long high,long long l,long long r){
        if(l<=low && high<=r){
            return seg[ind];
        }
        if(high<l || low>r){
            return LLONG_MAX;
        }
        long long mid = (low + high)/2;
        long long left = query(2*ind+1,low,mid,l,r);
        long long right = query(2*ind+2,mid+1,high,l,r);

        return min(left,right);
    }

    void pointUpdate(long long ind,long long low,long long high,long long i,long long val){
    if(low == high){
        seg[ind] = val;
        return;
    }

    long long mid = (low + high)/2;

    if(i<=mid) pointUpdate(2*ind+1,low,mid,i,val);
    else pointUpdate(2*ind+2,mid+1,high,i,val);

    seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
}
};

int main(){
    long long n,q;
    cin>>n>>q;
    vector<long long>arr(n);
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }

    SegmentTree st(arr);
    st.build(0,0,n-1);

    while(q--) {
        long long type,a,b;
        cin>>type>>a>>b;

        if(type == 1) {
            st.pointUpdate(0,0,n-1,a-1,b);
            arr[a-1] = b;
        }
        else {
            cout<<st.query(0,0,n-1,a-1,b-1)<<'\n';
        }
    }
    return 0;
}