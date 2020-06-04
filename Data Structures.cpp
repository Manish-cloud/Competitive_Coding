/*
 * Author: Manish
 */
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(0);
using namespace std;

#define M 32
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vp;
typedef vector<tuple<int, int, int>> vt;
typedef set<int> si;
const ll Mod = 1000000007;

int main() {
    fastio;
    /*
     * Vector :-
     * A dynamic array is an array whose size can be changed during the execution of the program.
     * The most popular dynamic array in C++ is the vector structure, which can be used almost like an ordinary array.
     */
    vector<int> v;
    v.push_back(3); // [3]
    v.push_back(2); // [3,2]
    v.push_back(5); // [3,2,5]

    cout<<"Vector Size : "<<v.size()<<endl;
    cout<<"Last Element of Vector : "<<v.back()<<endl;
    cout<<"Elements of Vector : ";

    for (auto val : v)
        cout<<val<<" ";
    cout<<endl;

    v.pop_back();   // Removing last element of vector
    cout<<"Elements of Vector (After pop_back() operation) : ";
    for (auto val : v)
        cout<<val<<" ";
    cout<<endl;

    vi arr(10,0);   //Creating arr (array) of size 10 and initializing with 0
    cout<<"Elements of vector : ";
    for (auto val : arr)
        cout<<val<<" ";
    cout<<endl;

    /*
     * Set Structure :-
     * A set is a data structure that maintains a collection of elements.
     * The basic operations of sets are element insertion, search and removal.
     */
    set<int>s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    cout<<"Elements of set : ";
    for (auto ele: s)
        cout<<ele<<" ";
    cout<<endl;
    cout<<"Count of 1 in set s : "<<s.count(1)<<endl;

    s.erase(1);
    cout<<"Elements of set after removing element 1 : ";
    for (auto ele: s)
        cout<<ele<<" ";
    cout<<endl;

    s = {5,5,5};
    cout<<"Elements of set : ";
    for (auto ele : s)
        cout<<ele<<" ";
    cout<<endl;

    /*
     * C++ also contains the structures multiset and unordered_multiset that otherwise work like set and unordered_set
     * but they can contain multiple instances of an element.
     */
    multiset<int> ms={10, 10, 10};
    cout<<"Count of 10 : "<<ms.count(10)<<endl;
    cout<<"Elements of multiset : ";
    for (auto ele : ms)
        cout<<ele<<" ";

    ms.erase(10);       // Erase all elements with value 10
    cout<<"\nSize of multiset : "<<ms.size();
    ms={10, 10, 10};
    ms.erase(ms.find(10));  //Erase single element with value 10
    cout<<"\nSize of multiset : "<<ms.size();

    /*
     * Map structures :-
     * A map is a generalized array that consists of key-value-pairs.
     */
    map<string,int> m;
    m["apple"] = 120;
    m["banana"] = 50;
    m["orange"] = 80;
    cout << "\nm[banana] : " << m["banana"]; // 3
    cout << "\nm[pineapple] : "<< m["pineapple"]; // 0
    if (m.count("pineapple"))
        cout<<"\n key exists";
    else
        cout<<"\n key does not exists";

    cout<<"\nElements of map m ";
    for (auto keyValue : m)
        cout<<"\n"<<keyValue.first<<" : "<<keyValue.second;
    cout<<endl;

    /*
     * Bitset:-
     * A bitset is an array whose each value is either 0 or 1.
     * The beneﬁt of using bitsets is that they require less memory than ordinary arrays,
     * because each element in a bitset only uses one bit of memory
     */

    bitset<5>abitset;
    abitset[1]=1;
    for (int i=0;i<5;i++)
        cout<<abitset[i];
    cout<<endl;

    cout<<abitset<<endl;

    string str = "0010011010";  //from right to left
    bitset <10> bs(str);
    for (int i=0;i<str.length();i++)
        cout<<bs[i];
    cout<<endl;
    cout<<bs<<endl;

    // default constructor initializes with all bits 0
    bitset<M> bset1;

    // bset2 is initialized with bits of 20
    bitset<M> bset2(20);

    // bset3 is initialized with bits of specified binary string
    bitset<M> bset3(string("1100"));

    // cout prints exact bits representation of bitset
    cout << bset1 << endl;
    cout << bset2 << endl;
    cout << bset3 << endl;
    cout << endl;

    /*
     * Deque :-
     * A deque is a dynamic array whose size can be efficiently changed at both ends of the array.
     */

    deque<int> d;
    d.push_back(3);     // [3]
    d.push_front(2);    // [2,3]
    d.push_back(4);     // [2,3,4]
    d.push_front(1);    // [1,2,3,4]
    cout<<"Elements present in dequeue : ";
    for (auto item : d)
        cout<<item<<" ";
    cout<<endl;

    /*
     * Stack :-
     * A stack is a data structure that provides two O(1) time operations:
     * adding an element to the top, and removing an element from the top.
     */
    stack<int> astack;
    astack.push(3);
    astack.push(2);
    astack.push(5);
    cout << "Top most element of stack : " <<astack.top()<<endl; // 5
    astack.pop();
    cout << "Top most element of stack : " << astack.top()<<endl; // 2

    /*
     * Priority queue
     */

    priority_queue<int> priorityQueue;
    priorityQueue.push(7);
    priorityQueue.push(1);
    priorityQueue.push(6);
    priorityQueue.push(5);
    priorityQueue.push(3);
    cout<<priorityQueue.top()<<endl;
    priorityQueue.pop();
    cout<<priorityQueue.top()<<endl;

    priority_queue<int,vector<int>,greater<int>> q; // priority queue that supports finding and removing the smallest element
    q.push(7);
    q.push(1);
    q.push(6);
    q.push(5);
    q.push(3);
    cout<<q.top()<<endl;

    return 0;
}