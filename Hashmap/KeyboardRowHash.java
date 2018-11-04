class Solution {
    public String[] findWords(String[] words) {
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        
        map.put('q',1);
        map.put('w',1);
        map.put('e',1);
        map.put('r',1);
        map.put('t',1);
        map.put('y',1);
        map.put('u',1);
        map.put('i',1);
        map.put('o',1);
        map.put('p',1);
        
        map.put('a',2);
        map.put('s',2);
        map.put('d',2);
        map.put('f',2);
        map.put('g',2);
        map.put('h',2);
        map.put('j',2);
        map.put('k',2);
        map.put('l',2);
        
        map.put('z',3);
        map.put('x',3);
        map.put('c',3);
        map.put('v',3);
        map.put('b',3);
        map.put('n',3);
        map.put('m',3);
        ArrayList<String> strs = new ArrayList<String>();
        
        for(int i=0;i<words.length;i++)
        {
            int flag=0;
            String sp = words[i];
            String s=sp.toLowerCase();
            
            int val = map.get(s.charAt(0));
            
            for(int j=1;j<s.length();j++)
            {
                if(map.get(s.charAt(j))!=val)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                strs.add(sp);
            }
        }
        String[] strings = new String[strs.size()];
        for(int i=0;i<strs.size();i++)
        {
            strings[i]=strs.get(i);
        }
        return strings;
    }
}