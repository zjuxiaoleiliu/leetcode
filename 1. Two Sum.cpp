题目描述:

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
/*
乍一看就感觉可以用暴力搜索，但是猜到OJ肯定不会允许用暴力搜索这么简单的方法，
于是去试了一下，果然是Time Limit Exceeded，这个算法的时间复杂度是O(n^2)。
那么只能想个O(n)的算法来实现，由于暴力搜索的方法是遍历所有的两个数字的组合，
然后算其和，这样虽然节省了空间，但是时间复杂度高。一般来说，我们为了提高时间的复杂度，
需要用空间来换，这算是一个trade off吧，我们只想用线性的时间复杂度来解决问题，
那么就是说只能遍历一个数字，那么另一个数字呢，我们可以事先将其存储起来，
使用一个HashMap，来建立数字和其坐标位置之间的映射，我们都知道HashMap是常数级的查找效率
这样，我们在遍历数组的时候，用target减去遍历到的数字，就是另一个需要的数字了，
直接在HashMap中查找其是否存在即可
*/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {

    int n = numbers.size();
    unordered_map<int, int> m;//存储的是第一个数的下标
    vector<int> ret;
     
    for(int i=0; i<n; i++)//流式处理，新增加一个没见过的数字，i为第二个数下标
    {
        int first = target - numbers[i];
        if(m.find(first)!= m.end())
        {
            ret.push_back(m[first]);
            ret.push_back(i);
            break;
           
        }
        else 
            m[numbers[i]] = i;
            
    }
     
    return ret;  
        
    }
};