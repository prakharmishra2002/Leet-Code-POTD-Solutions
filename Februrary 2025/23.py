class Solution:
    def constructFromPrePost(
        self, preorder: List[int], postorder: List[int]
    ) -> Optional[TreeNode]:
        num_of_nodes = len(preorder)
        return self._construct_tree(0, num_of_nodes - 1, 0, preorder, postorder)

    # Helper function to construct the tree recursively
    def _construct_tree(
        self,
        pre_start: int,
        pre_end: int,
        post_start: int,
        preorder: List[int],
        postorder: List[int],
    ) -> Optional[TreeNode]:
        # Base case: If there are no nodes to process, return None
        if pre_start > pre_end:
            return None

        # Base case: If only one node is left, return that node
        if pre_start == pre_end:
            return TreeNode(preorder[pre_start])

        # The left child root in preorder traversal (next element after root)
        left_root = preorder[pre_start + 1]

        # Calculate the number of nodes in the left subtree by searching in postorder
        num_of_nodes_in_left = 1
        while postorder[post_start + num_of_nodes_in_left - 1] != left_root:
            num_of_nodes_in_left += 1

        root = TreeNode(preorder[pre_start])

        # Recursively construct the left subtree
        root.left = self._construct_tree(
            pre_start + 1,
            pre_start + num_of_nodes_in_left,
            post_start,
            preorder,
            postorder,
        )

        # Recursively construct the right subtree
        root.right = self._construct_tree(
            pre_start + num_of_nodes_in_left + 1,
            pre_end,
            post_start + num_of_nodes_in_left,
            preorder,
            postorder,
        )

        return root
