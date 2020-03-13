
// https://stackoverflow.com/questions/60659992/rat-in-maze-problems-how-to-display-coordinates-where-rat-stepped-in-random-gen
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define N 4
#define M 5

// maze of n*m matrix
int n = N, m = M;

// Coordinates of food
int fx, fy;

void printOut(const vector< vector<int> >& v)
{
    // for(int i = 0; i < v.size(); i++)
    for(int i = 0; i < v.size(); i++)
    {
        cout << "("<< v[i][0] << "," << v[i][1] << ")";
        if(i< v.size()-1) cout << "->";
    }
    cout << endl;
}

bool isSafeZone(const int& i, const int& j){
    return i>=0 && i < N && j>=0 && j<M;
}

bool isReachable(int maze[N][M], vector<vector<int>>& path)
{
    // Initially starting at (0, 0).
    bool visited[N][M]{};
    stack< vector<vector<int>> > s;
    vector<vector<int>> temp = {{0,0}};
    s.push(temp);
    vector<vector<int>> cur;

    while (!s.empty()) {
        cur = s.top();
        s.pop();
        cout << "size:" << cur.size() <<"\n" <<endl;
        if(cur.size()>1) cout << "content:" << cur[1][0] << " | "<< cur[1][1] <<endl;
        int i = cur.back()[0];
        int j = cur.back()[1];
        cout << "i::::::::" << i << ",j:::::" << j << endl;

        if(i==fx && j==fy){
            path = cur;
            return true;
        }
        visited[i][j] = true;
        // go right
        if(isSafeZone(i,j+1) && maze[i][j+1]==1 && !visited[i][j+1] )
        {
            cout << "i:" << i << ",j:" << j+1 << endl;
            vector<vector<int>> tmp(cur);
            tmp.push_back({i,j+1});
            s.push(tmp);
        }

        // go left
        if(isSafeZone(i,j-1) && maze[i][j-1]==1 && !visited[i][j-1] )
        {
            cout << "i:" << i << ",j:" << j-1 << endl;
            vector<vector<int>> tmp(cur);
            tmp.push_back({i,j-1});
            s.push(tmp);
        }

        // go bottom
        if(isSafeZone(i+1,j) && maze[i+1][j]==1 && !visited[i+1][j] )
        {
            cout << "i:" << i+1 << ",j:" << j << endl;
            vector<vector<int>> tmp(cur);
            tmp.push_back({i+1,j});
            s.push(tmp);
        }

        // go top
        if(isSafeZone(i-1,j) && maze[i-1][j]==1 && !visited[i-1][j] )
        {
            cout << "i:" << i-1 << ",j:" << j << endl;
            vector<vector<int>> tmp(cur);
            tmp.push_back({i-1,j});
            s.push(tmp);
        }
    }
    return false;
}

// Driver code
int main()
{
    // Initially setting the visited
    // array to true (unvisited)

    // Maze matrix
    int maze[N][M] = {
        { 1, 0, 1, 1, 0 },
        { 1, 1, 1, 0, 1 },
        { 0, 1, 0, 1, 1 },
        { 1, 1, 1, 1, 1 }
    };

    // Food coordinates
    fx = 2;
    fy = 3;
    vector<vector<int>> path;
    if (isReachable(maze, path)) {
        printOut(path);
        cout << "Path Found!" << '\n';
    }
    else
        cout << "No Path Found!" << '\n';

    return 0;
}
