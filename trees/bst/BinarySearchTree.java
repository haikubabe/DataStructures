package trees.bst;

import trees.TreeNode;

import java.util.Stack;

public class BinarySearchTree {

    private static void inorderR(TreeNode root) {
        if (root == null) {
            return;
        }
        inorderR(root.left);
        System.out.print(root.val + " ");
        inorderR(root.right);
    }

    private static void inorderI(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode current = root;
        while (current != null || !stack.isEmpty()) {
            while (current != null) {
                stack.push(current);
                current = current.left;
            }
            current = stack.pop();
            System.out.print(current.val + " ");
            current = current.right;
        }
    }

    private static void preorderR(TreeNode root) {
        if (root == null) {
            return;
        }
        System.out.print(root.val + " ");
        preorderR(root.left);
        preorderR(root.right);
    }

    private static void preorderI(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        if (root != null) {
            stack.push(root);
        }
        while (!stack.isEmpty()) {
            TreeNode current = stack.pop();
            System.out.print(current.val + " ");
            if (current.right != null) {
                stack.push(current.right);
            }
            if (current.left != null) {
                stack.push(current.left);
            }
        }
    }

    private static void postorderR(TreeNode root) {
        if (root == null) {
            return;
        }
        postorderR(root.left);
        postorderR(root.right);
        System.out.print(root.val + " ");
    }

    private static void postorderI(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode current = root, prev = null;
        while (current != null || !stack.isEmpty()) {
            while (current != null) {
                stack.push(current);
                current = current.left;
            }
            current = stack.peek();
            if (current.right == null) {
                System.out.print(current.val + " ");
                prev = stack.pop();
            } else {
                while (current != null && current.right == prev) {
                    System.out.print(current.val + " ");
                    prev = stack.pop();
                    if (stack.isEmpty()) {
                        return;
                    }
                    current = stack.peek();
                }
            }
            if (current != null) {
                current = current.right;
            }
        }
    }

    private static TreeNode search(TreeNode root, int key) {
        if (root == null || root.val == key) {
            return root;
        }
        if (key < root.val) {
            return search(root.left, key);
        } else {
            return search(root.right, key);
        }
    }

    private static TreeNode searchI(TreeNode root, int key) {
        while (root != null && root.val != key) {
            if (key < root.val) {
                root = root.left;
            } else {
                root = root.right;
            }
        }
        return root;
    }

    private static TreeNode minimum(TreeNode root) {
        if (root == null || root.left == null) {
            return root;
        }
        return minimum(root.left);
    }

    private static TreeNode minimumI(TreeNode root) {
        while (root != null && root.left != null) {
            root = root.left;
        }
        return root;
    }

    private static TreeNode maximum(TreeNode root) {
        if (root == null || root.right == null) {
            return root;
        }
        return maximum(root.right);
    }

    private static TreeNode maximumI(TreeNode root) {
        while (root != null && root.right != null) {
            root = root.right;
        }
        return root;
    }

    private static TreeNode successor(TreeNode root, TreeNode current) {
        if (current.right != null) {
            return minimum(current.right);
        }
        TreeNode successor = null;
        TreeNode ancestor = root;
        while (ancestor != current) {
            if (current.val < ancestor.val) {
                successor = ancestor;
                ancestor = ancestor.left;
            } else {
                ancestor = ancestor.right;
            }
        }
        return successor;
    }

    private static TreeNode insertI(TreeNode root, int data) {
        TreeNode node = new TreeNode(data);
        if (root == null) {
            return node;
        }

        TreeNode temp = null, rootNode = root;
        while (root != null) {
            temp = root;
            if (data < root.val) {
                root = root.left;
            } else {
                root = root.right;
            }
        }
        if (data < temp.val) {
            temp.left = node;
        } else {
            temp.right = node;
        }
        return rootNode;
    }

    private static TreeNode insertR(TreeNode root, int data) {
        if (root == null) {
          return new TreeNode(data);
        }
        if (data < root.val) {
            root.left = insertR(root.left, data);
        } else {
            root.right = insertR(root.right, data);
        }
        return root;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(7);
        root.left = new TreeNode(5);
        root.right = new TreeNode(9);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(6);
        root.right.left = new TreeNode(8);
        root.right.right = new TreeNode(10);

        System.out.println("Inorder Recursive :");
        inorderR(root);
        System.out.println();
        System.out.println("Inorder Iterative :");
        inorderI(root);
        System.out.println();
        System.out.println("Preorder Recursive :");
        preorderR(root);
        System.out.println();
        System.out.println("Preorder Iterative :");
        preorderI(root);
        System.out.println();
        System.out.println("Postorder Recursive :");
        postorderR(root);
        System.out.println();
        System.out.println("Postorder Iterative :");
        postorderI(root);
        System.out.println();
        System.out.println("Search a key recursively :");
        TreeNode node = search(root, 20);
        if (node != null) {
            System.out.println(node.val);
        } else {
            System.out.println("The given key doesn't exist");
        }
        System.out.println("Search a key iteratively :");
        TreeNode node1 = searchI(root, 10);
        if (node1 != null) {
            System.out.println(node1.val);
        } else {
            System.out.println("The given key doesn't exist");
        }
        System.out.println("Find minimum node recursively :");
        TreeNode minNode = minimum(root);
        if (minNode != null) {
            System.out.println(minNode.val);
        } else {
            System.out.println("Tree is empty");
        }
        System.out.println("Find minimum node iteratively :");
        TreeNode minNode1 = minimumI(root);
        if (minNode1 != null) {
            System.out.println(minNode1.val);
        } else {
            System.out.println("Tree is empty");
        }
        System.out.println("Find maximum node recursively :");
        TreeNode maxNode = maximum(root);
        if (maxNode != null) {
            System.out.println(maxNode.val);
        } else {
            System.out.println("Tree is empty");
        }
        System.out.println("Find maximum node iteratively :");
        TreeNode maxNode1 = maximumI(root);
        if (maxNode1 != null) {
            System.out.println(maxNode1.val);
        } else {
            System.out.println("Tree is empty");
        }
        System.out.println("Successor of a node");
        TreeNode s1 = successor(root, root.left.left);
        if (s1 == null) {
            System.out.println("No successor of " + root.left.left.val);
        } else {
            System.out.println("Successor of " + root.left.left.val + " is " + s1.val);
        }
        TreeNode s2 = successor(root, root.left);
        if (s2 == null) {
            System.out.println("No successor of " + root.left.val);
        } else {
            System.out.println("Successor of " + root.left.val + " is " + s2.val);
        }
        TreeNode s3 = successor(root, root.left.right);
        if (s3 == null) {
            System.out.println("No successor of " + root.left.right.val);
        } else {
            System.out.println("Successor of " + root.left.right.val + " is " + s3.val);
        }
        TreeNode s4 = successor(root, root.right.right);
        if (s4 == null) {
            System.out.println("No successor of " + root.right.right.val);
        } else {
            System.out.println("Successor of " + root.right.right.val + " is " + s4.val);
        }

        inorderR(insertI(root, 3));
        System.out.println();

        inorderR(insertR(root, 2));
        System.out.println();
    }
}
