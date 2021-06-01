#include<bits/stdc++.h>
using namespace std;
void choose_swap(string a){
  set<char> s;
  for (int i = 0; i < a.length(); i++)
  {
      s.insert(a[i]);
  }
  for (int i = 0; i < a.length(); i++)
  {
        s.erase(a[i]);
        if(s.empty()) break;
        char ch=*s.begin();
        if(ch<a[i]){
            char ch1=a[i];
            for (int j = 0; j < a.length(); j++)
            {
                if(a[j]==ch1) a[j]=ch;
                else if(a[j]==ch)   a[j]==ch1;
            }
            break;
        }
      
  }
  cout<<a<<endl;
    
}

int main(){
    string s;
    cin>>s;
    choose_swap(s);
}




// In this problem i have to replace string with lexicographic string
// Lexicographic means increasing order of character
// In this if given baab
// Take set place {b,a}
// take elemenet from set which is b
// loop through entire string and check if ch is less than the b
// if yes then replace it with b and if we found b anywhere in string then replace it with ch

// so  here   b->a->a->b
// so  take b from set {a} b->a->a->b
// take a from set {}  a->b->b->a


// other example c->c->a->d
//  set{a,c,d} ch=a {c,d} a->a->c->d
//  set{c,d}   ch=c {d}   a->a->c->d
//  set{} ch=d             a->a->c->d
//                        
// ch=d                    