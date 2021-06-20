#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; //Total chicks
    cin>>n;
    int k;
    cin>>k;//atleast k chicks need to cross the bar
    int time; //time period during which chicks can cross the bar
    cin>>time;
    int b;//bar
    cin>>b;

    int dist[n];//holding the distances of different cicks
    int speed[n];//holding speed of different chicks

    for (int i = 0; i < n; i++)
    {
        cin>>dist[i];
        cin>>speed[i];
    }

    int swaps=0;//no of swaps needed
    int not_possible=0;//holds no of cheeks can not reach to bar
    int count=0;//no of chicks reach to bar

    for (int i = n-1; i >=0; i--)
    {
        int distance_needed=b-dist[i]; //difference of distance between the bar and ith chick
        int distance_possible=speed[i]*time;//max distance that can cover by chick i in T time
        if (distance_possible>=distance_needed)
        {
            count++;
            // chick can cover the distance

            // if in middle suppose c1 c2 c3 c4 c5  (c2,c3) can't reach to bar so we need to swap c1 and make c2 c3 c1 c4 c5
            // so swaps=2 so that within time limit k chicks can reach to bar
            if(not_possible>0){
                swaps+=not_possible;
            }
        }
        else{
            not_possible++;
        }

        // k chicks reach to bar then stops loop
        if(count>=k){
            break;
        }
        
    }
    
    cout<<swaps;

} 