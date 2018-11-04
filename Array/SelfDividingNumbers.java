class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        for(int i=left;i<=right;i++)
        {
            ArrayList<Integer> nums = new ArrayList<Integer>();
            int x=i;
            int flag=0;
            int flag2=0;
            while(x!=0)
            {
                nums.add(x%10);
                if(x%10==0)
                {
                    flag=1;
                }
                x=x/10;
            }
            if(flag==1)
            {
                continue;
            }
            else
            {
                for(int j=0;j<nums.size();j++)
                {
                    if(i%nums.get(j)!=0)
                    {
                        flag2=1;
                        continue;
                    }
                }
                if(flag2==0)
                {
                    list.add(i);
                }
            }
        }
        return list;
    }
}