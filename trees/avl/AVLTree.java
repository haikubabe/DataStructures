package trees.avl;

public class AVLTree {

    private Node root;

    private int height(Node x) {
        if (x == null) {
            return -1;
        }
        return x.height;
    }

    private int updateHeight(Node x) {
        return max(height(x.left), height(x.right)) + 1;
    }

    private int max(int a, int b) {
        return (a > b ? a : b);
    }

    private Node leftRotate(Node x) {
        Node y = x.right;
        x.right = y.left;
        if (y.left != null) {
            y.left.parent = x;
        }
        y.parent = x.parent;
        if (x.parent == null) {
            this.root = y;
        } else if (x == x.parent.left) {
            x.parent.left = y;
        } else {
            x.parent.right = y;
        }
        y.left = x;
        x.parent = y;
        x.height = updateHeight(x);
        y.height = updateHeight(y);
        return y;
    }

    private Node rightRotate(Node x) {
        Node y = x.left;
        x.left = y.right;
        if (y.right != null) {
            y.right.parent = x;
        }
        y.parent = x.parent;
        if (x.parent == null) {
            this.root = y;
        } else if (x == x.parent.left) {
            x.parent.left = y;
        } else {
            x.parent.right = y;
        }
        y.right = x;
        x.parent = y;
        x.height = updateHeight(x);
        y.height = updateHeight(y);
        return y;
    }

    private int balanceFactor(Node x) {
        return height(x.left)-height(x.right);
    }

    private boolean isDoublyRightHeavy(Node x) {
        return balanceFactor(x) < -1;
    }

    private boolean isDoublyLeftHeavy(Node x) {
        return balanceFactor(x) > 1;
    }

    private boolean isRightHeavy(Node x) {
        return balanceFactor(x) < 0;
    }

    private boolean isLeftHeavy(Node x) {
        return balanceFactor(x) > 0;
    }

    private Node rebalance(Node x) {
        //if x is doubly right heavy
        if (isDoublyRightHeavy(x)) {
            //if the right child of x is left heavy
            if (isLeftHeavy(x.right)) {
                rightRotate(x.right);
            }
            //the right child of x is right heavy
            x = leftRotate(x);
        }
        //if x is doubly left heavy
        else if (isDoublyLeftHeavy(x)) {
            //if the left child of x is right heavy
            if (isRightHeavy(x.left)) {
                leftRotate(x.left);
            }
            //the left child of x is left heavy
            x = rightRotate(x);
        }
        return x;
    }

    private Node insert(Node root, int data) {

        if (root == null) {
            return new Node(data);
        }

        Node node;
        if (data < root.data) {
            node = insert(root.left, data);
            root.left = node;
            node.parent = root;
        } else if (data > root.data) {
            node = insert(root.right, data);
            root.right = node;
            node.parent = root;
        } else {
            return root;
        }

        root.height = updateHeight(root);
        root = rebalance(root);
        return root;
    }

    private void inorder(Node root) {
        if (root == null) {
            return;
        }
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    public static void main(String[] args) {

        AVLTree avlTree = new AVLTree();
        avlTree.root = avlTree.insert(avlTree.root, 10);
        avlTree.root = avlTree.insert(avlTree.root, 20);
        avlTree.root = avlTree.insert(avlTree.root, 30);
        avlTree.root = avlTree.insert(avlTree.root, 40);
        avlTree.root = avlTree.insert(avlTree.root, 50);
        avlTree.root = avlTree.insert(avlTree.root, 25);

        avlTree.inorder(avlTree.root);
        System.out.println();
    }
}
