#include <bits/stdc++.h>
using namespace std;
struct Item{
    int v,w;
    double r;
};
bool compare(Item a,Item b){
    return a.r>b.r;
}
int main(){
	int n;
    int profit=0;
	int cap=0;
    cout<<"Enter the number of elements: ";
	cin>>n;
	Item arr[n];
	
	cout<<"Enter the Cap: ";
	cin>>cap;
	for (int i=0;i<n;i++){
		cout<<"Enter Value and w of element"<<i+1;
		cin>>arr[i].v>>arr[i].w;
		arr[i].r=(arr[i].v)/(arr[i].w);
	}
	sort(arr,arr+n,compare);
	for(int i=0;i<n;i++){
		if(cap>0 && arr[i].w<cap){
			cap-=arr[i].w;
			profit+=arr[i].v;
		}
		else{
			profit+=(arr[i].r)*cap;
            break;
		}
	}
	cout<<"Profit is : "<<profit;
    return 0;
}