// N meetings in one room

class Solution{
public:
    int maxMeetings(vector<int>& start, vector<int>& end){
        int n = start.size();
        
        vector<pair<int,int>> meetings;
        meetings.reserve(n);
        
        for(int i = 0; i < n; i++){
            meetings.push_back({end[i], start[i]}); 
        }
        
        sort(meetings.begin(), meetings.end()); 
        
        int count = 0;
        int lastEnd = -1;
        
        for(auto &m : meetings){
            int e = m.first;
            int s = m.second;
            
            if(s > lastEnd){   
                count++;
                lastEnd = e;
            }
        }
        
        return count;
    }
};
