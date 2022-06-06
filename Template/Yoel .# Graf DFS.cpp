bool DFS(vector<vector<int> > &M, int i, int j){
    if (i < h && j < w){
        if(M[i][j] == 0) return false;
        if((i == h-1 && j == w-1) )return true;
        M[i][j] = 0;
        return (DFS(M, i + 1, j) || DFS(M, i, j + 1)); //tinggal nambahin ini kalo mau nambahin arah geraknya
    } else return false;
}
