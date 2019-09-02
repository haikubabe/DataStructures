package custom_hashmap;

public class Test {
    public static void main(String[] args) {
        MyMap<String, String> myMap = new MyHashMap<>();
        myMap.put("sree", "sreemoyee");
        myMap.put("gosour", "sourav");
        System.out.println(myMap.size());
        System.out.println(myMap.containsKey("sree"));
        System.out.println(myMap.containsKey("gosour"));
        System.out.println(myMap.get("sree"));
        System.out.println(myMap.get("gosour"));

        myMap.put("abcd", "test");
        System.out.println(myMap.size());
        System.out.println(myMap.containsKey("abcd"));
        System.out.println(myMap.get("abcd"));

        myMap.put("sree", "newsreemoyee");
        System.out.println(myMap.size());
        System.out.println(myMap.containsKey("sree"));
        System.out.println(myMap.get("sree"));

        myMap.remove("gosour");
        System.out.println(myMap.size());
        System.out.println(myMap.containsKey("gosour"));
        System.out.println(myMap.get("gosour"));
    }
}
