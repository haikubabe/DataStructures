package custom_hashmap;

import java.util.Map;

public class MyHashMap<K, V> implements MyMap<K, V> {

    private static final int DEFAULT_INITIAL_CAPACITY = 1 << 4;

    static class Node<K, V> implements MyMap.Entry<K, V> {
        int hash;
        K key;
        V value;
        Node<K, V> next;

        Node(int hash, K key, V value, Node<K, V> next) {
            this.hash = hash;
            this.key = key;
            this.value = value;
            this.next = next;
        }

        @Override
        public K getKey() {
            return key;
        }

        @Override
        public V getValue() {
            return value;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == this) {
                return true;
            }
            if (obj == null || obj.getClass() != this.getClass()) {
                return false;
            }
            Map.Entry<?, ?> entry = (Map.Entry<?, ?>) obj;
            return ((key != null && key.equals(entry.getKey())) &&
                    (value != null && value.equals(entry.getValue())));
        }

        @Override
        public int hashCode() {
            int hash = 31;
            int prime = 17;
            hash = prime * hash + (key == null ? 0 : key.hashCode());
            hash = prime * hash + (value == null ? 0 : value.hashCode());
            return hash;
        }
    }

    private Node<K, V>[] bucket;

    private int size;

    public MyHashMap() {
        this(DEFAULT_INITIAL_CAPACITY);
    }

    public MyHashMap(int initialCapacity) {
        this.bucket = new Node[initialCapacity];
    }

    private int hash(Object key) {
        return (key == null ? 0 : Math.abs(key.hashCode()));
    }

    private int getBucketSize() {
        return bucket.length;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public boolean containsKey(Object key) {
        return getNode(key) != null;
    }

    @Override
    public V get(Object key) {
        Node<K,V> entry;
        return (entry = getNode(key)) == null ? null : entry.value;
    }

    private Node<K,V> getNode(Object key) {
        int hash = hash(key);
        int index = (getBucketSize() - 1) & hash;
        Node<K, V> entry = bucket[index];
        //if there is no node at this bucket location
        if (entry == null) {
            return null;
        }
        //check the equality with the first node
        if (entry.hash == hash &&
                (key == entry.key || (key != null && key.equals(entry.key)))) {
            return entry;
        }
        //check the remaining nodes
        while (entry.next != null) {
            entry = entry.next;
            if (entry.hash == hash &&
                    (key == entry.key || (key != null && key.equals(entry.key)))) {
                return entry;
            }
        }
        return null;
    }

    @Override
    public void put(K key, V value) {
        int hash = hash(key);
        int index = (getBucketSize() - 1) & hash;
        Node<K, V> entry = bucket[index];
        //if no node is present at this bucket location
        if (entry == null) {
            bucket[index] = newNode(hash, key, value, null);
            size++;
        } else {
            Node<K, V> node = null;
            //check the equality with the first node
            if (entry.hash == hash &&
                    (key == entry.key || (key != null && key.equals(entry.key)))) {
                node = entry;
            } else {
                //check the remaining nodes
                while (entry.next != null) {
                    node = entry.next;
                    if (node.hash == hash &&
                            (key == node.key || (key != null && key.equals(node.key)))) {
                        break;
                    }
                }
                //if the node is not equal and the next of it is null
                if (entry.next == null) {
                    node = entry.next;
                    entry.next = newNode(hash, key, value, null);
                    size++;
                }
            }
            if (node != null) {
                node.value = value;
            }
        }
    }

    @Override
    public V remove(Object key) {
        Node<K,V> entry;
        return ((entry = removeNode(key)) == null ? null : entry.value);
    }

    private Node<K, V> newNode(int hash, K key, V value, Node<K, V> next) {
        return new Node<>(hash, key, value, next);
    }

    private Node<K,V> removeNode(Object key) {
        int hash = hash(key);
        int index = (getBucketSize() - 1) & hash;
        Node<K, V> entry = bucket[index];
        //there is node at this bucket location
        if (entry != null) {
            Node<K,V> node = null;
            //check the equality with the first node
            if (entry.hash == hash &&
                    (key == entry.key || (key != null && key.equals(entry.key)))) {
                node = entry;
                size--;
            } else {
                while (entry.next != null) {
                    node = entry.next;
                    if (node.hash == hash &&
                            (key == node.key || (key != null && key.equals(node.key)))) {
                        size--;
                        break;
                    }
                }
            }
            if (node != null) {
                if (node == entry) {
                    bucket[index] = node.next;
                } else {
                    entry.next = node.next;
                }
                return node;
            }
        }
        return null;
    }
}
