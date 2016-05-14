/*************************************************************
方法一、循环改变相邻位置前边为偶数后边为奇数的情况O（n）
*************************************************************/
class Solution {
public:
    void reOrderArray(vector<int> &array)
    {
        if(array.size()<1)
            return;
        for(int i = 0; i < array.size() - 1; ++i)
            for(int j = 0; j < array.size() -i- 1; ++j)
            {
            if(array[j]%2 == 0 && array[j+1]%2 == 1)
                {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
         
    }
};
/*************************************************************
方法二、与法一类似，但是这次是找到奇数在偶数后边的情况，然后
奇数偶数之间的数字整体后移，为奇数的插入腾出空间
*************************************************************/
class Solution {
public:
    void reOrderArray(vector<int> &array) 
    {
        int length = array.size();
        
        int i = 0;
        int j = 0;
        while(i < length && j < length)
        {
            while(array[i]%2 == 1)
                i++;
            while(array[j]%2 == 0)
                j++;
            
            if(j>i && i < length && j < length)
            {
                int temp = array[j];
                for(int k = j;k > i;--k)
                {
                    array[k] = array[k-1];
                }
                array[i] = temp;
            }
            else
                {
                j++;
            }
        }
    }
};
