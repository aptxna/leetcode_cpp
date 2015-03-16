/**
 * Clone Graph
 * 
 * Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 * OJ's undirected graph serialization:
 * Nodes are labeled uniquely.
 * We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.

 * The graph has a total of three nodes, and therefore contains three parts as separated by #.
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 * Visually, the graph looks like the following:
 *  1
      / \
     /   \
    0 --- 2
         / \
         \_/
 * 
 * 
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 * 
 * 参考：http://fisherlei.blogspot.com/2013/12/leetcode-clone-graph-solution.html
 */

class CloneGraph {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map;
        queue<UndirectedGraphNode *> visit;
        visit.push(node);
        UndirectedGraphNode *nodecpy = new UndirectedGraphNode(node->label);
        map[node] = nodecpy;
        
        while (!visit.empty()) {
            UndirectedGraphNode *current = visit.front();
            visit.pop();
            for (int i = 0; i < current->neighbors.size(); i++) {
                UndirectedGraphNode *neighbor = current->neighbors[i];
                if (map.find(neighbor) == map.end()) {
                    UndirectedGraphNode *neighborcpy = new UndirectedGraphNode(neighbor->label);
                    map[current]->neighbors.push_back(neighborcpy);
                    map[neighbor] = neighborcpy;
                    visit.push(neighbor);
                }
                else
                    map[current]->neighbors.push_back(map[neighbor]);
            }
        }
        
        return nodecpy;
    }
};