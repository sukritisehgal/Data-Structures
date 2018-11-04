/*
     * Complete the function below.
     */
    static int[] jobOffers(int[] scores, int[] lowerLimits, int[] upperLimits) {
    
        ArrayList<Integer> result = new ArrayList<Integer>();
        Arrays.sort(scores);
        for(int i =0;i<lowerLimits.length;i++)
        {
            int lower = lowerLimits[i];
            int upper = upperLimits[i];
            int count=0;
            /*for(int j=0;j<scores.length;j++)
            {
                if(scores[j]>=lower && scores[j]<=upper)
                {
                    count+=1;
                }
                else if(scores[j]>upper)
                {
                    //System.out.println("Hi");
                    break;
                }
            }
            result.add(count);*/
            
        }
        int[] arr = new int[result.size()];
        int i=0;
        for(int j=0;j<result.size();j++)
        {
            arr[i]=result.get(j);
            i++;
        }
        //arr = result.toArray(arr);
        
        return arr;
        
    }

