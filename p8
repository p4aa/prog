//8: Implement paging simulation using FIFO/LRU/Optimal page replacement algorithm.

1. FIFO
// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>
using namespace std;
const int N=100005;
int n;
int frame_size;
int pages[N];
int mark[N];
void fifo_page_replacement(void)
{
queue<int> Q;
int page_faults=0;
for(int i=0; i<n; i++)
{
if(mark[pages[i]]==true)
{
cout<<"Reference to page "<<pages[i]<<" did not cause a page fault\n";
}
else
{
Q.push(pages[i]);
mark[pages[i]]=true;
if(Q.size()>frame_size)
{
int p= Q.front();
mark[p]=false;
Q.pop();
}
page_faults++;
cout<<"Reference to page "<<pages[i]<<" caused a page fault\n";
}
}
cout<<"\nTotal Page Faults: "<<page_faults;
return;
}
int main()
{
cout<<"Number of Frames: ";
cin>>frame_size;
cout<<"Page Reference Stream Length: ";
cin>>n;
cout<<"Page Reference Stream:\n";
for(int i=0; i<n; i++)
cin>>pages[i];
fifo_page_replacement();
return 0;
}

2. LRU
// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>
#include<bits/stdc++.h>
using namespace std;
// Function to find page faults using indexes
int pageFaults(int pages[], int n, int capacity)
{
// To represent set of current pages. We use
// an unordered_set so that we quickly check
// if a page is present in set or not
unordered_set<int> s;
// To store least recently used indexes
// of pages.
unordered_map<int, int> indexes;
// Start from initial page
int page_faults = 0;
for (int i=0; i<n; i++)
{
// Check if the set can hold more pages
if (s.size() < capacity)
{
// Insert it into set if not present
// already which represents page fault
if (s.find(pages[i])==s.end())
{
s.insert(pages[i]);
// increment page fault
page_faults++;
}
// Store the recently used index of
// each page
indexes[pages[i]] = i;
}
// If the set is full then need to perform lru
// i.e. remove the least recently used page
// and insert the current page
else
{
// Check if current page is not already
// present in the set
if (s.find(pages[i]) == s.end())
{
// Find the least recently used pages
// that is present in the set
int lru = INT_MAX, val;
for (auto it=s.begin(); it!=s.end(); it++)
{
if (indexes[*it] < lru)
{
lru = indexes[*it];
val = *it;
}
}
// Remove the indexes page
s.erase(val);
// insert the current page
s.insert(pages[i]);
// Increment page faults
page_faults++;
}
// Update the current page index
indexes[pages[i]] = i;
}
}
return page_faults;
}
// Driver code
int main()
{
int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
int n = sizeof(pages)/sizeof(pages[0]);
int capacity = 4;
cout << pageFaults(pages, n, capacity);
return 0;
}

3.Optimal Page Replacement

// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
// Function to check whether a page exists
// in a frame or not
bool search(int key, vector<int>& fr)
{
for (int i = 0; i < fr.size(); i++)
if (fr[i] == key)
return true;
return false;
}
// Function to find the frame that will not be used
// recently in future after given index in pg[0..pn-1]
int predict(int pg[], vector<int>& fr, int pn, int index)
{
// Store the index of pages which are going
// to be used recently in future
int res = -1, farthest = index;
for (int i = 0; i < fr.size(); i++) {
int j;
for (j = index; j < pn; j++) {
if (fr[i] == pg[j]) {
if (j > farthest) {
farthest = j;
res = i;
}
break;
}
}
// If a page is never referenced in future,
// return it.
if (j == pn)
return i;
}
// If all of the frames were not in future,
// return any of them, we return 0. Otherwise
// we return res.
return (res == -1) ? 0 : res;
}
void optimalPage(int pg[], int pn, int fn)
{
// Create an array for given number of
// frames and initialize it as empty.
vector<int> fr;
// Traverse through page reference array
// and check for miss and hit.
int hit = 0;
for (int i = 0; i < pn; i++) {
// Page found in a frame : HIT
if (search(pg[i], fr)) {
hit++;
continue;
}
// Page not found in a frame : MISS
// If there is space available in frames.
if (fr.size() < fn)
fr.push_back(pg[i]);
// Find the page to be replaced.
else {
int j = predict(pg, fr, pn, i + 1);
fr[j] = pg[i];
}
}
cout << "No. of hits = " << hit << endl;
cout << "No. of misses = " << pn - hit << endl;
}
// Driver Function
int main()
{
int pg[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 };
int pn = sizeof(pg) / sizeof(pg[0]);
int fn = 4;
optimalPage(pg, pn, fn);
return 0;
}
