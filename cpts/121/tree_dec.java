/*

2 rules for particular node

case 1: if current node is greater than or equal to 2, you can decremnt by 2 for free

OR

minimize_cost(tree)

case 2: select some other node and decrement 
both by 1 and incur a cost equal to distance(n1, n2)


case 1: if node.count >= 2 {node.count -= 2}

OR

case 2: pick another node n2 such that minimize_cost(tree) is minimal

def minimize_cost(root):
    
    2, 0, 0

    2
   / \
  1   1


*/

public static int getMinCost(List<Integer> val, int tNodes, List<Integer> tFrom, List<Integer> tTo) {
        int cost = 0;
        
        int numZero = 0;

        for (int i = 0; i <, val.size(); ++i) {
            if (val.get(i) == 0) {
                ++numZero;
            }
        }

        if (numZero == tNodes) {
            return cost;
        }


        if (numZero == tNodes - 1) {
            for (int i = 0; i < val.size(); ++i) {
                if (val.get(i) > 0 && val.get(i) % 2 != 0) return Integer.MAX_INT;
            }
        }

        for (int i = 0; i < tNodes; ++i) {
            int curNode = i;
            // case 1:
            int nodeVal = val.get(curNode);

            int minCase1 = Integer.MAX_INT;

            if (nodeVal >= 2) {
                val.set(curNode, nodeVal - 2);
                minCase1 = getMinCost(val, tNodes, tFrom, tTo);

                val.set(curNode, nodeVal);
            }

            int minCase2 = Integer.MAX_INT;

            // case 2:
            for (int otherNode = 0; otherNode < tNodes; ++otherNode) {

                if (val.get(curNode) > 0 && val.get(otherNode) > 0) {
                    int dist = dist(otherNode, curNode);
                    int otherVal = val.get(otherNode);


                    val.set(curNode, nodeVal-1);
                    val.set(otherNode, otherVal - 1);
                    minCase2 = Math.min(minCase2, getMinCost(val, tNodes, tFrom, tTo) + dist);
                    val.set(curNode, nodeVal);
                    val.set(otherNode, otherVal);
                
            }

            if (minCase1 == Integer.MAX_INT && minCase2 == Integer.MAX_INT) {
                return minCase1;
            }
            
            cost = Math.min(minCase1, minCase2);
            
        }

        if (numZero != tNodes) {
            return Integer.MAX_INT;
        }

        return cost;
}

Set<Integer> visited = new HashSet<>();

/*
    0
   / \
  1   2
  |   |
  3   4
      |
      5
*/
public static int dist(int startNode, int endNode, int tNodes, List<Integer> tFrom, List<Integer> tTo) {
    if (startNode == endNode) {
        return 0;
    }
    
    visited.add(startNode);
    int minDistance = Integer.MAX_INT;

    for (int i = 0; i < tFrom.size(); ++i) {
        int node = tFrom.get(i) - 1;

        if (node == startNode) {
            int adjacentNode = tTo.get(i) - 1;

            if (!visited.contains(adjacentNode)) {
                visited.add(adjacentNode);
                minDistance = Math.min(minDistance, dist(adjacentNode, endNode, tNodes, tFrom, tTo) + 1);
                visited.remove(adjacentNode);
            }
        }
    }

    return minDistance;
}

public static int min2(List<Integer> val, int tNodes, List<Integer> tFrom, List<Integer> tTo){
    val = modVals(val);
    int aList = getAdjacencyListFilterOutZeros(tNodes, tFrom,  tTo, val); 
    distances = dist2(aList);


}

int helper(int[][] d) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int dist = d[i][j];
            d[i][j] = Integer.MAX_INT;
            int best = helper(d);
        }
    }
}

// flloyd warshawl shrotesrt path
public static int[][] dist2(boolean[][] adjacencyList, int n) {
    /*
        1 2 3 4 5
    1   t t f
    2
    3
    4
    5
    */
    
    int[][] d = new int[n][n];

    // ^^^^^^^^^^^^^ inittialize it to infinity in d, and d[i][i] = 0 for all i
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == i) {
                d[i][i] = 0;
            } else {
                if (adjacencyList[i][j]) {
                    d[i][j] = 1;
                } else {
                    d[i][j] = Integer.MAX_INT;
                }
            }
        }
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int bestDist = d[i][j];
            int bestOther = Integer.MAX_INT;

            for (int k = 0; k < n; ++k) {
                int cost = d[i][k] + d[k][j];
                if (cost > bestOther) {
                    bestOther = cost;
                }
            }

            if (bestDist > bestOther) {
                bestDist = bestOther;
            }

            d[i][j] = bestDist;
        }
    }
}