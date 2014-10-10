/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
        	return NULL;

        map<int, int> vis;
        map<int, UndirectedGraphNode*> newGraphNodes;
        UndirectedGraphNode *retNode = NULL;

        queue<UndirectedGraphNode *> q;
        q.push(node);
        vis[node->label] = 1;
        while(!q.empty()) {
        	UndirectedGraphNode *cur = q.front();
        	q.pop();
        	UndirectedGraphNode *curNewNode;
        	if(newGraphNodes.find(cur->label) == newGraphNodes.end()) {
        		UndirectedGraphNode *newNode = new UndirectedGraphNode(cur->label);
        		newGraphNodes[cur->label] = newNode;
        		curNewNode = newNode;
        		if(!retNode)
        			retNode = newNode;
        	} else {
        		curNewNode = newGraphNodes[cur->label];
        	}

        	for(int i = 0; i < cur->neighbors.size(); ++i) {
        		UndirectedGraphNode *neighbor = cur->neighbors[i];
        		if(vis.find(neighbor->label) == vis.end()) {
        			q.push(neighbor);
        			vis[neighbor->label] = 1;
        		}
        		if(newGraphNodes.find(neighbor->label) == newGraphNodes.end()) {
        			UndirectedGraphNode *newNeighbor = new UndirectedGraphNode(neighbor->label);
        			newGraphNodes[neighbor->label] = newNeighbor;
        		}
    			curNewNode->neighbors.push_back(newGraphNodes[neighbor->label]);
        	}
        }

        return retNode;
    }
};
