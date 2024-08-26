#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <bits/stdc++.h> 
#include <map>
#include <queue>
#include <fstream>
#include<algorithm>

using namespace std;

class graphNode
{
public:
    int data;
    vector<graphNode *> neighbours;
    graphNode()
    {
        data = 0;
        neighbours = vector<graphNode *>();
    }

    graphNode(int val)
    {
        data = val;
        neighbours = vector<graphNode *>();
    }

    graphNode(int val, vector<graphNode *> neighbours)
    {
        data = val;
        this->neighbours = neighbours;
    }

    ~graphNode()
    {
        neighbours.clear();
    }
};

graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	if(node == NULL){
		return NULL;
	}
	unordered_map<graphNode *, graphNode *> copies;

	graphNode* copy = new graphNode(node->data);
	copies[node] = copy;
	queue<graphNode *> level;
	level.push(node);

	while(!level.empty()){
		graphNode* cur = level.front();
		level.pop();

		for(graphNode *neighbor : cur->neighbours){
			if(copies.find(neighbor) == copies.end()){
				copies[neighbor] = new graphNode(neighbor->data, {});
				level.push(neighbor);
			}
			copies[cur] -> neighbours.push_back(copies[neighbor]);
		}
	}
	return copy;
}

bool comp(graphNode* a, graphNode* b)
{
    return a->data<b->data;
}

class Runner
{
    int t;
    vector<graphNode *> graphs;

public:
    bool bfsCheckAnswer(graphNode *ans, graphNode *src)
    {
        map<graphNode *, bool> visit, visitAns;
        queue<graphNode *> q, qans;
        q.push(src);
        qans.push(ans);
        visit[src] = true;
        visitAns[ans] = true;
        while (!q.empty())
        {
            graphNode *u = q.front();
            graphNode *p = qans.front();
            if (u->data != p->data)
            {
                return false;
            }
            if (u == p)
            {
                return false;
            }
            q.pop();
            qans.pop();
            vector<graphNode *> v = u->neighbours;
            vector<graphNode *> vAns = p->neighbours;

            if (v.size() != vAns.size())
            {
                return false;
            }

            int n = v.size();

            sort(v.begin(), v.end(),comp);
            sort(vAns.begin(), vAns.end(),comp);
            
            
            for (int i = 0; i < n; i++)
            {
                 if (v[i]->data != vAns[i]->data)
                {
                    return false;
                }
                if (!visit[v[i]])
                {
                    visit[v[i]] = true;
                    q.push(v[i]);
                }

                if (!visitAns[vAns[i]])
                {
                    visitAns[vAns[i]] = true;
                    qans.push(vAns[i]);
                }
            }
        }
        return true;
    }

    void takeInput()
    {
        cin >> t;
        for (int c = 0; c < t; c++)
        {
            int n;
            cin >> n;
            graphNode *head;
            int m;
            cin >> m;

            map<int, graphNode *> check;

            for (int i = 0; i < m; i++)
            {
                int x, y;
                cin >> x >> y;
                if (x == y)
                {
                    continue;
                }
                if (!check[x])
                {
                    graphNode *temp = new graphNode();
                    head = temp;
                    temp->data = x;
                    check[x] = temp;
                }
                if (!check[y])
                {
                    graphNode *temp = new graphNode();
                    temp->data = y;
                    check[y] = temp;
                }

                vector<graphNode *> n1 = check[x]->neighbours;
                if (find(n1.begin(), n1.end(), check[y]) == n1.end())
                {
                    check[x]->neighbours.push_back(check[y]);
                }

                vector<graphNode *> n2 = check[y]->neighbours;
                if (find(n2.begin(), n2.end(), check[x]) == n2.end())
                {
                    check[y]->neighbours.push_back(check[x]);
                }
            }
            graphs.push_back(head);
        }
    }

    graphNode *copyGraphHelper(graphNode *node, unordered_map<graphNode *, graphNode *> &copies)
    {
        if (node == NULL)
        {
            return NULL;
        }

        graphNode *copy = new graphNode(node->data);
        copies[node] = copy;
        queue<graphNode *> level;
        level.push(node);

        while (!level.empty())
        {
            graphNode *cur = level.front();
            level.pop();
            for (graphNode *neighbor : cur->neighbours)
            {
                if (copies.find(neighbor) == copies.end())
                {
                    copies[neighbor] = new graphNode(neighbor->data, {});
                    level.push(neighbor);
                }
                copies[cur]->neighbours.push_back(copies[neighbor]);
            }
        }
        return copy;
    }

    graphNode *copyGraph(graphNode *node)
    {
        unordered_map<graphNode *, graphNode *> copies;
        return copyGraphHelper(node, copies);
    }

    void execute()
    {
        for (int i = 0; i < t; i++)
        {
            graphNode *copy = copyGraph(graphs[i]);

            graphNode *ans = cloneGraph(copy);

            delete copy;
            delete ans;
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            graphNode *copy = copyGraph(graphs[i]);

            graphNode *ans = cloneGraph(copy);

            if (bfsCheckAnswer(ans, graphs[i]))
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }

            delete ans;
        }
    }
};

int main()
{

    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}