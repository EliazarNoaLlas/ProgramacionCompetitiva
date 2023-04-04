# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        '''
        Traverse tree, depth first:
            At each node record its parent to the parents dictionary
        Follow the line of parents from p, and insert all into the set p_ancestors
        Follow the line of parents from q, until one is a member of p_ancestors
        '''
        parents = {root.val: None}      # Mapea el valor de cada nodo en su nodo padre
        p_ancestors = set()             # A set for p's ancestors

        def find_all_parents(node: TreeNode) -> None:
            # Depth-first traversal to identify the parent of each node
            if node.left:
                parents[node.left.val] = node
                find_all_parents(node.left)
            if node.right:
                parents[node.right.val] = node
                find_all_parents(node.right)
    
        find_all_parents(root)
        while p is not None:
            p_ancestors.add(p.val)
            p = parents[p.val]
        while q != root and q.val not in p_ancestors:
            q = parents[q.val]
        return q
root = [3,5,1,6,2,0,8,None,None,7,4]
p = 5
q = 1
Solution().lowestCommonAncestor(root, p, q)
esto