class Solution {
    public int[] sortArrayByParity(int[] A) {
        List<Integer> even = new ArrayList<Integer>();
        List<Integer> odd = new ArrayList<Integer>();
        
        for(int i=0;i<A.length;i++)
        {
            if(A[i]%2==0)
            {
                even.add(A[i]);
            }
            else
            {
                odd.add(A[i]);
            }
        }
        int i=0;
        for(i=0;i<even.size();i++)
        {
            A[i]=even.get(i);
        }
        //i+=1;
        //System.out.println(i);
        for(int j=0;j<odd.size();j++)
        {
            A[i]=odd.get(j);
            i++;
        }
        return A;
    }
}