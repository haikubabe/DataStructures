package trees.avl;

public class Node {

    public int data;
    public Node left;
    public Node right;
    public Node parent;
    public int height;

    public Node(int data) {
        this.data = data;
        this.height = 0;
    }
}
