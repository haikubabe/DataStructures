package custom_hashmap;

public interface MyMap<K,V> {

    /**
     * Returns the number of key-value mappings in this map
     * @return the number of key-value mappings in this map
     */
    int size();

    /**
     * Returns true if this map contains no key-value mappings
     * @return true if this map contains no key-value mappings
     */
    boolean isEmpty();

    /**
     * Returns true if this map contains a mapping for the specified key
     * @param key whose presence in this map is to be tested
     * @return true if this map contains a mapping for the specified key
     */
    boolean containsKey(Object key);

    /**
     * Returns the value for the specified key or returns null if there
     * is no mapping for the specified key
     * @param key whose associated value is to be returned
     * @return the value for the specified key or returns null if there
     * is no mapping for the specified key
     */
    V get(Object key);

    /**
     * Associates the specified value with the specified key in this map.
     * If this map previously contained a mapping for the key, the old value
     * is replaced by the specified value.
     * @param key with which the specified value is to be associated
     * @param value value to be associated with the specified key
     */
    void put(K key, V value);

    /**
     * Removes the mapping for the specified key from this map if it is present.
     * Returns the removed value associated with the specified key from this map,
     * or return null if there is no mapping for the key
     * @param key whose associated value is to be removed
     * @return the removed value associated with the specified key from this map,
     * or return null if there is no mapping for the key
     */
    V remove(Object key);


    /**
     * A map entry (key-value pair)
     * @param <K> key
     * @param <V> value
     */
    interface Entry<K,V> {

        /**
         * Returns the key corresponding to this entry
         * @return the key corresponding to this entry
         */
        K getKey();

        /**
         * Returns the value corresponding to this entry
         * @return the value corresponding to this entry
         */
        V getValue();

        /**
         * Returns true if the specified entry is equal to this map entry
         * @param entry to be compared for equality with this map entry
         * @return true if the specified entry is equal to this map entry
         */
        boolean equals(Object entry);

        /**
         * Returns the hashcode for this map entry
         * @return the hashcode for this map entry
         */
        int hashCode();
    }
}
