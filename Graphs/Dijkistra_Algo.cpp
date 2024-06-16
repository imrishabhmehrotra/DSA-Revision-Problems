// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution
{
    public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> dist(V, INT_MAX);
        
        pq.push({0, S});
        dist[S] = 0;

        while (!pq.empty()) {
            int node = pq.top().second;
            int nodedist = pq.top().first;
            pq.pop();

            for (vector<int> neighbor : adj[node]) {
                int adjnode = neighbor[0];
                int adjnodedist = neighbor[1];

                if (dist[adjnode] > dist[node] + adjnodedist) {
                    dist[adjnode] = dist[node] + adjnodedist;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }

        return dist;
    }
};

// Solution 2 - Using set

class Solution
{
    public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //dist, node
        set<pair<int,int>> st;
        
        vector<int> dist(V, INT_MAX);
        //source node
        st.insert({0, S});
        dist[S] = 0;
        
        while(!st.empty()) {
            auto curr = *(st.begin());
            int node = curr.second;
            int nodedist = curr.first;
            st.erase(curr);
            
            for(auto neighbor : adj[node]) {
                int adjnode = neighbor[0];
                int adjnodedist = neighbor[1];
                
                if(nodedist + adjnodedist < dist[adjnode]) {
                    if(dist[adjnode] != INT_MAX)
                        st.erase({dist[adjnode], adjnode});
                    dist[adjnode] = adjnodedist + nodedist;
                    st.insert({dist[adjnode], adjnode});
                }
            }
        }  
        return dist;
    }
};