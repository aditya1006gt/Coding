class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        // vector<pair<int,int>>ser;
        int n=servers.size();
        for(int i=0;i<n;i++) {
            pq.push({servers[i],i});
        }
        // sort(ser.begin(),ser.end());

        priority_queue< pair<long long,pair<int,int>>, vector<pair<long long,pair<int,int>>>, greater<pair<long long,pair<int,int>>>>busy;

        int m=tasks.size();
        long long time=0;
        vector<int> ans;
        for(int i=0;i<m;i++) {
            time=max(time,(long long)i);

            while(!busy.empty() && busy.top().first<=time) {
                auto tp=busy.top();
                busy.pop();
                pq.push(tp.second);
            }

            if(pq.empty()) {

                time=busy.top().first;

                while(!busy.empty() && busy.top().first<=time) {
                    auto tp=busy.top();
                    busy.pop();
                    pq.push(tp.second);
                }
            }
            
            auto tp=pq.top();pq.pop();

            int serind=tp.second;
            int wt=tp.first;
            ans.push_back(serind);

            busy.push({time+tasks[i],{wt,serind}});
        }
        return ans;
    }
};