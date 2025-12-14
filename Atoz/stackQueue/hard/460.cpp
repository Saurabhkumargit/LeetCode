// https://leetcode.com/problems/lfu-cache/

#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
private:
    int cap;
    int minFreq;

    unordered_map<int, pair<int, int>> keyData;

    unordered_map<int, list<int>> freqList;

    unordered_map<int, list<int>::iterator> keyIter;

    void updateFreq(int key) {
        int freq = keyData[key].second;

        freqList[freq].erase(keyIter[key]);
        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        keyData[key].second++;
        freqList[freq + 1].push_front(key);
        keyIter[key] = freqList[freq + 1].begin();
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (cap == 0 || keyData.find(key) == keyData.end())
            return -1;

        updateFreq(key);
        return keyData[key].first;
    }

    void put(int key, int value) {
        if (cap == 0)
            return;

        if (keyData.find(key) != keyData.end()) {
            keyData[key].first = value;
            updateFreq(key);
            return;
        }

        if (keyData.size() == cap) {
            int evictKey = freqList[minFreq].back();
            freqList[minFreq].pop_back();
            if (freqList[minFreq].empty())
                freqList.erase(minFreq);

            keyIter.erase(evictKey);
            keyData.erase(evictKey);
        }

        keyData[key] = {value, 1};
        freqList[1].push_front(key);
        keyIter[key] = freqList[1].begin();
        minFreq = 1;
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */