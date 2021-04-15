// Hari

public:
    static bool sortbysec(pair<int,int> &a, pair<int,int> &b)
    {
        return (a.second < b.second);
    }
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> meet;
        for(int i = 0; i<n; i++){
            meet.push_back(make_pair(start[i], end[i]));
        }
        sort(meet.begin(), meet.end(), sortbysec);
        
        int count = 1;
        int endTimePrev = meet[0].second;
        for(int i = 1; i<n; i++){
            if(meet[i].first > endTimePrev) {
                count++;
                endTimePrev = meet[i].second;
            }
        }
        return count;
    }
