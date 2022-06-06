void dijkstra(int s, int n) {
    priority_queue <pii, vector <pii>, greater <pii> > pq;
    set <int> seen;
    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()) {
        pii now = pq.top();
        pq.pop();
        if(seen.find(now.second) != seen.end()) continue;
        seen.insert(now.second);
        for(int i = 0; i < v[now.second].size(); i++) {
            int next = v[now.second][i].second;
            int cost = v[now.second][i].first;

            if(now.first + cost < dist[next] || dist[next] == -1) {
                dist[next] = now.first + cost;
                pq.push({dist[next], next});
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << "from " << s << " to " << i << " : " << dist[i] << endl;
    }
    return;
}
