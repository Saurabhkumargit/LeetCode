// https://leetcode.com/problems/find-median-from-data-stream/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> left; 
    priority_queue<int, vector<int>, greater<int>> right; 

public:
    MedianFinder() {}

    void addNum(int num) {
        left.push(num);

        if (!right.empty() && left.top() > right.top()) {
            int x = left.top(); left.pop();
            right.push(x);
        }

        if ((int)left.size() > (int)right.size() + 1) {
            int x = left.top(); left.pop();
            right.push(x);
        } 
        else if ((int)right.size() > (int)left.size()) {
            int x = right.top(); right.pop();
            left.push(x);
        }
    }

    double findMedian() {
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        }
        return left.top(); 
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */